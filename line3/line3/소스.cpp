#include <iostream>
struct table1 {
	int id;
	char name[20];
	char occupation[20];
};
struct table2 {
	int id;
	char city[20];
	char zip[6];
};
using namespace std;

void bubbleSort(table1* t1, int N) {
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - i - 1; j++)
			if (t1[j].id > t1[j + 1].id)
				swap(t1[j], t1[j + 1]);
}
int main(void) {
	int N, M;
	char trash[3][20];
	char trash2[3][20];

	cin >> N;
	table1* t1 = new table1[N];
	for (int i = 0; i < 3; i++)
		cin >> trash[i];
	for (int i = 0; i < N - 1; i++) {
		cin >> t1[i].id;
		cin >> t1[i].name;
		cin >> t1[i].occupation;
	}
	bubbleSort(t1, N - 1);

	cin >> M;
	table2* t2 = new table2[M];
	for (int i = 0; i < 3; i++)
		cin >> trash2[i];
	for (int i = 0; i < M - 1; i++) {
		cin >> t2[i].id;
		cin >> t2[i].city;
		cin >> t2[i].zip;
	}

	cout << trash[0] << " " << trash[1] << " " << trash[2] << " " << trash2[1] << " " << trash2[2] << endl;
	for (int i = 0; i < N - 1; i++) {
		int cnt = 0;
		for (int j = 0; j < M - 1; j++) {
			if (t2[j].id == t1[i].id) {
				cout << t1[i].id << " " << t1[i].name << " " << t1[i].occupation << " " << t2[j].city << " " << t2[j].zip << endl;
				cnt++;
			}
		}
		if (cnt == 0)
			cout << t1[i].id << " " << t1[i].name << " " << t1[i].occupation << " NULL NULL" << endl;
	}

	return 0;
}