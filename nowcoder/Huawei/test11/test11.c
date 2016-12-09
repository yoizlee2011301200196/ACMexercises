#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

typedef vector<string>::iterator strIterator;

void bubbleSort(strIterator beg, strIterator end)
{
    for (vector<string>::size_type i = 0; i < end - beg - 1; i++)
    {
	for (strIterator it = beg; it != end - i - 1; ++it)
 	{
	    if ( *it > *(it + 1))
	    {
		string temp = *it;
		*it = *(it + 1);
		*(it + 1) = temp;
	    }
	}
    }
}

int main()
{
    int num;
    while (cin >> num)
    {
	string s;
	vector<string> vect;
	while (num--)
	{
	    cin >> s;
	    vect.push_back(s);
	}
	bubbleSort(vect.begin(), vect.end());
	for (strIterator it = vect.begin(); it != vect.end(); ++it)
	{
	    cout << *it << endl;
	}
    }

    return 0;
}
