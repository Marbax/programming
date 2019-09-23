#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//vector<int> v1;
	//vector<int> v2(10);
	//vector<int> v3(10, 5);
	//int arr[10]{ 1,2,4,5,7,8,9 };
	//vector<int> v4(arr, arr + 10);
	//vector<int> v5 = v4;
	//vector<int> v6(v5.begin(), v5.end());// end возвращает эллемент за последним (недостижим) т.е. до end

	//for (size_t i = 0; i < 50; i++)
	//{
	//	cout << v1.capacity() << " " << v1.size() << endl;
	//	v1.push_back(i);
	//}
	//
	//v1.shrink_to_fit();
	////v1.clear();
	//cout << v1.capacity() << " " << v1.size() << endl;

	/*v6.insert(v6.begin(), 1000);
	v6.erase(v6.begin());
	for (size_t i = 0; i < v6.size() + 3; i++)
	{
		cout << v6.at(i) << " ";
	}*/

	vector<int> vector1(10);
	for (auto i = vector1.begin(); i != vector1.end(); i++) // auto same as vector<int>::iterator
	{
		*i = rand() % 10;
	}
	for (int item : vector1) // только для вывода используется
	{
		cout << item << " ";
	}
	cout << endl;
	cout << endl;

	vector<vector<int>> arr(5);
	for (size_t i = 0; i < arr.size(); i++)
	{
		arr[i].resize(4);
	}

	for (size_t i = 0; i < arr.size(); i++)
	{
		for (size_t j = 0; j < arr[i].size(); j++)
		{
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

}