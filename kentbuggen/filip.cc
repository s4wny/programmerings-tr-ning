#include <iostream>
#include <map>

using namespace std;

int main()
{
	int N;
	cin >> N;
	map<string, int> m;
	string readIn;
	for(int i = 0; i < N; i++)
	{
		cin >> readIn;
		if(m.find(readIn) != m.end())
			m[readIn] = 1;
		else
			m[readIn] = 0;
	}
	int count = 0;
	
	for(map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
		count += it->second;
	cout << count;
	return 0;
}
