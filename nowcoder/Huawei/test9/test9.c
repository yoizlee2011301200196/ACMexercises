#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
//solution 1
/*
    string s;
    while (cin >> s)
    {
	reverse(s.begin(), s.end());
	cout << s << endl;
    }
*/

//solution 2
/*
    string s;
    while (cin >> s)
    {
	string str;
	for (string::reverse_iterator it = s.rbegin(); it != s.rend(); ++it)
	{
	    str += (*it);
	}
	cout << str << endl;
    }
*/

//solution 3
    int a;
    while (cin >> a)
    {
	string s;
	while (a)
	{
	    int temp = a % 10;
	    s += (temp + '0');
	    a /= 10;
	}
	cout << s << endl;
    }

    return 0;
}
