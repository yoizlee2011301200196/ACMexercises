#include <iostream>
#include <string>
using namespace std;

int main()
{
    int ch[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
    string pd;
    while (cin >> pd)
    {
	string s;
	for (int i = 0; i < pd.size(); i++)
	{
	    if (pd[i] >= 'A' && pd[i] <= 'Z')
	    {
		s += ((pd[i] + 33 - 'a') % 26 + 'a');
	    } else if (pd[i] >= 'a' && pd[i] <= 'z') {
		s += to_string(ch[pd[i] - 'a']);
	    } else if (pd[i] >= '0' && pd[i] <= '9') {
		s += pd[i];
	    }
	}
	cout << s << endl;
    }

    return 0;
}
