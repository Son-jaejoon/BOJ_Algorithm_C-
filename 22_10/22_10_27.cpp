#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <functional>
#define endl "\n"

using namespace std;

/* 1007�� ���� ��Ī
// �ؼ� : ���Ϳ� ���� ���ؿ� �ð����⵵�� ���̴� ��(���� N�� �� �ݸ� �����ϸ� �ȴ�)�� �˾ƾ� Ǯ �� �ִ�.

vector<pair<int, int>> v;
double ans;
vector<bool> visited;

double sum()
{
    pair<int, int> vec = {0, 0};

    for(int i = 0 ; i < v.size() ; i++)
    {
        if(visited[i])
        {
            vec.first -= v[i].first;
            vec.second -= v[i].second;
        }
        else
        {
            vec.first += v[i].first;
            vec.second += v[i].second;
        }
    }

    return sqrt(pow(vec.first, 2) + pow(vec.second, 2));
}

void dfs(int cur, int cnt)
{
    if(cnt == v.size()/2)
    {
        ans = min(ans, sum());
        return;
    }

    for(int i = cur ; i < v.size() ; i++)
    {
        visited[i] = true;
        dfs(i + 1, cnt + 1);
        visited[i] = false;
    }
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
        ans = 1e10;

        int N;
        cin >> N;

        v.clear();
        visited.clear();
        visited.assign(N + 1, 0);

        for(int i = 0 ; i < N ; i++)
        {
            int y, x;
            cin >> y >> x;

            v.emplace_back(make_pair(y, x));
        }

        dfs(0, 0);
        printf("%.7lf\n", ans);
    }
}
*/