/*
        ID:atupal
        TASK:beads
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
#define NDEBUG
#include <cassert>


using namespace std;
int n;

int max(int x, int y){
        if(x > y) return x;
        return y;
}

int min(int x, int y){
        if(x > y) return y;
        return x;
}

int main(){
        assert(1 == 2);
        //freopen("beads.in", "r", stdin);
        //freopen("beads.out", "w", stdout);
        scanf("%d", &n);
        char set[n + 1];
        scanf("%s", set);
        int left[n];
        int right[n];
        for(int i = 0; i < n; ++ i) left[i] = right[i] = 0;
        
        char flag = 'a';
        for(int i = n - 1; i >= 0; -- i) {if(set[i] != 'w' && flag == 'a')flag = set[i]; if(flag != 'a' && set[i] != flag && set[i] != 'w')break; ++ left[n - 1];}
        for(int i = 0; i < n - 1; ++ i){
                if(set[i] == flag) left[i] = left[(i + n - 1) % n] + 1;
                else if(set[i] == 'w') left[i] = left[(i + n - 1) % n] + 1;
                else if(set[(i - 1 + n) % n] == 'w'){ left[i] = 2;flag = set[i];}
                else {left[i] = 1; flag = set[i];}
        }
        
        
        flag = 'a';
        for(int i = 0; i < n; ++ i){if(set[i] != 'w' && flag == 'a')flag = set[i]; if(flag != 'a' && set[i] != flag && set[i] != 'w')break; ++ right[0];}
        for(int i = n - 1; i > 0; -- i){
                if(set[i] == flag || set[i] == 'w') right[i] = right[(i + 1) % n] + 1;
                else if(set[(i - 1) % n] == 'w') {right[i] = 2; flag = set[i];}
                else {right[i] = 1; flag = set[i];}
        }
        int ans = 0;
        for(int i = 0; i < n; ++ i)
                ans = ::max(ans, left[i] + right[(i + 1) % n]);
        ans = min(ans, n);
        printf("%d\n", ans);
        cin >> n;
}
