//ітераційний спосіб
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void create(int** a, const int rowCount, const int colCount, const int low, const int high)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = low + rand() % (high - low + 1);
}

void print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (a[i][j] > 0 && (a[i][j] % 5 != 0))
			{
				S += a[i][j];
				k++;
				a[i][j] = 0;
			}
}

void change(int** a, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = a[row1][j];
		a[row1][j] = a[row2][j];
		a[row2][j] = tmp;
	}
}

void sort(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount - 1; i++)
		for (int j = 0; j < rowCount - i - 1; j++)
			if ((a[j][0] > a[j + 1][0])
				||
				(a[j][0] == a[j + 1][0] &&
					a[j][1] < a[j + 1][1])
				||
				(a[j][0] == a[j + 1][0] &&
					a[j][1] == a[j + 1][1] &&
					a[j][3] > a[j + 1][3]))
				change(a, j, j + 1, colCount);
}

int main()
{
	srand((unsigned)time(NULL));
	int low = -31;
	int high = 54;
	int rowCount = 4;
	int colCount = 4;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	create(a, rowCount, colCount, low, high);
	print(a, rowCount, colCount);
	sort(a, rowCount, colCount);
	print(a, rowCount, colCount);
	int S = 0;
	int k = 0;
	Calc(a, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	print(a, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}