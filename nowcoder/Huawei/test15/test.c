#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    istringstream is("12");
    int i;
    is >> i;
    cout << i << endl; 
    ostringstream os;
    int a = 123;
    os << a;
    cout << os.str() << endl;
    return 0;
}
