#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string.h> 
#include <unistd.h> 

#include "helpers.h"

int main(int argc, char** argv) { 

    clrscr(); 

    printf("COWBOY SHOOTOUT\nYOU ARE BACK TO BACK\nTAKE 10 PACES..."); 

    for(int i = 1; i < 10; i++){ 
        msleep(500); 
        printf("%d...", i);
        fflush(stdout); 
    }   

    int s = 1 + rand() / (RAND_MAX / (5) + 1); 
    sleep(s);

    printf("HE DRAWS...\n"); 
    fflush(stdout); 

    for(int i = 0; i < s; i++) {
        if(kbhit()) {
            printf("BUT YOU SHOOT FIRST\nYOU KILLED HIM");
            return 0; 
        }
        (void)getch(); // Consume any input.
        msleep(500);
    }

    printf("AND SHOOTS\nYOU ARE DEAD"); 

    return 0; 
}
