#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
int N, K;

std::vector<int> arr;
 
 
int main() {
    
    std::cin.sync_with_stdio(false);
    
    cin >> N >> K;

	for(int i = 0; i<N; i++)
	{
		char c;
		cin >> c;

		switch (c)
		{
		case 'U':
			arr.push_back(0);
			break;
		case 'V':
			arr.push_back(3);
			break;
		case 'H':
			arr.push_back(1);
			break;
		case 'N':
			arr.push_back(2);
			break;
		}
	}

	int result = 0;

	for(int i = 0; i<N;i++)
	{
		if(arr[i] != 0)
		{
			int dif =  4 - arr[i];
			result += dif;
			if(i+K <= N)
			{
				for(int j = i; j<i+K; j++)
				{
					arr[j] += dif;
					if(arr[j] >= 4)
						arr[j] -= 4;
				}
			}
			else
			{
				result = -1;
				break;
			}
		}
	}
	
	cout<< result;
    
    return 0;
}