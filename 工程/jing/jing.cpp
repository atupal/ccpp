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
//ȫ�ֱ�������
double ** dis; //���������������
int ** zhida; //�������������Ƿ�ֱ��
int * category; //����ÿ��������
int *core; //�����Ƿ�Ϊ���Ķ���
vector<double> x; //����x����
vector<double> y; //����y����
vector<int> cat; //����ÿ�����ĵ����Ŀ
int size;  //�����ж��ٸ���
int categoryNum; //����������Ŀ

//��㼯�������������еľ���
double dist(int i, int j){
        return sqrt(abs((x[i] - x[j]) * (x[i] - x[j])) + abs((y[i] - y[j]) * (y[i] - y[j])));
}
//�ж��Ƿ�Ϊ���Ķ���,�����������
int isCore(int i){
        int tmp = 0;
        for(int j = 0; j < size; ++ j)
                if(dis[i][j] < EPS && dis[i][j] != 0) ++ tmp;
        if(tmp >= MINPTS) return 1;
        return 0;
}
//����
void dfs(int i){
        for(int j = 0; j < size; ++ j){
                if(i != j && zhida[i][j] && category[j] == 0){
                        category[j] = category[i];
                        ++ cat[category[i]];
                        dfs(j);
                }
        }
}

//�������
int main(){
        //�����ļ�
        ifstream file;
        file.open(INPUT1);
        
        double tmp;
        int i = 0;
        while(file >> tmp){
                if((++ i) % 2) x.push_back(tmp);
                else y.push_back(tmp);
        }
        
        //������ʼ��
        size = x.size();
        dis = (double **) malloc(size * 4);
        zhida = (int **) malloc(size * 4);
        core = (int *) malloc(size * sizeof(int));
        category = (int *) malloc(size * sizeof(int));
        for(int i = 0; i < size; ++ i){
                dis[i] = (double *) malloc(size * sizeof(double));
                zhida[i] = (int *) malloc(size * sizeof(int));
        }
        
        //�����������ľ��벢����
        for(int i = 0; i < size; ++ i){
                for(int j = i; j < size; ++ j){
                        dis[i][j] = dis[j][i] = dist(i, j);
                }
        }

        //�ҳ����Ķ��󲢱���
        for(int i = 0; i < size; ++ i)
                core[i] = isCore(i);

        //����Ķ�����ܶ�ֱ���
        for(int i = 0; i < size; ++ i){
                for(int j = 0; j < size; ++ j){
                        if(i != j && dis[j][i] < EPS && core[i])
                                zhida[i][j] = 1;
                        else zhida[i][j] = 0;
                }
        }
        
        //����ļ�
        ofstream out;
        out.open("./out.txt");
        //�Ե㼯���з��ಢ�ϲ��������������������
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

        //������
        for(int i = 0; i < size; ++ i)
               out << x[i] << " " << y[i] << " " << category[i] << endl;
        //��ʾ������������̨
        cat[0] = size;
        for(int i = 1; i < cat.size(); ++ i){
                cout << "category " << i << " :" << cat[i] << "��" << endl;
                cat[0] -= cat[i];
        }
        cout << "��⵽����Ⱥ�� :" << cat[0] << "��" << endl;
        
        file.close();
        out.close();
        system("pause");
        return 0;
}
