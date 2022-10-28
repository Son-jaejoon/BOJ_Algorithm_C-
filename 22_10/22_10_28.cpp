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

/* 9527�� 1�� ���� ����
// �ؼ� : ��Ʈ ����ŷ, ��Ʈ�� ����, ���� ��
// ���� : https://degurii.tistory.com/158

long long A, B;

long long solution(long long x)
{
    x++;
    long long a = x, b = 1, ans = 0;

    while(a)
    {
        if(x & b)
            ans += x % b + (x - x % (b * 2)) / 2;
        else
            ans += (x - x % b) / 2;
        
        b <<= 1;
        a >>= 1;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    cout << solution(B) - solution(A - 1) << endl;
}
*/