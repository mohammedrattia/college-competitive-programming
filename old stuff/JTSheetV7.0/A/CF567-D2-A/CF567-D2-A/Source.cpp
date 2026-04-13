#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	long long n;
	std::cin >> n;
	std::vector<long long> x(n);
	long long min = 0, max = 0;
	x.reserve(n);
	for (auto &e : x)
		std::cin >> e;
	for (int i = 0; i < n; i++)
	{
		max = std::max(x[i] - x[0], x[n - 1] - x[i]);
		if (i == 0)
			min = x[i + 1] - x[i];
		else if (i == n - 1)
			min = x[i] - x[i - 1];
		else
			min = std::min(x[i] - x[i - 1], x[i + 1] - x[i]);
		std::cout << min << " " << max << std::endl;
	}
}