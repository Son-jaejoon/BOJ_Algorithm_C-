#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <functional>
#define endl "\n"

using namespace std;

/* 16973�� ���簢�� Ż��
// �ؼ� : �⺻ �ִܰŸ� + ���簢���� �������� �����ϸ� ���� Ǯ �� �ִ� ����.

int N, M, H, W, Sr, Sc, Fr, Fc;

vector<vector<int>> arr;
vector<vector<bool>> visited;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

struct xyc
{
    int y;
    int x;
    int cnt;
};

xyc create(int y, int x, int cnt)
{
    xyc n_xyc;
    n_xyc.y = y;
    n_xyc.x = x;
    n_xyc.cnt = cnt;

    return n_xyc;
}

bool chk(int y, int x, int dir)
{
    if (dir == 0) // ��
    {
        for (int i = x; i <= x + W - 1; i++)
        {
            if (arr[y][i] == 1)
                return false;
        }

        return true;
    }
    else if (dir == 1) // �Ʒ�
    {
        y = y + H - 1;

        for (int i = x; i <= x + W - 1; i++)
        {
            if (arr[y][i] == 1)
                return false;
        }

        return true;
    }
    else if (dir == 2) // ����
    {
        for (int i = y; i <= y + H - 1; i++)
        {
            if (arr[i][x] == 1)
                return false;
        }

        return true;
    }
    else if (dir == 3) // ������
    {
        x = x + W - 1;

        for (int i = y; i <= y + H - 1; i++)
        {
            if (arr[i][x] == 1)
                return false;
        }

        return true;
    }

    return true;
}

void solution()
{
    queue<xyc> q;
    q.emplace(create(Sr, Sc, 0));
    visited[Sr][Sc] = true;

    while (!q.empty())
    {
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;
        q.pop();

        if (y == Fr && x == Fc)
        {
            cout << cnt;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int n_cnt = cnt + 1;

            if (ny < 1 || nx < 1 || ny > N || nx > M) // ���簢�� �� ���� ��ĭ�� �����
                continue;

            if (ny + H - 1 > N || nx + W - 1 > M) // ���簢���� �����
                continue;

            if (visited[ny][nx]) // �̹� �ѹ� �ͺ�����
                continue;

            if (!chk(ny, nx, i))
                continue;

            visited[ny][nx] = true;
            q.emplace(create(ny, nx, n_cnt));
        }
    }

    cout << -1;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    arr.assign(N + 1, vector<int>(M + 1, 0));
    visited.assign(N + 1, vector<bool>(M + 1, false));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
        }
    }

    cin >> H >> W >> Sr >> Sc >> Fr >> Fc;

    solution();
}
*/