#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
	vector<string> vect;
	string s;
	while (num--)
	{
	    cin >> s;
	    vect.push_back(s);
	}
	string query;
	cin >> query;
	string queryStr = query;
	sort(queryStr.begin(), queryStr.end());
	string temp;
	vector<string> res;
	for (vector<string>::iterator it = vect.begin(); it != vect.end(); ++it)
	{
	    temp = *it;
	    sort(temp.begin(), temp.end());
	    if (temp == queryStr && *it != query)
		res.push_back(*it);
	}
	sort(res.begin(), res.end());
        cout << res.size() << endl;
	int index;
	cin >> index;
	if (index <= res.size())
	    cout << res[index - 1] << endl;
	
    }

    return 0;
}
