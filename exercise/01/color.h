#pragma once
#include <windows.h>

class color {
public:
	color() : red{0}, green{0}, blue{0} {};
	color(double red, double green, double blue) : red{red}, green{green}, blue{blue} {};
	bool operator==(const color& other) const;
	double get_red() const;
	double get_green() const;
	double get_blue() const;
	double set_red(double red);
	double set_green(double green);
	double set_blue(double blue);
	COLORREF get_color_ref() const;
	double get_luminance() const;

private:
	double red;
	double green;
	double blue;
};