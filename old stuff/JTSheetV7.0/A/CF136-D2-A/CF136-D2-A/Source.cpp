#include <iostream>
#include <vector>

int main()
{
	int n, p;
	std::cin >> n;
	std::vector<int> ans(n);
	ans.reserve(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> p;
		ans[p - 1] = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << ans[i] << " ";
	}
}