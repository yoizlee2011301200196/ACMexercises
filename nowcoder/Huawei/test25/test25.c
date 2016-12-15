#include <iostream>
#include <string>
using namespace std;

void encrypt(const char aucPassword[], char aucResult[])
{
    int i = 0;
    for (; aucPassword[i] != '\0'; i++)
    {
	if (aucPassword[i] >= '0' && aucPassword[i] <= '9')
	{
	     aucResult[i] = '0' + (aucPassword[i] + 1 - '0') % 10;
	} else if (aucPassword[i] >= 'A' && aucPassword[i] <= 'Z') {
	     aucResult[i] = 'a' + (aucPassword[i] + 33 - 'a') % 26;
	} else if (aucPassword[i] >= 'a' && aucPassword[i] <= 'z') {
	     aucResult[i] = 'A' + (aucPassword[i] -31 - 'A') % 26;
	} else {
	     aucResult[i] = aucPassword[i];
	}
    }
    aucResult[i] = '\0';
    
}

void unEncrypt(const char password[], char result[])
{
    int i = 0;
    for (; password[i] != '\0'; i++)
    {
	if (password[i] >= '0' && password[i] <= '9')
	{
	    result[i] = '0' + (password[i] + 10 - 1 - '0') % 10;
	} else if (password[i] >= 'A' && password[i] <= 'Z') {
	    result[i] = 'a' + (password[i] +32 +26 - 1 - 'a') % 26;
	} else if (password[i] >= 'a' && password[i] <= 'z') {
	    result[i] = 'A' + (password[i] - 'a' + 26 - 1) % 26;
	} else {
	    result[i] = password[i];
	}
    }
    result[i] = '\0';
}

int main()
{
    string password;
    while (cin >> password)
    {
	char *enc = new char[password.size() + 1];
	encrypt(password.c_str(), enc);
	for (int i = 0; enc[i] != '\0'; i++)
	    cout << enc[i];
	cout << endl;
	string encry;
	cin >> encry;
	char *unenc = new char[encry.size() + 1];
  	unEncrypt(encry.c_str(), unenc);
	for (int i = 0; unenc[i] != '\0'; i++)
	{
	    cout << unenc[i];
	}
	cout << endl;
	delete [] enc;
    }

    return 0;
}
