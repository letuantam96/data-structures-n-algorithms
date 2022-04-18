#include <iostream>
#include <string>
using namespace std;

int main() {
	int cot, hang;
	char A[50][20];
	string s;
//	freopen("input.txt", "r", stdin);
	while (1) {
		cin >> cot;
		if (cot == 0) break;
		cin >> s;
		hang = s.size() / cot;
		for (int i = 0; i < hang; i++) {
			for (int j = 0; j < cot; j++) {
				if (i % 2 == 0) A[i][j] = s[i*cot + j];
				else A[i][cot - 1 - j] = s[i*cot + j];
			}
		}
		

		for (int j = 0; j < cot; j++) {
			for (int i = 0; i < hang; i++) {
				cout << A[i][j];
			}
		}
		cout << "\n";
	}
}
