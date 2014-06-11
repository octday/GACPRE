#pragma once

#include <Base/MathBase.h>

namespace gbase
{
	template <typename T, const int len>
	class BASE_TEMPLATE_API VectorN
	{
	public:
		typedef class VectorN<T, len> SpecificType;
		typedef T ElementType;

		// Default constructor does nothing, just like built-in types
		inline VectorN()
		{
			// Uninitialized variable
		}

		// Copy constructor
		inline VectorN(const VectorN& that)
		{
			Assign(that);
		}

		// Construction from scalar
		inline VectorN(T s)
		{
			int n;
			for (n = 0; n < len; n++)
			{
				mData[n] = s;
			}
		}

		// Assignment operator
		inline VectorN& operator=(const VectorN& that)
		{
			Assign(that);
			return *this;
		}

		inline VectorN& operator=(const T& that)
		{
			int n;
			for (n = 0; n < len; n++)
				mData[n] = that;

			return *this;
		}

		inline VectorN operator+(const VectorN& that) const
		{
			SpecificType result;
			int n;
			for (n = 0; n < len; n++)
				result.mData[n] = mData[n] + that.mData[n];
			return result;
		}

		inline VectorN& operator+=(const VectorN& that)
		{
			return (*this = *this + that);
		}

		inline VectorN operator-() const
		{
			SpecificType result;
			int n;
			for (n = 0; n < len; n++)
				result.mData[n] = -mData[n];
			return result;
		}

		inline VectorN operator-(const VectorN& that) const
		{
			SpecificType result;
			int n;
			for (n = 0; n < len; n++)
				result.mData[n] = mData[n] - that.mData[n];
			return result;
		}

		inline VectorN& operator-=(const VectorN& that)
		{
			return (*this = *this - that);
		}

		inline VectorN operator*(const VectorN& that) const
		{
			SpecificType result;
			int n;
			for (n = 0; n < len; n++)
				result.mData[n] = mData[n] * that.mData[n];
			return result;
		}

		inline VectorN& operator*=(const VectorN& that)
		{
			return (*this = *this * that);
		}

		inline VectorN operator*(const T& that) const
		{
			SpecificType result;
			int n;
			for (n = 0; n < len; n++)
				result.mData[n] = mData[n] * that;
			return result;
		}

		inline VectorN& operator*=(const T& that)
		{
			Assign(*this * that);

			return *this;
		}

		inline VectorN operator/(const VectorN& that) const
		{
			SpecificType result;
			int n;
			for (n = 0; n < len; n++)
				result.mData[n] = mData[n] / that.mData[n];
			return result;
		}

		inline VectorN& operator/=(const VectorN& that)
		{
			Assign(*this / that);

			return *this;
		}

		inline VectorN operator/(const T& that) const
		{
			SpecificType result;
			int n;
			for (n = 0; n < len; n++)
				result.mData[n] = mData[n] / that;
			return result;
		}

		inline VectorN& operator/=(const T& that)
		{
			Assign(*this / that);
			return *this;
		}

		inline T& operator[](int n) { return mData[n]; }
		inline const T& operator[](int n) const { return mData[n]; }

		inline static int GetSize(void) { return len; }

		inline operator const T* () const { return &mData[0]; }

		static inline VectorN Random()
		{
			VectorN result;
			int i;

			for (i = 0; i < len; i++)
			{
				result[i] = gbase::Random<T>();
			}
			return result;
		}

	protected:
		T mData[len];

		inline void Assign(const VectorN& that)
		{
			int n;
			for (n = 0; n < len; n++)
				mData[n] = that.mData[n];
		}
	};

	template <typename T, int n>
	static inline const VectorN<T, n> operator * (T x, const VectorN<T, n>& v)
	{
		return v * x;
	}

	template <typename T, int len>
	static inline T Dot(const VectorN<T, len>& a, const VectorN<T, len>& b)
	{
		int n;
		T total = T(0);
		for (n = 0; n < len; n++)
		{
			total += a[n] * b[n];
		}
		return total;
	}

	template <typename T>
	static inline VectorN<T, 3> Cross(const VectorN<T, 3>& a, const VectorN<T, 3>& b)
	{
		return TVector3<T>(a[1] * b[2] - b[1] * a[2],
			a[2] * b[0] - b[2] * a[0],
			a[0] * b[1] - b[0] * a[1]);
	}

	template <typename T, int len>
	static inline T Length(const VectorN<T, len>& v)
	{
		T result(0);

		for (int i = 0; i < v.GetSize(); ++i)
		{
			result += v[i] * v[i];
		}

		return (T)sqrt(result);
	}

	template <typename T, int len>
	static inline VectorN<T, len> Normalize(const VectorN<T, len>& v)
	{
		return v / Length(v);
	}

	template <typename T, int len>
	static inline T Distance(const VectorN<T, len>& a, const VectorN<T, len>& b)
	{
		return Length(b - a);
	}

	template <typename T, int len>
	static inline T Angle(const VectorN<T, len>& a, const VectorN<T, len>& b)
	{
		return arccos(Dot(a, b));
	}

	template <typename T, const int N>
	static inline VectorN<T, N> Min(const VectorN<T, N>& x, const VectorN<T, N>& y)
	{
		VectorN<T, N> t;
		int n;

		for (n = 0; n < N; n++)
		{
			t[n] = Min(x[n], y[n]);
		}

		return t;
	}

	template <typename T, const int N>
	static inline VectorN<T, N> Max(const VectorN<T, N>& x, const VectorN<T, N>& y)
	{
		VectorN<T, N> t;
		int n;

		for (n = 0; n < N; n++)
		{
			t[n] = Max<T>(x[n], y[n]);
		}

		return t;
	}

	template <typename T, const int N>
	static inline VectorN<T, N> Clamp(const VectorN<T, N>& x, const VectorN<T, N>& minVal, const VectorN<T, N>& maxVal)
	{
		return Min<T>(Max<T>(x, minVal), maxVal);
	}

	template <typename T, const int N>
	static inline VectorN<T, N> Smoothstep(const VectorN<T, N>& edge0, const VectorN<T, N>& edge1, const VectorN<T, N>& x)
	{
		VectorN<T, N> t;
		t = Clamp((x - edge0) / (edge1 - edge0), VectorN<T, N>(T(0)), VectorN<T, N>(T(1)));
		return t * t * (VectorN<T, N>(T(3)) - VectorN<T, N>(T(2)) * t);
	}

	template <typename T, const int S>
	static inline VectorN<T, S> Reflect(const VectorN<T, S>& I, const VectorN<T, S>& N)
	{
		return I - 2 * Dot(N, I) * N;
	}

	template <typename T, const int S>
	static inline VectorN<T, S> Refract(const VectorN<T, S>& I, const VectorN<T, S>& N, T eta)
	{
		T d = Dot(N, I);
		T k = T(1) - eta * eta * (T(1) - d * d);
		if (k < 0.0)
		{
			return VectorN<T, N>(0);
		}
		else
		{
			return eta * I - (eta * d + sqrt(k)) * N;
		}
	}

	template <typename T, const int N>
	static inline VectorN<T, N> operator/(const T s, const VectorN<T, N>& v)
	{
		int n;
		VectorN<T, N> result;

		for (n = 0; n < N; n++)
		{
			result[n] = s / v[n];
		}

		return result;
	}

	template <typename T>
	class BASE_TEMPLATE_API TVector2 : public VectorN<T, 2>
	{
	public:
		typedef VectorN<T, 2> Base;

		// Uninitialized variable
		inline TVector2() {}
		// Copy constructor
		inline TVector2(const Base& v) : Base(v) {}

		// vec2(x, y);
		inline TVector2(T x, T y)
		{
			Base::mData[0] = x;
			Base::mData[1] = y;
		}
	};

	typedef TVector2<float> Vector2;
	typedef TVector2<int> IVector2;
	typedef TVector2<unsigned int> UVector2;
	typedef TVector2<double> DVector2;

	template <typename T>
	static inline const TVector2<T> operator / (T x, const TVector2<T>& v)
	{
		return TVector2<T>(x / v[0], x / v[1]);
	}


	template <typename T>
	class BASE_TEMPLATE_API TVector3 : public VectorN<T, 3>
	{
	public:
		typedef VectorN<T, 3> Base;

		// Uninitialized variable
		inline TVector3() {}

		// Copy constructor
		inline TVector3(const Base& v) : Base(v) {}

		// vec3(x, y, z);
		inline TVector3(T x, T y, T z)
		{
			Base::mData[0] = x;
			Base::mData[1] = y;
			Base::mData[2] = z;
		}

		// vec3(v, z);
		inline TVector3(const TVector2<T>& v, T z)
		{
			Base::mData[0] = v[0];
			Base::mData[1] = v[1];
			Base::mData[2] = z;
		}

		// vec3(x, v)
		inline TVector3(T x, const TVector2<T>& v)
		{
			Base::mData[0] = x;
			Base::mData[1] = v[0];
			Base::mData[2] = v[1];
		}
	};

	typedef TVector3<float> Vector3;
	typedef TVector3<int> IVector3;
	typedef TVector3<unsigned int> UVector3;
	typedef TVector3<double> DVector3;

	template <typename T>
	static inline const TVector3<T> operator / (T x, const TVector3<T>& v)
	{
		return TVector3<T>(x / v[0], x / v[1], x / v[2]);
	}

	template <typename T>
	class BASE_TEMPLATE_API TVector4 : public VectorN<T, 4>
	{
	public:
		typedef VectorN<T, 4> Base;

		// Uninitialized variable
		TVector4() {}

		// Copy constructor
		inline TVector4(const Base& v) : Base(v) {}

		// vec4(x, y, z, w);
		inline TVector4(T x, T y, T z, T w)
		{
			Base::mData[0] = x;
			Base::mData[1] = y;
			Base::mData[2] = z;
			Base::mData[3] = w;
		}

		// vec4(v, z, w);
		inline TVector4(const TVector2<T>& v, T z, T w)
		{
			Base::mData[0] = v[0];
			Base::mData[1] = v[1];
			Base::mData[2] = z;
			Base::mData[3] = w;
		}

		// vec4(x, v, w);
		inline TVector4(T x, const TVector2<T>& v, T w)
		{
			Base::mData[0] = x;
			Base::mData[1] = v[0];
			Base::mData[2] = v[1];
			Base::mData[3] = w;
		}

		// vec4(x, y, v);
		inline TVector4(T x, T y, const TVector2<T>& v)
		{
			Base::mData[0] = x;
			Base::mData[1] = y;
			Base::mData[2] = v[0];
			Base::mData[3] = v[1];
		}

		// vec4(v1, v2);
		inline TVector4(const TVector2<T>& u, const TVector2<T>& v)
		{
			Base::mData[0] = u[0];
			Base::mData[1] = u[1];
			Base::mData[2] = v[0];
			Base::mData[3] = v[1];
		}

		// vec4(v, w);
		inline TVector4(const TVector3<T>& v, T w)
		{
			Base::mData[0] = v[0];
			Base::mData[1] = v[1];
			Base::mData[2] = v[2];
			Base::mData[3] = w;
		}

		// vec4(x, v);
		inline TVector4(T x, const TVector3<T>& v)
		{
			Base::mData[0] = x;
			Base::mData[1] = v[0];
			Base::mData[2] = v[1];
			Base::mData[3] = v[2];
		}
	};

	typedef TVector4<float> Vector4;
	typedef TVector4<int> IVector4;
	typedef TVector4<unsigned int> UVector4;
	typedef TVector4<double> DVector4;

	template <typename T>
	static inline const TVector4<T> operator / (T x, const TVector4<T>& v)
	{
		return TVector4<T>(x / v[0], x / v[1], x / v[2], x / v[3]);
	}

	static const Vector4 ZeroColor = Vector4(0.0f, 0.0f, 0.0f, 0.0f);
	static const Vector4 WhiteColor = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
	static const Vector4 BlackColor = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
	static const Vector4 RedColor = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
	static const Vector4 GreenColor = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
	static const Vector4 BlueColor = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
	static const Vector4 OrangeColor = Vector4(1.0f, 0.65f, 0.0f, 1.0f);
	static const Vector4 YellowColor = Vector4(1.0f, 1.0f, 0.0f, 1.0f);
	static const Vector4 GrayColor = Vector4(0.5f, 0.5f, 0.5f, 1.0f);

	
}