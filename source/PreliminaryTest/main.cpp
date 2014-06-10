#include "ZMath.h"
using namespace ZMath;

int main()
{
	Vec3 a;
	a.x = 100.0f;
	a.y = 200.0f;
	a.z = 300.0f;
	a.r = 400.0f;
	a.g = 500.0f;
	a.b = 600.0f;
	a[0] = 1.0f;
	a[1] = 0.0f;
	a[2] = 1.0f;

	Vec3 b(0.0f, 0.0f, 1.0f);
	float f = b[0];

	Vec3 leet(1337.1337f);
	f = leet[0];

	Vec2 g(1.0f);

	Vec3 fromTwo(g, 3.0f);

	return 0;
}