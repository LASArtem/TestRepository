//�������� ������� ������ CGradeBook
#include <string>
#include <iostream>
using namespace std;

#include "CGradeBook.hpp"
#include <windows.h>

CGradeBook::CGradeBook(string name, int grades[])                       //����������� ������� ��� ����� � ������ ������
{
    setCourseName(name);                                                //��������� ���������� ���
    for (int counter = 0 ; counter < numberOfStudents ; counter ++){    //��������� ���������� ������
        gradesOfStudents[counter] = grades[counter];
    }
}

CGradeBook::~CGradeBook()                                               //����������
{

}

void CGradeBook::setCourseName(string name){                            //�������� ����� �����
    nameOfCourse = name;                                                //��������� ��� ����� � ������ nameOfCourse
}

string CGradeBook::getCourseName(){                                     //��������� ��� �����
    return nameOfCourse;                                                //������� ��� �����
}

void CGradeBook::displayMessage(){                                      //������� ���������� ��� ��������� ������
    cout << "Welcome to Grade Book for: " << getCourseName() << endl;   //����� ������ ���������
}

int CGradeBook::actWithGrades(){                                       //�������� ��� ��������
    int choice2;
    cout << "\n\n\t\tWhat do you want to do?:" << endl;
    cout << "\n\t1 - watch all grades." << endl;                        // 1 - �������� ��� ������
    cout << "\t2 - find out max grade." << endl;                        // 2 - ����� ������������ ������
    cout << "\t3 - find out min grade." << endl;                        // 3 - ����� ����������� ������
    cout << "\t4 - find out average grade. (CREDHEE 4uclo)" << endl;    // 4 - ����� ������� ������
    cout << "\t5 - watch on diagram of grades." << endl;                // 5 - �������� ��������� ������������� ������
    cout << "\t6 - exit from GradeBook" <<endl;                         // 6 - ����� �� ���������
    cout << "\n\n\t\t\tYour choice is: ";                               //��� ����� ��� :
    cin  >> choice2;                                                    //������� �����
    system("cls");

    switch (choice2)                //����� Switch ���������� �������������� �������
    {
        case 1:
            watchAllGrades();
            return 1;
            break;
        case 2:
            maximumOfGrades();
            return 1;
            break;
        case 3:
            minimumOfGrades();
            return 1;
            break;
        case 4:
            averageOfGrades();
            return 1;
            break;
        case 5:
            diagramOfGrades();
            return 1;
            break;
        default:
            return 2;
            break;
    }
}

void CGradeBook::watchAllGrades(){                                      //�������� ��� ������ �� ������� ������
    cout << "\n\n\t\tGrades of all students is:\n" << endl;
    for (int counter = 0 ; counter < numberOfStudents/2 ; counter++){
        cout << "\tGrade of student #" << counter+1 << ": " << gradesOfStudents[counter] << "  ***  ";
        cout << "Grade of student #" << counter+1+numberOfStudents/2 << ": " << gradesOfStudents[counter+numberOfStudents/2] << endl;
    }
}

void CGradeBook::maximumOfGrades(){                                     //����� ������������ ������ � ������� � �������� �
    int highestGrade = 0;
    for (int counter = 0 ; counter < numberOfStudents ; counter++ ){
        if (highestGrade < gradesOfStudents[counter]){
            highestGrade = gradesOfStudents[counter];
        }
    }
    cout << "\n\n\tMax grade of all student's grades is: " << highestGrade << endl;
}

void CGradeBook::minimumOfGrades(){                                     //����� ����������� ������ � ������� � �������� �
    int lowestGrade = 100;
    for (int counter = 0 ; counter < numberOfStudents ; counter++ ){
        if (lowestGrade > gradesOfStudents[counter]){
            lowestGrade = gradesOfStudents[counter];
        }
    }
    cout << "\n\n\tMin grade of all student's grades is: " << lowestGrade << endl;
}

void CGradeBook::averageOfGrades(){                                     //����� ������� �������� ������ � �������� ���
    int total = 0;
    for (int counter = 0 ; counter < numberOfStudents ; counter++ ){
        total += gradesOfStudents[counter];
    }
    cout << "\n\n\tAverage grade of all student's grades is: " << static_cast<double>(total) / numberOfStudents << endl;
}

void CGradeBook::diagramOfGrades(){                                     //�������� ��������� ������������� �������
    const int frequencySize = 11;
    int frequency[frequencySize] = {0};

    for (int counter = 0 ; counter < numberOfStudents ; counter ++){
        frequency[ gradesOfStudents[counter]/10 ]++;
    }

    cout << "\n\t\tDiagram of grades:\n" << endl;
    for (int counter2 = 0 ; counter2 < frequencySize ; counter2 ++){
        if (counter2 == 0){
            cout << " 0-9  :";
        }
        else if (counter2 == 10){
            cout << "  100 :";
        }
        else{
            cout << counter2*10 << "-" << counter2*10+9 << " :";
        }

        for (int stars = 0 ; stars < frequency[counter2] ; stars++){
            cout << "*";
        }
        cout << endl;
    }
}
