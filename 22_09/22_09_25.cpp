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

/* 10775�� ����
// �ؼ� : �ϴ� ���� ���ذ� �������(G, P, 1�� ���� Gi����Ʈ���� ������� ��ŷ), ���� ū ������ ��ŷ
// �׷��� �Ǹ� �ϳ��� -1�ϴٺ��� 0�̵�. �׷��ٸ� ��ŷ�� �ڸ��� ���°Ŵ� �״������� break
// ���� : https://blog.naver.com/kks227/220791837179

int G, P, ans;
vector<int> available;

int find_loot(int n)
{
    if(available[n] < 0)
        return n;
    
    available[n] = find_loot(available[n]);
    return available[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> G >> P;
    available.assign(G + 1, -1);
    
    bool chk = false;
    for(int i = 1 ; i <= P ; i++)
    {
        int num;
        cin >> num;

        if(find_loot(num) < 1)
        {
            chk = true;
        }
        
        if(!chk)
        {
            available[find_loot(num)] = find_loot(find_loot(num) - 1);
            ans++;
        }
    }

    cout << ans;
}
*/

/* 1976�� ���� ����
// �ؼ� : ���Ͽ� ���ε�, ���� ������ �� ����.

int N, M;

vector<int> city;
vector<int> travel;

int find_loot(int n)
{
    if(city[n] < 0)
        return n;
    
    city[n] = find_loot(city[n]);
    return city[n];
}

void merge(int a, int b)
{
    a = find_loot(a);
    b = find_loot(b);

    if(a == b)
        return;
    
    city[b] = a;
}

void solution()
{
    for(int i = 0 ; i < travel.size() - 1 ; i++)
    {
        int cur = travel[i];
        int next = travel[i + 1];

        if(find_loot(cur) == find_loot(next))
            continue;
        else
        {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    city.assign(N + 1, -1);

    for(int i = 1 ; i <= N ; i++)
    {
        for(int j = 1 ; j <= N ; j++)
        {
            int num;
            cin >> num;

            if(num == 1)
                merge(i, j);
        }
    }
    
    for(int i = 0 ; i < M ; i++)
    {
        int num;
        cin >> num;
        travel.emplace_back(num);
    }

    solution();
}
*/

/* 16562�� ģ����
// �ؼ� : ���Ͽ� ���ε�, find, merge(�� �κп��� ��뿡 ���� �θ� ����)
// 0(�� �ڽ�)�� ��Ʈ�� ģ���� �ٸ��� �ٽ� ��ܾ��� merge

int N, M, K;
vector<int> cost;
vector<int> relation;
vector<int> save;

int find_loot(int n)
{
    if(relation[n] < 0)
        return n;
    
    relation[n] = find_loot(relation[n]);
    return relation[n];
}

void merge(int a, int b)
{
    a = find_loot(a);
    b = find_loot(b);

    if(a == b)
        return; 

    if(cost[a] > cost[b])
        relation[a] = b;
    else
        relation[b] = a;
}

void solution()
{
    int ans = 0;

    for(int i = 1 ; i <= N ; i++)
    {
        int idx = find_loot(i);

        if(idx != find_loot(0))
        {
            ans += cost[idx];
            merge(0, idx);
        }
    }

    if(ans > K)
        cout << "Oh no" << endl;
    else
        cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> M >> K;
    cost.assign(N + 1, 987654321);
    relation.assign(N + 1, -1);

    for(int i = 1 ; i <= N ; i++)
    {
        cin >> cost[i];
    }

    for(int i = 0 ; i < M ; i++)
    {
        int v, w;

        cin >> v >> w;
        
        merge(v, w);
    }

    solution();
}
*/