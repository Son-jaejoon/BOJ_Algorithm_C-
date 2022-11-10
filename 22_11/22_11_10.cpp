#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <functional>
#define endl "\n"

using namespace std;

/* 11689�� GCD(n, k) = 1
// �ؼ� : GCD�� 1�� ���� n,k�� ���μҿ����Ѵ�. �̴� ���Ϸ� ���� �Լ��� �̿���
// n�� ���μ��� ���� �� ���Ϸ� �� ����� �̿��Ѵ�.
// TLE�� �޾� �� �����غ���, ���μ��� ���� �� �����佺�׳׽� ü�� ������ i*i ���� number�� ���� 1�� �ƴϸ�
// ���Ϸ� �� ����� �̿��� �־ TLE�� �ذ��� �� �־���.

long long N;

void solution()
{
    long long number = N;
    long long ans = N;

    vector<long long> v;

    for(long long i = 2 ; i*i <= number ; i++)
    {
        if(number % i == 0)
        {
            while(number % i == 0)
            {
                number /= i;
            }

            ans = ans*(1 - 1./i);
        }
    }

    if(number != 1)
    {
        ans = ans*(1 - 1./number);
    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    
    solution();
}
*/