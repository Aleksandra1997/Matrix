#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class cmacierz
{
private:
	vector<vector<int>> m_matrix;
	int nr_wierszy;
	int nr_kolumn;

public:
	void uzupelnij(int w, int k);
	void wyswietl();
	void losowe();
	void wymiar();
	void nowa(cmacierz &m1);
	void wymiary_mnozenia(cmacierz &m1);
	cmacierz skalar(int liczba);
	cmacierz operator+(const cmacierz &m1);
	cmacierz operator*(const cmacierz &m1);
	friend ostream& operator<<(ostream&wejscie, cmacierz& m2);
	friend istream& operator>>(istream&wyjscie, cmacierz& m2);
};