#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#define endl "\n"

using namespace std;

/* 16974�� ���� �ܹ���
// �ؼ� : �Դ� �翡 ���� ������� �ƴ���
// ���� : https://nim-code.tistory.com/268

int n;
long long x;
long long dp[51];
long long patty[51];

long long get_patty(int N, long long X)
{
    if(N == 0)
    {
        if(X == 1)
            return 1;
        else if(X == 0)
            return 0;
    }

    if(X == 1)
        return 0;
    else if(X <= dp[N - 1] + 1)
        return get_patty(N - 1, X - 1);
    else if(X == 1 + dp[N - 1] + 1)
        return patty[N - 1] + 1;
    else if(X <= 1 + dp[N - 1] + 1 + dp[N - 1])
        return patty[N - 1] + 1 + get_patty(N - 1, X - 1 - dp[N - 1] - 1);
    else
        return patty[N - 1] * 2 + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> x;
    dp[0] = 1;
    patty[0] = 1;

    for(int i = 1 ; i <= n ; i++)
    {
        dp[i] = 1 + dp[i-1] + 1 + dp[i-1] + 1;
        patty[i] = patty[i - 1] + 1 + patty[i - 1]; 
    }

    cout << get_patty(n, x);
}
*/

/* 11066�� ������ġ��
// �ؼ� : �߸𸣰��� ���ذ� �ȵ�
// ���� : https://cocoon1787.tistory.com/317, https://melonicedlatte.com/algorithm/2018/03/22/051337.html

int k;

int file[501];
int sum[501];
int dp[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;

    cin >> T;
    while(T--)
    {
        cin >> k;

        for(int i = 1 ; i <= k ; i++)
        {
            cin >> file[i];
            sum[i] = sum[i - 1] + file[i];
        }

        for(int i = 1 ; i <= k ; i++)
        {
            for(int j = 1 ; j <= k - i ; j++)
            {
                dp[j][i+j] = 987654321;

                for(int k = j ; k < i+j ; k++)
                {
                    dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + sum[i+j] - sum[j-1]);
                }
            }
        }

        cout << dp[1][k] << endl;
    }
}
*/

/* 11058�� ũ������
// �ؼ� : 2,3,4�� ������ ���� �̷�������Ѵٴ� ���� �����ؾ���.
// 2,3,4,4 �� ���� �Ǳ� ������ ���� ���� vs ����� 4���� ����� �ݺ��ϴ��� ��� �� ����

long long dp[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    for(int i = 1 ; i <= n ; i++)
    {
        dp[i] = dp[i-1] + 1;

        for(int j = 3 ; j <= i; j++)
        {
            if(dp[i] < dp[i-j]*(j-1))
                dp[i] = dp[i-j]*(j-1);
        }
    }

    cout << dp[n];
}
*/