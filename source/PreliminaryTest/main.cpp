#include "ZMath.h"
using namespace ZMath;

int main()
{
	Vec3 x(12.0f, 0.0f, 0.0f);
	Vec3 y(0.0f, 1.0f, 0.0f);
	Vec3 z(0.0f, 0.0f, 2.0f);

	Vec4 x4(1.0f, 0.0f, -6.0f, 0.0f);
	Vec4 y4(2.0f, 21.0f, 3.0f, -5.0f);
	Vec4 z4(-9.0f, -11.0f, 50.0f, 2.0f);
	Vec4 w4(4.0f, 2.0f, -200.0f, 0.0f);

	Mat3x3 r3 = CreateRowMatrix3x3(x, y, z);
	Mat3x3 c3 = CreateColumnMatrix3x3(x, y, z);

	Mat4x4 r4 = CreateRowMatrix4x4(x4, y4, z4, w4);
	Mat4x4 c4 = CreateColumnMatrix4x4(x4, y4, z4, w4);

	float det = Determinant(r3);
	det = Determinant(c3);

	r3 = Inverse(r3);
	c3 = Inverse(c3);

	det = Determinant(r4);
	det = Determinant(c4);

	r4 = Inverse(r4);
	c4 = Inverse(c4);
	return 0;
}