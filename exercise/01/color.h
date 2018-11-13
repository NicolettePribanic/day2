#pragma once
#include <windows.h>

class color {
public:
	color() : red{0}, green{0}, blue{0} {};
	color(double red, double green, double blue);
	color& operator=(const color& other);
	bool operator==(const color& other) const;
	double get_red() const;
	double get_green() const;
	double get_blue() const;
	void set_red(double red);
	void set_green(double green);
	void set_blue(double blue);
	COLORREF get_color_ref() const;
	double get_luminance() const;

private:
	double red;
	double green;
	double blue;
	const int maxColorRange = 255;
	const double redIntensity = 0.2126;
	const double greenIntensity = 0.7152;
	const double blueIntensity = 0.0722;
};