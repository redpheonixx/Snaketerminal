#include<iostream>
#include<ncurses.h>	/* I have made two arrays a[i] for x coordinates and b[i] for y coordinates i have to update head a[9]b[9] using keypad 			and switch function and for rest of the snake i did run a loop to store the coordinates of part(A) which is present 				just before the part(B) to part(B) except a[9]b[9] which is head.*/
#include<unistd.h>
using namespace std;
int main()

{	int a[10],b[10];		//taken initial lenght of snake to be 10
	int k=3,z;
	for(int i=0;i<10;i++)		//this will save the coordinates of snake initial position
	{
		a[i]=i+2;		// x coordinates
		b[i]=10;		//y coordinates
	}
	initscr();
	WINDOW*win=newwin(75, 75, 3, 2);
	raw();
	noecho();
	for(int i=0;i<10;i++)		//printing snake for the first time
	{	
		wmove(win,b[i],a[i]);
		wprintw(win,"*");
	}
	wrefresh(win);
	for(;;)
	
	{ int f=a[0]; int g=b[0];		//grabbing the tail of snake so to print space there 
		for(int i=0;i<9;i++)		//copying the coordinates of part(A) which is present just before the part(B) to part(B) except 						//a[9] which is head
		{
			a[i]=a[i+1];
			b[i]=b[i+1];
		}
	
		keypad(stdscr,TRUE);		//updating head a[9] a/c to input from user
		nodelay(stdscr,TRUE);
		z=getch();
			switch(z)
			{
				 case KEY_UP:if(k==2)	//checking if snake was moving in opposite direction of input or not
						{
							k=2;	//if yes then it will keep moving in that direction only
						}
					     else
						{
							k=5;	//otherwise it will change the direction
						}
        		            	     break;
        		         case KEY_DOWN:if(k==5)
						{
							k=5;
						}
					     else
						{
							k=2;
						}
        		            	     break;
        		            	
        		         case KEY_RIGHT:if(k==1)
						{
							k=1;
						}
					     else
						{
							k=3;
						}
        		            	     break;
        		            	
        		         case KEY_LEFT:if(k==3)
						{
							k=3;
						}
					     else
						{
							k=1;
						}
        		            	     break;
        		        	
			}
			if(k==5)
			{
				b[9]-=1;
			}
			if(k==2)
			{
				b[9]+=1;
			}
			if(k==3)
			{
				a[9]+=1;
			}
			if(k==1)
			{
				a[9]-=1;
			}
			usleep(100000);
			wmove(win,g,f);
			wprintw(win," ");	//printing space on snake's tail coordinates
		for(int i=0;i<9;i++)		//printing snake after updating
		{	wmove(win,g,f);
			wprintw(win," ");
			wmove(win,b[i],a[i]);
			wprintw(win,"*");
		}
		wrefresh(win);
	}	
	endwin();	
return 0;
}
