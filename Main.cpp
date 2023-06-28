#include<easyx.h>
#include<stdio.h>
#include<conio.h>
#include "ProjectTypes.h"
#define width 800
#define heith 600
int main() {
	initgraph(width, heith);
	setaspectratio(1, -1);
	setorigin(width / 2, heith / 2);
	setbkcolor(RGB(164, 225, 202));
	cleardevice();
	closegraph;
	return 0;
}
void process() {
	int input;
	Vector2 movement = Vector2_create(1, 1);
	while (true)
	{
		if (kbhit()) {
			input = getch();
			barMove(input);
			if (input == 27)break;
		}
		Vector2_assign(&movement, &collidCheck());
		circleMove();
	}
}
void circleMove() {

}
Vector2 collidCheck() {

}
void barMove(int input) {

}