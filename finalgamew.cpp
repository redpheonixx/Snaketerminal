#include<iostream>
#include<ncurses.h>	
#include<unistd.h>
#include<cstdlib>
using namespace std;
int main()
{
initscr();
WINDOW*win=newwin(30, 100, 3, 2);
raw();
noecho();
curs_set(FALSE); 
int a[100],b[30];
int fox=16;
int foy=10;
int l=10;
int jk=0,mn=0,g,f;
int k=3;
 
	
//-------------------------------------------------------------------------------------------------------------------------------------
 /*for(int i=0;i<75;i++)//BOUNDARY FUNCTION
	{
	for(int j=0;j<75;j++)
		{
			if(i==0||j==0||i==74||j==74)
			{wmove(win,j,i);
			wprintw(win,"#");}
			
		}
	}
 wrefresh(win);*/
 
 
//------------------------------------------------------------------------------------------------------------------------------------
	
 for(int i=0;i<l;i++)		//PRINTING SNAKE FOR FIRST TIME
	{
		a[i]=i+2;
		b[i]=10;		
	}
	
	for(int i=0;i<l;i++)		
	{	
		wmove(win,b[i],a[i]);
		wprintw(win,"*");
	}
	
	
//------------------------------------------------------------------------------------------------------------------------------------
 for(;;)
	{ 	/*for(int i=0;i<75;i++)//BOUNDARY FUNCTION
		{
		for(int j=0;j<75;j++)
			{
				if(i==0||j==0||i==74||j==74)
				{wmove(win,j,i);
				wprintw(win,"#");}
				
			}
		}*/
		 wborder(win, '#', '#', '#', '#', '+', '+', '+', '+');

	
 		wrefresh(win);	
		int z;
		int f=a[0]; int g=b[0];		//MOVEMENT FUNCTION
		for(int i=0;i<l-1;i++)		 						
		{
			a[i]=a[i+1];
			b[i]=b[i+1];
		}
	
		keypad(stdscr,TRUE);		
		nodelay(stdscr,TRUE);
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
			if(k==5)
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
		wmove(win,g,f);
		wprintw(win," ");	//PRINTING SNAKE AFTER UPDATING
		for(int i=0;i<l;i++)	
			{	
				wmove(win,b[i],a[i]);
				wprintw(win,"*");
					
			}
		wrefresh(win);

//-----------------------------------------------------------------------------------------------------------------------------------

		if(fox==a[l-1]&&foy==b[l-1])	//UPDATE FUNCTION
		{	
			l+=1;
			int mn=1;
			a[l-1]=a[l-2];
			b[l-1]=b[l-2];
			wmove(win,foy,fox);   
			wprintw(win," ");
			wrefresh(win);	
			label2:
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
		/*if(mn==1)			//FOOD FUNCTION
		{
			
			wmove(win,foy,fox);   
			wprintw(win," ");
			wrefresh(win);	
			label2:
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
			
				
			
		}*/
		wmove(win,foy,fox);
		wprintw(win,"0");
		wrefresh(win);
		usleep(100000);
//------------------------------------------------------------------------------------------------------------------------------------
		int gh;				//GAME OVER FUNCTION
		/*for(int i=0;i<l-2;i++)
		{	
			if(a[l-1]==a[i])		
			 gh=1;	
		}*/
		if(a[l-1]==99||b[l-1]==49||a[l-1]==1||b[l-1]==1)	
		{
			
			system("CLEAR");
			
			cout<<"---------------------------------------GAME OVER---------------------------------------------";
			jk=1;
			
		}
		
		/*else if(gh==1)
		{
			system("CLEAR");
			
			cout<<"----------------------------------------GAME OVER--------------------------------------------";
			jk=1;
		}*/
//----------------------------------------------------------------------------------------------------------------------------------------
		if(jk==1)
		goto end;
	}
		end:
		endwin();
		
		return 0;
}	
