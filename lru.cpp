#include <iostream>
#include <unordered_map>

using namespace std;

class Node
{
public:
    Node *prev;
    Node *next;
    int data;
};

class DLList
{
public:
    DLList() { head = NULL; tail = NULL; count = 0; }
    ~DLList() {}
    Node* addNode(int val);
    void print();
    void removeTail();
    void moveToHead(Node* node);
    int size() { return count; }
private:
    Node *head;
    Node *tail;
    int count;
};

Node* DLList::addNode(int val)
{
    Node *tmp = new Node();
    tmp->data = val;
    tmp->prev = NULL;
    tmp->next = NULL;

    if (tail == NULL)
    {
        tail = tmp;
        head = tmp;
    }
    else 
    {
        head->prev = tmp;
        tmp->next = head;
        head = tmp;
    }
    count++;
    return tmp;
}

void DLList::moveToHead(Node *node)
{
    if (head == node)
        return;
    node->prev->next = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    else 
        tail = node->prev;

    node->next = head;
    node->prev = NULL;
    head->prev = node;
    head = node;
}

void DLList::removeTail()
{
    count--;
    if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else 
    {
        Node *del = tail;
        tail->prev->next = NULL;
        tail = tail->prev;
        delete del;
    }
}
void DLList::print()
{
    Node* temp = head;
    int ctr = 0;
    while ( (temp != NULL) && (ctr++ != 25)  ) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

class LRUCache
{
public:
    LRUCache(int aCacheSize);
    void fetchPage(int pageNumber);

private:
    int cacheSize;
    DLList LRUOrder;
    unordered_map<int, Node*> directAccess;
};

LRUCache::LRUCache(int aCacheSize) : cacheSize(aCacheSize)
{

}

void LRUCache::fetchPage(int pageNumber)
{
    unordered_map<int, Node*>::const_iterator it = directAccess.find(pageNumber);

    if (it != directAccess.end())
    {
        LRUOrder.moveToHead((Node*)it->second);
    }
    else 
    {
        if (LRUOrder.size() == cacheSize - 1)
            LRUOrder.removeTail();
        Node *node = LRUOrder.addNode(pageNumber);
        directAccess.insert(make_pair(pageNumber, node));
    }
    LRUOrder.print();    
}


int main()
{
    LRUCache lruCache(10);

    lruCache.fetchPage(5);
    lruCache.fetchPage(7);
    lruCache.fetchPage(15);
    lruCache.fetchPage(34);
    lruCache.fetchPage(23);
    lruCache.fetchPage(21);
    lruCache.fetchPage(7);
    lruCache.fetchPage(32);
    lruCache.fetchPage(34);
    lruCache.fetchPage(35);
    lruCache.fetchPage(15);
    lruCache.fetchPage(37);
    lruCache.fetchPage(17);
    lruCache.fetchPage(28);
    lruCache.fetchPage(16);

    return 0;
}
