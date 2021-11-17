#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;;

void FillRand(int arr[], const unsigned int n);
void FillRand(int** arr, const int rows, const int cols);

void FillRand(double arr[], const unsigned int n);
void FillRand(double** arr, const int rows, const int cols);

void FillRand(char arr[], const unsigned int n);
void FillRand(char** arr, const int rows, const int cols);

void Print(int arr[], const unsigned int n);
void Print(int** arr, const int rows, const int cols);

void Print(double arr[], const unsigned int n);
void Print(double** arr, const int rows, const int cols);

void Print(char arr[], const unsigned int n);
void Print(char** arr, const int rows, const int cols);


//#define DIM_1_ARRAY_INT
//#define DIM_2_ARRAY_INT

//#define DIM_1_ARRAY_DOUBLE
//#define DIM_2_ARRAY_DOUBLE

//#define DIM_1_ARRAY_CHAR
#define DIM_2_ARRAY_CHAR

int main() {

#ifdef DIM_1_ARRAY_INT
	unsigned int n;	//Array size
	cout << "Enter size of array: "; cin >> n;
	int* arr = new int[n] {};

	FillRand(arr, n);
	Print(arr, n);
		
	delete[] arr;
#endif // DIM_1_ARRAY_INT

#ifdef DIM_2_ARRAY_INT
	int rows, cols;
	cout << "Enter number of rows: "; cin >> rows;
	cout << "Enter number of columns: "; cin >> cols;
	
	int** arr = new int* [rows];	
	for (int i = 0; i < rows; i++){

		arr[i] = new int[cols] {};	
	}
	
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	
	for (int i = 0; i < rows; i++){
		delete[] arr[i];
	}
	delete[] arr;

#endif // DIM_2_ARRAY_INT

#ifdef DIM_1_ARRAY_DOUBLE
	unsigned int n;	//Array size
	cout << "Enter size of array: "; cin >> n;
	double* arr = new double[n] {};

	FillRand(arr, n);
	Print(arr, n);

	delete[] arr;
#endif // DIM_1_ARRAY_DOUBLE

#ifdef DIM_2_ARRAY_DOUBLE
	int rows, cols;
	cout << "Enter number of rows: "; cin >> rows;
	cout << "Enter number of columns: "; cin >> cols;

	double** arr = new double* [rows];
	for (int i = 0; i < rows; i++) {

		arr[i] = new double[cols] {};
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);


	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;

#endif // DIM_2_ARRAY_DOUBLE

#ifdef DIM_1_ARRAY_CHAR
	unsigned int n;	//Array size
	cout << "Enter size of array: "; cin >> n;
	char* arr = new char[n] {};

	FillRand(arr, n);
	Print(arr, n);

	delete[] arr;
#endif // DIM_1_ARRAY_CHAR

#ifdef DIM_2_ARRAY_CHAR
	int rows, cols;
	cout << "Enter number of rows: "; cin >> rows;
	cout << "Enter number of columns: "; cin >> cols;

	char** arr = new char* [rows];
	for (int i = 0; i < rows; i++) 	{

		arr[i] = new char[cols] {};
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);


	for (int i = 0; i < rows; i++) 	{

		delete[] arr[i];
	}
	delete[] arr;

#endif // DIM_2_ARRAY_CHAR

	return 0;
}

void FillRand(int arr[], const unsigned int n) {

	for (int i = 0; i < n; i++) {

		arr[i] = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols) {

	for (int i = 0; i < rows; i++) 	{

		for (int j = 0; j < cols; j++) 	{

			arr[i][j] = rand() % 100;
		}
	}
}

void FillRand(double arr[], const unsigned int n) {

	for (int i = 0; i < n; i++)  	{

		arr[i] = rand() % 100*0.1;
	}

	
}
void FillRand(double** arr, const int rows, const int cols) {

	for (int i = 0; i < rows; i++) 	{

		for (int j = 0; j < cols; j++) 	{

			arr[i][j] = rand() % 100 * 0.1;
		}
	}
}

void FillRand(char arr[], const unsigned int n) {

	for (int i = 0; i < n; i++) {

		arr[i] = rand() % 255;
	}
}

void FillRand(char** arr, const int rows, const int cols) {

	for (int i = 0; i < rows; i++) 	{

		for (int j = 0; j < cols; j++) 	{

			arr[i][j] = rand() % 255;
		}
	}
}

void Print(int arr[], const unsigned int n) {

	for (int i = 0; i < n; i++) {

		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols) {

	for (int i = 0; i < rows; i++)	{

		for (int j = 0; j < cols; j++) 	{

			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}


void Print(double arr[], const unsigned int n) {

	for (int i = 0; i < n; i++) {

		cout << arr[i] << "\t";
	}
	cout << endl;
}

void Print(double** arr, const int rows, const int cols) {

	for (int i = 0; i < rows; i++){

		for (int j = 0; j < cols; j++)	{

			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}


void Print(char arr[], const unsigned int n){

	for (int i = 0; i < n; i++)	{

		cout << arr[i] << "\t";
	}
	cout << endl;
}

void Print(char** arr, const int rows, const int cols) {

	for (int i = 0; i < rows; i++)	{

		for (int j = 0; j < cols; j++)	{

			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}