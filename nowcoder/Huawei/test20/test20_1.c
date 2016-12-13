#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int minimalDel(vector<int> vect)
{
    if (vect.size() == 1)
	return 0;
    if (vect.size() == 2)
	if (vect[0] != vect[1])
	    return 0;
    int max = vect[0], maxIndex = 0;
    for (vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
    {
	if (*it > max)
	{
	    max = *it;
	    maxIndex = it - vect.begin();
	}
    }
    bool ready = true;
    for (vector<int>::iterator it = vect.begin(); it != vect.begin() + maxIndex; ++it)
    {
	if (*it >= *(it + 1))
	{
	    ready = false;
	}
    }
    for (vector<int>::iterator it = vect.begin() + maxIndex; it != vect.end() - 1; ++it)
    {
	if (*it <= *(it + 1))
	{
	    ready = false;
	}
    }
    if (ready)
    {
	return 0;
    } else {
	int mindel = vect.size();
	int del = 0;
	vector<int> subvect;
	for (vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
	{
	    del = 1;
	    subvect.clear();
	    for (vector<int>::iterator iter = vect.begin(); iter != vect.end(); ++it)
	    {
		if (iter != it)
		{
		    subvect.push_back(*iter);
		}
	    }
	    del += minimalDel(subvect);
	    if (del < mindel)
	    {
		mindel = del;
	    }
	}
	return mindel;
    }

}

int main()
{
    int num;
    while (cin >> num)
    {
	vector<int> vect;
	int temp;
	while (num--)
	{
	    cin >> temp;
	    vect.push_back(temp); 
	}
	for (vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
	{
	    cout << *it << " ";
	}
	int mindel = minimalDel(vect);
	cout << mindel << endl;
    }

    return 0;
}
