#include <iostream>
using namespace std;

int P[10000];
int n, m;
int Color[10000], Rank[10000];
int Q[9999], fr, re;

void pushQ(int x)
{
	re = (re + 1) % 9999;
	Q[re] = x;
}

int popQ()
{
	int a = Q[fr];
	fr = (fr + 1) % 9999;
	return a;
}

int canJump(int a, int b)
{
	int x = a, y = b;
	int dem = 0;
	if (x % 10 != y % 10) dem++; 
	x = x / 10; y = y / 10; if (x % 10 != y % 10) dem++;
	x = x / 10; y = y / 10; if (x % 10 != y % 10) dem++;
	x = x / 10; y = y / 10; if (x % 10 != y % 10) dem++;

	if (dem == 1) return 1;
	else return 0;
}

int main()
{
	//freopen("input.txt","r",stdin);

	for (int i = 0; i <= 9999; i++) P[i] = 1;
	for (int i = 2; i * i <= 9999; i++)
		if (P[i])
			for (int j = 2; j <= 9999 / i; j++)
				P[i * j] = 0;
	P[0] = P[1] = 0;

	int TC;
	cin >> TC;
	for (int itc = 0; itc < TC; itc++)
	{
		cin >> n >> m;

		for (int i = 0; i < 10000; i++) 
		{
			Color[i] = 0;
			Rank[i] = -1;
		}
		fr = 0; re = -1;

		pushQ(n);
		Color[n] = 1;
		Rank[n] = 0;

		while (fr - re != 1)
		{
			int a = popQ();
			for (int i = 1000; i < 9999; i++)
			{
				if (P[i] && !Color[i] && canJump(a, i))
				{
					pushQ(i);
					Color[i] = 1;
					Rank[i] = Rank[a] + 1;
				}
			}
		}

		if (Rank[m] == -1) cout << "Impossible" << endl;
		else cout << Rank[m] << endl;

	}
	return 0;
}
