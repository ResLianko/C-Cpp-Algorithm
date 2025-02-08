//Chapter 3

#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <time.h>

#include <string.h>

#include <stdbool.h>

#include <ctype.h>

int main()
{

//Appendix per 02 begin

//非数组解法 （暴力解法）

int a, b, c, d, e, f, g, h, i;
for (int ghi = 123; ghi <= 987; ghi++) {
    int abc = ghi / 3;
    int def = abc * 2;
    bool can = true;
    if ((ghi % 3 != 0)||(abc < 123)) {can = false;}
g = ghi / 100;
h = (ghi - 100 * g) / 10;
i = ghi % 10;
a = abc / 100;
b = (abc - 100 * a) / 10;
c = abc % 10;
d = def / 100;
e = (def - 100 * d);
f = def % 10;
if (a * b * c * d * e * f * g * h * i == 0) {can = false;}
       if (a==b||a==c||a==d||a==e||a==f||a==g||a==h||a==i) {
    can = false;
} else if (b==c||b==d||b==e||b==f||b==g||b==h||b==i) {
    can = false;
} else if (c==d||c==e||c==f||c==g||c==h||c==i) {
    can = false;
} else if (d==e||d==f||d==g||d==h||d==i) {
    can = false;
} else if (e==f||e==g||e==h||e==i) {
    can = false;
} else if (f==g||f==h||f==i) {
    can = false;
} else if (g==h||g==i) {
    can = false;
} else if (h==i) {                                                  //这里显然不能用else
    can = false;
}
if (can) {printf("%d %d %d\n", abc, def, ghi);}
}
//Appendix per 02 end



//fall-through

//下面介绍switch的fall-through现象

//与go不同，C是默认fall-through（贯穿）的，如下

/*
int num;
scanf("%d", &num);
switch (num)
{
case 1:
    printf("1\n");
case 2:
    printf("2\n");
case 3:
    printf("3\n");
default:
    printf("others\n");
}//2~2    3   others
*/

//若要不穿透，只需使用break，如下

/*
int num;
scanf("%d", &num);
switch (num)
{
case 1:
    printf("1\n");
    break;
case 2:
    printf("2\n");
    break;
case 3:
    printf("3\n");
    break;
default:
    printf("others\n");
}//2~2
*/

//default是可选的，它在不满足case时执行，可以不写（正如else可以不写），通常置最后，但不一定

//多个case同一操作的写法：case串联，不加break，代码块置后
/*
int num;
scanf("%d", &num);
switch (num)
{
case 1:

case 2:
    printf("2\n");
    break;
case 3:
    printf("3\n");
    break;
case 4:
    printf("4\n");
case 5:

case 6:

default:
    printf("others\n");
}
//1~2   2~2    5/6~others
*/

//对char的switch语句
/*
char marriage_status;
scanf("%c", &marriage_status);

switch (marriage_status)
{
case 'S':
    printf("single");
    break;
case 'M':
    printf("married");
    break;
case 'W':
    printf("widowed");
    break;
case 'E':
    printf("separated");
    break;
case 'D':
    printf("divorced");
    break;
default:
    printf("error:invalid code");
    break;
}
*/

//多维数组
//我们指出，多维数组也能用memset清零，也能用for嵌套遍历，后者可用"%d ", "%3d"之类的格式

//一维数组的相等判定与广义赋值

int arr1[3] = {4, 5, 6};
int arr2[3] = {4, 5, 6};
int arr3[3] = {1, 2, 3};
bool arrequal = true;
int size1 = sizeof(arr1) / sizeof(arr1[0]);  
int size2 = sizeof(arr2) / sizeof(arr2[0]);  
if (size1 != size2) {
    arrequal = false;
} else {
    for (int i = 0; i < size1; i++)                                         //<而非<=
    {
        if (arr1[i] != arr2[i])
        {
            arrequal = false;
            break;
        }
        
    }
    
}
if (arrequal) {
    printf("are eq\n");
} else {
    printf("are not eq\n");
}

printf("%d %d %d\n", arr3[0], arr3[1], arr3[2]);
memcpy(arr3, arr1, sizeof(arr1));
printf("%d %d %d\n", arr3[0], arr3[1], arr3[2]);
/*
在C和C++中，局部数组（在函数内部声明的数组）未初始化时，其元素的值是未定义的
这意味着它们可能包含任何值，包括垃圾值（之前存储在内存中的值）
全局数组（在函数外部声明的数组）会被自动初始化为0
*/

//字符数组
/*
字符数组不表示字符串时，末元素可以是任意字符
表示字符串时，末元素存储'\0'作为字符串结束标志
*/
char s[6];
s[0] = 'A';
s[1] = 'r';
s[2] = 'r';
s[3] = 'a';
s[4] = 'y';
s[5] = '\0';
printf("%s\n", s);

scanf("%s", s);//无&符！！！    末尾自动加'\0'
printf("%s\n", s);



//冒泡排序（Bubble Sort）：基本的排序

//当此之时，我刚在广工（非本校）的（线上）算竞玩了一会，这是我参加的第一次算竞，其中需用到如下算法
//以lld数组为例，int的手法完全类似
//化为升序

int n;
scanf("%d", &n);
long long arr[n];//一个（关乎具体输入情境的）声明与准备

for (int i = 0; i < n; i++)
{  
    scanf("%lld", &arr[i]);  
}                                           //读入一列整数（如1 6 5 2 2 3 8 4 7 4 4 9）
/*此即输入12 1 6 5 2 2 3 8 4 7 4 4 9*/

for (int i = 0; i < n; i++) {printf("%lld ", arr[i]);}                                           //打印一下，有：1 6 5 2 2 3 8 4 7 4 4 9

//bubble的核心部分，以下
for (int i = 0; i < n - 1; i++) {                   //重复遍历序列n-1次
    for (int j = 0; j < n - 1 - i; j++) {           //【1】
        if (arr[j] > arr[j + 1]) {                  //依次比较相邻数对，降序则互换，升序则不变
        long long temp = arr[j];                    
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }  
    }  
}
//以上
/*【1】
显然，第一次外层循环会使整个序列的最大值max1冒泡到末位，第二次外层循环会使除去max1的整个序列的最大值max2冒泡到次末位，依此类推
n-1次循环就能完成n元序列的排序
然而，若内层循环每次都从0遍历到n-1-1(共n-1次)，则队尾已排好的诸多max将被进行不必要的无效比较，为此
被比较的数对从(0, 1)到(n-1-i-1, n-1-i)，每次少比较一个数
*/

//清楚原理后，我们完全可以将上面的代码改写得更具可读性(若能清晰地理解，上面的代码也是易读的，甚至更推荐)

for (int i = 1; i <= n - 1; i++) {                   //重复遍历序列n-1次
    for (int j = 0; j <= (n - 2) - (i - 1); j++) {     //第一次循环的终点是(n-2, n-1)，(i - 1)应从0开始参与循环
        if (arr[j] > arr[j + 1]) {                   
        long long temp = arr[j];                    
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }  
    }  
}

//然而，这个算法仍可优化，即当某次外循环后，排序已经完成，就完全不必进行余下的循环

for (int i = 1; i <= n - 1; i++) {                   //重复遍历序列n-1次(第i次)
    int swapped = 0;                                 //检测一次外循环中是否发生交换动作
    for (int j = 0; j <= (n - 2) - (i - 1); j++) {     //第一次循环的终点是(n-2, n-1)
        if (arr[j] > arr[j + 1]) {                   
        long long temp = arr[j];                    
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            swapped = 1;
        }  
    
    }  
    if (swapped == 0) {break;}
}
//至此，我们通过约束内外双循环的次数，提高了程序的效率
printf("\n");
//打印一下
for (int i = 0; i < n; i++) {printf("%lld ", arr[i]);}
//关于快速排序(Quick Sort) 见后



printf("\n");
//在早期标准中，for循环语句中不能声明变量，要在此前声明（但我们使用的标准是支持的）

//随机数的生成
/*int ra = rand();
printf("%d", ra);//每次生成的数是一样的 41 41 41 ... 若要解决这个问题，考虑*/
srand(time(0));//srand用于设置生成随机数的种子 time(0)返回当前时间戳 时间戳是指从1970年1月1日（通用协调时间，UTC）00:00:00起至现在的总秒数
int ra = rand();
printf("%d\n", ra);//7354 7488 7579 ...(可生成不同的随机数，但仍与时间强相关)
//若要生成0~99 1~100的随机数，考虑
int ra1 = rand()%100; int ra2 = rand()%100 + 1;
//rand()返回整型的伪随机数

//著名的 猜数游戏
/*
srand(time(0));
int num = rand()%100 + 1;
    printf("请输入你猜的数(1~100)\n");
    for (int n; scanf("%d", &n)!=EOF;) {
        if (n > num) {
            printf("猜大了\n");
        } else if (n < num) {
            printf("猜小了\n");
        } else {
            printf("猜中了，下一轮游戏开始\n");
            num = rand()%100 + 1;
        }
    }
*/

//一些注记    A

//01 若约定 0 to finish 可用while (scanf(...)!=0)读入
//02 scanf("%d", &num) && num!=0 等价于 scanf("%d", &num), num != 0
//03 while/for是先验的，可能执行0次；do-while是后验的，至少执行一次
//04 break/continue只对本层循环生效
/*05 CONTINUE 对于for 跳过循环体其余语句，转向循环变量增量表达式的计算
对于while/do-while 跳过循环体其余语句，转向循环继续条件的判定*/

//06 goto

/*
goto是一个控制流语句，实现任意位点无条件跳转
语法：
goto label;
...
label://目标位点
e.g.
#include <stdio.h>
int main()
{
printf("1\n");
printf("2\n");
for (int i = 5; i <= 10; i++) {
    if (i == 7) {
        goto lb01;
    }
    printf("i\n");
}
lb01:
printf("999\n");
printf("a\n");
printf("b\n");
return 0;
}

输出
1
2
5
6
999
a
b

然而，若在return 0;之前加上
lb02:
printf("c\n");
goto lb02;
程序的行为似乎是无限打印c
而这段程序单独运行的结果当然也是无限打印c

p.s.
【1】无论在命令行还是在vscode 我们都可以输入Ctrl+C来终止程序的运行
【2】ATTENTION 务必慎用goto 或者说应当尽量避免用goto

*/

//07 break 用于循环/switch    continue 只用于循环
//08 while(1) 无限循环
/*09 一行输出5个数的输出方法参考
int count = 1;
for (int i = 1; i <= 30; i+=2) {
    printf("%d", i);
    printf("%c", count%5 ? ' ' : '\n');
    count++;
}
非5个，输出空格    5个，输出空行    效果如下
1 3 5 7 9
11 13 15 17 19
21 23 25 27 29
考虑 printf("%-2d", i) 就有
1  3  5  7  9 
11 13 15 17 19
21 23 25 27 29
*/

/*
10 素数(Prime number)判定

首先，说明
int p = 2;
printf("%lf", sqrt(p));
将输出
1.414214 而非 1.000000

其次，考虑
int num;
bool isPrime = true;
scanf("%d", &num);
if (num <= 1) {
    isPrime = false;
} else {
    for (int i = 2; i <= sqrt(num) ; i++)       //试验证<=sqrt(num)的合理性和优越性
    {
        if (num % i == 0)
        {
            isPrime = false;
            break;
        }
        
    }
    
}
if (isPrime) {
    printf("prime");
} else {
    printf("not prime");
}
*/



//一些注记    B

//部分语法的预先讨论

//参见draft-04    PRE-dft03



//浮点型判等
/*不推荐
double a0 = 5, b0 = 5;
if (a0 == b0)
{
    printf("0");
}//0
*/
/*推荐
#include <stdio.h>
#include <math.h>
#define EPSILON 1e-6
int main()
{
float a = 5, b = 5;
if (fabs(a - b) < EPSILON)
{
    printf("0");
}
return 0;
}//0
*/

//isupper / islower   in <ctype.h>
printf("%d", isupper('A'));
printf("%d", isupper('C'));
printf("%d", isupper('b'));
printf("%d", isupper('d'));//1100
printf("%d", islower('A'));
printf("%d", islower('C'));
printf("%d", islower('b'));
printf("%d", islower('d'));
printf("%d", islower('i'));
printf("%d", islower('o'));//002222【注意这里返回的不是1而是另一个非零值2】

//Several examples of UB

/*
int count = 0;
count = count++;
printf("%d", count);//0 其他环境下可能为1 这是UB

int c = 0;
printf("%d%d%d", c++, c++, c++);//210 这也是UB
*/

//赋值号从右向左结合
/*
譬如
int a, b;
b = a = 1;
是合法的，相当于a = 1; b = a;
*/

//exit(0)
//exit(0)结束所有线程，终止整个程序（不是返回调用它的函数，而是直接终止整个程序）
printf("999");//999
exit(0);
printf("999");//Null
return 0;
}