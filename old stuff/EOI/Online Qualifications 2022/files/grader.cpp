#include "bits/stdc++.h"
#include "xorarray.h"

namespace{
    int __n;
    int __qs;
    std::vector <long long> __a;
    void error_if(bool cond ,std::string message){
        if(cond){
            printf("%s\n",message.c_str());
            exit(0);
        }
    }
}

long long use_machine(long long x)
{
    error_if((x < 0) || (x >= (1LL<<50)) ,"WA: x must be a non-negative integer less than 2^50");
    __qs++;
    long long ret = 0;
    for(long long&i : __a)
        ret += i^x;
    return ret;
}

int main()
{
    scanf("%d",&__n);
    __a.resize(__n);
    for(long long&i : __a)
        scanf("%lld",&i);

    long long px = guess_xor(__n);
    long long jx = 0;
    for(long long&i : __a)
        jx ^= i;

    error_if(px != jx ,"WA: guessed xor is incorrect");
    printf("OK: %d\n",__qs);
}
