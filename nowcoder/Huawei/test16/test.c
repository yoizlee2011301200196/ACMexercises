#include <iostream>
#include <string>
#include <iterator>
using namespace std;

int main()
{
    string s = "ab1we3";
    string::size_type it = s.find_first_of("321");
    cout << s[it] << endl;
    string s1 = "a123ab";
    cout << s1.find("abc") << endl;
    return 0;
}
