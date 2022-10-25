#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <cstring>
#include <functional>
#define endl "\n"

using namespace std;

/* 2529�� �ε�ȣ
// �ؼ� : ũ�� ���� ���� �������ķ� �ذ��Ѵٴ� ���� �ű���. 
// (�ּ��ϰ��, A < B : A -> B A�� 0�� �ְ� ���� B�� 1�� �־���ؼ�
//  �ִ��ϰ��, A < B : B -> A B�� 9�� �ְ� ���� A�� 8�� �־���ؼ� )

int K;

int inDegree[10], outDegree[10];
vector<int> min_graph[10], max_graph[10];
char max_ans[11], min_ans[11]; 
bool chk[10];

void solution()
{
    priority_queue<int, vector<int>, greater<int>> pq; // 12345�� ��� �տ��� ���� �־���ϹǷ� ��������

    for(int i = 0 ; i <= K ; i++)
    {
        if(inDegree[i] == 0)
            pq.emplace(i);
    }

    while(!pq.empty())
    {
        int cur = pq.top();
        pq.pop();

        for(int i = 0 ; i < 10 ; i++)
        {
            if(!chk[i])
            {
                chk[i] = true;
                min_ans[cur] = char(i + '0');
                break;
            }
        }

        for(int i = 0 ; i < min_graph[cur].size() ; i++)
        {
            int next = min_graph[cur][i];
            if(--inDegree[next] == 0)
                pq.emplace(next);
        }
    }

    memset(chk, false, sizeof(chk));
    
    for(int i = 0 ; i <= K ; i++)
    {
        if(outDegree[i] == 0)
            pq.emplace(i);
    }

    while(!pq.empty())
    {
        int cur = pq.top();
        pq.pop();

        for(int i = 9 ; i >= 0 ; i--)
        {
            if(!chk[i])
            {
                chk[i] = true;
                max_ans[cur] = char(i + '0');
                break; 
            }
        }

        for(int i = 0 ; i < max_graph[cur].size() ; i++)
        {
            int next = max_graph[cur][i];

            if(--outDegree[next] == 0)
                pq.emplace(next);
        }
    }

    cout << max_ans << endl << min_ans;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;

    for(int i = 0 ; i < K ; i++)
    {
        char st;
        cin >> st;
        
        if(st == '<')
        {
            min_graph[i].emplace_back(i + 1);
            inDegree[i + 1]++;
            max_graph[i + 1].emplace_back(i);
            outDegree[i]++;
        }
        else if(st == '>')
        {
            min_graph[i + 1].emplace_back(i);
            inDegree[i]++;
            max_graph[i].emplace_back(i + 1);
            outDegree[i + 1]++;
        }
    }

    solution();
}
*/