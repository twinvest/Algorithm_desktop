#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];
int ans;
int length;
//dp[i] = i��° ���Ҹ� ���������� �ϴ� LIS�� ����

int main() 
{
	ios_base::sync_with_stdio(false);    //�̰� ��� scanf, printf�� �ӵ� ���������.
	cin >> length;
	
	for (int i = 1; i <= length; ++i) 
	{
		cin >> arr[i];                   //���� ����
		
		int here = 0;                    //��� 0���� �ʱ�ȭ.
		for (int j = 1; j < i; ++j) 
		{
			if (arr[i] > arr[j])
				here = max(here, dp[j]);
		}
		
		dp[i] = here + 1;
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
