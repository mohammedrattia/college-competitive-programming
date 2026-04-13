#include <iostream>

char grid[10][10];
int n, m;
const char* path = "@IEHOVA#";

bool valid(int r, int c)
{
	return r >= 0 && c >= 0 && r < n && c < m;
}

void mov(int r, int c, int i = 0)
{
	if (path[i] == '#')
		return;
	if (i > 0)
		std::cout << " ";
	if (valid(r - 1, c) && grid[r - 1][c] == path[i + 1])
	{
		std::cout << "forth";
		mov(r - 1, c, i + 1);
	}
	if (valid(r, c + 1) && grid[r][c + 1] == path[i + 1])
	{
		std::cout << "right";
		mov(r, c + 1, i + 1);
	}
	if (valid(r, c - 1) && grid[r][c - 1] == path[i + 1])
	{
		std::cout << "left";
		mov(r, c - 1, i + 1);
	}
}

int main()
{
	int t;
	std::cin >> t;
	while (t--)
	{
		std::cin >> n >> m;
		int x, y;
		for (int i = 0; i < n; i++)
		{
			std::cin >> grid[i];
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == path[0])
				{
					x = j, y = i;
				}
			}
		}

		mov(y, x);
		std::cout << std::endl;
	}
}
00000
00000
00000
00000
00000
