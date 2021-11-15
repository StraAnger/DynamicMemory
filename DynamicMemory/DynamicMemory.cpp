#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;;

void FillRand(int arr[], const unsigned int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const unsigned int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], unsigned int& n, int value);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	unsigned int n;	//Размер массива
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1

	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	///////////////////////////////////////////////////////////////////////////////
	////////////		Объявление двумерного динамического массива		///////////
	///////////////////////////////////////////////////////////////////////////////
	int** arr = new int* [rows];	//Создаем массив указателей
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};	//Выделяем память под строки двумерного массива
		//и помещаем адреса строк в элементы массива указателей.
	}
	///////////////////////////////////////////////////////////////////////////////
	////////////	Использование двумерного динамического массива		///////////
	///////////////////////////////////////////////////////////////////////////////

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	///////////////////////////////////////////////////////////////////////////////
	////////////		Удаление двумерного динамического массива		///////////
	///////////////////////////////////////////////////////////////////////////////
	//1) Удаляем строки двумерного массива:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2) Удаляем массив указателей:
	delete[] arr;
}

void FillRand(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int* push_back(int arr[], unsigned int& n, int value)
{
	//1) Создаем буферный массив:
	int* buffer = new int[n + 1]{};
	//2) Копируем значения из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив:
	delete[] arr;
	//4) Теперь buffer выглядит точно так же, как должен выглядить arr
	//поэтому подменяем адрес старого массива адресом ного (буферного) массива:
	arr = buffer;	//перезаписываем адрес старого массива адресом нового массива
	//5) Только после всего этого в массив arr можно добавить значение:
	arr[n] = value;	//Добавляем значение в конец массива
	//6) После того как в массиве добавился элемент, количество его элементов увеличивается на 1
	n++;
	//7) Значение добавлено
	return arr;	//Возвращаем адрес нового массива, с добавленным значением.
}