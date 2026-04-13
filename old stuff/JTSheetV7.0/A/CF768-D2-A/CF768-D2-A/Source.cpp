#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	a.reserve(n);
	for (auto &e : a)
		std::cin >> e;

	std::sort(a.begin(), a.end());

	int cnt_min = 0, cnt_max = 0;
	bool find_min = 0, find_max = 0;

	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] < a[i + 1] && find_min == 0)
		{
			find_min = 1;
			cnt_min = i + 1;
		}
		if (a[n - i - 1] > a[n - i - 2] && find_max == 0)
		{
			find_max = 1;
			cnt_max = i + 1;
		}
		if (find_min == 1 && find_max == 1)
			break;
	}

	if (cnt_min + cnt_max == n || cnt_min + cnt_max == 0)
		std::cout << 0;
	else
		std::cout << n - (cnt_min + cnt_max);
}