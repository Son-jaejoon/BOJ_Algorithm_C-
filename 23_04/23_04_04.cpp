#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <functional>
#include <climits>
#include <stack>
#include <numeric>
#include <deque>
#define endl "\n"

using namespace std;

/* 15990�� 1, 2, 3 ���ϱ� 5
// �ؼ� : DP, 3���� ���� int�� ������ ���� �� �ִ� �� ���ǿ��
// url : https://www.acmicpc.net/problem/15990

#define MOD 1000000009

int dp[100001][4];

void solution()
{
    dp[1][1] = dp[2][2] = 1;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;

    for(int i = 4 ; i <= 100000 ; i++)
    {
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
    }
}

void input()
{
    int T;

    cin >> T;

    while(T--)
    {
        int N;
        cin >> N;

        cout << ((long long)dp[N][1] + dp[N][2] + dp[N][3]) % MOD << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();
    input();
}
*/