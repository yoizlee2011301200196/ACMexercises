#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#include <set>
#include <list>
using namespace std;

void quickSort(int* arr, int a, int b);

int main()
{
//solution 1
/*
    vector<int> vect;
    int num, i = 0;
    cin >> num;
    int temp;
    while (i < num)
    {
	cin >> temp;
    	vect.push_back(temp);
	i++;
    }
    sort(vect.begin(), vect.end());
    vector<int>::iterator it = unique(vect.begin(), vect.end());
    while (it != vect.end())
    {
	it = vect.erase(it);
    }
    for (vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
    {
	cout << *it << endl;
    }
*/
// test 1
/*
    set<int> st = {2, 1, 5, 3};
    for (set<int>::iterator it = st.begin(); it != st.end(); ++it)
    {
	cout << *it << " ";
    }
    cout << endl;
    list<int> lst = {2, 1, 5, 3};
    for (list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
	cout << *it << " ";
    }
    cout << endl;
    vector<int> vect = {2, 1, 5, 3};
    for (vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
    {
	cout << *it << " ";
    }
    cout << endl;
*/
// solution 2
/*
    int num = 0;
    while (cin >> num)
    {
	set<int> st;
	int temp;
	while (num--)
	{
	    cin >> temp;
	    st.insert(temp); 
	}
	for (set<int>::iterator it = st.begin(); it != st.end(); ++it)
	{
	    cout << *it << endl;
	}
    }
*/
// solution 3
/*
    int num = 0;
    int a[1001];
    while (cin >> num)
    {
	for (int i = 0; i < 1001; i++)
	    a[i] = 0;
	int temp;
	while (num--)
	{
	    cin >> temp;
	    a[temp] = 1;
	}
	for (int i = 0; i < 1001; i++)
	{
	    if (a[i])
	    {
		cout << i << endl;
	    }
	}
    }
*/
//solution 4

    int num = 0;
    int temp;
    while (cin >> num)
    {
	int *a = new int[num];
	for (int i = 0; i < num; i++)
	{
	    cin >> temp;
	    a[i] = temp;
	}
	if (num >1)
	{
	    quickSort(a, 0, num - 1);
	    int pre = a[0];
	    for (int i = 1; i < num; i++)
	    {
		while (a[i] == pre)
		{
		    for (int j = i; j < num - 1; j++)
		    {
			a[j] = a[j + 1];
		    }
		    num--;
		}
		pre = a[i];
	    }
	}
	for (int i = 0; i < num; i++)
	    cout << a[i] << endl;
	delete [] a;
    }
/*
    int a[] = {2, 3, 2, 1, 7, 5, 2};
    quickSort(a, 0, 6);
    for (int i = 0; i < 7; i++)
	cout << a[i] << " ";
    cout << endl;
*/
    return 0;
}

void quickSort(int* arr, int a, int b)
{
    if (a >= b)
	return;
    int i = a + 1, j = b;
    while (i < j)
    {
	while (arr[j] >= arr[a] && j >= i)
	    j--;
	while (arr[i] <= arr[a] && i < j)
	    i++;
	if (i < j)
 	{
	    int temp = arr[i];
	    arr[i] = arr[j];
	    arr[j] = temp;
	}
    }
    if (arr[j] < arr[a])
    {
	int temp = arr[j];
    	arr[j] = arr[a];
    	arr[a] = temp;
    }
    quickSort(arr, a, j - 1);
    quickSort(arr, j + 1, b);
}
