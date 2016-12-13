#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string stableSort(string str)
{
    string s;
    char up = 'A', low = 'a';
    while (up <= 'Z')
    {
	for (int i = 0; i < str.size(); i++)
	{
	    if (str[i] == up || str[i] == low)
	    {
		s += str[i];
	    }
	}
	up++;
	low++;
    }
    return s;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
	string str;
	for (int i = 0; i < line.size(); i++)
	{
	    if (isalpha(line[i]))
	    {
	 	str += line[i];
 	    }
	}
	string s = stableSort(str);
	int j = 0;
	for (int i = 0; i < line.size(); i++)
	{
	    if (isalpha(line[i]))
	    {
		line[i] = s[j];
		j++;
	    }
	}
	cout << line << endl;
    }

    return 0;
}
