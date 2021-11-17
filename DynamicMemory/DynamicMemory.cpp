#include"stdafx.h"
#include"FillRand.h"//���� ������� �� ���������, �� *.cpp-���� �� � ���� ������ �� ������������
#include"Print.h"
#include"Print.cpp"	//���� ������� ���������, �� ������������ ��� � *.cpp-����

template<typename T>T* push_back(T arr[], unsigned int& n, T value);
template<typename T>T* push_front(T arr[], unsigned int& n, T value);
template<typename T>T* insert(T arr[], unsigned int& n, T value, unsigned int index);
template<typename T>T* pop_back(T arr[], unsigned int& n);
template<typename T>T* pop_front(T arr[], unsigned int& n);
//T* - ��������� �� ��������� ���
template<typename T>T* erase(T arr[], unsigned int& n, int value, unsigned int index);

template<typename T>T** allocate(const unsigned int rows, const unsigned int cols);
template<typename T>void clear(T** arr, const unsigned int rows);

template<typename T>T** push_row_back(T** arr, unsigned int& rows, const unsigned int cols);
template<typename T>T** pop_row_back(T** arr, unsigned int& rows, const unsigned int cols);

//T& - ������ �� ��������� ���
template<typename T>void push_col_back(T** arr, const unsigned int rows, unsigned int& cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define PREFORMANCE_CHECK

//#ifdef	- #if defined		(���� ����������)
//#ifndef	- #if not defined	(���� �� ����������)

void main()
{
	using namespace std;
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	unsigned int n;	//������ �������
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n] {};

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);
	cout << "\n---------------------------------------------\n";
	arr = pop_back(arr, n);
	Print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	unsigned int rows, cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;
	double** arr = allocate<double>(rows, cols);
	///////////////////////////////////////////////////////////////////////////////
	////////////	������������� ���������� ������������� �������		///////////
	///////////////////////////////////////////////////////////////////////////////

	//(type)value - C-like notation
	//type(value) - Functional notation

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "���������� ������ � ����� �������:\n";
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "��������� ����������� ������ ���������� �������:\n";
	FillRand(arr[rows - 1], cols, 1000, 2000);
	Print(arr, rows, cols);
	cout << "������� ��������� ������ �� �������:\n";
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "��������� ������� � ����� �������:\n";
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	clear(arr, rows);

	/*
	//https://ru.wikipedia.org/wiki/%D0%92%D0%B5%D0%BD%D0%B3%D0%B5%D1%80%D1%81%D0%BA%D0%B0%D1%8F_%D0%BD%D0%BE%D1%82%D0%B0%D1%86%D0%B8%D1%8F
	size_t d_rows, d_cols;
	cout << "������� ���������� �����: "; cin >> d_rows;
	cout << "������� ���������� ��������� ������: "; cin >> d_cols;
	double** d_arr_2 = allocate<double>(d_rows, d_cols);
	FillRand(d_arr_2, d_rows, d_cols);
	Print(d_arr_2, d_rows, d_cols);
	clear(d_arr_2, rows);*/
#endif // DYNAMIC_MEMORY_2

#ifdef PREFORMANCE_CHECK
	unsigned int rows, cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;
	int** arr = allocate(rows, cols);
	cout << "������ ��������, ��� ���������� ������ ������� ����� �������\n";
	system("PAUSE");
	arr = push_row_back(arr, rows, cols);
	clear(arr, rows);
#endif // PREFORMANCE_CHECK

}



template<typename T>T* push_back(T arr[], unsigned int& n, T value)
{
	//1) ������� �������� ������:
	T* buffer = new T[n + 1]{};
	//2) �������� �������� �� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������:
	delete[] arr;
	//4) ������ buffer �������� ����� ��� ��, ��� ������ ��������� arr
	//������� ��������� ����� ������� ������� ������� ���� (���������) �������:
	arr = buffer;	//�������������� ����� ������� ������� ������� ������ �������
	//5) ������ ����� ����� ����� � ������ arr ����� �������� ��������:
	arr[n] = value;	//��������� �������� � ����� �������
	//6) ����� ���� ��� � ������� ��������� �������, ���������� ��� ��������� ������������� �� 1
	n++;
	//7) �������� ���������
	return arr;	//���������� ����� ������ �������, � ����������� ���������.
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
	////////////		���������� ���������� ������������� �������		///////////
	///////////////////////////////////////////////////////////////////////////////
	T** arr = new T * [rows];	//������� ������ ����������
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols]{};	//�������� ������ ��� ������ ���������� �������
		//� �������� ������ ����� � �������� ������� ����������.
	}
	return arr;
}
template<typename T>void clear(T** arr, const unsigned int rows)
{
	///////////////////////////////////////////////////////////////////////////////
	////////////		�������� ���������� ������������� �������		///////////
	///////////////////////////////////////////////////////////////////////////////
	//1) ������� ������ ���������� �������:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2) ������� ������ ����������:
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
	T** buffer = new T * [rows + 1]{};	//������� ����� ������ ����������
	for (int i = 0; i < rows; i++)
		buffer[i] = arr[i];
	delete[] arr;	//������� ������ ������ ����������
	arr = buffer;
	arr[rows] = new T[cols]{};
	rows++;
	return arr;
}
template<typename T>T** pop_row_back(T** arr, unsigned int& rows, const unsigned int cols)
{
	T** buffer = new T * [--rows]{};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr[rows];	//������� ��������� ������ �� ������
	delete[] arr;	//������� ������ ������ ����������
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