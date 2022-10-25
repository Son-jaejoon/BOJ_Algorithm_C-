#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

/* 9663�� N-Queen
//�ؼ� : ���� ��ġ�� ���� for���� ���� �ٽ� ������ ���� �ϳ��� üũ�ϸ鼭 + ���ִ� ���� ����
//�ش� ����� 2���� �迭�� ���� �ʰ� 1���� �迭���� ���� ���� ��� ���� ������ ���� �ٽ�
// ��Ʈ��ŷ�� ���ؼ� : https://chanhuiseok.github.io/posts/algo-23/

int board[15];
int n;
int count = 0;

int promising(int cdx) {

	// ���� ���̸� �ȵǰ�, �밢���� �־�� �� �ȴ�.
	for (int i = 0; i < cdx; i++) {
		if (board[cdx] == board[i] || cdx - i == abs(board[cdx] - board[i])) {
			return 0;
		}
	}
	return 1;
}

void dfs(int cdx)
{
    if(cdx == n)
    {
        count++;
        return;
    }

    for(int i = 0 ; i < n ; i++)
    {
        board[cdx] = i ;
        if(promising(cdx))
        {
            dfs(cdx + 1);
        }
    }
}

int main()
{
    scanf("%d", &n);

    dfs(0);
    printf("%d\n", count);
}
*/

/* 16197�� �� ����
//�ؼ�: bfs�� �̿��� ������ �����̴� ���� 2����� �����ϰ� x,y��ǥ�� 2�辿 ���´� �����ϸ� �ȴ�.
//bfs ���빮���� Ȯ���� �� �ٽ��ѹ� ���� ���� �߿�.

char board[22][22];
int n, m, coin1_x, coin1_y, coin2_x, coin2_y;
std::string s;
int visited[22][22][22][22] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool check = false;

struct Coins
{
    int x1, y1, x2, y2, cnt;
};

bool isOut(int x, int y)
{
    if ((0 <= x && x < n) && (0 <= y && y < m))
        return true;

    return false;
}

int bfs()
{
    std::queue<Coins> q;
    q.push({coin1_x, coin1_y, coin2_x, coin2_y, 0});

    while (!q.empty())
    {
        Coins cur = q.front();
        visited[cur.x1][cur.y1][cur.x2][cur.y2] = 1;
        q.pop();

        if (cur.cnt > 10)
            break;

        for (int i = 0; i < 4; i++)
        {
            int nx1 = cur.x1 + dx[i];
            int ny1 = cur.y1 + dy[i];
            int nx2 = cur.x2 + dx[i];
            int ny2 = cur.y2 + dy[i];

            if ((isOut(nx1, ny1) && !isOut(nx2, ny2)) || (!isOut(nx1, ny1) && isOut(nx2, ny2)))
            {
                if (cur.cnt + 1 > 10)
                    return -1;

                return cur.cnt + 1;
            }

            if (!isOut(nx1, ny1) && !isOut(nx2, ny2))
                continue;

            if (board[nx1][ny1] == '#' && board[nx2][ny2] == '#')
                continue;

            if (board[nx1][ny1] == '#')
            {
                nx1 = cur.x1;
                ny1 = cur.y1;
            }
            else if (board[nx2][ny2] == '#')
            {
                nx2 = cur.x2;
                ny2 = cur.y2;
            }

            if (!visited[nx1][ny1][nx2][ny2])
            {
                q.push({nx1, ny1, nx2, ny2, cur.cnt + 1});
                visited[nx1][ny1][nx2][ny2] = 1;
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d", &n, &m);
    int num = 0;

    for (int i = 0; i < n; i++)
    {
        std::cin >> s;

        for (int j = 0; j < s.size(); j++)
        {
            board[i][j] = s[j];

            if (board[i][j] == 'o')
            {
                board[i][j] = '.';

                if (num == 0)
                {
                    coin1_x = i;
                    coin1_y = j;
                    num++;
                }

                if (num == 1)
                {
                    coin2_x = i;
                    coin2_y = j;
                }
            }
        }
    }

    std::cout << bfs() << std::endl;
}
*/

/* 16927�� �迭 ������ 2
//�ؼ� : �� �������� (���� ���� - 1)*2 + (���� ���� - 1)*2�� �ϸ� 1����
//���� ��α� : https://conkjh032.tistory.com/278

int N, M, R;
int arr[301][301];

void rotate()
{
    int y1 = 0;
    int x1 = 0;

    int y2 = N-1;
    int x2 = 0;

    int y3 = N-1;
    int x3 = M-1;

    int y4 = 0;
    int x4 = M-1;

    while((y1 < y2) && (x1 < x4))
    {
        int move = R % ((y2-y1)*2 + (x4-x1)*2);

        while(move--){

            int tmp = arr[y1][x1];

            for(int j=x1; j<x4; j++)
            {
                arr[y1][j] = arr[y1][j+1];
            }

            for(int i=y4; i<y3; i++)
            {
                arr[i][x4] = arr[i+1][x4];
            }

            for(int j=x3; j>x2; j--)
            {
                arr[y3][j] = arr[y3][j-1];
            }

            for(int i=y2; i>y1; i--)
            {
                arr[i][x2] = arr[i-1][x2];
            }

            arr[y1+1][x1] = tmp;
        }

        y1 += 1;
        x1 += 1;

        y2 -= 1;
        x2 += 1;

        y3 -= 1;
        x3 -= 1;

        y4 += 1;
        x4 -= 1;
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &R);

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < M ; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    rotate();

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < M ; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
*/