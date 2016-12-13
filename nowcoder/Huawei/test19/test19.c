#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
	vector<char> vect1;
	vector<int> vect2;
	for (int i = 0; i < s.size(); i++)
	{
	    vector<char>::iterator it = find(vect1.begin(), vect1.end(), s[i]);
	    if (it == vect1.end())
	    {
	 	vect1.push_back(s[i]);
		vect2.push_back(1);
	    } else {
		vect2[it - vect1.begin()]++;
	    }
	}
	vector<char> del;
	int min = 20, num = 1;
	for (vector<int>::iterator it = vect2.begin(); it != vect2.end(); ++it)
	{
	    if (*it < min)
	    {
		min = *it;
		num = 1;
		del.push_back(vect1[it - vect2.begin()]);
	    } else if (*it == min) {
		num++;
		del.push_back(vect1[it - vect2.begin()]);
	    }
	}
	string str;	
	for (vector<char>::reverse_iterator it = del.rbegin(); it != (del.rbegin() + num); ++it)
	{
	    for (int i = 0; i < s.size(); i++)
	    {
		if (s[i] != *it)
		{
		    str += s[i];
		}
	    }
	    s = str;
	    str = "";
	}
	cout << s << endl;
	
    }

    return 0;
}
