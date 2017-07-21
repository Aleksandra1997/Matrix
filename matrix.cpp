#include "matrix.h"

void cmacierz::losowe()
{
	srand(time(NULL));

	for (int i = 0; i < nr_wierszy; i++)
	{
		vector<int>wiersze;
		for (int j = 0; j < nr_kolumn; j++)
		{
			wiersze.push_back(rand() % 10);
		}
		m_matrix.push_back(wiersze);
	}
	cout << endl;
}

void cmacierz::wymiar()
{
	cout << "Enter the number of rows: " << endl;
	cin >> this->nr_wierszy;
	cout << "Enter the number of columns: " << endl;
	cin >> this->nr_kolumn;
}

void cmacierz::nowa(cmacierz &m1)
{
	m1.wymiar();
	this->nr_wierszy = m1.nr_wierszy;
	this->nr_kolumn = m1.nr_kolumn;
	m1.uzupelnij(m1.nr_wierszy, m1.nr_kolumn);
}

void cmacierz::wymiary_mnozenia(cmacierz &m1)
{
	m1.wymiar();
	m1.losowe();
	this->nr_kolumn = m1.nr_wierszy;

	this->nr_wierszy = rand() % 6;
	cout << "Dimensions of the first matrix are " << m1.nr_wierszy << " x " << m1.nr_kolumn <<
		" and the second one's dimensions are " << nr_wierszy << " x " << nr_kolumn << endl;
}

cmacierz cmacierz::skalar(int liczba)
{
	cmacierz result;
	result.uzupelnij(nr_wierszy, nr_kolumn);

	for (int i = 0; i < nr_wierszy; i++)
	{
		for (int j = 0; j < nr_kolumn; j++)
		{
			result.m_matrix[i][j] = this->m_matrix[i][j] * liczba;
		}
	}
	return result;
}

void cmacierz::uzupelnij(int w, int k)
{
	this->nr_kolumn = k;
	this->nr_wierszy = w;

	for (int i = 0; i < nr_wierszy; i++)
	{
		vector<int> wiersz;
		for (int j = 0; j < nr_kolumn; j++)
		{
			wiersz.push_back(i + 1 + j);
			cout << "\t";
		}
		m_matrix.push_back(wiersz);
	}
	cout << endl;
}

void cmacierz::wyswietl()
{
	for (int i = 0; i < nr_wierszy; i++)
	{
		cout << "[ ";
		for (int j = 0; j < nr_kolumn; j++)
		{
			if (m_matrix[i][j] < 10)
			{
				cout << " ";
			}
			cout << m_matrix[i][j] << " ";
		}
		cout << "]" << endl;
	}
}

cmacierz cmacierz::operator+(const cmacierz &m1)
{
	cmacierz result;
	result.uzupelnij(nr_wierszy, nr_kolumn);

	if ((this->nr_wierszy == m1.nr_wierszy) && (this->nr_kolumn == m1.nr_kolumn))
	{
		for (int i = 0; i < m1.nr_wierszy; i++)
		{
			for (int j = 0; j < m1.nr_kolumn; j++)
			{
				result.m_matrix[i][j] = this->m_matrix[i][j] + m1.m_matrix[i][j];
			}
		}
	}
	else
	{
		cout << "Nieprawidlowe wymiary macierzy" << endl;
	}
	return result;
}

cmacierz cmacierz::operator*(const cmacierz &m1)
{
	cmacierz result;
	result.uzupelnij(nr_wierszy, m1.nr_kolumn);

	if (this->nr_kolumn == m1.nr_wierszy)
	{
		for (int i = 0; i < this->nr_wierszy; i++)
		{
			for (int j = 0; j < m1.nr_kolumn; j++)
			{
				result.m_matrix[i][j] = 0;
				for (int k = 0; k < this->nr_kolumn; k++)
				{
					result.m_matrix[i][j] = result.m_matrix[i][j] + this->m_matrix[i][k] * m1.m_matrix[k][j];
				}
			}
		}
	}
	else
	{
		cout << "Nieprawidlowe wymiary macierzy" << endl;
	}

	return result;
}

istream& operator>>(istream&wejscie, cmacierz& m2)
{
	for (int i = 0; i < m2.nr_wierszy; i++)
	{
		vector<int>wiersze;
		for (int j = 0; j < m2.nr_kolumn; j++)
		{
			int a;
			cout << "Enter the number you want to put on the place with its cordinates as: " << i << ", " << j << endl;
			wejscie >> a;
			wiersze.push_back(a);
		}
		m2.m_matrix.push_back(wiersze);
	}
	return wejscie;
}

ostream& operator<<(ostream&wyjscie, cmacierz& m2)
{
	for (int i = 0; i < m2.nr_wierszy; i++)
	{
		wyjscie << "[ ";
		for (int j = 0; j < m2.nr_kolumn; j++)
		{
			if (m2.m_matrix[i][j] < 10)
			{
				wyjscie << " ";
			}
			wyjscie << m2.m_matrix[i][j] << " ";
		}
		wyjscie << "]" << endl;
	}
	return wyjscie;
}