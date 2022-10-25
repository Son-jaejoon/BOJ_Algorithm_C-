#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

/* 1707�� �̺� �׷���
//�ؼ� : �̺� �׷����� ��ü�� ������ 2���� �׷����� ������ 2���� �׷� ���̿����� ������ �����ϴ� ��츦 ���Ѵ�.
//�ش� �׷����� �Ǻ��ϱ� ���ؼ� DFS�� ���� ���� ������ �ڽ� ������ ������ �ݴ�� ������ �� ��
//��� ��츦 for�� ���� �θ� �ڽ� ���� ������ ���� ������ NO, �ٸ��� YES�� �ȴ�.

#define RED 2
#define BLUE 3

int k; // ���̽� ����
int v; // ���̽� ������ ��
int e; // ���̽� ������ ��

std::vector<int> graph[20001];
int visited[20001];

void dfs(int start)
{
    if(visited[start] == 0)
        visited[start] = RED;

    for(int i = 0 ; i < graph[start].size(); i++)
    {
        int idx = graph[start][i];

        if(visited[idx] == 0)
        {
            if(visited[start] == RED)
                visited[idx] = BLUE;
            else if(visited[start] == BLUE)
                visited[idx] = RED;

            dfs(idx);
        }
    }
}

int check()
{
    for (int i = 1 ; i <= v ; i++)
    {
        for(int j = 0 ; j < graph[i].size() ; j++)
        {
            int idx = graph[i][j];

            if(visited[i] == visited[idx])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    scanf("%d", &k);

    while(k > 0)
    {
        scanf("%d %d", &v, &e);

        for(int i = 0 ; i < e; i++)
        {
            int num1, num2;
            scanf("%d %d", &num1, &num2);
            graph[num1].push_back(num2);
            graph[num2].push_back(num1);
        }
        
        for(int i = 1 ; i <= v; i++)
        {
            if(visited[i] == 0)
                dfs(i);
        }

        if(check() == 0)
            printf("NO\n");
        else
            printf("YES\n");


        std::memset(visited, 0, sizeof(visited));
        std::memset(graph, 0 , sizeof(graph));
        k--;
    }
}
*/

/* 7576�� �丶��
//�ؼ� : �ʺ�켱Ž���� ���� ����. ť�� ���� x,y ��ǥ�� �ް� ��ǥ�� �������� �����¿츦 ���Ѵ�.
//       �����Ѵٸ� if ���� ���� ���� �ذ�.

bool isInside(int ny, int nx, int a, int b)
{
    if(0 <= nx && 0 <= ny && ny < a && nx < b)
    {
        return true;
    }else
        return false;
}

int main()
{
    int ans = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int M;
    int N;

    scanf("%d %d", &M, &N);

    int arr[N][M];
    std::queue<std::pair<int, int>> tomato;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &arr[i][j]);

            if (arr[i][j] == 1)
            {
                tomato.push(std::make_pair(i, j));
            }
        }
    }

    while (!tomato.empty())
    {
        int y = tomato.front().first;
        int x = tomato.front().second;
        tomato.pop();

        for(int i = 0 ; i < 4 ; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(isInside(ny, nx, N, M) && arr[ny][nx] == 0)
            {
                arr[ny][nx] = arr[y][x] + 1;
                tomato.push(std::make_pair(ny, nx));
            }
        }
    }

    for(int i = 0 ; i < N ; i ++)
    {
        for(int j = 0 ; j < M ; j++)
        {
            if(arr[i][j] == 0)
            {
                printf("-1\n");
                return 0;
            }

            if(ans < arr[i][j])
            {
                ans = arr[i][j];
            }
        }
    }

    printf("%d\n", ans - 1);
}
*/