//���������� ���������� ������� ��������
//�� ���� ���������� ������� �� �����������
//����� �������� ������� �� ��� ���������� �������� �������� ������

#include <iostream>
using namespace std;
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>

void sortingArray(int a[], int arraySize);              //�������� ����������� �������

int main(){
    const int arraySize = 10;                           //������������� ������� �������
    int randArray[arraySize];                           //�������� �������

    cout << "\n\t\tRandom array is:" << endl;           //������������� ��������� ������ � �������� ���
    srand(time(0));
    for (int i = 0 ; i < arraySize/2 ; i++){
        randArray[i] = rand()%100;
        randArray[i+arraySize/2] = rand()%100;
        cout << "randArray[" << setw(2) << i << "] = " << setw(2) << randArray[i] << "   ";
        cout << "randArray[" << setw(2) << i+arraySize/2 << "] = " << setw(2) << randArray[i+arraySize/2] << endl;
    }

    sortingArray(randArray, arraySize);                 //������� �������. ������� ����������� ��������� ������

    cout << "\n\n\t\tSorting array is:" << endl;        //�������� ��������������� ������
    for (int i = 0 ; i < arraySize/2 ; i++){
        cout << "randArray[" << setw(2) << i << "] = " << setw(2) << randArray[i] << "   ";
        cout << "randArray[" << setw(2) << i+arraySize/2 << "] = " << setw(2) << randArray[i+arraySize/2] << endl;
    }

    cout << "\n\n";                                     //��������� ��������
    system("pause");
}

void sortingArray(int a[], int arraySize){              //�������� ����������� �������
    int insertFromArray;                                //������, ������� ������ "�������" �� �������
    int step;                                           //��� ���������� ��� �������� �������� ���������� �����

    for (int i = 1 ; i < arraySize ; i++){              //���� ����������
        insertFromArray = a[i];                         //��������� ������� ������ �� �������
        step = i - 1;                                   //������� ���������� ������ �� �������

        while( (step >= 0) && (a[step] > insertFromArray) ){    //������ ���� 1)��� ����� ����������� � 2)���� ������� ������, ��� "�������" ������ �� �������
            a[step+1] = a[step];                        //������������ �� 1 ������ � ����� ������� �������� ������� ������
            step--;                                     //��������� ��� �� 1
        }
        a[step+1] = insertFromArray;                      //������� �������� "�������" � ������� ������
    }
}
