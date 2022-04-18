#include <iostream>
#define MAX 1000000
using namespace std;

int A[MAX];
int TC;
int N;
int s, e, max_s;

int main()
{
//	freopen("input.txt","r",stdin);
	cin >> TC;
	for (int itc = 1; itc <= TC; itc++)
	{
		cin >> N;
		for (int i = 0; i <= MAX; i++) A[i] = 0;
		max_s = 0;

		for (int i = 1; i <= N; i++)
		{
			cin >> s >> e;
			if ((!A[s]) || (e < A[s])) A[s] = e; 
			if (s > max_s) max_s = s;
		}

		int dem = 0;
		e = 0;
		for (int i = 0; i <= max_s; i++)
			if (A[i])
			{
				if (i >= e)
				{
					dem++;
					e = A[i];
				}
				else if (A[i] < e) e = A[i];
			}
		cout << dem << endl;
	}
}
