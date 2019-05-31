#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

void Save(int &size)
{
    char path_sctruct[20] = "test.dat";
    ofstream file_out(path_sctruct, ios::binary);
    if (!file_out.is_open())
    {
        cout << "Error , while try to open file!" << endl;
    }
    else
    {
        size = 222;
        file_out.write((char *)&size, sizeof(size));
    }
    file_out.close();
}

void Load(int &size)
{
    char path_sctruct[20] = "test.dat";
    ifstream file_in(path_sctruct, ios::binary);
    if (!file_in.is_open())
    {
        cout << "Error , while try to open file!" << endl;
    }
    else
    {
        file_in.read((char *)&size, sizeof(size));
    }
    file_in.close();
}
int main()
{
    int size = 5;
    //Save(size);
    Load(size);
    cout << size;
}