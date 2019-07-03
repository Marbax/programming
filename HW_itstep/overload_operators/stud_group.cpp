#include <iostream>
#include <string.h>
using namespace std;

/* Не нужно использовать битовые поля. Не хватает проверок.
Функции добавления и удаления должны принимать необходимые параметры, а не считывать из с клавиатуры  
*/


/* 
Домашнее задание: Конструкторы. Деструкторы. Конструктор копирования.
Написать класс, описывающий группу студентов. Описание студента
также реализуется с помощью соответствующего класса.

Студент:
    Поля:
        Имя;
        Год рождения.

Группа:
    Поля:
        Факультет;
        Курс;
        Количество студентов;
        Студенты.
    Методы:
        Добавление студента в группу;
        Удаление студента из группы(по позиции);
        Вывод на экран всех студентов.
 */

class Group;

class Student
{
private:
    char *student_name = nullptr;
    size_t bday_year : 11;
    friend Group; // НУЖНО БЫЛО ЧЕРЕЗ СЕТТЕРЫ И ГЕТТЕРЫ , ДАННЫЙ СПОСОБ НАРУШАЕТ ИНКАПСУЛЯЦИЮ

public:
    Student(char *student_name, size_t bday_year) : bday_year(bday_year)
    {
        this->student_name = strdup(student_name);
    }
    Student() : bday_year(0)
    {
        student_name = strdup("new");
    }
    Student(const Student &obj) // конструктор копирования
    {
        student_name = strdup(obj.student_name);
        bday_year = obj.bday_year;
    }
    ~Student()
    {
        delete[] student_name;
    }
    Student &operator=(const Student &obj) // перегрузка присваивания(копирования lvalue)
    {
        if (this == &obj) // сравнение двух АДРЕСОВ в памяти, т.к. обекты могут быть одинаковы а адрес - нет
        {
            return *this;
        }

        delete[] student_name; // удалаяем память левого обьекта
        bday_year = obj.bday_year;
        student_name = strdup(obj.student_name);
        return *this;
    }
};

class Group
{
private:
    char *faculty = nullptr;
    size_t course : 3;
    size_t students_count = 0; // если не инициализировать нулем по дэфолту то там мусор ,из за этого вылетала программа std::bad_alloc
    Student *students = nullptr;

public:
    Group(const char *faculty, size_t course) : course(course)
    {
        this->faculty = strdup(faculty);
    }
    Group(const char *faculty) : course(1)
    {
        this->faculty = strdup(faculty);
    }
    ~Group()
    {
        delete[] faculty;
        if (students_count > 0) // ТАК, КАК ЕСТЬ УДАЛЕНИЕ СТУДЕНТОВ ,МОЖЕТ БЫТЬ ПУСТОЙ МАССИВ
        {
            delete[] students;
        }
    }

    void Add_student_to_group() // ДОЛЖНЫ БЫЛИ ПРИНИМАТЬ ПАРАМЕТРЫ ,А НЕ ПРЕДЛАГАТЬ ВВОД
    {
        size_t bday_year;
        char buf[100];
        cout << "\nEnter student name => ";
        cin.getline(buf, 100);
        cout << "\nEnter student's birthday year => ";
        cin >> bday_year;
        cin.ignore();
        cout << endl;

        Student new_student(buf, bday_year);
        if (students_count == 0)
        {
            students = new Student[1];
        }
        else
        {
            Student *tmp = new Student[students_count + 1];
            for (int i = 0; i < students_count; i++)
            {
                tmp[i] = students[i];
            }
            delete[] students;
            students = tmp;
        }
        students[students_count] = new_student;
        students_count++;
    }
    void Remove_student_from_group() // ДОЛЖНЫ БЫЛИ ПРИНИМАТЬ ПАРАМЕТРЫ ,А НЕ ПРЕДЛААТЬ ВВОД
    {

        if (students_count > 0)
        {
            int pos;
            cout << "Enter student position => " << endl;
            cin >> pos;
            cin.ignore();

            if (pos < 0 || pos >= students_count) // эксепшн , если позиция за пределами ,защита от вылетов
            {
                return;
            }
            Student *tmp = new Student[--students_count];
            for (int i = 0, j = 0; i < students_count; j++, i++) //пересоздает массив исключая ненужный обьект
            {
                if (i == pos)
                {
                    j++;
                }
                tmp[i] = students[j];
            }
            delete[] students;
            students = tmp;
        }
    }
    void Show_all_students_in_group()
    {
        cout << "Faculty : " << faculty << endl;
        cout << "Course : " << course << endl;
        if (students_count > 0)
        {
            for (size_t i = 0; i < students_count; i++)
            {
                cout << "\n========================_" << i << "_======================" << endl;
                cout << "Name : " << students[i].student_name << endl;
                cout << "Birthday year : " << students[i].bday_year << endl;
                cout << "===================================================" << endl;
            }
        }
        else
        {
            cout << "\n\t\t\tThere no students!" << endl;
        }
    }
};

int main()
{
    Group first("Software development", 2);
    first.Show_all_students_in_group();
    first.Add_student_to_group();
    first.Show_all_students_in_group();
    first.Add_student_to_group();
    first.Show_all_students_in_group();
    first.Remove_student_from_group();
    first.Show_all_students_in_group();
    cout << "\n!!!END_OF_PROGRAM!!!\n";
}
