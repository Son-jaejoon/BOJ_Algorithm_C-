#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

/* 13913�� ���ٲ��� 4
//�ؼ� : ���ڲ��� 1�� �������� �迭�� ���� ���� ������ �� �ش� ���� �������� ã�� ���.
int N, K;
int ans = 0;

std::queue<std::pair<int,int>> q;
int graph[100001];
std::vector<int> load;

bool visit[100010];

int bfs()
{
    while(!q.empty())
    {
        int locate = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(locate == K)
        {
            ans = cost;
            int idx = locate;
        
            while(idx != N)
            {
                load.emplace_back(idx);
                idx = graph[idx];
            }
            load.emplace_back(N);
            return ans;
        }

        int x_1 = locate - 1;
        int x_2 = locate + 1;
        int x_3 = locate * 2;

        if(0 <= x_1 && !visit[x_1])
        {
            visit[x_1] = true;
            q.emplace(std::make_pair(x_1, cost + 1));
            graph[x_1] = locate;
        }

        if(x_2 <= K && !visit[x_2])
        {
            visit[x_2] = true;
            q.emplace(std::make_pair(x_2, cost + 1));
            graph[x_2] = locate;
        }

        if(x_3 <= K+1 && !visit[x_3])
        {
            visit[x_3] = true;
            q.emplace(std::make_pair(x_3, cost + 1));
            graph[x_3] = locate;
        }
    }

    return 0;
}

int main()
{
    scanf("%d %d", &N, &K);

    q.emplace(std::make_pair(N, 0));

    printf("%d\n", bfs());

    for(int i = load.size() - 1 ; i >= 0 ; i--)
    {
        printf("%d ", load[i]);
    }
}
*/

/* 1697�� ���ٲ���
//�ؼ�: BFS�� ����ϴ� ����. ������ ���� �������� ���� ���ϰų� ���� ���� ���� �ش� ���� ť�� �ִ´�.
//���� �ش� ���� �湮�� �Ǿ��ִ� ���¶�� �̹� �ڿ��� ������ �Ǳ⶧���� �ߺ������� ���� �� �ִ�.

int N, K;
int ans = 0;
std::queue<std::pair<int, int>> q;
bool isChk[100010];

int bfs()
{
    while(!q.empty())
    {
        int locate = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(locate == K)
        {
            ans = cost;
            return ans;
        }

         int x_1 = locate - 1;
         int x_2 = locate + 1;
         int x_3 = locate * 2;

         if(0 <= x_1 && !isChk[x_1])
         {
            isChk[x_1] = true;
            q.emplace(std::make_pair(x_1, cost + 1));
         }

         if(x_2 <= K && !isChk[x_2])
         {
            isChk[x_2] = true;
            q.emplace(std::make_pair(x_2, cost + 1));
         }

         if(x_3<= K+1 && !isChk[x_3])
         {
            isChk[x_3] = true;
            q.emplace(std::make_pair(x_3, cost + 1));
         }         
    }

    return 0;
}

int main()
{
    //������ +1 or -1 �ѹ� �̵��� �Ѵ� 1��
    //�����̵� �ϸ� 2*X

    scanf("%d %d", &N, &K);

    q.emplace(std::make_pair(N, 0));

    printf("%d\n", bfs());
}
*/