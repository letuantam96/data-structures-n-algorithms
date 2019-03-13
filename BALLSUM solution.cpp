#include <iostream>
using namespace std;

long long int n, k;
long long int T, S, U;

long long int UCLN (long long int a, long long int b)
{
	if (b == 0) return a;
	return UCLN(b, a % b);
}

int main()
{
//	freopen("input.txt","r",stdin);
	while (1)
	{
		cin >> n >> k;
		if (n == -1) break;

		T = S = U = 0;
		if (n >= 2 && k >= 3)
		{
			int a = k / 2;
			T = ((k-1)*k/2 - a)/2;
			S = n*(n-1)/2;


			U = UCLN(T, S);
			T = T / U;
			S = S / U;
		} else T = 0;

		if (T == 0) cout << "0" << endl;
		else cout << T << "/" << S << endl;
	}
	return 0;
}
