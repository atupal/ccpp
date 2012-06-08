#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class EllysThreeRivers {
public:
	int l;
	int w;
	vector <int> wi;
	vector <int>  s;
	double triSlipe(double length, int i){
		if(i >= 3) return length / w;
		double re = 100000000;
		int n = 10;
		double left = 0.0;
		double right = length;
		while(n --){
		double mid = left + (right - left) / 3.0;
		double midmid = right - (right - left) / 3.0;
		double m1 = sqrt((mid ) * (mid) + wi[i] * wi[i]) / s[i] + triSlipe(length - mid, i + 1);
		double m2 = sqrt((midmid ) * (midmid ) + wi[i] * wi[i]) / s[i] + triSlipe(length - midmid, i + 1);
                re = re < m1 ? re : m1;
                re = re < m2 ? re : m2;
		if(m1 > m2)
			left = mid;
		else right = midmid;
		}
		return re;
	}

	double getMin(int length, int walk, vector <int> width, vector <int> swim) {
		l = length;
		w = walk;
		wi = width;
		s = swim;

		return triSlipe(length, 0);
	}
};
int main(){
        EllysThreeRivers a;
        int l = 10;
        int w = 8;
        vector <int> wi;
        wi.push_back(5);
        wi.push_back(2);
        wi.push_back(3);
        vector <int> s;
        s.push_back(5);
        s.push_back(2);
        s.push_back(7);
        cout << a.getMin(l, w, wi, s) << endl;
        system("pause");
        return 0;
}