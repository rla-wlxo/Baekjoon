#include <iostream>
using namespace std;

int main()
{
	int K;
	cin >> K;
	int count = 0;

	int squared = 1;
	while (squared < K)
	{
		squared *= 2;
	}

	if (squared == K)
		cout << squared << " " << 0;
	else
	{
		int temp = squared;
		int ans = 0;
		while (K > 0)
		{
			if (K >= temp)
				K -= temp;
			else
			{
				temp /= 2;
				count++;
			}
		}
	}
	cout << squared << " " << count;
}