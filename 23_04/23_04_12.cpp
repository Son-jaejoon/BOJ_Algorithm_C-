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

/* 24444번 알고리즘 수업 - 너비 우선 탐색 1
// 해설 : BFS, 정렬
// url : https://www.acmicpc.net/problem/24444

int N, M, R;
vector<int> adj[100001], answer;
vector<bool> visited;

void input()
{
    cin >> N >> M >> R;

    for(int i = 0 ; i < M ; i++)
    {
        int u, v;

        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
}

void bfs()
{
    int dist = 1;
    queue<int> q;
    q.emplace(R);
    visited[R] = true;

    while(!q.empty())
    {
        int curr_node = q.front();
        answer[curr_node] = dist;
        dist++;
        q.pop();

        for(int i = 0 ; i < adj[curr_node].size() ; i++)
        {
            int next_node = adj[curr_node][i];

            if(visited[next_node])
                continue;
            
            visited[next_node] = true;
            q.emplace(next_node);
        }
    }
}

void solution()
{
    for(int i = 1 ; i <= N ; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
    
    answer.assign(N + 1, 0);
    visited.assign(N + 1, false);
    bfs();

    for(int i = 1 ; i <= N ; i++)
    {
        cout << answer[i] << endl;
    }
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