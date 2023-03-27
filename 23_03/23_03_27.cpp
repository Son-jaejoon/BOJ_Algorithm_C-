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

/* 18111�� ����ũ����Ʈ
// �ؼ� : ����, TLE�� �����ϰ� ���Ʈ������ �������� üũ�ϴ� ���� �߿��� �� ����.
// url : https://www.acmicpc.net/problem/18111

int N, M, B;
vector<vector<int>> v;

void input()
{
    cin >> N >> M >> B;

    v.assign(N, vector<int>(M, 0));

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < M ; j++)
        {
            cin >> v[i][j];
        }
    }
}

void solution()
{
    int answer_sec = 987654321;
    int answer_h = 0;

    for(int h = 0 ; h <= 256 ; h++)
    {
        int remove = 0;
        int build = 0;

        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < M ; j++)
            {
                int height = v[i][j] - h;

                if(height >= 0)
                    remove += height;
                else
                    build -= height;
            }
        }

        if(remove + B >= build)
        {
            int time = remove*2 + build;

            if(answer_sec > time)
            {
                answer_sec = time;
                answer_h = h;
            }
            else if(answer_sec == time && answer_h < h)
            {
                answer_h = h;
            }
        }
    }

    cout << answer_sec << " " << answer_h;
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