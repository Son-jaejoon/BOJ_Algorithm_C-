#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

/* 12886�� �� �׷�
// �ؼ� : �հ谡 3���� �������°�
// ����: https://comyoung.tistory.com/245

using namespace std;

int A, B, C, SUM;
bool visit[1501][1501];
 
int main() {
    scanf("%d %d %d", &A, &B, &C);
    SUM = A + B + C;
 
    if (SUM % 3 != 0) {//A,B,C �Ȱ��� �����ϰ� �й� �Ұ��� �ϸ� �ٷ� 0 return
        printf("0\n");
        return 0;
    }
 
    queue<pair<int,int>> qu;
    qu.push({ A,B });
    visit[A][B] = true;
    int a, b;
 
    while (!qu.empty())
    {
        a = qu.front().first;
        b = qu.front().second;
        //3�� ���� ���������ϴ� temp
        int temp[3] = { a, b, SUM - a - b }; // c = sum - a - b
        qu.pop();
        
        for (int i = 0; i < 3; i++) {//3���� ���� ������ ���� 
            for (int j = 0; j < 3; j++) {
                
                if (temp[i] < temp[j]) {
                    int num1 = temp[i] * 2;
                    int num2 = temp[j] - temp[i];
                    if (visit[num1][num2]) continue;
 
                    visit[num1][num2] = true;
                    qu.push({ num1,num2 });
                }
            }
        }
    }
    printf("%d\n", visit[SUM / 3][SUM / 3]);
    return 0;
}
*/

/* 17142�� ������ 3
// �ؼ� : bfs�� Ƚ���� ���ϴ� ��͸� ��ģ ����
// ���ͷ� ��� Ȱ�����̷����� ��ġ�� ������ �� size�� ���� for���� ���� ���ϴ� ������ �Ǿ�����
// �ش� �κ��� true�� �ٲ� bfs�� ���� chk�ϴ� ���� �ٽ�
// ���� : https://codingwell.tistory.com/56

using namespace std;

int n, m, secureCnt = 0, result = 2500;
int lab[50][50] = {0, };
int visited[50][50];
int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
bool virus_visited[10] = {false, };
vector<pair<int, int>> virus;

void bfs(int size)
{
    queue<pair<int, int>> q;
    memset(visited, -1, sizeof(visited));

    for (int i = 0; i < size; i++)
    {
        if (virus_visited[i])
        {
            q.push({virus[i].first, virus[i].second});
            visited[virus[i].first][virus[i].second] = 0;
        }
    }

    int cnt = 0, time = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (lab[nx][ny] != 1 && visited[nx][ny] == -1)
            {
                q.push({nx, ny});
                visited[nx][ny] = visited[x][y] + 1;
                if (lab[nx][ny] == 0)
                {
                    cnt++;
                    time = visited[nx][ny];
                }
            }
        }
    }
    if (cnt == secureCnt)
        result = min(result, time);
}

void selectVirus(int index, int cnt, int size)
{
    if (cnt == m)
    {
        bfs(size);
        return;
    }
    
    for (int i = index; i < size; i++)
    {
        if (!virus_visited[i])
        {
            virus_visited[i] = true;
            selectVirus(i + 1, cnt + 1, size);
            virus_visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> lab[i][j];
            if (lab[i][j] == 2)
                virus.push_back({i, j});
            else if (lab[i][j] == 0)
                secureCnt++;
        }
    }

    selectVirus(0, 0, virus.size());
    if (result != 2500)
        cout << result;
    else
        cout << -1;
}
*/

/* 5014�� ��ŸƮ��ũ
// �ؼ� : �������� BFS����

int F, S, G, U, D;
// �ְ��� : F��
// ������ġ : S��
// ������ : G��

bool visited[1000001];

void bfs(int now, int des, int up, int down)
{
    std::queue<std::pair<std::pair<int, int>, int >> q;
    q.emplace(std::make_pair(std::make_pair(now, des), 0));
    visited[now] = true;

    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if(x == y)
        {
            printf("%d", cnt);
            return;
        }

        if(x - down > 0)
        {
            if(!visited[x-down])
            {
                visited[x-down] = true;
                q.emplace(std::make_pair(std::make_pair(x - down, y), cnt + 1));
            }
        }

        if(x + up <= F)
        {
            if(!visited[x + up])
            {
                visited[x + up] = true;
                q.emplace(std::make_pair(std::make_pair(x + up, y), cnt + 1));
            }
        }
    }

    printf("use the stairs");
    return;
}

int main()
{
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

    bfs(S, G, U, D);
}
*/