#include <iostream>
using namespace std;
#define MAX 50000
#define PP 1000000007

int A[MAX+1];
int P[MAX], nP, VT[MAX+1];
int Dem[MAX];
int KQ[MAX+1];
int n;

int main()
{
	//freopen("input.txt","r",stdin);
	
	//sang nguyen to
	for (int i = 0; i <= MAX; i++) A[i] = 1;
	for (int i = 2; i * i <= MAX; i++)
		if (A[i])
			for (int j = 2; j <= MAX / i; j++)
				A[i*j] = 0;
	nP = 0;
	for (int i = 2; i <= MAX; i++)
		if (A[i]) P[nP++] = i;


	for (int i = 0; i < nP; i++) Dem[i] = 0;
	for (int i = 0; i < nP; i++) VT[P[i]] = i;

	for (int in = 2; in <= MAX; in++)
	{
		int a = in, iP = 0;
		while (a != 1)
		{
			
			if (P[iP] * P[iP] > a)
			{
				Dem[VT[a]]++;
				break;
			}

			if (a % P[iP] == 0)
			{
				a = a / P[iP];
				Dem[iP]++;
			}
			else iP++;

		}

		long long int T = 1;
		for (int i = 0; i < nP; i++)
			if (Dem[i]) T = (T * (Dem[i] + 1) ) % PP;

		KQ[in] = T;
	}
	KQ[0] = KQ[1] = 1;


	int TC;
	cin >> TC;
	for (int itc = 0; itc < TC; itc++)
	{
		cin >> n;
		cout << KQ[n] << endl;
	}

	return 0;
}
