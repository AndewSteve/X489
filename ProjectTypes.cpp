#include "ProjectTypes.h"
Vector2 Vector2_create(int x, int y) {
	Vector2 vector2;
	vector2.x = x;
	vector2.y = y;
	return vector2;
}
void Vector2_assign(Vector2* ori, Vector2* other) {
	ori->x = other->x;
	ori->y = other->y;
};