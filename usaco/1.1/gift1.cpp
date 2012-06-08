/*
        ID:atupal
        LANG:C++
        TASK:gift1
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
        int np;int res[100],o[100];
int equal(char a[], char b[]){
        for(int i = 0; i < 20; ++ i){
                if(a[i] != b[i])
                        return 0;
        }
        return 1;
}

void add(char Name[], char name[][20], int m){
        for(int i = 0; i < np; ++ i ){
                if(equal(name[i], Name))
                        res[i] += m;
        }
}
void oo(char * Name, char name[][20], int m){
        for(int i = 0; i < np; ++ i ){
                if(equal(name[i], Name))
                        o[i] += m;
        }
}


int main(){
        freopen("gift1.in", "r", stdin);
        freopen("gift1.out", "w", stdout);

        cin >> np;
        
        char name[np][20];
        for(int i = 0; i < np; ++ i) {res[i] = 0;o[i] = 0;}
        for(int i = 0; i < np; ++ i){
                cin >> name[i];
        }

        char tmp[20];
        int iter = np;
        while(iter --){
                cin >> tmp;
                int mon;
                int n;
                cin >> mon >> n;
                oo(tmp, name, mon / n);
                char t[20];
                int m = n;
                while(m --){
                        cin >> t;
                        add(t, name, mon / n);
                }
                add(tmp, name, mon - mon / n * n);
        }
        for(int i = 0; i < np; ++ i){
                cout << name[i] << " " << res[i] - o[i] << endl;
        }
        //fclose(stdin);
        //fclose(stdout);
        return 0;
}