#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

/* 14002�� ���� �� �����ϴ� �κ� ����4 ���ذ� �� �ʿ���
int main()
{
    int A;
    scanf("%d", &A);

    int arr[1000] = {1000, };
    int dp[1000] = {1000, }; // dp[idx] idx�� ���� �� ������ ����

    std::vector<int> long_arr[1000];
    std::vector<int> ans;

    std::fill(arr, arr+1000, 1000);

    for(int i = 0 ; i < A ; i ++)
    {
        scanf("%d", &arr[i]);
    }

    for(int i = 0 ; i < A ; i++)
    {
        dp[i] = 1;
        long_arr[i].push_back(arr[i]);

        for(int j = 0; j < i ; j++)
        {
            if(arr[i] > arr[j])
            {
                if(dp[i] < dp[j] + 1)
                {
                    long_arr[i].clear();
                    long_arr[i] = long_arr[j];
                    long_arr[i].push_back(arr[i]);
                    dp[i] = dp[j] + 1;
                }
            }
        }

        if(ans.size() < long_arr[i].size())
        {
            ans = long_arr[i];
        }
    }

    printf("%d\n", ans.size());

    for(int i = 0 ; i < ans.size(); i++)
    {
        if(i != ans.size() - 1)
        {
            printf("%d ", ans[i]);    
        }else printf("%d", ans[i]);
    }
}
*/

/* 16194�� ī�� �����ϱ�2
�ؼ�: ī�� �����ϱ� 1���� ���� DP����. �ּҷ� ���� �����ϱ� ������ price[1001]�� �ִ밪���� ���صδ� ���� ����.
int main()
{
    int N;
    scanf("%d", &N);

    int arr[1001] = {0, };
    int price[1001] = {10000, };

    std::fill(price, price + 1001, 10000);

    for(int i = 1 ; i <= N ; i++)
    {
        scanf("%d", &arr[i]);
    }

    price[0] = arr[0] = 0;

    for(int i = 1 ; i <= N ; i++)
    {
        for(int j = 1 ; j <= i ; j++)
        {
            price[i] = std::min(price[i], price[i-j] + arr[j]);
        }
    }

    printf("%d\n", price[N]);
}
*/

/* 11052�� ī�� �����ϱ�.
�ؼ�: DP����ϴ� ����. �� N���� ī�带 �����Ѵٸ� 1���� N-1�� ���� / 2���� N-2�� ���� --- i���� N-i�� ����(��ȭ��)
int main()
{
    int N;
    scanf("%d", &N);
    
    int arr[1001] = {0, };
    int price[1001] = {0, };

    for(int i = 1 ; i <= N ; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(int i = 1 ; i <= N ; i++)
    {
        for(int j = 1 ; j <= i ; j++)
        {
            price[i] = std::max(price[i], price[i - j] + arr[j]);
        }
    }

   printf("%d\n", price[N]);
}
*/