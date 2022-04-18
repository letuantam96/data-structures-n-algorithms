#include <iostream>
using namespace std;
 
char c;
long long int A[5002];
int i;
int N[5002];
 
int main()
{
//	freopen("input.txt","r",stdin);
	while (1)
	{
			for (int i = 0; i <= 5001; i++) A[i] = 0;
 
 
		A[0] = 1;
		cin >> c;
		if (c == '0') break;
		A[1] = 1; N[1] = c - 48;
		i = 2;
		while (1)
		{
			c = cin.get();
			if (c == '\n') break;
			int x = c - 48;
 
		
 
			if (x > 0) A[i] = A[i - 1];
			if (x + N[i - 1] * 10 < 27 && x + N[i - 1] * 10 > 9)
				A[i] += A[i - 2];
 
			N[i] = x;
			i++;
		}
		cout << A[i - 1] << endl;
	}
	return 0;
} 
