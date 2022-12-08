#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <functional>
#include <climits>
#include <stack>
#include <numeric>
#define endl "\n"

using namespace std;

/* 13172�� ��
// �ؼ� : ������ �� ���� ���� �ϴ� �� �����ϱ� �������., ���������� �̿��� �ŵ�����

long long M, N, S, answer;
long long mod = 1000000007;

long long power(long long x, long long y)
{
    long long res = 1;

    while(y > 0)
    {
        if(y & 1)
            res = (res*x) % mod;
        
        x = (x*x) % mod;
        y >>= 1;
    }

    return res % mod;
}

void input()
{
    cin >> M;
}

void solution()
{
    while(M--)
    {
        cin >> N >> S;

        long long g = gcd(S, N);
        
        N /= g;
        S /= g;

        answer += S*power(N, mod - 2)%mod;
        answer %= mod;
    }

    cout << answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solution();
}
*/