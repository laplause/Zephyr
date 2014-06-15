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

#ifndef ZMATH_H
#define ZMATH_H

#include <math.h>

namespace ZMath
{
	const float PI = 3.14159265359f;     //180 degrees
	const float TWOPI = PI * 2.0f;       //360 degrees
	const float PIOVERTWO = PI * 0.5f;   //90 degrees
	const float PIOVERFOUR = PI * 0.25f; //45 degrees


	// Templated by type and size Vector
	template<typename T, int n>
	struct Vector 
	{ 
		// Vector Data
		T data[n];

		T& operator[](unsigned int component) { return data[component]; };
		const T& operator[](unsigned int component) const { return data[component]; }

		// Vector Addition and Subtraction
		Vector<T, n>& operator+=(const Vector<T, n>& rhs)
		{
			for (int i = 0; i < n; i++)
			{
				data[i] += rhs[i];
			}

			return *this;
		}
		Vector<T, n>& operator-=(const Vector<T, n>& rhs)
		{
			for (int i = 0; i < n; i++)
			{
				data[i] -= rhs[i];
			}

			return *this;
		}

		// Vector Multiplication by scalar
		Vector<T, n>& operator*=(const T& scalar)
		{
			for (int i = 0; i < n; i++)
			{
				data[i] *= scalar;
			}

			return *this;
		}
		Vector<T, n>& operator/=(const T& scalar)
		{
			for (int i = 0; i < n; i++)
			{
				data[i] /= scalar;
			}

			return *this;
		}
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
		const T& operator[](unsigned int component) const { return data[component]; }
		Vector<T, 2>& operator+=(const Vector<T, 2>& rhs)
		{
			for (int i = 0; i < 2; i++)
			{
				data[i] += rhs[i];
			}

			return *this;
		}
		Vector<T, 2>& operator-=(const Vector<T, 2>& rhs)
		{
			for (int i = 0; i < 2; i++)
			{
				data[i] -= rhs[i];
			}

			return *this;
		}
		Vector<T, 2>& operator*=(const T& scalar)
		{
			for (int i = 0; i < 2; i++)
			{
				data[i] *= scalar;
			}

			return *this;
		}
		Vector<T, 2>& operator/=(const T& scalar)
		{
			for (int i = 0; i < 2; i++)
			{
				data[i] /= scalar;
			}

			return *this;
		}
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
		const T& operator[](unsigned int component) const { return data[component]; }
		Vector<T, 3>& operator+=(const Vector<T, 3>& rhs)
		{
			for (int i = 0; i < 3; i++)
			{
				data[i] += rhs[i];
			}

			return *this;
		}
		Vector<T, 3>& operator-=(const Vector<T, 3>& rhs)
		{
			for (int i = 0; i < 3; i++)
			{
				data[i] -= rhs[i];
			}

			return *this;
		}
		Vector<T, 3>& operator*=(const T& scalar)
		{
			for (int i = 0; i < 3; i++)
			{
				data[i] *= scalar;
			}

			return *this;
		}
		Vector<T, 3>& operator/=(const T& scalar)
		{
			for (int i = 0; i < 3; i++)
			{
				data[i] /= scalar;
			}

			return *this;
		}
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
		T& operator[](unsigned int component) { return data[component]; }
		const T& operator[](unsigned int component) const { return data[component]; }
		Vector<T, 4>& operator+=(const Vector<T, 4>& rhs)
		{
			for (int i = 0; i < 4; i++)
			{
				data[i] += rhs[i];
			}

			return *this;
		}
		Vector<T, 4>& operator-=(const Vector<T, 4>& rhs)
		{
			for (int i = 0; i < 4; i++)
			{
				data[i] -= rhs[i];
			}

			return *this;
		}
		Vector<T, 4>& operator*=(const T& scalar)
		{
			for (int i = 0; i < 4; i++)
			{
				data[i] *= scalar;
			}

			return *this;
		}
		Vector<T, 4>& operator/=(const T& scalar)
		{
			for (int i = 0; i < 4; i++)
			{
				data[i] /= scalar;
			}

			return *this;
		}
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
		{
			data[0][0] = M00; data[0][1] = M01; data[0][2] = M02;
			data[1][0] = M10; data[1][1] = M11; data[1][2] = M12;
			data[2][0] = M20; data[2][1] = M21; data[2][2] = M22;
		}
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
		{
			data[0][0] = M00; data[0][1] = M01; data[0][2] = M02; data[0][3] = M03;
			data[1][0] = M10; data[1][1] = M11; data[1][2] = M12; data[1][3] = M13;
			data[2][0] = M20; data[2][1] = M21; data[2][2] = M22; data[2][3] = M23;
			data[3][0] = M30; data[3][1] = M31; data[3][2] = M32; data[3][3] = M33;
		}
		//Matrix(Vector<T, 4>& Row0, Vector<T, 4>& Row1, Vector<T, 4>& Row2, Vector<T, 4>& Row3) : row0(Row0), row1(Row1), row2(Row2), row3(Row3) {}
		Vector<T, 4>& operator[](unsigned int n) { return rows[n]; }
	};

	Mat3x3 CreateRowMatrix3x3(Vec3& row0, Vec3& row1, Vec3& row2)
	{
		Mat3x3 m;
		m.row0 = row0;
		m.row1 = row1;
		m.row2 = row2;

		return m;
	}

	// Creation Functions
	Mat3x3 CreateIdentity3x3()
	{
		return Mat3x3(1.0f, 0, 0,
					  0, 1.0f, 0,
					  0, 0, 1.0f);
	}

	Mat4x4 CreateRowMatrix4x4(Vec4& row0, Vec4& row1, Vec4& row2, Vec4& row3)
	{
		Mat4x4 m;
		m.row0 = row0;
		m.row1 = row1;
		m.row2 = row2;
		m.row3 = row3;

		return m;
	}

	Mat4x4 CreateIdentity4x4()
	{
		return Mat4x4(1.0f, 0, 0, 0,
					  0, 1.0f, 0, 0,
					  0, 0, 1.0f, 0,
					  0, 0, 0, 1.0f);
	}

	// Vector operations
	template<typename T, int size>
	Vector<T, size> Add(Vector<T, size>& lhs, const Vector<T, size>& rhs)
	{
		return lhs += rhs;
	}

	template<typename T, int size>
	Vector<T, size> operator+(Vector<T, size>& lhs, const Vector<T, size>& rhs)
	{
		return Add(lhs, rhs);
	}

	template<typename T, int size>
	Vector<T, size> Sub(Vector<T, size>& lhs, const Vector<T, size>& rhs)
	{
		return lhs -= rhs;
	}

	template<typename T, int size>
	Vector<T, size> operator-(Vector<T, size>& lhs, const Vector<T, size>& rhs)
	{
		return Sub(lhs, rhs);
	}

	template<typename T, int size>
	Vector<T, size> operator*(Vector<T, size>& lhs, const T& scalar)
	{
		return lhs *= scalar;
	}

	template<typename T, int size>
	Vector<T, size> operator/(Vector<T, size>& lhs, const T& scalar)
	{
		return lhs /= scalar;
	}

	template<typename T, int size>
	T LengthSquared(Vector<T, size>& v)
	{
		T result = 0;
		for (int i = 0; i < size; i++)
		{
			result += (v[i] * v[i]);
		}

		return result;
	}

	template<typename T, int size>
	T Length(Vector<T, size>& v)
	{
		return sqrtf(LengthSquared<T, size>(v));
	}

	template<typename T, int size>
	Vector<T, size> Normalize(Vector<T, size>& v)
	{
		T length = Length<T, size>(v);

		if (length > 0)
		{
			for (int i = 0; i < size; i++)
			{
				v[i] /= length;
			}
		}

		return v;
	}

	template<typename T, int size>
	T Dot(const Vector<T, size>& lhs, const Vector<T, size>& rhs)
	{
		T result = 0;
		for (int i = 0; i < size; i++)
		{
			result += (lhs[i] * rhs[i]);
		}

		return result;
	}
	
}//end ZMath

#endif