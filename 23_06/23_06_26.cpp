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

/* 14225�� �κ� ������ ��
// �ؼ� : ���Ʈ����, TLE�� �ͱ� �ߴµ� �׳� �ܼ��ϰ� false�� ã���� �̴�.
// url : https://www.acmicpc.net/problem/14225

int N;
vector<int> v;
vector<bool> check(2000001);

void input()
{
    cin >> N;
    v.assign(N, 0);

    for(int i = 0 ; i < N ; i++)
    {
        cin >> v[i];
    }
}

void available_num(int idx, int sum)
{
    if(idx >= N)
        return;
    
    check[sum + v[idx]] = true;
    available_num(idx + 1, sum);
    available_num(idx + 1, sum + v[idx]);
}

void solution()
{
    check[0] = true;
    available_num(0, 0);

    int answer = find(check.begin(), check.end(), false) - check.begin();
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