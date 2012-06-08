#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#define EPS 0.070
#define MINPTS 4
#define INPUT1 "./CircleData.txt"
#define INPUT2 "./FiveData.txt"
#define INPUT3 "./MoonData.txt"
using namespace std;
//全局变量定义
double ** dis; //保存任意两点距离
int ** zhida; //保存任意两点是否直达
int * category; //保存每个点的类别
int *core; //保存是否为核心对象
vector<double> x; //保存x坐标
vector<double> y; //保存y坐标
vector<int> cat; //保存每个类别的点的数目
int size;  //保存有多少个点
int categoryNum; //保存类别的数目

//求点集中任意两个序列的距离
double dist(int i, int j){
        return sqrt(abs((x[i] - x[j]) * (x[i] - x[j])) + abs((y[i] - y[j]) * (y[i] - y[j])));
}
//判断是否为核心对象,深度优先搜索
int isCore(int i){
        int tmp = 0;
        for(int j = 0; j < size; ++ j)
                if(dis[i][j] < EPS && dis[i][j] != 0) ++ tmp;
        if(tmp >= MINPTS) return 1;
        return 0;
}
//聚类
void dfs(int i){
        for(int j = 0; j < size; ++ j){
                if(i != j && zhida[i][j] && category[j] == 0){
                        category[j] = category[i];
                        ++ cat[category[i]];
                        dfs(j);
                }
        }
}

//程序入口
int main(){
        //输入文件
        ifstream file;
        file.open(INPUT1);
        
        double tmp;
        int i = 0;
        while(file >> tmp){
                if((++ i) % 2) x.push_back(tmp);
                else y.push_back(tmp);
        }
        
        //变量初始化
        size = x.size();
        dis = (double **) malloc(size * 4);
        zhida = (int **) malloc(size * 4);
        core = (int *) malloc(size * sizeof(int));
        category = (int *) malloc(size * sizeof(int));
        for(int i = 0; i < size; ++ i){
                dis[i] = (double *) malloc(size * sizeof(double));
                zhida[i] = (int *) malloc(size * sizeof(int));
        }
        
        //求出任意两点的距离并保存
        for(int i = 0; i < size; ++ i){
                for(int j = i; j < size; ++ j){
                        dis[i][j] = dis[j][i] = dist(i, j);
                }
        }

        //找出核心对象并保存
        for(int i = 0; i < size; ++ i)
                core[i] = isCore(i);

        //算核心对象的密度直达点
        for(int i = 0; i < size; ++ i){
                for(int j = 0; j < size; ++ j){
                        if(i != j && dis[j][i] < EPS && core[i])
                                zhida[i][j] = 1;
                        else zhida[i][j] = 0;
                }
        }
        
        //输出文件
        ofstream out;
        out.open("./out.txt");
        //对点集进行分类并合并（采用深度优先搜索）
        cat.push_back(0);
        categoryNum = 0;
        for(int i = 0; i < size; ++ i) category[i] = 0;
        for(int i = 0; i < size; ++ i){
                if(core[i] && category[i] == 0){
                        category[i] = ++ categoryNum;
                        cat.push_back(1);
                        //cout << categoryNum << endl;
                        dfs(i);
                }
        }

        //输出结果
        for(int i = 0; i < size; ++ i)
               out << x[i] << " " << y[i] << " " << category[i] << endl;
        //显示分类结果到控制台
        cat[0] = size;
        for(int i = 1; i < cat.size(); ++ i){
                cout << "category " << i << " :" << cat[i] << "个" << endl;
                cat[0] -= cat[i];
        }
        cout << "检测到的离群点 :" << cat[0] << "个" << endl;
        
        file.close();
        out.close();
        system("pause");
        return 0;
}
