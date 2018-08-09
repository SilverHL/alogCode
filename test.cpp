#include <iostream>

using namespace std;

int main()
{
    char c = '1';
    char *pc = &c;
    cout << sizeof(c) << endl;
    cout << sizeof(pc) << endl;;
}
