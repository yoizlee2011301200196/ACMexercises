#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
using namespace std;

int main()
{
    int aNum = 0, bNum = 0, cNum = 0, dNum = 0, eNum = 0, errNum = 0, priNum = 0;
    int ip[4] = {0}, code[4] = {0};
    string line;
    while (cin >> line)
    {
	string ipstr, codestr;
	bool ipflag = false, codeflag = false;
	istringstream is(line);
	getline(is, ipstr, '~');
	string s;
	int i = 0;
	istringstream is1(ipstr);
	while (getline(is1, s, '.'))
	{
	    if (s == "")
	    {
		break;
	    } else {
		int temp = atoi(s.c_str());
		if (temp < 0 || temp > 255)
		{
		    break;
		} else {
		    if (i < 4)
		    	ip[i] = temp;
		    i++;
		}
	    }
	}
	if (i != 4)
	{
	    errNum += 1;
	    continue;
	} else {
	    ipflag = true;
	}
	getline(is, codestr, '~');

	istringstream is2(codestr);
	string s1;
	int j = 0;
	while (getline(is2, s1, '.'))
	{
	    int temp = atoi(s1.c_str());
	    if (s1 == "")
		break;
	    else {
		if (temp < 0 || temp > 255)
            	{
                    break;
            	} else {
		    bitset<8> bs(temp);
		    int t = -1;
		    for (int i = bs.size() - 1; i >= 0; i--)
		    {
			if (bs[i] == 0)
			{
			    t = i;
			    break;
			}
		    }
		    for (int i = t - 1; i >= 0; i--)
		    {
			if (bs[i] != 0)
			{
			    temp = -1;
			    break;
			}
		    }
		    if (temp == -1)
			break;
		    else {
		    	code[j] = temp;
		    	j++;
		    }
		}
	    }
	}

	if (j != 4)
	{
	    errNum++;
	    continue;
	} else {
	    j = 0;
	    while (j < 4 && code[j] == 255)
	    {
		j++;
	    }
	    for (int i = j + 1; i < 4; i++)
	    {
		if (code[i] != 0)
		{
		    j = -1;
		    break;
		}
	    }

	    if (j == -1 || code[3] == 255)
	    {
		errNum++;
		continue;
	    } else {
		codeflag = true;
	    }
	}
	if (ipflag && codeflag)
	{
	    if (ip[0] >= 1 && ip[0] <= 126)
            {
                aNum++;
		if (ip[0] == 10)
		    priNum++;
            } else if (ip[0] >= 128 && ip[0] <= 191) {
                bNum++;
		if (ip[0] == 172 && ip[1] >= 16 && ip[1] <= 31)
		    priNum++;
            } else if (ip[0] >= 192 && ip[0] <= 223) {
                cNum++;
		if (ip[0] == 192 && ip[1] == 168)
		    priNum++;
            } else if (ip[0] >= 224 && ip[0] <= 239) {
                dNum++;
            } else if (ip[0] >= 240 && ip[0] <= 255) {
                eNum++;
            }
	}
    }    
    cout << aNum << " " << bNum << " " << cNum << " " << dNum << " " << eNum << " " << errNum << " " << priNum << endl;

    return 0;
}
