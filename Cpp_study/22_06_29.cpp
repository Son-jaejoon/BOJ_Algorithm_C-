/* �ϳ��� ����ü������ ����ϴ� ��ũ�� ����� ���������� ��ü
 #define ID_LEN   20 -> 
 enum
 {
    ID_LEN = 20
 };
*/

/* ��ũ�� ��� ���� �̸�����(namespace)�ȿ� ���� ��
 namespace CAR_CONST
   {
        enum
        {
            ID_LEN = 20
        ;}
   }

   struct Car
   {
        char gamerID[CAR_CONST::ID_LEN];
   }
*/

//����ü�� Ŭ������ ���̴� �������������ڸ� ǥ������ �ʾ��� �� ����ü�� public, Ŭ������ private�� ����ȴ�.