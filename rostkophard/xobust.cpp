#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;




int main()
{
	std::vector <int> pq;

	int n;

	cin >> n;

	int beg_votes;

	cin >> beg_votes;

	for (int i = 1; i < n; i++)
	{
		int votes;
		cin >> votes;
		pq.push_back(votes);
	}

	std::make_heap(pq.begin(), pq.end());

	int res = 0;

	while (pq.front() >= (beg_votes+res))
	{
		
		pq.push_back(pq.front()-1);
		std::push_heap(pq.begin(), pq.end());

		std::pop_heap(pq.begin(), pq.end());
		pq.pop_back();

		res++;
	}


	cout << res;


	return 0;
}

