/***
 * 现在给出一个加强版的括号匹配问题： 给出n个由括号 '(' 和 ‘)’ 组成的字符串
 * ，请计算出这些字符串中有多少对字符串满足si + sj是合法的括号匹配。如果si + sj和sj + si都是合法的括号匹配(i ≠ j)，
 * 那么这两种搭配都需要计入答案；如果对于si，si + si是合法的括号匹配，那么也需要计入答案。
 * **/

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    string contain;
    int left;
    int right;
    bool closed;
}node[300000];

bool isClosed(string con)
{
    stack<char> sta;
    for (int i = 0; i < con.length(); i++)
    {
        if (con[i] == '(')
            sta.push(con[i]);
        if (con[i] == ')')
            if (sta.empty())
                return false;
            else 
                sta.pop();
    }

    if (sta.empty())
        return true;
    return false;
}

void init(Node &node)
{
    stack<char> sta;
    node.closed = false;
    
    for (int i = 0; i < node.contain.length(); i++)
    {
        if (node.contain[i] == '(')
        {
            node.left++;
            sta.push('(');
        }
        if (node.contain[i] == ')')
        {
            node.right++;
            if (sta.empty())
                node.closed = false;
            else 
                sta.pop();
        }
    }

    if (sta.empty())
        node.closed = true;
    
}

int main()
{
    int n;
    cin >> n;
    string tmp = "";
    for (int i = 0; i < n; i++)
    {
        cin >> node[i].contain;
        init(node[i]);
               
    }

    long long total = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (node[i].left + node[j].left != 
                node[i].right + node[j].right)
                continue;
            if (node[i].closed && node[j].closed)
            {
                total++;
                continue;
            }
            if (isClosed(node[i].contain + node[j].contain))
                total++;
        }

    cout << total;
}
