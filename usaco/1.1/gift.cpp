/*
        ID:atupal
        TASK:gift1
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
void Debug () {
    #if 1
    freopen ( "gift1.in", "r", stdin );
    freopen ( "gift1.out", "w", stdout );
    #endif
}
int N, mon, cnt, t;
string name;
int main ()
{
    Debug ();
    cin >> N;
    vector < string > nm ( N );
    map < string, int > rec, sen;
    for ( int i = 0; i < N; ++ i ) cin >> nm[i];
    for ( int i = 0; i < N; ++ i ) {
        cin >> name >> mon >> cnt;
        if ( t = cnt ) sen[name] +=  mon / cnt * cnt;
        while ( t -- ) {
              cin >> name;
              rec[name] += mon / cnt;
        }
    }
    for ( int i = 0; i < nm.size(); ++ i ) {
        cout << nm[i] << " " << rec[nm[i]] - sen[nm[i]] << endl;
    }
    return 0;
}


