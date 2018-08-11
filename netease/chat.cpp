/***
 * 小云正在参与开发一个即时聊天工具，他负责其中的会话列表部分。

会话列表为显示为一个从上到下的多行控件，其中每一行表示一个会话，每一个会话都可以以一个唯一正整数id表示。

当用户在一个会话中发送或接收信息时，如果该会话已经在会话列表中，则会从原来的位置移到列表的最上方；如果没有在会话列表中，则在会话列表最上方插入该会话。

小云在现在要做的工作是测试，他会先把会话列表清空等待接收信息。当接收完大量来自不同会话的信息后，就输出当前的会话列表，以检查其中是否有bug。
***/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<list<int> >lst;
    int n;
    int num;
    cin >> n;
    while (n--) 
    {   
        list<int> tmp;
        cin >> num;
        int id;
        while (num--)
        {
            cin >> id;
            list<int>::iterator res;
            if ((res = find(tmp.begin(), tmp.end(), id)) != tmp.end())
                tmp.erase(res);
            tmp.push_front(id);
        }
        lst.push_back(tmp);
        tmp.clear();
    }

    for (int i = 0; i < lst.size(); i++) 
    {
        for (auto idx = lst[i].begin(); idx != lst[i].end(); idx++)
            cout << *idx << " ";
        cout << endl;
    }
}
