#include <iostream>

using namespace std;

namespace my_space
{
class Window
{
private:
    int height, width;

public:
    Window(int height, int width);
    ~Window();
};

Window::Window(int height, int width) : height(height), width(width)
{
}

Window::~Window()
{
}

} // namespace my_space

int main(int argc, char *argv[]) // agrc - кол-водоп аргументов ,передаваемых при запуске исполняемого файла , argv - массив строк(самих аргументов)
{
    for (size_t i = 0; i < argc; i++)
    {
        cout << argv[i] << endl;
    }
    my_space::Window obj(15, 15);
}