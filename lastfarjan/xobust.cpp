#include <iostream>

int main()
{
	int N, L, a;
	std::cin >> N >> L;
	int sum = -4; // -4 Eftersom jag tar bort det tomrumet jag lägger på de sista bilarna i varje kö
	L *= 4; // Vi är bara intresserade av den totala längden
	for (int i = 0; i < N;i++)
	{
		std::cin >> a;
		sum += a + 1;

		if (sum > L )
		{
			std::cout << i; break;
		}
	}
	return 0;
}