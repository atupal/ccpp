/*线段树的常用操作及实现方法

我们来看一个例题，通过例题来了解线段树的操作与及实现方法。

例题1（ZJU1610 Count The Colors 线段树基本应用题目）

题目原文：http://acm.zju.edu.cn/show_problem.php?pid=1610

简要翻译：给出在线段[0,8000]上的若干次涂色，问最后能看见哪些颜色，并统计能看到多少段。

解析：

就这个题目而言，方法很多，而且数据范围不大，但我们从线段树的角度来解决这个问题。

建树自然就是建立一棵代表线段[0,8000]的线段树，涂色操作就是将[a , b]涂成颜色c。最后做统计。

所以结构中Element可以改为Color。

Color>=0当且仅当改结点代表的线段所有颜色均为Color。

那么每一个球的颜色可以表示成深度最小的包含此球的Color>=0线段的颜色。

于是我们可以从前到后模拟图色过程，最后做一个统计即可。于是复杂度为O（n log L），其中n为操作数，L为线段长度。

线段树的另外一个应用就是查询线段有否被一些线段覆盖，并随时查询当前被覆盖线段的总长度。那么此时 可以在结点结构中加入一个整型变量count；代表当前结点代表的子树中被覆盖的线段长度和。这样就要在插入（删除）当中维护这个count值，于是当前 的覆盖总值就是根节点的count值了。

附代码：
*/

#define NoColor -1               //没有颜色
#define MulColor -2              //混合色
#include <stdio.h>
#include <string.h>
int        Len;
struct     TNode {
           int        left , right;                   //线段的左端点和右端点
           int        col;                            //该线段的涂色
           TNode      *LeftChild , *RightChild;       //线段的左儿子和右儿子
           void       Construct ( int , int );        //构造线段树
           void       Insert ( int , int , int );     //插入线段
           void       Calculate ();                   //计算涂色
} Tree [16000] , *Root = &Tree [0]; 
int        CalColor [8001] , Many [8001];          //CalColor用于存放每一点的颜色
void       TNode :: Construct ( int l , int r )
{
           left = l; right = r;
           if ( l + 1 == r ) { LeftChild = NULL; RightChild = NULL; return; }      //叶子结点的处理 
           int        mid = ( l + r ) >> 1;           //中点除以二
           LeftChild = &Tree [Len ++];
           RightChild = &Tree [Len ++];
           LeftChild->Construct( l , mid );         //构造左儿子
           RightChild->Construct( mid , r );        //构造右儿子
} 
void       TNode :: Insert ( int l , int r , int c )
{
           if ( col == c ) return;                  //同色不处理
           if ( l == left && r == right ) { col = c; return; }        //整段线段都重合的时候才进行涂色,涂完返回
           int        mid = ( left + right ) >> 1;
           if ( col != MulColor ) { LeftChild -> col = col; RightChild -> col = col; }
           col = MulColor;
           if ( r <= mid ) { LeftChild -> Insert ( l , r , c ); return; } //左部分被包含时继续往左儿子上涂色
           if ( l >= mid ) { RightChild -> Insert ( l , r , c ); return; }//右部分被包含时继续往右儿子上涂色
           LeftChild -> Insert ( l , mid , c );          //跨越两端时分段插入
           RightChild -> Insert ( mid , r , c );
}
//统计每一点的颜色 
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
           Len = 1; Tree [0].Construct( 0 , 8000 );            //从8000开始构造 
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
                           if ( t != -1 ) Many [t] ++;          //Many[t]表示颜色t出现的次数
                   }
                   for ( i = 0; i <= 8000; i ++ ) if ( Many [i] )
                           printf ( "%d %d\n" , i , Many [i] ); 
                   printf ( "\n" );
           }        
}