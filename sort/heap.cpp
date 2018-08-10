#include <iostream>

using namespace std;

void heapDown(int *a, int start, int end)
{
    int c = start;
    int l = 2*c + 1;
    int tmp = a[c];

    for ( ; l < end; c = l, l = 2 * l + 1 ) 
    {
        if (a[l] < a[l+1])
            ++l;
        if (tmp > a[l])
            break;
        else 
        {
            a[c] = a[l];
            a[l] = tmp;
        }
    }
}

void heapSortAsc(int *a, int n)
{

    for (int i = n / 2 - 1; i >= 0; --i) 
        heapDown(a, i, n-1);

    for (int i = n-1; i > 0; --i) 
    {
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;

        heapDown(a, 0, i-1);
    }
}

void heapDownDesc(int *a, int start, int end)
{
    int c = start;
    int l = 2 * c + 1;
    int temp = a[c];

    for ( ; l < end; c = l, l = 2 * l + 1 ) 
    {
        if (a[l] > a[l+1])
            ++l;
        if (a[c] < a[l])
            break;
        else 
        {
            a[c] = a[l];
            a[l] = temp;
        }
    }
}

void heapSortDesc(int *a, int n)
{
    for (int i = n/2-1; i >= 0; --i) 
        heapDownDesc(a, i, n-1);

    for (int i = n-1; i > 0; --i) 
    {
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;

        heapDownDesc(a, 0, i-1);
    }
}
int main()
{
    int i;
    int a[] = {20, 30, 90, 40, 70, 110, 60, 10, 100, 50, 80};
    int size = sizeof(a) / sizeof(a[0]);

    heapSortDesc(a, size);
    for (int i = 0; i < size; i++ )
        cout << a[i] << " ";
    heapSortAsc(a, size);
    for (int i = 0; i < size; i++ )
        cout << a[i] << " ";
}
