#pragma once

#include <iostream>

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

    T get_vector(unsigned char d) { return const dim[d]; }
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

    unsigned char get_brightness() { return const brightness; }
};

template <typename T>
bool reflect(ray<T> &a, ray<T> &b)
{
}

template <typename T>
bool refract(ray<T> &a, ray<T> &b)
{
}

} // namespace Ray

template <typename T>
std::ostream &operator<<(std::ostream &os, const Ray::vector<T> &v)
{
    return os << "(" << v.get_vector(0) << " " << v.get_vector(1) << " " << v.get_vector(2) << ")";
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Ray::ray<T> &r)
{
    return os << "(" << r.get_vector(0) << " " << r.get_vector(1) << " " << r.get_vector(2) << ") " << r.get_brightness() << "%";
}