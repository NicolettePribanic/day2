#include "array.h"
#include <algorithm>
#include <stdexcept>

array::array(int size, double value)
{
	if (size < 0) throw std::out_of_range("Size is too small!");
	n = size;
	p = new double[size];
	std::fill(p, p + size, value);
}

array::array(const array & other)
{
	n = other.n;
	p = new double[n];
	std::copy(other.p, other.p + n, p);
}

array::array(array && other) noexcept : n(std::exchange(other.n, 0)), p(std::exchange(other.p, nullptr)) {}

array & array::operator=(array other)
{
	std::swap(n, other.n);
	std::swap(p, other.p);
	return *this;
}

array & array::operator=(array && other)
{
	n = std::move(other.n);
	p = std::move(other.p);
	return *this;
}

array::~array()
{
	if (p == nullptr) return;
	delete[] p;
	p = nullptr;
	n = 0;

}

int array::size() const
{
	return n;
}

double array::at(int index) const
{
	if (index > n || index < 0) throw std::out_of_range("Index out of range!");
	return *(p + index);
}
