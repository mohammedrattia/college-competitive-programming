#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
	int n, k, a[100][2];
	std::cin >> n >> k;
	for (int i = 0; i < n; i++)
		std::cin >> a[i][0] >> a[i][1];
	double distance = 0.0;
	for (int i = 0; i < n - 1; i++)
	{
		double powx = pow(a[i + 1][0] - a[i][0], 2);
		double powy = pow(a[i + 1][1] - a[i][1], 2);
		distance += sqrt(powx + powy);
	}
	double time = distance * k / 50;
	std::cout << std::fixed << std::setprecision(9) << time;
}