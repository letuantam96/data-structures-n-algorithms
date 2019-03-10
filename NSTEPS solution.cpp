#include <iostream>
using namespace std;

int main() {
//	freopen("input.txt", "r", stdin);
	int head, x, y, num;
	cin >> head;
	for (int tc = 1; tc <= head; tc++) {
		cin >> x;
		cin >> y;
		if (x == y) {
			num = x / 2;
			cout << x + 2 * num << endl;
		}
		else if ((x - y) == 2) {
			num = y / 2;
			cout << 2 + y + 2 * num << endl;
		}
		else cout << "No Number" << endl;
	}
}
