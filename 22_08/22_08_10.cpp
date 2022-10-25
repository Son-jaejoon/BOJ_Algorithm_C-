#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#define endl "\n"

using namespace std;

/* 12869�� ��Ż����ũ
// �ؼ� : 1. ü���� �ش�Ȱ� �ֳ� �޸������ 2. scv�� ������ �ٽ� �����ؼ� �ִ´�. 3. 6���� ����� ���� �ִ´�.
// ���� : https://transferhwang.tistory.com/462

int N;
vector<int> scv;
int dp[61][61][61];

int attack(int x, int y, int z)
{
    if(x < 0) return attack(0, y, z);
    if(y < 0) return attack(x, 0, z);
    if(z < 0) return attack(x, y, 0);

    if(dp[x][y][z] != -1)
        return dp[x][y][z]; // �޸������
    
    if(x == 0 && y == 0 && z == 0)
        return 0;
    
    dp[x][y][z] = 987654321;
    dp[x][y][z] = min(dp[x][y][z], attack(x - 9, y - 3, z - 1) + 1);
    dp[x][y][z] = min(dp[x][y][z], attack(x - 9, y - 1, z - 3) + 1);
    dp[x][y][z] = min(dp[x][y][z], attack(x - 3, y - 1, z - 9) + 1);
    dp[x][y][z] = min(dp[x][y][z], attack(x - 1, y - 3, z - 9) + 1);
    dp[x][y][z] = min(dp[x][y][z], attack(x - 3, y - 9, z - 1) + 1);
    dp[x][y][z] = min(dp[x][y][z], attack(x - 1, y - 9, z - 3) + 1);

    return dp[x][y][z];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    scv.assign(3, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> scv[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << attack(scv[0], scv[1], scv[2]);
}
*/

/* 2294�� ���� 2
// �ؼ� : ���� ������ ���⶧���� ������  +1 �ϴ� ���� �˾�ä�°� �ٽ�
// ���� : https://jaemin8852.tistory.com/163

int n, k;
vector<int> v;
vector<int> dp;

void coin()
{

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = v[i] ; j <= k ; j++)
        {
            dp[j] = min(dp[j], dp[j - v[i]] + 1);
        }
    }

    if(dp[k] == 10001)
        cout << -1;
    else
        cout << dp[k];
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    v.assign(n, -1);
    dp.assign(k + 1, 10001);
    dp[0] = 0;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> v[i];
    }

    coin();
}
*/

/* 2293�� ���� 1
// �ؼ� : ������ ��ġ�� ���ݺ��� ������ ����� ���� 1�� �߰���

int n, k;
vector<int> v;
vector<int> dp;

void coin()
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 1 ; j <= k ; j++)
        {
            if(j - v[i] >= 0)
            {
                dp[j] = dp[j] + dp[j - v[i]];
            }
        }
    }

    cout << dp[k];
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    v.assign(n, 0);
    dp.assign(k + 1, 0);
    dp[0] = 1;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> v[i];
    }

    coin();
}
*/