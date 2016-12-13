#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

bool biggerth(string s1, string s2)
{
    int a = atoi(s1.c_str());
    int b = atoi(s2.c_str());
    return a < b;
}

int main()
{
    int i, r;
    while (cin >> i)
    {

    vector<string> ivect;
    string s;
    while (i--)
    {
	cin >> s;
	ivect.push_back(s);
    }
    cin >> r;
    vector<string> rvect;
    while (r--)
    {
	cin >> s;
	rvect.push_back(s);
    }
    sort(rvect.begin(), rvect.end(), biggerth);
    string pre = rvect[0];
    vector<string> res1;
    vector<int> res2;
    vector<string> ires;
    vector<int> nres;
    for (vector<string>::iterator it = rvect.begin(); it != rvect.end(); ++it)
    {
	int beg1 = res1.size();
	if (it != rvect.begin() && *it == pre)
	{
	    continue;
	}
	for (vector<string>::iterator iter = ivect.begin(); iter != ivect.end(); ++iter)
	{
	    int itemp = (*iter).find(*it);
	    if (itemp != string::npos)
	    {
		res1.push_back(*iter);
		res2.push_back(iter - ivect.begin());
	    }
	}
	if (res1.size() != beg1)
	{
	     ires.push_back(*it);
	     nres.push_back(res1.size() - beg1);
	     res1.push_back(" ");
	     res2.push_back(-1);
	}
	pre = *it;
    }
    cout << ires.size() + res1.size() + res2.size() - nres.size() << " ";
    vector<int>::iterator res2it = res2.begin();
    vector<string>::iterator res1it = res1.begin();
    vector<int>::iterator nit = nres.begin();
    for(vector<string>::iterator it = ires.begin(); it != ires.end(); ++it)
    {
	cout << *it << " " << *nit;
	while (*res2it != -1)
	{
	    cout << " " << *res2it << " " << *res1it;
	    res2it++;
	    res1it++;
	}
	res2it++;
	res1it++;
	nit++;
	if (res2it != res2.end())
	    cout << " ";
    }
    cout << endl;
    }
    return 0;
}
