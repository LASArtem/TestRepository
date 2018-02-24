//Программа реализует линейный поиск по массиву
//Я решил, создавать массив со случайными цифрами от 0 до 39
//число элемнтов массива: 40

#include <iostream>
using namespace std;
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>

void linearSearch(int a[], int arraySize, int key);             //Прототип функции - поиска ключа по массиву чисел

int main(){
    const int arraySize = 40;                                   //Объявление размера массива
    int QQ[arraySize];                                          //Создание массива
    int keyForSearch;                                           //Создание ячейки под ключ поиска

    while ((keyForSearch >= arraySize)||(keyForSearch < 0)){    //Ввод ключа в диапазоне от 0 до 39
        system("cls");
        cout << "\n\n\n\tPlease, enter number for search in array \n\n\t\tfrom 0 to "<< arraySize << ": ";
        cin  >> keyForSearch;
    }

    system("cls");
    cout << "\n\n\tYou enter number: " << keyForSearch << endl; //Показать ключ поиска
    cout << "\n\tRandom array is: \n" << endl;
    srand(time(0));
    for (int i = 0 ; i < arraySize ; i++){                      //Заполнение и выведения массива чисел
        QQ[i] = rand()%arraySize;
        cout << "array[" << setw(2) << i << "] = " << setw(2) << QQ[i];
        if ((i%4) == 3){
            cout << endl;
        }
        else{
            cout << "     ";
        }
    }
    linearSearch(QQ, arraySize, keyForSearch);                  //Запуск функции поиска

    cout << "\n\n";
    system("pause");                                            //Окончание программы
}

void linearSearch(int a[], int arraySize, int key){             //Определение функции - поиска
    int flag = 0;                                               //число найденых совпадений
    cout << "\n\n\tWe will search your number at random array:\n\n";
    for (int i = 0 ; i < arraySize ; i++){                      //поиск и выведение ячеек массива по совпадению с ключом поиска
        if (a[i] == key){
            cout << "Program finds your number at " << i << "-element of our random array" << endl;
            flag++;
        }
    }

    if (flag == 0){                                             //Если совпадений не было то об этом сообщат
        cout << "Your number did not find at random array";
    }
}
