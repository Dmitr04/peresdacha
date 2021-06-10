#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define N 20
int main(){
    int a, b[N], t;
    for ( int i = 0; i < N; i++)
    b[i] = 1;
    cin >> a;
    t = a - 1;
    do {
        for ( int i = 0; i < a; i++){
            if ((i == a - 1) || (b[i+1] == 0)){
                cout << b[i] << endl;
                break;
            }
            else
            cout << b[i] << " ";
        }
        if ((b[t]-1 >= b[t-1]+1) && (t >= 1)){
        b[t]--;
        b[t-1]++;
        }
        else{
            b[t-1]+=b[t];
            b[t--]=0;
        }
    }
    while (b[0]!=0);
}