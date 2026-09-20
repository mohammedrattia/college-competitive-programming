#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> A)
{
    int n = A.size();
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {
        bool b = false;
        for (int j = 0; j < (int)arr.size(); j++)
        {
            if (A[i] < *arr[j].rbegin())
            {
                arr[j].push_back(A[i]);
                b = true;
            }
        }
        if (!b)
        {
            arr.push_back(vector<int>());
            (*arr.rbegin()).push_back(A[i]);
        }
    }
    return arr.size();
}

vector<int> toIntVector(string str)
{
    std::vector<int> out;
    std::string i;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, i, ','))
    {
        out.push_back(atoi(i.c_str()));
    }
    return out;
}

int main()
{
    // Read in from stdin, solve the problem, and write answer to stdout.
    string AS;
    cin >> AS;
    vector<int> A = toIntVector(AS);
    cout << solution(A);
}
