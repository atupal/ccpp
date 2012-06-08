/*
        ID:atupal
        TASK:D
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

vector<int>ans;

int main(){
        int N;
        cin >> N;
        while(N){
                ans.clear();
                int n = N;
                int k = 0;
                while(n){
                        int c = N / (int) pow(10.0, k) / 11;
                        int b = N / (int) pow(10.0, k) % 11;
                        int a = (N - b * (int) pow(10.0, k) - c * (int) pow(10.0, k) * 11) / 2;
                        if(a * 2 +  b * (int) pow(10.0, k) + c * (int) pow(10.0, k) * 11 == N && b < 10 && (b != 0 || c != 0)) ans.push_back(a +  b * (int) pow(10.0, k) + c * (int) pow(10.0, k + 1));
                        b --;
                        a = (N - b * (int) pow(10.0, k) - c * (int) pow(10.0, k) * 11) / 2;
                        if(a * 2 +  b * (int) pow(10.0, k) + c * (int) pow(10.0, k) * 11 == N && b > -1 && (b != 0 || c != 0)) ans.push_back(a +  b * (int) pow(10.0, k) + c * (int) pow(10.0, k + 1));
                        ++ k;
                        n /= 10;
                }
                sort(ans.begin(), ans.end());
                if(ans.size() == 0) cout << "No solution.";
                else cout << ans[0];
                for(int i = 1; i < ans.size(); ++ i) if(ans[i] != ans[i - 1] && ans[i] != ans[ans.size() - 1]) cout << " " << ans[i];
                if(ans.size() > 0 && ans[0] != ans[ans.size() - 1])cout << " " << ans[ans.size() - 1];
                cin >> N;
                if(N)cout << endl;
        }
        return 0;
}



