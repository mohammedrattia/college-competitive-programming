#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr;
    char c;
    while (c != '\n')
    {
        scanf("%c", &c);
        if (c != '\n')
            arr.push_back((int)(c - '0'));
    }

    for (int j = 0; j < arr.size(); j++)
    {
        cout << arr[j];
    }
    for (int j = arr.size() - 1; j >= 0; j--)
    {
        cout << arr[j];
    }
}
