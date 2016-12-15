#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    string line;
    while (getline(cin, line))
    {
 	vector<string> vect;
	string s;
	for (int i = 0; i < line.size(); i++)
	{
	    s = "";
	    while (i < line.size() && isalpha(line[i]) && s.size() <= 20)
	    {
		s += line[i];
		i++;
	    }
	    if (s != "")
	    	vect.push_back(s);
	}
        for (vector<string>::reverse_iterator it = vect.rbegin(); it != vect.rend(); ++it)
        {
            if (it == vect.rend() - 1)
                cout << *it << endl;
            else {
                cout << *it << " ";
            }
    	}
    }	
    return 0;
}
