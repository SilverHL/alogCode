/***
 * 游戏里面有很多各式各样的任务，其中有一种任务玩家只能做一次，
 * 这类任务一共有1024个，任务ID范围[1,1024]。
 * 请用32个unsigned int类型来记录着1024个任务是否已经完成。
 * 初始状态都是未完成。 输入两个参数，都是任务ID，
 * 需要设置第一个ID的任务为已经完成；并检查第二个ID的任务是否已经完成。
 * 输出一个参数，如果第二个ID的任务已经完成输出1，如果未完成输出0。
 * 如果第一或第二个ID不在[1,1024]范围，则输出-1。 
 * **/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned int done[32];
    memset(done, 0, sizeof(done));
    
    int i1, i2;
    cin >> i1 >> i2;
    int id1 = i1 / 32;
    int id2 = i1 % 32;

    unsigned b = 0x80000000;
    b >>= id2;

    done[id1] |= b;
    
    int index1 = i2 / 32;
    int index2 = i2 % 32;

    b = 0x80000000;
    b >>= index2;

    if (done[index1] && b) 
        cout << 1;
    else 
        cout << 0;

}
