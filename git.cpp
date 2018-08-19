/***
 * git是一种分布式代码管理工具，git通过树的形式记录文件的更改历史，
 * 比如： base'<--base<--A<--A' ^ | --- B<--B' 小米工程师常常需要寻找两个分支最近的分割点，
 * 即base.假设git 树是多叉树，请实现一个算法，计算git树上任意两点的最近分割点。 
 * （假设git树节点数为n,用邻接矩阵的形式表示git树：字符串数组matrix包含n个字符串，每个字符串由
 * 字符'0'或'1'组成，长度为n。matrix[i][j]=='1'当且仅当git树种第i个和第j个节点有连接。节点0为git树
 * 的根节点。）
 * **/

#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<string>& matrix, vector<int>& pathR, int index, int x, int pre)
{
    //将当前点压入
    pathR.push_back(x);
    if (x == index)  //如果是寻找的index 说明联通 就退出
        return true;
    
    //如果从x到index可以连通 就压入index 退出
    if (matrix[x][index] == '1')
    {
        pathR.push_back(index);
        return true;
    }

    //每行遍历一遍
    for (int i = 0; i < matrix.size(); i++)
    {
        if (i == pre) //剪枝
            continue;
        if (matrix[x][i] == '1')
        {
            vector<int> path = pathR;
            if (dfs(matrix, path, index, i, x))
            {
                swap(path, pathR);
                return true;
            }
        }
    }
    return false;
}

int getSplitNode(vector<string> matrix, int indexA, int indexB) 
{
    if (matrix.empty() || 
        indexA >= matrix.size() || 
        indexB >= matrix.size())
    {
        return -1;
    }

    vector<int> pathA;
    vector<int> pathB;

    dfs(matrix, pathA, indexA, 0, -1);
    dfs(matrix, pathB, indexB, 0, -1);

    int size = min(pathA.size(), pathB.size());
    for (int i = 0; i < size; i++)
        if (pathA[i] != pathB[i])
            return pathA[i-1];

    return pathA[size-1];
}

int main()
{
    vector<string> vec = {"01011","10100","01000","10000","10000"};
    cout << getSplitNode(vec, 1, 2);
}
