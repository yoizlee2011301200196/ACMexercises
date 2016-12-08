#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(long a)
{
    bool flag = true;
    double b = pow(a, 0.5);
    for(int i = 2; i <= b; i++)
    {
	if (a % i == 0)
	{
	    flag = false;
	    break;
	}
    }
    return flag;
}

void getResult(long ul)
{
    long a = ul;
//find all factors
    vector<long> vect;
    while (!isPrime(a))
    {
	long i = 2;
	while (a % i != 0 && i <= a)
	{
	    i++;
	}
	if (a % i == 0)
 	{
	    vect.push_back(i);
	    a = a / i;
	}
    }
    vect.push_back(a);

//find all prime factors
    vector<long> vect1;
    for (vector<long>::iterator it = vect.begin(); it != vect.end(); ++it)
    {
	if (isPrime(*it))
	    vect1.push_back(*it);
    }

//sort all prime factors
    sort(vect1.begin(), vect1.end());

    for (vector<long>::iterator it = vect1.begin(); it != vect1.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
/*
//return sorted string
    string s;
    for (long i = 0; i < vect1.size(); i++)
    {
   	string s1 = vect1[i] + "";
	s = s + s1 + " ";
    }
    return s;
*/
}

int main()
{
//solution 1
/*
    long ul;
    while (cin >> ul)
    {
//	cout << isPrime(ul) << endl;
//	cout << getResult(ul) << endl;
	getResult(ul);
    }
*/

//solution 2
    long ul;
    while (cin >> ul)
    {
	while (ul != 1)
	{
	    for (int i = 2; i <= ul; i++)
	    {
		if (ul % i == 0)
		{
		    ul = ul / i;
		    cout << i << " ";
		    break;
		}
 	    }
	}
    }  
    return 0;
}
