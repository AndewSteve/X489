#ifndef PROJECTTYPES_H
#define PROJECTTYPES_H
typedef struct {
	int x;
	int y;
}Vector2;
Vector2 Vector2_create(int x, int y);
void Vector2_assign(const Vector2* ori, const Vector2* other);
#endif
