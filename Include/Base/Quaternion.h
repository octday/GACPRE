#pragma once

#include <Base/Matrix.h>

namespace gbase
{
	template <typename T>
	class BASE_TEMPLATE_API TQuaternion
	{
	public:
		inline TQuaternion()
		{

		}

		inline TQuaternion(const TQuaternion& q)
			: r(q.r),
			v(q.v)
		{

		}

		inline TQuaternion(T _r)
			: r(_r),
			v(T(0))
		{

		}

		inline TQuaternion(T _r, const TVector3<T>& _v)
			: r(_r),
			v(_v)
		{

		}

		inline TQuaternion(const TVector4<T>& _v)
			: r(_v[0]),
			v(_v[1], _v[2], _v[3])
		{
		}

		inline TQuaternion(T _x, T _y, T _z, T _w)
			: r(_x),
			v(_y, _z, _w)
		{

		}

		inline T& operator[](int n)
		{
			return mData[n];
		}

		inline const T& operator[](int n) const
		{
			return mData[n];
		}

		inline TQuaternion operator+(const TQuaternion& q) const
		{
			return Quaternion(r + q.r, v + q.v);
		}

		inline TQuaternion& operator+=(const TQuaternion& q)
		{
			r += q.r;
			v += q.v;

			return *this;
		}

		inline TQuaternion operator-(const TQuaternion& q) const
		{
			return Quaternion(r - q.r, v - q.v);
		}

		inline TQuaternion& operator-=(const TQuaternion& q)
		{
			r -= q.r;
			v -= q.v;

			return *this;
		}

		inline TQuaternion operator-() const
		{
			return TQuaternion(-r, -v);
		}

		inline TQuaternion operator*(const T s) const
		{
			return TQuaternion(mData[0] * s, mData[1] * s, mData[2] * s, mData[3] * s);
		}

		inline TQuaternion& operator*=(const T s)
		{
			r *= s;
			v *= s;

			return *this;
		}

		inline TQuaternion operator*(const TQuaternion& q) const
		{
			const T x1 = mData[0];
			const T y1 = mData[1];
			const T z1 = mData[2];
			const T w1 = mData[3];
			const T x2 = q.mData[0];
			const T y2 = q.mData[1];
			const T z2 = q.mData[2];
			const T w2 = q.mData[3];

			return TQuaternion(w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2,
				w1 * y2 + y1 * w2 + z1 * x2 - x1 * z2,
				w1 * z2 + z1 * w2 + x1 * y2 - y1 * x2,
				w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2);
		}

		inline TQuaternion operator/(const T s) const
		{
			return TQuaternion(mData[0] / s, mData[1] / s, mData[2] / s, mData[3] / s);
		}

		inline TQuaternion& operator/=(const T s)
		{
			r /= s;
			v /= s;

			return *this;
		}

		inline operator TVector4<T>&()
		{
			return *(TVector4<T>*)&mData[0];
		}

		inline operator const TVector4<T>&() const
		{
			return *(const TVector4<T>*)&mData[0];
		}

		inline bool operator==(const TQuaternion& q) const
		{
			return (r == q.r) && (v == q.v);
		}

		inline bool operator!=(const TQuaternion& q) const
		{
			return (r != q.r) || (v != q.v);
		}

		inline MatrixNM<T, 4, 4> asMatrix() const
		{
			MatrixNM<T, 4, 4> m;

			const T xx = x * x;
			const T yy = y * y;
			const T zz = z * z;
			const T ww = w * w;
			const T xy = x * y;
			const T xz = x * z;
			const T xw = x * w;
			const T yz = y * z;
			const T yw = y * w;
			const T zw = z * w;

			m[0][0] = T(1) - T(2) * (yy + zz);
			m[0][1] = T(2) * (xy - zw);
			m[0][2] = T(2) * (xz + yw);
			m[0][3] = T(0);

			m[1][0] = T(2) * (xy + zw);
			m[1][1] = T(1) - T(2) * (xx + zz);
			m[1][2] = T(2) * (yz - xw);
			m[1][3] = T(0);

			m[2][0] = T(2) * (xz - yw);
			m[2][1] = T(2) * (yz + xw);
			m[2][2] = T(1) - T(2) * (xx + yy);
			m[2][3] = T(0);

			m[3][0] = T(0);
			m[3][1] = T(0);
			m[3][2] = T(0);
			m[3][3] = T(1);

			return m;
		}

	private:
		union
		{
			struct
			{
				T           r;
				TVector3<T>    v;
			};
			struct
			{
				T           x;
				T           y;
				T           z;
				T           w;
			};
			T               mData[4];
		};
	};

	typedef TQuaternion<float> Quaternion;
	typedef TQuaternion<int> IQuaternion;
	typedef TQuaternion<unsigned int> UQuaternion;
	typedef TQuaternion<double> DQuaternion;

	template <typename T>
	static inline TQuaternion<T> operator*(T a, const TQuaternion<T>& b)
	{
		return b * a;
	}

	template <typename T>
	static inline TQuaternion<T> operator/(T a, const TQuaternion<T>& b)
	{
		return TQuaternion<T>(a / b[0], a / b[1], a / b[2], a / b[3]);
	}

	template <typename T>
	static inline TQuaternion<T> Normalize(const TQuaternion<T>& q)
	{
		return q / Length(VectorN<T, 4>(q));
	}

	template <typename T>
	static inline void QuaternionToMatrix(const TQuaternion<T>& q, MatrixNM<T, 4, 4>& m)
	{
		m = q.asMatrix();
	}
}