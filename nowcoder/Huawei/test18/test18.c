#include <iostream>
using namespace std;

int count(int a)
{
    if (a == 0 || a == 1)
	return 0;
    if (a == 2)
	return 1;
    return a / 3 + count(a % 3 + a / 3);
}

int main()
{
    int i;
    while (cin >> i)
    {
//solution 1
/*
	if (i == 0)
	    break;
	cout << i / 2 << endl;
*/
    	cout << count(i) << endl;
    }

    return 0;
}
