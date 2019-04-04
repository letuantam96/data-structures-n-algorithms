#include <iostream>
using namespace std;

int A[10000], B[10000], n, nB;
int imax, T;

void cal()
{
	for (int i = 0; i < nB - 1; i++)
		if (B[i] > B[i+1])
		{
			T += (B[i] - B[i+1]);
			B[i+1] = B[i];
		}
}

int main()
{
	//freopen("input.txt","r",stdin);
	int TC;
	cin >> TC;
	for (int itc = 0; itc < TC; itc++)
	{
		imax = 0, T = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> A[i];
			if (A[i] > A[imax]) imax = i;
		}

		for (int i = 0; i <= imax; i++)
			B[i] = A[i];
		nB = imax + 1;
		cal();

		for (int i = n - 1; i >= imax; i--)
			B[n - 1 - i] = A[i];
		nB = n - imax;
		cal();

		cout << T << endl;
	}
	return 0;
}
