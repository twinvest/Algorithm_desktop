#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];
int ans;
int length;
//dp[i] = i번째 원소를 마지막으로 하는 LIS의 길이

int main() 
{
	ios_base::sync_with_stdio(false);    //이걸 써야 scanf, printf와 속도 비슷해진다.
	cin >> length;
	
	for (int i = 1; i <= length; ++i) 
	{
		cin >> arr[i];                   //원본 수열
		
		int here = 0;                    //계속 0으로 초기화.
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
