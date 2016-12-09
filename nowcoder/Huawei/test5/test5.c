#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float f;
    while (cin >> f)
    {
//solutin 1
	//cout << round(f) << endl;
//solution 2
	cout << static_cast<int>(f + 0.5) << endl;
    }
    return 0;
}
