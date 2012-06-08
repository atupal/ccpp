#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(){
        double a = 1.0;
        int ans = 0;
        cin >> a;
        while(a != 0.00){
                
                ans = 0;
                double sum = 0;
                while(1){
                        ++ ans;
                        sum += 1.0 / (ans+1);
                        if(sum > a) break;
                }
                cout << ans << " card(s)" << endl;
                cin >> a;
        }
        return 0;
}