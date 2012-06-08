/*
        LANG: C++
        TASK:ride
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
        freopen("ride.out", "w", stdout);
        freopen("ride.in","r", stdin);
        char a[50];
        char b[50];
        while(cin >> a >> b){
                long m = 1;
                long n = 1;
                for(int i = 0; i < strlen(a); ++ i)
                        m *= a[i] - 'A' + 1;
                for(int i = 0; i < strlen(b); ++ i)
                        n *= b[i] - 'A' + 1;
                if(m % 47 == n % 47) cout << "GO" << endl;
                else cout << "STAY" << endl;
        }
        fclose(stdin);
        fclose(stdout);
        return 0;
}