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

/* 17615�� �� ������
// �ؼ� : �׸���, ���� �ѹ� �Ű�ٸ� �� �ڷ� �߰ߵǴ� ���� ���� ������ �ű� �� �ۿ� ����.
// url : https://www.acmicpc.net/problem/17615

int N;
int answer = 987654321;
string balls;

void input()
{
    cin >> N >> balls;
}

void move_ball(const char &select_color)
{
    int cnt = 0;
    bool chk = false;

    for(int i = 0 ; i < N ; i++)
    {
        if(balls[i] != select_color)
            chk = true;
        else if(chk && balls[i] == select_color)
            cnt++;
    }

    answer = min(answer, cnt);
    cnt = 0;
    chk = false;

    for(int i = N - 1 ; i >= 0 ; i--)
    {
        if(balls[i] != select_color)
            chk = true;
        else if(chk && balls[i] == select_color)
            cnt++;
    }

    answer = min(answer, cnt);
}

void solution()
{
    move_ball('R');
    move_ball('B');

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