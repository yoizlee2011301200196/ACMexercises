#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int findLoogestIncreaseSeq(vector<int> &vect)
{
    int len = 0;
    int *count = new int[vect.size()];
    for (int i = 0; i < vect.size(); i++)
	count[i] = 1;
    for (int i = 0; i < vect.size(); i++)
    {
	for (int j = i - 1; j >= 0; j--)
	{
	    if (vect[j] < vect[i] && count[j] >= count[i])
	    {
		count[i] = count[j] + 1;
	    }
	}
	if (count[i] > len)
	    len = count[i];
    }
    delete [] count;
    return len;
}

int main()
{
    vector<int> vect;
    int temp;
    while (cin >> temp)
    {
	vect.push_back(temp);
    }
    cout << findLoogestIncreaseSeq(vect) << endl;

    return 0;
}
