#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <functional>
#define endl "\n"

using namespace std;

/* 16565�� N��Ŀ
// �ؼ� : ó���� 13���� �� 1�� * ������ ���� �̶�� �����ؼ� WA�� �ް�,
// 13 �� N���� * �������� �ϸ鼭 �ߺ��� ��������� �˾���..

int N;
int MOD = 10007;

int nCk[53][53];

void solution()
{
    for(int i = 0 ; i <= 52 ; i++)
    {
        nCk[i][0] = nCk[i][i] = 1;

        for(int j = 1 ; j < i ; j++)
        {
            nCk[i][j] = nCk[i - 1][j - 1] + nCk[i - 1][j];
            nCk[i][j] %= MOD;
            nCk[i][i - j] = nCk[i][j];
        }
    }

    int ans = 0;

    for(int i = 4 ; i <= N ; i += 4)
    {
        if((i / 4) % 2 == 1)
            ans = (ans + nCk[13][i/4]*nCk[52 - i][N - i]) % MOD;
        else
            ans = (ans - nCk[13][i/4]*nCk[52 - i][N - i]) % MOD;       
    }

    if(ans < 0)
        ans += MOD;
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    solution();
}
*/