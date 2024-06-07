#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string.h> 
#include <unistd.h> 
#include <math.h> 

#include "helpers.h"

int main(int argc, char** argv){ 

    clrscr(); 

    printf("SECRET WEAPON\n"); 

    int d = 0; 

    while(1) {  
        printf("ENTER DIFFICULTY ");
        scanf("%d", &d); 

        if(d >= 4) { 
            break; 
        }
    }

    printf("\n"); 

    srand(time(NULL)); 

    int x = rand() % d + 1; 
    int y = rand() % d + 1; 

    for(int i = 1; i < 5 + d; i++) { 
        int x1 = 0; 
        int y1 = 0; 

        printf("GUESS FOR X "); 
        scanf("%d", &x1); 
        printf("\nGUESS FOR Y "); 
        scanf("%d", &y1); 
        printf("\n"); 

        float z = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));

        if(z == 0) { 
            printf("YOU DESTROYED IT IN %d GOES\n", i);
            return 0; 
        } else if(z <= 3) { 
            printf("CLOSE\n"); 
        } else if(z > 3) { 
            printf("NOT EVEN CLOSE\n"); 
        }
    }

    printf("THE ROBOTS HAVE SEEN\nYOU - AGGHHHHHH.....");
    return 0;
}
