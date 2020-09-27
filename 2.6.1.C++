#include <stdio.h>
#include <math.h>

/*本题要求实现一个函数，计算下列简单交错幂级数的部分和：

f(x,n)=x−x2+x​3−x4+⋯+(−1)n−1 * xn
​​
​​ 

函数接口定义：
double fn( double x, int n );
其中题目保证传入的n是正整数，并且输入输出都在双精度范围内。函数fn应返回上述级数的部分和。建议尝试用递归实现。

裁判测试程序样例：
#include <stdio.h>

double fn( double x, int n );

int main()
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%.2f\n", fn(x,n));

    return 0;
}

输入样例：
0.5 12
输出样例：
0.33
*/

//解题思路:将每一次求解的值看成上一次的值加上第n次的求值。由此一直递归下去直到遇到递归终止的条件,即n=1,然后函数依次进行返回，从而得到得到最终的结果。
double fn( double x, int n );

int main()
{
    double x;
    int n;

    x = 0.5;
    n = 12;
    printf("%.2f\n", fn(x,n));

    return 0;
}

double fn( double x, int n )
{
    double result;
    if(n == 1)
        result = x;
    else
        result = pow(-1, n -1 ) * pow(x, n) + fn(x, n -1);
    return result;
}