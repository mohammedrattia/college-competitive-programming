#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> snacks(n);
	snacks.reserve(n);
	for (auto &e : snacks)
		std::cin >> e;

	int j = n;
	std::vector<bool> dropped(n, 0);
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		dropped[snacks[i] - 1] = 1;
		if (snacks[i] == j)
		{
			int k = j;
			while ( k > 0 && dropped[k - 1] == 1)
			{
				std::cout << k << " ";
				cnt++;
				k--;
			}
			j -= cnt;
		}
		std::cout << "\n";
	}
}