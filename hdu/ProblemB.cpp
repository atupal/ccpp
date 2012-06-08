/*#include<iostream>
using namespace std;

int main(){
        int a,b,c,n;
        while(cin >> a >> b >> c >> n){
                int f1 = a;
                int f2 = b;
                int f3 = c;
                if(n == 1) printf("%d\n", f1);
                if(n == 2) printf("%d\n", f2);
                if(n == 3) printf("%d\n", f3);
                for(int i = 3; i < n; ++ i){
                        f3 = (f1 + f2 + f3);
                        f2 = (f3 - f1 - f2) ;
                        f1 = (f3 - f1 - f2) ;
                }
                printf("%d\n", f3%100000017);
        }
}
*/

#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int   rgcd(int   v1,int   v2)
{
        if(v1 %2 == 0 && v2 % 2 == 0)return 1;
        if(v2!=0)
              return   rgcd(v2,v1%v2);
        return   v1;
}



int main(){
int x1, y1, x2, y2;
while(scanf("%d%d%d%d", &x1,&y1,&x2,&y2))
{
if(x1 == x2 ){if(abs(y1 - y2) > 1)printf("%d\n", 3);else printf("%d\n", 2);}
else if (y1 == y2 ){if(abs(x1 - x2) > 1)printf("%d\n", 3);else printf("%d\n", 2);}
else if(x1 == x2 && y1 == y2)printf("%d\n", 1);
   else if(abs(x1 - x2) == abs(y1 - y2) && abs(x1 - x2) != 1)
printf("%d\n", 3);
 //else if(rgcd(abs(x1 - x2), abs(y1 - y2) == 1 ))printf("%d\n", 2);
 else printf("%d\n", 3);
}


return 0;
}