#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//------------------------------------------------------------------
	//----------------------���������_������----------------------------
	//------------------------------------------------------------------

	//fstream fs;
	//try
	//{
	//	fs.open(R"(F:\programming\class_work\21\Project1\test.txt)", ios::out);  // row string
	//	if (!fs.is_open())
	//	{
	//		throw new logic_error("can't open file!");
	//	}
	//	fs << "some text" << endl;
	//	fs << "one more" << "line" << endl;

	//	fs.close();
	//}
	//catch (const logic_error& ex)
	//{
	//	cerr << "Error. " << ex.what() << endl;
	//}

	//string buf;
	//try
	//{
	//	fs.open(R"(F:\programming\class_work\21\Project1\test.txt)", ios::in);  // row string
	//	if (!fs.is_open())
	//	{
	//		throw new logic_error("can't open file!");
	//	}
	//	//fs >> buf;
	//	//cout << fs.rdbuf() << endl; // ������� ��� ���������� ����� , �� ��� ����� ������� ������
	//	while (!fs.eof())
	//	{
	//		getline(fs, buf);
	//		cout << buf << endl;

	//	}

	//	fs.close();
	//}
	//catch (const logic_error& ex)
	//{
	//	cerr << "Error. " << ex.what() << endl;
	//}

	//------------------------------------------------------------------
	//----------------------������_�_����������������_�����_������------
	//------------------------------------------------------------------

	class MyArray
	{
	public:
		MyArray() = default;
		MyArray(int s, double val)
		{
			size = s;
			arr = new double[size];
			for (size_t i = 0; i < size; i++)
			{
				arr[i] = (val + i) * 2;
			}
		}
		/*MyArray(MyArray& obj) {
			size = obj.size;
			strdup(arr, obj.arr);
		}*/

		~MyArray()
		{
			if (size)
			{
				delete[] arr;
			}
		}
		void save(fstream &fs)
		{
			fs.write((char *)&size, sizeof(int));
			fs.write((char *)arr, sizeof(double) * size);
		}
		void load(fstream &fs)
		{
			if (size)
			{
				delete[] arr;
			}
			fs.read((char *)&size, sizeof(int));
			arr = new double[size];
			fs.read((char *)arr, sizeof(double) * size);
		}
		void setSize(int s) { size = s; }
		int getSize() { return size; }
		double operator[](int pos) { return arr[pos]; }

	private:
		int size = 0;
		double *arr = nullptr;
	};

	// bin example
	MyArray obj(10, 2);
	MyArray to_read;
	fstream fs;
	try
	{
		fs.open(R"(F:\programming\class_work\21\Project1\test.txt)", ios::out | ios::binary); // row string
		if (!fs.is_open())
		{
			throw new logic_error("can't open file!");
		}
		obj.save(fs);
		fs.close();
	}
	catch (const logic_error &ex)
	{
		cerr << "Error. " << ex.what() << endl;
	}

	string buf;
	try
	{
		fs.open(R"(F:\programming\class_work\21\Project1\test.txt)", ios::in | ios::binary); // row string
		if (!fs.is_open())
		{
			throw new logic_error("can't open file!");
		}
		to_read.load(fs);
		for (size_t i = 0; i < to_read.getSize(); i++)
		{
			cout << to_read[i] << " ";
		}
		cout << endl;
		fs.close();
	}
	catch (const logic_error &ex)
	{
		cerr << "Error. " << ex.what() << endl;
	}

	//------------------------------------------------------------------
	//----------------------��������_������-----------------------------
	//------------------------------------------------------------------

	//fstream fs;
	//double arr[5]{ 4.5,325.2,25.2,1.2 }, mas[5]{};
	//try
	//{
	//	fs.open(R"(F:\programming\class_work\21\Project1\test.txt)", ios::out | ios::binary);  // row string
	//	if (!fs.is_open())
	//	{
	//		throw new logic_error("can't open file!");
	//	}
	//	fs.write((char*)& arr, sizeof(double)*5);
	//	fs.close();
	//}
	//catch (const logic_error& ex)
	//{
	//	cerr << "Error. " << ex.what() << endl;
	//}

	//string buf;
	//try
	//{
	//	fs.open(R"(F:\programming\class_work\21\Project1\test.txt)", ios::in | ios::binary);  // row string
	//	if (!fs.is_open())
	//	{
	//		throw new logic_error("can't open file!");
	//	}
	//	fs.read((char*)& mas, sizeof(double)*5); // mas ���� ������ �� �����
	//	for (size_t i = 0; i < 5; i++)
	//	{
	//		cout << mas[i] << " " << endl;
	//	}

	//	fs.close();
	//}
	//catch (const logic_error& ex)
	//{
	//	cerr << "Error. " << ex.what() << endl;
	//}
}
