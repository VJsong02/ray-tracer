#pragma once

#include <iostream>

namespace Ray
{
	template <typename T>
	class vector
	{
	protected:
		T dim[3] = {0, 0, 0}; // Vector dimensions

	public:
		vector() {}

		vector(T x, T y, T z) // Construct vector
		{
			dim[0] = x;
			dim[1] = y;
			dim[2] = z;
		}

		T x() { return dim[0]; }
		T y() { return dim[1]; }
		T z() { return dim[2]; }

		friend std::ostream &operator<<(std::ostream &os, vector<T> &v)
		{
			return os << "(" << v.x() << " " << v.y() << " " << v.z() << ")";
		}

		vector<T> operator+(vector<T> &v)
		{
			return vector<T>(this->x() + v.x(), this->y() + v.y(), this->z() + v.z());
		}
	};
	
	template <typename T>
	class object {
		vector<T> location;
	};

	template <typename T>
	class ray : public vector<T>
	{
	protected:
		unsigned char brightness; // ray brightness 0 - 100

	public:
		ray() : vector() {}

		ray(T x, T y, T z, unsigned char b)
			: vector<T>(x, y, z)
		{
			brightness = b;
		}

		ray(vector<T> &v, unsigned char b)
			: vector<T>(v.x(), v.y(), v.z())
		{
			brightness = b;
		}

		unsigned char b() { return brightness; }

		friend std::ostream &operator<<(std::ostream &os, Ray::ray<T> &r)
		{
			return os << "(" << r.x() << " " << r.y() << " " << r.z() << ") " << +r.brightness() << "%";
		}

		bool trace(T increment) {
			
		}
	};

	template <typename T>
	vector<T> dot(vector<T> &a, vector<T> &b)
	{
		return vector<T>(a.x() * b.x(), a.y() * b.y(), a.z() * b.z());
	}

	template <typename T>
	vector<T> normalize(vector<T> &a)
	{
		T length = sqrt(a.x() * a.x(), a.y() * a.y(), a.z() * a.z());
		return *a / length;
	}

	template <typename T>
	ray<T> reflect(ray<T> &a, vector<T> &b)
	{
		unsigned char brightness = a.brightness;
		b = normalize(b);
		return ray<T>(a - 2 * dot(a, b) * b, a.brightness());
	}

	template <typename T>
	bool refract(ray<T> &a, vector<T> &b)
	{
	}

} // namespace Ray
