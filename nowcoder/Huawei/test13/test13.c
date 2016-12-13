#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
using namespace std;

int main()
{
    string str;
    while (cin >> str)
    {
//solution 1
/*
	istringstream is(str);
 	string s;
	int x = 0, y = 0;
	while (getline(is, s, ';'))
	{
	    if (s.size() == 3 && isalpha(s[0]) && isdigit(s[1]) && isdigit(s[2]) || (s.size() == 2 && isalpha(s[0]) && isdigit(s[1])))
	    {
		int num = atoi(s.substr(1).c_str());
		switch(s[0])
		{
		    case 'A':
			x -= num;
			break;
		    case 'D':
			x += num;
			break;
		    case 'W':
			y += num;
			break;
		    case 'S':
			y -= num;
			break;
		}
	    }
	}
*/

//solution 2
	int x = 0, y = 0;
	string::size_type end = str.find_first_of(';');
	while (end != string::npos)
	{
	    string s = str.substr(0, end);
	    if (end == str.size())
		break;
	    str = str.substr(end + 1);
	    end = str.find_first_of(';');
	    if (s.size() == 3 && isalpha(s[0]) && isdigit(s[1]) && isdigit(s[2]) || (s.size() == 2 && isalpha(s[0]) && isdigit(s[1])))
            {
                int num = atoi(s.substr(1).c_str());
                switch(s[0])
                {
                    case 'A':
                        x -= num;
                        break;
                    case 'D':
                        x += num;
                        break;
                    case 'W':
                        y += num;
                        break;
                    case 'S':
                        y -= num;
                        break;
                }
            }
	}
	cout << x << "," << y << endl;
    }
 
    return 0;
}
