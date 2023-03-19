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

/* 11055�� ���� ū �����ϴ� �κ� ����
// �ؼ� : ������ġ���� ������ġ���� ���� ����� ��� ������
// url : https://www.acmicpc.net/problem/11055

int N, answer;
vector<int> v, dp;

void input()
{
    cin >> N;

    v.assign(N, 0);
    dp.assign(N, 0);

    for(int i = 0 ; i < N ; i++)
    {
        cin >> v[i];
        dp[i] = v[i];
    }
}

void solution()
{
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            if(v[j] < v[i])
            {
                dp[i] = max(dp[i], dp[j] + v[i]);
            }
        }

        answer = max(answer, dp[i]);
    }

    cout << answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solution();
}
*/