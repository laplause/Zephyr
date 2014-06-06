#ifndef ZMATH_H
#define ZMATH_H

///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is an implementaion of a scalar vector math library for use in the						 //
//	Zephyr game/graphics engine.																		 //
//																								 //
//	Majority of implementation inspired by Nathan Reed's blog						             //
//	On Vector Math Libraries	                                                                 //
//	http://www.reedbeta.com/blog/2013/12/28/on-vector-math-libraries/						     //
//																								 //
///////////////////////////////////////////////////////////////////////////////////////////////////


namespace ZMath
{
	// Templated by type and size Vector
	template<typename T, int n>
	struct Vector 
	{ 
		T data[n];
		T operator[](unsigned int component) { return data[component]; };
	};

	// Partial Vector specializations with .x .y .z .w .r .g etc.. access
	template<typename T>
	struct Vector<T, 2>
	{
		union
		{
			float data[2];
			struct { float x, y; };
			struct { float r, g; };
		};

		// Constructors
		Vector() : x(0), y(0) {}
		Vector(T x, T y) : x(x), y(y) {}
		explicit Vector<T, 2>(T value) : x(value), y(value) {}
		float operator[](unsigned int component) { return data[component]; }
	};

	template<typename T>
	struct Vector<T, 3>
	{
		union
		{
			T data[3];
			struct { T x, y, z; };
			struct { T r, g, b; };
		};

		// Constructors
		Vector() : x(0), y(0), z(0) {}
		Vector(T x, T y, T z) : x(x), y(y), z(z) {}
		explicit Vector(T value) : x(value), y(value), z(value) {}
		T operator[](unsigned int component) { return data[component]; }
	};

	template<typename T>
	struct Vector<T, 4>
	{
		union
		{
			T data[4];
			struct { T x, y, z, w; };
			struct { T r, g, b, a; };
		};

		// Constructors
		Vector() : x(0), y(0), z(0), w(0) {}
		Vector(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
		explicit Vector(T value) : x(value), y(value), z(value), w(value) {}
		T operator[](unsigned int component) { return data[component]; };
	};

	// Common Vector typedefs
	typedef Vector<float, 2> Vec2;
	typedef Vector<float, 3> Vec3;
	typedef Vector<float, 4> Vec4;

	// Templated by type and size Matrix
	template<typename T, int rows, int cols>
	struct Matrix
	{
		T data[rows][cols];
	};

	// Partial Matrix specializations with .m00 .m01 .row1 .row2 etc.. access
	template<typename T>
	struct Matrix<T, 3, 3>
	{
		union
		{
			T data[3][3];
			struct
			{
				T m00, m01, m02,
				  m10, m11, m12,
				  m20, m21, m22;
			};
			struct { Vec3 row1, row2, row3; };
			struct { Vec3 rows[3]; };
		};
		Vec3 operator[](unsigned int n) { return rows[n]; }
	};

	template<typename T>
	struct Matrix<T, 4, 4>
	{
		union
		{
			T data[4][4];
			struct
			{
				T m00, m01, m02, m03,
				  m10, m11, m12, m13,
				  m20, m21, m22, m23,
				  m30, m31, m32, m33;
			};
			struct { Vec4 row1, row2, row3, row4; };
			struct { Vec4 rows[4]; };
		};
		Vec4 operator[](unsigned int n) { return rows[n]; }
	};

	// Common Matrix typedefs
	typedef Matrix<float, 3, 3> Mat3x3;
	typedef Matrix<float, 4, 4> Mat4x4;
	
}//end ZMath

#endif