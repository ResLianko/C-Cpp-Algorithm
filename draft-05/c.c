//Chapter 5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define N 5

int maxInArray(int a[], int n){    //n是长度
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

int findMid(int a, int b, int c){
    if ((a <= b) && (b <= c) || (c <= b) && (b <= a)) {
        return b;
    } else if ((a <= c) && (c <= b) || (b <= c) && (c <= a)) {
        return c;
    } else {
        return a;
    }
}

int main()
{

//存储类型
//auto 自动型（默认）    static 静态型   Register 寄存器型    extern 外部参照型
/*
01 【auto】 局部变量的默认存储类别/在函数中定义，函数被调用时创建，函数终止时销毁/通常存储在栈上，且只在定义它的块或函数中可见
e.g.在函数内部声明  int a;  事实上省略了auto  完整表达是  auto int a;  （局部变量默认具有自动存储期）
02 【static】 用于定义静态存储变量  分为静态全局变量和静态局部变量
前者在全局作用域中定义/后者在局部作用域中定义，变量在函数调用之间保持其值
03 【register】  用于定义建议(1)存储在CPU寄存器中的局部变量，以加快访问速度/不能被取址（&）
04 【extern】  引用其他文件中定义的全局变量或函数
注：(1)建议，但未必
*/



//字符数组的进一步讨论

printf("\n ===== func/str/begin ===== \n");

//01 sprintf    （将格式化的数据）输出到字符串（写入字符串）
    char str1[20];  
    char str2[20];  
    int i = 10;
    float f = 3.14159;  

    sprintf(str1, "%d", i);  
    sprintf(str2, "%f", f);  

    printf("Integer: %s\n", str1);//...10
    printf("Float: %s\n", str2);//...3.141590

    printf("%d %d\n", sprintf(str1, "%d", i), sprintf(str2, "%f", f));//2 8
    printf("%c %c\n", str1[0], str1[15]);//1
//返回值是写入到字符数组中的字符数（不包括结尾的空字符）
//要求字符串充分大（>=字符个数 + 1）（考虑结尾的\0）


//02 strchr    在字符串中【查找】【第一次】出现指定字符的【位置】 若无则返回NULL
//原型 char *strchr(const char *str, int c);                                          //<string.h>
//str 指向要搜索的字符串的指针    c 要查找的字符（以int形式传递，再被转化为unsigned char）
//遇\0停止搜索
const char *str = "HelloWorld";
char *result1 = strchr(str, 'H');
char *result2 = strchr(str, 'p');
printf("%p\n", result1);//000000000040402C
printf("%p\n", str);    //000000000040402C
printf("%p\n", result2);//0000000000000000
//在大多数系统上，NULL 指针的值被定义为 (void*)0 或简单的 0，但具体打印出的值可能依赖于编译器和平台
if (result1 != NULL)
{
    printf("Character 'H' found at position: %ld\n", result1 - str);
} else {
    printf("not found\n");
}
if (result2 != NULL)
{
    printf("Character 'p' found at position: %ld\n", result2 - str);
} else {
    printf("not found\n");
}

//若字符串中部含有空格，strchr 仍然适用，且计算位置时考虑空格    另外，查找空格也是可行的

char* result3 = strchr(str, 'W');//W

if (result3 != NULL)
{
    printf("Character 'W' found at position: %ld\n", result3 - str);
} else {
    printf("not found\n");
}

const char *strSp = "Hello World";
printf("%s\n", strSp);//Hello World

char* result4 = strchr(strSp, 'W');//W

if (result4 != NULL)
{
    printf("Character 'W' found at position: %ld\n", result4 - strSp);
} else {
    printf("not found\n");
}

char* result5 = strchr(strSp, ' ');//W

if (result5 != NULL)
{
    printf("Space found at position: %ld\n", result5 - strSp);
} else {
    printf("not found\n");
}
/*
Character 'H' found at position: 0
not found
Character 'W' found at position: 5
Hello World
Character 'W' found at position: 6
Space found at position: 5
*/
//这里，我们是让position从0开始计数的


//03 strlen (string length)
//in <string.h>
//返回字符串长度（其中的字符个数）  不含终止空字符（null terminator）  即末尾的'\0'
char str01[] = "I like you";//注意 这里末尾\0是自动添加的 无需手动添加
printf("%lu\n", strlen(str01));//10

//p.s.上面的 %ld %lu 分别表示 long 和 unsigned long


//04 strcpy strcmp strcat                                                              【"n"版本见appendix n】

//strcpy (string copy)
//char *strcpy(char *dest, const char *src);
//dest (destination): 目标字符串的指针
//src (source): 源字符串的指针
char src[] = "abcde!";
char dest[10];
strcpy(dest, src);
printf("%s\n", dest);//abcde!

char src1[] = "abc de!";
char dest1[10];
strcpy(dest1, src1);
printf("%s\n", dest1);//abc de!

//strcmp (string compare) 
//int strcmp(const char *str1, const char *str2);
//完全相同返回0  首个相异处s1 < s2返回负数  > , 返回正数    【考虑ASCII】
//见后文【字典序】
char str001[] = "Hello";
char str002[] = "Hellq";
char str003[] = "Hella";
char str004[] = "HelLlo";
char str005[] = "Hello";
printf("%d  %d  %d  %d\n", strcmp(str001, str002), strcmp(str001, str003), strcmp(str001, str004), strcmp(str001, str005));
//-1  1  1  0

//strcat (string concatenate): 连接 / 追加
//char *strcat(char *dest, const char *src);
//注意dest要充分大
char destA[] = "good ";
char srcA[] = "morning";

strcat(destA, srcA);

printf("%s\n", destA);//good morning


char destAA[] = "g o  o   d          ";
strcat(destAA, srcA);
printf("%s", destAA);//g o  o   d          morning

//Golang与字符相关的查找
/*参见 【dft 6】【go_char】*/

printf("\n ===== func/str/end ===== \n");



//数组再论

//01 宏定义
//为便于修改数组长度，常考虑使用宏定义确定数组长度
/*
#include <stdio.h>
#define N 100
int main()
{
int a[N];
}
*/

//02 上界upper bound  下界lower bound  下标界subscript bound
//这是三个非严格，习惯性的称呼
//对于a[N] (不同于数学上) 定义N为上界 0(有时为1, ...)为下界 N(有时指下标范围)为下标界

//03验证数组名（是地址常量 不可修改）指向首元素
int arr1[5] = {1, 2, 3, 4, 5};
printf("%x\n%x\n", arr1, &arr1[0]);
printf("%p\n%p\n", arr1, &arr1[0]);
printf("%x\n%x\n", arr1 + 2, &arr1[2]);
//%x格式说明符用于打印无符号十六进制整数，它并不适用于直接打印指针值
//使用%x来打印指针值是错误的  应使用%p来正确地打印指针值
/*
61fdb0
61fdb0
000000000061FDB0
000000000061FDB0
61fdb8
61fdb8
*/
//打印值
printf("%d %d\n", *arr1 + 3, arr1[3]);//4 4
//读入    scanf("%d", &a[i])也可写成scanf("%d", a + i)

//04不写长度地声明数组
int arr2[] = {1, 2, 3};
printf("%d\n", sizeof(arr2) / sizeof(arr2[0]));//3

//不连续地声明数组
//注意    int arr3[10] = {1, 5, , 9};是不合法的 中间不能有空位
//C99及以后标准支持如下初始化方法
int arr3[10] = {[0] = 1, [1] = 5, [3] = 9};
for (int i = 0; i < 10; i++)
{
    printf("%d ", arr3[i]);
}
printf("\n");//1 5 0 9 0 0 0 0 0 0

//初始化全为零的数组
double arr4[5] = {0};
printf("%d %d %d\n", arr4[0], arr4[2], arr4[4]);//0 0 0
//其他常序列不得使用此语法
double arr5[5] = {1};
printf("%d %d %d\n", arr4[0], arr4[2], arr4[4]);//0 0 0

//越界（非法，但不报错，需自行处理）
int arr6[5] = {1, 2, 3, 4, 5};
printf("%d %d\n", arr6[2], arr6[10]);//3 0    但并未报错

//变长数组 (Variable Length Array, VLA, introduced by C99)
/*int n;
scanf("%d", &n);
int arr7[n];*/

//一维数组作函数形参    int arr[] 也可写 int* arr
/*
这表明，在函数参数列表中看见【int *a】，应当考虑是传入整型变量还是整型数组
*/

//e.g.求数组最大元
//见main外（上面）
//调用
printf("%d %d\n", maxInArray(arr6, 5), maxInArray(arr3, 10));//5 9
//其中，参数分别是 数组名 长度

//二维数组除for遍历以外的初始化方法

//内存中，二维数组按行的顺序一维存放

int arr8[3][2] = {1, 2, 3, 4, 5, 6};

for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 2; j++)
    {
        printf("%d ", arr8[i][j]);
    }
}

printf("\n");

int arr9[][2] = {6, 5, 4, 3, 2, 1};

for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 2; j++)
    {
        printf("%d ", arr9[i][j]);
    }
}

printf("\n");                       //arr10[3][]不可 因为情形不唯一

int arr10[3][3] = {{0, 5, 4},
                   {3, 2, 9},
                   {0, 0, 0}};

for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        printf("%d ", arr10[i][j]);
    }
}

printf("\n");

//访问数组元素的一些杂例

printf("examples of accessing array elements\n");

int a[6][6];
//*a + i    //1行i+1列元素y[0][i]的地址    *a + i 即 *(a+0)+i
//*(a + i)    //i+1行1列元素y[i][0]的地址    *(a + i) 即 *(a+i)+0 
//有通式 *(a + p) + q 其中 a是指向首元素"a[0][0]"即"1行1列"的指针    而该式指向a[p][q]

int y[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
//y    //指向y[0][0]的指针
//*y    //可以说也是指向y[0][0]的指针
printf("%p %p %d\n", y, *y, **y);
//    *(y+2)+2-*y    其结果是y[2][2]与y[0][0]的相对位置的差
/*
*   2   3   
4   5   6   
7   8   *   
10  11  12
若编序号，且考虑s号与t号，则上述差值为
(t - s + 1) - 1 = t - s
9 - 1 = 8
*/
printf("%d\n", *(y+2)+2-*y);//8

/*
一般地，引用 a[p][q] 第i行第j列
下标法直接访问  a[i-1][j-1]
间访  *(*(a+i-1)+j-1)
*/

//二维数组中，行下标界可以省，列下标界不能省。原因是二维数组是按照行进行保存的，要正确取出某一行，需要知道该行中有几个元素（即共有几列）



//函数原型
//下面，我们对C的若干内置函数予以讨论

//01 main函数
/*
常见的有
int main(void){                               //不接受任何参数
    //code
    return 0;
}

int main(int argc, char *argv[]){              //接受命令行参数
    //code
    return 0;
}
argc 命令行参数的数量 argument count 其包括程序名，故其值至少为1
argv 指向字符串数组的指针 argument vector
*/

//02 printf
/*
int printf(const char *format, ...);
【format】一个格式字符串，可以包含普通字符和格式说明符
【...】可变参数列表，表示其可接受任意数量和类型的参数
printf返回的是成功输出的字符数，若发生错误，返回一个负数
验证如下
*/
int pr1 = printf("1234567");
int pr2 = printf("1234567\n");
printf("%d %d\n", pr1, pr2);
//12345671234567
//7 8

//03 getchar
//注意，getchar返回类型不是char而是int
//int getchar(void);    返回ASCII码    验证如下
/*printf("ASCII: %d\n", getchar());*/

//然而,这些函数真正的底层实现可能是更为复杂的，这里不作讨论



//一些注记

//for (; n; )是n != 0时执行，不是n != 1时执行，勿大意出错

//0263 是八进制数 因为有前导0 是【合法整型常量】
//"B"不是是合法整型常量 'B'或许不是...
//0XEJ 是十六进制数 因为有前缀0X或0x 不是...
//24e1 即24 x 10^1 即240.0 是浮点型 不是...
//设 n = 8 则 !n 不是 -8 而是 0 （0 ~ 非0    非0 ~ 0）
//函数的数据类型是指返回值的类型
//函数声明时有时形参名可省略 e.g.    int f(int)

//杂例
/*
    int a = 0, b = 0;
    while (a < 15)
    {
        a++;
    }
    while (b++ < 15);
    printf("%d, %d\n", a, b);
    //15, 16
*/
/*
【1】关注边界情形，易得 a = 15
【2】注意到第二个循环是空循环，且是要多次进行的循环，且最后一次【判断】时【自增操作】亦在进行，有 b = 16
*/



//mid 取出三个不全相等的整数的中间值 若有相等值 则就取该值
printf("middle\n");

//Solution I
int a1 = 3, a2 = 1, a3 = 2;
//考虑函数(见main前)
printf("%d\n", findMid(a1, a2, a3));//2

//Solution II 注意到所求即为三元序列的中位数
//int arrMid[3] = {a1, a2, a3};
//使用某种排序算法将arrMid[3]排序
//int mid = arrMid[1];



//选择排序(Selection Sort)
//这是继冒泡排序之后我们讨论的第二种排序算法
//(#define N 5)

    int x[5]= {1, 3, 4, 2, 5};

    int temp, k;                                      //k记录【当前轮】找到的最小元素的下标/temp(temporary)

    for(int i = 0; i < N - 1; i++)                    //N-1次外循环
    {
        k = i;                                        //从i开始遍历 i以前已经处理        

        for(int j = i + 1; j < N; j++)
        {
            if (x[j] < x[k])
            {
                k = j;
            }
        }                                             //此时k是该轮的最小元下标

        temp = x[k];
        x[k] = x[i];                                  //交换x[i]与最小元x[k]
        x[i] = temp;
    }

    //打印一下
    for(int i = 0; i < N; i++)
    {
        printf("%d ", x[i]);
    }
printf("\n");

//下面是另一则例子，完全类似，可以对照
void sort(int arr[], int n)                               //升序选择排序
{
    int minPos;                                           //min position
    for (int k = 0; k < n - 1; k++)
    {
        minPos = k;
        for(int pos = k + 1; pos < n; pos++)
        {
            if (*(arr + pos) < *(arr + minPos))           //arr[pos] < arr[minPos]
            {
                minPos = pos;
            }
        }
        int temp = *(arr + k);
        *(arr + k) = *(arr + minPos);
        *(arr + minPos) = temp;
    }
}



//appendix n
/*
上面我们介绍了strcpy函数 strcmp函数 strcat函数
事实上，在现代编程中，有更为安全而优越的函数供我们使用
它们也同样定义在<string.h>中
*/

//strncpy
//最多复制n个字符
//char *strncpy(char *dest, const char *src, size_t n);

//strncmp
//最多比较n个字符
//int strncmp(const char *str1, const char *str2, size_t n);

//strncat
//最多追加n个字符
//char *strncat(char *dest, const char *src, size_t n);

return 0;

}