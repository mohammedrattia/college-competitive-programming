// NOTE: it is recommended to use this even if you don't understand the
// following code.

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, C;
    cin >> N >> C;
    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    // insert your code here
    vector<int> arr(N, 0);
    int a = 2000005, cnt = 0;
    bool b = 1;
    for (int i = 0; i < N; i++)
    {
        if (i != 0 && L[i] != L[i-1])
        {
            if (b)
                b = 0;
            else
                a = min(a, cnt);
            cnt = 0;
        }
        cnt++;
    }
    cout << a+2 << endl;  // print the result
    return 0;
}
