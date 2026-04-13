#include <iostream>
#include <vector>

std::vector<int> vis;
std::vector<int> a;
long long n, x;
long long max_sum;

void dfs(int node, int sum, int num = n)
{
    if (((sum + num) / x * x) > (sum - num) && ((sum + num) / x * x) > max_sum)
    {
        max_sum = sum + num;
        return;
    }
    if (vis[node])
        return;
    vis[node] = 1;
    for (int i = 0; i < n; i++)
    {
        int child = a[i];
        if (!vis[child])
            dfs(child, sum - node, num - 1);
    }
}

int main()
{
    long long t;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n >> x;
        vis.clear();
        a.clear();
        a = std::vector<int>(n,0);
        vis = std::vector<int>(n,0);
        int sum = 0;
        max_sum = 0;

        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
            sum += a[i];
        }

        if (x > sum + n)
            std::cout << 0 << std::endl;
        else if (((sum + n) / x * x) < (sum - n))
        {
            for (int i = 0; i < n; i++)
            {
                dfs(i, sum);
                vis.clear();
                vis = std::vector<int>(n,0);
            }
            std::cout << (max_sum / x * x) << std::endl;
        }
        else
        {
            long long remain = (sum + n) % x;
            std::cout << (sum + n) - remain << std::endl;
        }
    }
}
