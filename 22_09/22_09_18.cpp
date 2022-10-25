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

/* 1695�� �Ӹ���� �����
// �ؼ� : DP�ε� ��ͷ� ���� ���� �����.
// ���� : https://tinyurl.com/2htfhxq6

int N;
vector<int> arr;
vector<vector<int>> dp;

int solution(int s, int e)
{
    if(s >= e)
        return 0;
    
    if(dp[s][e] != -1)
        return dp[s][e];
    
    int cnt = 0;
    
    if(arr[s] == arr[e])
        cnt = solution(s + 1, e - 1);
    else
        cnt = min(solution(s, e - 1) + 1, solution(s + 1, e) + 1);
    
    return dp[s][e] = cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    arr.assign(N, 0);
    dp.assign(N, vector<int>(N, -1));

    for(int i = 0 ; i < N ; i++)
    {
        cin >> arr[i];
    }

    cout << solution(0, N - 1);
}
*/

/* 10942�� �Ӹ����?
// �ؼ� : �Ӹ������ ������ �����ؼ� �ϳ��� �ϴ°��� DP -> ó���� 1,2�� Ȯ���ϴ°� �߿���.
//���� : https://j3sung.tistory.com/107

int N, M;

vector<int> arr;
queue<pair<int, int>> question;
vector<vector<int>> chk;

void solution()
{
    for(int i = 1 ; i <= N ; i++)
    {
        chk[i][i] = 1;
        if(arr[i] == arr[i-1])
            chk[i - 1][i] = 1;
    }

    for(int i = 2 ; i < N ; i++) // ũ��
    {
        for(int j = 1 ; j <= N - i ; j++) // ����
        {
            int k = i + j; // ��

            if(arr[j] == arr[k] && chk[j + 1][k - 1] == 1) // �� ���� ����, ���̰� �Ӹ�����̸�
                chk[j][k] = 1;
        }
    }

    while(!question.empty())
    {
        int s = question.front().first;
        int e = question.front().second;
        question.pop();

        cout << chk[s][e] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    arr.assign(N + 1, 0);
    chk.assign(N + 1, vector<int>(N + 1, 0));

    for(int i = 1 ; i <= N ; i++)
    {
        cin >> arr[i];
    }

    cin >> M;

    for(int i = 0 ; i < M ; i++)
    {
        int s, e;
        cin >> s >> e;
        question.emplace(make_pair(s, e));
    }

    solution();
}
*/