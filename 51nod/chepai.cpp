/***
 * 一个车牌号由n位数字组成。如果一个车牌至少有k位数字是相同的，那么我们就说这个车牌漂亮的车牌。
 * 现在华沙想要改变他自己的车牌，使得他的车牌变得漂亮。当然，改车牌是要花钱的。
 * 每改变一位数字所要花费的费用等于当前位上的新旧数字之差的绝对值。
 * 那么总费用就是每位上所花费用的总和。举例如下，
旧牌为0123，新牌为7765，那么对应第一位所花费用为|0-7|＝7，
第二位为|1-7|＝6，第三位为|2-6|＝4，第四位为|3-5|＝2，总和为7+6+4+2＝19
华沙想用最少的钱，使他的车牌变得漂亮起来。现在给定n，k，和旧牌的号码，
计算换牌的最少费，以及新牌的号码，
如果最少费用的号码有多个，我们取字典序最小的那个。
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4+5;
typedef long long ll;

int n, k, min_sum, num[10];
string ans, tmp, in;

void init()
{
    min_sum = 1e5+5;
    memset(num, 0, sizeof(num));
}

int main()
{
    cin >> n >> k;
    init();
    cin >> in;

    for (int i = 0; i < n; i++)
        num[in[i]-'0']++;

    for (int i = 0; i < 10; i++) //对每个数字的结果进行枚举
    {
        int need = k - num[i], sum = 0;
        tmp = in;
        //从最小的距离开始改变
        for (int j = 1; j < 10 && need > 0; j++)
        {
            if (i + j < 10) //先改变排在前面的 先把大的往小了改
                for (int v = 0; v < n && need > 0; v++) //遍历一遍 把大的都改过来
                    if (tmp[v] - '0' == i+j)
                    {
                        tmp[v] = i+'0';
                        sum += j;
                        need--;
                    }

            if (i - j > -1)
                for (int v = n-1; v >= 0 && need > 0; --v)
                    if (tmp[v] - '0' == i+j)
                    {
                        tmp[v] = i + '0';
                        sum += j;
                        need--;
                    }
        }
        if (sum < min_sum && need <= 0)
        {
            ans = tmp;
            min_sum = sum;
        }
        else if (sum == min_sum && tmp < ans)
            ans = tmp;
    }

    cout << min_sum << endl;
    cout << ans << endl;

}
