/*
	ID:atupal
	TASK:milk2
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

int max(int x, int y){
        if(x > y) return x;
        return y;
}

int min(int x, int y){
       return x < y ? x : y;
}
int set[2000001];
int main(){
        //freopen("milk2.in", "r", stdin);
        //freopen("milk2.out", "w", stdout);
        //cout.sync_with_stdio(0);
        int n;
        scanf("%d", &n);
        int max1 = 0;
        int max2 = 0;
        
        memset(::set, 0, sizeof(::set));
        int a;
        int b;
        int start = 2000001;
        int end = 0;
        while(n --){
                scanf("%d%d", &a, &b);
                ::set[a] += 1;
                ::set[b] += -1;
                start = min(start, a);
                end = max(end, b);
        }
        int t = 0;
        int s = start;
        int e = 0;
        int m = 0;
        for(int i = start; i < end; ++ i){

                t += ::set[i];
                if(t) {++ e; m = 0; }
                else {++ m; e = 0;}
                max1 = max(max1, e);
                max2 = max(max2, m);
        }
        printf("%d %d\n", max1, max2);
        cin >> n;
        return 0;
}
