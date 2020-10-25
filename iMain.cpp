#include "iGraphics.h"
#include<math.h>
#include<stdio.h>
#include<time.h>
#define pi acos(-1)

int hour,min,sec;
double a1,a2,a3;
double t1=0,t2=0,t3=0;
int l=120,m=65;

int x =300,y =300,r =20;


void func(){

            t1=t1+(6)*(pi/180);
            t2=t2+(pi/1800);
            t3=t3+(pi/21600);

}


void iDraw() {
		       iClear();

	    iSetColor(255,51,153);
	    iPoint(200,200,3);
		iCircle(200,200,125);
	    iCircle(200,200,128);

	    iSetColor(105,225,25);
		iText(199+135*cos(m*pi/180),199+135*sin(m*pi/180),"1");m-=30;
		iText(199+135*cos(m*pi/180),199+135*sin(m*pi/180),"2");m-=30;
		iText(199+135*cos(m*pi/180),199+135*sin(m*pi/180),"3");m-=30;
		iText(199+135*cos(m*pi/180),199+135*sin(m*pi/180),"4");m-=30;
		iText(199+135*cos(m*pi/180),199+135*sin(m*pi/180),"5");m-=30;
		iText(199+135*cos(m*pi/180),199+135*sin(m*pi/180),"6");m-=30;
		iText(199+135*cos(m*pi/180),199+135*sin(m*pi/180),"7");m-=30;
		iText(199+135*cos(m*pi/180),199+135*sin(m*pi/180),"8");m-=30;
		iText(199+135*cos(m*pi/180),199+135*sin(m*pi/180),"9");m-=30;
		iText(199+135*cos(m*pi/180),199+135*sin(m*pi/180),"10");m-=30;
		iText(199+135*cos(m*pi/180),199+135*sin(m*pi/180),"11");m-=30;
		iText(199+135*cos(m*pi/180),199+135*sin(m*pi/180),"12");m=60;


	iSetColor(0,255,255);
	iLine(200,200,200+l*cos(a1-t1),200+l*sin(a1-t1));


	iSetColor(0,255,0);
	iLine(200,200,200+(l-10)*cos(a2-t2),200+(l-10)*sin(a2-t2));


	iSetColor(255,255,0);
	iLine(200,200,200+(l-35)*cos(a3-t3),200+(l-35)*sin(a3-t3));





}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		x += 10;
		y += 10;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		x -= 10;
		y -= 10;
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}


int main() {
	time_t now;
	struct tm *tm;
	now=time(0);
	if((tm=localtime(&now))==NULL)
         {
         	printf("error extracting time ");
         	return 1;
         }


	//printf("%d %d %d",tm->tm_hour,tm->tm_min,tm->tm_sec);

     hour=tm->tm_hour;
     min=tm->tm_min;
     sec=tm->tm_sec;
/*hour=8;
min=45;
sec=30;*/

     a1=(90-sec*6)*(pi/180);
     a2=(90-(min*6+(sec/10)))*(pi/180);
	 a3=(90-(hour*30+(min/2)+(sec/120)))*(pi/180);



    iSetTimer(1000,func);
	iInitialize(500, 500, "MY_ANALOG_CLOCK");

	return 0;
}
