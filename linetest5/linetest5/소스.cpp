#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
typedef pair<int, pair<int, int>> P;
using namespace std;
int main(void)
{
	bool arr[200000];
	queue<P> q;
	int brown_position;
	int kony_position;
	int time=1;
	scanf("%d %d", &brown_position, &kony_position);


	while (1)
	{
		kony_position = kony_position + time;
		time++;
		if (kony_position > 200000)
		{
			printf("-1");
			break;
		}
		
		int a = brown_position + 1;
		int b = brown_position - 1;
		int c = brown_position * 2;
		
		q.push({ time, {kony_position, brown_position} });
		
	}
	

	return 0;
}