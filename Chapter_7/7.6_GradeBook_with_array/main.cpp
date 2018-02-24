//Тестирование объекта класса GradeBook.
//В объект будет передан массив оценок.
//Объект класса должен его получить и обработать его по требованию пользователя.

#include <iostream>
#include <string>
using namespace std;

#include "CGradeBook.hpp"
#include <windows.h>

int main(){
    string nameOfCourseByUser;                                      //Ячейка для введенного названия группы
    int gradesByUser[CGradeBook::numberOfStudents];                 //Массив для введеных оценок
    int choice = 1;                                                 //ВЫбор на повтор списка дейсвий (1 - да, 2 - нет)

    cout << "\n\n\t\tWelcome to program with arrays" << endl;       //Приветсвие
    cout << "\n\n\tPlease, Enter name of course: " ;                //Запрос на ввод имени курса
    cin  >> nameOfCourseByUser;                                     //считывание имени курса

    for (int counter = 0; counter < CGradeBook::numberOfStudents ; counter++ ){     //цикл на ввод оценнок от 0 до 100
        system("cls");

        if (counter == 0){                                                          // показать при первом запуске цикла
             cout << "\n\n\tEnter " << CGradeBook::numberOfStudents << " marks for your students: " << endl;
        }

        cout << "\n\n\t\tEnter mark for student #" << counter + 1 << ": ";          //ВВести оценку N-того студента
        cin  >> gradesByUser[counter];                                              //Считать оценку

        while ((gradesByUser[counter] > 100)||(gradesByUser[counter] < 0)){         //Если она не попала в промежуток
                                                                                    //от 0 до 100, тогда зайти в While
                                                                                    //и не выходить пока оценка не
                                                                                    //попадет в нужный промежуток
            system("cls");
            cout << "\n\n\tYou have written wrong grade for student #" << counter + 1 << " !!!" << endl;
            cout << "\n\n\t\tGrade must be in range from 0 to 100 " << endl;
            cout << "\n\n\tEnter another mark for student #" << counter + 1 << ": ";
            cin  >> gradesByUser[counter];
        }
     }

    CGradeBook myCGradeBook(nameOfCourseByUser , gradesByUser);     //создать обьект класса CGradeBook
    while (choice == 1){                  //Цикл на повторение
        system("cls");
        myCGradeBook.displayMessage();                              //Показать приветсвие
        choice = myCGradeBook.actWithGrades();                      //Показать действия над оценками

        if (choice == 1){                                            //запрос на повтор программы
            cout << "\n\n\t\tDo you want to do something else?" << endl;
            cout << "\n\t\t\t\t1 - yes" << endl;
            cout << "\t\t\t\t2 - no" << endl;
            cout << "\n\t\t\tYour choice is: ";
            cin  >> choice;
        }
    }

    system("cls");
    cout << "\n\n\n\t\tProgram was created by Lebedev Artem" << endl;   //Вывод конечного сообщения
    cout << "\n\n\t\t\tSpecial for himself\n\n" << endl;
    system("pause");
}
