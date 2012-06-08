/*
        ID:atupal
        TASK:H
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
#include <cstring>64453
#include <cmath>
#include <ctime>
using namespace std;

int n, m;
int momo[103][103];
int ans = 0;
int re = 0;
void dfs(int i, int j, int set[103][103]){
        int flag = 0;
        if(i - 1 > -1 )if( set[i - 1][j] < set[i][j])if(momo[i - 1][j]){ans = ans > re + momo[i - 1][j] ? ans : re + momo[i - 1][j];}else {flag = 1;++ re;  dfs(i - 1, j, set); --re;}
        if(j - 1 > -1 )if( set[i][j - 1] < set[i][j])if(momo[i][j - 1]){ans = ans > re + momo[i][j - 1] ? ans : re + momo[i][j - 1];} else{flag = 1;++ re;  dfs(i, j - 1, set); --re;}
        if(i + 1 < n )if( set[i + 1][j] < set[i][j]){if(momo[i + 1][j]){ans = ans > re + momo[i + 1][j] ? ans : re + momo[i + 1][j];}else {flag = 1;++ re;  dfs(i + 1, j, set); --re;}}
        if(j + 1 < m )if( set[i][j + 1] < set[i][j]){if(momo[i][j + 1]){ans = ans > re + momo[i][j + 1] ? ans : re + momo[i][j + 1];}else {flag = 1;++ re;  dfs(i, j + 1, set); --re;}}
        ans = ans > re ? ans : re;
}

int main(){
        int set[103][103];int ans1 = 0;
        cin >> n >> m;
        for(int i = 0; i < n; ++ i)
        for(int j = 0; j < m; ++ j){cin >> set[i][j];momo[i][j] = 0;}
        for(int i = 0; i < n; ++ i)
        
        for(int j = 0; j < m; ++ j){ans = 0;dfs(i, j, set);momo[i][j] = ans + 1;ans1 = ans > ans1?ans:ans1;}
        cout << ans1 + 1 << endl;
        //system("pause");
        return 0;
}
