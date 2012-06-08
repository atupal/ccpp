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

int modExp(int a, int b, int n){
        int t,y;
        t = 1;
        y = a;
        while(b){
                if(b % 2) t = t * y % n;
                y = y * y % n;
                b /= 2;
        6y}
        return t;
}

int main(){
        cout << modExp(3, 4, 10) << endl;
        system("pause");
        return 0;
}