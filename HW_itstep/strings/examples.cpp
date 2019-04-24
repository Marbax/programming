#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <cstring>
#include <cmath>

using namespace std;

// ф-и с подчеркиванием работают только в вижуал студии

int main()
{
	SetConsoleOutputCP(1251); // вывод кодировки
	SetConsoleCP(1251); // вывод кодировки
	const int BUFFSIZE = 256;
	char buff[BUFFSIZE];

	// Пример 1
	{
		int code = getchar(); //Возвращает значение символа(если он есть), который пользователь набрал на клавиатуре. После ввода символа нужно нажать клавишу Enter. Заголовочный файл - stdio.h
		cout << code << endl;
	}
	// Пример 2
	{
		int code = _getch(); //Аналогично предыдущему, только символ на экране не отображается. Используется чаще для организации задержки выполнения программы. Заголовочный файл - conio.h
		cout << code << endl;
	}
	// Пример 3
	{
		int code = 65;
		putchar(code); //Выводит символ c на экран. В случае успеха возвращает сам символ c, в противном случе - EOF. Заголовочный файл - stdio.h
		cout << endl;
	}
	// Пример 4
	{
		cin.ignore();
		gets_s(buff);
		cout << buff << endl; // Читает символы, включая пробелы и табуляции, до тех пор, пока не встретится символ новой строки, который заменяется нулевым символом. Последовательность прочитанных символов запоминается в области памяти, адресуемой аргументом s. В случае успеха возвращает аргумент s, в случае ошибки - нуль. Заголовочный файл - stdio.h
	}
	// Пример 5
	{
		gets_s(buff);
		puts(buff); // Выводит строку, заданную аргументом const char *s. Заголовочный файл - stdio.h
	}
	// Пример 6_1
	{
		gets_s(buff);
		char str[256] = "Привет ";
		strcpy(str, buff); //Копирует строку buff в строку str, заменяя первую последней. Возвращает str.
		cout << buff << endl;
	}
	// Пример 6_2
	{
		gets_s(buff);
		char str[256] = "Привет ";
		strcat(str, buff); //Объединяет исходную строку buff и результирующую строку str, присоединяя первую к последней. Возвращает str.
		cout << buff << endl;
	}
	// Пример 7
	{
		int maxlen = 6;
		char scr[256] = "Вася !, Петя !", dest[256] = "Привет ";
		strncat(dest, scr, maxlen); //Объединяет maxlen символов исходной строки scr и результирующую строку dest, присоединяя часть первой к последней. Возвращает dest.
		cout << dest << endl;
	}
	// Пример 8
	{
		char str[256] = "Программирование на С++ ";
		char c = 'C';
		char *pts = strchr(str, c); //Ищет в строке str первое вхождение символа c, начиная с начала строки. В случае успеха возвращает указатель на найденный символ, иначе возвращает нуль.
		cout << pts << endl;
		//char *strrchr(const char *str, c); - Аналогично предыдущему, только поиск осуществляется с конца строки.
	}

	//Пример 9
	{
		const char *buf1 = "aaa", *buf2 = "bbb", *buf3 = "ccc";
		int ptr;
		ptr = strcmp(buf2, buf1); // Сравнивает две строки. Возвращает отрицательное значение, если s1<s2; нуль, если s1==s2; положительное значение, если s1>s2. Параметры - указатели на сравниваемые строки.
		if (ptr > 0)
			cout << "буфер 2 больше чем буфер 1" << endl;
		else
			cout << "буфер 2 - меньше чем буфер 1" << endl;
		ptr = strcmp(buf2, buf3);
		if (ptr > 0)
			cout << "буфер 2 больше чем буфер 3" << endl;
		else
			cout << "буфер 2 - меньше чем буфер 3" << endl;

		const char *buf11 = "aaa", *buf22 = "aaa";
		ptr = strcmp(buf22, buf11);
		if (ptr == 0)
			cout << "buf22 == buf11 " << endl;
		else
			cout << "buf22 != buf11 " << endl;

		const char *BUFF1 = "AAA", *BUFF2 = "aaa";

		if (0 == _stricmp(BUFF1, BUFF2)) // Аналогично предыдущему, только сравнение осуществляется без учета регистра символов.
			cout << "buf1 == buf2 " << endl;
		else
			cout << "buf2 != buf1 " << endl;

		const char *BUFF3 = "aaaccc", *BUFF4 = "aaabbb";
		int maxlen = 3;

		if (0 == strncmp(BUFF3, BUFF4, maxlen)) // Аналогично предыдущему, только сравниваются первые maxlen символов.
			cout << "buf3 == buf4 " << endl;
		else
			cout << "buf3 != buf4 " << endl;

		const char *BUFF5 = "AAAccc", *BUFF6 = "aaabbb";
		maxlen = 3;

		if (0 == _strnicmp(BUFF5, BUFF6, maxlen)) // Аналогично предыдущему, только сравниваются первые maxlen символов без учета регистра.
			cout << "buf5 == buf6 " << endl;
		else
			cout << "buf5 != buf6 " << endl;
	}
	//Пример 10
	{
		const char *string1 = "1234567890";
		const char *string2 = "ss123459";
		int length;
		length = strspn(string1, string2); //Возвращает длину максимальной начальной подстроки строки string1,содержащей символов из второй строки string2.
		cout << length << endl;
	}
	//Пример 11
	{
		const char *string1 = "1234567890";
		int size = strlen(string1); //Возвращает длину строки string1 - количество символов, предшествующих нулевому символу.
		cout << size << endl;
	}
	//Пример 12
	{
		char str[256] = "AAbbCCddEE";
		_strlwr(str); //Преобразует все прописные (большие) буквы в строчные (малые) в строке str.
		cout << str << endl;
	}
	//Пример 13
	{
		char str[256] = "AAbbCCddEE";
		_strupr(str); //Преобразует все строчные (малые) буквы в прописные (большие) в строке str.
		cout << str << endl;
	}
	//Пример 14
	{
		char str[256] = "Строка";
		int n = 1;
		char c = 'S';
		_strnset(str, c, n); //Заполняет строку str символами c. Параметр n задает количество размещаемых символов в строке.
		cout << str << endl;
	}
	//Пример 15
	{
		char s1[256] = "ABCDEFG", s2[256] = "MKD";
		char *pt = strpbrk(s1, s2); //Ищет в строке s1 первое вхождение любого символа из строки s2. Возвращает указатель на первый найденный символ или нуль - если символ не найден.
		cout << pt << endl;
	}
	//Пример 16
	{
		char str[256] = "ABCDE";
		_strrev(str); //Изменяет порядок следования символов в строке на обратный (кроме завершающего нулевого символа). Функция возвращает строку str.
		cout << str << endl;
	}
	//Пример 17
	{
		char str[256] = "Строка!!!";
		char c = 'A';
		_strset(str, c); //Заменяет все символы строки s заданным символом c.
		cout << str << endl;
	}
	//Пример 18
	{
		const char *s1 = "12345dza67890";
		const char *s2 = "a";
		int length;
		length = strcspn(s1, s2); //Вычисляет длину максимальной начальной подстроки строки s1,используя символы из строки s2.
		cout << length << endl;
	}
	//Пример 19
	{
		char s1[256] = "Один, Два, Три, Четыре, Пять";
		char s2[256] = "Три";
		char *pt = strstr(s1, s2); //Ищет в строке s1 строку s2. Возвращает адрес первого символа вхождения строки s2. Если строка отсутствует - возвращает нуль.
		cout << pt << endl;
	}
	//Пример 20
	{
		char s1[256] = "Один,Два:Три;Четыре!Пять<Шесть>Семь";
		char s2[256] = ",:;!<>";

		char *pt;
		pt = strtok(s1, s2); //Делит исходную строку s1 на лексемы (подстроки), разделенные одним или несколькими символами из строки s2.
		if (pt)
			cout << pt << endl;
		while (pt)
		{
			pt = strtok(NULL, s2);
			if (pt)
				cout << pt << endl;
		}
	}

	//Пример 21
	{
		char s[256] = "23.45";
		char s1[256] = "45";

		double ch = atof(s); //Преобразует строку s в число с плавающей точкой типа double. Заголовочный файл - math.h
		cout << ch << endl;

		int res = atoi(s1); //Преобразует строку s в число типа int. Возвращает значение или нуль, если строку преобразовать нельзя. Заголовочный файл - stdlib.h
		cout << res << endl;

		int value = 255;
		char s2[256];
		int radix = 10;
		_itoa(value, s2, radix); //Преобразует значение целого типа value в строку s2. Возвращает указатель на результирующую строку. Значение radix - основание системы счисления, используемое при преобразовании (от 2 до 36). Заголовочный файл - stdlib.h
		cout << s2 << endl;
	}
}