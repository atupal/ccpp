/*
        ID:atupal
        TASK:C
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

double x, y, l, w;

double h(double angle){
        double s = (double )l * cos(angle) + (double) w * sin(angle) - (double) x;
        double h = s * tan(angle) + w * cos(angle);
        return h;
}

double max(double x, double y){
        if(x > y) return x;
        return y;
}

int main(){
        while(cin >> x >> y >> l >> w){
        double left = 0.0;
        double right = acos(-1.0) / 2;
        double ans = 0;
        for(int i = 0; i < 100; ++ i){
                double mid = left + (right - left) / 3;
                double midmid = right - (right - left) / 3;
                double m1 = h(mid);
                double m2 = h(midmid);
                ans = max(m1, ans);
                ans = max(m2, ans);
                if(m1 < m2) left = mid;
                else right = midmid;
        }
        if(ans > y) cout << "no" << endl;
        else cout << "yes" << endl;
        }
        return 0;
}
