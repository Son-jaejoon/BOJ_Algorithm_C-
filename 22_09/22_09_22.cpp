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

/* 2096�� ��������
// �ؼ� : ������ �̷��� Ǫ�°��� �������� ��Ǯ����. �����̵� ������(������ ���� �ȱ�) + DP
// ���� : https://blog.naver.com/kks227/220795165570

int N;

int colMax[3], colMin[3], tmpMax[3], tmpMin[3];

void solution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> tmpMax[j];
            tmpMin[j] = tmpMax[j];
            tmpMax[j] += max(colMax[1], (j == 1) ? max(colMax[0], colMax[2]) : colMax[j]);
            tmpMin[j] += min(colMin[1], (j == 1) ? min(colMin[0], colMin[2]) : colMin[j]);
        }
        memcpy(colMax, tmpMax, sizeof(tmpMax));
        memcpy(colMin, tmpMin, sizeof(tmpMin));
    }

    sort(colMax, colMax + 3);
    sort(colMin, colMin + 3);

    cout << colMax[2] << " " << colMin[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    solution();
}
*/

/* 1300 K��° ��
// �ؼ� : �̺й迭���� ���ݰ� idx������ �Ϸ������� N�� Ŀ���� �ð��ʰ���.
// �׷��Ƿ� �ٸ� �ذ� ���� ã�� idx���� �־������Ƿ� �װ� ���� �۰� ����ϴ� ����� �˾ƾ���.
// �̺� Ž���� ��� low, high�� ������ ��Ȯ�ϰ� ��� ������ ��𿡼� �����ؾ����� �� �˾ƾ���.
// ���� : https://jaimemin.tistory.com/988

long long N, K;

void solution()
{

    long long start_idx = 1;
    long long end_idx = K;
    long long ans = 0;

    while(start_idx <= end_idx)
    {
        long long mid = (start_idx + end_idx)/2;
        long long cnt = 0;

        for(int i = 1 ; i <= N ; i++)
        {
            cnt += min(mid / i, N); // 1���� idx�� ������ y�� �ϸ� ���� ������ ���� -> 1�ΰ�� N���� Ŀ���Ƿ� �ּҰ��� ���ϴ� ��

            if(cnt >= K)
                break;
        }

        if(cnt >= K)
        {
            ans = mid; // cnt�� k�� �� ������, cnt >= K�� �� ans�� �����س�����.
            end_idx = mid - 1;
        }
        else
        {
            start_idx = mid + 1;
        }
    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    solution();
}
*/