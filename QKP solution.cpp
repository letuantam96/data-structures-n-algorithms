#include <iostream>
using namespace std;

int n, m;
int Q[1000][2], K[1000][2];
int demQ, demK, demP;
int A[1000][1000];
int dx[8] = {-1, -1, +0, +1, +1, +1, +0, -1};
int dy[8] = {+0, +1, +1, +1, +0, -1, -1, -1};
int kx[8] = {-2, -1, +1, +2, +2, +1, -1, -2};
int ky[8] = {+1, +2, +2, +1, -1, -2, -2, -1};

int main()
{
//	freopen("input.txt","r",stdin);
	int itc = 0;
	while (1)
	{
		cin >> n >> m;
		if (n == 0) break;
		itc++;

		//khoitao
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				A[i][j] = 0;


		cin >> demQ;
		for (int i = 0; i < demQ; i++)
		{
			cin >> Q[i][0] >> Q[i][1];
			Q[i][0]--; Q[i][1]--;
			A[Q[i][0]][Q[i][1]] = 2; //queen
		}
		cin >> demK;
		for (int i = 0; i < demK; i++)
		{
			cin >> K[i][0] >> K[i][1];
			K[i][0]--; K[i][1]--;
			A[K[i][0]][K[i][1]] = 3; //knight
		}
		cin >> demP;
		for (int i = 0; i < demP; i++)
		{
			int a, b;
			cin >> a >> b;
			A[a-1][b-1] = 4; //paws
		}


		for (int i = 0; i < demQ; i++)
		{

			for (int k = 0; k < 8; k++)
			{
				int x = Q[i][0];
				int y = Q[i][1];
				while (1)
				{
					x += dx[k];
					y += dy[k];
					if (x < 0 || x >= n || y < 0 || y >= m || A[x][y] > 1) break;
					A[x][y] = 1;
				}
			}
		}

		for (int i = 0; i < demK; i++)
		{
			int x = K[i][0];
			int y = K[i][1];
			for (int k = 0; k < 8; k++)
			{
				int xN = x + kx[k];
				int yN = y + ky[k];

				if (xN > -1 && xN < n && yN > -1 && yN < m && A[xN][yN] < 2)
					A[xN][yN] = 1;
			}
		}

		int dem = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (A[i][j] == 0) dem++;

		cout << "Board " << itc << " has " << dem << " safe squares." << endl;
	}
	return 0;
}
