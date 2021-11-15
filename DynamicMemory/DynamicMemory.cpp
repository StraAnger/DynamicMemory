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
	unsigned int n;	//������ �������
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n] {};

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1

	int rows, cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;
	///////////////////////////////////////////////////////////////////////////////
	////////////		���������� ���������� ������������� �������		///////////
	///////////////////////////////////////////////////////////////////////////////
	int** arr = new int* [rows];	//������� ������ ����������
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};	//�������� ������ ��� ������ ���������� �������
		//� �������� ������ ����� � �������� ������� ����������.
	}
	///////////////////////////////////////////////////////////////////////////////
	////////////	������������� ���������� ������������� �������		///////////
	///////////////////////////////////////////////////////////////////////////////

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

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
	//1) ������� �������� ������:
	int* buffer = new int[n + 1]{};
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