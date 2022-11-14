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

/* 17371�� �̻�
// �ؼ� : �ϳ��� �� ����ؾ������� ��ġ�� ��� �����ұ� ����ϴ�, ���ǽü��� ���� ����� �ǰڱ��� �����ϴ� ���� �ذ��ߴ�.


int N, ans;
vector<pair<int, int>> v;

double distance(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

void solution()
{
    int ans_distance = INT_MAX;

    for(int i = 0 ; i < N ; i++)
    {
        int distance_1 = 0;

        for(int j = 0 ; j < N ; j++)
        {
            if(i == j)
                continue;
            
            int tmp_distance = distance(v[i].first, v[i].second, v[j].first, v[j].second);

            distance_1 = max(distance_1, tmp_distance);
        }

        if(ans_distance > distance_1)
        {
            ans_distance = distance_1;
            ans = i;
        }
    }

    cout << v[ans].first << " " << v[ans].second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0 ; i < N ; i++)
    {
        int x, y;
        cin >> x >> y;

        v.emplace_back(make_pair(x, y));
    }

    solution();
}
*/