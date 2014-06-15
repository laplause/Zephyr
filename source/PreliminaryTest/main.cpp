#include "ZMath.h"
using namespace ZMath;

int main()
{
	Vec2 x2(1.0f, 0.0f), y2(1.0f, 0.0f);
	Vec3 x3(0.0f, 0.0f, 1.0f), y3(1.0f, 0.0f, 0.0f);
	Vec4 x(1.0f, 0, 0, 0), y(-1.0f, 0, 0, 0);

	Vector<float, 5> x5, y5;
	x5[0] = 5.0f;
	x5[1] = 4.0f;
	x5[2] = 3.0f;
	x5[3] = 2.0f;
	x5[4] = 1.0f;
	y5[0] = 2.0f;
	y5[1] = 6.0f;
	y5[2] = 1.0f;
	y5[3] = 9.0f;
	y5[4] = 0.0f;

	float dot = Dot(x, y);
	dot = Dot(x2, y2);
	dot = Dot(x3, y3);
	dot = Dot(x5, y5);

	Vec3 z = Cross(x3, y3);

	return 0;
}