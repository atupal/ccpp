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
#define a 2
#define b 10
#define n 10
using namespace std;

int main() {
        int re = 1;
        for(int i = 0; i < b; ++ i) {
                re = a * re % n;
        }
        cout << re << endl;
        
        system("pause");
        return 0;
}
