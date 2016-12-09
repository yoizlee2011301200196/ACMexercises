#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
//solution 1
/*
	int count = 0;
	while (num)
	{
	    if (num % 2)
	    {
		count++;
	    }
	    num /= 2;
	}
	cout << count << endl;
*/

//solution 2
	bitset<32> bs(num);
	cout << bs.count() << endl;
    }

    return 0;
}
