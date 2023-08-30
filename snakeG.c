#include<stdio.h> 
#include<stdlib.h>
#include<conio.h>


int hight=30,width=30,x,y,goalx,goaly,flag=0,game_over,score;
int tailX[100],tailY[100];
int pieces=0;
void logic()//main logic written here
{   
	int i,j;
    int prev2X,prev2Y;
    int prevX=tailX[0];
	int prevY=tailY[0];
	tailX[0]=x;
	tailY[0]=y;
	for(i=1;i<=pieces;i++)//tail follow diretion og head logic
	{
	    prev2X=tailX[i];
	    prev2Y=tailY[i];
	  	tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}

	switch(flag)//increment of snake
	{
		case 1:
			{
				x--;
				break;
			}
		case 2:
			{
				x++;
				break;
			}
		case 3:
			{
				y--;
				break;
			}
		case 4:
			{
				y++;
				break;
			}
	}
		if(x==0||x==hight||y==0||y==width)//if snake touch boaundry
		{
			game_over=1;
		}
		
		for(i=0;i<pieces;i++)//snake touch their own body part
		{
			if(x==tailX[i]&&y==tailY[i])
			{
				game_over=1;
			}
		}
		if(x==goalx&&y==goaly)
		{
			label3:
			goalx=rand()%30;
 			if(goalx==0)
			goto label3;
			label4:
			goaly=rand()%30;
			if(goaly==0)
			goto label4;
			score+=10;
			pieces++;
		}
}
void entry()//keyboard operated funtion
{
	if(kbhit())
	
	{
		switch(getch())
		{
			case'8':
				{
					flag=1;
					break;
				}
			case'5':
				{
					flag=2;
					break;
				}
					
			case'4':
				{
					flag=3;
					break;
				}
					
			case'6':
				{
					flag=4;
					break;
				}	
		}
	}
}
void setup()//starting position of snake & fruit
{
	y=hight/2;
	x=width/2;
	label1:
	goalx=rand()%30;
	if(goalx==0)
	goto label1;
	label2:
	goaly=rand()%30;
	if(goaly==0)
	goto label2;
	game_over=0;
	score=0;	
}
void look()//look of game
{
	system("cls");
	int i,j,k;
	
	for(i=0;i<=hight;i++)
	{
		for(j=0;j<=width;j++)
		{    	
			if(i==0||i==hight||j==0||j==width)
			{    
				printf("#");	
			}//boundry
			else
			{   
				if(i==x&&j==y)
				{   
					printf("0");
				}//head
				else 
					if(i==goalx&&j==goaly)
				{   
					printf("@");
				}//fruit
				else
				{  int ch=0;
					for(k=0;k<pieces;k++)
					{
						if(i==tailX[k]&&j==tailY[k])
						{   
							printf("o");
							ch=1;
						}//snake tail	
					}
					if(ch==0)
					printf(" ");	
				}
			}
		
		}
		printf("\n");
	} 
  }
	
    

int main()
{  
	int i,j,play;
	char yn;
  	system("color 70");


  	
  		printf("\n\n\n\n\t\t\t\t\t***********************\n");
    	printf("\t\t\t\t\t[WELCOME TO SNAKE GAME]\n");
    	printf("\t\t\t\t\t***********************\n\n");
		 printf("# GAME INTRUCTION:-\n");
		printf(" FOR SNAKE MOVEMENT:\n");
		printf("--> 4-left  6-right ");
		printf("8-up  5-down\n");
		printf("--> Game over when player press opposite key of the snake movement direction.\n");
		printf("--> Press 'y' for play again.\n");
		printf("\n\n\t\t\t\t\t   Enter 0 for exit:\n");
		printf("\t\t\t\t\t   Enter 1 for play: ");
		scanf("%d",&play);
		switch(play)
    	{
		   case 1:
	    	{       
			    play_game:
			   	setup();
		    	while(game_over!=1)
			   {    
 	   			    look();	
				    entry();
				    logic();
				    
				    for(i=0;i<1000;i++)
				    {
				    	for(j=0;j<10000;j++)
				    	{
				    	  //here for loop to make game slow	
						}
					}
		       }
		    	printf("\n\n\t** GAME OVER **\n\n");
		 		printf("\tSCORE : %d",score);
		 		printf("\n\n YOU WANNA PLAY AGAIN? (Y/N) : ");
				scanf(" %c",&yn);
	      	    if(yn=='y'||yn=='Y')
	            {
	            	score=0;
	            	game_over=0;
	            	pieces=0;
	            	system("cls");
	        		goto play_game;
				}
				if(yn=='n'||yn=='N')
				{
					goto exit;
				}
				break;
        	}//case 1 end here
		    case 0:
		    {
		   	 	exit:
		   	  	system("cls");
		   	  	printf("\n\n\n\n\n\t\t\t\t\tHAVE A NICE DAY :)\n\n\n\n");	
		   	 	break;
		    }//case 0 and here		
	   }//switch-play end here   
}//main funtion end here
