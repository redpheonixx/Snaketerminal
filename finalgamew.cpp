#include<iostream>
#include<ncurses.h>	
#include<unistd.h>
#include<cstdlib>
using namespace std;
int main()
{
initscr();				//intializing the curses
WINDOW*win=newwin(30, 100, 3, 2);	//creating window
raw();
noecho();
start_color();				//initialzing colors
init_pair(1,COLOR_RED, COLOR_WHITE);
wbkgd(win, COLOR_PAIR(1));
curs_set(FALSE); 			//erase cursor
int a[100],b[30];			//arrays to store snake coordinates
int fox=16;				//arrays to store food coordinates 
int foy=10;
int l=10;				//initailzing snake's lenght 
int jk=0,g,f;				//flag values used
int k=3; 
//--------------------------------------------------------------------------------------------------------------------------------------
//INTIALIZING SNAKE COORDINATES
for(int i=0;i<l;i++)		
	{
		a[i]=i+2;
		b[i]=10;		
	}
	


		
//------------------------------------------------------------------------------------------------------------------------------------
 for(;;)
	{ 	
		wborder(win, '#', '#', '#', '#', '+', '+', '+', '+');// Border function
		wrefresh(win);	
//------------------------------------------------------------------------------------------------------------------------------------
		//MOVEMENT FUNCTION

		int z;				//input from the user
		int f=a[0]; int g=b[0];		//grabbing snake tail coordinates so to print space after snake moved by 1 unit
		for(int i=0;i<l-1;i++)	//copying snake points coordinates to the point just behind them					
		{
			a[i]=a[i+1];
			b[i]=b[i+1];
		}
	
		keypad(stdscr,TRUE);	//Allowing special characters to be enable(arrows keys)	
		nodelay(stdscr,TRUE);	//taking input without stopping the game
		z=getch();
			switch(z)
			{
				 case KEY_UP:if(k==2)	
						{
							k=2;
						}
					     else
						{
							k=5;	
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
			if(k==5)			//storing new coordinates if snake's head
			{
				b[l-1]-=1;
			}
			if(k==2)
			{
				b[l-1]+=1;
			}
			if(k==3)
			{
				a[l-1]+=1;
			}
			if(k==1)
			{
				a[l-1]-=1;
			}
//----------------------------------------------------------------------------------------------------------------------------------
		//PRINTING SNAKE AFTER UPDATING
		wmove(win,g,f);
		wprintw(win," ");	
		for(int i=0;i<l;i++)	
			{	
				wmove(win,b[i],a[i]);
				wprintw(win,"0");
					
			}
		wrefresh(win);

//-----------------------------------------------------------------------------------------------------------------------------------
		//UPDATE FUNCTION
		if(fox==a[l-1]&&foy==b[l-1])	
		{	
			l+=1;			//increasing the lenght 
			a[l-1]=a[l-2];		//storing new points coordinates as that of snake 
			b[l-1]=b[l-2];
			wmove(win,foy,fox);   	//erasing eaten food
			wprintw(win," ");
			wrefresh(win);	
			label2:			//Getting new food's coordinates
			srand ( time(NULL) );
			int v=1+rand()%98;
			int bv=1+rand()%28;
			for(int i=0;i<l;i++)
				{	
					if(v==a[i]&&bv==b[i])
					{goto label2;}
				}
			fox=v;
			foy=bv;
			
		}
		
//----------------------------------------------------------------------------------------------------------------------------------
		//PRINTING FOOD AFTER UPDATE
		wmove(win,foy,fox);
		wprintw(win,"*");
		wrefresh(win);
		usleep(100000);
//------------------------------------------------------------------------------------------------------------------------------------
		//GAME OVER FUNCTION
		int gh;				
		for(int i=0;i<l-2;i++)		//Checking if snake has bitten himself
		{	
			if(a[l-1]==a[i]&&b[l-1]==b[i])		
			 {	
			 	system("CLEAR");
			 	cout<<"----------------------------------------GAME OVER--------------------------------------------";
				jk=1;
			}
		}
		if(a[l-1]==99||b[l-1]==29||a[l-1]==1||b[l-1]==1)//Checking if snake has hitten boundary	
		{
			
			system("CLEAR");
			
			cout<<"---------------------------------------GAME OVER---------------------------------------------";
			jk=1;
			
		}
		
		
//----------------------------------------------------------------------------------------------------------------------------------------
		if(jk==1) //exiting the loop if any of above two conditions are true
		goto end;
	}
		end:
		endwin();//ending the curses
		
return 0;
}	
