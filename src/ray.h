#pragma once

#include <iostream>

namespace Ray
{
	template <typename T>
	class vector
	{
	protected:
		T vector[3]; // Vector dimensions

	public:
		vector(T x, T y, T z)
		{
			vector[0] = x;
			vector[1] = y;
			vector[2] = z;
		}

		T get_vector(unsigned char d) { return vector[d]; }
	};

	template <typename T>
	class ray : public vector<T>
	{
	protected:
		unsigned char brightness; // ray brightness

	public:
		ray(T x, T y, T z, unsigned char b)
		{
			vector[0] = x;
			vector[1] = y;
			vector[2] = z;
			brightness = b;
		}

		unsigned char get_brightness() { return brightness; }
	};

	template <typename T>
	bool reflect(ray<T>& a, ray<T>& b)
	{

	}

	template <typename T>
	bool refract(ray<T>& a, ray<T>& b)
	{

	}


} // namespace Ray

template <typename T>
std::ostream& operator<<(std::ostream& os, const Ray::vector<T>& v)
{
	return os << "(" << v.get_vector(0) << " " << v.get_vector(1) << " " << v.get_vector(2) << ")";
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Ray::ray<T>& r)
{
	return os << "(" << r.get_vector(0) << " " << r.get_vector(1) << " " << r.get_vector(2) << ") " << r.get_brightness() << "%";
}