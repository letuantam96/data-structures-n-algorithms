#include <iostream>
using namespace std;
#define INF 1000000001

int n, c;
int st, en;
int A[100000], dL[50001], dR[50001];
int maxL;

void merge(int l, int m, int r)
{
	int i, iL = 0, iR = 0;
	for (i = 0; i <= m - l; i++) dL[i] = A[l + i]; dL[i] = INF;
	for (i = 0; i <= r - m - 1; i++) dR[i] = A[m + 1 + i]; dR[i] = INF;
	for (i = l; i <= r; i++)
		if (dL[iL] < dR[iR]) A[i] = dL[iL++];
		else A[i] = dR[iR++];
}

void mSort(int l, int r)
{
	if (l == r) return;
	int m = (l + r) / 2;
	mSort(l, m);
	mSort(m + 1, r);
	merge(l, m, r);
}

void find(int st, int en)
{
	if (st > en) return;

	int mi = (st + en) / 2;
	int num = c - 1, buf = A[0];
	for (int i = 1; i < n; i++)
		if (A[i] - buf >= mi)
		{
			num--;
			buf = A[i];
		}
	if (num <= 0)
	{
		find(mi + 1, en);
		maxL = maxL > mi ? maxL : mi;
	}

	else find(st, mi - 1);
}


int main()
{
//	freopen("input.txt","r",stdin);
	int TC;
	cin >> TC;
	for (int itc = 0; itc < TC; itc++)
	{
		cin >> n >> c;
		for (int i = 0; i < n; i++)
			cin >> A[i];

		mSort(0, n - 1);

		st = 1; en = (A[n-1] - A[0]) / (c - 1);
		maxL = 1;
		find(1, en);
		cout << maxL << endl;
	}
	return 0;
}
