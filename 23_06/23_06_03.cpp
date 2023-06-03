#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <functional>
#include <climits>
#include <stack>
#include <numeric>
#include <deque>
#define endl "\n"

using namespace std;

/* 1105�� ��
// �ؼ� : ����, 8�� ���� ���� ����ִ� ��(8�� ������ �ȵǵ� �Ǵ� �ſ���.)
// url : https://www.acmicpc.net/problem/1105

string L, R;

void input()
{
    cin >> L >> R;
}

void solution()
{
    int answer = 0;

    if(L.size() != R.size())
    {
        cout << answer;
        return;
    }

    for(int i = 0 ; i < L.size() ; i++)
    {
        if(L[i] != R[i])
            break;

        if(L[i] == '8')
            answer++;
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