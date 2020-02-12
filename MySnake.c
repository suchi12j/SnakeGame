#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int height=20,width=20,gameOver,flag;  //size of the boundry
int x,y,fruitX,fruitY,score;
int tailX[100],tailY[100],countTail=0;
void setup()
{
	gameOver=0;
	x=width/2;  
	y=height/2;
	
	label1:
	fruitX=rand()%20;
	
	label2:
	fruitY=rand()%20;
	//It can happen if fruit is generated at the wall ie j=0 so we have generate the fruit again.
	if(fruitX==0)
	{
		goto label1;
	}
		if(fruitY==0)
	{
		goto label2;
	}
}
//drawing board
void draw()
{
	int i,j,k;
	system("cls");
	for(i=0;i<width;i++)
	{
		for(j=0;j<height;j++)
		{
			if(i==0||j==width-1||j==0||i==height-1)
			{
				printf("*");
			}
			else
			{
			
				if(i==x && j==y)
					printf("O"); //Snake head symbol
				else if(i==fruitX && j==fruitY)
					printf("@"); //fruit symbol
				else
					{
						int ch=0;
						for(k=0;k<countTail;k++)
						{
							if(i==tailX[k] && j==tailY[k])
							{
								printf("o");  //Snake body symbol
								ch=1;
							}
						}
						if(ch==0)
							printf(" ");
					}
			}
		
		}
				printf("\n");
	}
	printf("SCORE: %d",score);
}
void input()
{
	if(kbhit())  //this is the input we get from keyboard
	{
		switch(getch())
		{
			case 'a':
				flag=1;
				break;
			case 's':
				flag=2;
				break;
			case 'w':
				flag=3;
				break;
			case 'z':
				flag=4;
				break;
			case 'x':
				gameOver=1;
				break;
		}
	}
}
void algorithm()
{
	int i;
	int prevX=tailX[0];
	int prevY=tailY[0];
	int prev2X, prev2Y;
	tailX[0]=x;
	tailY[0]=y;
	for(i=1;i<countTail;i++)
	{
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=x;
		tailY[i]=y;
		prevX=prev2X;
		prevY=prev2Y;
	}
	switch(flag)
	{
		case 1:
			y--;  //left movement of snake
			break;
		case 2:
			y++; 	//right
			break;
		case 3:
			x--;	//up
			break;
		case 4:
			x++;	//down
		default:
			break;
	}
	if(x<0||x>width||y>height||y<0)  //exceeds the boundary
		gameOver=1;
	for(i=0;i<countTail;i++)  //Snake bites itself
	{
		if(x==tailX[i]&& y==tailY[i])
			gameOver=1;
	}
	if(x==fruitX && y==fruitY)
	{
			label3:
		fruitX=rand()%20;
		
		label4:
		fruitY=rand()%20;
		//It can happen if fruit is generated at the wall ie j=0 
		if(fruitX==0)
		{
			goto label3;
		}
			if(fruitY==0)
		{
			goto label4;
		}
		score+=10;
		countTail++;
	}
}
int main()
{
	int m,n;
	char c;
	label5:
	
	setup();
	while(!gameOver)
	{
		draw();
		input();
		algorithm();
	}
	for(m=0;m<100000;m++) //to slow
	{
		for(n=0;n<10000;n++)
		{
			
		}
	}
	for(m=0;m<1000;m++) //to slow
	{
		for(n=0;n<1000;n++)
		{
			
		}
	}
	while(0){
	
	printf("\n Press Y to continue again: ");
	scanf("%c",&c);
	if(c=='y'||c=='Y')
	{
		goto label5;
	}
	else 
	break;
}
	
	return 0;
}
