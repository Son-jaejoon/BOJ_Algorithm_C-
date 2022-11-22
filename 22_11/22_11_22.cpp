#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <functional>
#include <climits>
#define endl "\n"

using namespace std;

/* 11444�� �Ǻ���ġ �� 6
// �ؼ� : ó���� ��ȭ������ �ذ��Ϸ� ������, �Է°��� Ŀ vector �ִ�ũ�⸦ ��� ����� �̿��Ͽ� Ǯ���Ͽ���.
// ���� : https://tinyurl.com/2gr6pctj

#define mod 1000000007

long long n;

typedef vector<vector<long long>> matrix;

matrix operator* (matrix& a, matrix& b)
{
	matrix c(2, vector<long long>(2));

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++){
			for (int k = 0; k < 2; k++)
				c[i][j] += a[i][k] * b[k][j];

			c[i][j] %= mod;
		}
	return c;	
}

int main()
{
	cin >> n;

	matrix ans = {{1,0}, {0,1}};
	matrix a = {{1,1}, {1,0}};

	while (n > 0)
	{
		if (n % 2 == 1)
			ans = ans * a;
		a = a * a;
		n /= 2;
	}
	
	cout << ans[0][1] << '\n';
}
*/