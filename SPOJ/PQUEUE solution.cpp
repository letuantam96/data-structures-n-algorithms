#include <iostream>
using namespace std;
#define MAX 1000000

int A[11], a, dem, flag;
int n, m;
int Q[MAX];
int fr, re;

void pushQ(int x)
{
	re = (re + 1) % MAX;
	Q[re] = x;
}

int popQ()
{
	int a = Q[fr];
	fr = (fr + 1) % MAX;
	return a;
}

int isPrint()
{
	for (int i = Q[fr] + 1; i < 11; i++)
		if (A[i] > 0) return 0;
	return 1;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int TC;
	cin >> TC;
	for (int itc = 0; itc < TC; itc++)
	{

		fr = 0; re = -1;
		for (int i = 0; i < 11; i++)
			A[i] = 0;

		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			A[a]++;
			pushQ(a);
		}
		
		dem = 0;
		flag = 1;
		while(1)
		{
			if (isPrint())
			{
				int a = popQ();
				dem++;
				m--;
				n--;
				A[a]--;
				if (m == -1) break;
			}
			else
			{
				int a = popQ();
				pushQ(a);
				m--;
				if (m == -1) m = n - 1;
			}
		}
		cout << dem << endl;
	}
	return 0;
}
