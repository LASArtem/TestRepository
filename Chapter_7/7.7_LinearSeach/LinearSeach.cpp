//��������� ��������� �������� ����� �� �������
//� �����, ��������� ������ �� ���������� ������� �� 0 �� 39
//����� �������� �������: 40

#include <iostream>
using namespace std;
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>

void linearSearch(int a[], int arraySize, int key);             //�������� ������� - ������ ����� �� ������� �����

int main(){
    const int arraySize = 40;                                   //���������� ������� �������
    int QQ[arraySize];                                          //�������� �������
    int keyForSearch;                                           //�������� ������ ��� ���� ������

    while ((keyForSearch >= arraySize)||(keyForSearch < 0)){    //���� ����� � ��������� �� 0 �� 39
        system("cls");
        cout << "\n\n\n\tPlease, enter number for search in array \n\n\t\tfrom 0 to "<< arraySize << ": ";
        cin  >> keyForSearch;
    }

    system("cls");
    cout << "\n\n\tYou enter number: " << keyForSearch << endl; //�������� ���� ������
    cout << "\n\tRandom array is: \n" << endl;
    srand(time(0));
    for (int i = 0 ; i < arraySize ; i++){                      //���������� � ��������� ������� �����
        QQ[i] = rand()%arraySize;
        cout << "array[" << setw(2) << i << "] = " << setw(2) << QQ[i];
        if ((i%4) == 3){
            cout << endl;
        }
        else{
            cout << "     ";
        }
    }
    linearSearch(QQ, arraySize, keyForSearch);                  //������ ������� ������

    cout << "\n\n";
    system("pause");                                            //��������� ���������
}

void linearSearch(int a[], int arraySize, int key){             //����������� ������� - ������
    int flag = 0;                                               //����� �������� ����������
    cout << "\n\n\tWe will search your number at random array:\n\n";
    for (int i = 0 ; i < arraySize ; i++){                      //����� � ��������� ����� ������� �� ���������� � ������ ������
        if (a[i] == key){
            cout << "Program finds your number at " << i << "-element of our random array" << endl;
            flag++;
        }
    }

    if (flag == 0){                                             //���� ���������� �� ���� �� �� ���� �������
        cout << "Your number did not find at random array";
    }
}
