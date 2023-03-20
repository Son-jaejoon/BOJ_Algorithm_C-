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

/* 1406�� ������
// �ؼ� : 1�� �������� ���� ������ �ٴڿ� ���� ����(left, right);
// url : https://www.acmicpc.net/problem/1406

void input()
{
    string st;
    int M;

    stack<char> left;
    stack<char> right;

    cin >> st >> M;

    for(char a : st)
        left.emplace(a);

    for(int i = 0 ; i < M ; i++)
    {
        char ch;
        cin >> ch;

        if(ch == 'P')
        {
            char input_ch;
            cin >> input_ch;

            left.emplace(input_ch);
        }
        else if(ch == 'L')
        {
            if(!left.empty())
            {
                right.emplace(left.top());
                left.pop();
            }
        }
        else if(ch == 'D')
        {
            if(!right.empty())
            {
                left.emplace(right.top());
                right.pop();
            }
        }
        else if(ch == 'B')
        {
            if(!left.empty())
                left.pop();
        }
    }

    while(!left.empty())
    {
        right.emplace(left.top());
        left.pop();
    }

    while(!right.empty())
    {
        cout << right.top();
        right.pop();
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