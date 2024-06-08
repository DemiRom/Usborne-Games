#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string.h> 
#include <unistd.h> 
#include <math.h> 

#include "helpers.h"

int main(int argc, char** argv){ 
    clrscr(); 

    set_conio_terminal_mode();

    srand(time(NULL)); 

    printf("TRAITOR's CASTLE\r\n"); 

    int score = 0; 

    for(int i = 1; i < 10; i++) { 
        char* r = (char*)malloc(sizeof(char) * 10); 
        int t = (rand() % 9) + 1;  
        for(int j = 1; j < 10; j++) { 
            if(j == t) { 
                strncat(r, "O", 1); 
            } else if(j != t) { 
                strncat(r, ".", 1); 
            }
        }

        printf("%s\r\n", r);

        for(int i = 0; i < 10; i++) {
            if(kbhit()) {
                char inc = getch() + 1; // +1 to offset the scancodes up range 50-59 instead of 49-57 (48 '0' is dealt with after)
                if(inc == 48) inc = inc + 10; //Special case for 0 just bump it up passed 9 
                inc = inc - 50; //Now drop 50 off the scancode to get 0-10 
                                
                if(inc + 1 == t) { 
                    printf("GOOD SHOT\r\n"); 
                    score++; 
                    goto free; 
                } else if(inc + 1 != t) { 
                    printf("MISSED\r\n"); 
                    goto free; 
                }
            }
            msleep(200); 
        }
        printf("MISSED\r\n"); 
free:
        free(r); 
    }

    printf("YOU HIT %d OUT OF 10\r\n", score);
    return 0; 
}
