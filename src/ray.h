#pragma once

#include <ostream>

namespace Ray
{
	template <typename T>
	class vector
	{
	protected:
		T dim[3]; // Vector dimensions

	public:
		vector(T x, T y, T z)
		{
			dim[0] = x;
			dim[1] = y;
			dim[2] = z;
		}

		T x(unsigned char d) { return dim[0]; }
		T y(unsigned char d) { return dim[1]; }
		T z(unsigned char d) { return dim[2]; }

		friend std::ostream& operator<<(std::ostream& os, Ray::vector<T>& v)
		{
			return os << "(" << v.x() << " " << v.y() << " " << v.z() << ")";
		}

		vector<T> operator+(vector<T>& v)
		{
			vector<T> result = *this;
			return vector<T>(result.x() + v.x(), result.y() + v.y(), result.z() + v.z());
		}

		vector<T> operator-(vector<T> & v)
		{
			vector<T> result = *this;
			return vector<T>(result.x() - v.x(), result.y() - v.y(), result.z() - v.z());
		}

		vector<T> operator*(vector<T> & v)
		{
			vector<T> result = *this;
			return vector<T>(result.x() * v.x(), result.y() * v.y(), result.z() * v.z());
		}

		vector<T> operator*(T k)
		{
			vector<T> result = *this;
			return vector<T>(result.x() * k, result.y() * k, result.z() * k);
		}

		vector<T> operator/(vector<T> & v)
		{
			vector<T> result = *this;
			return vector<T>(result.x() / v.x(), result.y() / v.y(), result.z() / v.z());
		}

		vector<T> dot(vector<T> & a, vector<T> & b)
		{
			return vector<T>(a.x() * b.x(), a.y() * b.y(), a.z() * b.z());
		}

		vector<T> normalize(vector<T> & a)
		{
			T length = sqrt(a.x() * a.x(), a.y() * a.y(), a.z() * a.z());
			return *a / length;
		}
	};

	template <typename T>
	class ray : public vector<T>
	{
	protected:
		unsigned char brightness; // ray brightness

	public:
		ray(T x, T y, T z, unsigned char b)
			: vector<T>(x, y, z)
		{
			brightness = b;
		}

		ray(vector<T>& v, unsigned char b)
			: vector<T>(v.x(), v.y(), v.z())
		{
			brightness = b;
		}

		unsigned char brightness() { return brightness; }

		friend std::ostream& operator<<(std::ostream& os, Ray::ray<T>& r)
		{
			return os << "(" << r.x() << " " << r.y() << " " << r.z() << ") " << +r.brightness() << "%";
		}
	};

	template <typename T>
	ray<T> reflect(ray<T> & a, vector<T> & b)
	{
		unsigned char brightness = a.brightness;
		vector<T> b = normalize(b);
		return ray<T>(a - 2 * dot(a, b) * b, a.brightness());
	}

	template <typename T>
	bool refract(ray<T> & a, vector<T> & b)
	{

	}

} // namespace Ray
