﻿#include <iostream>
//#include <cstdio>

//Вычислить i-ое число Фибоначчи через быстрое возведение в степень специально подобранной матрицы 2 на 2.
//Требуемая сложность O(log i). Рекурсивный и нерекурсивный варианты.
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    int M[2][2] = { {1, 1}, {1, 0} };
    int F[2][2] = { {1, 1}, {1, 0} };

    for (int i = 2; i <= n - 1; n++)
    {
        int a11 = F[0][0] * M[0][0] + F[0][1] * M[1][0];
        int a12 = F[0][0] * M[0][1] + F[0][1] * M[1][1];
        int a21 = F[0][0] * M[0][1] + F[0][1] * M[1][1];
        int a22 = F[1][0] * M[0][1] + F[1][1] * M[1][1];

        F[0][0] = a11;
        F[0][1] = a12;
        F[1][0] = a21;
        F[1][1] = a22;
    }
    cout << F[0][0] << endl;
    return 0;
}

/*
void matrix(int F[2][2], int M[2][2])
{
    int a11 = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int a12 = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int a21 = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int a22 = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = a11;
    F[0][1] = a12;
    F[1][0] = a21;
    F[1][1] = a22;
}

void pow(int F[2][2], int n)
{
    int i;
    int M[2][2] = { {1, 1}, {1, 0} };
    for (i = 2; i <= n; i++)
        matrix(F, M);
}

int fib(int n)
{
    int F[2][2] = { {1, 1}, {1, 0} };
    if (n == 0)
        return 0;
    pow(F, n - 1);
    return F[0][0];
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
