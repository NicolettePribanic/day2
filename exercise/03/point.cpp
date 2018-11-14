#include "point.h"

bool point::operator==(const point & other) const
{
	return x == other.x && y == other.y;
}

bool point::operator!=(const point & other) const
{
	return !((*this)==other);
}

bool point::operator<(const point & other) const
{
	return x <= other.x && y < other.y || x < other.x && y <= other.y;
}
