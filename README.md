Первый проект [MVP](https://github.com/Marbax/-9-1_32_Morozov_M_E_exam_practice "Link to another my repo")

---

[MyVector class](HW_itstep/overload_operators/Vector.cpp "Link to current repo file")\
[MyString class](HW_itstep/overload_operators/string_+_-_.cpp "Link to current repo file")\
[MyFraction class](HW_itstep/overload_operators/fraction.cpp "Link to current repo file")

---

<details><summary> My cheatsheet </summary><p>

[Markdown-Cheatsheet](https://github.com/sandino/Markdown-Cheatsheet "Link to another repo")\
[Offical GitHub markdown guide](https://guides.github.com/features/mastering-markdown/ "Link to GitHub site")

</p></details>

---

.\
.\
.

<details><summary>Урок 7. Указатели</summary><p>

- Указатель это переменная ,которая может хранить в себе адрес другой переменной 
- " & " для получения адреса в памяти
- " * " разименование , позволяет получить содержимое переменной через указатель на нее

- ```int *pa = &a;```  указатель
- ```int **ppt = &pt;``` указатель на указатель
- ```pt = nullptr;``` указатель в никуда / обнуление
- ```int &ra = a;``` ссылка
- ```int *&pra = pa;``` ссылка на указатель


- Массивы неразрывно связаны со своей памятью ,их нельзя переуказывать


- Приложению изначально выделяется минимально 1МБ - stack 
- Вся остальная память(которая дальше ,после stack) - "куча" или "Heap"
    - Принцип работы памяти LIFO - первый пришедший уходит последним 
- Оператор ```new``` ищет запрошеный обьем непрерывный области памяти в  "куче"
- Для удаления есть оператор ```delete ``` , например ```delete pt;``` и ```delete[]arr;```
- Единственный способ вызвать определенные данные из "кучи" по указателю в памяти , хорошо создавать массивы в куче 
- Массивы созданные в куче - наываются Динамическими
- Запрошеная в куче память сама никогда не удалаяется(C++ нет сборщика мусора) и в плане операционной системы она занята (если она не удаляется - это утечка памяти). В C++ память из кучи сама не удаляется ,нужно в ручную , если удалять то ,чего нет - будет всегда ошибка .
- Как только программа закрывается - система чистит память сама 

- Чтобы добавить в массив новый еллемент нужно сделать 4 действия 
    - Создаем новый массив нового размера 
    - Скопировать данные из старого массива в новый
    - Удаляем старый массив
    - Перенаправляем старый массив в новую память
    
<details><summary>Например</summary><p>

```
    int *tmp = new int[size + 1];  // 1
    for (int i = 0; i < size; i++) // 2
    {
        tmp[i] = arr[i];
    }
    delete[] arr; // 3

    arr = tmp; // 4
```
</p></details>

- В языке C есть только указатели 
<details><summary>Например добавления эллемента в C</summary><p>

```

void Add_to_array_like_C(int **arr, int *size, int value) // Способ из C
{
    int *tmp = new int[*size + 1];  // 1
    for (int i = 0; i < *size; i++) // 2
    {
        tmp[i] = *(*arr + i);
    }
    delete[] * arr; // 3

    *arr = tmp; // 4
    // *(*arr+*size) = value;
    tmp[*size] = value;
    // (*size)++;
    *size = *size + 1;
}

```

</p></details>

- В C++ есть ссылки ,с ними проще и приятнее работать ,нежели с указателями 
<details><summary>Например добавления эллемента в C++</summary><p>

```

void Add_to_array(int *&arr, int &size, int value)
{
    int *tmp = new int[size + 1];  // 1
    for (int i = 0; i < size; i++) // 2
    {
        tmp[i] = arr[i];
    }
    delete[] arr; // 3

    arr = tmp; // 4
    arr[size] = value;
    size++;
}

```

</p></details>

- Чтоб узнать код символа

```
char key = getchar();
cout << int (key);
```

</p></details>

<details><summary>Урок 8.Динамические многомерные массивы </summary><p>
Динамические многомерные массивы создются иначе.
- Указатель на указзатель **arr

<details><summary>Двумерный</summary><p>
<details><summary>Создание</summary><p>
```
    int **arr = new int *[row];   //создание массива массивов
    for (int i = 0; i < row; i++) //создание двумерных подмассивов
    {
        arr[i] = new int[col];
    }
```
</p></details>

<details><summary>Удаление</summary><p>

```
    for (int i = 0; i < row; i++) // удаление двумерных подмассивов
    {
        delete[] arr[i];
    }
    delete[] arr; //удаление массива массивов
```
</p></details>
</p></details>

- Рваныые,зубчатые массивы , двумерные массивы с разной размерность строк ,благодаря созданию нового массива ,который хранит размеры строк.

- Чаровские массивы выводятся до спец символа (терминирующий символ \0)

<details><summary>прототипы, стандартные ф-и для работы со строкоми string.h</summary><p>
версия с n(напр nstrcpy) в начале названия принимает кол-во еще

```int strlen(char*)``` считает кол-во символов в строке ,без учета нуль симмвола
```char* strcpy(char*d,char*s)``` копирует символы строки, заменяет полностью с нулевого эллемента
```char* strcat(char*d,char*s)``` копирует символы строки , вставляет с конца (ищет нуль символ и с него начинает ,размер должен быть выделен заранее),нельзя юзать с пустыми массивами
размер нужно выделять самому для всех стандартных ф-й
```int strcmp(char*,char*)``` сравнивает по содержимому(возвращает 0 если одинаковые)(вычитает еллементы по индексу)
```char * strstr(char*str,char*substr)```  проверяет или есть подстрока(substr) в строке (str) и возвращает первое совпадени (адрес),если ничего не нашел вернет ноль
```char* strchr(char* str,char ch)``` проверяет или есть символ в строке 
```char* strpbrk(char* str,char* cbls)``` находит первое вхождение любого из символов второй строки
```char* strtok(char* str,char* sep)``` разбивает строку на части , второе значение набор символов , по которым разбивать
```int atoi(char*)``` asci to int переводит строку в инт, передавать только цифры ,заканчивается когда встречает буквы

только для вижуал студии
```int itoi(int,char*,int)``` число в символ переводит 

</p></details>

- 8u-replace если новая строка короче ,то ,при ресайзе (при копирование обрезает строку)
- 8u-2-replacing_array ,с помощью кнопки "ескейп" нельзя выйти и свитча (нужно юзать гетчар), так же ретерн в свитче все ломает 

- В строку возможно (но нельзя) записать больше значений ,чем выделено
</p></details>


<details><summary> Урок 9.Указатели на ф-и. Создание типов данных. Структуры. </summary><p>

### Указатели на ф-и
- Два основных вида ф-й : ф-и первого порядка и высшего порядка, ф-и первого порядка можно передавать в другие ф-и в кач-ве аргемента , а ф-и высшего порядка могут принимать в кач-ве аргумента другие ф-и.

### Создание типов данных(структура)
- Структура - конструкция ,позволяющая создать свой собственный тип. Группировка для упрощения понимания и уменьшения  кода

- ```sizeof(a);``` показывает сколько памяти выделено для выражения в скобках

</p></details>


<details><summary> Урок 10.Препроцессор. </summary><p>

```C++
#if/#ifdef/#ifndef <константное_выражение
                    или идентификатор>
          <текст_1>
#else// необязательная директива
          <текст_2>
#endif
```

- Оператор # превращает аргумент, которому он предшествует, в строку, заключенную в кавычки.

```C++
#include <iostream>
using namespace std;
# define mkstr(s) #s
void main()
{
    cout<<mkstr(I love C);
    // Для компилятора cout<<"I love C";
}
```

- Оператор ## используется для конкатенации (объе-динения) двух лексем

```C++
#include <iostream>
using namespace std;
# define concat(a,b) a##b
void main()
{
    int xy=10;
    cout<<concat(x,y);
    // Для компилятора cout<<xy;
}
```

```#include <имя_файла>``` поиск в системных дирректориях
```#include "имя_файла"``` относительный путь, потом поиск в системных дирректориях

### Работа с файлами 

 - 3 основных класса (библиотека fstream)
    - fstream   - общий класс, и для чтения и для записи 
    - ifstream  - для чтения 
    - ofstream  - для записи

<details><summary> Пример чтения из файла </summary><p>

```C++
void Load()
{
    string path = "Videostore_state.txt";
    ifstream file_in;
    file_in.open(path);
    if (!file_in.is_open())
    {
        cout << "Error , while try to open file!" << endl;
    }
    else
    {
        /* char ch;
        while(file_in.get(ch)) // посимвольное чтение из файла
        {
            cout << ch;
        } */

        //string str;
        char ch[500];
        while (file_in.eof())
        {
            //str = "";
            //getline(file_in,str); // считывает строку
            file_in.getline(ch, 500); // считывает массив чаров
        }
    }
    file_in.close();
}
```
</p></details>


</p></details>


<details><summary> 11 . Битовые операции. ООП </summary><p>

### Битовые операции
 - Для экономии памяти
 - Все битовые операции выполняются быстрее

 - Битовые операторы (6 шт)
   - ~a - (тильда) инверсия битов ,напр ```int a = 5; a = ~a;``` a = -6
(Нужно инвертировать и прибавить один бит , тогда число станет отрицательным)
   - a& mask - and
   - a! mask - or
   - a^ mask - xor ('exclusive or' ,если два одинаковых ,то дает всегда false)
(Битовая последовтельность значения - это маска)
 - a >> step - побитовый сдвиг(сдвиг в право на один (делит на два) (если первый бит слева 1 то придут единици , если первый бит слева 0 то придут нули)
 - a << step - (сдвиг в лево на один (умножает на два)(всегда приходят нули) )

### ООП
 - Самый простой подход - процедурное программирование
 - Потом ООП, все данные в виде отдельных обьектов и того как с ними работать (до 2010 был самым актуальным)
 - (в ~2005 уперлись в производительность процессоров)Функциональноп программирование начало набирать популярность, там данные неизменны (через временные переменные). Проблемы : последовательность операций , задачи выполняются когда могут

Принципи ООП:
 - Инкапсуляция - сокрытие доступа к данным извне(проверка перед вводом данных) (модификаторы : public , private , protected)
 - Наследование - создание данных на основе имеющихся
 - Полиморфизм - статический и динамический (в основном динамический), принцип при котором обьект может вести себя по разному в зависимости от ситуации (метод - это функция внутри класса)
(Классы реализуют все три принципа.)
 - Во все классы неявно передается параметр this-> ,по отношению к его переменым 

Методы ,которые не должны менять поля  - лучше помечать как константы

Классы памяти авто ,статик , екстерн , регистри

Классы являются основой С++, внутри класса описываются методы,которые работают с приватными полями класса, конструкторы инициализируют параметры при создании обьекта класса , деструкторы чистят память в конце

</p></details>

<details><summary> 12 . Конструктор перемещения  </summary><p>

<details><summary> l-value ссылки   </summary><p>

```
int a=5;
int & ref = a;
```

</p></details>

<details><summary> r-value ссылки   </summary><p>

### Могут ссылаться на временные обьекты , даже на литералы !

```
int &&r=5;
```

</p></details>

(Конструктор копирования (если тот не описан)заменяет конструктор перемещения ,но работает немного дольше )
```move``` ф-я вызывающая насыльный конструктор перемещения

<details><summary> Пример конструктор перемещения  </summary><p>

```
MyString(MyString &&obj) // r-value ссылка ,конструктор перемещения
    {
        capacity = obj.capacity;
        str = obj.str;
        obj.str = nullptr;
        obj.capacity = 0;
    }
```
</p></details>

По умолчанию большинство операторов работают со стандартными типами  ,для абстрактных типов операторы нужно перегружать ,чтобы не выходило недопонимания.

## Нельзя перегружать
- .
- ?:
- ::
- sizeof
- \#
- \##
- .* - pointer to member selection(указатель члена класса и тд. )
- Нельзя перегружать бинарные операторы КАК унарные и НАОБОРОТ
### ```*``` разыменование и умножение МОЖНО перегружать

### ```explicit``` запрещает неявный вызов метода

### Глобальные перегрузки и дружественные перегрузки 
 - Глобальная не имеет доступа к приватной части класса
 - Дружественные ф-и (нарушают инкапсуляцию ПЛОХО) имеют доступ к приватной части класса. Можно описовать в классе или оставлять ее прототип ,она все равно не будет частью класса (может быть даже дружественный класс).


</p></details>


<details><summary> 13. Переггрузка []. UML   </summary><p>

---
>**Если принимаемые параметры перегруженого оператора могут быть константными(не изменяются) ,то лучше перегружать как френдли ф-ю**
---
`int *arr = new int[size]{};` - если выделять память так , то она удалится при выходе из области выдимости

`Array(const Array &obj) = delete;` - delete запрещает вызывать ,то есть , никто никогда не сможет вызывать конструктор копирования и перегруженый оператор копирования (=) (перегруженый оператор присвоения(перемещения) "=" для rvalue будет работать)

`int operator[](int pos) const { return arr[pos]; }`  - перегрузка по константности индексирования (ВОЗВРАЩАЕТ КОПИЮ)

`int &operator[](int pos) { return arr[pos]; }`  - перегрузка по константности индексирования (ВОЗВРАЩАЕТ ССЛЫКУ НА ОБЬЕКТ)

---
>***Вектор*** - динамический массив
---
>## UML диаграммы
>
>- Use case diagram - показывает что пользователь может делать с программой (искать ,что >то ,покупать ,логиниться ) , либо модертор (что то добавлять ,что то изменять ,логиниться)> , либо кто угодно еще , можно использовать наследование .
>
>- class diagram - отображает набор классов ,которые должны быть и как они взаимодействуют >с собой ,обязательно имя класса, могут быть методы и поля . is a - класс является >подвидом другого класса (наследование(в uml линия с пустой стрелки от наследника) )(напр. >человек , а студент является подвидом человека student is a person) , has a - класс >является составной частью (group has a student)
>
>- statechart diagram - показывает все возможные состаяния системы и переходы между ними
>
>- activity diagram - как блоксхема 
>
>- sequence diagram - показывает кто от кого зависит и что за чем должно выполоняться
>
>- coloboration diagram - похоже на диаграму состояний(statechart) , но показывает кто с >кем может взаимодействовать
>
>- component diagram - показывает физических компонентов и как они взаимодействуют ( >ексешники и тд)
>
>- deployment diagram - топология взаимодействия , сервисы и тд (наверное)

### [Сайт](http://draw.io) для рисования UML диаграм
### [Сайт](https://creately.com/blog/diagrams/uml-diagram-types-examples/) с примерами UML и возможностью их делать
---
>## Два вида включения (в уроках неправильно написано) :
> - Агрегация - подразумевает что включаемый обьект может существовать отдельно (в uml >линия с пустым ромбом , идет от включаемого)
> - Композиция - обьект не может существовать отдельно (отдел(продаж) это часть компании , >сам существовать не может) (в uml линия с зарисованым ромбом , идет от включаемого)

>### В C++ ***нет разделения на классы и интерфейсы***.
>
>Интерфейс в uml рисуется пунктирной линией с пустой стрелкой (интерфейс принято называть >в некоторых языках начиная с i (iInterface))
>
>Асоциация в uml просто линия , значит что обьекты как то связаны(КАК принято писать над >стрелкой)
---

</p></details>


---
