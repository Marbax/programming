#include "MyStack.h"
#include <iostream>
#include <string.h>

using namespace std;

/* 
Написать программу, принимающую арифметическое выражение в виде строки, и
определяющую корректность расстановки скобок в этом выражении. Учесть круглые «()»,
квадратные«[]», фигурные «{}» и угловые «<>» скобки.
Скобки считаются сбалансированными, если:
a) количество открывающихся скобок совпадает с количеством закрывающихся;
b) закрывающаяся скобка не идет раньше соответствующей ей открывающейся;
c) соблюдается принцип вложенности скобок.
 */

bool ValidateString(const char *str);

int main()
{
    (ValidateString("([13/0]<)>")) ? cout << "True" << endl : cout << "False" << endl;
    (ValidateString("([13/0]<>)")) ? cout << "True" << endl : cout << "False" << endl;
    (ValidateString("([13/0])<>")) ? cout << "True" << endl : cout << "False" << endl;
    (ValidateString("([<13/0])>")) ? cout << "True" << endl : cout << "False" << endl;
    (ValidateString("([>13/0]<)")) ? cout << "True" << endl : cout << "False" << endl;
    (ValidateString("([13/0]<>)11")) ? cout << "True" << endl : cout << "False" << endl;
    (ValidateString("([13/0])<>11")) ? cout << "True" << endl : cout << "False" << endl;
    cout << "END OF PROGRAM" << endl;
}

bool ValidateString(const char *str)
{
    MyStack tmp_stack(strlen(str) + 1);
    for (const char *pt = str; *pt; pt++)
    {
        if (!tmp_stack.Is_Full())
        {
            switch (*pt)
            {
            case '(':
                tmp_stack.Push(*pt);
                break;
            case '{':
                tmp_stack.Push(*pt);
                break;
            case '[':
                tmp_stack.Push(*pt);
                break;
            case '<':
                tmp_stack.Push(*pt);
                break;
            case ')':
                if (tmp_stack.Is_Empty())
                    return false;
                if (tmp_stack.Pop() != '(')
                {
                    return false;
                }
                break;
            case '}':
                if (tmp_stack.Is_Empty())
                    return false;
                if (tmp_stack.Pop() != '{')
                {
                    return false;
                }
                break;
            case ']':
                if (tmp_stack.Is_Empty())
                    return false;
                if (tmp_stack.Pop() != '[')
                {
                    return false;
                }
                break;
            case '>':
                if (tmp_stack.Is_Empty())
                    return false;
                if (tmp_stack.Pop() != '<')
                {
                    return false;
                }
                break;

            default:
                break;
            }
        }
    }
    if (!tmp_stack.Is_Empty())
        return false;

    return true;
}
