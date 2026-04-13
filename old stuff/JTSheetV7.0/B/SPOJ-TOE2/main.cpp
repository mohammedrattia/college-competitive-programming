#include <iostream>
#include <queue>
#include <string>

using namespace std;

bool win(string &cur)
{
    bool sols = (cur[1 - 1] != '.' && cur[1 - 1] == cur[2 - 1] && cur[2 - 1] == cur[3 - 1])||
                (cur[4 - 1] != '.' && cur[4 - 1] == cur[5 - 1] && cur[5 - 1] == cur[6 - 1])||
                (cur[7 - 1] != '.' && cur[7 - 1] == cur[8 - 1] && cur[8 - 1] == cur[9 - 1])||
                (cur[1 - 1] != '.' && cur[1 - 1] == cur[4 - 1] && cur[4 - 1] == cur[7 - 1])||
                (cur[2 - 1] != '.' && cur[2 - 1] == cur[5 - 1] && cur[5 - 1] == cur[8 - 1])||
                (cur[3 - 1] != '.' && cur[3 - 1] == cur[6 - 1] && cur[6 - 1] == cur[9 - 1])||
                (cur[1 - 1] != '.' && cur[1 - 1] == cur[5 - 1] && cur[5 - 1] == cur[9 - 1])||
                (cur[7 - 1] != '.' && cur[7 - 1] == cur[5 - 1] && cur[5 - 1] == cur[3 - 1]);
    return sols;
}

string bfs(queue<pair<string, bool>> &q, string &board)
{
    while (q.size())
    {
        string cur = q.front().first;
        bool player = q.front().second;
        q.pop();
        if (cur == board && (win(cur) || cur.find('.') == std::string::npos))
        {
            return "valid";
        }
        if (win(cur))
        {
            continue;
        }
        for (int i = 0; i < 9; i++)
        {
            if (cur[i] == '.')
            {
                cur[i] = (player ? 'X' : 'O');
                if (cur[i] == board[i])
                    q.push({cur, !player});
                cur[i] = '.';
            }
        }
    }
    return "invalid";
}

void solve(string &str)
{
    string start = ".........";

    queue<pair<string, bool>> q;
    q.push({start, 1});

    cout << bfs(q, str) << endl;
}

int main()
{
    string str;
    cin >> str;
    while (str != "end")
    {
        solve(str);
        cin >> str;

    }
}
