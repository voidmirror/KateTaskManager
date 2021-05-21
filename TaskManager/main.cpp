#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Database.hpp"
#include "Manager.hpp"
#include "Employee.hpp"
#include "Task.hpp"

using namespace std;

void opening(ifstream filename, int n)//функция для проверки на открытие файлов с бд
{
	file.open(filename);
	if (!file.is_open())//если не открылся файл то выхоим с программы
	{
		cout << "   !!!   THE DATABASE NUMBER " << n << " IS BROKEN   !!!   " << endl;
		return 0;
	}
}

int main(int argc, char** argv1, char** argv2){
	if (argc!=3) //проверка на количество аргументов
	{ 
			cout << "   !!!   PLEASE, PROVIDE EXACTLY 2 DATABASE FILENAMES	   !!!   " << endl;
			return 0;
	}
	
	string employeeName=argv[1]; // переносим название бд в переменные
	string taskName=argv[2];
	ifstram file1;
	ifstream file2;
	
	opening(file1,1);// открываем файлы с бд
	opening(file2,2);
	
	Manager basa;// загружаем бд в оперативную память и закрываем тектовые файлы
	basa.load(file1);
	basa.load(file2);
	file1.close();
	file2.close();
	
	basa.work();// запускаем работу менеджера 
	
	ofstream file11; //обновляем текстовые файлы бд и закрываем их
	ofstream file22;
	opening(file11,1);
	opening(file22,2);
	
	basa.unload(file11);
	file11.close();
	basa.unload(file22);
	file22.close();
	
	return 0;
}}
