//Сортировка случайного массива вставкой
//по сути сортировка массива по возрастанию
//метод является простым но для габаритных массивов является долгим

#include <iostream>
using namespace std;
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>

void sortingArray(int a[], int arraySize);              //прототип ыортирующей функции

int main(){
    const int arraySize = 10;                           //Инициализация размера массива
    int randArray[arraySize];                           //Создание массива

    cout << "\n\t\tRandom array is:" << endl;           //Сгенерировать случайный массив и показать его
    srand(time(0));
    for (int i = 0 ; i < arraySize/2 ; i++){
        randArray[i] = rand()%100;
        randArray[i+arraySize/2] = rand()%100;
        cout << "randArray[" << setw(2) << i << "] = " << setw(2) << randArray[i] << "   ";
        cout << "randArray[" << setw(2) << i+arraySize/2 << "] = " << setw(2) << randArray[i+arraySize/2] << endl;
    }

    sortingArray(randArray, arraySize);                 //Вызвать функцию. которая отсортирует случайный массив

    cout << "\n\n\t\tSorting array is:" << endl;        //Показать отсортированный массив
    for (int i = 0 ; i < arraySize/2 ; i++){
        cout << "randArray[" << setw(2) << i << "] = " << setw(2) << randArray[i] << "   ";
        cout << "randArray[" << setw(2) << i+arraySize/2 << "] = " << setw(2) << randArray[i+arraySize/2] << endl;
    }

    cout << "\n\n";                                     //Закончить пограмму
    system("pause");
}

void sortingArray(int a[], int arraySize){              //Описание сортирующей функции
    int insertFromArray;                                //Ячейка, которая хранит "вставку" из массива
    int step;                                           //Шаг сортировки или значение индексов предыдущих ячеек

    for (int i = 1 ; i < arraySize ; i++){              //Цикл сортировки
        insertFromArray = a[i];                         //сохранить текущую ячейку из массива
        step = i - 1;                                   //Указать предыдущий индекс из массива

        while( (step >= 0) && (a[step] > insertFromArray) ){    //Делать пока 1)Шаг будет положителен и 2)пока вставка меньше, чем "Шаговая" ячейка из массива
            a[step+1] = a[step];                        //Перезаписать на 1 ячейку в перед текущее значение шаговой ячейки
            step--;                                     //Уменьшить шаг на 1
        }
        a[step+1] = insertFromArray;                      //Вписать значение "Вставки" в шаговый индекс
    }
}
