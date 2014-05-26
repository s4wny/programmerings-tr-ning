#include <iostream>
#include <map>
#include <string>

using namespace std;


map<string, char> runes;

char getrune(string s)
{
	if(runes.find(s) != runes.end())
		return runes[s];
	

	return '?';

}


int main()
{
	unsigned int T;

    scanf( "%d", &T );

	for(int i = 0; i<T; i++)
	{
		char C;
		string B;

		cin>> C >> B;
		runes[B] = C;
	}

	string binary;

	cin >> binary;

	string result = "";

	for(int i = 0; i<binary.length(); i+=4)
	{
		string sub = "";
		for(int j = i;j<i+4;j++)
		{
			sub += binary[j];
		}


		result += getrune(sub);
	}
	
	cout << result;

	cin >> T;

	return 0;
}

