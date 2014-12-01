// skolvägen.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

char revers(char c)
{
    if(c == 'N')
		return 'S';
	else
		return 'N';
}


int main()
{

	string s;

	cin>>s;


	char state = 'N';

	int ans = 0;

	for(int i = 0; i<s.length(); i++)
	{

		if(s[i] == state)
		{

			if(i == s.length()-1)
			{
				if(state == 'S')
					state = revers(state);

				ans++;
				break;

			}

			for(int j = i+1; j<s.length(); j++)
			{
				if(s[j] == state)
				{
					state = revers(state);
					break;
				}else if(s[j] == revers(state))
				{
					break;
				}else if(j == s.length() -1 && s[j] == 'B')
				{
					if(state == 'S')
						state=revers(state);
				}
			}

			ans ++;
		}else if (s[i] == 'B')
			ans++;
	}

	if(state == 'S')
		ans++;

	cout << ans;

	return 0;
}

