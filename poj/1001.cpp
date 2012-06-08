#include <iostream>
#include <stdlib.h>
using namespace std;

void  multi(int *, int *, int[]);

int main(){
        int a[100];
        int b[100];
        int c[100];
        char s[100];
        int n;
        while(cin >> s >> n){
        for(int i = 0; i < 100; ++ i) a[i] = b[i] = 0;
        for(int i = 0; i < 100; ++ i) c[i] = 0;
        int p = 0;
        for(int i = 0; i < strlen(s); ++ i){
                if(s[strlen(s) - i - 1] != '.'){if(!p)a[i] = b[i] = (int) (s[strlen(s) - i - 1] - '0');else a[i - 1] = b[i - 1] = (int) (s[strlen(s) - i - 1] - '0');}else p = i * n;
        }
        for(int i = 0; i < n - 1; ++ i){
                multi(a, b, c);
                for(int i = 0; i < 100; ++ i) {a[i] = c[i]; c[i] = 0;}
        }
        int j;
        int e;
        for(e = 0; e < 100; ++ e)if(a[e] != 0 || e == p) break;
        for(j = 99; j > -1; --j) if(a[j] != 0) break;
        if(e- 1 >= j){printf("0\n"); continue;}
        for(int i = 0; i < p - j; ++ i)if(i == 0)printf(".");else printf("0");
        for(int i = j; i > e - 1; -- i) if(i != p)printf("%d", a[i]);else if(i > e) printf("%d.", a[i]);else printf("%d", a[i]);printf("\n");}
        getchar();getchar();
}

void multi(int a[], int b[], int c[]){
        for(int i = 0; i < 100; ++ i){
                for(int j = 0; j < 100; ++ j){
                        c[i + j] += a[i] * b[j];
                }
        }
        for(int i = 0; i < 100; ++ i){
                c[i + 1] += c[i] / 10;
                c[i] %= 10;
        }
}