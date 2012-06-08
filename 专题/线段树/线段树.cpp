/*�߶����ĳ��ò�����ʵ�ַ���

��������һ�����⣬ͨ���������˽��߶����Ĳ����뼰ʵ�ַ�����

����1��ZJU1610 Count The Colors �߶�������Ӧ����Ŀ��

��Ŀԭ�ģ�http://acm.zju.edu.cn/show_problem.php?pid=1610

��Ҫ���룺�������߶�[0,8000]�ϵ����ɴ�Ϳɫ��������ܿ�����Щ��ɫ����ͳ���ܿ������ٶΡ�

������

�������Ŀ���ԣ������ܶ࣬�������ݷ�Χ���󣬵����Ǵ��߶����ĽǶ������������⡣

������Ȼ���ǽ���һ�ô����߶�[0,8000]���߶�����Ϳɫ�������ǽ�[a , b]Ϳ����ɫc�������ͳ�ơ�

���Խṹ��Element���Ը�ΪColor��

Color>=0���ҽ����Ľ�������߶�������ɫ��ΪColor��

��ôÿһ�������ɫ���Ա�ʾ�������С�İ��������Color>=0�߶ε���ɫ��

�������ǿ��Դ�ǰ����ģ��ͼɫ���̣������һ��ͳ�Ƽ��ɡ����Ǹ��Ӷ�ΪO��n log L��������nΪ��������LΪ�߶γ��ȡ�

�߶���������һ��Ӧ�þ��ǲ�ѯ�߶��з�һЩ�߶θ��ǣ�����ʱ��ѯ��ǰ�������߶ε��ܳ��ȡ���ô��ʱ �����ڽ��ṹ�м���һ�����ͱ���count������ǰ������������б����ǵ��߶γ��Ⱥ͡�������Ҫ�ڲ��루ɾ��������ά�����countֵ�����ǵ�ǰ �ĸ�����ֵ���Ǹ��ڵ��countֵ�ˡ�

�����룺
*/

#define NoColor -1               //û����ɫ
#define MulColor -2              //���ɫ
#include <stdio.h>
#include <string.h>
int        Len;
struct     TNode {
           int        left , right;                   //�߶ε���˵���Ҷ˵�
           int        col;                            //���߶ε�Ϳɫ
           TNode      *LeftChild , *RightChild;       //�߶ε�����Ӻ��Ҷ���
           void       Construct ( int , int );        //�����߶���
           void       Insert ( int , int , int );     //�����߶�
           void       Calculate ();                   //����Ϳɫ
} Tree [16000] , *Root = &Tree [0]; 
int        CalColor [8001] , Many [8001];          //CalColor���ڴ��ÿһ�����ɫ
void       TNode :: Construct ( int l , int r )
{
           left = l; right = r;
           if ( l + 1 == r ) { LeftChild = NULL; RightChild = NULL; return; }      //Ҷ�ӽ��Ĵ��� 
           int        mid = ( l + r ) >> 1;           //�е���Զ�
           LeftChild = &Tree [Len ++];
           RightChild = &Tree [Len ++];
           LeftChild->Construct( l , mid );         //���������
           RightChild->Construct( mid , r );        //�����Ҷ���
} 
void       TNode :: Insert ( int l , int r , int c )
{
           if ( col == c ) return;                  //ͬɫ������
           if ( l == left && r == right ) { col = c; return; }        //�����߶ζ��غϵ�ʱ��Ž���Ϳɫ,Ϳ�귵��
           int        mid = ( left + right ) >> 1;
           if ( col != MulColor ) { LeftChild -> col = col; RightChild -> col = col; }
           col = MulColor;
           if ( r <= mid ) { LeftChild -> Insert ( l , r , c ); return; } //�󲿷ֱ�����ʱ�������������Ϳɫ
           if ( l >= mid ) { RightChild -> Insert ( l , r , c ); return; }//�Ҳ��ֱ�����ʱ�������Ҷ�����Ϳɫ
           LeftChild -> Insert ( l , mid , c );          //��Խ����ʱ�ֶβ���
           RightChild -> Insert ( mid , r , c );
}
//ͳ��ÿһ�����ɫ 
void       TNode :: Calculate ()
{
           if ( col != MulColor && col != NoColor ) {
                   int        i;
                   for ( i = left; i < right; i ++ ) CalColor [i] = col;
           }
           if ( col == MulColor ) { LeftChild -> Calculate (); RightChild -> Calculate (); }
} 
main ()
{
           int        Total , a , b , c , i , t;
           Len = 1; Tree [0].Construct( 0 , 8000 );            //��8000��ʼ���� 
           while ( scanf ( "%d" , &Total ) != EOF ) {
                   Tree [0].col = NoColor;
                   while ( Total ) {
                           scanf ( "%d %d %d" , &a , &b , &c );
                           Root -> Insert( a , b , c );
                           Total --;
                   }
                   memset ( CalColor , 0xff , sizeof ( CalColor ) );
                   memset ( Many , 0 , sizeof ( Many ));
                   Root -> Calculate (); 
                   t = -1;
                   for ( i = 0; i <= 8000; i ++ ) {
                           if ( CalColor [i] == t ) continue;
                           t = CalColor [i];
                           if ( t != -1 ) Many [t] ++;          //Many[t]��ʾ��ɫt���ֵĴ���
                   }
                   for ( i = 0; i <= 8000; i ++ ) if ( Many [i] )
                           printf ( "%d %d\n" , i , Many [i] ); 
                   printf ( "\n" );
           }        
}