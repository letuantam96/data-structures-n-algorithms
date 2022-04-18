#include <iostream>
using namespace std;

class Stack {
public:
	int arr[1000];
	int top;
	Stack() { top = -1; }
	void push(int a) { arr[++top] = a; }
	int pop() {	return arr[top--]; }
};

int main() {
	int num, buff;

//	freopen("input.txt", "r", stdin);
	while (1) {
		Stack A, B;
		A.push(0);
		bool check = true;
		cin >> num;
		if (num == 0) break;
		for (int i = 1; i <= num; i++) {
			cin >> buff;
			if (buff == (A.arr[A.top] + 1)) A.push(buff);
			else if (B.top == -1) B.push(buff);
			else if (buff < (B.arr[B.top])) B.push(buff);
			else {
				/*cout << A.arr[A.top];
				cout << B.arr[B.top];
				cout << buff;*/
				check = false;
			}
			while ((B.top > -1) && (B.arr[B.top] == (A.arr[A.top] + 1))) {
					A.push(B.pop());
					//cout << "[" << A.arr[A.top] << "]";
			}

		}
		if (check == true) cout << "yes\n";
		else cout << "no\n";
	}
}
