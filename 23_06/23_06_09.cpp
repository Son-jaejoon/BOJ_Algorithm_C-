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

/* 17610�� ��������
// �ؼ� : BFS, ������ �������� ���ߴ�.(�׳� ���￡ �߸� �÷��� 1 ~ total(�ߵ��� ��) �� ���� �� �ִ� ������.)
// url : https://www.acmicpc.net/problem/17610

int N, total;
vector<int> weights;

void input()
{
    cin >> N;
    weights.assign(N, 0);

    for(int i = 0 ; i < N ; i++)
    {
        cin >> weights[i];
        total += weights[i];
    }
}

void solution()
{
    int answer = 0;
    vector<vector<bool>> visited(N + 1, vector<bool>(total + 1, false));

    queue<pair<int, int>> q;
    q.emplace(make_pair(0, 0));

    while(!q.empty())
    {
        int curr_idx = q.front().first;
        int sum = q.front().second;
        q.pop();

        if(curr_idx >= N)
            continue;
        
        if(!visited[curr_idx + 1][sum]) // ���� �� ��ŵ
        {
            visited[curr_idx + 1][sum] = true;
            q.emplace(make_pair(curr_idx + 1, sum));
        }

        if(!visited[curr_idx + 1][sum + weights[curr_idx]]) // ���� �߸� ���ʿ� �ֱ�
        {
            visited[curr_idx + 1][sum + weights[curr_idx]] = true;
            q.emplace(make_pair(curr_idx + 1, sum + weights[curr_idx]));
        }

        if(!visited[curr_idx + 1][abs(sum - weights[curr_idx])]) // ���� �߸� �����ʿ� �ֱ�
        {
            visited[curr_idx + 1][abs(sum - weights[curr_idx])] = true;
            q.emplace(make_pair(curr_idx + 1, abs(sum - weights[curr_idx])));
        }
    }

    for(int i = 1 ; i <= total ; i++)
    {
        if(!visited[N][i])
            answer++;
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