#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string.h> 
#include <unistd.h> 

#include "helpers.h"

int main(int argc, char** argv) { 
    clrscr(); 

    printf("VITAL MESSAGE\n"); 
    int d = 0; 

    while(1) { 
        printf("HOW DIFFICULT? (4-10) ");
        scanf("%d", &d);
        if(d >= 4 && d <= 10) {
            break; 
        }
    }

    srand(time(NULL)); 

    char* m = (char*)malloc(sizeof(char) * d + 1); 

    for(size_t i = 0; i < d; i++) { 
        //                     65 to 90 is our ASCII range 
        char ranLetter = (char)65 + rand() / (RAND_MAX / (90 - 65 + 1) + 1); 
        strncat(m, &ranLetter, 1); 
    }
    

    clrscr(); 

    printf("SEND THIS MESSAGE:\n\n%s", m);
    fflush(stdout); // Flush the stdout buffer before sleeping to avoid not printing the chars

    sleep(0.5 * d);

    clrscr(); 

    char* n = (char*)malloc(sizeof(char) * d + 1); //Input buffer
    
    scanf("%s", n); 

    if (strncmp(m, n, d) == 0) { 
        printf("MESSAGE CORRECT\nTHE WAR IS OVER\n");
        free(m); 
        free(n); 
        return 0; 
    }
    printf("YOU GOT IT WRONG\nYOU SHOULD HAVE SENT: %s\n", m);
    free(m); 
    free(n); 
    return 0; 
}
