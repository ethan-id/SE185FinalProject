/*----------------------------------------------------------------------------
-		    SE 185: Final Project - Memory Game                 		 	 -/* 
-   Team member 1 "Ethan Hancock" | "%"                                      -   
-   Team member 2 "Joseph Chalupa" | "%"                                     -
-   Team member 3 "Anthony Phan" | "%"                                       -
-   Team member 4 "Levi Sissel" | "%"                                        -
- 	Section: 7															     -
-	Date: 12/1/2021														     -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <math.h>

#define WORDLENGTH 11
#define MAXWORDS 100

int read_words(char* WL[MAXWORDS], char* file_name);
void trimws(char* str);

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char* argv[]) {
    WINDOW *my_window;
	char* wordlist[MAXWORDS];
    int i;
    wordcount = read_words(wordlist, argv[1]);

    initscr();

    for(i = 0; i < wordcount; i++){
        mvprintw(row, column, wordlist[i]);
        column += 15;

        if (column == 85){
            column = 10;
            row++;
        }
	}
    printf("\n");
    
	refresh();
    getchar();
    endwin();




}