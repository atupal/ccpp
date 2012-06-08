/*
    by atupal
    �ʰ�ѧ����·ϵͳ��
    �գɺܴ졣���� 
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

//����ѧ���ṹ�� 
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

//������������ĳѧ�ŵ��������� 
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
//����һ��ѧ�� 
int insert(student * set){
    char tmp[MAXLEN];
    long long id;
    printf("ѧ��: \t");
    scanf("%lld", &id);
    if(id <= 0) return -1; 
    int i = index(set, id);
    set[i].id = id; 
    
    printf("����: \t");
    scanf("%s", &tmp);
    strcpy(set[i].name, tmp);
    
    printf("�Ա�: \t");
    scanf("%s", &tmp);
    strcpy(set[i].sex, tmp);
    
    printf("סַ: \t");
    scanf("%s", &tmp);
    strcpy(set[i].address, tmp);
    
    printf("�绰: \t");
    scanf("%s", &tmp);
    strcpy(set[i].phone, tmp);
    
    printf("-------------------------------------------------------------------------------\n");
    return 0; 
}
//ɾ��һ��ѧ�� 
void del(student * set, long long index){
    printf("������Ҫɾ����ѧ����ѧ�ţ�"); 
    scanf("%lld", &index) ; 
    int i;
    for(i = 1; i <= set[0].id; ++ i){
        if(set[i].id == index){
            printf("ȷ��ɾ�� %s��(y / n) : ", set[i].name);
            char tmp;
            while((scanf("%c", &tmp), tmp) == '\n');
            if(tmp == 'y'){
                    printf("�ѳɹ�ɾ��%s�ļ�¼\n", set[i].name);                     
                   int j; 
                   for(j = i; j < set[0].id; ++ j)
                        set[j] = set[j + 1];
                    -- set[0].id;
                    
                    return ; 
            }else return ;
        }
    }
    printf("error: δ�ҵ����ѧ��! \n");
    return; 
}
//��ӡһ��ѧ�� 
void display(student stu){
    printf("\n-------------------------------------------------------------------------------\n");
    printf("%15s%15s%15s%15s%15s", "ѧ��", "����", "�Ա�", "��ͥסַ", "��ϵ�绰\n");
    printf("%15lld", stu.id);
    printf("%15s%15s%15s%15s\n", stu.name, stu.sex, stu.address, stu.phone);
    printf("-------------------------------------------------------------------------------\n");
} 
//��ӡ����ѧ�� 
void displayAll(student * set){
    int i;
    for(i = 1; i <= set[0].id; ++ i) display(set[i]);
}
//���³ɼ� 
int updataGrade(student * set){
    printf("������ѧ��ѧ�ţ�");
    long long tmp;
    scanf("%lld", &tmp);
    if(tmp <= 0) return -1;
    int i = index(set, tmp);
    printf("��ֱ����� ���ģ���ѧ������ɼ����м䰴�ո�ֿ� ��");
    scanf("%f", &set[i].chinese);
    scanf("%f", &set[i].math);
    scanf("%f", &set[i].english);
    set[i].average = (set[i].chinese + set[i].math + set[i].english) / 3;
    return 0;
}
//���»����ɼ� 
int updataFinalGrade(student * set){
    printf("������ѧ��ѧ�ţ�");
    long long tmp;
    scanf("%lld", &tmp);
    if(tmp <= 0) return -1;
    int i = index(set, tmp);
    printf("��ֱ����� ͬѧ������, Ʒ�³ɼ�, �ο���ʦ����. �м䰴�ո�ֿ� ��");
    scanf("%f", &set[i].gradeFromOther);
    scanf("%f", &set[i].pingde);
    scanf("%f", &set[i].gradeFromTeather);
    set[i].finalGrade = set[i].average * AVE_RATE + set[i].gradeFromOther * AVE_FROM_OTHER_RATE + set[i].pingde * PINGDE_RATE + set[i].gradeFromTeather * AVE_FROM_TEATHER_RATE;
    return 0;
}
//���Գɼ����� 
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
//�ۺϳɼ����� 
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
//���浽��ѧ������.txt�� �� 
void save(student * set){
    FILE * file = fopen("ѧ������.txt", "w");
    fprintf(file, "%lld\n", set[0].id);
    int i;
    for(i = 1; i <= set[0].id; ++ i) 
        fprintf(file, "%lld %s %s %s %s %f %f %f %d %d %f %f %f %f %f\n",set[i].id, set[i].name, set[i].sex, set[i].address, set[i].phone,
                set[i].chinese, set[i].math, set[i].english, set[i].rate, set[i].finalRate, set[i].average, set[i].gradeFromOther, set[i].pingde, set[i].gradeFromTeather, set[i].finalGrade);
    fclose(file);
    return;
}
//��ʼ�������ļ��ж�ȡѧ����Ϣ���� 
void read(student * set){
    long long tmp;
    FILE * file = fopen("ѧ������.txt", "r");
    
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
//����ѧ�� 
int search(student * set) {
    printf("����Ҫ��ѯ��ѧ��ѧ�ţ�\n") ; 
    long long index;
    scanf("%lld", &index);
    int i; 
    for(i = 1; i <= set[0].id; ++ i) {
        if(set[i].id == index) {display(set[i]);}
    }
    printf("δ�ҵ������Ϣ�� �����Ƿ���������");
    return 0;    
} 
//������ 
int mainConsole(student * set){
       printf("����������ѡ����\n");
       printf("1 :����ѧ����Ϣ\n"); 
       printf("2 :����||����ѧ����Ϣ\n"); 
       printf("3 :ɾ��ѧ����Ϣ\n");
       printf("4 :���ѧ����Ϣ\n");
       printf("5 :¼�뿼�Գɼ�\n"); 
       printf("6 :¼���ۺϳɼ�\n"); 
       printf("7 :��ѯѧ����Ϣ\n"); 
       printf("8 :���ѧ����Ϣ\n");
       printf("9 :���Գɼ�����\n");
       printf("10 :�ۺϳɼ�����\n"); 
       printf("0 :�˳�\n"); 
       int choice;
       scanf("%d", &choice);
       switch(choice){
            case 1 : printf("����ѧ��ѧ�ţ���0����!\n"); while(!insert(set)); system("pause"); break;
            case 2 : insert(set) ; system("pause");break;
            case 3 : del(set, 0) ; system("pause");break;
            case 4 : displayAll(set);system("pause");break;
            case 5 : printf("����ѧ��ѧ�ţ� ��0����!\n"); while(!updataGrade(set)); system("pause");break;
            case 6 : printf("����ѧ��ѧ�ţ� ��0����!\n"); while(!updataFinalGrade(set)) ; system("pause");break;
            case 7 : search(set);  system("pause");break;
            case 8 : displayAll(set); system("pause");break;
            case 9 : rate(set);system("pause");break;
            case 10 : finalRate(set);system("pause");break;
            case 0 : return -1; break;
        }
      return 0; 
}

//��������� 
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
    printf("\n\n\n\n\n\n\n*****************************��ӭʹ��ѧ������ϵͳ*******************************");
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
