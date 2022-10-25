#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <functional>
#define endl "\n"

using namespace std;
/* 2056�� �۾�
// �ؼ� : ���� ����(���� ������ ������������, ������ �����Ƿ�, ���࿡�� ���� ū ���� ���� ���� ��������)
// ���� : https://melonicedlatte.com/algorithm/2018/08/31/012451.html

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<int> spend_time(N + 1);
    vector<int> total_time(N + 1);
    vector<vector<int>> parent(N + 1);

    for(int i = 1 ; i <= N ; i++)
    {
        int first;
        cin >> spend_time[i] >> first;

        for(int j = 0 ; j < first ; j++)
        {
            int number;
            cin >> number;
            parent[i].emplace_back(number);
        }
    }

    for(int i = 1 ; i <= N ; i++)
    {
        int parent_time = 0;

        for(int j = 0 ; j < parent[i].size() ; j++)
        {
            if(parent_time < total_time[parent[i][j]])
                parent_time = total_time[parent[i][j]];
        }

        total_time[i] = parent_time + spend_time[i];
    }

    int ans = 0;

    for(int i = 1 ; i <= N ; i++)
    {
        if(ans < total_time[i])
            ans = total_time[i];
    }

    cout << ans;
}
*/