#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

/* 2290�� LCD Test
//�ؼ�: �׳� ������ ������

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int s;
	string n;
	cin >> s >> n;

	for (int h = 0; h < 2 * s + 3; h++)
	{
		for (int i = 0; i < n.length(); i++)
		{
			//���� �� ��
			if (h == 0)
			{
				if (n[i] == '0' || n[i] == '2' || n[i] == '3' || n[i] == '5' || n[i] == '6' || n[i] == '7' || n[i] == '8' || n[i] == '9')
				{
					cout << " ";
					for (int j = 0; j < s; j++)
						cout << "-";
					cout << " ";
				}
				else
				{
					for (int j = 0; j < s + 2; j++)
						cout << " ";
				}
			}
			//���� ����
			else if (1 <= h && h <= s)
			{
				if (n[i] == '0' || n[i] == '4' || n[i] == '8' || n[i] == '9')
				{
					cout << "|";
					for (int j = 0; j < s; j++)
						cout << " ";
					cout << "|";
				}
				else if (n[i] == '1' || n[i] == '2' || n[i] == '3' || n[i] == '7')
				{
					for (int j = 0; j < s + 1; j++)
						cout << " ";
					cout << "|";
				}
				else
				{
					cout << "|";
					for (int j = 0; j < s + 1; j++)
						cout << " ";
				}
			}
			//���
			else if (h == s + 1)
			{
				if (n[i] == '0' || n[i] == '1' || n[i] == '7')
				{
					for (int j = 0; j < s + 2; j++)
						cout << " ";
				}
				else
				{
					cout << " ";
					for (int j = 0; j < s; j++)
						cout << "-";
					cout << " ";
				}
			}
			//���� �Ʒ���
			else if (s + 2 <= h && h <= 2 * s + 1)
			{
				if (n[i] == '0' || n[i] == '6' || n[i] == '8')
				{
					cout << "|";
					for (int j = 0; j < s; j++)
						cout << " ";
					cout << "|";
				}
				else if (n[i] == '1' || n[i] == '3' || n[i] == '4' || n[i] == '5' || n[i] == '7' || n[i] == '9')
				{
					for (int j = 0; j < s + 1; j++)
						cout << " ";
					cout << "|";
				}
				else
				{
					cout << "|";
					for (int j = 0; j < s + 1; j++)
						cout << " ";
				}
			}
			//�� �Ʒ���
			else
			{
				if (n[i] == '1' || n[i] == '4' || n[i] == '7')
				{
					for (int j = 0; j < s + 2; j++)
						cout << " ";
				}
				else
				{
					cout << " ";
					for (int j = 0; j < s; j++)
						cout << "-";
					cout << " ";
				}
			}
			cout << " ";
		}
		cout << "\n";
	}
	return 0;
}
*/

/*16935�� �迭 ������ 3
//�ؼ� : �׳� ������ ��

int N, M, R;
std::queue<int> q;
int arr[101][101];
int temp[101][101];

void arr_change(int num)
{
    if (num == 1)
    {
        for (int i = 0; i < N / 2; i++)
        {
            for (int j = 0; j < M; j++)
            {
                std::swap(arr[i][j], arr[N - i - 1][j]);
            }
        }
        return;
    }

    if (num == 2)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M / 2; j++)
            {
                std::swap(arr[i][j], arr[i][M - j - 1]);
            }
        }
        return;
    }

    if (num == 3)
    {
        std::memset(temp, 0, sizeof(temp));

        int h = N;

        std::swap(N, M);

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                temp[i][j] = arr[h - 1 - j][i];

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                arr[i][j] = temp[i][j];
        return;
    }

    if (num == 4)
    {
        std::memset(temp, 0, sizeof(temp));

        int w = M;

        std::swap(N, M);

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                temp[i][j] = arr[j][w-1-i];

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                arr[i][j] = temp[i][j];
        return;
    }

    if (num == 5)
    {

        for (int i = 0; i < N / 2; i++)
        {
            for (int j = 0; j < M / 2; j++)
            {
                std::swap(arr[i][j], arr[i][M / 2 + M % 2 + j]);
            }
        }

        for (int i = 0; i < N / 2; i++)
        {
            for (int j = 0; j < M / 2; j++)
            {
                std::swap(arr[i][j], arr[N / 2 + N % 2 + i][M / 2 + M % 2 + j]);
            }
        }

        for (int i = 0; i < N / 2; i++)
        {
            for (int j = 0; j < M / 2; j++)
            {
                std::swap(arr[i][j], arr[N / 2 + N % 2 + i][j]);
            }
        }

        return;
    }

    if (num == 6)
    {
        for (int i = 0; i < N / 2; i++)
        {
            for (int j = 0; j < M / 2; j++)
            {
                std::swap(arr[i][j], arr[N / 2 + N % 2 + i][j]);
            }
        }

        for (int i = 0; i < N / 2; i++)
        {
            for (int j = 0; j < M / 2; j++)
            {
                std::swap(arr[i][j], arr[N / 2 + N % 2 + i][M / 2 + M % 2 + j]);
            }
        }

        for (int i = 0; i < N / 2; i++)
        {
            for (int j = 0; j < M / 2; j++)
            {
                std::swap(arr[i][j], arr[i][M / 2 + M % 2 + j]);
            }
        }

        return;
    }
}

void arr_print(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &R);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < R; i++)
    {
        int num;
        scanf("%d", &num);
        q.emplace(num);
    }

    while (!q.empty())
    {
        arr_change(q.front());
        q.pop();
    }

    arr_print(N, M);
}
*/

/* 14226�� �̸�Ƽ��
//�ؼ� : ���ڲ����� ����� ������ make pair �� 2���� �� 3���� ���ڸ� ���� ���� ��ȯ�޴� ������� �ذ���.
int S;
std::queue<std::pair<std::pair<int, int>, int>> q;
bool visit[2010][2010];

int dfs()
{
    int cnt, clip, ans;
    while (!q.empty())
    {
        cnt = q.front().first.first;
        clip = q.front().first.second;
        ans = q.front().second;
        q.pop();

        if (cnt == S)
        {
            return ans;
        }

        int x_1 = cnt;
        int x_2 = cnt + clip;
        int x_3 = cnt - 1;

        if(!visit[x_1][cnt])
        {
            q.emplace(std::make_pair(std::make_pair(x_1, cnt), ans + 1));
            visit[x_1][cnt] = true;
        }
        if(x_2 <= S+1 && !visit[x_2][clip])
        {
            q.emplace(std::make_pair(std::make_pair(x_2, clip), ans + 1));
            visit[x_2][clip] = true;
        }
        if(x_3 > 0 && !visit[x_3][clip])
        {
            q.emplace(std::make_pair(std::make_pair(x_3, clip), ans + 1));
            visit[x_3][clip] = true;
        }
    }
    return 0;
}

int main()
{
    scanf("%d", &S);
    //���� �� ����
    // Ŭ������ �ٿ��ֱ�
    // 1�� ����

    q.emplace(std::make_pair(std::make_pair(1, 0), 0));
    visit[1][0] = true;

    int ans = dfs();
    printf("%d\n", ans);
}
*/