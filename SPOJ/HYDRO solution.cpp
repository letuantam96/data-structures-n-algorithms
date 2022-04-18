#include <iostream>

int TC, n, A[10000], T, imax;

int main()
{
	std::cin >> TC;
	for (int itc = 0; itc < TC; itc++)
	{
		T = 0; imax = 0;
		std::cin >> n;
		for (int i = 0; i < n; i++)
		{
			std::cin >> A[i];
			if (A[i] > A[imax]) imax = i;
		}

		for (int i = 0; i <= imax - 1; i++)
			if (A[i] > A[i+1])
			{
				T += A[i] - A[i+1];
				A[i+1] = A[i];
			}
		for (int i = n - 1; i >= imax + 1; i--)
			if (A[i] > A[i-1])
			{
				T += A[i] - A[i-1];
				A[i-1] = A[i];
			}
		std::cout << T << std::endl;
	}
	return 0;
}
