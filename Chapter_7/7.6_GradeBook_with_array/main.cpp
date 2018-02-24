//������������ ������� ������ GradeBook.
//� ������ ����� ������� ������ ������.
//������ ������ ������ ��� �������� � ���������� ��� �� ���������� ������������.

#include <iostream>
#include <string>
using namespace std;

#include "CGradeBook.hpp"
#include <windows.h>

int main(){
    string nameOfCourseByUser;                                      //������ ��� ���������� �������� ������
    int gradesByUser[CGradeBook::numberOfStudents];                 //������ ��� �������� ������
    int choice = 1;                                                 //����� �� ������ ������ ������� (1 - ��, 2 - ���)

    cout << "\n\n\t\tWelcome to program with arrays" << endl;       //����������
    cout << "\n\n\tPlease, Enter name of course: " ;                //������ �� ���� ����� �����
    cin  >> nameOfCourseByUser;                                     //���������� ����� �����

    for (int counter = 0; counter < CGradeBook::numberOfStudents ; counter++ ){     //���� �� ���� ������� �� 0 �� 100
        system("cls");

        if (counter == 0){                                                          // �������� ��� ������ ������� �����
             cout << "\n\n\tEnter " << CGradeBook::numberOfStudents << " marks for your students: " << endl;
        }

        cout << "\n\n\t\tEnter mark for student #" << counter + 1 << ": ";          //������ ������ N-���� ��������
        cin  >> gradesByUser[counter];                                              //������� ������

        while ((gradesByUser[counter] > 100)||(gradesByUser[counter] < 0)){         //���� ��� �� ������ � ����������
                                                                                    //�� 0 �� 100, ����� ����� � While
                                                                                    //� �� �������� ���� ������ ��
                                                                                    //������� � ������ ����������
            system("cls");
            cout << "\n\n\tYou have written wrong grade for student #" << counter + 1 << " !!!" << endl;
            cout << "\n\n\t\tGrade must be in range from 0 to 100 " << endl;
            cout << "\n\n\tEnter another mark for student #" << counter + 1 << ": ";
            cin  >> gradesByUser[counter];
        }
     }

    CGradeBook myCGradeBook(nameOfCourseByUser , gradesByUser);     //������� ������ ������ CGradeBook
    while (choice == 1){                  //���� �� ����������
        system("cls");
        myCGradeBook.displayMessage();                              //�������� ����������
        choice = myCGradeBook.actWithGrades();                      //�������� �������� ��� ��������

        if (choice == 1){                                            //������ �� ������ ���������
            cout << "\n\n\t\tDo you want to do something else?" << endl;
            cout << "\n\t\t\t\t1 - yes" << endl;
            cout << "\t\t\t\t2 - no" << endl;
            cout << "\n\t\t\tYour choice is: ";
            cin  >> choice;
        }
    }

    system("cls");
    cout << "\n\n\n\t\tProgram was created by Lebedev Artem" << endl;   //����� ��������� ���������
    cout << "\n\n\t\t\tSpecial for himself\n\n" << endl;
    system("pause");
}
