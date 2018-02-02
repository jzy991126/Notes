#pragma once

#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <math.h>

struct zb2 {
	int x, y;
	zb2(int X = 0, int Y = 0):x(X),y(Y) {}

	bool operator ==(const zb2 &a) const
	{
		return x == a.x&&y == a.y;
	}

	bool operator <(const zb2 &a) const
	{
		if (x == a.x)
			return y < a.y;
		return x < a.x;
	}

	zb2 operator +(const zb2 &a) const
	{
		return zb2(x + a.x, y + a.y);
	}
};

inline int manhattan_dist(const zb2 &a, const zb2 &b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

inline double euclid_dist(const zb2 &a, const zb2 &b) {
	return sqrt((a.x - b.x)*(a.x-b.x) + (a.y - b.y)*(a.y - b.y));
}

#endif // !STRUCTURES_H
