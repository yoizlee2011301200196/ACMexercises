#include <iostream>
#include <vector>
#include <iterator>
#include <string>
using namespace std;

int main()
{
//solution 1
/*
    string s1;
    while (cin >> s1)
    {
	vector<string> vect;
 	int m = s1.size() / 8;
	for (int i = 0; i < m; i++)
	{
	    vect.push_back(s1.substr(i*8, 8));
	}
	if ((s1.size() % 8) != 0)
 	{
	    int t = 8 - s1.size()%8;
	    for (int i = 0; i < t; i++)
	    {
	        s1 += '0';
	    }
	    vect.push_back(s1.substr(m * 8));
        }
	for (vector<string>::iterator it = vect.begin(); it != vect.end(); ++it)
        {
            cout << *it << endl;
        }
    }
*/

//solutin 2
    string s;
    while (cin >> s)
    {
	while (s.size() > 8)
	{
	    cout << s.substr(0, 8) << endl;
	    s = s.substr(8);
	}
	int m = s.size();
	for (int i = 0; i < 8 - m; i++)
	{
	    s += "0";
	}
	cout << s << endl;
    }
    return 0;
}
