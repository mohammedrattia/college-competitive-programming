#include <iostream>
#include <string>

int main()
{
    std::string srt[3], t;
    std::cin >> srt[0] >> srt[1] >> srt[2] >> t;
    for (int i = 0; i < (int) t.size(); i++)
    {
        int idx = t[i] - '0' - 1;
        std::cout << srt[idx];
    }
    return 0;
}
