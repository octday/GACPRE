#pragma once

#include <Base/Vector.h>

namespace gbase
{
	template <typename T, const int w, const int h>
	class BASE_TEMPLATE_API MatrixNM
	{
	public:
		typedef class MatrixNM<T, w, h> SpecificType;
		typedef class VectorN<T, h> ElementType;

		// Default constructor does nothing, just like built-in types
		inline MatrixNM()
		{
			// Uninitialized variable
		}

		// Copy constructor
		inline MatrixNM(const MatrixNM& that)
		{
			assign(that);
		}

		// Construction from element type
		// explicit to prevent assignment from T
		explicit inline MatrixNM(T f)
		{
			for (int n = 0; n < w; n++)
			{
				mData[n] = f;
			}
		}

		// Construction from vector
		inline MatrixNM(const ElementType& v)
		{
			for (int n = 0; n < w; n++)
			{
				mData[n] = v;
			}
		}

		// Assignment operator
		inline MatrixNM& operator=(const SpecificType& that)
		{
			assign(that);
			return *this;
		}

		inline MatrixNM operator+(const SpecificType& that) const
		{
			SpecificType result;
			int n;
			for (n = 0; n < w; n++)
				result.data[n] = mData[n] + that.data[n];
			return result;
		}

		inline SpecificType& operator+=(const SpecificType& that)
		{
			return (*this = *this + that);
		}

		inline SpecificType operator-(const SpecificType& that) const
		{
			SpecificType result;
			int n;
			for (n = 0; n < w; n++)
				result.data[n] = mData[n] - that.data[n];
			return result;
		}

		inline SpecificType& operator-=(const SpecificType& that)
		{
			return (*this = *this - that);
		}

		inline SpecificType operator*(const T& that) const
		{
			SpecificType result;
			int n;
			for (n = 0; n < w; n++)
				result.data[n] = mData[n] * that;
			return result;
		}

		inline SpecificType& operator*=(const T& that)
		{
			int n;
			for (n = 0; n < w; n++)
				mData[n] = mData[n] * that;
			return result;
		}

		// Matrix multiply.
		// TODO: This only works for square matrices. Need more template skill to make a non-square version.
		inline SpecificType operator*(const SpecificType& that) const
		{
			Ensure<w == h>();

			SpecificType result(0);

			for (int j = 0; j < w; j++)
			{
				for (int i = 0; i < h; i++)
				{
					T sum(0);

					for (int n = 0; n < w; n++)
					{
						sum += mData[n][i] * that[j][n];
					}

					result[j][i] = sum;
				}
			}

			return result;
		}

		inline SpecificType& operator*=(const SpecificType& that)
		{
			return (*this = *this * that);
		}

		inline ElementType& operator[](int n) { return mData[n]; }
		inline const ElementType& operator[](int n) const { return mData[n]; }
		inline operator T*() { return &mData[0][0]; }
		inline operator const T*() const { return &mData[0][0]; }

		inline MatrixNM<T, h, w> Transpose(void) const
		{
			MatrixNM<T, h, w> result;
			int x, y;

			for (y = 0; y < w; y++)
			{
				for (x = 0; x < h; x++)
				{
					result[x][y] = mData[y][x];
				}
			}

			return result;
		}

		static inline SpecificType Identity()
		{
			Ensure<w == h>();

			SpecificType result(0);

			for (int i = 0; i < w; i++)
			{
				result[i][i] = 1;
			}

			return result;
		}

		static inline int Width(void) { return w; }
		static inline int Height(void) { return h; }

	protected:
		// Column primary data (essentially, array of vectors)
		VectorN<T, h> mData[w];

		// Assignment function - called from assignment operator and copy constructor.
		inline void assign(const MatrixNM& that)
		{
			int n;
			for (n = 0; n < w; n++)
				mData[n] = that.mData[n];
		}
	};

	template <typename T, const int N, const int M>
	static inline MatrixNM<T, N, M> MatrixCompMult(const MatrixNM<T, N, M>& x, const MatrixNM<T, N, M>& y)
	{
		MatrixNM<T, N, M> result;
		int i, j;

		for (j = 0; j < M; ++j)
		{
			for (i = 0; i < N; ++i)
			{
				result[i][j] = x[i][j] * y[i][j];
			}
		}

		return result;
	}

	template <typename T, const int N, const int M>
	static inline VectorN<T, N> operator*(const VectorN<T, M>& vec, const MatrixNM<T, N, M>& mat)
	{
		int n, m;
		VectorN<T, N> result(T(0));

		for (m = 0; m < M; m++)
		{
			for (n = 0; n < N; n++)
			{
				result[n] += vec[m] * mat[n][m];
			}
		}

		return result;
	}


	template <typename T>
	class BASE_TEMPLATE_API TMatrix3 : public MatrixNM<T, 3, 3>
	{
	public:
		typedef MatrixNM<T, 3, 3> Base;
		typedef TMatrix3<T> SpecificType;

		inline TMatrix3() {}
		inline TMatrix3(const SpecificType& that) : Base(that) {}
		inline TMatrix3(const Base& that) : Base(that) {}
		inline TMatrix3(const VectorN<T, 3>& v) : Base(v) {}
		inline TMatrix3(const VectorN<T, 3>& v0,
			const VectorN<T, 3>& v1,
			const VectorN<T, 3>& v2)
		{
			Base::mData[0] = v0;
			Base::mData[1] = v1;
			Base::mData[2] = v2;
		}
	};

	typedef TMatrix3<float> Matrix3;
	typedef TMatrix3<double> DMatrix3;

	template <typename T>
	class BASE_TEMPLATE_API TMatrix4 : public MatrixNM<T, 4, 4>
	{
	public:
		typedef MatrixNM<T, 4, 4> Base;
		typedef TMatrix4<T> SpecificType;

		inline TMatrix4() {}
		inline TMatrix4(const SpecificType& that) : Base(that) {}
		inline TMatrix4(const Base& that) : Base(that) {}
		inline TMatrix4(const VectorN<T, 4>& v) : Base(v) {}
		inline TMatrix4(const VectorN<T, 4>& v0,
			const VectorN<T, 4>& v1,
			const VectorN<T, 4>& v2,
			const VectorN<T, 4>& v3)
		{
			Base::mData[0] = v0;
			Base::mData[1] = v1;
			Base::mData[2] = v2;
			Base::mData[3] = v3;
		}
	};

	typedef TMatrix4<float> Matrix4;
	typedef TMatrix4<double> DMatrix4;

	static inline Matrix4 Frustum(float left, float right, float bottom, float top, float n, float f)
	{
		Matrix4 result(Matrix4::Identity());

		if ((right == left) ||
			(top == bottom) ||
			(n == f) ||
			(n < 0.0) ||
			(f < 0.0))
			return result;

		result[0][0] = (2.0f * n) / (right - left);
		result[1][1] = (2.0f * n) / (top - bottom);

		result[2][0] = (right + left) / (right - left);
		result[2][1] = (top + bottom) / (top - bottom);
		result[2][2] = -(f + n) / (f - n);
		result[2][3] = -1.0f;

		result[3][2] = -(2.0f * f * n) / (f - n);
		result[3][3] = 0.0f;

		return result;
	}

	static inline Matrix4 Perspective(float fovy, float aspect, float n, float f)
	{
		float q = 1.0f / tan(Radians(0.5f * fovy));
		float A = q / aspect;
		float B = (n + f) / (n - f);
		float C = (2.0f * n * f) / (n - f);

		Matrix4 result;

		result[0] = Vector4(A, 0.0f, 0.0f, 0.0f);
		result[1] = Vector4(0.0f, q, 0.0f, 0.0f);
		result[2] = Vector4(0.0f, 0.0f, B, -1.0f);
		result[3] = Vector4(0.0f, 0.0f, C, 0.0f);

		return result;
	}

	static inline Matrix4 Ortho(float left, float right, float bottom, float top, float n, float f)
	{
		return Matrix4(Vector4(2.0f / (right - left), 0.0f, 0.0f, 0.0f),
			Vector4(0.0f, 2.0f / (top - bottom), 0.0f, 0.0f),
			Vector4(0.0f, 0.0f, 2.0f / (n - f), 0.0f),
			Vector4((left + right) / (left - right), (bottom + top) / (bottom - top), (n + f) / (f - n), 1.0f));
	}

	template <typename T>
	static inline TMatrix4<T> Translate(T x, T y, T z)
	{
		return TMatrix4<T>(TVector4<T>(1.0f, 0.0f, 0.0f, 0.0f),
			TVector4<T>(0.0f, 1.0f, 0.0f, 0.0f),
			TVector4<T>(0.0f, 0.0f, 1.0f, 0.0f),
			TVector4<T>(x, y, z, 1.0f));
	}

	template <typename T>
	static inline TMatrix4<T> Translate(const VectorN<T, 3>& v)
	{
		return Translate(v[0], v[1], v[2]);
	}

	template <typename T>
	static inline TMatrix4<T> Lookat(const VectorN<T, 3>& eye, const VectorN<T, 3>& center, const VectorN<T, 3>& up)
	{
		const TVector3<T> f = Normalize(center - eye);
		const TVector3<T> upN = Normalize(up);
		const TVector3<T> s = Cross(f, upN);
		const TVector3<T> u = Cross(s, f);
		const TMatrix4<T> M = TMatrix4<T>(TVector4<T>(s[0], u[0], -f[0], T(0)),
			TVector4<T>(s[1], u[1], -f[1], T(0)),
			TVector4<T>(s[2], u[2], -f[2], T(0)),
			TVector4<T>(T(0), T(0), T(0), T(1)));

		return M * Translate<T>(-eye);
	}

	template <typename T>
	static inline TMatrix4<T> Scale(T x, T y, T z)
	{
		return TMatrix4<T>(TVector4<T>(x, 0.0f, 0.0f, 0.0f),
			TVector4<T>(0.0f, y, 0.0f, 0.0f),
			TVector4<T>(0.0f, 0.0f, z, 0.0f),
			TVector4<T>(0.0f, 0.0f, 0.0f, 1.0f));
	}

	template <typename T>
	static inline TMatrix4<T> Scale(const TVector3<T>& v)
	{
		return Scale(v[0], v[1], v[2]);
	}

	template <typename T>
	static inline TMatrix4<T> Scale(T x)
	{
		return TMatrix4<T>(TVector4<T>(x, 0.0f, 0.0f, 0.0f),
			TVector4<T>(0.0f, x, 0.0f, 0.0f),
			TVector4<T>(0.0f, 0.0f, x, 0.0f),
			TVector4<T>(0.0f, 0.0f, 0.0f, 1.0f));
	}

	template <typename T>
	static inline TMatrix4<T> Rotate(T angle, T x, T y, T z)
	{
		TMatrix4<T> result;

		const T x2 = x * x;
		const T y2 = y * y;
		const T z2 = z * z;
		float rads = float(angle) * 0.0174532925f;
		const float c = cosf(rads);
		const float s = sinf(rads);
		const float omc = 1.0f - c;

		result[0] = TVector4<T>(T(x2 * omc + c), T(y * x * omc + z * s), T(x * z * omc - y * s), T(0));
		result[1] = TVector4<T>(T(x * y * omc - z * s), T(y2 * omc + c), T(y * z * omc + x * s), T(0));
		result[2] = TVector4<T>(T(x * z * omc + y * s), T(y * z * omc - x * s), T(z2 * omc + c), T(0));
		result[3] = TVector4<T>(T(0), T(0), T(0), T(1));

		return result;
	}

	template <typename T>
	static inline TMatrix4<T> Rotate(T angle, const VectorN<T, 3>& v)
	{
		return rotate<T>(angle, v[0], v[1], v[2]);
	}

	template <typename T>
	static inline TMatrix4<T> Rotate(T angle_x, T angle_y, T angle_z)
	{
		return Rotate(angle_z, 0.0f, 0.0f, 1.0f) *
			Rotate(angle_y, 0.0f, 1.0f, 0.0f) *
			Rotate(angle_x, 1.0f, 0.0f, 0.0f);
	}
}