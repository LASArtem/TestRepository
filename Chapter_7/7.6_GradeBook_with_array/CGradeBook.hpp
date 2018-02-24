//Интерфейс класса СGradeBook

class CGradeBook{
public:
    const static int numberOfStudents = 10;         //Указание числа студентов для журнала
    CGradeBook(string name, int grades[]);          //Потребовать название курса и оценки для студентов
    ~CGradeBook();

    void displayMessage();                          //Вывести приветствие на экран

    int actWithGrades();                           //Действия над полученными оценками

private:
    string nameOfCourse;                            //ячейка для хранения имени курса
    int gradesOfStudents[numberOfStudents];         //Массив оценок

    void setCourseName(string name);                //Сохранить название курса
    string getCourseName();                         //Получить название курса

    void watchAllGrades();                          //Показать все оценки
    void maximumOfGrades();                         //Найти максимальную оценку
    void minimumOfGrades();                         //Найти минимальную оценку
    void averageOfGrades();                         //Найти среднее значение оценок
    void diagramOfGrades();                         //Показать диаграмму распределения оценок
};
