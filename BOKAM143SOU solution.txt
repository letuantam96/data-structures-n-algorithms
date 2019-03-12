#include<iostream>
using namespace std;

int N, T;
int A[100];
int dem;

void Try(int k)
{
	for (int i = A[k-1]; i >= 0; i--)
		if (T + i*i*i <= N)
		{
			A[k] = i;
			T = T + i*i*i;

			if (T == N || k == 5)
			{
				if (T == N) dem++;
			}
			else Try(k+1);

			T = T - i*i*i;
		}
}

int main()
{
		cin >> N;
		
		T = 0;
		dem = 0;
		A[0] = 50;
		Try(1);
		cout << dem << endl;
}
