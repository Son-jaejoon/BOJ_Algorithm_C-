#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>

/* 16929�� Two Dots
//�ؼ�: dfs�� �̿��� ����. �����¿�� �̵��ϵ� �ݴ� �� ���� �̵��� return. �� �ܿ� ���� �ڽ��ȿ� �ִ���
//type�� ������ ��� �� ������ ����. ���� ������ ���ٰ� üũ����Ʈ�� true�̰� type�� ���ٸ� ù�ڸ��� ����
//�� ���̱� ������ ���� ���� ������ �����Ѵ�.
//���� : https://rolypolytoy.tistory.com/34

char map[51][51];
bool chk[51][51];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n,m;

void dfs(int x, int y, char type, int d)
{
    chk[x][y] = true;

    if(map[x][y] != type)
        return;

    for(int i = 0 ; i < 4 ; i++)
    {
        if(i == ((d + 2) % 4))
            continue;
        
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == type && !chk[nx][ny])
        {
            dfs(nx, ny, type, i);
        }else if(map[nx][ny] == type && chk[nx][ny])
        {
            printf("Yes");
            exit(0);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    for(int i = 0; i<n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            std::cin>>map[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            char tmp = map[i][j];

            if(!chk[i][j])
            {
                int d = -1;

                for(int k = 0; k < 4 ; k++)
                {
                    if(map[i+dx[k]][j + dy[k]] == tmp)
                    {
                        d = k;
                        break;
                    }
                }

                if(d == -1)
                    continue;
                
                dfs(i, j, tmp, d);
            }
        }
    }

    printf("No");
}
*/

/* 1644�� �Ҽ��� ������
//�ؼ� : ���ϴ� ���� 1/2 ���� ū �Ҽ��� ��� �ּ� 2���� ���ϴ��� ���� �Ǳ⶧����
//i�� 2�谡 ���ϴ� N�� ������ ���� ��츦 ���Ϳ� ���� �� �������� �� ���

int main()
{
    int N;
    std::vector<bool> check;
    std::vector<int> prime;

    scanf("%d", &N);
    check.resize(N + 1, true);

    for (int i = 2; i * i <= N; i++)
    {
        if (check[i] == true)
        {
            for (int j = i + i; j <= N; j += i)
                check[j] = false;
        }
    }

    for (int i = 2; i < N + 1; i++)
    {
        if (check[i] == true)
            prime.push_back(i);
    }

    int cnt = 0, high = 0, low = 0, sum = 0;

    while (1)
    {
        if (sum >= N)
            sum -= prime[low++];
        else if (high == prime.size())
            break;
        else
            sum += prime[high++];

        if (sum == N)
            cnt++;
    }

    printf("%d", cnt);
    return 0;
}
*/

/* 1806�� �κ���
// �ؼ�: �� Ʋ���� �𸣰ڴ�.
int N;
int S;

int arr[100001];
int length = 100001;

void part_sum(int num)
{
    int tmp = 0;

    for (int i = num; i < N; i++)
    {
        tmp = tmp + arr[i];

        if (tmp >= S)
        {
            if (length > i - num + 1)
            {
                length = i - num + 1;
            }

            part_sum(num + 1);
            return;
        }
    }

    return;
}

int main()
{
    scanf("%d %d", &N, &S);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    if(std::accumulate(arr, arr + N, 0) < S)
        printf("0");
    else
    {
        part_sum(0);
        printf("%d", length);
    }
}
*/