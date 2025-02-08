//Chapter 6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool hasSuffix(const char *str, const char *suffix){
    if (!str || !suffix)//这种写法或许应当慎用
    {
        return false;
    }//若二者有为空的，打成false
    size_t str_len = strlen(str);
    size_t suffix_len = strlen(suffix);
    if (suffix_len > str_len)
    {
        return false;
    }//若后缀长于被检字符串，打成false
    
    return strncmp(str + str_len - suffix_len, suffix, suffix_len) == 0;
    /*
    譬如 "abcdefghij"  (10)    查找后缀 "hij"  (3)
    str ~ to【第1个字符】
    str + str_len ~ to【\0】【第 N + 1】【第11】
    str + str_len - suffix_len ~ to【suffix开始处】【第8】
    */ 
}

int count(const char *haystack, const char *needle){
    int count = 0;
    const char *p;
    size_t needle_len = strlen(needle);

    if (needle_len == 0)//needle为空
    {
        return 0;
    }

    p = haystack;

    while (strstr(p, needle) != NULL)
    {
        p = strstr(p, needle) + needle_len;//【移动指针】 跳过刚找到的子串
        count++;
    }

    return count;
}

void to_uppercase(char *s){
    while (*s)
    {
        *s = toupper((unsigned char)*s);
        s++;
    }
}
/*
A T T E N T I O N ! ! ! 
这里 *s = ... / s++ 可以看作【取】字符串中的某个字符并作修改，【并不是】截断前文而成为新的字符串
s++ 起遍历字符串的作用，但它并不会截断字符串或改变字符串的原始内存布局
C串的数组名（在这个例子中是 s）实际上是一个指向字符串首字符的指针。
当执行 s++ 时，指针 s 会递增，指向字符串中的下一个字符  这仅仅改变了指针 s 的值（即它指向的内存地址），而不影响字符串本身或字符串中任何字符的值
*/
/*
s++之后，s不再是指向字符数组首元素的指针，也不再具备数组名的属性
s 在这里已经指向了字符串的末尾（'\0'），但不需要手动将其重置回原位置
因为打印操作使用的是原始的数组名或指针（在 main 函数中（strup）），而不是这个已递增的指针
*/

int main()
{

//【go_char】Golang与字符相关的查找

/*
我们知道，在【Golang】语言中，存在一些【在工程上】十分方便的字符串相关的【查找】类函数
然而，作为更底层，更接近硬件的语言，C并不直接提供那些函数
下面，我们将使用C，尝试模拟那些函数的功能
*/

//01 前缀查找 hasPrefix

const char *str01 = "hello world";
const char *prefix01 = "he";
const char *prefix02 = "she";

size_t prefix01_len = strlen(prefix01);
size_t prefix02_len = strlen(prefix02);

if (strncmp(str01, prefix01, prefix01_len) == 0)
{
    printf("T\n");
} else {
    printf("F\n");
}                                                        //T

if (strncmp(str01, prefix02, prefix02_len) == 0)
{
    printf("T\n");
} else {
    printf("F\n");
}                                                        //F

//进一步，不难知道 可以是全文，但不能是中部子串

const char *prefix03 = "hello world";
const char *prefix04 = "llo";
if (strncmp(str01, prefix03, strlen(prefix03)) == 0)
{
    printf("T\n");
} else {
    printf("F\n");
}                                                        //T
if (strncmp(str01, prefix04, strlen(prefix04)) == 0)
{
    printf("T\n");
} else {
    printf("F\n");
}                                                        //F

//02 后缀查找 hasSuffix
//见上面main外的函数
char *str02 = "qwertyuio";
char *suffix01 = "uio";
char *suffix02 = "abc";
printf("%d\n", hasSuffix(str02, suffix01));//1
printf("%d\n", hasSuffix(str02, suffix02));//0
//这里用整型形式打印了bool变量

//03 包含 contain
//相当于子串查找，这在C中倒是有较为直接的实现，即
//strstr 函数
//char *strstr(const char *haystack, const char *needle);
//haystack（干草堆） ~ 主字符串
//needle（针） ~ 子字符串
//有，返回第一次出现的指针    无，返回NULL
    const char *mainStr = "abcdefghijklmn";
    const char *subStr = "efg";
    char *result = strstr(mainStr, subStr);
    if (result) {
        printf("Substring '%s' is found in '%s' at position %ld.\n", subStr, mainStr, result - mainStr);
    } else {
        printf("Substring '%s' is not found in '%s'.\n", subStr, mainStr);
    }
//Substring 'efg' is found in 'abcdefghijklmn' at position 4.

//04 索引 index
//这已经在03中实现过了 ( result - mainStr )

//05 计数 count
//函数见上
char *strMain = "Sayonara, su be te no EVANGELION.";
char *strSub01 = "hello";//0
char *strSub02 = "EVA";//1
char *strSub03 = "eva";//0  表明大小写敏感
char *strSub04 = "a";//3
printf("%d %d %d %d\n", count(strMain, strSub01), count(strMain, strSub02), count(strMain, strSub03), count(strMain, strSub04));

//06 全大写 / 全小写

//06-01 单个字母
//在<ctype.h>中有现成的函数
//int toupper(int c);    int tolower(int c);
//toupper函数返回转换后的字符，但它不会直接修改传入的字符，故有时需要将toupper的返回值重新赋值给相应的字符变量
//若要自行实现，考虑
/*
char myUpper(char c){
    if (c >= 'a' && c <= 'z')
    {
        return c - ('A' - 'a');
    }
}
*/

//06-02 整个字符串
//函数见上
char strup[] = "Hello World";
printf("Original:%s\n", strup);
to_uppercase(strup);
printf("Upper:%s\n", strup);
/*
Original:Hello World
Upper:HELLO WORLD
*/

//p.s.    size_t    typedef unsigned long long size_t

//另外几点拓展

//01    scanf_s : scanf的更安全版本 

//是C11标准的一部分 但不是C语言标准库的一部分 特定于某些编译器的实现【譬如我此时的环境就不支持scanf_s】
//指定缓冲区最大长度 防止【缓冲区溢出】
//int scanf_s(const char *format, ...);
//通常在<stdio.h>或<cstdio>中
/*
int num;
char str[100];
scanf_s("%d %99s", &num, str, (unsigned)_countof(str));
//_countof是一个宏，接收一个数组作为参数，并返回该数组中元素的数量
*/
/*
缓冲区(Buffer) 用于临时存储数据的一块连续内存区域
缓冲区溢出(Buffer Overflow) 程序向缓冲区写入的数据超出缓冲区预定容量，使程序易于崩溃或受攻击
*/

//02    strcmp的实现
//上面我们考虑了若干函数的底层，其中多有用到strcmp 进一步，strcmp如何用简单地用C实现
/*
int strcmp(const char *str1, const char *str1){
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return (unsigned char)(*str1) - (unsigned char)(*str2);
}
*/

//03    中文字符串的比较
printf("\nCN\n");

char *strcn01 = "你好，世界！";
char *strcn02 = "你好，世界！";
char *strcn03 = "你好，小猫！";

if (strcmp(strcn01, strcn02) == 0)
{
    printf("equal.\n");
} else {
    printf("not equal.\n");
}

if (strcmp(strcn01, strcn03) == 0)
{
    printf("equal.\n");
} else {
    printf("not equal.\n");
}



//一些注明
printf("\n===== Remarks =====\n");
//字符串中  中文  一个汉字记 3 位

/*事实上
对于单字节编码（如ASCII）每个字符占用1个字节 因此 `strlen` 返回的结果就是字符的数量
但是，对于多字节编码
在UTF-8编码下，一个汉字通常占用3个字节（对于现代汉语中的常用汉字某些不常用的 / 新添加的Unicode字符可能会占用4个字节）
在GBK编码下，一个汉字占用2个字节
使用 `strlen` 来计算包含汉字的字符串长度，在UTF-8编码中，`strlen` 将返回汉字所占的总字节数而不是字符数
*/

char *str0001 = "abcde";
printf("%d\n", strlen(str0001));//5

char *str0002 = "中国";
printf("%d\n", strlen(str0002));//6

//字符串末尾有多个空格的情形
char *str0003 = "abc      ";//abc+【6个space】
printf("%d\n", strlen(str0003));//9
printf("%s%s\n", str0003, str0001);//abc      abcde
//注意【空格】（\32）不等于【空字符】（\0）



//我宣布她的宣布有效：一个先分析后输出的练习
/*
#include <stdio.h>

void wxb(void){
    printf("我宣布");
}
void nxb(void){
    printf("你宣布");
}
void effective(void){
    printf("的宣布有效");
}
void her(void){
    printf("她的宣布有效");
}

int main()
{
for (int i = 1; i <= 100; i++)
{
    if (i % 2 == 0)
    {
        printf("B: ");
        for (int j = 1; j <= i; j++)
        {
            if (j % 2 == 0)
            {
                nxb();
            } else {
                wxb();
            }
        }
        her();
        for (int j = 1; j <= i - 1; j++)
        {
            effective();
        }
        printf("\n");
    } else {
        printf("A: ");
        for (int j = 1; j <= i; j++)
        {
            if (j % 2 == 0)
            {
                nxb();
            } else {
                wxb();
            }
        }
        her();
        for (int j = 1; j <= i - 1; j++)
        {
            effective();
        }
        printf("\n");
    }
}
return 0;
}
*/
/*
A: 我宣布她的宣布有效
B: 我宣布你宣布她的宣布有效的宣布有效
A: 我宣布你宣布我宣布她的宣布有效的宣布有效的宣布有效
B: 我宣布你宣布我宣布你宣布她的宣布有效的宣布有效的宣布有效的宣布有效
A: 我宣布你宣布我宣布你宣布我宣布她的宣布有效的宣布有效的宣布有效的宣布有效的宣布有效
B: 我宣布你宣布我宣布你宣布我宣布你宣布她的宣布有效的宣布有效的宣布有效的宣布有效的宣布有效的宣布有效
A: 我宣布你宣布我宣布你宣布我宣布你宣布我宣布她的宣布有效的宣布有效的宣布有效的宣布有效的宣布有效的宣布有效的宣布有效
B: 我宣布你宣布我宣布你宣布我宣布你宣布我宣布你宣布她的宣布有效的宣布有效的宣布有效的宣布有效的宣布有效的宣布有效的宣布有效的宣布有效
......
*/



//alloc 分配内存                             (allocate 分配)
//#include <stdlib.h>

//malloc    (memory allocation)    ------“向系统要空间”
//void *malloc(unsigned int size)    /    ...size_t size
//或void * malloc(unsigned int size) 这里空格是无关紧要的【1】
//T* p = (T*) malloc(size)

//free
//void free(void *p)
//free(p)

//考虑

printf("Enter 5.\n");

int num;
int *a;
scanf("%d", &num);
//int a[num];(使用 VLA ( C99 及以后) )
//在C99之前，我们考虑如下方案
a = (int*)malloc(num * sizeof(int));//此时a就相当于数组，可以当数组用
//(code...)
free(a);

//若malloc申请内存失败（比如内存用完了），返回NULL（或说0）
/*
int *ptr01;
int cnt = 0;
while (ptr01 = malloc(100 * 1024 * 1024))
{
    cnt++;
}
printf("分配了%d00MB的空间\n", cnt);//分配了57000MB的空间
*/
/*
只能归还申请来的空间的首地址
譬如p，p++若干次，free的时候不能直接free(p)
*/
/*
我们推荐定义指针时就初始化为零值(e.g.    void *p = 0;)
因为free(NULL)总是合法而不报错的
*/
//但凡malloc 我们就推荐务必在合适的时机进行free    注意 重复free也会导致崩溃
/*
即使malloc而不free 程序结束时上述空间也会被释放
但不free仍然是一个坏习惯，对于小型程序无伤大雅，对于大型程序可能危害巨大
*/

/*
【int *ptr】【int * ptr】【int* ptr】【int*ptr】是等价的表达
我们统一采取并推荐第一种写法，同时不建议使用第四种写法
*/

//很自然地
//  int *px = &x, x;不合法
    int x, *px = &x;//合法

//p1, p2是同类型指针
//p2 = p1;  即  p2 = *&p1;

/*a[3][5];
表达式 a[0] 实际上是指向数组第一行（即包含元素 a[0][0] 到 a[0][4] 的行）的指针
a[0]可以被看作是指向 a[0][0] 的指针，但由于它是一个数组（尽管在这里我们通过指针的视角来看它），它实际上“指向”的是整行。
当我们在 a[0] 后面加上一个整数，比如 3，我们实际上是在进行指针算术运算
因此 a[0] + 3 指向 a[0] 行中第四个元素的地址（即 &a[0][3]）  注意，这里得到的是一个指向 int 的指针，而不是一个 int 值。



//appendix
printf("\n=== Appendix ===\n");
//int x, *p = &a;    声明整型变量x但不初始化    声明并初始化整型指针p为a的地址

//相对于Cpp，C中的字符串（事实上是字符数组）称 C串

//*p++ / "++" 优先级更高    即*(p++)    而非 (*p)++

//若不小心删去了一段代码，可以使用【Ctrl+Z】予以恢复（可以多次使用）

//a>b?a<c?a:b:c; 【=】 if (a > b) {if (a < c) a else b} else c

//常量指针 Constant pointer
//指针常量【指向常量的指针】 Pointer to a constant//有时依赖于翻译
/*
const int *pA = &a;  指向常量的指针 指针指向的值不可被修改 但指针本身的值可以被修改，从而指向其他的值
int * const pB = &b;  常量指针 指针指向的值可以被修改 但指针本身的值(存储的地址)不可被修改
上面我们多次使用的const char *strxxx = "...";就服从这里的原则
*/
const int a1 = 1;
const int a2 = 2;
int a3 = 3;

const int *pA1 = &a1;
//a1 = 9;报错
pA1 = &a2;//不报错

int * const pA3 = &a3;
//pA3 = &a1;报错
*pA3 = 8;//不报错

//关注const与何者更近    【注意，这只是一个粗浅的判别法！】
//与【类型】更近，表明被指者是常量 / 与【指针】更近，表明指针是常量

//计算机内存中，局部变量在栈区，malloc动态分配的数据在堆区

//指针【很多时候】是8字节的

//几个<ctype.h>中的函数
printf("\n 【type】 \n");

//isalpha(int c) 是否为字母
printf("%d\n", isalpha('A'));//1
printf("%d\n", isalpha('a'));//2
printf("%d\n", isalpha('k'));//2
printf("%d\n", isalpha('P'));//1
printf("%d\n", isalpha('1'));//0
//若是，返回非零值，一般是1
//由上可见，大写~1，小写~2（这可能与环境有关），非字母~0

//isdigit(int c) 是否为数字（0~9）
printf("%d %d\n", isdigit('3'), isdigit('p'));//1 0

//isprint 是否可打印
//可见字符可打印  空格可打印  控制字符（换行 回车 ...）不可打印
printf("%d %d %d", isprint('a'), isprint(' '), isprint('\n'));//2 64 0 
//可见，虽然不是【1】【1】【0】，但至少是【非0】【非0】【0】

//关于  UVa401  回文串与镜像串

/*
01  回文与镜像既不充分也不必要
AEOEA 回文不镜像 / AEO3A 镜像不回文
())( 回文不镜像 / (()) 镜像不回文

02  一个有二进制（binary）味道的映射
 p  m
(0, 0) ~ 0
(1, 0) ~ 1
(0, 1) ~ 2
(1, 1) ~ 3
【p + m * 2】
即
 m  p
(0, 0) ~ 0
(0, 1) ~ 1
(1, 0) ~ 2
(1, 1) ~ 3
【m * 2 + p】
*/

//lvalue(左值)可以被赋值 / rvalue(右值)不能被赋值

//数组可以保存结构体，其排序也可以使用Bubble Sort，此时临时变量是结构体

//gets与fgets【<stdio.h>】
//gets()  不安全 在C11标准中已经被废止  char *gets(char *str);
//fgets()  char *fgets(char *str, int num, FILE *stream); 
//【e.g.】fgets(p[i].name, sizeof(p[i].name), stdin);
//【e.g.】fgets(buf, maxn, fin);
/*【scanf】读入字符串，【空格】 / 【换行】 / 【tab】会作为结束标记  这个问题就要靠 gets / fgets / gets_s 解决*/

//puts【<stdio.h>】
//int puts(const char *str);  末尾自动换行


//kase 一般表示 case （case是C关键字 故用kase 多考虑初始化为0 作编号使用时写++kase）

return 0;

}

