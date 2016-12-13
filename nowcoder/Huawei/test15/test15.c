#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> vect;
    vector<int> count;
    string file;
    string line;
    while (cin >> file >> line)
    {
	string s =  file.substr(file.find_last_of('\\') + 1);
	s = (s.size() > 16)?s.substr(s.size() - 16):s;
	s = s + " " + line;
	vector<string>::iterator iter = find(vect.begin(), vect.end(), s);
  	if (iter != vect.end())
	{
	    count[iter - vect.begin()]++;
	} else {
	    count.push_back(1);
	    vect.push_back(s);
	}
    }
    vector<string> res;
    for (vector<string>::reverse_iterator it = vect.rbegin(); it != vect.rend(); ++it)
    {
	if (it - vect.rbegin() + 1 > 8)
	    break;
 	res.push_back((*it) + " " + to_string(count[it.base() - 1 - vect.begin()]));
    }
    for (vector<string>::reverse_iterator it = res.rbegin(); it != res.rend(); ++it)
    {
	cout << *it << endl;
    }

    return 0;
}
