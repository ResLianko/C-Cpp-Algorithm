//Chapter 7

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct Asd
{
    int asd;
    long long aasd;
} Asd;

typedef struct Qwe
{
    int qwe;
    char qqwe;
    Asd qqqwe;
} Qwe;

int main()
{
//Examples of UB / not UB

//-a---b
//experiments
int a = 1, b = 2;
printf("%d %d %d\n", a, b, -a---b);
//在我的环境下，结果是0 2 -3  而非  1 1 -2，这表明其被解释为-(a--)-b而非-a-(--b)
//但这恐怕是UB

//x += 5 == 4    这并不是UB
/*
==优先级高于赋值（含+=），故原式即 x += 0 即 x 不变
*/
//test
int x = 100;
int y = 100;
printf("%d\n", x += 5 == 4);//100
printf("%d\n", y += 5 == 5);//101
//统计数组A中的1的个数
int A[5] = {1, 1, 2, 3, 4};
int cnt = 0;
for (int i = 0; i < 5; i++)
{
    cnt += A[i] == 1;
}
printf("%d\n", cnt);//2

//下例毫无疑问是UB
/*int t = 0;
printf("%d\n", ++t--);*/

int m = 5;
//printf("%d\n", m+++++m);  【编译不通过 / UB】
printf("%d\n", m++ + ++m);//12  【 not UB / 5 + 7 = 12 】
printf("%d\n", m);//7
m = 5;
m = m++ + ++m;
printf("%d\n", m);//12
m = 5;
m += m++ + ++m;              //居然并非UB
printf("%d\n", m);//19
//【5 + 7 + (7:现在的m) = 19】



//利用指针为一维数组赋值
/*
Solution 1

int a[5];
int *p;
for ( p = a; p < a + 5; p++)
{
    scanf("%d", p);
}
for (int i = 0; i < 5; i++)
{
    printf("%d ", a[i]);
}

//int scanf(const char *format, ...);
//上面的指针 p 已经是地址了，这与之前我们常用的 &n 性质相同

Solution 2

int b[5];
for (int i = 0; i < 5; i++)
{
    scanf("%d", b + i);
}
for (int i = 0; i < 5; i++)
{
    printf("%d ", b[i]);
}
*/

//const char* a = "like you";  char型的常量数组 ~ 1个指针 ~ 1个字符串
//const char* a[] = {"like you", "hate you", "you"};  【1】
/*【1】
这是一个指针数组 其中每一个元素都是指向常量字符的指针，都可以指向一个字符串字面量或char数组
*/

//对于自定义函数，return语句一旦执行，函数就退出，不必担心所谓的多次return
//这可以简化地实现类似if-else的逻辑
/*例如
int myFunc(...){
    (code...)
    if (...) 
        return 1;
    return 0;
}*/

//一般而言，&a不作左值，不能被赋值



//字符相关注记
printf("\n===Remarks(char)===\n");

//我们提过，对于单字节编码（如ASCII）每个字符占用1个字节
char *str01 = "abcde";
printf("%d\n", strlen(str01));//5
printf("%d\n", sizeof(str01));//8  (str01指针)

//char s[] = {'a', 'b', 'c', '\0'}; 即 char s[] = "abc";【1】

char *str02 = "abc";//这种声明方式的缺陷在于无法利用str02指针修改string
printf("%s\n", str02);//abc
/*
*(str02 + 1) = 'p';//【ERROR】Segmentation fault
在 C 语言中，字符串字面量通常存储在只读内存段中。尝试【修改】这些内存区域的内容是非法操作，操作系统通常会阻止这种访问并导致程序崩溃。
*/
printf("%c\n", *(str02 + 1));//b
printf("%s\n", str02 + 1);//bc
//访问是可以的

//【1】方法，可以修改
char str03[] = "qwe111";
printf("%s\n", str03);//qwe111
*(str03 + 1) = 'p';
printf("%s\n", str03);//qpe111

printf("%d %d\n", strlen(str03), strlen(str03 + 3));//6 3【从第四个字符开始的子串】

//字符串数组（注意不是字符数组）
char *strgroup[3] = {"abc", "def", "ghi"};
    for (int i = 0; i < 3; i++) {
        printf("%s\n", strgroup[i]);
    }
//或者
char strgroup1[3][4] = {"abc", "def", "ghi"};//预留了'\0'的位置

//转义再论
printf("转义\n");

//"\\\\"共两个char
printf("%d\n", strlen("\\\\"));//2
printf("\\");//【\】
printf("\n");
printf("\\\\");//【\\】
//printf("\");报错
//printf("\\\");报错

printf("\n");

printf("===转义序列(escape sequences)===\n");
/*
\a  Alert(bell)【生成一个响铃信号】
\n  Newline
\t  Tab 水平制表符
\b  Backspace【光标退回一位】
\r  Carriage return【光标回到当前行开头】
\f  Form feed【换页 / 清屏】
\\  Backslash【反斜杠（本身）】
\"  "(double quotation mark)
\'  '(single quotation mark)
\0  Null
\ddd    octal(八进制)
\xdd    hexadecimal(十六进制)
*/
//printf("\a");     可能有蜂鸣或其他声光（但在我的环境下没什么反应）
printf("123\b456\n");
printf("123\r456\n");
/*
12456
456
*/

printf("===文件打开模式(file modes)===\n");
/*  
FILE *__cdecl fopen(const char * __restrict__ _Filename,const char * __restrict__ _Mode) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

FILE *fp;
fp = fopen("...", "...");
*/
/*
"r"     【只读】            必须已存在，否则指向NULL
"w"     【写入】            若已存在，清空（或言替换）再写入；若不存在，生成新的【只写】
"a"     【追加】            若已存在，添加到末尾（不覆盖原有内容）；若不存在，生成新的

"r+"    【读写】            必须已存在，否则指向NULL
"w+"    【读写】            若已存在，清空（或言替换）；若不存在，生成新的
"a+"    【读写追加          若已存在，添加到末尾（不覆盖原有内容）；若不存在，生成新的

"rb"    【二进制只读】
"wb"    【二进制写入】
"ab"    【二进制追加】
"rb+"   【二进制读写】
"wb+"   【二进制读写】
"ab+"   【二进制读写追加】
*/
//一般来说，可以用二进制模式打开文本文件，但不建议用文本模式打开二进制文件


//注记
printf("\n===Re===\n");

//【c = *p++】自增更优先，同时，考虑到后缀自增的意义，这表示复制*p的值给c再执行p++

//a[i][j]的值 ~ a[i][j] ~ *(a[i]+j) ~ *(*(a+i)+j)
//a[i][j]的地址 ~ &a[i][j] ~ a[i]+j ~ *(a+i)+j

//字典序(依ASCII / 长度 / 从前往后逐个比较)
//APP < app < apple < beta, beta > banana
//从前往后，但凡有相异字符，就依ASCII得结论 / 若直至一方结束，都相同，则短者更小，更靠前 / 若全同，等长，则相等
printf("（字典序）下面验证：");
//strcmp 函数的参数可以是字面量
printf("%d %d %d %d\n", strcmp("APP", "app"), strcmp("app", "apple"), strcmp("apple", "beta"), strcmp("beta", "banana"));
//-1 -1 -1 1

//【打表】 【查表】可以避免重复计算，节省时间

/*一个关于类型和输出的例子
double a = 2.123;
double b = 2.999;
int p = a;
printf("%lf", a);//2.1230000
printf("%d\n", p);//无输出
printf("%d\n", (int)a);//2
printf("%d\n", (int)b);//2

用int保存double字面量，不会报错，也不会截断，而是导致某些异常，比如无法输出
用(int)转换double字面量，会截断（而非四舍五入）
*/

//函数可以在main外定义并在main内声明，但【不推荐】这样做

//二维数组作函数参数
/*
声明方式01  e.g.
void myFunc2D(int array[][COLS], int rows){
...(函数体)
}
行数可以可变，列数必须在编译时已知
COLS是列数 rows是运行时指定的行数

声明方式02  e.g.
void func2D(int (*array)[COLS], int rows){
...(函数体)
}
int (*array)[COLS]是一个指向【包含COLS（列数，即每行的元素个数）个整数的一维数组】的指针

声明方式03  e.g.
#include <stdio.h>
    float sum(float **p, int m, int n){
    float s = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; i < n; j++)
        {
            s += p[i][j];
            return s;
        }
        
    }
    
}
int main()
{
...(初始化数组)
float a[5][6], *b[5];//【 float *b[5]; 】声明了一个包含5个元素的数组b，每个元素都是一个指向float类型的指针
for (int i = 0; i < 5; i++)
{
    b[i] = a[i];  b[i]指向二维数组第i+1行(i号行)首地址
}
printf("%f\n", sum(b, 5, 6));
}
（将二维数组视为一维数组的数组）

调用的方法是一致的
myFunc2D(myArray, ROWS);
即 设计函数时，行数往往作为函数的另一个参数
*/



//关于结构体的一些补充

/*01
补充说明一下，下面这种写法是合法的
stuct student {
...
...
...
} xiaoming, abc, arr[30], *ptr;
*/

//02结构体嵌套
//【C语言】的标准不允许在结构体定义内部直接初始化成员变量。初始化通常是在创建结构体实例时进行的，而不是在定义结构体类型时。
    // 创建结构体实例并初始化
    Asd myAsd = {123, 0}; // 初始化asd为123，aasd为0（或省略0，aasd将是未初始化的）
    Qwe myQwe = {987, 'a', {1234, 0}}; // 初始化qwe为987，qqwe为'a'，qqqwe为{1234, 0}【注意这种初始化方式】
 
    // 打印以验证初始化
    printf("Asd.asd: %d\n", myAsd.asd);//123
    printf("Qwe.qwe: %d\n", myQwe.qwe);//987
    printf("Qwe.qqwe: %c\n", myQwe.qqwe);//a
    printf("Qwe.qqqwe.asd: %d\n", myQwe.qqqwe.asd);//1234【嵌套结构体的访问】

//03利用花括号初始化结构体数组
/*
#include <stdio.h>

struct campus {
double area;
int students;
char name[50];
};

int main()
{
struct campus univ[3] = 
{
    {414, 3000, "朝晖"}, 
    {2150, 15000, "屏峰"}, 
    {990, 5000, "莫干山"}
};

printf("%lf %s\n", univ[1].area, univ[1].name);//2150.000000 屏峰

return 0;
}
*/

//04 成员运算符【 . 】【 -> 】优先级相当高，高于自增，也高于解引用算符【 * 】，几乎与括号同级

//05 这种写法也是合法的
//与上面的例子不同，该例在main函数内声明并初始化结构体实例
struct T1
{
    char c[4], *s;
} s1 = {"abc", "def"};



//fgetc 用于从文件流中读取一个字符 fgetc is in the <stdio.h> header file
//int fgetc(FILE *stream); 成功，返回字符的整型表示 失败 或 到达文件末尾，返回EOF

//fputs 将一个字符串写入文件流
//int fputs(const char *s, FILE *stream); 成功返回0，失败返回EOF



//【位运算】：直接对整数在内存中的二进制位进行操作
printf("\n=====位运算=====\n");

//01 按位与AND 【 & 】------位与
//两个相应二进制位都为1时，结果才为1，否则为0
/*
3 ~ 0011
5 ~ 0101
3 & 5 = 0001【即十进制的1】
*/
printf("%d\n", 3 & 5);//1

//02 按位或OR 【 | 】------位或
//相应地，有一个为1，结果就为1
/*
3 | 5 = 0111【7】
*/
printf("%d\n", 3 | 5);//7

//03 按位异或XOR 【 ^ 】------异或
//相应地，相异取1，相同取0（这一点和strcmp很相似）
/*
3 ^ 5 = 0110【6】
*/
printf("%d\n", 3 ^ 5);//6

//04 按位取反NOT 【 ~ 】
// 0 1 互换

//05 左移 【 << 】
//左移一位相当于原数乘以2    a << b = a x 2^b
printf("%d\n", 3 << 2);//12

//06 右移 【 >> 】
//右移一位相当于原数除以2向下取整    a >> b ~ a / (2^b)
printf("%d\n", 100 >> 3);//12

//移位运算符优先级低于减法 【 [(1 << 8) - 1] = [1 x (2^8) - 1] 】



//宏定义再谈
printf("\n===宏定义(macro definition)===\n");
//宏定义是一种预处理指令，用于在编译之前对代码进行文本替换

/*e.g.
#define PI 3.14159
#define N 100010
#define ERROR_MESSAGE "An error has occurred!"
注意，C语言中，宏名(Macro Name)必须是标识符(identifier)，符合标识符命名规范
譬如 #define 猫猫 "cat" 就是非法的，gcc编译器会明确指出macro names must be identifiers
*/

//带参数的宏
/*
所谓带参宏，有些类似函数，但本质上仍然是单纯的文本替换，很快我们将看到这一点
*/
/*
#define SQUARE(x) x * x
容易验证SQUARE(2) = 4

然而
4 / SQUARE(2)并非1，其值为4
正如我们先前所言，4 / SQUARE(2)相当于4 / 2 * 2 ( == 4 )
所以，更推荐的写法一定是#define SQUARE(x) (x * x)
此时，4 / SQUARE(2) = 1
*/



//文件杂例
/*
...
FILE *fp;
fp = fopen("e:\\digit.txt", "r");//绝对路径，其中，\\表示\
    if (fp == NULL)
    {
        printf("打开失败\n");
        exit(1);
    }
...
fclose(fp);

FILE *fp1;
fp1 = fopen("e:\\count.txt", "w");
    if (fp1 == NULL)
    {
        printf("打开失败\n");
        exit(1);
    }
...
fclose(fp1);
...
*/

printf("\n===Remarks===\n");
//'\007'是八进制转义序列，即警报字符\a  （本章提过\ddd    octal(八进制)）
//char *n[]【n是数组，元素是指向char的指针，C串（作为字符数组）是一种广义的指针，因此n常用于存储多个字符串】
char *arrN[3] = {"qwe", "asd", "zxc"};
printf("%s\n", arrN[2]);//zxc
printf("%s", arrN[0]);
printf("%s", arrN[1]);//顺便，我们验证了一下printf%s输出字符串不会自动加\n



printf("\n=====array=====\n");
/*数组杂例
int a[3][4];
a[1][3]当然表示2行4列值，*(*a+3)表示1行4列值（  *(*(a+0)+3)  ）
*a[1]，表示2行1列值（  a[1]表示2行（是指向a[1][0]的指针）  ）
*a是第一行的行指针，指向a[0][0]的指针
*a + 3表示上述指针向后移动3个元素（整数 / 单位），即指向a[0][3]的指针
这是一次解引用，再解引用一次就得到值
*/
int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
printf("%p\n", &arr[1][0]);//000000000061FD0C
printf("%p\n", arr[1]);//000000000061FD0C

//a[3] ~ 3[a]
int p[] = {1, 2, 3, 114514, 1919810};
printf("%d\n", p[3]);//114514
printf("%d\n", 3[p]);//114514
printf("%d %d %d\n", 0[p], 4[p], p[4]);//1 1919810 1919810
/*
这本质上是因为 a[i] 是 *(a + i) 的语法糖，前者会被解释为后者
a[i] = *(a + i) = *(i + a) = i[a]
也就是说a[i] = *(a + i)
i[a] = *(i + a)
而由交换性，RHS1 = RHS2
*/
return 0;
}