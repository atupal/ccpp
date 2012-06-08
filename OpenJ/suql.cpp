/*
        ID:atupal
        TASK:square
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
        int n;
        scanf("%d", &n);
        while(n --){
                int m;
                scanf("%d", &m);
                int set[m];
                int sum = 0;
                for(int i = 0; i < m; ++ i) scanf("%d", &set[i]);
                for(int i = 0; i < m; ++ i) sum += set[i];
                if(sum % 4) {printf("no"); continue;}
                int v = sum / 4;
                for(int i = 0; i < 4; ++ i){
                        int t = 0;
                        for(int j = 0; j < m; ++ j) {if(t + set[i] <= v) {t += set[i];set[i] = 0;}}
                }
                for(int i = 0; i < m; ++ i) if(set[i]) {printf("no"); goto here;}
                printf("yes");
                here:;
        }
        system("pause");
        return 0;
}

