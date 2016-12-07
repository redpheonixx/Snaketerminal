#include<iostream>
#include<ncurses.h>
#include<stdlib.h>
#include <unistd.h>
using namespace std;
int main()

{	int x=10;
	int y=10;
	int z;
	int k=3;
	initscr();
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_RED);
	for(;;)
	{	WINDOW*win=newwin(75, 75, 3, 2);
		wrefresh(win);
		wmove(win,y,x);
		raw();
		noecho();
		attron(COLOR_PAIR(1));
		wprintw(win,"*");
		wrefresh(win);		
    		usleep(600000);
		wmove(win,y,x);
		wprintw(win," ");			//prints space at the coordinates of point where it has earlier print *
		wrefresh(win);
		keypad(stdscr,TRUE);
		nodelay(stdscr,TRUE);				
		z=getch();
        	switch(z)		
        	    {
        	         case KEY_UP:k=5;
        	            	break;
        	         case KEY_DOWN:k=2;
        	            	break;
        	         case KEY_RIGHT:k=3;
        	            	break;
        	         case KEY_LEFT:k=1;
        	        	break;
			 
        	    }    
		if(k==5)
		{
			y-=1;
		}
		if(k==2)
		{
			y+=1;
		}
		if(k==3)
		{
			x+=1;
		}
		if(k==1)
		{
			x-=1;
		}

	}
	endwin();				
return 0;
}
