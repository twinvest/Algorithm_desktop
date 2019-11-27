#include<cstdio>
#include<queue>
using namespace std;
queue<int> q;
int day=1;
void bfs(int arr[][6])
{
	while (!q.empty())
	{
		int a, b;
		a = q.back();
		q.pop();
		b = q.back();
		q.pop();

		if (arr[a][b + 1] == 0 && (b + 1 != 6))//오른쪽
		{
			arr[a][b + 1] = day + 1;//방문
			q.push(a);
			q.push(b + 1);
		}
		if (arr[a][b - 1] == 0 && (b - 1 != -1))//왼쪽
		{
			arr[a][b - 1] = day + 1;//방문
			q.push(a);
			q.push(b - 1);
		}
		if (arr[a + 1][b] == 0 && (a + 1 != 4))//아래
		{
			arr[a + 1][b] = day + 1;//방문
			q.push(a + 1);
			q.push(b);
		}
		if (arr[a - 1][b] == 0 && (a - 1 != -1))//위
		{
			arr[a - 1][b] = day + 1;//방문
			q.push(a - 1);
			q.push(b);
		}
		day++;
	}
}
int main()
{
	
	int arr[4][6];
	int m, n;
	scanf("%d", &m);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);
	}
	for (int i = 0; i < n; i++);
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == day)
			{
				q.push(i);
				q.push(j);
			}
		}
	}
	bfs(arr);
	printf("%d", day);
}