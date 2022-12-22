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

/* 17349�� 1����� ������
// �ؼ� : ����

vector<pair<int, int>> v;

void input()
{
    int num, idx;

    for(int i = 0 ; i < 9 ; i++)
    {
        cin >> num >> idx;
        v.emplace_back(make_pair(num, idx));
    }
}

void solution()
{
    int cnt = 0;
    set<int> answer;

    while(cnt <= 8)
    {
        bool fail = false;
        int baseman = 0;
        vector<bool> player(10, false);
        vector<bool> visited(10, false);
        visited[0] = true;

        player[v[cnt].second] = !v[cnt].first;
        visited[v[cnt].second] = true;

        for(int i = 0 ; i < 9 ; i++)
        {
            if(i == cnt)
                continue;
            
            int value = v[i].first;
            int player_idx = v[i].second;

            if(visited[player_idx])
            {
                if(player[player_idx] != value)
                {
                    fail = true;
                    break;
                }
            }
            else
            {
                visited[player_idx] = true;
                player[player_idx] = value;
            }
        }

        if(fail)
        {
            cnt++;
            continue;
        }

        if(count(player.begin(), player.end(), true) == 0) //������ 1������� �𸦶�
        {
            if(count(visited.begin(), visited.end(), true) == 9) // ��޵��� ���� ����� 1���� ��, �׻���� 1���
            {
                baseman = find(visited.begin(), visited.end(), false) - visited.begin();
            }
            else
            {
                // �� ���� ��� ��޵��� ���� ��� ����� 1���
                for(int i = 0 ; i < 10 ; i++)
                {
                    if(!visited[i])
                        answer.insert(i);
                }
                cnt++;
                continue;
            }
        }
        else if(count(player.begin(), player.end(), true) == 1) // 1����� ȥ���� ��
        {
            
            baseman = find(player.begin(), player.end(), true) - player.begin();
        }
        else // �� ���� ���
        {
            cnt++;
            continue;
        }

        answer.insert(baseman);
        cnt++;
    }

    if(answer.size() == 1)
    {
        cout << *answer.begin();
        return;
    }

    cout << -1;
    return;
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