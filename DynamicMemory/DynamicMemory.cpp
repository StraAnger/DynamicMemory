#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;;

void FillRand(int arr[], const unsigned int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const unsigned int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);

template<typename T>void Print(T arr[], const unsigned int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* push_back(T arr[], unsigned int& n, T value);
template<typename T>T* push_front(T arr[], unsigned int& n, T value);
template<typename T>T* insert(T arr[], unsigned int& n, T value, unsigned int index);
template<typename T>T* pop_back(T arr[], unsigned int& n);
template<typename T>T* pop_front(T arr[], unsigned int& n);
//T* - Указатель на шаблонный тип
template<typename T>T* erase(T arr[], unsigned int& n, int value, unsigned int index);

template<typename T>T** allocate(const unsigned int rows, const unsigned int cols);
template<typename T>void clear(T** arr, const unsigned int rows);

template<typename T>T** push_row_back(T** arr, unsigned int& rows, const unsigned int cols);
template<typename T>T** pop_row_back(T** arr, unsigned int& rows, const unsigned int cols);

//T& - ссылка на шаблонный тип
template<typename T>void push_col_back(T** arr, const unsigned int rows, unsigned int& cols);

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
	double** arr = allocate<double>(rows, cols);
	///////////////////////////////////////////////////////////////////////////////
	////////////	Использование двумерного динамического массива		///////////
	///////////////////////////////////////////////////////////////////////////////

	//(type)value - C-like notation
	//type(value) - Functional notation

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

	/*
	//https://ru.wikipedia.org/wiki/%D0%92%D0%B5%D0%BD%D0%B3%D0%B5%D1%80%D1%81%D0%BA%D0%B0%D1%8F_%D0%BD%D0%BE%D1%82%D0%B0%D1%86%D0%B8%D1%8F
	size_t d_rows, d_cols;
	cout << "Введите количество строк: "; cin >> d_rows;
	cout << "Введите количество элементов строки: "; cin >> d_cols;
	double** d_arr_2 = allocate<double>(d_rows, d_cols);
	FillRand(d_arr_2, d_rows, d_cols);
	Print(d_arr_2, d_rows, d_cols);
	clear(d_arr_2, rows);*/
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
void FillRand(double arr[], const unsigned int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
		arr[i] /= 100;
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
void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10000;
			arr[i][j] /= 100;
		}
	}
}

template<typename T>void Print(T arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const int rows, const int cols)
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

template<typename T>T* push_back(T arr[], unsigned int& n, T value)
{
	//1) Создаем буферный массив:
	T* buffer = new T[n + 1]{};
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
template<typename T>T* push_front(T arr[], unsigned int& n, T value)
{
	T* buffer = new T[n + 1]{};
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
template<typename T>T* insert(T arr[], unsigned int& n, T value, unsigned int index)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
template<typename T>T* pop_back(T arr[], unsigned int& n)
{
	T* buffer = new T[--n]{};
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

template<typename T>T** allocate(const unsigned int rows, const unsigned int cols)
{
	///////////////////////////////////////////////////////////////////////////////
	////////////		Объявление двумерного динамического массива		///////////
	///////////////////////////////////////////////////////////////////////////////
	T** arr = new T * [rows];	//Создаем массив указателей
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols]{};	//Выделяем память под строки двумерного массива
		//и помещаем адреса строк в элементы массива указателей.
	}
	return arr;
}
template<typename T>void clear(T** arr, const unsigned int rows)
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

template<typename T>T** push_row_back(T** arr, unsigned int& rows, const unsigned int cols)
{
	//++ Increment
	//-- Decrement
	int i = 0;
	++i;	//Prefix inclrement
	i++;	//Postfix inclrement
	--i;	//Prefix decrement
	i--;	//Postfix decrement
	T** buffer = new T * [rows + 1]{};	//Создаем новый массив указателей
	for (int i = 0; i < rows; i++)
		buffer[i] = arr[i];
	delete[] arr;	//Удаляем старый массив указателей
	arr = buffer;
	arr[rows] = new T[cols]{};
	rows++;
	return arr;
}
template<typename T>T** pop_row_back(T** arr, unsigned int& rows, const unsigned int cols)
{
	T** buffer = new T * [--rows]{};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr[rows];	//Удаляем последнюю строку из памяти
	delete[] arr;	//Удаляем старый массив указателей
	return buffer;
}

template<typename T>void push_col_back(T** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}