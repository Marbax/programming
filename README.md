Первый проект [MVP](https://github.com/Marbax/-9-1_32_Morozov_M_E_exam_practice "https://github.com/Marbax/-9-1_32_Morozov_M_E_exam_practice")  

---

[MyVector class](HW_itstep/overload_operators/Vector.cpp "HW_itstep/overload_operators/Vector.cpp")  
[MyString class](HW_itstep/overload_operators/string_+_-_.cpp "HW_itstep/overload_operators/string_+_-_.cpp")  
[MyFraction class](HW_itstep/overload_operators/fraction.cpp "HW_itstep/overload_operators/fraction.cpp")  

---

<details><summary> My cheatsheet </summary><p>

[Markdown Cheatsheet](https://github.com/sandino/Markdown-Cheatsheet "https://github.com/sandino/Markdown-Cheatsheet")  
[Offical GitHub markdown guide](https://guides.github.com/features/mastering-markdown/ "https://guides.github.com/features/mastering-markdown/")  
[Сайт](http://draw.io "http://draw.io") для рисования UML диаграм  
[Сайт](https://creately.com/blog/diagrams/uml-diagram-types-examples/ "https://creately.com/blog/diagrams/uml-diagram-types-examples/") с примерами UML диаграм и возможностью их делать **(нет нормального экспорта)**  
[Сайт](https://metanit.com/sharp/patterns/ "https://metanit.com/sharp/patterns/") паттерны , примеры на шарпе   
[Сайт](https://refactoring.guru/ru/design-patterns "https://refactoring.guru/ru/design-patterns ") паттерны , примеры на псевдо коде и разных языках (кроме плюсов)    
[Сайт](http://cpp-reference.ru/patterns/ "http://cpp-reference.ru/patterns/ ") паттерны , примеры на плюсах  
[std::exception](https://docs.microsoft.com/en-us/cpp/standard-library/exception?view=vs-2019 "https://docs.microsoft.com/en-us/cpp/standard-library/exception?view=vs-2019") - описание исключений

</p></details>

---

.  
.  
.  

<details><summary>  7. Указатели </summary><p>

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
    
<details><summary> Например</summary><p>

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
<details><summary> Например добавления эллемента в C</summary><p>

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
<details><summary> Например добавления эллемента в C++</summary><p>

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

<details><summary>  8. Динамические многомерные массивы </summary><p>
Динамические многомерные массивы создются иначе.
- Указатель на указзатель **arr

<details><summary> Двумерный</summary><p>
<details><summary> Создание</summary><p>
```
    int **arr = new int *[row];   //создание массива массивов
    for (int i = 0; i < row; i++) //создание двумерных подмассивов
    {
        arr[i] = new int[col];
    }
```
</p></details>

<details><summary> Удаление</summary><p>

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

<details><summary> прототипы, стандартные ф-и для работы со строкоми string.h</summary><p>
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


<details><summary> 9. Указатели на ф-и. Создание типов данных. Структуры. </summary><p>

### Указатели на ф-и
- Два основных вида ф-й : ф-и первого порядка и высшего порядка, ф-и первого порядка можно передавать в другие ф-и в кач-ве аргемента , а ф-и высшего порядка могут принимать в кач-ве аргумента другие ф-и.

### Создание типов данных(структура)
- Структура - конструкция ,позволяющая создать свой собственный тип. Группировка для упрощения понимания и уменьшения  кода

- ```sizeof(a);``` показывает сколько памяти выделено для выражения в скобках

</p></details>


<details><summary> 10. Препроцессор. </summary><p>

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

`Array(const Array &obj) = delete;` - delete запрещает вызывать ,то есть , никто никогда не сможет вызывать конструктор копирования и перегруженый оператор копирования (=) **(перегруженый оператор присвоения(перемещения) "=" для rvalue будет работать)**

`int operator[](int pos) const { return arr[pos]; }`  - перегрузка по константности индексирования **(возвращает копию)**

`int &operator[](int pos) { return arr[pos]; }`  - перегрузка по константности индексирования **(возвращает ссылку на обьект)**

---
>***Вектор*** - динамический массив
---
>## UML диаграммы
>
>- Use case diagram - показывает что пользователь может делать с программой (искать ,что то ,покупать ,логиниться ) , либо модертор (что то добавлять ,что то изменять ,логиниться) , либо кто угодно еще , можно использовать наследование .
>
>- class diagram - отображает набор классов ,которые должны быть и как они взаимодействуют с собой ,обязательно имя класса, могут быть методы и поля . **is a** - класс является подвидом другого класса (наследование(в uml линия с пустой стрелки от наследника) )(напр. человек , а студент является подвидом человека student is a person) , **has a** - класс является составной частью (group has a student)
>
>- statechart diagram - показывает все возможные состаяния системы и переходы между ними
>
>- activity diagram - как блоксхема 
>
>- sequence diagram - показывает кто от кого зависит и что за чем должно выполоняться
>
>- coloboration diagram - похоже на диаграму состояний **(statechart)** , но показывает кто с кем может взаимодействовать
>
>- component diagram - показывает физических компонентов и как они взаимодействуют **( екзешники и тд)**
>
>- deployment diagram - топология взаимодействия , сервисы и тд **(наверное)**

---
>## Два вида включения (в уроках неправильно написано) :
> - Агрегация - подразумевает что включаемый обьект может существовать отдельно (в uml >линия с пустым ромбом , идет от включаемого)
> - Композиция - обьект не может существовать отдельно (отдел(продаж) это часть компании , >сам существовать не может) (в uml линия с зарисованым ромбом , идет от включаемого)

>### В C++ ***нет разделения на классы и интерфейсы***.
>
>Интерфейс в uml рисуется пунктирной линией с пустой стрелкой (интерфейс принято называть в некоторых языках начиная с i (iInterface))
>
>Асоциация в uml просто линия , значит что обьекты как то связаны(КАК принято писать над стрелкой)
---

</p></details>


<details><summary> 14. Работа со стэком. Разделение класса на файлы. Очередь  </summary><p>

### Принципы стэка
- ***push*** - добавление эллемента в конец  
- ***pop*** - удаляет эллемента из конца  
- ***top || peek*** - конец(вершина) стэка  
- ***is_empty*** - проверка или пусто  
- ***is_full***  - проверка или заполнено  

Добавление класса в visual studio `Project->Add class`


### Принципы очереди
- ***push*** - добавление эллемента в начало(либо пока приоритет ниже)(чаще)  
- ***pop*** - удаляет эллемента из конца(либо пока приоритет больше)(реже)  
- ***top*** || ***peek*** - начало очереди  
- ***is_empty*** - проверка или пусто  
- ***is_full***  - проверка или заполнено  


</p></details>


<details><summary> 15. Шаблонный класы. Списки </summary><p>

Шаблоные типы не хранятся в памяти , при компиляции формируется свой собсвенный класс для каждого типа.
Шаблонные класы описываются только в одном файле.


</p></details>


<details><summary> 16. Бинарное дерево </summary><p>

Граф - набор точек (узлы графа) и набор линий (ребра)  
Скорее всего понадобится Теория графов  
Задача комивояжора - используется для построения маршрута ,так чтобы поситить каждую точку с минимальными затратами  
Деревья ,это графы , у которых путь между двумя точками только один
Бинарные деревья имеют не более двух потомков  
Бинарное дерево поиска , слева значение меньше ,справа - больше   
Бинарное дерево - динамическая структура хранения данных   
Деревья всегда упорядочнены
В основном все эллементы уникальны 
Сложность поиска O(log n)
Узел состоит из четырез частей , данные ,указатель на родителя , указатели на потомков
Есть два варианта обхода дерева   
- Обход в глубину  - с конца в начало(3 реализации)
- Обход в ширину - начинается с корня,смотрится какие узлы есть и заходится в каждый (рекурсивная ф-я)

<details><summary> Пример вывода бинарного дерева </summary><p>

```C++
template <class T>
void Tree<T>::print(Node<T> *node) // выводит в отсортированом виде (инфиксная форма ,от меншего к большему)
{
    if (node == nullptr)
    {
        return;
    }
    print(node->getLeft());
    std::cout << node->getData() << " ";
    print(node->getRight());
}
```
Вызывает рекурсивно до левого крайнего эллемента ,с конца выводит их ,после каждого проверяет правый и вывлдит , таким образом выводит эллементы от меньшего к большему.

</p></details>

Удаление узла - может быть три ситуации , которые нужно обрабатывать 
- Если потомков нет - проще всего
- Если один потомок - следующий направляем в свой родитель и наоборот , как в двусвязном списке
- Если два потомка - узлы не удаляются никогда и никак (нужно найти следующий правый потомок и рекурсивно скопировать его данные по левому ребенку)



ДЗ доделать дерево
 - поиск
 - деструктор
 - перемещение
 - кол-во эллементов (ф-я перебирает эллементы и считает кол-во узлов)
 - операторы = , стандартные
 - деструктор (в цикле удалять корень ,пока корень не будет нулптр)


## Паттерны
Нужны чтобы дальше программу было комфортно поодерживать
3 вида паттернов 
 - Порождающие (все с наследованием) - описывают как создавать обьекты , стандартные  
    - Singleton - антипатерн 
    - Builder - позволяет создавать сложные обьекты (например составная часть других обьектов)
    - Prototype - создает обьекты на основе существующих (через метод копирования на каком то классе ,вместо `new`)
    - Factory Method - переносит логику создания в сам ПОРОЖДАЮЩИЙ обьект (для большого количсетва каких то обьектов)
    - Abstract Factory - позволяет комбинировать несколько иерархий наследования
 - Поведеньчиские
 - Структурные

Литература\сайты:
 - [Сайт](https://metanit.com/sharp/patterns/ "Link to site") паттерны , примеры на шарпе  
 - [Сайт](https://refactoring.guru/ru/design-patterns "Link to site") паттерны , примеры на псевдо коде и разных языках (кроме плюсов)
 - [Сайт](http://cpp-reference.ru/patterns/ "Link to site") паттерны , примеры на плюсах  
 - Книга - Дизайн ,паттерни ,просто як двеpi 

</p></details>

<details><summary> 17. String. Наследование . Вложеные классы.  </summary><p>

- агрегация - полый ромб 
- композиция - зарисованый ромб

[string](https://ru.cppreference.com/w/cpp/string/basic_string)  

- cstr - стринговая ф-я , переводит в чаровский массив
- capacity - выделенная память
- clear - удаляет все эллементы и сайз = 0 , память не чистит
- compare - сравнивает как strcmp , посимвольно
- data - возвращает чаровский массив(как cstr) НО без нуль символа в конца
- empty - проверка или пустая строка ,булева
- erase - удаляет эллемент или диапазон
- find - как strstr 



## Наследование
Наследование - механизм ООП , позволяющий описать новый клас ,на основе уже существующего .При наследовании свойства и ф-сть наследуются потомком . Класс наследник имеет доступ к публичным и защищенным полям и методам базового класса . Класс наследник может добавлять свои данные и методы ,а так же переопределять существующие .

- ***Родительский класс*** - (базовый класс,суперкласс)(в С# basic class , Java - super class) класс выступающий в качестве основы , при наследовании .
- ***Класс наследник*** - (потомок,клаас потомок, дочерний класс, производный класс) класс ,который образован в результате наследования .
- ***Интерефейс*** - все публичные методы класса.

### Варианты наследования 

- По кол-ву базовых классов :
    - одиночное 
        - открытое ( в основном используется)
        - закрытое
        - защищенное
    - множественное (>1)(следует избегать )
        - открытое ( в основном используется)
        - закрытое
        - защищенное

- ***Открытое наследование*** - наследование интерфейса . Все открытые и защищенные члены базового класса остается открытыми и защищенными членами потомка.
- ***Закрытое наследование*** - наследование реализации . Все публичные и защищенные поля и методы базового класса становятся закрытыми полями и методами класса потомка . Производный класс на прямую не поддерживает интерфейс базового , но использует его реализацию ,предоставляя свой собственный открытый интерфейс . ***(почти не используется , лучше заменять наследованием включения ( агрегации или композиции))***
- ***Защищенное наследование*** - наследование реализации доступное для дальнейшего наследования . Все публичные и защищенные поля и методы базового класса становятся защищенными полями и методами класса потомка . 


</p></details>

<details><summary> 18. Связывание. Абстрактный класс. Патерны порождающие/структурные  </summary><p>

## Связывание 2 способа
 - Раннее связывание - на этапе компиляции
 - Позднее связывание(динамический полиморфизм) - когда на этапе компиляции не известно какая ф-я нужна. `virtual` - вместо одного адреса в памяти формируется таблица виртуальных ф-й ( массив адресов ф-й)
`override`- можно писать только для виртуальных ф-й , не дает написать не те параметры(доп проверка)
`final` - запрещает потомкам переопределять виртульный метод (но работает странно , т.к. не хочет использовать родительский метод)

если есть виртуальный метод то нужно обязательно сделать деструктор тоже виртуальным
в Java все ф-и по умолчанию виртуальные , в C++/C# ф-и по умолчанию не виртуальные 

Статический полиморфизм - перегрузка операторов 

Имя ф-и = адрес в памяти 


## Абстрактный класс
 - Класс ,ебьект которого нельзя создать.Для того чтобы класс стал виртуальным - внутри него нужно описать хотябы одну чисто виртуальную ф-ю. 
    - Чисто виртуальная ф-я - описывается как прототип виртульной ф-и приравненый к нулю. У чистой виртуальнрой ф-и не существует реализации ,но каждый класс ,который наследуется от абстрактного класса ОБЯЗАН реализовать все его чисто виртуальные ф-и.
    - Чисто виртуальный деструктор ОБЯЗАН иметь реализацию.


</p></details>

<details><summary> 19. Множественное наследование. Преобразование. Обработка исключения   </summary><p>


Преобразование ,4 типа :
- **const_cast** - позволяет снять или ***добавить***(создать новый) модификатор const ,***volatile***(запрещает компилятору оптимизировать значения , в основном для системного программирования)  
<details><summary> Пример const_cast</summary><p>

```C++
int a = 5;
const int * cpa = &a;
cout<<*cpa<<endl;
//*cpa=10; // не сработает
int * pa = const_cast<int*>(cpa);
```
</p></details>

- **static_cast** - примерно одинаково с `(int)a`
- **dynamic_cast** - проверяет какой именно обьект под указателем (работает только для полиморфных классов ( у него нет виртуальных ф-й) не даст скомпилировать ф-ю)
- **reinterpret_cast** - преобразовует все что угодно к чему годно (есть некоторые ограничения )

## 2 Варианта обработка ошибок 
- `if else` - сложно читать код , ретерн не пашет , нужно много дописывать и тд
- `try catch throw` - с 90х-10х была популярна , минусы : в плюсах не обязательна ,в новых языках обязательна (Джава)
    - `try` - описывает блок в котором может произойти исключение 
    - `catch` - описывает что ловить 
    - `throw` - выкидывает кетч


</p></details>


<details><summary> 20. Доп аргументы программы. Namespace. Указатели   </summary><p>

<details><summary> Пример работы с доп аргументами </summary><p>

```C++
int main(int argc, char *argv[]) 
```
- agrc - кол-водоп аргументов ,передаваемых при запуске исполняемого файла 
- argv - массив строк(самих аргументов)

Использование :
```bash
g++ main.cpp && ./a.out arg arg1 ... argN
```

</p></details>

[std::exception](https://docs.microsoft.com/en-us/cpp/standard-library/exception?view=vs-2019 "https://docs.microsoft.com/en-us/cpp/standard-library/exception?view=vs-2019") - описание исключений

### Указатели 

4 стандартных типа (все шаблонные ) библиотека memory
- ***auto_ptr*** - самый старый (устаревший )б после 14го стандарта удалили ,небыло конструктора перемещения нормального , нет перегруженого `[]`
- ***uniq_ptr*** - тот же `auto_ptr` но с конструктором перемещения ,конструктор копирования запрешен, нет перегруженого `[]` , но можно так `unique_ptr<int[]> arr(new int[5]);`
- ***shared_ptr*** (библиотека boost (большая))  - самый приятный и самый тяжелый , считает кол-во активных указателей , если больше одного то в деструкторе просто уменьшается счетчик , у указателя есть методы , очень тяжеловесные указатели ,нельзя сделать массив ,в отличии от `uniq_ptr`.
- ***weak_ptr*** (библиотека boost (большая))  - хранят тоже что и `shared_ptr` , используется если нужно указывать друг на друга (потомки используют `weak_ptr`), создается на основе существуего `shared_ptr` (`weak_ptr` не учитывается в кол-ве указателей  `shared_ptr`) , для всех операций нужно локать `wp.lock()`
>Облегчают очистку памяти ,но занимают больше системных ресурсов

[Примеры]("")
</p></details>





---

<details><summary> Экзамен №2 </summary><p>

## Экзамен
- Сделать ООП приложение , класыы ,инкапсуляция , перегрузки операторов, динамические структуры данных( не все ) , наследование и полиморфизм(2-3 класса), виртуальные ф-и .
- Либо переделать библиотеку из базового семестра (нет).


sfml -  сскидывать его библиотеки вместе с проектом  
сроки - до конца курса , в начале октября/конце сентября 



</p></details>

---
