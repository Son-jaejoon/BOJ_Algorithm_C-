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

/* 11726번 2xn 타일링
// 해설 : DP, dp해결 할때 그려서 푸는법 https://jaemin8852.tistory.com/158 
// url : https://www.acmicpc.net/problem/11726

int N;
vector<int> dp;

void input()
{
    cin >> N;
}

int find_answer(int num)
{
    if(dp[num] != 0)
        return dp[num];
    else
        return dp[num] = (find_answer(num - 1) + find_answer(num - 2)) % 10007;   
}

void solution()
{
    dp.assign(N + 1, 0);
    dp[1] = 1;
    dp[2] = 2;

    find_answer(N);

    cout << dp[N];
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