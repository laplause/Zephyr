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
		T& operator[](unsigned int component) { return data[component]; };
	};

	// Common Vector typedefs
	typedef Vector<float, 2> Vec2;
	typedef Vector<float, 3> Vec3;
	typedef Vector<float, 4> Vec4;

	// Partial Vector specializations with .x .y .z .w .r .b etc.. access
	template<typename T>
	struct Vector<T, 2>
	{
		union
		{
			T data[2];
			struct { T x, y; };
			struct { T r, g; };
		};

		// Constructors
		Vector() : x(0), y(0) {}
		Vector(T x, T y) : x(x), y(y) {}
		explicit Vector(T value) : x(value), y(value) {}
		T& operator[](unsigned int component) { return data[component]; }
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
		Vector(Vec2& xy, T z) : x(xy.x), y(xy.y), z(z) {}
		T& operator[](unsigned int component) { return data[component]; }
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
		Vector(Vector<T, 2>& xy, T z, T w) : x(xy.x), y(xy.y), z(z), w(w) {}
		Vector(Vector<T, 3>& xyz, T w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}
		T& operator[](unsigned int component) { return data[component]; };
	};

	// Templated by type and size Matrix
	template<typename T, int rows, int cols>
	struct Matrix
	{
		T data[rows][cols];
	};

	// Common Matrix typedefs
	typedef Matrix<float, 3, 3> Mat3x3;
	typedef Matrix<float, 4, 4> Mat4x4;

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
			struct { Vector<T, 3> row0, row1, row2; };
			struct { Vector<T, 3> rows[3]; };
		};
		Matrix() 
		: m00(0), m01(0), m02(0), m10(0), m11(0), m12(0), m20(0), m21(0), m22(0) {}
		Matrix(T M00, T M01, T M02, T M10, T M11, T M12, T M20, T M21, T M22)
		: m00(M00), m01(M01), m02(M02), m10(M10), m11(M11), m12(M12), m20(M20), m21(M21), m22(M22) {}
		//Matrix(Vector<T, 3>& Row0, Vector<T, 3>& Row1, Vector<T, 3>& Row2) : row0(Row0), row1(Row1), row2(Row2) {}
		Vector<T, 3>& operator[](unsigned int n) { return rows[n]; }
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
			struct { Vector<T, 4> row0, row1, row2, row3; };
			struct { Vector<T, 4> rows[4]; };
		};
		Matrix()
		: m00(0), m01(0), m02(0), m03(0), m10(0), m11(0), m12(0), m13(0),
		  m20(0), m21(0), m22(0), m23(0), m30(0), m31(0), m32(0), m33(0) {}
		Matrix(T M00, T M01, T M02, T M03, T M10, T M11, T M12, T M13,
			   T M20, T M21, T M22, T M23, T M30, T M31, T M32, T M33)
		: m00(M00), m01(M01), m02(M02), m03(M03), m10(M10), m11(M11), m12(M12), m13(M13),
		  m20(M20), m21(M21), m22(M22), m23(M23), m30(M30), m31(M31), m32(M32), m33(M33) {}
		//Matrix(Vector<T, 4>& Row0, Vector<T, 4>& Row1, Vector<T, 4>& Row2, Vector<T, 4>& Row3) : row0(Row0), row1(Row1), row2(Row2), row3(Row3) {}
		Vector<T, 4>& operator[](unsigned int n) { return rows[n]; }
	};
	
}//end ZMath

#endif