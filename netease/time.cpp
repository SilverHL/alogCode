/***
 *
小W有一个电子时钟用于显示时间，显示的格式为HH:MM:SS，HH，MM，SS分别表示时，分，秒。其中时的范围为[‘00’,‘01’…‘23’]，分的范围为[‘00’,‘01’…‘59’]，秒的范围为[‘00’,‘01’…‘59’]。

但是有一天小W发现钟表似乎坏了，显示了一个不可能存在的时间“98:23:00”，小W希望改变最少的数字，使得电子时钟显示的时间为一个真实存在的时间，譬如“98:23:00”通过修改第一个’9’为’1’，即可成为一个真实存在的时间“18:23:00”。修改的方法可能有很多，小W想知道，在满足改变最少的数字的前提下，符合条件的字典序最小的时间是多少。其中字典序比较为用“HHMMSS”的6位字符串进行比较。

输入描述: 每个输入数据包含多个测试点。每个测试点后有一个空行。 第一行为测试点的个数T(T<=100)。 每个测试点包含1行，为一个字符串”HH:MM:SS”，表示钟表显示的时间。
**/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string hour, mint, sec;
    string tim;

    while (n--) 
    {
        cin >> tim;
        hour += tim[0];
        hour += tim[1];
        mint += tim[3];
        mint += tim[4];
        sec += tim[6];
        sec += tim[7];

        if (hour >= "24")
        {
            if (hour[1] <= '3' && hour[0] > '2') 
                hour[0] = '0';
            else if (hour[0] <= '2' && hour[1] > '3')
                hour[0] = '0';
            else 
                hour = "00";
        }

        if (mint >= "60") 
        {
            if (mint[0] >= '6') 
                mint[0] = '0';
        }

        if (sec >= "60")
            if (sec[0] >= '6')
                sec[0] = '0';

        cout << hour << ":" << mint << ":" << sec << endl;
        hour.clear();
        mint.clear();
        sec.clear();
        tim.clear();
    }
}
