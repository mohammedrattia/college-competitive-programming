#include <iostream>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;

	int l[2][2], r[2][2];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
				std::cin >> l[j][0] >> l[j][1] >> r[j][0] >> r[j][1];

		int def[4];
		def[0] = std::max(l[0][0], l[1][0]);
		def[1] = std::max(l[0][1], l[1][1]);
		def[2] = std::min(r[0][0], r[1][0]);
		def[3] = std::min(r[0][1], r[1][1]);

		if (i > 0)
			std::cout << "\n";

		if (def[0] < def[2] && def[1] < def[3])
			std::cout << def[0] << " " << def[1] << " " << def[2] << " " << def[3] << std::endl;
		else
			std::cout << "No Overlap" << std::endl;
	}

}