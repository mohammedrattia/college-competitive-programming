#include <iostream>
#include <utility>
#include <map>
#include <set>
#include <queue>

using namespace std;

int x[2], y[2];
map<pair<int, int>, int> len;
set<pair<int, int>> pnt;

int bfs()
{
    pair<int, int> e = make_pair(x[1], y[1]);
    queue<pair<int, int>> q;
    int drow[8] = {1, 0, -1, -1, -1, 0, 1, 1};
    int dcol[8] = {1, 1, 1, 0, -1, -1, -1, 0};
    int nodes = 0, dep = 0;

    q.push({x[0], y[0]});
    while (q.size())
    {
        dep++;
        nodes = q.size();
        while (nodes--)
        {
            pair<int, int> cur = q.front();
            q.pop();

            for (int i = 0; i < 8; i++)
            {
                int row = cur.first+drow[i];
                int col = cur.second+dcol[i];
                if (len.count({row, col}) == 0 && pnt.count({row, col}) != 0)
                {
                    q.push({row, col});
                    len[{row, col}] = dep;
                    if (make_pair(row, col) == e)
                        return len[{row, col}];
                }
            }
        }
    }
    return -1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie();
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int r, a, b;
        cin >> r >> a >> b;
        for (int j = a; j <= b; j++)
        {
            pnt.insert({r, j});
        }
    }

    cout << bfs() << endl;
}
