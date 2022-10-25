#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <cstring>
#include <functional>
#define endl "\n"

using namespace std;

/* 3665�� ���� ����
// �ؼ� : ���� ����, ���� ���� + ��� ��ȣ �Ѵ� ����
// ���� : https://4legs-study.tistory.com/100

int N, M;

vector<int> team;
vector<int> order;
vector<int> inDegree;
bool adj[501][501];

void solution()
{
    vector<int> ans;
    queue<int> q;

    for(int i = 1 ; i <= N ; i++)
    {
        if(inDegree[i] == 0)
            q.emplace(i);
    }

    while(!q.empty())
    {
        if(q.size() > 1)
        {
            cout << "?" << endl;
            return;
        }

        int cur = q.front();
        q.pop();

        ans.emplace_back(team[cur]);
        
        if(ans.size() == N)
        {
            for(int i = 0 ; i < ans.size() ; i++)
            {
                cout << ans[i] << " ";
            }

            cout << endl;
            return;
        }

        for(int i = 1 ; i <= N; i++)
        {
            if(!adj[cur][i])
                continue;
            
            adj[cur][i] = false;
            
            if(--inDegree[i] == 0)
                q.emplace(i);
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;

    cin >> T;

    while(T--)
    {   
        team.clear();
        order.clear();
        inDegree.clear();
        memset(adj, false, sizeof(adj));

        cin >> N;
        
        team.assign(N + 1, 0);
        order.assign(N + 1, 0);
        inDegree.assign(N + 1, 0);
        
        for(int i = 1 ; i <= N ; i++)
        {
            cin >> team[i];
            order[team[i]] = i;
        }

        for(int i = 1 ; i < N ; i++)
        {
            for(int j = i + 1 ; j <= N ; j++)
            {
                adj[i][j] = true;
                inDegree[j]++;
            }
        }

        cin >> M;

        for(int i = 0 ; i < M ; i++)
        {
            int a, b;

            cin >> a >> b;

            if(order[a] > order[b]) // ��� ���� ã��.
                 swap(a, b);
            
            int order_f = order[a], order_s = order[b]; // �� a, b�� ���(���) ã��. 

            adj[order_f][order_s] = false; // first -> second ����
            inDegree[order_s]--;

            adj[order_s][order_f] = true; // second -> first ����
            inDegree[order_f]++;
        }

        solution();
    }
}
*/

/* 2637�� �峭�� ����
// �ؼ� : vector<pair<int, int>> �� 2���� �迭�� ���� pair�̴�. , ���� ���ķ� Ǯ �� �ִ� �� �ű���.
// ���� : https://leesh111112.tistory.com/162

int N, M;

vector<bool> ans;
vector<int> inDegree;
vector<int> cost;
vector<pair<int, int>> graph[101];

void solution()
{
    queue<int> q;

    q.emplace(N);
    cost[N] = 1;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int i = 0 ; i < graph[cur].size() ; i++)
        {
            int next = graph[cur][i].first;
            int cnt = graph[cur][i].second;

            cost[next] += cost[cur]*cnt;
            if(--inDegree[next] == 0)
                q.emplace(next);
        }
    }

    for(int i = 1 ; i <= N ; i++)
    {
        if(ans[i])
            cout << i << " " << cost[i] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    ans.assign(N + 1, true);
    inDegree.assign(N + 1, 0);
    cost.assign(N + 1, 0);

    for(int i = 0 ; i < M ; i++)
    {
        int x, y, k;

        cin >> x >> y >> k;

        inDegree[y]++;
        graph[x].push_back({y, k});
        ans[x] = false;
    }

    solution();
}
*/