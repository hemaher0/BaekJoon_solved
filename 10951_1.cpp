#include <iostream>
using namespace std;
int main()
{
    int a, b;

    while (true) {
        cin >> a >> b;
        if (cin.eof() == true) {
            // cin���� �Է¹��� ���� ������
            // cin.eof()�� true�� ��ȯ�Ѵ�. �翬�� �׷��� ������ false ��ȯ
            break;
        }
        cout << a + b << endl;
    }
}