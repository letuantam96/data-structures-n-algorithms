#include <iostream>
using namespace std;
#define INF 999999

int n, u, v, maxR, maxP;
int Dem[10000];
int B[10000][10000];
int Color[10000];
int Rank[10000];

int S[10000], top;

void pushS(int x)
{
	S[++top] = x;
}

int popS()
{
	return S[top--];
}


void DFS(int s)
{
	for (int i = 0; i < n; i++) Color[i] = 0;

	top = -1;
	pushS(s);
	Color[s] = 1;
	Rank[s] = 1;
	maxR = -INF;
	maxP = s;
	while (top != -1)
	{
		int a = popS();
		for (int i = 0; i < Dem[a]; i++)
		{
			if (!Color[B[a][i]])
			{
				pushS(B[a][i]);
				Color[B[a][i]] = 1;
				Rank[B[a][i]] = Rank[a] + 1;
				if (Rank[B[a][i]] > maxR)
				{
					maxR = Rank[B[a][i]];
					maxP = B[a][i];
				}
			}
		}
	}
}

int main()
{
	//freopen("input.txt","r",stdin);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		u--; v--;
		B[u][Dem[u]] = v;
		B[v][Dem[v]] = u;
		Dem[u]++;
		Dem[v]++;
	}

	DFS(0);
	DFS(maxP);
	cout << maxR - 1 << endl;
}
