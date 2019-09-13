//#pragma once
#ifndef _MY_POINT
#define _MY_POINT
#include <iostream>
class Point
{
public:
	float x = 0;
	float y = 0;

	Point() = default;
	Point(float x, float y) : x(x), y(y) {}
	Point(Point &obj)
	{
		x = obj.x;
		y = obj.y;
	}
	Point(Point &&obj)
	{
		x = std::move(obj.x);
		y = std::move(obj.y);
	}
	Point &operator=(Point &obj)
	{
		x = obj.x;
		y = obj.y;
	}
	friend std::ostream &operator<<(std::ostream &os, const Point &obj)
	{
		os << " x = " << obj.x << " y = " << obj.y;
		return os;
	}
};
#endif //_MY_POINT