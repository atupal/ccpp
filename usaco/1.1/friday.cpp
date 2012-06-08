/*
        ID:atupal
        LANG:C++
        TASK:friday
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
#define BEGIN 1900
using namespace std;

int leap[400];
int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int lm[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void mleap(){
        for(int i = 0; i < 400; ++ i){
                int t = BEGIN + i;
                if(t % 100 == 0){
                        if(t % 400 == 0) leap[i] = 366;
                        else leap[i] = 365;
                }
                else if(t % 4 == 0) leap[i] = 366;
                else leap[i] = 365;
        }

}

int day(int y, int m){
        int re = 0;
        for(int i = 0; i < y; ++ i)
                re += leap[i];
        for(int i = 0; i < m; ++ i)
                if(leap[y] == 366) re += lm[i];
                else re += ::m[i];
        return re + 13;
}

int main(){
        freopen("friday.in", "r", stdin);
        freopen("friday.out", "w", stdout);
        int n;
        cin >> n;
        mleap();
        int re[7];
        for(int i = 0; i < 7; ++ i) re[i] = 0;
        for(int i = 0; i < n; ++ i){
                for(int j = 0; j < 12; ++ j)
                        ++ re[day(i, j) % 7];
        }
        
        cout << re[6] << ' ' << re[0];
        for(int i = 1; i <= 5; ++ i)
                cout << ' ' << re[i];
        cout << endl;
        return 0;
}