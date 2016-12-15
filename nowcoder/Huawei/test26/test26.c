#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

string processString(string str1, string str2)
{
    map<char, char> ma;
    ma['0'] = '0';
    ma['1'] = '8';
    ma['2'] = '4';
    ma['3'] = 'C';
    ma['4'] = '2';
    ma['5'] = 'A';
    ma['6'] = '6';
    ma['7'] = 'E';
    ma['8'] = '1';
    ma['9'] = '9';
    ma['a'] = '5';
    ma['b'] = 'D';
    ma['c'] = '3';
    ma['d'] = 'B';
    ma['e'] = '7';
    ma['f'] = 'F';
    string s;
    s = str1 + str2;
    string s1, s2;
    for (int i = 0; i < s.size(); i++)
    {
	if (i % 2 == 0)
	{
	    s2 += s[i];
	} else {
	    s1 += s[i];
	}
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    s.clear();
    int p = 0;
    while (p < s1.size())
    {
	s = s + s2[p] + s1[p];
	p++;
    }
    if (p < s2.size())
	s += s2[p];
    for (int i = 0; i < s.size(); i++)
    {
	if (s[i] >= '0' && s[i] <= '9' || (s[i] >= 'a' && s[i] <= 'f'))
	{
	    s[i] = ma[s[i]];
	} else if (s[i] >= 'A' && s[i] <= 'F') {
	    s[i] = ma[s[i] + 32];
	}
    } 
    return s;
}

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
	string s = processString(s1, s2);
	cout << s << endl;
    }

    return 0;
}
