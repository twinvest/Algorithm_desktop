#include<cstdio>
#include<string>
#include<math.h>
#include<vector>
using namespace std;
//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution {
public:
	int solution(vector<int> arr) {
		int flag = 0;
		for (int i = 0; (i < (sizeof(arr) / sizeof(int))) && (1 <= arr[i] && arr[i] <= 100); i++)
		{
			if (arr[i] % 2 == 0)
				flag++;
		}
		return flag;
	}
};
int main()
{
	Solution s;
	vector<int> arr;
	for (int i = 1; i < 5; i++)
	{
		arr.push_back(i);
	}
	
	int a = s.solution(arr);
	printf("%d", a);
}