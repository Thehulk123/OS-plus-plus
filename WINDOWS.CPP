// **************************************************
// This is the program for mofdel of OS
// **************************************************



// **************************************************
// Header Files Includes
// **************************************************

#include <fstream.h>
#include <iostream.h>
#include <process.h>
#include <string.h>
#include <math.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "password.cpp"
#include <graphics.h>

#define PI 3.14159265
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

// **************************************************
// Function for shutdown
// **************************************************

void shutdown()
{
	clrscr();
	closegraph();
	int g=DETECT,d;
	char pass[100];
	initgraph(&g,&d,"\\TC\\BGI");
	settextstyle(GOTHIC_FONT,0,7);
	setbkcolor(1);
	int x = getmaxx()/2;
	int y = getmaxy()/2;
	setcolor(WHITE);
	outtextxy(x-120,y-100,"C++ OS");
	settextstyle(2,0,7);
	outtextxy(x-79,y+45,"shutting down...");
	setcolor(8);
	for(int circ=-50; circ<=50; circ+=25)
	{
		circle(x+circ,y+100,3);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(x+circ,y+100,8);
	}
	delay(1000);
	for(int clr=-50; clr<=50; clr+=25)
	{
		setfillstyle(SOLID_FILL,6);
		floodfill(x+clr,y+100,8);
		delay(500);
	}
	for(clr=-50; clr<=50; clr+=25)
	{
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(x+clr,y+100,8);
		delay(500);
	}
	for(clr=-50; clr<=50; clr+=25)
	{
		setfillstyle(SOLID_FILL,6);
		floodfill(x+clr,y+100,8);
		delay(500);
	}
	sound(200);
	delay(400);
	nosound();
	sound(800);
	delay(400);
	nosound();
	clrscr();
	initgraph(&g,&d,"\\TC\\BGI");
	setbkcolor(BLACK);
	delay(2000);
}


// **************************************************
// Finction for password screen
// **************************************************

int count=0;
int relog=0;
password obj;

void pwdsrc()
{
	delay(2);
	char pass[50];
	pass[0]='\0';
	closegraph();
	int g=DETECT,d;
	initgraph(&g,&d,"\\TC\\BGI");
	int x = getmaxx()/2;
	int y = getmaxy()/2;
	setbkcolor(1);
	setcolor(8);
	rectangle(x-50,y-100,x+50,y+10);
	setfillstyle(SOLID_FILL,7);
	floodfill(x,y,8);
	setcolor(WHITE);
	settextstyle(1,0,2);
	outtextxy(x-48,y+12,"ANKIT");
	settextstyle(2,0,6);
	outtextxy(x-102,y+40,"Password : ");
	settextstyle(5,0,1);
	outtextxy(5,5,"Enter password to continue or 'shutdown' to shutdown...");
	settextstyle(2,0,6);
	rectangle(x-5,y+42,x+108,y+64);
    if(obj.checkpd(pass)!=1 || relog==1)
    {
	int pasd=0;
	while(x)
	{
		pass[pasd]=getch();
		if(pass[pasd]!=13 && pass[pasd]!=8)
		{
			if(pasd<9)
				outtextxy(x+pasd*12,y+42,"*");
			pasd++;
		}
		else if(pass[pasd]==8)
		{
			if(pasd>0)
			{
				cleardevice();
				setbkcolor(1);
				setcolor(8);
				rectangle(x-50,y-100,x+50,y+10);
				setfillstyle(SOLID_FILL,7);
				floodfill(x,y,8);
				setcolor(WHITE);
				settextstyle(1,0,2);
				outtextxy(x-48,y+12,"ANKIT");
				settextstyle(2,0,6);
				outtextxy(x-102,y+40,"Password : ");
				settextstyle(5,0,1);
				outtextxy(5,5,"Enter password to continue or 'shutdown' to shutdown...");
				settextstyle(2,0,6);
				rectangle(x-5,y+42,x+108,y+64);
				for(int j=0; j<pasd-1; j++)
				{
					if(j<9)
						outtextxy(x+j*12,y+42,"*");
				}
				pass[pasd]=pass[--pasd]=00;
			}
		}
		else
		{
			pass[pasd]='\0';
			break;
		}
	}
    }
	setcolor(7);
	arc(x+124,y+53,270,90,6);
	arc(x+124,y+53,270,90,7);
	arc(x+124,y+53,270,90,8);
	int load=0;
	for(int i=0; i<=800; i++)
	{
		setcolor(7);
		arc(x+124,y+53,load+270,load+90,6);
		arc(x+124,y+53,load+274,load+94,7);
		arc(x+124,y+53,load+270,load+90,8);
		setcolor(1);
		arc(x+124,y+53,load+90,load+270,7);
		arc(x+124,y+53,load+86,load+274,8);
		arc(x+124,y+53,load+90,load+270,6);
		delay(5);
		load+=1;
		if(load==360)
			load=0;
	}
	if(strcmp(pass,"shutdown")==0 || count==4)
	{
		shutdown();
		exit(0);
	}

	if(obj.checkpd(pass)==0)
	{
		count++;
		pwdsrc();
	}
	count=0;
	cleardevice();
	setbkcolor(RED);
	delay(1000);
}

// **************************************************
// Function for logout
// **************************************************

void logout()
{
	clrscr();
	closegraph();
	int g=DETECT,d;
	char pass[100];
	initgraph(&g,&d,"\\TC\\BGI");
	settextstyle(GOTHIC_FONT,0,7);
	setbkcolor(1);
	int x = getmaxx()/2;
	int y = getmaxy()/2;
	setcolor(WHITE);
	outtextxy(x-120,y-100,"C++ OS");
	settextstyle(2,0,7);
	outtextxy(x-72,y+45,"logging out...");
	setcolor(8);
	for(int circ=-50; circ<=50; circ+=25)
	{
		circle(x+circ,y+100,3);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(x+circ,y+100,8);
	}
	delay(1000);
	for(int clr=-50; clr<=50; clr+=25)
	{
		setfillstyle(SOLID_FILL,6);
		floodfill(x+clr,y+100,8);
		delay(500);
	}
	for(clr=-50; clr<=50; clr+=25)
	{
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(x+clr,y+100,8);
		delay(500);
	}
	for(clr=-50; clr<=50; clr+=25)
	{
		setfillstyle(SOLID_FILL,6);
		floodfill(x+clr,y+100,8);
		delay(500);
	}
}

// **************************************************
// CALCULATOR PART
// **************************************************

class graphics
{
public:
    void screen(int x1,int y1,int x2,int y2)
	{
		setcolor(0);
		setfillstyle(1,0);
		rectangle(x1,y1,x2,y2);
		floodfill(x1+2,y1+2,0);
		setcolor(15);
		Rectangle(x1,y1,x2,y2,15,8);
		Rectangle(x1-1,y1-1,x2+1,y2+1,15,8);
		gotoxy(30,9);
		cout<<"0";
	}
    	
	void button(int x1,int y1,int x2,int y2,char *ch,int col)
	{
		int color;
		setcolor(col);
		setfillstyle(1,col);
		rectangle(x1,y1,x2,y2);
		floodfill(x1+2,y1+2,col);
		Rectangle(x1-1,y1-1,x2+1,y2+1,0,15);
		if(col==4)
			color=15;
		else
			color=0;
		setcolor(color);
		settextstyle(2,0,6);
		outtextxy(x1+12,y1+3,ch);
	}
    
	void pressed_button(int x1,int y1,int x2,int y2,char *ch,int col1,int col2)
	{
		button(x1,y1,x2,y2,ch,col1);
		delay(200);
		button(x1,y1,x2,y2,ch,col2);
	}

    void Rectangle(int x1,int y1,int x2,int y2,int col1,int col2)
	{
		setcolor(col1);
		line(x2,y1,x2,y2);
		line(x1,y2,x2,y2);
		setcolor(col2);
		line(x1,y1,x2,y1);
		line(x1,y1,x1,y2);
	}
    void Form(int x1,int y1,int x2,int y2,int col1,int col2,char *ch)
	{
		setcolor(col1);
		setfillstyle(1,col1);
	    rectangle(x1,y1,x2,y2);
		floodfill(x1+2,y1+2,col1);
		setcolor(col2);
		setfillstyle(1,col2);
		rectangle(x1,y1,x2,y1+20);
		floodfill(x1+2,y1+2,col2);
		Rectangle(x1-1,y1-1,x2+1,y2+1,8,15);
		Rectangle(x1-2,y1-2,x2+2,y2+2,8,15);
		setcolor(15);
		settextstyle(2,0,5);
		outtextxy(x1+8,y1+2,ch);
    }
       
	void Interface()
    {
		setcolor(15);
		settextstyle(1,0,4);
		outtextxy(170,20,"Simple Calculator");
		setcolor(0);
		setfillstyle(1,0);
		rectangle(220,90,410,340);
		floodfill(222,92,0);
		Form(210,80,400,330,7,4,"Calculator");
		screen(225,120,385,145);
		int x1=220,y1=175,x2=250,y2=200;
	 	int col=4;
		button(x1,y1,x2,y2,"7",col);
		button(x1+=35,y1,x2+=35,y2,"8",col);
		button(x1+=35,y1,x2+=35,y2,"9",col);
		button(x1+=35,y1,x2+=35,y2,"v-",col);
		button(x1+=35,y1,x2+=35,y2,"C",col);
      	y1+=35;
      	y2+=35;
      	x1=220;
      	x2=250;
   		button(x1,y1,x2,y2,"4",col);
   		button(x1+=35,y1,x2+=35,y2,"5",col);
   		button(x1+=35,y1,x2+=35,y2,"6",col);
   		button(x1+=35,y1,x2+=35,y2,"*",col);
   		button(x1+=35,y1,x2+=35,y2,"/",col);
      	y1+=35;
      	y2+=35;
      	x1=220;
      	x2=250;
   		button(x1,y1,x2,y2,"1",col);
   		button(x1+=35,y1,x2+=35,y2,"2",col);
		button(x1+=35,y1,x2+=35,y2,"3",col);
   		button(x1+=35,y1,x2+=35,y2,"+",col);
   		button(x1+=35,y1,x2+=35,y2,"-",col);
      	y1+=35;
      	y2+=35;
      	x1=220;
      	x2=250;
   		button(x1,y1,x2,y2,"0",col);
   		button(x1+=35,y1,x2+=35,y2,".",col);
   		button(x1+=35,y1,x2+=35,y2,"^2",col);
   		button(x1+=35,y1,x2+=35,y2,"A",col);
   		button(x1+=35,y1,x2+=35,y2,"=",col);

		setcolor(14);
		settextstyle(1,0,3);
		outtextxy(185,380,"Press Escape To Exit");
		setcolor(15);
		settextstyle(7,0,2);
		// outtextxy(440,100,"Instructions");
		setcolor(10);
		settextstyle(8,0,1);
		// outtextxy(430,150,"Press 'v' For v-");
		// outtextxy(430,200,"Press '^' For ^");
		// outtextxy(430,250,"Press 'c' For Clear");
    }
};

void calculator_main()
{
  	int gd=DETECT,gm;
   	initgraph(&gd,&gm,"..\\bgi");
   	cleardevice();
   	
	int col=1;
    setcolor(col);
	setfillstyle(1,col);
	rectangle(0,0,625,475);
	floodfill(2,2,col);
	setcolor(7);
	rectangle(0,0,625,475);
	rectangle(1,1,624,474);
	rectangle(3,3,622,472);

   	graphics g;
   	g.Interface();

	char ch,a1[25],a2[25];
 	int x=0,c=30,r=9,pi=0;
 	int clear=0,equals=0,equal1=0,answer=0;
 	float val1,val2;
 	float result;
 	int sum=0,mul=0,div=0,sub=0;
 	do
  	{
  		gotoxy(c,r);
  		ch=getch();
  		if(clear==1||equals==1||answer==1||pi==1)
    	{	
    		gotoxy(30,9);
    		cout<<"0                 ";
    		clear=0;
    		equals=0;
    		answer=0;
    		pi=0;
    	}

  		if(x>9&&(!(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='='||ch=='c'||ch=='C'||ch=='u'||ch=='U')))
      		continue;
		gotoxy(c,r);
  		
		switch(ch)
   		{	
    		case'1':
    		g.pressed_button(220,245,250,270,"1",14,4);
    		cout<<"1";
    		break;
    		case'2':
    		g.pressed_button(255,245,285,270,"2",14,4);
    		cout<<"2";
    		break;
    		case'3':
    		g.pressed_button(290,245,320,270,"3",14,4);
    		cout<<"3";
    		break;
    		case'4':
    		g.pressed_button(220,210,250,235,"4",14,4);
    		cout<<"4";
    		break;
    		case'5':
    		g.pressed_button(255,210,285,235,"5",14,4);
    		cout<<"5";
    		break;
    		case'6':
    		g.pressed_button(290,210,320,235,"6",14,4);
    		cout<<"6";
    		break;
    		case'7':
    		g.pressed_button(220,175,250,200,"7",14,4);
    		cout<<"7";
    		break;
    		case'8':
    		g.pressed_button(255,175,285,200,"8",14,4);
    		cout<<"8";
    		break;
   			case'9':
    		g.pressed_button(290,175,320,200,"9",14,4);
    		cout<<"9";
    		break;
    		case'C':case'c':
        	g.pressed_button(360,175,390,200,"C",14,4);
    		gotoxy(30,9);
      		cout<<"0                  ";
      		sum=0;mul=0;div=0;sub=0;
      		c=30;r=9;x=0;
      		clear=1;
      		continue;

    		case'*':
       		g.pressed_button(325,210,355,235,"*",14,4);
      		a1[x]='\0';
      		val1=atof(a1);
      		mul=1;
      		c=30;r=9;x=0;
      		clear=1;
      		continue;

    		case'/':
      		g.pressed_button(360,210,390,235,"/",14,4);
      		a1[x]='\0';
      		val1=atof(a1);
      		div=1;
      		c=30;r=9;x=0;
      		clear=1;
      		continue;
    		//break;

    		case'+':
      		g.pressed_button(325,245,355,270,"+",14,4);
      		a1[x]='\0';
      		val1=atof(a1);
      		sum=1;
      		c=30;r=9;x=0;
      		clear=1;
      		continue;
    		//break;
    		
			case'-':
      		g.pressed_button(360,245,390,270,"-",14,4);
      		a1[x]='\0';
      		val1=atof(a1);
      		sub=1;
      		c=30;r=9;x=0;
      		clear=1;
      		continue;
    		//break;
    		
			case'^':
    		// g.pressed_button(290,280,320,305,"^2",14,4);
    		// gotoxy(30,9);
    		// cout<<"                   " ;
    		// gotoxy(30,9);
    		// cout<<"3.14";
    		// pi=1;
    		// continue;
   	 		// //break;
			a1[x]='\0';
      		val1=atof(a1);
      		result=pow(val1,2);
      		gotoxy(30,9);
      		cout<<"             ";
      		gotoxy(30,9);
      		cout<<result;
      		c=30;r=9;x=0;
      		clear=1;
      		continue;
    		//break;

    		case'v': case'V':
      		g.pressed_button(325,175,355,200,"v-",14,4);
      		a1[x]='\0';
      		val1=atof(a1);
      		result=sqrt(val1);
      		gotoxy(30,9);
      		cout<<"             ";
      		gotoxy(30,9);
      		cout<<result;
      		c=30;r=9;x=0;
      		clear=1;
      		continue;
    		//break;
    		
			case'A':case'a':
    		g.pressed_button(325,280,355,305,"A",14,4);
    		if(equal1==1)
    		{
    			gotoxy(30,9);
    			cout<<"                ";
    			gotoxy(30,9);
    			cout<<result;
    		}
    		answer=1;
    		continue;
    		//break;
    
			case'=':
      		a2[x]='\0';
      		val2=atof(a2);
      		g.pressed_button(360,280,390,305,"=",14,4);
      		gotoxy(30,9);
      		cout<<"0                 ";
      		if(sum==1)
      		{
      			result=val1+val2;
     			gotoxy(30,9);
      			cout<<result;
      		}
      		else if(div==1)
      		{	
			    if(val2==0)
      			{
      				gotoxy(30,9);
      				cout<<"ì";
     			}
      			else
      			{
      				result=val1/val2;
      				gotoxy(30,9);
      				cout<<result;
      			}
      		}
      		else if(mul==1)
      		{
     		 	result=val1*val2;
      			gotoxy(30,9);
      			cout<<result;
      		}
      		else if(sub==1)
      		{
      			result=val1-val2;
      			gotoxy(30,9);
      			cout<<result;
      		}
    		equals=1;
   	 		equal1=1;
       		c=30;r=9,x=0;
       		continue;
    		//break;
    	
			case'.':
     	 		g.pressed_button(255,280,285,305,".",14,4);
      			if(x>0)
      			cout<<".";
    		  	else continue;
    			break;
    		
			case'0':
     	 		g.pressed_button(220,280,250,305,"0",14,4);
      			if(x>0)
      			cout<<"0";
      			else continue;
    			break;
  			
			default:
       			continue;
   		}
   
   		c++;
   		if(sum==0 && sub==0 && mul==0 && div==0)
       		a1[x]=ch;
    	else
       		a2[x]=ch;
    	x++;

  	}while(ch!=27);

  	closegraph();
}

// **************************************************
// GAME PART
// **************************************************

void game_main()
{
	start: int a[3][3]={5,6,7,8,9,10,11,12,13},i,j,k,x,y,t,cn=0,co=0;
	char c;
	static int nod=0,nn=0,sc[2]={0,0};
	nod++;
	
	clrscr();
	int driver=DETECT,mode;
	initgraph(&driver,&mode,"c:\tc\bgi");
	
	setbkcolor(RED);
	line(100,200,400,200);
	line(100,300,400,300);
	line(200,100,200,400);
	line(300,100,300,400);
	gotoxy(20,2);cout<<"TIC TAC TOE";
	gotoxy(10,5);cout<<" BOX NO ";
	gotoxy(15,7);cout<<"0";
	gotoxy(30,7);cout<<"1";
	gotoxy(45,7);cout<<"2";
	gotoxy(15,14);cout<<"3";
	gotoxy(30,14);cout<<"4";	
	gotoxy(45,14);cout<<"5";
	gotoxy(15,21);cout<<"6";
	gotoxy(30,21);cout<<"7";
	gotoxy(45,21);cout<<"8";
	gotoxy(55,22);cout<<"RESULT";
	gotoxy(55,23);cout<<"****************";
	gotoxy(55,15);cout<<"P1-"<<sc[0];
	gotoxy(55,16);cout<<"P2-"<<sc[1];
	
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{ 
			re:
			gotoxy(65,4);
			k=((i+j)%2+1);
			cout<<"Enter player"<<k;
			gotoxy(60,5);
			cout<<" Box no from 0 to 8   ";
			gotoxy(58,6);cout<<"[   ]";
			gotoxy(60,6);
			t=getch();
			t=t-48;
			if(t==0)
			{
				x=0;y=0;goto play;
			}
			if(t==1)
			{
				x=1;y=0;goto play;
			}
			if(t==2)
			{
				x=2;y=0;goto play;
			}
			if(t==3)
			{
				x=0;y=1;goto play;
			}
			if(t==4)
			{
				x=1;y=1;goto play;
			}
			if(t==5)
			{
				x=2;y=1;goto play;
			}
			if(t==6)
			{
				x=0;y=2;goto play;
			}
			if(t==7)
			{
				x=1;y=2;goto play;
			}
			if(t==8)
			{
				x=2;y=2;goto play;
			}
			else
			{
				goto re ;
			}
			
			play:
			if( (a[x][y]==1) || (a[x][y]==2) )
			{
				goto re;
			}
			if( (a[x][y]!=1) && (a[x][y]!=2) )
			{ 
				if(k==1)
				{
					circle(100*x+100+50,100*y+100+50,50);
					a[x][y]=k;co++;
				} 
				if(k==2)
				{
					line(x*100+100,y*100+100,x*100+200,y*100+200);
					line(x*100+100,y*100+200,x*100+200,y*100+100);
					a[x][y]=k;co++;
				}
			}
			gotoxy(60,23);
			if( (a[0][0]==a[1][0]) && (a[1][0]==a[2][0]) )
			{
				cout<<"Player "<<k<<" wins";cn=1;sc[k-1]++;
			}
			if( (a[0][0]==a[0][1]) && (a[0][1]==a[0][2]) )
			{
				cout<<"Player "<<k<<" wins";cn=1;sc[k-1]++;
			}
			if( (a[0][0]==a[1][1]) && (a[1][1]==a[2][2]) )
			{
				cout<<"Player "<<k<<" wins";cn=1;sc[k-1]++;
			}
			if( (a[1][0]==a[1][1]) && (a[1][1]==a[1][2]) )
			{
				cout<<"Player "<<k<<" wins";cn=1;sc[k-1]++;
			}
			if( (a[2][0]==a[2][1]) && (a[2][1]==a[2][2]) )
			{
				cout<<"Player "<<k<<" wins";cn=1;sc[k-1]++;
			}
			if( (a[2][0]==a[1][1]) && (a[1][1]==a[0][2]) )
			{
				cout<<"Player "<<k<<" wins";cn=1;sc[k-1]++;
			}
			if( (a[0][2]==a[1][2]) && (a[1][2]==a[2][2]) )
			{
				cout<<"Player "<<k<<" wins";cn=1;sc[k-1]++;
			}
			if((a[0][1]==a[1][1])&&(a[1][1]==a[2][1]))
			{
				cout<<"Player "<<k<<" wins";cn=1;sc[k-1]++;
			}
			if(cn==1)
			{
				goto que;
			}
			if(co==9)
			{
				gotoxy(62,23);cout<<"DRAW";nn++;goto que;
			}
		}
	}

	que:
	gotoxy(60,24);
	cout<<"Play again y/n";
	c=getch();
	if( (c=='y') || (c=='Y' ))
	{	
		goto start;
	}
	else if( (c=='n') || (c=='N') )
	{
		goto end;
	}
	else goto que;

	end:
	closegraph();
	cout<<"Final score is "<<sc[k-1]<<"-"<<nod-nn-sc[k-1];
	gotoxy(20,10);
	cout<<"Thanks for playing this game";
	getch();
}

// **************************************************
// Main Function
// **************************************************

void main()
{
	start:
	clrscr();
	int g=DETECT,d;
	initgraph(&g,&d,"\\TC\\BGI");
	settextstyle(GOTHIC_FONT,0,9);
	setbkcolor(1);
	int x = getmaxx()/2;
	int y = getmaxy()/2;
	char src='n';
	setcolor(WHITE);
	outtextxy(x-175,y-130,"C++ OS");
	setcolor(8);
	for(int circ=-50; circ<=50; circ+=25)
	{
		circle(x+circ,y+100,3);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(x+circ,y+100,8);
	}
	delay(1000);
	for(int clr=-50; clr<=50; clr+=25)
	{
		setfillstyle(SOLID_FILL,6);
		floodfill(x+clr,y+100,8);
		delay(500);
	}
	for(clr=-50; clr<=50; clr+=25)
	{
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(x+clr,y+100,8);
		delay(500);
	}
	for(clr=-50; clr<=50; clr+=25)
	{
		setfillstyle(SOLID_FILL,6);
		floodfill(x+clr,y+100,8);
		delay(500);
	}
	closegraph();
	initgraph(&g,&d,"\\TC\\BGI");
	setbkcolor(1);
	sound(200);
	delay(400);
	nosound();
	sound(100);
	delay(400);
	nosound();
	sound(200);
	delay(400);
	nosound();
	sound(300);
	delay(800);
	nosound();
	delay(700); 
	l1:
	pwdsrc();
	l2:
	closegraph();
	initgraph(&g,&d,"\\TC\\BGI");
	setbkcolor(RED);
	setcolor(YELLOW);
	for(int i=10; i<x*2-20; i+=4)
	{
		outtextxy(i,10,"#");
		outtextxy(i,y*2-20,"#");
	}
	for(i=10; i<y*2-20; i+=2)
	{
		outtextxy(x*2-20,i,"#");
		outtextxy(10,i,"#");
	}
	char choice;
	char YorN='y',NorY='y';
	char onetwo,twoone,arrow;
	outtextxy(x-76,23,"* * * WELCOME * * *");
	settextstyle(2,0,5);

	//CALCULATOR
	setcolor(3);
	rectangle(x-275,90,x-225,140);
	circle(x-250,115,23);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,2);
	floodfill(x-250,115,3);
	setcolor(1);
	settextstyle(4,0,1);
	outtextxy(x-265,92,"+");
	outtextxy(x-245,92,"-");
	outtextxy(x-264,108,"o");
	outtextxy(x-245,110,"=");
	settextstyle(2,0,5);

	//DESKTOP
	setcolor(3);
	rectangle(x-145,90,x-95,140);
	rectangle(x-140,95,x-100,128);
	rectangle(x-137,98,x-103,125);
	setfillstyle(SOLID_FILL,7);
	floodfill(x-138,96,3);
	setfillstyle(SOLID_FILL,1);
	floodfill(x-130,100,3);

	//LOGOUT
	setcolor(3);
	rectangle(x,90,x+50,140);
	circle(x+25,115,23);
	setcolor(WHITE);
	arc(x+22,115,25,335,12);
	arc(x+22,115,25,335,11);
	rectangle(x+25,114.5,x+40,115.5);
	line(x+37,111,x+40,115.5);
	line(x+37,112,x+40,115.5);
	line(x+37,117.5,x+40,115.5);
	line(x+37,118.5,x+40,115.5);

	//SHUTDOWN
	setcolor(3);
	rectangle(x+120,90,x+170,140);
	circle(x+145,115,23);
	setcolor(15);
	arc(x+145,118,115,65,12);
	arc(x+145,118,115,65,11);
	rectangle(x+145.5,115,x+144.5,102);

	//RESTART
	setcolor(3);
	rectangle(x+230,90,x+280,140);
	circle(x+255,115,23);
	setcolor(15);
	arc(x+255,115,300,240,12);
	arc(x+255,115,300,240,11);
	line(x+260,120,x+259,125);
	line(x+259,120,x+258,126);
	line(x+263,129,x+259,125);
	line(x+262,129,x+258,126);

	//SETTING
	setcolor(3);
	rectangle(x-275,170,x-225,220);
	circle(x-250,195,23);
	setcolor(7);
	arc(x-250,190,5,175,8);
	arc(x-250,190,5,175,9);
	setcolor(15);
	rectangle(x-262,190,x-238,205);
	circle(x-250,198,2);
	rectangle(x-251,200,x-249,204);
	setfillstyle(SOLID_FILL,8);
	floodfill(x-261,191,15);

	//GAME
	setcolor(3);
	rectangle(x-145,170,x-90,220);
	int polypoint[]={x-132,176,x-103,176,x-92,193,x-92,210,x-109,210,x-114,200,x-121,200,x-126,210,x-143,210,x-143,193,x-132,176};
	drawpoly(11,polypoint);
	circle(x-133,200,7);
	circle(x-102,200,7);
	circle(x-125,185,6);
	circle(x-110,185,6);
	setfillstyle(1,1);
	floodfill(x-133,200,3);
	floodfill(x-102,200,3);
	floodfill(x-125,185,3);
	floodfill(x-110,185,3);
	setfillstyle(1,7);
	floodfill(x-131,177,3);
	setcolor(15);
	outtextxy(x-127,177,"+");
	outtextxy(x-112,177,"-");
	outtextxy(x-135,191,"x");
	outtextxy(x-104,191,"o");

	onetwo=twoone='1';
	long unsigned late;
	while(onetwo!=13)
	{
		twoone=onetwo;
		if(twoone=='1')
		{
			setcolor(3);
			line(x-120,129,x-115,134);
			line(x-120,129,x-125,134);
			line(x-120,130,x-115,134);
			line(x-120,130,x-125,134);
			line(x-119,129,x-114,134);
			line(x-121,129,x-126,134);
			setfillstyle(SOLID_FILL,8);
			setcolor(14);
			floodfill(x-274,91,3);
			outtextxy(x-300,140,"1. Calculator");
			setfillstyle(SOLID_FILL,RED);
			setcolor(15);
			floodfill(x-144,91,3);
			outtextxy(x-170,140,"2. Screen saver");
			floodfill(x+2,91,3);
			outtextxy(x-20,140,"3. Log out");
			floodfill(x+121,91,3);
			outtextxy(x+95,140,"4. Shutdown");
			floodfill(x+231,91,3);
			outtextxy(x+215,140,"5. Restart");
			floodfill(x-274,171,3);
			outtextxy(x-300,220,"6. Setting");
			floodfill(x-144,171,3);
			outtextxy(x-145,220,"7. Game");
		}
		else if(twoone=='2')
		{
			floodfill(x-274,91,3);
			outtextxy(x-300,140,"1. Calculator");
			setfillstyle(SOLID_FILL,8);
			setcolor(14);
			floodfill(x-144,91,3);
			outtextxy(x-170,140,"2. Screen saver");
			setfillstyle(SOLID_FILL,RED);
			setcolor(7);
			line(x-120,129,x-115,134);
			line(x-120,129,x-125,134);
			line(x-120,130,x-115,134);
			line(x-120,130,x-125,134);
			line(x-119,129,x-114,134);
			line(x-121,129,x-126,134);
			setcolor(15);
			floodfill(x+2,91,3);
			outtextxy(x-20,140,"3. Log out");
			floodfill(x+121,91,3);
			outtextxy(x+95,140,"4. Shutdown");
			floodfill(x+231,91,3);
			outtextxy(x+215,140,"5. Restart");
			floodfill(x-274,171,3);
			outtextxy(x-300,220,"6. Setting");
			floodfill(x-144,171,3);
			outtextxy(x-145,220,"7. Game");
		}
		else if(twoone=='3')
		{
			setcolor(3);
			line(x-120,129,x-115,134);
			line(x-120,129,x-125,134);
			line(x-120,130,x-115,134);
			line(x-120,130,x-125,134);
			line(x-119,129,x-114,134);
			line(x-121,129,x-126,134);
			setcolor(15);
			floodfill(x-274,91,3);
			outtextxy(x-300,140,"1. Calculator");
			floodfill(x-144,91,3);
			outtextxy(x-170,140,"2. Screen saver");
			setfillstyle(SOLID_FILL,8);
			setcolor(14);
			floodfill(x+2,91,3);
			outtextxy(x-20,140,"3. Log out");
			setfillstyle(SOLID_FILL,RED);
			setcolor(15);
			floodfill(x+121,91,3);
			outtextxy(x+95,140,"4. Shutdown");
			floodfill(x+231,91,3);
			outtextxy(x+215,140,"5. Restart");
			floodfill(x-274,171,3);
			outtextxy(x-300,220,"6. Setting");
			floodfill(x-144,171,3);
			outtextxy(x-145,220,"7. Game");
		}
		else if(twoone=='4')
		{
			setcolor(3);
			line(x-120,129,x-115,134);
			line(x-120,129,x-125,134);
			line(x-120,130,x-115,134);
			line(x-120,130,x-125,134);
			line(x-119,129,x-114,134);
			line(x-121,129,x-126,134);
			setcolor(15);
			floodfill(x-274,91,3);
			outtextxy(x-300,140,"1. Calculator");
			floodfill(x-144,91,3);
			outtextxy(x-170,140,"2. Screen saver");
			floodfill(x+2,91,3);
			outtextxy(x-20,140,"3. Log out");
			setfillstyle(SOLID_FILL,8);
			setcolor(14);
			floodfill(x+121,91,3);
			outtextxy(x+95,140,"4. Shutdown");
			setfillstyle(SOLID_FILL,RED);
			setcolor(15);
			floodfill(x+231,91,3);
			outtextxy(x+215,140,"5. Restart");
			floodfill(x-274,171,3);
			outtextxy(x-300,220,"6. Setting");
			floodfill(x-144,171,3);
			outtextxy(x-145,220,"7. Game");
		}
		else if(twoone=='5')
		{
			setcolor(3);
			line(x-120,129,x-115,134);
			line(x-120,129,x-125,134);
			line(x-120,130,x-115,134);
			line(x-120,130,x-125,134);
			line(x-119,129,x-114,134);
			line(x-121,129,x-126,134);
			setcolor(15);
			floodfill(x-274,91,3);
			outtextxy(x-300,140,"1. Calculator");
			floodfill(x-144,91,3);
			outtextxy(x-170,140,"2. Screen saver");
			floodfill(x+2,91,3);
			outtextxy(x-20,140,"3. Log out");
			floodfill(x+121,91,3);
			outtextxy(x+95,140,"4. Shutdown");
			setfillstyle(SOLID_FILL,8);
			setcolor(14);
			floodfill(x+231,91,3);
			outtextxy(x+215,140,"5. Restart");
			setfillstyle(SOLID_FILL,RED);
			setcolor(15);
			floodfill(x-274,171,3);
			outtextxy(x-300,220,"6. Setting");
			floodfill(x-144,171,3);
			outtextxy(x-145,220,"7. Game");
		}
		else if(twoone=='6')
		{
			setcolor(3);
			line(x-120,129,x-115,134);
			line(x-120,129,x-125,134);
			line(x-120,130,x-115,134);
			line(x-120,130,x-125,134);
			line(x-119,129,x-114,134);
			line(x-121,129,x-126,134);
			setcolor(15);
			floodfill(x-274,91,3);
			outtextxy(x-300,140,"1. Calculator");
			floodfill(x-144,91,3);
			outtextxy(x-170,140,"2. Screen saver");
			floodfill(x+2,91,3);
			outtextxy(x-20,140,"3. Log out");
			floodfill(x+121,91,3);
			outtextxy(x+95,140,"4. Shutdown");
			floodfill(x+231,91,3);
			outtextxy(x+215,140,"5. Restart");
			setfillstyle(SOLID_FILL,8);
			setcolor(14);
			floodfill(x-274,171,3);
			outtextxy(x-300,220,"6. Setting");
			setfillstyle(SOLID_FILL,RED);
			setcolor(15);
			floodfill(x-144,171,3);
			outtextxy(x-145,220,"7. Game");
		}
		else if(twoone=='7')
		{
			setcolor(3);
			line(x-120,129,x-115,134);
			line(x-120,129,x-125,134);
			line(x-120,130,x-115,134);
			line(x-120,130,x-125,134);
			line(x-119,129,x-114,134);
			line(x-121,129,x-126,134);
			setcolor(15);
			floodfill(x-274,91,3);
			outtextxy(x-300,140,"1. Calculator");
			floodfill(x-144,91,3);
			outtextxy(x-170,140,"2. Screen saver");
			floodfill(x+2,91,3);
			outtextxy(x-20,140,"3. Log out");
			floodfill(x+121,91,3);
			outtextxy(x+95,140,"4. Shutdown");
			floodfill(x+231,91,3);
			outtextxy(x+215,140,"5. Restart");
			floodfill(x-274,171,3);
			outtextxy(x-300,220,"6. Setting");
			setfillstyle(SOLID_FILL,8);
			floodfill(x-144,171,3);
			setcolor(14);
			outtextxy(x-145,220,"7. Game");
			setfillstyle(SOLID_FILL,RED);
			setcolor(15);
		}
		if(src=='y')
		{
			onetwo=twoone='2';
			src='n';
			break;
		}
		late=0;
		fstream screen("srcsav.dar",ios::noreplace|ios::out);
		screen<<"screen3";
		screen.close();
		while(!kbhit())
		{
			late++;
			if(late==27000000)
			{
				ifstream ifs("srcsav.dar");
				char buffer[10];
				ifs.getline(buffer,10);
				ifs.close();
				if(strcmp(buffer,"screen1")==0)
					goto screensaver1;
				else if(strcmp(buffer,"screen2")==0)
					goto screensaver2;
				else
					goto screensaver3;
			}
		}
		onetwo=getch();
		if(onetwo=='\0')
		{
			arrow=getch();
			if(arrow==DOWN)
			{   if(twoone=='1'|| twoone=='6')
					onetwo='6';
				else
					onetwo='7';
			}
			else if(arrow==UP)
			{
				if(twoone=='6')
					onetwo='1';
				else if(twoone=='7')
					onetwo='2';
				else
					onetwo=twoone;
			}
			else if(arrow==LEFT)
			{
				if(twoone!='1')
					onetwo=(--twoone);
				else
					onetwo=twoone;
			}
			else if(arrow==RIGHT)
			{
				if(twoone!='7')
					onetwo=(++twoone);
				else
					onetwo=twoone;
			}
		}
		else if((onetwo<'1' || onetwo>'7') && onetwo!=13)
			onetwo=twoone;
	}
	choice = twoone;
	setcolor(14);
	switch(choice)
	{
		case '1':
		//Calculator
			  calculator_main();
			  goto l2;
		case '2':
		//Screen Saver
		   rectangle(x-160,220,x+220,395);
		   rectangle(x-165,215,x+225,400);
		   setfillstyle(SOLID_FILL,RED);
		   floodfill(x-159,221,YELLOW);
		   setfillstyle(SOLID_FILL,8);
		   floodfill(x-162,217,YELLOW);
		   settextstyle(2,0,6);
		   outtextxy(x-140,260,"1. Moving ball");
		   outtextxy(x-140,290,"2. Circles");
		   outtextxy(x-140,320,"3. Stars");
		   settextstyle(8,0,1);
		   onetwo=11;
		   while(onetwo!=13)
		   {
			twoone=onetwo;
			if(twoone==11)
			{
				setcolor(2);
				outtextxy(x+40,257,"PREVIEW");
				setcolor(15);
				outtextxy(x+150,257,"APPLY");
				outtextxy(x+40,287,"PREVIEW");
				outtextxy(x+150,287,"APPLY");
				outtextxy(x+40,317,"PREVIEW");
				outtextxy(x+150,317,"APPLY");
				outtextxy(x+100,357,"CANCEL");
			}
			else if(twoone==12)
			{
				outtextxy(x+40,257,"PREVIEW");
				setcolor(2);
				outtextxy(x+150,257,"APPLY");
				setcolor(15);
				outtextxy(x+40,287,"PREVIEW");
				outtextxy(x+150,287,"APPLY");
				outtextxy(x+40,317,"PREVIEW");
				outtextxy(x+150,317,"APPLY");
			}
			else if(twoone==21)
			{
				outtextxy(x+40,257,"PREVIEW");
				outtextxy(x+150,257,"APPLY");
				setcolor(2);
				outtextxy(x+40,287,"PREVIEW");
				setcolor(15);
				outtextxy(x+150,287,"APPLY");
				outtextxy(x+40,317,"PREVIEW");
				outtextxy(x+150,317,"APPLY");
			}
			else if(twoone==22)
			{
				outtextxy(x+40,257,"PREVIEW");
				outtextxy(x+150,257,"APPLY");
				outtextxy(x+40,287,"PREVIEW");
				setcolor(2);
				outtextxy(x+150,287,"APPLY");
				setcolor(15);
				outtextxy(x+40,317,"PREVIEW");
				outtextxy(x+150,317,"APPLY");
			}
			else if(twoone==31)
			{
				outtextxy(x+40,257,"PREVIEW");
				outtextxy(x+150,257,"APPLY");
				outtextxy(x+40,287,"PREVIEW");
				outtextxy(x+150,287,"APPLY");
				setcolor(2);
				outtextxy(x+40,317,"PREVIEW");
				setcolor(15);
				outtextxy(x+150,317,"APPLY");
				outtextxy(x+100,357,"CANCEL");
			}
			else if(twoone==32)
			{
				outtextxy(x+40,257,"PREVIEW");
				outtextxy(x+150,257,"APPLY");
				outtextxy(x+40,287,"PREVIEW");
				outtextxy(x+150,287,"APPLY");
				outtextxy(x+40,317,"PREVIEW");
				setcolor(2);
				outtextxy(x+150,317,"APPLY");
				setcolor(15);
				outtextxy(x+100,357,"CANCEL");
			}
			else if(twoone==41 || twoone==42)
			{
				outtextxy(x+40,317,"PREVIEW");
				outtextxy(x+150,317,"APPLY");
				setcolor(2);
				outtextxy(x+100,357,"CANCEL");
				setcolor(15);
			}
			onetwo=getch();
			if(onetwo=='\0')
			{
				arrow=getch();
				if(arrow==UP)
				{
					if(twoone>12)
						onetwo=twoone-10;
					else
						onetwo=twoone;
				}
				else if(arrow==DOWN)
				{
					if(twoone<40)
						onetwo=twoone+10;
					else
						onetwo=twoone;
				}
				else if(arrow==LEFT)
				{
					if(twoone==32 || twoone==22 || twoone==12)
						onetwo=twoone-1;
					else
						onetwo=twoone;
				}
				else if(arrow==RIGHT)
				{
					if(twoone==11 || twoone==21 || twoone==31)
						onetwo=twoone+1;
					else
						onetwo=twoone;
				}
				else
					onetwo=twoone;
			}
			else if(onetwo!=13)
				onetwo=twoone;
		   }
		   if(twoone==41 || twoone==42)
			goto l2;
		   else if(twoone==11)
		   {
			screensaver1:
			closegraph();
			initgraph(&g,&d,"\\TC\\BGI");
			setbkcolor(7);
			int bx=60,by=60;
			int outy=1;
			int outx=1;
			while(!kbhit())
			{
				cleardevice();
				circle(bx,by,20);
				line(0,40,x*2,40);
				line(0,(y*2)-85,x*2,(y*2)-85);
				setcolor(WHITE);
				setfillstyle(SOLID_FILL,RED);
				floodfill(bx,by,WHITE);
				delay(10);
				if(by<60 || by>(y*2)-105)
					outy=!outy;
				if(outy)
					by+=2;
				else
					by-=2;

				if(bx<20 || bx>(x*2)-20)
					outx=!outx;
				if(outx)
					bx+=2;
				else
					bx-=2;
			}
			getch();
		   }
		   else if(twoone==21)
		   {
			screensaver2:
			closegraph();
			initgraph(&g,&d,"\\TC\\BGI");
			setbkcolor(7);
			while(!kbhit())
			{
				int a=rand();
				setcolor(a);
				for(int i=0; i<40; ++i)
				{
					circle(x,y,i);
					delay(2);
				}
				setcolor(a+3);
				for(int j=45; j<85; ++j)
				{
					circle(x,y,j);
					delay(2);
				}
				setcolor(a-3);
				for(int k=90; k<130; ++k)
				{
					circle(x,y,k);
					delay(2);
				}
				setcolor(a+8);
				for(int l=135; l<175; ++l)
				{
					circle(x,y,l);
					delay(2);
				}
				delay(400);
			}
			getch();
		   }
		   else if(twoone==31)
		   {
			screensaver3:
			closegraph();
			initgraph(&g,&d,"\\TC\\BGI");
			setbkcolor(BLACK);
			while(!kbhit())
			{
				for(int i=0; i<500; i++)
				{
					putpixel(rand()%(x*2),rand()%(y*2),15);
				}
				delay(100);
				cleardevice();
			}
			getch();
		   }
		   if(twoone==11 || twoone==21 || twoone==31)
		   {
			src='y';
			goto l2;
		   }
		   else
		   {
			ofstream ofs("srcsav.dar");
			if(twoone==12)
				ofs<<"screen1";
			else if(twoone==22)
				ofs<<"screen2";
			else
				ofs<<"screen3";
			ofs.close();
			goto l2;
		   }
		case '3':
		//LOGOUT
			outtextxy(x-125,240,"Are you sure you want to logout?");
			rectangle(x-155,220,x+150,335);
			rectangle(x-160,215,x+155,340);
			setfillstyle(SOLID_FILL,RED);
			floodfill(x-154,221,YELLOW);
			setfillstyle(SOLID_FILL,8);
			floodfill(x-157,217,YELLOW);
			settextstyle(1,0,1);
			while(YorN!=13)
			{
				if(YorN=='n' || YorN=='N')
				{
					NorY=YorN;
					setcolor(7);
					outtextxy(x-70,290,"YES");
					setcolor(YELLOW);
					outtextxy(x+40,290,"NO");
				}
				else if(YorN=='y'||YorN=='Y')
				{
					NorY=YorN;
					setcolor(YELLOW);
					outtextxy(x-70,290,"YES");
					setcolor(7);
					outtextxy(x+40,290,"NO");
				}
				YorN=getch();
				if(YorN=='\0')
				{
					arrow=getch();
					if(arrow==75 || arrow==77)
					{
						 if(NorY=='y' || NorY=='Y')
						  YorN='n';
						 else
						  YorN='y';
					}
				}
			}
			if(NorY=='y' || NorY=='Y')
			{
				cleardevice();
				setbkcolor(RED);
				delay(1500);
				relog=1;
				logout();
				goto l1;
			}
			else
				goto l2;
		case '4':
		//SHUTDOWN
			outtextxy(x-125,240,"Are you sure you want to shutdown?");
			rectangle(x-155,220,x+160,335);
			rectangle(x-160,215,x+165,340);
			setfillstyle(SOLID_FILL,RED);
			floodfill(x-154,221,YELLOW);
			setfillstyle(SOLID_FILL,8);
			floodfill(x-157,217,YELLOW);
			settextstyle(1,0,1);
			while(YorN!=13)
			{
				if(YorN=='n' || YorN=='N')
				{
					NorY=YorN;
					setcolor(7);
					outtextxy(x-70,290,"YES");
					setcolor(YELLOW);
					outtextxy(x+40,290,"NO");
				}
				else if(YorN=='y'||YorN=='Y')
				{
					NorY=YorN;
					setcolor(YELLOW);
					outtextxy(x-70,290,"YES");
					setcolor(7);
					outtextxy(x+40,290,"NO");
				}
				YorN=getch();
				if(YorN=='\0')
				{
					arrow=getch();
					if(arrow==75 || arrow==77)
					{
						 if(NorY=='y' || NorY=='Y')
						  YorN='n';
						 else
						  YorN='y';
					}
				}
			}
			if(NorY=='y' || NorY=='Y')
			{
				cleardevice();
				setbkcolor(RED);
				delay(1500);
				shutdown();
				exit(0);
			}
			else
				goto l2;
		case '5':
		//RESTART
			outtextxy(x-125,240,"Are you sure you want to restart?");
			rectangle(x-155,220,x+155,335);
			rectangle(x-160,215,x+160,340);
			setfillstyle(SOLID_FILL,RED);
			floodfill(x-154,221,YELLOW);
			setfillstyle(SOLID_FILL,8);
			floodfill(x-157,217,YELLOW);
			settextstyle(1,0,1);
			while(YorN!=13)
			{
				if(YorN=='n' || YorN=='N')
				{
					NorY=YorN;
					setcolor(7);
					outtextxy(x-70,290,"YES");
					setcolor(YELLOW);
					outtextxy(x+40,290,"NO");
				}
				else if(YorN=='y'||YorN=='Y')
				{
					NorY=YorN;
					setcolor(YELLOW);
					outtextxy(x-70,290,"YES");
					setcolor(7);
					outtextxy(x+40,290,"NO");
				}
				YorN=getch();
				if(YorN=='\0')
				{
					arrow=getch();
					if(arrow==75 || arrow==77)
					{
						 if(NorY=='y' || NorY=='Y')
						  YorN='n';
						 else
						  YorN='y';
					}
				}
			}
			if(NorY=='y' || NorY=='Y')
			{
				cleardevice();
				setbkcolor(RED);
				delay(1500);
				logout();
				relog=0;
				shutdown();
				goto start;
			}
			else
				goto l2;
		case '6':
		//SETTING
			settextstyle(3,0,1);
			onetwo=twoone='1';
			rectangle(x-155,220,x+155,375);
			rectangle(x-160,215,x+160,380);
			setfillstyle(SOLID_FILL,RED);
			floodfill(x-154,221,YELLOW);
			setfillstyle(SOLID_FILL,8);
			floodfill(x-157,217,YELLOW);
			outtextxy(x-30,225,"SETTINGS");
			if(obj.checkpd("\0")==1)
			{
				 while(twoone!=13)
				 {
				   if(twoone=='1')
				   {
					  onetwo=twoone;
					  setcolor(2);
					  outtextxy(x-130,280,"1.Create Password");
					  setcolor(WHITE);
					  outtextxy(x-130,310,"2.Cancel");
				   }
				   else if(twoone=='2')
				   {
					  onetwo=twoone;
					  setcolor(WHITE);
					  outtextxy(x-130,280,"1.Create Password");
					  setcolor(2);
					  outtextxy(x-130,310,"2.Cancel");
				   }
				   twoone=getch();
				   if(twoone=='\0')
				   {
					  arrow=getch();
					  if(arrow==UP || arrow==DOWN)
					  {
					  if(onetwo=='1')
						twoone='2';
					  else
						twoone='1';
					  }
				   }
				 }
				 if(onetwo=='1')
				 {
				newpsd:
				clrscr();
				closegraph();
				initgraph(&g,&d,"\\TC\\BGI");
				rectangle(x-250,y-100,x+250,y+100);
				char pass[25];
				int pasd=0;
				newpsd1:
				setcolor(3);
				outtextxy(x-170,y-49,"   New Password");
				rectangle(x-5,y-55,x+146,y-35);
				setcolor(WHITE);
				settextstyle(7,0,1);
				outtextxy(x-100,y+30,"Cancel");
				outtextxy(x+90,y+30,"Apply");
				settextstyle(0,0,1);
				while(x)
				{
					pass[pasd]=getch();
					if(pass[pasd]!=13 && pass[pasd]!=8 &&pass[pasd]!=9)
					{
					if(pasd<12)
					outtextxy(x+pasd*12,y-48,"*");
					pasd++;
					}
					else if(pass[pasd]==8)
					{
					if(pasd>0)
					{
					   cleardevice();
					   rectangle(x-250,y-100,x+250,y+100);
					   setcolor(3);
					   outtextxy(x-170,y-49,"   New Password");
					   rectangle(x-5,y-55,x+146,y-35);
					   setcolor(WHITE);
					   settextstyle(7,0,1);
					   outtextxy(x-100,y+30,"Cancel");
					   outtextxy(x+90,y+30,"Apply");
					   settextstyle(0,0,1);
					   for(int j=0; j<pasd-1; j++)
					   {
						  if(j<12)
						  outtextxy(x+j*12,y-48,"*");
					   }
					   pass[pasd]=pass[--pasd]=00;
					}
					}
					else
					{
					pass[pasd]='\0';
					break;
					}
				}
				setcolor(WHITE);
				outtextxy(x-170,y-49,"   New Password");
				rectangle(x-5,y-55,x+146,y-35);
				setcolor(3);
				settextstyle(7,0,1);
				outtextxy(x-100,y+30,"Cancel");
				settextstyle(0,0,1);
				settextstyle(2,0,4);
				setcolor(WHITE);
				outtextxy(x+100,y+105,"Press TAB to move to next");
				npsd1:
				YorN=getch();
				if(YorN==13)
					goto l2;
				else if(YorN==9)
				{
					setcolor(WHITE);
					settextstyle(7,0,1);
					outtextxy(x-100,y+30,"Cancel");
					setcolor(3);
					outtextxy(x+90,y+30,"Apply");
					settextstyle(0,0,1);
				}
				else if(YorN=='\0')
				{
					arrow=getch();
					if(arrow==RIGHT)
					{
					setcolor(WHITE);
					settextstyle(7,0,1);
					outtextxy(x-100,y+30,"Cancel");
					setcolor(3);
					outtextxy(x+90,y+30,"Apply");
					settextstyle(0,0,1);
					}
					else
					goto npsd1;
				}
				else
					goto npsd1;
				npsd2:
				YorN=getch();
				if(YorN==9)
					goto newpsd1;
				else if(YorN=='\0')
				{
					arrow=getch();
					if(arrow==LEFT)
					{
						setcolor(3);
						settextstyle(7,0,1);
						outtextxy(x-100,y+30,"Cancel");
						setcolor(WHITE);
						outtextxy(x+90,y+30,"Apply");
						settextstyle(0,0,1);
						goto npsd1;
					}
					else goto npsd2;
				}
				else if(YorN==13)
				{
					fstream fs;
					fs.open("Password.dar",ios::trunc|ios::out);
					fs.write((char*)&pass,sizeof(pass));
					fs.close();
					closegraph();
					goto l2;
				}
				else goto npsd2;
				 }
				 goto l2;
			}
			while(twoone!=13)
			{
				if(twoone=='1')
				{
				onetwo=twoone;
				setcolor(2);
				outtextxy(x-130,280,"1.Change Password");
				setcolor(WHITE);
				outtextxy(x-130,300,"2.Remove password");
				outtextxy(x-130,320,"3.Cancel");
				}
				else if(twoone=='2')
				{
				onetwo=twoone;
				setcolor(WHITE);
				outtextxy(x-130,280,"1.Change Password");
				outtextxy(x-130,320,"3.Cancel");
				setcolor(2);
				outtextxy(x-130,300,"2.Remove password");
				}
				else if(twoone=='3')
				{
				onetwo=twoone;
				setcolor(WHITE);
				outtextxy(x-130,280,"1.Change Password");
				outtextxy(x-130,300,"2.Remove password");
				setcolor(2);
				outtextxy(x-130,320,"3.Cancel");
				}
				twoone=getch();
				if(twoone=='\0')
				{
				arrow=getch();
				if(arrow==UP)
				{
					if(onetwo=='1')
						 twoone='3';
					else if(onetwo=='2')
						 twoone='1';
					else
						 twoone='2';
				}
				else if(arrow==DOWN)
				{
					if(onetwo=='1')
						twoone='2';
					else if(onetwo=='2')
						twoone='3';
					else
						twoone='1';
				}
				}
			}
			if(onetwo=='1')
			{
				int wrongpd=0;
				cp:
				clrscr();
				closegraph();
				initgraph(&g,&d,"\\TC\\BGI");
				rectangle(x-250,y-100,x+250,y+100);
				char pass1[25],pass2[25];
				int pasd1=0,pasd2=0;
				pc:
				setcolor(3);
				if(wrongpd==1)
				{
					setcolor(3);
					settextstyle(2,0,4);
					outtextxy(x-5,y-35,"Incorrect password !!");
					settextstyle(0,0,1);
				}
				outtextxy(x-170,y-49,"Current Password");
				rectangle(x-5,y-55,x+146,y-35);
				setcolor(WHITE);
				outtextxy(x-170,y-9,"New Password");
				rectangle(x-5,y-15,x+146,y+5);
				settextstyle(7,0,1);
				outtextxy(x+10,y+60,"Cancel");
				outtextxy(x+120,y+60,"Apply");
				settextstyle(0,0,1);
				while(x)
				{
					pass1[pasd1]=getch();
					if(pass1[pasd1]!=13 && pass1[pasd1]!=8 &&pass1[pasd1]!=9)
					{
					if(pasd1<12)
					outtextxy(x+pasd1*12,y-48,"*");
					pasd1++;
					}
					else if(pass1[pasd1]==8)
					{
					if(pasd1>0)
					{
						cleardevice();
						rectangle(x-250,y-100,x+250,y+100);
						setcolor(3);
						outtextxy(x-170,y-49,"Current Password");
						rectangle(x-5,y-55,x+146,y-35);
						setcolor(WHITE);
						outtextxy(x-170,y-9,"New Password");
						rectangle(x-5,y-15,x+146,y+5);
						settextstyle(7,0,1);
						outtextxy(x+10,y+60,"Cancel");
						outtextxy(x+120,y+60,"Apply");
						settextstyle(0,0,1);
						for(int j=0; j<pasd2; j++)
						{
						if(j<12)
						outtextxy(x+j*12,y-8,"*");
						}
						for(j=0; j<pasd1-1; j++)
						{
						if(j<12)
						outtextxy(x+j*12,y-48,"*");
						}
						pass1[pasd1]=pass1[--pasd1]=00;
					}
					}
					else
					{
					pass1[pasd1]='\0';
					break;
					}
				}
				setcolor(WHITE);
				outtextxy(x-170,y-49,"Current Password");
				rectangle(x-5,y-55,x+146,y-35);
				shortpd:
				setcolor(3);
				outtextxy(x-170,y-9,"New Password");
				rectangle(x-5,y-15,x+146,y+5);
				setcolor(WHITE);
				while(x)
				{
					pass2[pasd2]=getch();
					if(pass2[pasd2]!=13 && pass2[pasd2]!=8 && pass2[pasd2]!=9)
					{
					if(pasd2<12)
					outtextxy(x+pasd2*12,y-8,"*");
					pasd2++;
					}
					else if(pass2[pasd2]==8)
					{
					if(pasd2>0)
					{
						cleardevice();
						rectangle(x-250,y-100,x+250,y+100);
						setcolor(WHITE);
						outtextxy(x-170,y-49,"Current Password");
						rectangle(x-5,y-55,x+146,y-35);
						setcolor(3);
						outtextxy(x-170,y-9,"New Password");
						rectangle(x-5,y-15,x+146,y+5);
						setcolor(WHITE);
						settextstyle(7,0,1);
						outtextxy(x+10,y+60,"Cancel");
						outtextxy(x+120,y+60,"Apply");
						settextstyle(0,0,1);
						for(int j=0; j<pasd1; j++)
						{
						if(j<12)
						outtextxy(x+j*12,y-48,"*");
						}
						for(j=0; j<pasd2-1; j++)
						{
						if(j<12)
						outtextxy(x+j*12,y-8,"*");
						}
						pass2[pasd2]=pass2[--pasd2]=00;
					}
					}
					else
					{
					pass2[pasd2]='\0';
					break;
					}
				}
				outtextxy(x-170,y-9,"New Password");
				rectangle(x-5,y-15,x+146,y+5);
				settextstyle(7,0,1);
				setcolor(3);
				outtextxy(x+10,y+60,"Cancel");
				settextstyle(2,0,4);
				setcolor(WHITE);
				outtextxy(x+100,y+105,"Press TAB to move to next");
				cap1:
				YorN=getch();
				if(YorN==13)
				{
					closegraph();
					goto l2;
				}
				else if(YorN==9)
				{
					settextstyle(7,0,1);
					setcolor(WHITE);
					outtextxy(x+10,y+60,"Cancel");
					setcolor(3);
					outtextxy(x+120,y+60,"Apply");
					settextstyle(0,0,1);
				}
				else if(YorN=='\0')
				{
					arrow=getch();
					if(arrow==RIGHT)
					{
					   settextstyle(7,0,1);
					   setcolor(WHITE);
					   outtextxy(x+10,y+60,"Cancel");
					   setcolor(3);
					   outtextxy(x+120,y+60,"Apply");
					   settextstyle(0,0,1);
					}
					else
					   goto cap1;
				}
				else
					goto cap1;
				cap2:
				YorN=getch();
				if(YorN==9)
					goto pc;
				else if(YorN=='\0')
				{
					arrow=getch();
					if(arrow==LEFT)
					{
					   settextstyle(7,0,1);
					   setcolor(3);
					   outtextxy(x+10,y+60,"Cancel");
					   setcolor(WHITE);
					   outtextxy(x+120,y+60,"Apply");
					   settextstyle(0,0,1);
					   goto cap1;
					}
					else
					   goto cap2;
				}
				else if(YorN==13)
				{
					if(pass2[0]=='\0')
					{
					settextstyle(2,0,4);
					outtextxy(x-5,y+10,"password too short !!");
					settextstyle(7,0,1);
					setcolor(WHITE);
					outtextxy(x+120,y+60,"Apply");
					settextstyle(0,0,1);
					goto shortpd;
					}
					if(obj.checkpd(pass1)!=1)
					{
					wrongpd=1;
					goto cp;
					}
					fstream fs;
					fs.open("Password.dar",ios::binary|ios::out);
					fs.write((char*)&pass2,sizeof(pass2));
					fs.close();
					goto l2;
				}
				else
					goto cap2;
			}
			else if(onetwo=='2')
			{
				cp1:
				clrscr();
				closegraph();
				initgraph(&g,&d,"\\TC\\BGI");
				rectangle(x-250,y-100,x+250,y+100);
				char pass[25];
				int pasd=0;
				pc1:
				setcolor(3);
				outtextxy(x-170,y-49,"Current Password");
				rectangle(x-5,y-55,x+146,y-35);
				setcolor(WHITE);
				settextstyle(7,0,1);
				outtextxy(x-100,y+30,"Cancel");
				outtextxy(x+90,y+30,"Apply");
				settextstyle(0,0,1);
				while(x)
				{
				pass[pasd]=getch();
				if(pass[pasd]!=13 && pass[pasd]!=8 &&pass[pasd]!=9)
				{
				   if(pasd<12)
				   outtextxy(x+pasd*12,y-48,"*");
				   pasd++;
				}
				else if(pass[pasd]==8)
				{
				   if(pasd>0)
				   {
					   cleardevice();
					   rectangle(x-250,y-100,x+250,y+100);
					   setcolor(3);
					   outtextxy(x-170,y-49,"Current Password");
					   rectangle(x-5,y-55,x+146,y-35);
					   setcolor(WHITE);
					   settextstyle(7,0,1);
					   outtextxy(x-100,y+30,"Cancel");
					   outtextxy(x+90,y+30,"Apply");
					   settextstyle(0,0,1);
					   for(int j=0; j<pasd-1; j++)
					   {
					if(j<12)
					outtextxy(x+j*12,y-48,"*");
					   }
					   pass[pasd]=pass[--pasd]=00;
				   }
				}
				else
				{
					pass[pasd]='\0';
					break;
				}
				}
				setcolor(WHITE);
				outtextxy(x-170,y-49,"Current Password");
				rectangle(x-5,y-55,x+146,y-35);
				setcolor(3);
				settextstyle(7,0,1);
				outtextxy(x-100,y+30,"Cancel");
				settextstyle(0,0,1);
				settextstyle(2,0,4);
				setcolor(WHITE);
				outtextxy(x+100,y+105,"Press TAB to move to next");
				cap3:
				YorN=getch();
				if(YorN==13)
				goto l2;
				else if(YorN==9)
				{
				setcolor(WHITE);
				settextstyle(7,0,1);
				outtextxy(x-100,y+30,"Cancel");
				setcolor(3);
				outtextxy(x+90,y+30,"Apply");
				settextstyle(0,0,1);
				}
				else if(YorN=='\0')
				{
				arrow=getch();
				if(arrow==RIGHT)
				{
					setcolor(WHITE);
					settextstyle(7,0,1);
					outtextxy(x-100,y+30,"Cancel");
					setcolor(3);
					outtextxy(x+90,y+30,"Apply");
					settextstyle(0,0,1);
				}
				else
					goto cap3;
				}
				else
				goto cap3;
				cap4:
				YorN=getch();
				if(YorN==9)
				goto pc1;
				else if(YorN=='\0')
				{
				arrow=getch();
				if(arrow==LEFT)
				{
					setcolor(3);
					settextstyle(7,0,1);
					outtextxy(x-100,y+30,"Cancel");
					setcolor(WHITE);
					outtextxy(x+90,y+30,"Apply");
					settextstyle(0,0,1);
					goto cap3;
				}
				else goto cap4;
				}
				else if(YorN==13)
				{
				if(obj.checkpd(pass)!=1)
					goto cp1;
				fstream fs;
				fs.open("Password.dar",ios::trunc|ios::out);
				fs.close();
				closegraph();
				goto l2;
				}
				else goto cap4;
			}
			else if(onetwo=='3')
				goto l2;
			break;
		case '7':
			game_main();
			goto l2;
		default:
			return;
	}
	getch();
}
