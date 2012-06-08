/*
        ID:atupal
        TASK:A
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

void swap(int & a, int & b){
        int t = a;
        a = b;
        b = t;
}
vector <int> re;
int is(int t){
        for(int i = 0; i < re.size(); ++ i)
                if(re[i] ==  t)return 1;
        return 0;
}



void p(int set[], int i){
        if(i > 3) {int t = set[0] * 1000 + set[1] * 100 + set[2] * 10 + set[3]; if(!is(t) && t >= 1000)re.push_back(t);}
        else{
                for(int j = i; j < 4; ++ j){
                        swap(set[i], set[j]);
                        p(set, i + 1);
                        swap(set[i], set[j]);
                }
        }
}

int main(){
        int set[4];
        cin >> set[0] >> set[1] >> set[2] >> set[3];
        while(set[0] || set[1] || set[2] || set[3]){
                //cout << set[0] << set[1] << set[2] << set[3] << endl;

                p(set, 0);
                sort(re.begin(), re.end());
                int c = 0;

                        for(int j = 0; j < re.size(); ++ j){

                                if(j > 0 && ((re[j - 1] / 1000) != (re[j] / 1000)))cout<< endl << re[j] ;
else if(j > 0)                               cout << " "<< re[j] ;else cout << re[j];
                        }cin >> set[0] >> set[1] >> set[2] >> set[3];

                        if(set[0] || set[1] || set[2] || set[3])cout << endl << endl;else cout << endl;
                re.clear();

        }
        return 0;
}