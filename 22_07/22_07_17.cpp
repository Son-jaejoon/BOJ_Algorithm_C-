#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
//����Լ� ������ DP �����ϱ�(��ȭ��)

/*��ȣ ����� 1759��
int l,c;

std::vector <char> vec;

bool isUsed[15];

void locker(int cnt, std::string s)
{
    if(cnt == l)
    {
        int consonant = 0; //����
        int vowel = 0; //����

        for(int i = 0 ; i < l ; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                vowel++;
                continue;
            }else consonant++;
        }

        if(vowel >= 1 && consonant >= 2) // ���� �ּ� 1��, ���� �ּ� 2��
            std::cout << s << '\n';

        return;
    }

    for(int i = 0 ; i < c ; i++)
    {
        if(!isUsed[i])
        {
            if(!s.empty()) // ���� ������� ������ ������� ������
            {
                if(s.back() > vec[i]) // ���� ������� ������ ���� vec[i] ���� ũ��
                    continue;
            }

            isUsed[i] = true;
            s.push_back(vec[i]);
            locker(cnt + 1, s); // cnt�� 4�� �ɶ����� �Լ� �ݺ�
            s.pop_back(); // cnt�� 4�� �Ǿ����� �������κи� ����
            isUsed[i] = false;
        }
    }
}


int main()
{
    scanf("%d %d", &l, &c);

    for(int i = 0; i < c ; i++)
    {
        char c;
        std::cin>>c;
        vec.push_back(c);
    }

    std::sort(vec.begin(), vec.end());

    locker(0, "");
}
*/

/* ��� 14501��
int date;
int timer[15] = {0, }, money[15] = {0, }, total[15] = {0, };

int max_money(int n)
{
    n -= 1;
    int deadline;
    for(int i = n ; i >= 0 ; i--)
    {
        deadline = i + timer[i];
        if(deadline > date)
        {
            timer[i] = 0;
            money[i] = 0;
            total[i] = total[i+1];
        }else
        {
            total[i] = std::max(total[i+1], total[deadline] + money[i]);
        }
    }

    return total[0];
}

int main()
{
    scanf("%d", &date);

    for(int i = 0; i<date ; i++)
    {
        scanf("%d %d", &timer[i], &money[i]);
    }

    printf("%d", max_money(date));
}
*/

/* 1, 2, 3 ���ϱ�


int divideNumber(int n)
{
    int want_number = n;
    if (n > 0)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 4;

        want_number = divideNumber(n-1) + divideNumber(n-2) + divideNumber(n-3);

        return want_number;
    }

    return 0;
}

int main()
{
    int case_num;
    scanf("%d", &case_num);
    for (int i = 0; i < case_num; i++)
    {
        int number;
        scanf("%d", &number);
        printf("%d \n", divideNumber(number));
    }
}
*/