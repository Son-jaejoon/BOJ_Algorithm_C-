#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/* 2003�� ������ �� 2
//�ؼ�: ���� �ް� ó������ ���ؼ� ���� ������ ans++ or �ʰ��� break�� �ð� �Ƴ���.

int N;
long long M;
int A[10002];
int ans = 0;

void make_num(int num)
{
    long long tmp = 0;

    for(int i = num ; i <= N ; i++)
    {
        
        tmp += A[i];

        if(tmp == M)
        {
            ans++;
            make_num(num + 1);
            break;
        }else if(tmp > M)
        {
            make_num(num + 1);
            break;
        }
    }

    return;
}

int main()
{
    scanf("%d %lld", &N, &M);

    for(int i = 1 ; i <= N ; i++)
    {
        scanf("%d", &A[i]);
    }

    make_num(1);
    printf("%d", ans);
}
*/

/* 1339�� �ܾ� ����
//�ؼ� : �ش� ������ �׸��� �˰������� �ڸ��� ���� ���� �� ����ū ���� 9~1���� ���ϴ� ���
//�׸��� �˰����� ��� ���� �� ��� ���� : https://sectumsempra.tistory.com/88

int N;
int alphabet[26];
std::string str;
std::vector<std::string> v;

bool cmp(int A, int B)
{
    if (A > B) return true;
    return false;
}

void max_word()
{
    for(int i = 0 ; i < N ; i++)
    {
        std::string s = v[i];
        int len = s.length();
        int pow = 1;

        for(int j = len - 1 ; j >= 0 ; j--)
        {
            int tmp = s[j] - 'A';
            alphabet[tmp] = alphabet[tmp] + pow;

            pow = pow * 10;
        }
    }
    std::sort(alphabet, alphabet + 26, cmp);

    int ans = 0;
    int num = 9;
    
    for(int i = 0 ; i < 26 ; i++)
    {
        if(alphabet[i] == 0)
            break;
        
        ans = ans + (alphabet[i] * num);
        num--;
    }

    printf("%d", ans);
}

int main()
{
    scanf("%d", &N);

    for(int i = 0 ; i < N ; i++)
    {
        std::cin>>str;
        v.emplace_back(str);
    }

    max_word();
}
*/

/* 14888�� ������ �����ֱ�
//�ؼ�: ��Ʈ��ŷ�� ����Լ��� ��� �����ϴ����� ����.
//if return ���� �� ������ ������ ����, for���� ��� �ݺ��ؾ��ϹǷ� �����ڸ� ����
//����: https://cryptosalamander.tistory.com/60

int arr[11];
int op[4];
int N;
int my_max = -1000000001;
int my_min = 1000000001;
int temp;

void max_min_fx(int result, int idx)
{
    if (idx == N)
    {
        my_max = std::max(my_max, result);
        my_min = std::min(my_min, result);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (op[i] > 0)
        {
            op[i]--;

            if (i == 0)
            {
                max_min_fx(result + arr[idx], idx+1);
            }else if (i == 1)
            {
                max_min_fx(result - arr[idx], idx+1);
            }else if (i == 2)
            {
                max_min_fx(result * arr[idx], idx+1);
            }else
            {
                max_min_fx(result / arr[idx], idx+1);
            }

            op[i]++;
        }
    }

    return;
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &op[i]);
    }

    max_min_fx(arr[0], 1);

    printf("%d\n%d", my_max, my_min);
}
*/