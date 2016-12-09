#include <iostream>
#include <string>
using namespace std;

int main()
{
//solution 1
/*
    string s;
    while (cin >> s)
    {
	string str;
 	bool ch[10];
	for (int i = 0; i < 10; i++)
	{
	    ch[i] = true;
	}
	for (string::reverse_iterator it = s.rbegin(); it != s.rend(); ++it)
	{
	    if(!ch[*it - '0'])
	    {
		continue;
	    } else {
		ch[*it - '0'] = false;
		str += (*it);
	    }
	}
	cout << str << endl;
    }
*/

//solution 2
    int a;
    while (cin >> a)
    {
	string str = "";
	bool ch[10] = {0};
	while (a >= 1)
	{
	    int temp = a % 10;
	    a /= 10;
	    if (ch[temp])
	    {
		continue;
	    } else {
		ch[temp] = true;
		str += (temp + '0');
	    }
	}
	cout << str << endl;
    }
    return 0;
}
