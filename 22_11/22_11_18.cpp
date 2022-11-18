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

/* 1967�� Ʈ���� ����
// �ؼ� : Ʈ��
// ó���� ���� �� ��带 ���� �� �� ������ ����ġ�� ���� ���ϴ� ������ �����ߴ�.
// ������ ���� ����ġ = �Ÿ��� �˰��� ���� �ذ��� �� �־���.


int N;
vector<pair<int, int>> graph[10001];

int max_cost = 0;
int ans_node = -1;

void dfs(int curr, int w, vector<bool> visited)
{
    if(visited[curr])
        return;
    
    if(max_cost < w)
    {
        max_cost = w;
        ans_node = curr;
    }

    visited[curr] = true;

    for(int i = 0 ; i < graph[curr].size() ; i++)
    {
        int next = graph[curr][i].first;
        int weight = graph[curr][i].second + w;

        dfs(next, weight, visited);
    }
}

void solution()
{
    vector<bool> visited;
    visited.assign(N + 1, false);

    dfs(1, 0, visited);

    max_cost = 0;
    dfs(ans_node, 0, visited);

    cout << max_cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1 ; i < N ; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;
        graph[a].emplace_back(make_pair(b, c));
        graph[b].emplace_back(make_pair(a, c));
    }

    solution();
}
*/