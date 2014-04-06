#ifndef ZMATH_H
#define ZMATH_H

///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is an implementaion of a SIMD vector math library for use in the						 //
//	Zephyr graphics engine.																		 //
//																								 //
//	Majority of implementation taken from the VMATH library inspired by the						 //
//	Gamasutra article Designing Fast Cross-Platform SIMD Vector Libraries by Gustavo Oliveira	 //
//	http://www.gamasutra.com/view/feature/4248/designing_fast_crossplatform_simd_.php			 //
//																								 //
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <xmmintrin.h>

namespace ZMath
{
	typedef __m128 Vec4;

	typedef __declspec(align(16)) struct Matrix4x4
	{
		Vec4 r[4];
	} Matrix4x4;

	//! Load takes an array of floats and loads it into a SIMD register.
	/*!
		\param pVec A pointer to an array of 4 floats that will be loaded into a SIMD vector.
		\return A SIMD Vector with the loaded data.
	*/
	inline Vec4 Load(float *pVec)
	{
		return(_mm_load_ps(pVec));
	}
	//! Load takes a single float and loads it into a SIMD register.
	/*!
		\param f A single precision floating point value to be loaded for all four values of the vector.
		\return A SIMD Vector with the loaded data.
	*/
	inline Vec4 Load(float f)
	{
		return(_mm_set_ps(f, f, f, f));
	}
	//! Load takes 4 floating point numbers and loads them into the vector.
	/*!
		\param x The x component of the vector.
		\param y The x component of the vector.
		\param z The x component of the vector.
		\param w The x component of the vector.
		\return A SIMD Vector with the loaded data.
	*/
	inline Vec4 Load(float x, float y, float z, float w)
	{
		return(_mm_set_ps(w, z, y, x));
	}
	//! Add Takes two Vec4s and returns the result of the vector addition.
	/*!
		\param a A Vec4 that will be summed with b.
		\param b A Vec4 that will be summed with a.
		\return A Vec4 that is the vector sum of a + b.
	*/
	inline Vec4 Add(Vec4 a, Vec4 b)
	{
		return(_mm_add_ps(a, b));
	}
	//! Sub Takes two Vec4s and returns the result of the vector subtraction.
	/*!
		\param a A Vec4 that will have the vector b subtracted from it.
		\param b A Vec4 that will subtracted from a.
		\return A Vec4 that is the result of the vector subtraction a - b.
	*/
	inline Vec4 Sub(Vec4 a, Vec4 b)
	{
		return(_mm_sub_ps(a, b));
	}
	//! Mul takes two Vec4s and returns a vector that is the result of the vector multiplication.
	/*!
		\param a A Vec4 that will be multiplied with b.
		\param b A Vec4 that will be multiplied with a.
		\return A Vec4 that is the result of the vector multiplication a * b.
	*/
	inline Vec4 Mul(Vec4 a, Vec4 b)
	{
		return(_mm_mul_ps(a, b));
	}
	//! Div takes two Vec4s and returns a vector that is the result of the component-wise vector division.
	/*!
		\param a A Vec4 that will be divided by b.
		\param b The Vec4 that will divide a.
		\return A Vec4 that is the result of the vector division a / b.
	*/
	inline Vec4 Div(Vec4 a, Vec4 b)
	{
		return(_mm_div_ps(a, b));
	}
	//! Store takes an array of single precision floating point values and SIMD vector and stores the vector in the float array.
	/*!
		\param pVec A pointer to an array of floats that will be filled by the vector v
		\param v A Vec4 that will be used to fill the float array.
	*/
	inline void Store(float *pVec, Vec4 v)
	{
		_mm_store_ps(pVec, v);
	}

	//////////////////////////////////////////////////////////////////////////////
	// Fast SSE2 4-dimensional dot product by Gustavo M. Oliveira.
	// Feel free to use for commercial or non-commercial applications,
	// as long as this header is mantained.
	//
	// For more information on how to write and use high-performance
	// SIMD Libraties, visit:
	// http://www.guitarv.com/ComputerScience.aspx?page=articles
	//
	// The author assumes NO RESPONSIBILITY and/or LIABILITY for any problems
	// caused by the use of this software. Use it at your own risk.
	//////////////////////////////////////////////////////////////////////////////


	//! Dot takes two Vectors and returns a vector whose components are all equal to the dot/scalar product result.
	/*!
		\param a A Vec4 that will be used to calculate a dot b.
		\param b A Vec4 that will be used to calculate a dot b.
		\return A Vec4 whose components will equal the result of the dot product. x = y = z = w = a dot b.
	*/
	inline Vec4 Dot(Vec4 a, Vec4 b)
	{
		Vec4 temp = _mm_mul_ps(a, b);
		Vec4 temp2 = _mm_shuffle_ps(temp, temp, _MM_SHUFFLE(2,3,0,1));
		temp = _mm_add_ps(temp, temp2);
		temp2 = _mm_shuffle_ps(temp, temp, _MM_SHUFFLE(0,0,3,3));
		return _mm_add_ps(temp, temp2);
	}
	//! Cross takes two Vectors and returns a vector that is the result of the cross/vector product.
	/*!
		\param a A Vec4 that will be used to calculate a cross b.
		\param b A Vec4 that will be used to calculate a cross b.
		\return A Vec4 that is the result of a cross b.
	*/
	inline Vec4 Cross(Vec4 a, Vec4 b)
	{
		Vec4 result = _mm_sub_ps(_mm_mul_ps(a, _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1))),
			_mm_mul_ps(b, _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1))));
		return _mm_shuffle_ps(result, result, _MM_SHUFFLE(3, 0, 2, 1));

		//return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2))),
				//		  _mm_mul_ps(_mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1))));

		/*Vec4 t0 = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1));
		Vec4 t1 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2));
		Vec4 t3 = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2));
		Vec4 t4 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1));

		t0 = _mm_mul_ps(t0, t1);
		t3 = _mm_mul_ps(t3, t4);

		return _mm_sub_ps(t0, t3);*/
	}
}

#endif