#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <functional>
#define endl "\n"

using namespace std;

/* 17779�� �Ը��Ǵ��� 2
// �ؼ� : ���� ������. üũ�Ѵ�.
// ���� : https://yabmoons.tistory.com/300

int N;
int ans = 987654321;
vector<vector<int>> arr;
vector<vector<int>> label;
int save[5];

bool CanMakeLine(int y, int x, int d1, int d2)
{
    if (y + d1 >= N || x - d1 < 0)
        return false;
    if (y + d2 >= N || x + d2 >= N)
        return false;
    if (y + d1 + d2 >= N || y - d1 + d2 >= N)
        return false;
    if (y + d2 + d1 >= N || y + d2 - d1 < 0)
        return false;
 
    return true;
}

void calculate(int y, int x, int d1, int d2)
{
    for(int i = 1 ; i <= N ; i++)
    {
        for(int j = 1 ; j <= N ; j++)
        {
            label[i][j] = 5;
        }
    }

    //1��
    int vote_1 = 0;

    for(int i = 1 ; i < y + d1 ; i++)
    {
        for(int j = 1 ; j <= x ; j++)
        {
            label[i][j] = 1;
            vote_1 += arr[i][j];
        }
    }
    save[0] = vote_1;

    //2��
    int vote_2 = 0;

    for(int i = 1 ; i <= y + d2 ; i++)
    {
        for(int j = x + 1 ; j <= N ; j++)
        {
            label[i][j] = 2;
            vote_2 += arr[i][j];
        }
    }
    save[1] = vote_2;

    //3��
    int vote_3 = 0;

    for(int i = y + d1 ; i <= N ; i++)
    {
        for(int j = 1 ; j < x - d1 + d2 ; j++)
        {
            label[i][j] = 3;
            vote_3 += arr[i][j];
        }
    }
    save[2] = vote_3;

    //4��
    int vote_4 = 0;

    for(int i = y + d2 ; i <= N ; i++)
    {
        for(int j = x - d1 + d2 ; j <= N ; j++)
        {
            label[i][j] = 4;
            vote_4 += arr[i][j];
        }
    }
    save[3] = vote_4;

    //5��
    int vote_5 = 0;

    for(int i = 1 ; i <= N ; i++)
    {
        for(int j = 1; j <= N ; j++)
        {
            if(label[i][j] == 5)
                vote_5 += arr[i][j];
        }
    }
    save[4] = vote_5;

    sort(save, save + 5);
    int result = save[5] - save[1];
    
    ans = min(ans, result);
}

void solution()
{
    for(int i = 1 ; i <= N ; i++)
    {
        for(int j = 1 ; j <= N ; j++)
        {
            for(int d1 = 1 ; d1 < j ; d1++)
            {
                for(int d2 = 1 ; d2 < N - j ; d2++)
                {

                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    arr.assign(N + 1, vector<int>(N + 1, 0));
    label.assign(N + 1, vector<int>(N + 1, 5));

    for(int i = 1 ; i <= N ; i++)
    {
        for(int j = 1 ; j <= N ; j++)
        {
            cin >> arr[i][j];
        }
    }

    solution();
    cout << ans;
}
*/

/* 17085 ���ڰ� 2�� ����
// �ؼ� : �� ���ƿ�

int N, M;
char map[15][15];
int answer = 0;

//�� �� �� ��
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

//(r,c)�� �߽��� ��, ������ ���ڰ��� �ִ� ũ��
int getSize(int r, int c){  
    int ret = 0;
    while(1){
        bool flag = true;
        for(int i = 0; i<4; i++){
            int nr = r + dr[i]*ret;
            int nc = c + dc[i]*ret;
            if(nr<0 || nc<0 || nr>=N || nc>=M || map[nr][nc] != '#'){
                flag = false;
                break;
            }
        }
        if(flag) ret++;
        else break;
    }
    return ret - 1; //ret�� 0���� �����ϹǷ�, ó�� ����ϸ� ret=1�� �Ǵµ� �̶� ���ڰ��� ũ��� 0�� ('*' �Ѱ�¥��)
}

//�߽��� (r,c)�̰� ũ�Ⱑ K�� ���ڰ��� ����ų�(val='#') ���ڰ� ���󺹱�(val='.')
void make_cross(int r, int c, int k, int val){ 
    for(int i = 0; i<=k; i++){
        for(int j = 0; j<4; j++){
            int nr = r + dr[j]*i;
            int nc = c + dc[j]*i;
            map[nr][nc] = val;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }


    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(map[i][j] == '#'){
                int step1 = getSize(i,j);
                for (int k = 0; k <= step1; k++)    //ù��° ���ڰ� ũ�� 1���� max����, 
                {
                    make_cross(i,j,k,'*');  //ù��° ���ڰ� ǥ��

                    for(int r = 0; r<N; r++){
                        for(int c=0; c<M; c++){
                            if(map[r][c] == '#'){
                                int step2 = getSize(r,c); //�� ũ�⿡ ���� �ι�° ���ڰ� ũ�� ���ϱ�
                                int width1 = 4*k + 1;
                                int width2 = 4*step2 + 1;
                                answer = max(answer, width1*width2);
                            }
                        }
                    }
                    make_cross(i,j, k, '#');    //ù��° ���ڰ� ���󺹱�


                }
            } 
        
            
        }
    }
    
   
    cout << answer;

    return 0;
}
*/