#include <iostream>
using namespace std;

char c;
int flag;
int R[100][100];
int n, m;
int nD;
int xD[11], yD[11];
int xR, yR;
int nW, xW[10000], yW[10000];
int A[100][100];
int Dir[2][4] = 
{{-1, +0, +1, +0},
{+0, +1, +0, -1}};
int B[10][10];
int Color[10];
int Path[10];
int T, minT;

int Q[10000];
int fr = 0, re = -1;

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

void BFS(int x, int y)
{
	int td = x*m + y;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			R[i][j] = -1;

	pushQ(td);
	R[x][y] = 0;
	while (fr - re != 1)
	{
		int a = popQ();
		int xx = a / m; int yy = a % m;

		for (int i = 0; i < 4; i++)
		{
			int xxN = xx + Dir[0][i];
			int yyN = yy + Dir[1][i];

			if (xxN > -1 && xxN < n && yyN > -1 && yyN < m && !A[xxN][yyN] && R[xxN][yyN] == -1)
			{
				pushQ(xxN * m + yyN);
				R[xxN][yyN] = R[xx][yy] + 1;
			}
		}
	}
}

void Try(int k)
{
	if (T < minT)
	{
		for (int i = 0; i < nD; i++)
		{
			if (!Color[i])
			{
				T += B[Path[k-1]][i];
				Color[i] = 1;
				Path[k] = i;

				if (k == nD - 1)
				{
					if (T < minT)
						minT = T;
				}
				else
				{
					Try(k+1);
				}

				T -= B[Path[k-1]][i];
				Color[i] = 0;
			}
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	while (1)
	{
		flag = 1;


		cin >> n >> m;
		if (n == 0) break;
		nD = 1;
		nW = 0;

		int tg = n; n = m; m = tg;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				A[i][j] = 0;
			}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> c;
				if (c == '*') //dirt
				{
					xD[nD] = i;
					yD[nD] = j;
					nD++;
								A[i][j] = 0;
				}
				else if (c == 'x') //wall
				{
					xW[nW] = i;
					yW[nW] = j;
					nW++;
					A[i][j] = 2;
				}
				else if (c == 'o') //robot
				{
					xR = i;
					yR = j;
								A[i][j] = 0;
				}
			}

		xD[0] = xR;
		yD[0] = yR;
		nD;

		for (int i = 0; i < nD; i++)
		{
			int x = xD[i];
			int y = yD[i];

			BFS(x, y);

			for (int ii = 0; ii < nD; ii++)
			{
				B[i][ii] = R[xD[ii]][yD[ii]];
				if (R[xD[ii]][yD[ii]] == -1) flag = 0;
			}

		}

		for (int i = 0; i < nD - 1; i++) Color[i] = 0;

		T = 0, minT = 9999999;

		if (flag == 0) minT = -1;
		else
		{
		Path[0] = 0; Color[0] = 1;
		Try(1);
		}
		if (minT == 9999999) minT = -1;
		cout << minT << endl;


	}
	return 0;
}
