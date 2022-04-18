#include <iostream>
using namespace std;

int isP[1001], nP, P[1001], dem;
int C[1001], A[1000001];


int cald(int x)
{
	int i = 0, T = 1;

	for (int i = 0; i < nP; i++) C[i] = 0;

	while (x != 1)
	{
		//if (P[i] * P[i] > x) {T = 2; break;}
		if (x % P[i] == 0)
		{
			x /= P[i];
			C[i]++;
		}
		else i++;
		if (i == nP) {T = 2; break;}
	}

	for (int i = 0; i < nP; i++) T = T * (C[i] + 1);
	return T;
}

int main()
{
	//Sieve of Eratosthenes
	for (int i = 2; i <= 1000; i++) isP[i] = 1;
	for (int i = 2; i * i <= 1000; i++)
		for (int j = 2; j <= 1000 / i; j++)
			isP[i * j] = 0;
	isP[0] = isP[1] = 0;

	nP = 0;
	for (int i = 2; i <= 1000; i++)
		if (isP[i])
			P[nP++] = i;

	for (int i = 0; i < 1000000; i++)
		A[i] = 0;

	for (int i = 0; i < nP - 1; i++)
		for (int j = i + 1; j < nP; j++)
			A[P[i] * P[j]] = 1;

	dem = 0;
	for (int x = 2; x <= 1000000; x++)
	{
		int a = cald(x);
		if (A[a])
		{
			dem++;
			if (dem % 9 == 0) cout << x << endl;
		}
	}

	return 0;
}
