#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;;

void FillRand(int arr[], const unsigned int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const unsigned int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], unsigned int& n, int value);
int* push_front(int arr[], unsigned int& n, int value);
int* insert(int arr[], unsigned int& n, int value, unsigned int index);
int* pop_back(int arr[], unsigned int& n);
int* pop_front(int arr[], unsigned int& n);
int* erase(int arr[], unsigned int& n, int value, unsigned int index);

int** allocate(const unsigned int rows, const unsigned int cols);
void clear(int** arr, const unsigned int rows);

int** push_row_back(int** arr, unsigned int& rows, const unsigned int cols);
int** pop_row_back(int** arr, unsigned int& rows, const unsigned int cols);

void push_col_back(int** arr, const unsigned int rows, unsigned int& cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define PREFORMANCE_CHECK

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
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);
	cout << "\n---------------------------------------------\n";
	arr = pop_back(arr, n);
	Print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	unsigned int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	int** arr = allocate(rows, cols);
	///////////////////////////////////////////////////////////////////////////////
	////////////	Использование двумерного динамического массива		///////////
	///////////////////////////////////////////////////////////////////////////////

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Добавление строки в конец массива:\n";
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Заполняем добавленную строку случайными числами:\n";
	FillRand(arr[rows - 1], cols, 1000, 2000);
	Print(arr, rows, cols);
	cout << "Удаляем последнюю строку из массива:\n";
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Добавляем столбец в конец массива:\n";
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	clear(arr, rows);
#endif // DYNAMIC_MEMORY_2

#ifdef PREFORMANCE_CHECK
	unsigned int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	int** arr = allocate(rows, cols);
	cout << "Память выделена, для добавления строки нажмите любую клавишу\n";
	system("PAUSE");
	arr = push_row_back(arr, rows, cols);
	clear(arr, rows);
#endif // PREFORMANCE_CHECK

}

void FillRand(int arr[], const unsigned int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
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
		//cout << arr[i] << ":\t";
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
int* push_front(int arr[], unsigned int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* insert(int arr[], unsigned int& n, int value, unsigned int index)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
int* pop_back(int arr[], unsigned int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

int** allocate(const unsigned int rows, const unsigned int cols)
{
	///////////////////////////////////////////////////////////////////////////////
	////////////		Объявление двумерного динамического массива		///////////
	///////////////////////////////////////////////////////////////////////////////
	int** arr = new int* [rows];	//Создаем массив указателей
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};	//Выделяем память под строки двумерного массива
		//и помещаем адреса строк в элементы массива указателей.
	}
	return arr;
}
void clear(int** arr, const unsigned int rows)
{
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

int** push_row_back(int** arr, unsigned int& rows, const unsigned int cols)
{
	int** buffer = new int* [rows + 1]{};	//Создаем новый массив указателей
	for (int i = 0; i < rows; i++)
		buffer[i] = arr[i];
	delete[] arr;	//Удаляем старый массив указателей
	arr = buffer;
	arr[rows] = new int[cols] {};
	rows++;
	return arr;
}
int** pop_row_back(int** arr, unsigned int& rows, const unsigned int cols)
{
	int** buffer = new int* [--rows]{};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr[rows];	//Удаляем последнюю строку из памяти
	delete[] arr;	//Удаляем старый массив указателей
	return buffer;
}

void push_col_back(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}