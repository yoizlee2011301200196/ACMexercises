#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
	stack<string> st;
	istringstream ss(s);
	string str;
	while (ss >> str)
	{
	    st.push(str);
	}
	cout << st.top();
	st.pop();
	while (!st.empty())
	{
	    cout << " " << st.top();
	    st.pop();
	}
	cout << endl;
    }

    return 0;
}
