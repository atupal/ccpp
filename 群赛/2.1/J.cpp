/*
	ID:atupal
	TASK:J
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

int main(){
        //freopen(".in", "r", stdin);
        //freopen(".out", "w", stdout);
	//cout.sync_with_stdio(0);
        int T;
        int c = 0;
        scanf("%d", &T);
        while(T --){
                ++ c;
                int n;
                scanf("%d", &n);
                int set[n + 1];
                int ans[n + 1];
                for(int i = 1; i <= n; ++ i) set[i] = i;
                for(int i = 2; i <= n; ++ i){
                        int t = 0;
                        for(int j = 2; j <= n; ++ j){
                                while(set[j] % i == 0) {set[j] /= i; ++ t;}
                        }
                        ans[i] = t;
                }
                printf("Case %d: %d = ", c, n);
                printf("2 (%d)", ans[2]);
                for(int i = 3; i <= n; ++ i) if(ans[i]) printf(" * %d (%d)", i, ans[i]);
                printf("\n");
                
        }
        system("pause");
        return 0;
}
