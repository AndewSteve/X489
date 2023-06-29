#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include "ProjectTypes.h"
#include <iostream>
#define Width 800
#define Heith 600
#define RectangleWidth 500
#define RectangleHeigth 60
#define Radius 100
#define Speed 10
int main() {
	initgraph(Width, Heith);
	setorigin(Width / 2, Heith / 2);
	setaspectratio(1, -1);
	setbkcolor(RGB(164, 225, 202));
	cleardevice();
	process();
	closegraph();
	return 0;
}
Vector2 movement = Vector2_create(Speed, Speed);
Vector2 P0 = Vector2_create(0,0);
void process() {
	initialCurve();
	clock_t lastTime = clock();
	double deltaTime = 0.0;
	double updateInterval = 1.0 / 60.0;
	char input;
	while (true)
	{
		clock_t currentTime = clock();
		deltaTime += (double)(currentTime - lastTime) / CLOCKS_PER_SEC;
		lastTime = currentTime;
		if (deltaTime >= updateInterval)
		{
			collidCheck();
			circleMove();
			deltaTime -= updateInterval;
		}
		if (_kbhit()) {
			input = _getch();
			if (input == 27)break;
			if((input == 'A') || (input == 'a') || (input == 'D') || (input == 'd'))barMove(input);
		}
		//collidCheck();
		//circleMove();
	}
}

Vector2 P1 = Vector2_create(-RectangleWidth / 2, RectangleHeigth -Heith / 2);
Vector2 P2 = Vector2_create(RectangleWidth / 2,- Heith / 2);
void initialCurve() {
	solidcircle(P0.x, P0.y, Radius);
	solidrectangle(P1.x,P1.y,P2.x,P2.y);
}


void circleMove() {
	clearcircle(P0.x, P0.y, Radius);
	P0.x += movement.x;
	P0.y += movement.y;
	solidcircle(P0.x, P0.y, Radius);
}
void collidCheck() {
	if((P0.y+Radius)==(Heith/2) || 
		((P0.x>P1.x)&&(P0.x<P2.x)&&(P0.y-Radius==P1.y)) )movement.y*=-1;
	if (((P0.x + Radius) == (Width/2))|| ((P0.x - Radius) == (-Width/2)))movement.x *= -1;
}
void barMove(int input) {
	clearrectangle(P1.x, P1.y, P2.x, P2.y);
	if (((input == 'A') || (input == 'a'))&&(P1.x>-Width/2)) {
		P1.x -= Speed;
		P2.x -= Speed;
	}
	if (((input == 'D') || (input == 'd')) &&(P2.x < Width / 2)) {
		P1.x += Speed;
		P2.x += Speed;
	}
	solidrectangle(P1.x, P1.y, P2.x, P2.y);
}