#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c, n, maxn, sum;
    cin >> a >> b;
    sum = 0;
    maxn = a;
    for (int i = a; i <= b; i++)
    {
        if (i % 2 != 1)
        continue;
        c = abs(i);
        n = 0;
        while (c != 0){
            if(c % 2 == 0)
            n = n + 1;
            c = c / 2;
        }
        if (n != 5)
        continue;
        if (i % 3 != 0)
        continue;
        if (i % 11 != 0)
        continue;
        sum += 1;
        maxn = max(maxn,i);
    }
    if (sum != 0 ){
        cout << sum << ' ' << maxn;
    }
    else{
        cout << sum << " 0 ";
    }
}
