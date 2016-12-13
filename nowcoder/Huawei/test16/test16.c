#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string pd;
    while (cin >> pd)
    {
	if (pd.size() <= 8)
	{
	    cout << "NG" << endl;
	    continue;
	} else {
	    int type = 0;
	    if (pd.find_first_of("0123456789") != string::npos)
		type++;
	    if (pd.find_first_of("abcdefghijklmnopqrstuvwxyz") != string::npos)
		type++;
	    if (pd.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos)
		type++;
	    for (int i = 0; i < pd.size(); i++)
	    {
		if (!isalpha(pd[i]) && !isdigit(pd[i]))
		{
		    type++;
		    break;
		}
	    }	
	    if (type < 3)
	    {
		cout << "NG" << endl;
		continue;
	    }
	    bool repeat = false;
	    for (int i = 0; i < pd.size() - 3; i++)
	    {
		string temp = pd.substr(i + 3);
		string::size_type k = temp.find(pd.substr(i, 3));
		if (k != string::npos)
		{
		    cout << "NG" << endl;
		    repeat = true;
		    break;
		}
	    }
	    if (!repeat)
		cout << "OK" << endl;
	}
    }

    return 0;
}
