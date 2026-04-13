#include <iostream>
#include <cmath>

using namespace std;

int n, k;
int code_num (int num)
{
    int i = 0, sum = 0;
    while (num >= pow(k, i)) sum += num/pow(k, i++);
    return sum;
}

int b_search (int start, int endn)
{
    while (start < endn)
    {
        int mid = (start + endn)/2;
        if (code_num (mid) < n) start = mid + 1;
        else if (code_num (mid) > n) endn = mid;
        else return mid;
    }
    return start;
}

int main()
{
    cin >> n >> k;
    cout << b_search(1, n);
}
