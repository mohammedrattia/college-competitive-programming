#include <iostream>
#include <iomanip>

#define PI		3.14159265358979323846

int main()
{
	double d, h, v, e;
	std::cin >> d >> h >> v >> e;

	double radias = d / 2;
	double area = radias * radias * PI;
	double rain = area * e;

	if (rain >= v)
		std::cout << "NO";
	else
	{
		std::cout << "YES\n";
		std::cout << std::setprecision(13) << (area * h)/(v - rain);
	}
}