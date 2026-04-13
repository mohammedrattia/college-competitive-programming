#include <iostream>
#include <vector>

int main()
{
	int n;
	while (std::cin >> n && n != 0)
	{
		std::vector<int> d(n), c(n);
		int m, y;

		int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		int i = 0;
		while (i < n)
		{
			std::cin >> d[i] >> m >> y >> c[i];
			d[i] += (y - 1900) * 365 + (y - 1900) / 4;
			if (y % 4 == 0 && m < 3)
				d[i]--;
			for (int j = 0; j < m - 1; j++)
				d[i] += months[j];
			i++;
		}

		int cnt = 0, sum = 0;
		for (int j = 1; j < n; j++)
		{
			if (d[j] - d[j - 1] == 1)
			{
				cnt++;
				sum += c[j] - c[j - 1];
			}
		}

		std::cout << cnt << " " << sum << std::endl;
	}
}