#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int decreaseSort(vector<int> vect)
{
    int i = 1, maxIndex = 0, max = 0;
    while (i < vect.size())
    {
	if (vect[i] >= vect[i - 1])
	{
	    if (vect[i] >= max)
	    {
		max = vect[i];
		maxIndex = i;
	    }
	}
	i++;
    }
    int del = 0;
//递归终止条件
    if (maxIndex == 0)
    {
	return del;
    } else {
//去掉最大凸起的前面部分
    vector<int> front;
    for (int i = 0; i < maxIndex; i++)
    {
	if (vect[i] > max)
	{
	    front.push_back(vect[i]);
	} else {
	    del++;
	}
    }
    for (int i = maxIndex; i < vect.size(); i++)
    {
	front.push_back(vect[i]);
    }
    del += decreaseSort(front);
    int mindel = del;
//去掉最大凸起的后面部分
    vector<int> back;
    del = 0;
    for (int i = 0; i < maxIndex; i++)
    {
	back.push_back(vect[i]);
    }
    for (int i = maxIndex; i < vect.size(); i++)
    {
	if (vect[i] >= vect[maxIndex - 1])
	{
	    del++;
	} else {
	    back.push_back(vect[i]);
	}
    }
    del += decreaseSort(back);
    if (del < mindel)
    {
	mindel = del;
    }
    return mindel;
    }
}

int increaseSort(vector<int> vect)
{
    int i = 1, maxIndex = -1, max = 0;
    while (i < vect.size())
    {
	if (vect[i] <= vect[i - 1])
	{
	    if (vect[i - 1] >= max)
	    {
		max = vect[i - 1];
		maxIndex = i - 1;
  	    }
	}
	i++;
    }
    int del = 0;
//递归终止条件
    if (maxIndex == -1)
    {
	return 0;
    } else {
//删除最大凸起前半部分
    vector<int> front;
    for (int i = 0; i <= maxIndex; i++)
    {
	if (vect[i] < vect[maxIndex + 1])
	{
	    front.push_back(vect[i]);
	} else {
	    del++;
	}
    }
    for (int i = maxIndex + 1; i < vect.size(); i++)
    {
	front.push_back(vect[i]);
    }
    del += increaseSort(front);
    int mindel = del;
//去掉最大凸起的后面部分
    vector<int> back;
    del = 0;
    for (int i = 0; i <= maxIndex; i++)
    {
	back.push_back(vect[i]);
    }
    for (int i = maxIndex + 1; i < vect.size(); i++)
    {
	if (vect[i] <= vect[maxIndex])
	{
	    del++;
	} else {
	    back.push_back(vect[i]);
	}
    }
    del += increaseSort(back);
    if (del < mindel)
    {
	mindel = del;
    }
    return mindel;
    }
}

int main()
{
    int num, temp;
    while (cin >> num)
    {
    vector<int> vect;
    while (num--)
    {
	cin >> temp;
	vect.push_back(temp);
    }
    int mindel = vect.size();
    for (int i = 0; i < vect.size(); i++)
    {
	vector<int> front, back;
 	for (int j = 0; j <= i; j++)
	{
	    front.push_back(vect[j]);
	}
	for (int j = i; j < vect.size(); j++)
	{
	    back.push_back(vect[j]);
	}
	int idel = increaseSort(front);
	int ddel = decreaseSort(back);
 	int del = idel + ddel;
   	if (del < mindel)
	{
	    mindel = del;
	}
    }
    cout << mindel << endl;
    }
    return 0;
}
