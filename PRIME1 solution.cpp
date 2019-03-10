#include <iostream>
using namespace std;

bool isPrime(int a)
{
	if(a == 0 || a == 1) return false;
	if(a == 2) return true;

	for(int i = 2; i*i <= a; i++)
		if(a % i == 0)
			return false;

	return true;
}

int TC, m, n;
int main()
{
	cin >> TC;
	for (int itc = 1; itc <= TC; itc++)
	{
		cin >> m >> n;
		for (int i = m; i <= n; i++)
			if (isPrime(i)) cout << i << endl;
		cout << endl;
	}
}
