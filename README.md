...
...
...
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

</p></details>

