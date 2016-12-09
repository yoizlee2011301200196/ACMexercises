#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main()
{
//solution 1
/*
    bool ch[128] = {false};
    char c;
    while (cin >> c)
    {
    	ch[c] = true;
    }
    int count = 0;
    for (int i = 0; i < 128; i++)
    {
	if (ch[i])
	    count++;
    }
    cout << count << endl;
*/

//solution 2
    set<char> st;
    char c;
    while (cin >> c)
    {
	st.insert(c);
    }
    cout << st.size() << endl;
    return 0;
}
