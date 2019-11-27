#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 100001 * 2;
string tmp, str;
int A[MAXN];
vector<int> space;

void manachers(string S, int N)
{
	int r = 0, p = 0;
	for (int i = 0; i < N; i++)
	{
		if (i <= r)
			A[i] = min(A[2 * p - i], r - i);
		else
			A[i] = 0;

		while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && S[i - A[i] - 1] == S[i + A[i] + 1])

			A[i]++;

		if (r < i + A[i])
		{
			r = i + A[i];
			p = i;
		}
	}
}



int main()
{

	int check = 0;

	string tmp = "������� �������� ��������̴�.";//"������� �������� ��������̴�.";

	for (int i = 0; i < tmp.size(); ++i)

	{

		if (tmp.at(i) == ' ')

		{

			space.push_back(i - check);

			check++;

			tmp.erase(i, 1);

		}

	}



	//¦���� ��츦 ���� #�ٿ��ֱ�

	for (int i = 0; i < tmp.size(); i++)

	{

		str += '#';

		str += tmp[i];

	}

	str += '#';



	//����Ŀ���˰���

	manachers(str, str.size());



	for (int i = 0; i < str.size(); i++)

	{

		int num = A[i];

		if (num > 1)

		{

			while (num > 1)

			{

				--num;

				string print = "";

				print += str.substr(i - num, num + 1);

				print += str.substr(i + 1, num);   //print += str.substr(i, A[i] + 1);



				if (print[0] == '#')

					continue;



				for (int j = 0; j < space.size(); ++j)

				{

					if (i > space.at(j))

					{

						int a = space.at(j) - (i / 2) + A[i];

						//if (i % 2 == 1) a += -1;

						if (a > i - num && a < i + num)

						{

							print.insert(a, " ");

							break;

						}

					}

				}

				printf("%s\n", print);

			}



		}

	}



	/*

	for (int i = 0; i < print.size(); ++i)

	{

	if (print.at(i) == '#')

	{

	print.erase(i, 1);

	}

	}

	*/
	int ans = -1;

	for (int i = 0; i < str.size(); i++)

		ans = max(ans, A[i]);

	printf("%d", ans);

	return 0;

}