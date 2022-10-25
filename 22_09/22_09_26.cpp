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

/* 1922�� ��Ʈ��ũ ����
// �ؼ� : MST(�ּ� ���д� Ʈ��, Minimum spanning tree) ���� ����. ���Ͽ� ���ε� - merge bool�� true,false
// ���� : https://blog.naver.com/kks227/220799105543

struct info
{
    int x, y, c;
};

info create(int x, int y, int c)
{
    info n_info;

    n_info.x = x;
    n_info.y = y;
    n_info.c = c;

    return n_info;
}

bool cmp(info &a, info &b)
{
    return a.c < b.c;
}

int N, M, ans;
vector<int> computer;
vector<info> connect;

int find_loot(int n)
{
    if (computer[n] < 0)
        return n;

    return computer[n] = find_loot(computer[n]);
}

bool merge(int a, int b)
{
    a = find_loot(a);
    b = find_loot(b);

    if (a == b)
        return false;

    computer[b] = a;

    return true;
}

void solution()
{
    int chk = 0;

    for (int i = 0; i < connect.size(); i++)
    {
        int x = connect[i].x;
        int y = connect[i].y;
        int c = connect[i].c;

        if (merge(x, y))
        {
            ans += c;

            if (++chk == N - 1)
            {
                cout << ans;
                return;
            }
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    computer.assign(N + 1, -1);

    for (int i = 0; i < M; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        if (a == b)
            continue;
        connect.emplace_back(create(a, b, c));
    }

    sort(connect.begin(), connect.end(), cmp);

    solution();
}
*/

/* 17398�� ��Ÿ� ����
// �ؼ� : �������� ����, ������ ������ �ʱ⿡ -1�� ������ ���� ���� �Ѹ� ���� �� �ָ� �����ؼ� �����Ű�� ��.
// ex) arr[a] <= arr[b] -> arr[a] += arr[b], arr[b] = a / b�� a�� ����Ű�� �ǰ� ���������� a�� ���� ����� ������ �����.

int N, M, Q;
long long ans;

vector<bool> chk;
vector<int> network;
vector<pair<int, int>> connect;
vector<pair<int, int>> save;

int find_loot(int n)
{
    if(network[n] < 0)
        return n;

    return network[n] = find_loot(network[n]);
}

void merge(int a, int b)
{
    a = find_loot(a);
    b = find_loot(b);

    if(a == b)
        return;

    if(network[a] <= network[b])
    {
        network[a] += network[b];
        network[b] = a;
    }
    else
    {
        network[b] += network[a];
        network[a] = b;
    }
}

void solution()
{
    for(int i = 1 ; i < connect.size() ; i++)
    {
        if(chk[i])
            continue;

        merge(connect[i].first, connect[i].second);
    }

    for(int i = save.size() - 1 ; i >= 0 ; i--)
    {
        int x = save[i].first;
        int y = save[i].second;

        if(find_loot(x) != find_loot(y))
        {
            ans += network[find_loot(x)] * network[find_loot(y)];
        }

        merge(x, y);
    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> Q;
    connect.emplace_back(make_pair(0, 0));
    network.assign(N + 1, -1);
    chk.assign(M + 1, false);

    for(int i = 1 ; i <= M ; i++)
    {
        int x, y;

        cin >> x >> y;

        connect.emplace_back(make_pair(x, y));
    }

    for(int i = 0 ; i < Q ; i++)
    {
        int a;

        cin >> a;
        chk[a] = true;
        save.emplace_back(make_pair(connect[a].first, connect[a].second));
    }

    solution();
}
*/