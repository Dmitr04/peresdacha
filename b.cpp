#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c, d, x, t=0;
    cin >> a >> b;
    for ( int i = a; i <= b; i++){
        d = i;
        while (d % 2 == 0){
            d = d / 2;
        }
        x = sqrt(d);
        if ( x * x == d){
          for ( int j = 3; j < sqrt(d)-1; j++){
              if(d % j == 0){
                  c++;
              }
          }  
            if (c==1){
                cout << i << endl;
                t++;
            }
            c = 0;
        }
    }
    if (t==0)
    cout << t;
}