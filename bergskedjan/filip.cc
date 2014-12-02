#include <cmath>
#include <vector>
#include <iostream>
#include <map>
#include <iterator>

using namespace std;


typedef struct point{
	double x;
	double y;
} point;

typedef map<double, point> mip;


inline point newPoint(double x, double y)
{
	point tmp;
	tmp.x = x;
	tmp.y = y;
	return tmp;
}

inline double dist(double a, double b)
{
	return abs(a-b);
}

inline double distX(point a, point b)
{
	return abs(a.x-b.x); 
}

inline double distY(point a, point b)
{
	return abs(a.y-b.y);
}

double k(point a, point b)
{
	return (b.y-a.y)/(b.x-a.x);
}

inline point split(point a, point b)
{
	double delta = dist(a.x-a.y, b.x-b.y)/2;
	
	if(a.y - delta < 0)
	{
		if(a.y != 0)
			return newPoint(a.x + a.y, 0);
		else
			return newPoint(b.x - b.y, 0);
	} else
		return newPoint(a.x + delta, a.y - delta);
}

inline void addPoints(mip& p, double x, double y)
{
	if(!(p[x-y].y > 0))
		p[x-y] = newPoint(x-y, 0);
	if(!(p[x+y].y > 0))
		p[x+y] = newPoint(x+y, 0);
	if(!(p[x].y > y))
		p[x] = newPoint(x, y);
	
}

int main(void)
{
	int N;
	cin >> N;

	mip points;
	mip::iterator it;
	double totArea = 0;

	double X, Y;
	for(int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		addPoints(points, X, Y);
	}

	it = points.begin();
	while(next(it, 1) != points.end())
	{
		if(k(it->second, next(it,1)->second) == 0 && (it->second).y == 0)
		{
			if(k(next(it,1)->second, next(it,2)->second) == 0)
			{
				points.erase(next(it,1));
				continue;
			} 
			it++;
			continue;
		}
		if(abs(k(it->second, next(it,1)->second)) < 1)
		{
			point t = split(it->second, next(it,1)->second);
			points[t.x] = t;
			continue;
		}
		if(k(it->second, next(it,1)->second) < -1)
		{
			points.erase(next(it,1));
			continue;
		}
		if(k(it->second, (next(it,1)->second)) > 1)
		{	
			it--;
			points.erase(next(it,1));
			continue;
		}
		it++;
	}

	it = points.begin();
	while(next(it,1) != points.end())
	{
		//cout << (it->second).x << " " << (it->second).y << endl;
		totArea += distX(it->second, next(it,1)->second) * min((it->second).y, (next(it,1)->second).y);
		totArea += distX(it->second, next(it,1)->second) * distY(it->second, next(it,1)->second)/2;
		it++;
	}

	cout << fixed << totArea << endl;
	return 0;
}
