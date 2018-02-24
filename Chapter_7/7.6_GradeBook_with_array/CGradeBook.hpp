//��������� ������ �GradeBook

class CGradeBook{
public:
    const static int numberOfStudents = 10;         //�������� ����� ��������� ��� �������
    CGradeBook(string name, int grades[]);          //����������� �������� ����� � ������ ��� ���������
    ~CGradeBook();

    void displayMessage();                          //������� ����������� �� �����

    int actWithGrades();                           //�������� ��� ����������� ��������

private:
    string nameOfCourse;                            //������ ��� �������� ����� �����
    int gradesOfStudents[numberOfStudents];         //������ ������

    void setCourseName(string name);                //��������� �������� �����
    string getCourseName();                         //�������� �������� �����

    void watchAllGrades();                          //�������� ��� ������
    void maximumOfGrades();                         //����� ������������ ������
    void minimumOfGrades();                         //����� ����������� ������
    void averageOfGrades();                         //����� ������� �������� ������
    void diagramOfGrades();                         //�������� ��������� ������������� ������
};
