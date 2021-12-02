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
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#define WORDLENGTH 11
#define MAXWORDS 100

int read_words(char* WL[MAXWORDS], char* file_name);
void trimws(char* str);

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char* argv[]) {
    WINDOW *my_window;
    int wordcount;
	char* wordlist[MAXWORDS];
    int i;
    wordcount = read_words(wordlist, argv[1]);

    initscr();

    for(i = 0; i < wordcount; i++){
        mvprintw(0, 0, wordlist[i]);
        
	}
    printf("\n");

	refresh();
    getchar();
    endwin();




}

void trimws(char* str) {
	int length = strlen(str);
	int x;
	if (length == 0) return;
	x = length - 1;
	while (isspace(str[x]) && (x >= 0)) {
		str[x] = '\0';
		x -= 1;
	}
}

int read_words(char* WL[MAXWORDS], char* file_name)
{
	int numread = 0;
	char line[WORDLENGTH];
	char *p;
	FILE* fp = fopen(file_name, "r");
	while (!feof(fp)) {
		p = fgets(line, WORDLENGTH, fp);
		if (p != NULL) 
		{
			trimws(line);
			WL[numread] = (char *)malloc(strlen(line) + 1);
			strcpy(WL[numread], line);
			numread++;
		}
	}
	fclose(fp);
	return numread;
}