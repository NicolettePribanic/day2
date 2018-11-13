#include "stdafx.h"
#include "color.h"

color::color(double red, double green, double blue)
{
	set_red(red);
	set_green(green);
	set_blue(blue);
}

color & color::operator=(const color & other)
{
	if (this != &other) {
		red = other.red;
		green = other.green;
		blue = other.blue;
	}
	return *this;
}

bool color::operator==(const color & other) const
{
	return this->red == other.red && this->green == other.green && this->blue == other.blue;
}

double color::get_red() const
{
	return red;
}

double color::get_green() const
{
	return green;
}

double color::get_blue() const
{
	return blue;
}

namespace {

	double convert(double col)
	{
		if (col < 0) return 0;
		if (col > 1) return 1;
		return col;
	}
}

void color::set_red(double red)
{
	this->red = convert(red);
}

void color::set_green(double green)
{
	this->green = convert(green);
}

void color::set_blue(double blue)
{
	this->blue = convert(blue);
}

COLORREF color::get_color_ref() const
{
	return RGB(red * maxColorRange, green * maxColorRange, blue * maxColorRange);
}

double color::get_luminance() const
{
	return red * redIntensity + green * greenIntensity + blue * blueIntensity;
}
