#include<iostream>
using namespace std;

void move(int from, int to) {
	cout << from << "->" << to << endl;
}
void Hanoi(int n, int from, int to, int by) {
	if (n == 1) move(from, to);
	else {
		Hanoi(n - 1, from, by, to);
		move(from, to);
		Hanoi(n - 1, by, to, from);
	}
}
int main(void) {
	Hanoi(3, 1, 3, 2);
}