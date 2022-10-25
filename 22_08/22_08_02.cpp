#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>

/* 16946�� �� �μ��� �̵��ϱ� 4
// �ؼ� : 1���� �κ� 0���� ���� -> �ߺ� �κ� �󺧸��ϴ� ��

int N, M;
int arr[1001][1001];
int save_point[1001][1001];
int label[1001][1001];
bool visited[1001][1001];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

std::vector<std::pair<int, int>> one;

void bfs(int a, int b, int labelling)
{
    int count = 0;

    std::queue<std::pair<int, int>> q;
    std::vector<std::pair<int, int>> save;
    q.emplace(std::make_pair(a, b));
    save.emplace_back(std::make_pair(a, b));
    visited[a][b] = true;
    label[a][b] = labelling;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        count++;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && nx >= 0 && ny < N && nx < M)
            {
                if (arr[ny][nx] == 0 && !visited[ny][nx])
                {
                    q.emplace(std::make_pair(ny, nx));
                    save.emplace_back(std::make_pair(ny, nx));
                    visited[ny][nx] = true;
                    label[ny][nx] = labelling;
                }
            }
        }
    }

    for (int i = 0; i < save.size(); i++)
    {
        int y = save[i].first;
        int x = save[i].second;

        save_point[y][x] = count;
    }

    return;
}

int main()
{
    int label_num = 0;

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &arr[i][j]);
            if (arr[i][j] == 1)
                one.emplace_back(std::make_pair(i, j));
        }
    }

    for (int i = 0; i < one.size(); i++)
    {
        std::vector<int> chk;
        int y = one[i].first;
        int x = one[i].second;
        int sum = 0;

        for (int j = 0; j < 4; j++)
        {
            bool overlap = false;
            int ny = y + dy[j];
            int nx = x + dx[j];

            if (ny >= 0 && nx >= 0 && ny < N && nx < M)
            {
                if (arr[ny][nx] != 0)
                {
                    continue;
                }

                if (save_point[ny][nx] == 0)
                {
                    bfs(ny, nx, label_num++);
                    chk.emplace_back(label[ny][nx]);
                    sum = sum + save_point[ny][nx];
                }

                for (int k = 0; k < chk.size(); k++)
                {
                    if (chk[k] == label[ny][nx])
                        overlap = true;
                }

                if (!overlap)
                {
                    chk.emplace_back(label[ny][nx]);
                    sum = sum + save_point[ny][nx];
                }
            }
        }
        sum++;
        arr[y][x] = sum;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d", arr[i][j] % 10);
        }
        printf("\n");
    }
}
*/

/* 14442�� �� �μ��� �̵��ϱ� 2
// �ؼ� : ������ 2������ �� �μ��� Ƚ���� k�� ������ ��Ȳ�� �߰��ϸ� �ȴ�.
// �ش� �κ��� �߰� �� �� ���� ���� ���� ���� �μ��� ������ ��(���� �μ� Ƚ�� - 1)�� �ִ� �� üũ�ؾ���.

using namespace std;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int r,c,k;
int visited[1000][1000][10];

int bfs(int row, int col, vector<string> &graph ) {
    queue<pair<pair<int, int>, int>> q;
    q.push({ {0,0},k });
    visited[0][0][k] = 1;

    while (!q.empty()) {
        int current_r = q.front().first.first;
        int current_c = q.front().first.second;
        int block = q.front().second;
        q.pop();

        if (current_r == r - 1 && current_c == c - 1) { //�������� �����ϸ� return
            return visited[current_r][current_c][block];
        }

        for (int i = 0; i < 4; i++) {
            int next_r = current_r + dir[i][0];
            int next_c = current_c + dir[i][1];
            if (next_r >= 0 && next_r < r&& next_c >= 0 && next_c < c) {
                //���� ĭ�� ���̰� ���� �� ���� ��
                if (graph[next_r][next_c] == '1' && block >= 1 && visited[next_r][next_c][block-1] == 0) {
                    q.push({ {next_r,next_c} , block - 1});
                    visited[next_r][next_c][block-1] = visited[current_r][current_c][block] + 1;
                }
                //���� ĭ�� 0�̰� �湮���� �ʾ��� ��
                else if (graph[next_r][next_c] == '0' && visited[next_r][next_c][block] == 0) {
                    q.push({ {next_r,next_c}, block});
                    visited[next_r][next_c][block] = visited[current_r][current_c][block] + 1;
                }
            }
        }

    }
    return -1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r>>c>>k;
    vector<string> graph(r);

    for (int i = 0; i < r; i++) {
        cin >> graph[i];
    }
    cout <<bfs(0, 0, graph);
    return 0;
}
*/

/* 2206�� �� �μ��� �̵��ϱ�
// �ؼ� : �� Ʋ���� �𸣰��� -> �ѹ� �μ��� �������µ� �� ���� ���������� �̹� �湮�� false�� �س��Ƽ� -1 ���.
// �� �μ��� �̵� or �Ⱥμ��� �̵� // �ν����� ���ܼ� ���

int N, M;

int arr[1001][1001];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int ans = 2000;

bool visited[1002][1002];
int vs[1002][1002][2];

void bfs()
{
    std::queue<std::pair<std::pair<int, int>, int>> q;
    q.emplace(std::make_pair(std::make_pair(1, 1), 0));
    vs[1][1][0] = 1;

    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int block = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (block == 0)
            {
                if (!vs[ny][nx][0] == -1 && arr[ny][nx] == 0)
                {
                    q.emplace(std::make_pair(std::make_pair(ny, nx), 0));
                    vs[ny][nx][0] = vs[ny][nx][0] + 1;
                }
                else if (!vs[ny][nx][1] == -1 && arr[ny][nx] == 1)
                {
                    q.emplace(std::make_pair(std::make_pair(ny, nx), 1));
                    vs[ny][nx][1] = vs[ny][nx][0] + 1;
                }
            }
            else if (block == 1)
            {
                if (!vs[ny][nx][1] == -1 && arr[ny][nx] == 0)
                {
                    q.emplace(std::make_pair(std::make_pair(ny, nx), 1));
                    vs[ny][nx][1] = vs[ny][nx][1] + 1;
                }
            }
        }
    }
    return;
}

int main()
{
    scanf("%d %d", &N, &M);
    std::memset(arr, -1, sizeof(arr));
    std::memset(visited, -1, sizeof(vs));

    for (int i = 1; i <= N; i++)
    {
        std::string s;
        std::cin >> s;

        for (int j = 1; j <= M; j++)
        {
            arr[i][j] = s[j - 1];
        }
    }

    bfs();

    if ((vs[N][M][0] == -1) != (vs[N][M][1] == -1))
        printf("%d", std::max(vs[N][M][0], vs[N][M][1]));
    else
        printf("%d", std::min(vs[N][M][0], vs[N][M][1]));
}
*/