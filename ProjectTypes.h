#ifndef PROJECTTYPES_H
#define PROJECTTYPES_H
typedef struct {
	int x;
	int y;
}Vector2;
Vector2 Vector2_create(int x, int y);
void process();
void initialCurve();
void circleMove();
void collidCheck();
void barMove(int input);
#endif
