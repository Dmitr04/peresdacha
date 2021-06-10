#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream finn("input.txt");
    string b, c;
    int n = 0;
    int d = 0;
    finn >> b;
    int m = 1;
    int cu = 1;
    for ( int i = 1; i < b.size(); i++){
        if (b[i] != b[i-1]){
            cu ++;
            d = i;
            if ( cu > m){
                m = cu;
                c = b.substr(n, d - n + 1);
            }
        }
        if (b[i] == b[i - 1])
        {
            cu = 1;
            n = i;
        }
    }
    if ((d == 0) || (d == 1))
    cout << "0";
    else
    cout << c << ' ' << m;
}