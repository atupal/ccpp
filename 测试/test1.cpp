#include <iostream>
using namespace std;

class Test{
public :
        char * str;
public :
        ~Test(){};
        Test(char * a = "default"){str = new char[strlen(a) + 1]; strcpy(str, a);}
        void cd(char *s){strcpy(str, s);}
        void show(){cout << str << endl;}
//        friend Test operator =(Test &t, Test &t2){
//                //strcpy(str, t.str);
//                //return Test(str);
//                return NULL;
//        }
//        friend  Test operator +(Test &t1, Test &t2){
//                char *tmp = new char[strlen(t1.str) + strlen(t2.str) + 1];
//                int t = 0;
//                strcpy(tmp, t1.str);
//                do tmp[t + strlen(t1.str)] = t2.str[t];
//                while(t2.str[t ++]);
//                return Test(tmp);
//        }
        Test operator +(Test &t2){
                char *tmp = new char[strlen(str) + strlen(t2.str) + 1];
                int t = 0;
                strcpy(tmp, str);
                do tmp[t + strlen(str)] = t2.str[t];
                while(t2.str[t ++]);
                return Test(tmp);
        }
};

int main(){
        Test test_1;
        Test test_2;
        test_2.cd("sdfr");
        test_1 + test_1 + test_1;
        test_1.show();
        getchar();
        return 0;
}
