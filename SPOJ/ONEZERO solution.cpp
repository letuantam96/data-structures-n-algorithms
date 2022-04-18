#include <iostream>
using namespace std;

int n;
int R[20001];

struct mtype
{
	int C[10000];
	int l;
	int r;
};


mtype x;

mtype Q[10000];
int fr, re;

//void pushQ(mtype a)
//{
//	re = (re + 1) % 10000;
//	Q[re] = a;
//}

//mtype popQ()
//{
//	mtype a = Q[fr];
//	fr = (fr + 1) % 10000;
//	return a;
//}

int main()
{
//	freopen("input.txt","r",stdin);
	int TC;
	cin >> TC;
	for (int itc = 0; itc < TC; itc++)
	{
		cin >> n;
		for (int i = 0; i <= n; i++) R[i] = 0;

		fr = 0; re = -1;

		x.C[1] = 1;
		x.l = 1;
		x.r = 1;

		//pushQ(x);
		re = (re + 1) % 10000;
		for (int i = 1; i <= x.l; i++)
			Q[re].C[i] = x.C[i];
		Q[re].l = x.l;
		Q[re].r = x.r;


		R[1] = 1;

		while (1)
		{
			//x = popQ();
			for (int i = 1; i <= Q[fr].l; i++) x.C[i] = Q[fr].C[i];
			x.l = Q[fr].l;
			x.r = Q[fr].r;
			fr = (fr + 1) % 10000;

			if (x.r % n == 0) break;
			else 
			{
				mtype y;
				for (int i = 1; i <= x.l; i++)
					y.C[i] = x.C[i];
				y.l = x.l + 1;
				y.C[y.l] = 0;
				y.r = (x.r * 10 % n);
				if (R[y.r] == 0)
				{//pushQ(y);
					re = (re + 1) % 10000;
					for (int i = 1; i <= y.l; i++)
						Q[re].C[i] = y.C[i];
					Q[re].l = y.l;
					Q[re].r = y.r;
				}
				R[y.r] = 1;
				y.C[y.l] = 1;
				y.r = (x.r * 10 + 1) % n;
				if (R[y.r] == 0)
				{//pushQ(y);
					re = (re + 1) % 10000;
					for (int i = 1; i <= y.l; i++)
						Q[re].C[i] = y.C[i];
					Q[re].l = y.l;
					Q[re].r = y.r;
				}
				R[y.r] = 1;
			}
		}
		for (int i = 1; i <= x.l; i++) cout << x.C[i];
		cout << endl;
	}
	return 0;
}
