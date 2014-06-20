#include "ZMath.h"
using namespace ZMath;

int main()
{
	Vec3 x(1.0f, 2.0f, 3.0f);
	Vec3 y(4.0f, 5.0f, 6.0f);
	Vec3 z(7.0f, 8.0f, 9.0f);

	Vec4 x4(1.0f, 2.0f, 3.0f, 4.0f);
	Vec4 y4(5.0f, 6.0f, 7.0f, 8.0f);
	Vec4 z4(9.0f, 10.0f, 11.0f, 12.0f);
	Vec4 w4(13.0f, 14.0f, 15.0f, 16.0f);

	Mat3x3 r3 = CreateRowMatrix3x3(x, y, z);
	Mat3x3 c3 = CreateColumnMatrix3x3(x, y, z);

	Mat4x4 r4 = CreateRowMatrix4x4(x4, y4, z4, w4);
	Mat4x4 c4 = CreateColumnMatrix4x4(x4, y4, z4, w4);

	r3 *= 2.0f;
	r3 /= 2.0f;

	r3 = Transpose(r3);
	r4 = Transpose(r4);
	c3 = Transpose(c3);
	c4 = Transpose(c4);

	r3 = r3 * 2.0f;
	r3 = r3 / 2.0f;

	r4 *= 2.0f;
	r4 /= 2.0f;

	r4 = r4 * 2.0f;
	r4 = r4 / 2.0f;
	return 0;
}