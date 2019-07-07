#include"head.h"

int collision(rect r1, rect r2)
{
	int d = 1;
	if (r1.x < r2.x && r1.x + r1.w > r2.x)
	{
		if (r1.y > r2.y && r1.y < r2.y + r2.h)
			return d;
		if (r1.y < r2.y && r1.y + r1.h > r2.y)
			return d;
	}
	else {
		if (r1.x > r2.x && r2.x + r2.w > r1.x)
		{
			if (r1.y > r2.y && r1.y < r2.y + r2.h)
				return d;
			if (r1.y < r2.y && r1.y + r1.h > r2.y)
				return d;
		}
	}
	d = 0;
	return d;
}


