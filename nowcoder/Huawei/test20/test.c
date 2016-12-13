#include <iostream>
using namespace std;

int test()
{
    int a = -1;
    if (a == -1)
	return 0;
    cout << "hello" << endl;
    return 1;
}

int main()
{
    int a = test();
    cout << a << endl;

    return 0;
}
