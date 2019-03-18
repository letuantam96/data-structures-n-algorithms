#include <iostream>
using namespace std;

long long int n;
//int dem = 0;

long long int Exchange(long long int n)
{
	//dem++;
	long long int n1 = n / 2;
	long long int n2 = n / 3;
	long long int n3 = n / 4;
	if (n1 + n2 + n3 <= n) return n;
	else return Exchange(n1) + Exchange(n2) + Exchange(n3);
}

int main()
{
//	freopen("input.txt","r",stdin);
	while (cin >> n)
	{
		long long int a = Exchange(n);
		cout << a << endl;
	}
	return 0;
}
