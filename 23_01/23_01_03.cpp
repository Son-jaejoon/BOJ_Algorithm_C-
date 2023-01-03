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

/* 11279�� �ִ� ��
// �ؼ� : �켱���� ť
// url : https://www.acmicpc.net/problem/11279

void input()
{
    int N;
    cin >> N;

    priority_queue<int> pq;

    for(int i = 0 ; i < N ; i++)
    {
        int num;
        cin >> num;

        if(num == 0)
        {
            if(pq.empty())
            {
                cout << "0" << endl;
            }
            else
            {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else
        {
            pq.emplace(num);
        }
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