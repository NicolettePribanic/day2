#include "array.h"
#include <algorithm>
#include <stdexcept>

array::array(int size, double value)
{
	if (size < 0) return;
	n = size;
	p = new double[size];
	std::fill(p, p + size, value);
}

array::array(const array & other) : n(other.n), p (other.p) {}

array::array(array && other) noexcept : n(std::exchange(other.n, 0)), p(std::move(other.p)) {}

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

array::~array() {}

int array::size() const
{
	return n;
}

double array::at(int index) const
{
	if (index > n || index < 0) throw std::out_of_range("Index out of range!");
	return *(p + index);
}
