#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int a)
{
    if (a == 2)
        return true;
    int temp = pow(a, 0.5);
    for (int i = 2; i <= temp; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int num;
    while (cin >> num)
    {
        vector<int> odd;
        vector<int> oven;
        int temp;
        while (num--)
        {
            cin >> temp;
            if (temp % 2 == 0)
                oven.push_back(temp);
            else
                odd.push_back(temp);
        }
        int minsize = (odd.size() >= oven.size())?oven.size():odd.size();
cout << odd.size() << " " << oven.size() << endl;
        if (minsize == oven.size())
        {
            vector<int> uniodd;
            vector<int> countodd;
            for (vector<int>::iterator it = odd.begin(); it != odd.end(); ++it)
            {
                if (find (uniodd.begin(), uniodd.end(), *it) != uniodd.end())
                {
                    continue;
                } else {
                    uniodd.push_back(*it);
                    countodd.push_back(count(odd.begin(), odd.end(), *it));
                }
            }
            vector<vector<int> > ma;
            for (vector<int>::iterator it = oven.begin(); it != oven.end(); ++it)
            {
		vector<int> vect;
                for (vector<int>::iterator iter = uniodd.begin(); iter != uniodd.end(); ++iter)
                {
                    if(isPrime(((*it) + (*iter))))
                    {
                        vect.push_back(iter - uniodd.begin());
                    }
                }
                vect.push_back(-1);
		ma.push_back(vect);
            }
/*
for (int i = 0; i < ma.size(); i++)
{
    for (int j = 0; j < ma[i].size(); j++)
	cout << ma[i][j] << " ";
    cout << endl;
}
*/
            vector<int> sortoven;
            vector<vector<int> > sortma;
            int maxlen = 0;
	    for (int i = 0; i < ma.size(); i++)
            {
                if (ma[i].size() > maxlen)
                {
                    maxlen = ma[i].size();
                }
            }
            for (int i = 2; i <= maxlen; i++)
            {
                for (int j = 0; j < ma.size(); j++)
                {
                    if (ma[j].size() == i)
                    {
			vector<int> vect(ma[j].begin(), ma[j].end() - 1);
                        sortma.push_back(vect);
                        sortoven.push_back(oven[j]);
                    }
                }
            }
for (int i = 0; i < sortma.size(); i++)
{
    for (int j = 0; j < sortma[i].size(); j++)
        cout << sortma[i][j] << " ";
    cout << endl;
}
            int pairnum = 0;
            for (int i = 0; i < sortoven.size(); i++)
            {
                for (int j = 0; j < sortma[i].size(); j++)
                {
                    if (countodd[sortma[i][j]] != 0)
                    {
                        countodd[sortma[i][j]]--;
                        pairnum++;
                        break;
                    }
                }
            }
            cout << pairnum << endl;
	    continue;
        }
	if (minsize == odd.size())
        {
            vector<int> unioven;
            vector<int> countoven;
            for (vector<int>::iterator it = oven.begin(); it != oven.end(); ++it)
            {
                if (find (unioven.begin(), unioven.end(), *it) != unioven.end())
                {
                    continue;
                } else {
                    unioven.push_back(*it);
                    countoven.push_back(count(oven.begin(), oven.end(), *it));
                }
            }
            vector<vector<int> > ma;
            for (vector<int>::iterator it = odd.begin(); it != odd.end(); ++it)
            {
		vector<int> vect;
                for (vector<int>::iterator iter = unioven.begin(); iter != unioven.end(); ++iter)
                {
                    if(isPrime(*it + *iter))
                    {
                        vect.push_back(iter - unioven.begin());
                    }
                }
                vect.push_back(-1);
		ma.push_back(vect);
            }
            vector<int> sortodd;
            vector<vector<int> > sortma;
            int maxlen = 0;
            for (int i = 0; i < ma.size(); i++)
            {
                if (ma[i].size() > maxlen)
                {
                    maxlen = ma[i].size();
                }
            }
            for (int i = 2; i <= maxlen; i++)
            {
                for (int j = 0; j < ma.size(); j++)
                {
                    if (ma[j].size() == i)
                    {
			vector<int> vect(ma[j].begin(), ma[j].end() - 1);
                        sortma.push_back(ma[j]);
                        sortodd.push_back(odd[j]);
                    }
                }
            }
            int pairnum = 0;
            for (int i = 0; i < sortodd.size(); i++)
            {
                for (int j = 0; j < sortma[i].size(); j++)
                {
                    if (countoven[sortma[i][j]] != 0)
                    {
                        countoven[sortma[i][j]]--;
                        pairnum++;
                        break;
                    }
                }
            }
            cout << pairnum << endl;
        }
    }

    return 0;
}
