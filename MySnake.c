#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
bool gameover;
const int width=20;
const int height=20;
int x,y,fruitX,fruitY,score;
int tailX[100],tailY[100]; 
int nTail;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;

void Setup()
{
	gameover=false;
	dir=STOP;
	x=width/2;  //initial position of snake
	y=height/2;
	fruitX=rand()%width;
	fruitY=rand()%height;
	score=0;
}
//=====fuction to draw board and generate fruit
void Draw_Board()
{
	system("cls");
	for(int i=0;i<width+2;i++)   
		cout<<"*";
	cout<<endl;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(j==0)
				cout<<"*";
			if(i==y&&j==x)
				cout<<"O";
			else if(i==fruitY&&j==fruitX)
				cout<<"@";
			else
			{
				bool print=false;
				for(int k=0;k<nTail;k++)
				{ 
					if(tailX[k]==j&&tailY[k]==i)
					{
						cout<<"o";
						print=true;
					}
				}
					if(!print)
					cout<<" " ;
			}
			if(j==width-1) cout<<"*";
	}
		cout<<endl;
	}
	for(int i=0;i<width+2;i++) 
		cout<<"*";
	cout<<endl;
	cout<<"Score:"<<score<<endl;
}
// function to process user input
void user_input()
{
	if(_kbhit()) //keyboard hit
	{
		switch(_getch())
		{
			case 'a':
				dir=LEFT;
				break;
			case 'd':
				dir=RIGHT;
				break;
			case 'w':
				dir=UP;
				break;
			case 's':
				dir=DOWN;
				break;
			case 'x':
				gameover=true;
				break;
		}
	}
}

//function 
void logic()
{
	int prevX =tailX[0];
	int prevY=tailY[0];
	int prev2X,prev2Y;
	tailX[0]=x;
	tailY[0]=y;
	for(int i=1;i<nTail;i++)
	{
		prev2X=tailX[i];
		prev2Y=tailY[i];
	    tailX[i]=prevX;   
		tailY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}
	switch(dir)
	{
		case LEFT:
		x--;
		break;
		case RIGHT:
		x++;
		break;
		case UP:
		y--;
		break;	
		case DOWN:
		y++;
		break;
		default:
		break;
	}
	//if boundary  is touched => exit game
	if(x<0||x>=width||y>=height||y<0)    
		gameover=true;
	//if touches itself => exit game   
	for(int i=0;i<nTail;i++)
	{
		if(x==tailX[i]&& y==tailY[i])
			gameover=true;
	}
	
	if(x>=width) x=0; else if(x<0) x=width-1;  
	if(y>=height) y=0; else if(y<0) y=height-1;
			
		if(x==fruitX && y==fruitY)
		{
			score+=10;
			fruitX =rand() % width;
			fruitY =rand() % height;
			nTail++;
		}
}

int main(){
	int m,n;
	char ch;
	cout<<" 					:::::WELCOME TO SLYTHERIN:::::					"<<endl;
	while(1)
	{
	
		cout<<"Press W to Continue"<<endl<<"Press X to Exit"<<endl;
		cin>>ch;
		system("cls");
		if(ch=='W'||ch=='w')
		{
		     Setup();
		     while(!gameover)
		     {
			     Draw_Board();
			     user_input();
			     logic();
		     }    
		}
		if(ch=='X'||ch=='x')
		{
			cout<<endl<<endl<<"				SEE YOU LATER ALLIGATOR"<<endl;
			exit(1);
		}
	}
	return 0;
}
