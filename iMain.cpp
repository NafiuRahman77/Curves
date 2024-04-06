#include"iGraphics.h"
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<windows.h>
#include<MMsystem.h>

void eggmove();
void egg_rand();

int screenwidth= 1400;
int screenheight=760;

int x,y;
int timeset=1;
int score_x;
int timer;
int timerstate=1;
int eggcoordinate;
int chickenx=0;
int chickendx=700;
int eggY=0;
int basket_x=0;
int basketdx=700;
int newgame=1;


char a[20]={"background.bmp"};
char b[20]={"rope.bmp"};
char c[20]={"chicken.bmp"};
char e[20]=("poop.bmp");
char f[20]=("goldegg.bmp");
char g[20]=("blueegg.bmp");
char h[20]=("whiteegg.bmp");
char d[20]=("basket.bmp");
char j[20]="homescreen.bmp";
char k[20]="score.bmp";
char m[20]="helmp.bmp";
char n[20]="clock.bmp";
char q[20]="Timer.bmp";

char s[20];
char t[20];
int gamestate = -1;
void iMouse(int button, int state, int mx, int my);

void iDraw()
{

	if(gamestate==-1)
    {   iClear();
        iShowBMP(0,0,j);
       if(newgame==1 && timerstate==1)
        {
        timer=120;
        score_x=0;
        // printf("%d",newgame);
        }
        if(newgame==1 && timerstate==2)
        {
        timer=80;
        score_x=0;
        // printf("%d",newgame);
        }
        if(newgame==1 && timerstate==3)
        {
        timer=40;
        score_x=0;
        // printf("%d",newgame);
        }

    }
	else if(gamestate==2)
    {
    iClear();

    iShowBMP(0,0,a);
	iShowBMP2(0,480,b,0xffffff);
	iShowBMP2(chickendx+chickenx,510,c,0xffffff);
	iShowBMP2(basketdx+basket_x,0,d,0xffffff);

       //collision testing for egg and basket

        if(eggcoordinate%5==0)
        {
            iShowBMP2(x+y,490+eggY,e,0xffffff);
            if((x+y)>=(basketdx+basket_x-60) && (x+y)<=(basketdx+basket_x+60) && (490+eggY)<=75 && (490+eggY)>=55)
                {
                    if(score_x>=10)
                        score_x=score_x-10;
                    else
                        score_x=0;
                }

        }
        if(eggcoordinate%5==1)
        {
            iShowBMP2(x+y,490+eggY,f,0xffffff);
            if((x+y)>=(basketdx+basket_x-60) && (x+y)<=(basketdx+basket_x+60) && (490+eggY)<=75 && (490+eggY)>=55)
                score_x=score_x+10;
        }
         if(eggcoordinate%5==3)
        {
            iShowBMP2(x+y,490+eggY,h,0);
            if((x+y)>=(basketdx+basket_x-60) && (x+y)<=(basketdx+basket_x+60) && (490+eggY)<=75 && (490+eggY)>=55)
                score_x=score_x+1;
        }
        if(eggcoordinate%5==2)
        {
            iShowBMP2(x+y,490+eggY,g,0xffffff);
            if((x+y)>=(basketdx+basket_x-60) && (x+y)<=(basketdx+basket_x+60) && (490+eggY)<=75 && (490+eggY)>=55)
                score_x=score_x+5;
        }

         if(eggcoordinate%5==4)
        {
            iShowBMP2(x+y,490+eggY,n,0xffffff);
            if((x+y)>=(basketdx+basket_x-70) && (x+y)<=(basketdx+basket_x+70) && (490+eggY)<=75 && (490+eggY)>=55)
                {
                    timer+=2;
                }

        }


    iSetColor(0,0,0);

    sprintf(s,"%d",score_x);
    iText(1200,720,"SCORE:" ,GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1300,720,s ,GLUT_BITMAP_TIMES_ROMAN_24);


    sprintf(t,"%d",timer);
    iText(10,730,"Time:" ,GLUT_BITMAP_TIMES_ROMAN_24);
    iText(80,730,t ,GLUT_BITMAP_TIMES_ROMAN_24);

        iResumeTimer(0);
        iResumeTimer(1);
        iResumeTimer(2);
        iResumeTimer(3);
        iResumeTimer(4);
        iResumeTimer(5);
        iResumeTimer(6);

    }

    else if(gamestate==3)

    {

         iClear();
         iShowBMP(0,0,k);
         iText(508,760-349,"YOUR SCORE IS:" ,GLUT_BITMAP_TIMES_ROMAN_24);
         iText(700,760-349, s ,GLUT_BITMAP_TIMES_ROMAN_24);

    }

    else if(gamestate==4)

    {

        iShowBMP(0,0,m);

    }
    else if(gamestate==5)
    {
         iShowBMP(0,0,q);
    }
}


void iMouseMove(int mx, int my)
{
	if(mx-(basketdx+basket_x)>=10 && (basketdx+basket_x)<1200)
    {
        basket_x+=35;
    }
    if((basketdx+basket_x)-mx>=10 &&(basketdx+basket_x)>35)
    {
        basket_x-=35;
    }
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
       if(gamestate==-1)
       {
           if(mx>=378 && mx<=740 && my>=304 && my<=378)
            {
                gamestate=2;
                newgame=1;

            }
            if(mx>=35 && mx<=182 && my>=499 && my<=542)
            {
                gamestate=2;
                newgame=0;

            }


           if(mx>=1174 && mx<=1365 && my>=760-253 && my<=760-206)
           {
               gamestate=4;
           }

           if(mx>=1016 && mx<=1158 && my>=760-256 && my<=760-208)
           {
                gamestate=5;
           }
       }
       if(gamestate==2)
       {
           if(mx>=1273 && mx<=1391 && my>=5 && my<=35)
            {
                gamestate=-1;
                newgame=0;
                iPauseTimer(0);
                iPauseTimer(1);
                iPauseTimer(2);
                iPauseTimer(3);
                iPauseTimer(4);
                iPauseTimer(5);
                iPauseTimer(6);

            }

       }

       if(gamestate==3)
       {
           if(mx>=356 && mx<=986 && my>=248 && my<=319)
             {gamestate=-1;}
       }
       if(gamestate==4)
       {
           if(mx>=407 && mx<=777 && my>=46 && my<=127)
           {
               gamestate=-1;
           }
       }
       if(gamestate==5)
       {
           if(mx>=51 && mx<=301 && my>=760-367 && my<=760-302)
           {
               gamestate=-1;
               timerstate=1;
           }
           if(mx>=494 && mx<=752 && my>=760-366 && my<=760-299)
           {
               gamestate=-1;
               timerstate=2;
           }
           if(mx>=975 && mx<=1239 && my>=760-365 && my<=760-301)
           {
               gamestate=-1;
               timerstate=3;
           }
       }
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

void iKeyboard(unsigned char key)
{
	if(key == 'x')
	{
		exit(0);
	}
    if(key == 'f')
	{
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
		iPauseTimer(3);
		iPauseTimer(4);
		iPauseTimer(5);
		iPauseTimer(6);

	}
	if(key == 'r')
	{
		iResumeTimer(0);

	}
	if(key=='p')
    {
        if(basketdx+basket_x<1170)
            basket_x+=40;
    }
	if(key=='q')
    {
        if(basketdx+basket_x>35)
            basket_x-=40;
    }


}

void y_movement()
{
    eggY=0;
}

void chickenval()
{
    x=chickendx;
    y=chickenx;
}

void iSpecialKeyboard(unsigned char key)
{
  //place your codes for other keys here

}

void eggmove()
{
  eggY=eggY-25;
}




void chickenmove()
{
    if((chickendx+chickenx)>=0)
    {
        int x;
        x=rand();
        if(x%2==0 && (chickendx+chickenx)<1180)
            chickenx+=80;

        if(x%2==1 && (chickendx+chickenx)>80)
            chickenx-=80;
    }

}



void egg_rand()
{
    eggcoordinate=rand();
}

void timerfunc()
{

    timer--;
    if (timer<0)
        gamestate=3;
}

void music()
{
    //PlaySound(TEXT("cyberpunk.wav"), NULL, SND_ASYNC);
}

void animate(){

}

int main()
{
    iSetTimer(80,chickenmove);
    //iSetTimer(2000,i_timer);
    iSetTimer(50,eggmove);
    iSetTimer(2000,y_movement);
    iSetTimer(2000,chickenval);
    iSetTimer(2000,egg_rand);
    iSetTimer(2000,timerfunc);
    iSetTimer(5000,music);
    iInitialize(screenwidth,screenheight,"Catch The Egg");

    return 0;
}


