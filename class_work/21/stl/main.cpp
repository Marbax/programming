#include <iostream>
#include <string>
#include <list>
#include <deque>
#include <set>
#include <unordered_set>
#include <ctime>
#include <map>
#include <unordered_map>


using namespace std;

int main()
{
	srand(time(0));
	deque<int>d(10);

	for (size_t i = 0; i < d.size(); i++)
	{
		d[i] = rand() % 12;
	}

	for (size_t i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;


	//set<int>s; // повторы выкидываются
	//multiset<int>s; // повторы остаются
	//unordered_set<int>s; // не полностью упорядчнены , повторы выкидываются
	unordered_multiset<int>s; // не полностью упорядчнены , повторы остаются 

	for (size_t i = 0; i < d.size(); i++)
	{
		s.insert(d[i]);
	}

	for (int item : s)
	{
		cout << item << " ";
	}
	cout << endl;


	//map<int, string>m; // упорядочнены ,так как мапа тоже дерево (от меньшего к большему) уникальны
	//multimap<int, string>m; // упорядочнены ,так как мапа тоже дерево (от меньшего к большему) не уникальны

	unordered_map<int, string>m; // не полность упорядочнены ,так как мапа тоже дерево (от меньшего к большему) не уникальны


	m.insert(pair<int, string>(5, "five"));
	m.insert(pair<int, string>(4, "four"));
	m.insert(pair<int, string>(3, "ten"));
	m.insert(pair<int, string>(3, "zero"));
	m.insert(pair<int, string>(3, "three"));
	m.insert(pair<int, string>(2, "two"));

	//cout << m[0] << endl; // в квадратные скобки принимается ключ любого типа

	for (auto item : m)
	{
		cout << item.first << " -> " << item.second << endl;
	}

	cout << endl;

	//unordered_map<string, string>m1; // не полность упорядочнены ,так как мапа тоже дерево (от меньшего к большему) уникальны
	unordered_multimap<string, string>m1; // не полность упорядочнены ,так как мапа тоже дерево (от меньшего к большему) не уникальны


	m1.insert(pair<string, string>("four", "five"));
	m1.insert(pair<string, string>("four", "four"));
	m1.insert(pair<string, string>("four", "ten"));
	cout<<m1.load_factor();// коеф заполненности
	cout << endl;
	m1.insert(pair<string, string>("two", "zero"));
	m1.insert(pair<string, string>("two", "three"));
	m1.insert(pair<string, string>("zero", "two"));

	for (auto item : m1)
	{
		cout << item.first << " -> " << item.second << endl;
	}

	cout << endl;


}