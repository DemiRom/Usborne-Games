#include <time.h> 
#include <errno.h> 

#ifdef _WIN32
#include <conio.h> 
#endif

#ifndef _WIN32

#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/select.h> 
#include <termios.h> 

struct termios orig_termios; 

void clrscr() { 
    system("clear"); 
}

void reset_terminal_mode() {
    tcsetattr(0, TCSANOW, &orig_termios); 
}

void set_conio_terminal_mode()
{
    struct termios new_termios; 

    tcgetattr(0, &orig_termios);
    memcpy(&new_termios, &orig_termios, sizeof(new_termios)); 

    atexit(reset_terminal_mode); 
    cfmakeraw(&new_termios); 
    tcsetattr(0, TCSANOW, &new_termios); 
}

int kbhit() { 
    struct timeval tv= { 0L, 0L }; 
    fd_set fds; 
    FD_ZERO(&fds); 
    FD_SET(0, &fds); 
    return select(1, &fds, NULL, NULL, &tv) > 0; 
}

int getch() { 
    int r; 
    unsigned char c; 
    if ((r = read(0, &c, sizeof(c))) < 0) {
        return r; 
    }
    return c; 
}

#endif

int msleep(long msec) { 
    struct timespec ts; 
    
    int res; 

    if(msec < 0) { 
        errno = EINVAL; 
        return -1; 
    }

    ts.tv_sec = msec / 1000; 
    ts.tv_nsec = (msec % 1000) * 1000000; 

    do { 
        res = nanosleep(&ts, &ts); 
    } while (res && errno == EINTR); 

    return res; 
}

