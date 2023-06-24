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

/* 2531�� ȸ�� �ʹ�
// �ؼ� : ���Ʈ ����
// url : https://www.acmicpc.net/problem/2531

int N, D, K, C;
vector<int> belt;

void input()
{
    cin >> N >> D >> K >> C;
    belt.assign(N, 0);

    for(int i = 0 ; i < N ; i++)
    {
        cin >> belt[i];
    }
}

void solution()
{
    vector<bool> eat_food;
    int answer = 0, cnt = 0;

    for(int i = 0 ; i < N ; i++)
    {
        int food_num;
        cnt = 1;
        eat_food.assign(D + 1, false);
        eat_food[C] = true;

        for(int j = i ; j < i + K ; j++)
        {
            food_num = belt[j % N];

            if(!eat_food[food_num])    
            {
                eat_food[food_num] = true;
                cnt++;
            }
        }

        answer = max(answer, cnt);
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