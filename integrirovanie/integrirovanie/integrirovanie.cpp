// integrirovanie.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include "F_rectangle.h"

int main()
{
    string x;
    float a = 0, b = 0, N = 0;
    //intTrap f1;
    F_rectangle<float> f;
    cout << "Vvedite formulu f(x): ";
    cin >> x;
    cout << endl;
    cout << "Vvedite nijnyuu granizu integrirovaniya: ";
    cin >> a;
    cout << endl;
    cout << "Vvedite verhnyuu granizu integrirovaniya: ";
    cin >> b;
    cout << endl;
    cout << "Vvedite kol-vo otrezkov razbieniya: ";
    cin >> N;
    cout << endl;
    f.func(a, b, N, x);
    
}
