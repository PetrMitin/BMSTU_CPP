﻿// sem1.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>;
#include <cstdlib>;
using namespace std;

int sumRec(int n) 
{
	if (n > 0) return n + sumRec(n - 1);
	else return 0;
}

void printStars(int n, int counter)
{
	for (int i = 1; i <= n - abs(n - counter); i++) printf("*");
	printf("\n");
	if (2 * n >= counter) printStars(n, counter + 1);
}

int main()
{
	int n;
	//printf("Enter n \n");
	//scanf_s("%i", &n);
	//printf("%i", sumRec(n));
	scanf_s("%i", &n);
	printStars(n, 1);
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
