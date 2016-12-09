#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
	int key, value;
	map<int, int> ma;
	while (cin >> key >> value)
	{
/*
	    if (ma.count(key))
	    {
		ma[key] += value;
	    } else {
		ma[key] = value;
	    }
*/
	    ma[key] += value;
	}

	for (pair<int, int> p : ma)
	{
	    cout << p.first << " " << p.second << endl;
	}
/*
	for (map<int, int>::iterator it = ma.begin(); it != ma.end(); ++it)
	{
	    cout << it->first << " " << it->second << endl;
	}
*/
    }
    return 0;
}
