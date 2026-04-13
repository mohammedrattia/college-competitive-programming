#include <iostream>

int main()
{
	double rec[10][4];
	int n = 0;
	char c;
	while (std::cin >> c && c == 'r')
	{
		std::cin >> rec[n][0] >> rec[n][1] >> rec[n][2] >> rec[n][3];
		n++;
	}
	double x, y;
	int point = 1;
	bool start = 1;
	while (std::cin >> x >> y && x != 9999.9 && y != 9999.9)
	{
		bool contained = false;
		for (int i = 0; i <= n; i++)
		{
			if (x > rec[i][0] && x < rec[i][2] && y < rec[i][1] && y > rec[i][3])
			{
				std::cout << "Point " << point << " is contained in figure " << i + 1 << std::endl;
				contained = true;
			}
		}
		if (!contained)
		{
			std::cout << "Point " << point << " is not contained in any figure" << std::endl;
		}
		point++;
	}
}