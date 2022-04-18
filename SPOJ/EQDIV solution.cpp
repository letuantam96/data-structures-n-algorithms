#include <iostream>
using namespace std;

int n;
int u, v;
int A[100][100], Color[100][100];
int du[4] = {-1, 0, +1, 0};
int dv[4] = {0, +1, 0, -1};

int Q[10000];
int fr, re;
int dem, flag;

void pushQ(int x)
{
	re = (re + 1) % 10000;
	Q[re] = x;
}

int popQ()
{
	int a = Q[fr];
	fr = (fr + 1) % 10000;
	return a;
}

int main()
{
//	freopen("input.txt","r",stdin);
	while (1)
	{
		cin >> n;
		if (n == 0) break;
		flag = 1;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				A[i][j] = n-1;
				Color[i][j] = 0;
			}


		for (int in = 0; in < n - 1; in++)
		{
			for (int i = 0; i < n; i++)
			{
				cin >> u >> v;
				u--; v--;
				A[u][v] = in;

				
			}
			do
			{
			} while (cin.get() != '\n');
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!Color[i][j])
				{
					fr = 0; re = -1;
					pushQ(i*n+j);
					Color[i][j] = 1;
					dem = 0;

					while (fr - re != 1)
					{
						int a = popQ();
						dem++;
						u = a / n;
						v = a % n;
						for (int k = 0; k < 4; k++)
						{
							int uN = u + du[k];
							int vN = v + dv[k];
							if (uN > -1 && uN < n && vN > -1 && vN < n && !Color[uN][vN] && A[u][v] == A[uN][vN])
							{
								pushQ(uN*n+vN);
								Color[uN][vN] = 1;
							}
						}
					}
					if (dem != n) flag = 0;
				}
				if (flag == 0) break;
			}
			if (flag == 0) break;
		}

		if (flag) cout << "good" << endl;
		else cout << "wrong" << endl;
	}
	return 0;
}
