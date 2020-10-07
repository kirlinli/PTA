/*
汉诺塔的非递归求解:
非递归思路：

（1）将最小圆盘移动到下一个柱子上

（2）对剩余两柱子进行顶上最小的元素判断，把小一点的圆盘移动到大一点的圆盘上（有空柱则摞在空柱子上）。

 重复上述两步就可以得到答案。

注意：这样得到的最后的答案不一定是摞在 c 上，如果 N 是奇数将摞在 b 上，所以如果 N 是奇数我们就令第二个柱子为 c ，第三个柱子为 b ，这样就一定最后是摞在 c 上的。
*/

#include <iostream>
#include <stack>
using namespace std;
stack<int> s[3];
char name[3] = {'a','b','c'};
void fun(int a, int b)
{
    if(s[a].empty() && !s[b].empty() || (!s[a].empty() && !s[b].empty() && (s[a].top() > s[b].top())))
    {
        s[a].push(s[b].top());
        s[b].pop();
        printf("%c---->%c\n",name[b],name[a]);
        return;  
    }

    if(s[b].empty() && !s[a].empty() ||(!s[a].empty() && !s[b].empty() && s[a].top() < s[b].top()) )
    {
        s[b].push(s[a].top());
        s[a].pop();
        printf("%c---->%c\n",name[a],name[b]);
        return;
    }
}
int main()
{
    int before, now = 0, after = 1;
    int n = 3;
    //scanf("%d", &n);
    for(int i = n; i > 0; i--)
    {
        s[0].push(i);
    }
    if(n % 2 == 1)
    {
        name[1] = 'c';
        name[2] = 'b';
    }
        
    while(true)
    {
        fun(now,after);
        before = now;
        if(s[after].size() == n)
            break;
        now = after;
        after = (now + 1) % 3;
        fun(before, after);
    }
}