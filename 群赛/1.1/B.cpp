/*
        ID:atupal
        TASK:B
        LANG:C++
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

long long x1, x2;

void gcd(long long x, long long y){
        if(x < y){
                long long t = x;
                x = y;
                y = t;
        }
        if(y == 0){
                cout << x2 / x << "/" << x1 / x << endl;
        }else
        gcd(y, x % y);
}

void hua(long long a, long long b, int l1, int l2){
        long long x = a * ((long long)pow(10.0, l2) - 1) + b;
        long long y = ((long long)pow(10.0,l2) - 1) * (long long)pow(10.0, l1);
        x1 = y;
        x2 = x;
        if(b == 0){x2 = a; x1 = (long long)pow(10.0, l1);gcd(x1,x2);}
        else gcd(x, y);
}

int main(){
        int n;
        cin >> n;
        char set[20];
        while(n --){
                int dot = 0;
                int k = 0;
                char t;
                long long a = 0 , b = 0;
                int l1 = 0, l2 = 0;
                cin >> set;
                for(int i = 0; ; ++ i){
                        if(set[i] == '\0' || set[i] == ')')break;
                        if(set[i] == '.' && !dot) {dot = 1;continue;}
                        if(set[i] == '(' && !k) {k = 1;continue;}
                        if(dot && (!k)){a = a * 10 + (set[i] - '0');++ l1;}
                        if(k){b = b * 10 + (set[i] - '0');++l2;}
                }
                hua(a,b,l1,l2);
                
        }
        return 0;
}



