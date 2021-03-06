#include <stdio.h>

//int s[1000001]
/*
给定一个顺序存储的线性表，请设计一个算法查找该线性表中最长的连续递增子序列。例如，(1,9,2,5,7,3,4,6,8,0)中最长的递增子序列为(3,4,6,8)。

输入格式:
输入第1行给出正整数n（≤10
​5
​​ ）；第2行给出n个整数，其间以空格分隔。

输出格式:
在一行中输出第一次出现的最长连续递增子序列，数字之间用空格分隔，序列结尾不能有多余空格。

输入样例：
15
1 9 2 5 7 3 4 6 8 0 11 15 17 17 10
输出样例：
3 4 6 8

解题思路:利用双指针,从头部扫描到尾部。其中尾指针记录符合要求的最后一个元素的位置，每一次尾指针都与其后面的一个元素进行比较,若后面元素较大
则尾指针sum加上后面的元素值,且尾指针后移一位。否则，比较当前sum与max的值,记录最大值的起点和终点,并将尾指针往后挪一位，再将头指针移至尾指针处。之后再将sum归零。
如此直到尾指针到数组边界。
*/
void fun(int n, int a[])
{
    int i = 0;
    int j = 0;
    int max = 0;
    int sum = a[j];
    int head = 0;
    int rear = 0;
    while(j < n)
    {
        
        if(a[j + 1] > a[j])
        {
           sum += a[j + 1];
           j++;
        }
        else
        {
            if(max < sum)
            {
                max = sum;
                head = i;
                rear = j;
                
            }
            sum = 0;
            j++;
            i = j;
        }
    }
    for(head; head <= rear; head++)
    {
        printf("%d ", a[head]);
    }
}
    


int main()
{
    // int n;
    // scanf("%d",n);
    int a[] = {1, 9,13, 2, 5, 7, 3, 4, 6, 8, 0};
    fun(11, a);
    return -1;
    
}