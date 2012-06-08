/*
    by atupal
    彩板学生管路系统；
    ＵＩ很挫。。。 
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAXSTU 100
#define MAXLEN 100
#define AVE_RATE 0.6
#define AVE_FROM_OTHER_RATE 0.1
#define PINGDE_RATE 0.1
#define AVE_FROM_TEATHER_RATE 0.2

//定义学生结构体 
typedef struct{
        long long id;
        char name[MAXLEN];
        char sex[MAXLEN];
        char address[MAXLEN];
        char phone[MAXLEN];
        float chinese;
        float math;
        float english;
        int rate;
        int finalRate;
        float average;
        float gradeFromOther; 
        float pingde;
        float gradeFromTeather;
        float finalGrade;
}student;

//返回在数组中某学号的数组索引 
int index(student * set, long long index){
    int i = 0;
    while(++ i <= set[0].id){
        if(set[i].id == index) return i;
        if(set[i].id > index) {
            int j;
            for(j = set[0].id; j >=i ; -- j)
                set[j + 1] = set[j];
//            memset(set[i], 0);
            ++ set[0].id; 
            return i;
        }
    }
    ++ set[0].id; 
    return set[0].id;
}
//插入一个学生 
int insert(student * set){
    char tmp[MAXLEN];
    long long id;
    printf("学号: \t");
    scanf("%lld", &id);
    if(id <= 0) return -1; 
    int i = index(set, id);
    set[i].id = id; 
    
    printf("姓名: \t");
    scanf("%s", &tmp);
    strcpy(set[i].name, tmp);
    
    printf("性别: \t");
    scanf("%s", &tmp);
    strcpy(set[i].sex, tmp);
    
    printf("住址: \t");
    scanf("%s", &tmp);
    strcpy(set[i].address, tmp);
    
    printf("电话: \t");
    scanf("%s", &tmp);
    strcpy(set[i].phone, tmp);
    
    printf("-------------------------------------------------------------------------------\n");
    return 0; 
}
//删除一个学生 
void del(student * set, long long index){
    printf("请输入要删除的学生的学号："); 
    scanf("%lld", &index) ; 
    int i;
    for(i = 1; i <= set[0].id; ++ i){
        if(set[i].id == index){
            printf("确认删除 %s？(y / n) : ", set[i].name);
            char tmp;
            while((scanf("%c", &tmp), tmp) == '\n');
            if(tmp == 'y'){
                    printf("已成功删除%s的记录\n", set[i].name);                     
                   int j; 
                   for(j = i; j < set[0].id; ++ j)
                        set[j] = set[j + 1];
                    -- set[0].id;
                    
                    return ; 
            }else return ;
        }
    }
    printf("error: 未找到相关学生! \n");
    return; 
}
//打印一个学生 
void display(student stu){
    printf("\n-------------------------------------------------------------------------------\n");
    printf("%15s%15s%15s%15s%15s", "学号", "姓名", "性别", "家庭住址", "联系电话\n");
    printf("%15lld", stu.id);
    printf("%15s%15s%15s%15s\n", stu.name, stu.sex, stu.address, stu.phone);
    printf("-------------------------------------------------------------------------------\n");
} 
//打印所有学生 
void displayAll(student * set){
    int i;
    for(i = 1; i <= set[0].id; ++ i) display(set[i]);
}
//更新成绩 
int updataGrade(student * set){
    printf("请输入学生学号：");
    long long tmp;
    scanf("%lld", &tmp);
    if(tmp <= 0) return -1;
    int i = index(set, tmp);
    printf("请分别输入 语文，数学，外语成绩，中间按空格分开 ：");
    scanf("%f", &set[i].chinese);
    scanf("%f", &set[i].math);
    scanf("%f", &set[i].english);
    set[i].average = (set[i].chinese + set[i].math + set[i].english) / 3;
    return 0;
}
//更新互评成绩 
int updataFinalGrade(student * set){
    printf("请输入学生学号：");
    long long tmp;
    scanf("%lld", &tmp);
    if(tmp <= 0) return -1;
    int i = index(set, tmp);
    printf("请分别输入 同学互评分, 品德成绩, 任课老师评分. 中间按空格分开 ：");
    scanf("%f", &set[i].gradeFromOther);
    scanf("%f", &set[i].pingde);
    scanf("%f", &set[i].gradeFromTeather);
    set[i].finalGrade = set[i].average * AVE_RATE + set[i].gradeFromOther * AVE_FROM_OTHER_RATE + set[i].pingde * PINGDE_RATE + set[i].gradeFromTeather * AVE_FROM_TEATHER_RATE;
    return 0;
}
//考试成绩排名 
void rate(student * set){
    int i;
    int j;
    
    for(i = 1; i <= set[0].id; ++ i){
        ++ set[i].rate;
        for(j = 1; j <= set[0].id; ++ j){
            if(i != j && set[j].average > set[i].average) ++ set[i].rate;
        }
        printf("");
    }
    for(i = 1; i <= set[0].id; ++ i){
        printf("%lld %s rate: %d", set[i].id, set[i].name, set[i].rate);
    }
}
//综合成绩排名 
void finalRate(student * set){
    int i;
    int j;
    for(i = 1; i <= set[0].id; ++ i)  
        for(j = 1; j <= set[0].id; ++ j){
            if(i != j && set[j].finalGrade > set[i].finalGrade) ++ set[i].finalRate;
        }
    for(i = 1; i <= set[0].id; ++ i){
        printf("%lld %s finalRate: %d", set[i].id, set[i].name, set[i].finalRate);
    }
}
//保存到“学生管理.txt” 中 
void save(student * set){
    FILE * file = fopen("学生管理.txt", "w");
    fprintf(file, "%lld\n", set[0].id);
    int i;
    for(i = 1; i <= set[0].id; ++ i) 
        fprintf(file, "%lld %s %s %s %s %f %f %f %d %d %f %f %f %f %f\n",set[i].id, set[i].name, set[i].sex, set[i].address, set[i].phone,
                set[i].chinese, set[i].math, set[i].english, set[i].rate, set[i].finalRate, set[i].average, set[i].gradeFromOther, set[i].pingde, set[i].gradeFromTeather, set[i].finalGrade);
    fclose(file);
    return;
}
//初始化，从文件中读取学生信息数据 
void read(student * set){
    long long tmp;
    FILE * file = fopen("学生管理.txt", "r");
    
    fscanf(file, "%lld", &tmp);
    
    printf("%lld", tmp);
    if(tmp >= MAXSTU || tmp <= 0) return;
    set[0].id = tmp;
    int i;
    for(i = 1; i <= tmp; ++ i) 
        fscanf(file, "%lld %s %s %s %s %f %f %f %d %d %f %f %f %f %f\n",&set[i].id, set[i].name, set[i].sex, set[i].address, set[i].phone,
                &set[i].chinese, &set[i].math, &set[i].english, &set[i].rate, &set[i].finalRate, &set[i].average, &set[i].gradeFromOther, &set[i].pingde, &set[i].gradeFromTeather, &set[i].finalGrade);
    fclose(file);
    return;
}
//搜索学生 
int search(student * set) {
    printf("输入要查询的学生学号：\n") ; 
    long long index;
    scanf("%lld", &index);
    int i; 
    for(i = 1; i <= set[0].id; ++ i) {
        if(set[i].id == index) {display(set[i]);}
    }
    printf("未找到相关信息， 请检查是否输入有误！");
    return 0;    
} 
//主界面 
int mainConsole(student * set){
       printf("输入数字以选择功能\n");
       printf("1 :输入学生信息\n"); 
       printf("2 :插入||更新学生信息\n"); 
       printf("3 :删除学生信息\n");
       printf("4 :浏览学生信息\n");
       printf("5 :录入考试成绩\n"); 
       printf("6 :录入综合成绩\n"); 
       printf("7 :查询学生信息\n"); 
       printf("8 :输出学生信息\n");
       printf("9 :考试成绩排名\n");
       printf("10 :综合成绩排名\n"); 
       printf("0 :退出\n"); 
       int choice;
       scanf("%d", &choice);
       switch(choice){
            case 1 : printf("输入学生学号，以0结束!\n"); while(!insert(set)); system("pause"); break;
            case 2 : insert(set) ; system("pause");break;
            case 3 : del(set, 0) ; system("pause");break;
            case 4 : displayAll(set);system("pause");break;
            case 5 : printf("输入学生学号， 以0结束!\n"); while(!updataGrade(set)); system("pause");break;
            case 6 : printf("输入学生学号， 以0结束!\n"); while(!updataFinalGrade(set)) ; system("pause");break;
            case 7 : search(set);  system("pause");break;
            case 8 : displayAll(set); system("pause");break;
            case 9 : rate(set);system("pause");break;
            case 10 : finalRate(set);system("pause");break;
            case 0 : return -1; break;
        }
      return 0; 
}

//主程序入口 
int main(int argc, char *argv[])
{
     //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
       //     FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
       CONSOLE_CURSOR_INFO cci;
    cci.bVisible = FALSE;
    cci.dwSize = sizeof(cci);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cci);
       
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
    FOREGROUND_BLUE);
    printf("\n\n\n\n\n\n\n*****************************欢迎使用学生管理系统*******************************");
    getchar();
    cci.bVisible = TRUE;
    SetConsoleCursorInfo(handle, &cci);
    

    
    system("cls");
    student set[MAXSTU];
    
    set[0].id = 0; 
    
    read(set);
    while(!mainConsole(set)){
        system("cls");
    }
    
//    int i;
//    scanf("%d", &i);
//    for(; i > 0; -- i){
//    insert(set);
//    updataGrade(set);}
//    rate(set);
//    for(i = 1; i <= set[0].id; ++ i) {display(set[i]);printf("%d\n", set[i].rate);}
    system("pause");
    save(set);
    return 0;
}
