#include <stdio.h> 
#include <stdlib.h> 
#include <ncurses.h> 
#include <math.h> 

int main(void) { 
    
    initscr(); 
    clear(); // Clear the screen

    for(int i = 0; i < 10; i++) { 
        for(int j = 0; j < 10; j++){ 
            move(i, j); 

            if(i % 2 == 0 && j % 2 == 0) 
                addstr("x"); 
            else 
                addstr("o");
        }
    }
 

    move(50, 50); 

    for(int i = 0; i < 10; i++) { 
        for(int j = 0; j < 10; j++) { 
            int dist = sqrt((i - 10) * (i - 10) + (j - 10) * (j - 10));
            if(dist == 10) 
                addstr("O"); 
            else
                addstr(" ");

            move(50 + i, 50 + j); 
        }
    }


    refresh(); 

    getch(); 

    endwin();

    return 0; 

}
