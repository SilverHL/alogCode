#include <iostream>
#include <cstring>
#include <memory.h>

using namespace std;

const int branchNum = 26;

/***
 * Trie树的节点 用来指出是否为完整字符串 
 * 以及它的下一个字符
 * **/

struct TrieNode
{
    bool isStr;
    TrieNode *next[branchNum];  //最多可存在26个分支
};

void Insert( TrieNode *root, const char *word );
bool Search( TrieNode *root, const char *word );
void Delete( TrieNode *node );

int main()
{
    //初始化前缀树的根节点
    TrieNode *root = new TrieNode();
    root->isStr = false;

    //前缀树中的每个节点的下一个节点　要分配空间
    memset(root->next, NULL, sizeof(root->next));

    Insert(root, "a");
    Insert(root, "bcd");
    Insert(root, "xyz");
    Insert(root, "abcdef");

    if (Search(root, "a"))
        cout << "a exist" << endl;

    Delete(root);
}

void Insert(TrieNode *root, const char *word)
{
    TrieNode *location = root;
    while (*word)
    {
        //节点的子节点为空　新建一个子节点
        if (location->next[*word-'a'] == NULL)
        {
            TrieNode *newNode = new TrieNode();
            newNode->isStr = false;
            memset(newNode->next, NULL, sizeof(newNode));

            location->next[*word-'a'] = newNode;
        }
        location = location->next[*word-'a'];
        word++;
    }

    location->isStr = true;

}

bool Search( TrieNode *root, const char *word )
{
    TrieNode *location = root;
    while (*word)
    {
        if (location->next[*word-'a'] == NULL)
            return false;
        else 
            location = location->next[*word-'a'];
    }

    return location->isStr;
}

void Delete(TrieNode *root)
{
    for (int i = 0; i < branchNum; i++)
    {
        if (root->next[i] != NULL)
            Delete(root->next[i]);
    }

    delete root;
    
}
