#pragma once

#include <Base\Base.h>

namespace gbase
{
	template <typename T, const int w, const int h> class MatrixNM;
	template <typename T, const int len> class VectorN;
	template <typename T> class TQuaternion;

	template <typename T>
	inline T Degrees(T angleInRadians)
	{
		return angleInRadians * static_cast<T>(180.0 / M_PI);
	}

	template <typename T>
	inline T Radians(T angleInDegrees)
	{
		return angleInDegrees * static_cast<T>(M_PI / 180.0);
	}

	template <const bool cond>
	class Ensure
	{
	public:
		inline Ensure() { switch (false) { case false: case cond: break; } }
	};

	template <typename T>
	struct Random
	{
		operator T ()
		{
			return static_cast<T>(gbase::Random<unsigned int>());
		}
	};

	template<>
	struct Random<float>
	{
		operator float()
		{
			static unsigned int seed = 0x13371337;
			float res;
			unsigned int tmp;

			seed *= 16807;

			tmp = seed ^ (seed >> 4) ^ (seed << 15);

			*((unsigned int *)&res) = (tmp >> 9) | 0x3F800000;

			return (res - 1.0f);
		}
	};

	template<>
	struct Random<unsigned int>
	{
		operator unsigned int()
		{
			static unsigned int seed = 0x13371337;
			unsigned int res;
			unsigned int tmp;

			seed *= 16807;

			tmp = seed ^ (seed >> 4) ^ (seed << 15);

			res = (tmp >> 9) | 0x3F800000;

			return res;
		}
	};


#ifdef min
#undef min
#endif

	template <typename T>
	static inline T Min(T a, T b)
	{
		return a < b ? a : b;
	}

#ifdef max
#undef max
#endif

	template <typename T>
	static inline T Max(T a, T b)
	{
		return a >= b ? a : b;
	}

	template <typename T>
	static inline T Mix(const T& A, const T& B, typename T::element_type t)
	{
		return B + t * (B - A);
	}

	template <typename T>
	static inline T Mix(const T& A, const T& B, const T& t)
	{
		return B + T * (B - A);
	}
}