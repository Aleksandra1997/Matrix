#include <iostream>
#include <conio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "matrix.h"

using namespace std;


int main()
{
	while (1)
	{
		cout << "-----------------------MENU-----------------------" << endl;
		cout << "[1] - Create the matrix" << endl;
		cout << "[2] - Fill in your matrix" << endl;
		cout << "[3] - Random matrix" << endl;
		cout << "[4] - Add the matrix" << endl;
		cout << "[5] - Multiply the matrix by the scalar" << endl;
		cout << "[6] - Multiplication of two matrixes" << endl;
		cout << "[x/X] - The End" << endl;
		cout << "--------------------------------------------------" << endl;
		char choice;
		choice = _getch();

		switch (choice)
		{
		case '1':
		{
			cout << endl;
			int row, column;
			cmacierz m1;
			cout << "Enter the number of rows: ";
			cin >> row;
			cout << "Enter the number of columns: ";
			cin >> column;
			m1.uzupelnij(row, column);

			//other option
			//m1.wyswietl();
			cout << m1;
			break;
		}
		case'2':
		{
			cout << endl;

			cmacierz m2;
			cout << "\nFill in the matrix" << endl;
			m2.wymiar();
			cin >> m2;
			cout << "\nYour matrix: " << endl << m2;
			break;
		}
		case '3':
		{
			cout << endl;
			cmacierz m2;
			m2.wymiar();

			cout << "Random matrix--->" << endl;

			m2.losowe();
			//other option
			//m2.wyswietl();
			cout << m2 << endl;

			break;
		}
		case '4':
		{
			cout << endl;
			cmacierz matrix1, matrix2, sum;
			matrix1.nowa(matrix2);
			matrix1.losowe();

			cout << "ADDITION\n" << endl;
			cout << "FIRST MATRIX" << endl;
			cout << matrix1 << endl;
			cout << "\nSECOND MATRIX" << endl;
			cout << matrix2 << endl;

			cout << "WYNIK" << endl;
			sum = matrix1.operator+(matrix2);
			cout << sum << endl;

			break;
		}
		case'5':
		{
			cout << endl;
			int a;
			cmacierz m2;
			cmacierz result;
			cout << "Enter the number: ";
			cin >> a;

			m2.wymiar();
			m2.losowe();

			//other option
			//m2.wyswietl();
			cout << m2;
			cout << "* " << a << " = " << endl;

			result = m2.skalar(a);
			cout << result;
			//wynik.wyswietl();

			break;
		}
		case '6':
		{
			cmacierz m1, m2, product;
			m1.wymiary_mnozenia(m2);
			m1.losowe();

			product = m1.operator*(m2);
			cout << m1 << endl << " * " << endl << m2 << endl << " = " << endl << product;

			break;
		}
		case 'x':
		{
			cout << endl;
			cout << "The end." << endl;
			_sleep(500);
			return 0;
		}
		case 'X':
		{
			cout << endl;
			cout << "The end." << endl;
			_sleep(500);
			return 0;
		}

		default:
		{
			system("cls");
			cout << "Enter the number from 1 to 6 to take action or press x/X to end the program." << endl;
			break;
		}
		}

	}
	_getch();
	return 0;
}