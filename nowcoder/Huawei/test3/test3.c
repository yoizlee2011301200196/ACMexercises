#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

int main()
{
//solution 1
/*
    map<char, int> map1;
    map1['A'] = 10;
    map1['B'] = 11;
    map1['C'] = 12;
    map1['D'] = 13;
    map1['E'] = 14;
    map1['F'] = 15;
    string s;
    while (cin >> s)
    {
   	int sum = 0;
	for (int i = 2; i <  s.size(); i++)
	{
	    if (s[i] <= '9')
	    {
		sum += (s[i] - '0') * pow(16, (s.size() - 1 -i));
	    } else {
		sum += map1[s[i]] * pow(16, (s.size() - 1 - i));
	    }
	}
	cout << sum << endl;
    }
*/

//solution 2
    int a;
    while (cin >> hex >> a)
    {
	cout << a << endl;
	cout << oct << a << endl;
    }
    return 0;
}
