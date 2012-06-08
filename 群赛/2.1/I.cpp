/*
	ID:atupal
	TASK:I
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

long ab(long x){
        if(x > 0) return x;
        return -x;
}

long gcd(long a, long b){
        return b == 0 ? a : gcd(b, a % b);
}


int main(){
        //freopen(".in", "r", stdin);
        //freopen(".out", "w", stdout);
	//cout.sync_with_stdio(0);
        long T;
        long c = 0;
        scanf("%d", &T);
        while(T --){
                ++ c;
                long ans = 0;
                long x1, y1, x2, y2, x, y;
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                y = ab(y1 - y2);
                x = ab(x1 - x2);
                if(x < y){
                        long tmp = x;
                        x = y;
                        y = tmp;
                }
                long t = gcd(x, y);
                if(t == y) {ans = y + 1; goto here;}
                if(t != 0)
               { y /= t;}
                if(x && y)
                ans = ab(y1 - y2) / y + 1;
                else if(x == 0 || y == 0) ans = ab(x1 - x2) + ab(y1 - y2) + 1;
                here:
                printf("Case %d: %d\n", c, ans);
        }
        cin >> T;
        //system("pause");
        return 0;
}
