#pragma once

#include <cmath>
#include <ostream>
#include <string>

namespace Ray
{
template <typename T>
class vector
{
  protected:
	T dim[3]; // Vector dimensions

  public:
	vector(T x, T y, T z) // Construct vector
	{
		dim[0] = x;
		dim[1] = y;
		dim[2] = z;
	}

	T x() { return dim[0]; }
	T y() { return dim[1]; }
	T z() { return dim[2]; }

	void set(T x, T y, T z)
	{
		dim[0] = x;
		dim[1] = y;
		dim[2] = z;
	}

	friend std::ostream &operator<<(std::ostream &os, vector<T> &v)
	{
		os << "(" << v.x() << " " << v.y() << " " << v.z() << ")";
		return os;
	}

	vector<T> operator+(const vector<T> &v)
	{
		return vector<T>(this->x() + *v.x(), this->y() + *v.y(), this->z() + *v.z());
	}

	vector<T> operator-(vector<T> &v)
	{
		return vector<T>(this->x() - v.x(), this->y() - v.y(), this->z() - v.z());
	}

	vector<T> operator*(vector<T> &v)
	{
		return vector<T>(this->x() * v.x(), this->y() * v.y(), this->z() * v.z());
	}

	vector<T> operator*(T k)
	{
		return vector<T>(this->x() * k, this->y() * k, this->z() * k);
	}

	vector<T> operator/(T k)
	{
		return vector<T>(this->x() / k, this->y() / k, this->z() / k);
	}
};

template <typename T>
class object
{
	vector<T> location;
};

template <typename T>
class ray : public vector<T>
{
  protected:
	unsigned char brightness; // ray brightness 0 - 100

  public:
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

	void set(T x, T y, T z, unsigned char brightness)
	{
		dim[0] = x;
		dim[1] = y;
		dim[2] = z;
		b = brightness;
	}

	vector<T> strip()
	{
		return vector<T>(this->x(), this->y(), this->z());
	}

	unsigned char b() { return brightness; }

	friend std::ostream operator<<(std::ostream &os, Ray::ray<T> &r)
	{
		os << "(" << r.x() << " " << r.y() << " " << r.z() << ") " << +r.b() << "%";
		return os;
	}

	bool trace(T increment)
	{
	}
};

namespace functions
{
template <typename T>
vector<T> dot(vector<T> &a, vector<T> &b)
{
	return vector<T>(a.x() * b.x(), a.y() * b.y(), a.z() * b.z());
}

template <typename T>
vector<T> normalize(vector<T> &a)
{
	T length = sqrt(a.x() * a.x() + a.y() * a.y() + a.z() * a.z());
	return a / length;
}

template <typename T>
ray<T> reflect(ray<T> &a, vector<T> &b)
{
	unsigned char brightness = a.b();
	b = normalize(b);
	return ray<T>(a.strip() - dot(a, b) * b * (T)2, a.b());
}

template <typename T>
bool refract(ray<T> &a, vector<T> &b)
{
}
} // namespace functions
} // namespace Ray