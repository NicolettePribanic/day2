#pragma once

class point
{
public:
	point() : x(0), y(0) {};
	point(int x, int y) : x(x), y(y) {};
	point(const point& other) = default;
	point(point&& other) = default;
	point& operator=(const point& other) = default;
	point& operator=(point&& other) = default;
	~point() = default;
	bool operator==(const point& other) const;
	bool operator!=(const point& other) const;
	bool operator<(const point& other) const;

private:
	int x, y;
};