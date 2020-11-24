#pragma once

#include <string>
#include <iostream>
#include <cmath>

using namespace std;

template <class T>
class F_rectangle
{
private:
	int N;
	T h;
	T arrX[100];
	T arrY[100];
	T a, b;

	int num1 = NULL, num2 = NULL, numX = NULL, numsin = NULL;
public:
	T myH() { return (h = (b - a) / N); }
	void myX();

	void setA(T a) { this->a = a; }
	void setB(T b) { this->b = b; }
	void setN(int N) { this->N = N; }
	void setF(string x);
	void setY();

	void func(T a1, T b1, int N, string x1);
};

template<class T>
inline void F_rectangle<T>::myX()
{
	for (int i = 0; i < N + 1; i++) {
		arrX[i] = a + i * myH();
	}
}

template<class T>
inline void F_rectangle<T>::setF(string x)
{
	int k = 0;
	bool plus = true;
	for (int i = 0; i < x.size(); ) {
		if (x[i] == '-') { plus = false; i++; }
		else if (x[i] == '+') { plus = true; i++; }
		while (x[i] != '+' && x[i] != '-' && x[i] != '*' && x[i] != '/' && x[i] != 'x' && i < x.size() && x[i] != 's' && x[i] != 'c') {
			num1 *= 10;
			num1 += int(x[i]) - 48;
			i++;
		}


		if (x[i] == 's') {
			if (x[i + 1] == 'i')
				if (x[i + 2] == 'n')
					if (x[i + 3] == '(') {
						i += 4;
						while (x[i] != 'x' || x[i] != ')') {
							num1 *= 10;
							num1 += int(x[i]) - 48;
							i++;
						}
						if (x[i] == 'x') {
							if (plus == false) num1 *= -1;
							numsin += num1;
							i++;
						}
						else {
							if (plus == false) num1 *= -1;
							num2 += sin(num1);
						}
					}
			continue;
		}
	

		if (x[i] == 'x') {
			if (plus == false) num1 *= -1;
			numX += num1;
			i++;
		}
		else {
			if (plus == false) num1 *= -1;
			num2 += num1;
		}
		num1 = NULL;
		plus = true;
	}
}

template<class T>
inline void F_rectangle<T>::setY()
{
for (int i = 0; i < N + 1; i++) {
	arrY[i] = numX * arrX[i] + num2;
}
}

template<class T>
inline void F_rectangle<T>::func(T a1, T b1, int N, string x1)
{
	T rez = 0;

	setA(a1);
	setB(b1);
	setN(N);
	T h = myH();
	setF(x1);
	myX();
	setY();
	int newN = (int)N;
	T y_last = (arrY[0] + arrY[newN]) / 2;
	for (int i = 1; i < N; i++) {
		y_last += arrY[i];
	}
	y_last *= h;
	rez = y_last;
	cout << "rezultat: " << rez << endl;
}
