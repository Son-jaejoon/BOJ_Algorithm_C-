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

/* 6549�� ������׷����� ���� ū ���簢��
// �ؼ� : ����, ���׸�Ʈ Ʈ��
// url : https://www.acmicpc.net/problem/6549

vector<long long> v;

void solution()
{
    long long answer = 0;
    stack<long long> s;
    s.emplace(0);

    for(int i = 1 ; i < v.size() ; i++)
    {
        while(!s.empty() && v[s.top()] > v[i])
        {
            int curr = s.top();
            s.pop();
            answer = max(answer, v[curr]*(i - s.top() - 1));
        }

        s.emplace(i);
    }

    cout << answer << endl;;
}

void input()
{
    int t;

    while(1)
    {
        cin >> t;
        
        if(t == 0)
            break;
        
        v.assign(t + 2, 0);

        for(int i = 1 ; i <= t ; i++)
        {
            cin >> v[i];
        }

        solution();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
}
*/