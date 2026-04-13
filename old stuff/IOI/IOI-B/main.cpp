#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << "." << endl;
        }
        else if (n == 2)
        {
            cout << ".." << endl;
            cout << ".." << endl;
        }
        else if (n == 3)
        {
            cout << "X.." << endl;
            cout << "..O" << endl;
            cout << ".O." << endl;
        }
        else if (n == 4)
        {
            cout << "X..." << endl;
            cout << "..O." << endl;
            cout << ".O.." << endl;
            cout << "...X" << endl;
        }
        else if (n == 5)
        {
            cout << "X...X" << endl;
            cout << "..O.." << endl;
            cout << ".O.O." << endl;
            cout << "..O.." << endl;
            cout << "X...X" << endl;
        }
        else if (n == 6)
        {
            cout << "XXX..." << endl;
            cout << "....OO" << endl;
            cout << ".....O" << endl;
            cout << "XX...." << endl;
            cout << "...O.." << endl;
            cout << "....O." << endl;
        }
        else if (n == 7)
        {
            cout << "XXX...." << endl;
            cout << "......O" << endl;
            cout << ".....OO" << endl;
            cout << "......O" << endl;
            cout << "XXX...." << endl;
            cout << "....O.." << endl;
            cout << ".....O." << endl;
        }
        else if (n == 8)
        {
            cout << "XXX....." << endl;
            cout << "......OO" << endl;
            cout << ".....OOO" << endl;
            cout << "......OO" << endl;
            cout << "XXX....O" << endl;
            cout << "XX......" << endl;
            cout << ".....O.." << endl;
            cout << "......O." << endl;
        }
        else if (n == 9)
        {
            cout << "XXXX....." << endl;
            cout << ".......OO" << endl;
            cout << "......OOO" << endl;
            cout << ".......OO" << endl;
            cout << "........O" << endl;
            cout << "XXX......" << endl;
            cout << "XX......." << endl;
            cout << ".....OO.." << endl;
            cout << "......OO." << endl;
        }
        else if (n == 10)
        {
            cout << "XXXXX....." << endl;
            cout << "........OO" << endl;
            cout << ".......OOO" << endl;
            cout << ".......OOO" << endl;
            cout << "........OO" << endl;
            cout << "XXXX......" << endl;
            cout << "XXX......." << endl;
            cout << "......O..." << endl;
            cout << ".......O.." << endl;
            cout << "........O." << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int i = 0; i < n; i++)
                {
                    cout << ".";
                }
                cout << endl;
            }
        }
    }
}
