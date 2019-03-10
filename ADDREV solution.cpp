#include <iostream>
using namespace std;

int reversed(int a) {
	int temp = 0;
	while (a > 0) {
		temp = temp * 10 + a % 10;
		a = a / 10;
	}
	return temp;
}

int main() {
//	freopen("input.txt", "r", stdin);
	int head, num1, num2;
	cin >> head;
	for (int tc = 1; tc <= head; tc++) {
		cin >> num1;
		cin >> num2;
		cout << reversed(reversed(num1) + reversed(num2)) << endl;
	}
}
