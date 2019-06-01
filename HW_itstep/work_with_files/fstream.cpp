
void Save(Movie *&videostore, int &size)//хз как структуру сохранять правиль
{
    string path_sctruct = "Videostore_struct.dat";
    // FILE* f = fopen(path_sctruct,"wb")
    ofstream fout(path_sctruct, ios::binary);
    if (!fout.is_open())
    {
        cout << "Error , while try to open file!" << endl;
    }
    else
    {
        fout.write((char *)&size, sizeof(size));
        /* for (int i = 0; i < size; i++)
        {
            fout.write((char *)(&videostore[i]), sizeof(Movie));
        } */
        fout.write((char *)(&videostore), sizeof(Movie) * size);
    }
    fout.close();
}

void Load(Movie *&videostore, int &size) // хз как загружать структуру правильно
{
    string path_sctruct = "Videostore_struct.dat";
    ifstream file_in(path_sctruct, ios::binary);
    if (!file_in.is_open())
    {
        cout << "Error , while try to open file!" << endl;
    }
    else
    {
        file_in.read((char *)&size, sizeof(size));
        cout << "size = " << size << endl;
        /* for (int i = 0; i < size; i++)
        {
            videostore = new Movie[i];
            file_in.read((char *)(&videostore[i]), sizeof(Movie));
            cout << "!!! " << i << " " << &videostore[i] << endl;
        } */
        file_in.read((char *)(&videostore), sizeof(Movie));
    }
    file_in.close();
}