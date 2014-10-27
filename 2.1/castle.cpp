/*
ID: wyuan171
PROG: castle
LANG: C++
*/
// 10/26/2014; Copy from http://www.nocow.cn/index.php/Code:USACO/castle/C%2B%2B.
// To do -- Use both flood fill and Union Set.
#include <fstream>

using namespace std;
#include <cstdio>
const int Max = 55 ;

int M, N ;
int map[Max][Max] ;

int set[Max*Max] ;      //  集合
int set_val[Max*Max];   // 并集权值

int find( int set[], int x ) // 查找
{
    int i = x ;
    while( i!=set[i] ){
        set[i]=set[ set[i] ];   // 压缩路径
        i = set[i];
    }
    return i ;
}

void weighted_quick_union( int set[], int set_val[], int p, int q )  // 加权并集
{
    int i = find( set, p );
    int j = find( set, q );
    if( i==j ) return ;
    if( set_val[i]<set_val[j] ){
        set[i]=j;
        set_val[j]+=set_val[i];
    }
    else{
        set[j]= i;
        set_val[i]+=set_val[j];
    }
}

int mov[16][4] = {  // 标示 左 上 右 下 , 是否可行
    { 1,1,1,1 },    // 四周均无墙
    { 0,1,1,1 }, { 1,0,1,1 }, { 0,0,1,1 }, { 1,1,0,1 }, { 0,1,0,1 },
    { 1,0,0,1 }, { 0,0,0,1 }, { 1,1,1,0 }, { 0,1,1,0 }, { 1,0,1,0 },
    { 0,0,1,0 }, { 1,1,0,0 }, { 0,1,0,0 }, { 1,0,0,0 },
    { 0,0,0,0 }     // 四周均有墙
} ;
//四个方向  左 上 右 下
int px[4] = {  0, -1, 0, 1 };
int py[4] = { -1,  0, 1, 0 };

int doit( int num , int x, int y )  // 判断四周可并集对象
{
    int i ;
    int tx , ty ;
    for( i=0; i<4 ;++i )    //  匹配四个方向
    {
        tx = x+px[i];  ty = y+py[i];
        if( mov[ num ][ i ]==1 )
            weighted_quick_union( set, set_val, M*x+y, M*tx+ty );
    }
}

int main( )
{
    freopen("castle.in","r",stdin); freopen("castle.out","w",stdout);
    
    int i, j ;
    int total ;     //  矩阵全部元素数目  N*M
    int count ;     //  房间数
    int max ;       //  最大房间单元数 ,  可合并后的最大单元数
    
    int a, b ;
    int c, d ;      // 拆强所在单元坐标
    int tmp ;
    bool flag ;     // 是否在东
    
    while( scanf ("%d %d", &M, &N )!=EOF )
    {
        total = N*M ;
        for( i = 0; i < total; ++i ) {
            set[i] = i;
            set_val[i] = 1 ;
        }
        
        for( i = 0; i < N; ++i )
            for( j = 0; j < M; ++j )
                scanf("%d", &map[i][j] ) ;
        
        for( i = 0; i < N; ++i )
            for( j = 0; j < M; ++j )
                doit( map[i][j], i, j ) ;
        
        max = count = 0 ;
        for( i = 0; i < total; ++i )
            if( set[i] == i )
            {
                if( set_val[i] > max )
                    max = set_val[i];
                ++count ;
            }
        
        printf("%d\n", count );
        printf("%d\n", max );
        
        max = 0 ;       // 重新置零, 计算最大可合并单元
        for( j = M-1; j >= 0 ; --j )
            for( i = 0; i < N; ++i )
            {
                if( j != M-1 && mov[ map[i][j] ][ 2 ] == 0 ) // 东侧有墙
                {
                    a = find( set, M*i+j ) ;
                    b = find( set, M*i+(j+1) ) ;
                    if( a != b )
                    {
                        tmp = set_val[a] + set_val[b] ;
                        if( tmp >= max )
                        {
                            max = tmp ;
                            c = i; d = j;
                            flag = true ;
                        }
                    }
                }
                if( i!=0 && mov[ map[i][j] ][ 1 ] == 0 ) // 北侧有墙
                {
                    a = find( set, M*i+j ) ;
                    b = find( set, M*(i-1)+j ) ;
                    if( a != b )
                    {
                        tmp = set_val[a] + set_val[b] ;
                        if( tmp >= max )
                        {
                            max = tmp ;
                            c = i; d = j;
                            flag = false ;
                        }
                    }
                }
            }
        
        printf("%d\n", max );
        printf("%d %d %c\n", c+1, d+1, flag ? 'E':'N' );
    }
    return 0;
}
