// lab88.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <cmath>
#include <iostream>

using namespace std; 
int main()
{
	// Упражнение 3(1)
	// 1 ВАРИАНТ ЗАПОЛНЕНИЯ
	cout << "Статический массив, индексная адресация: \n";
	int arr[10];
	for (int i = 0; i <= 9; i++) {
		arr[i] = pow(i, 2);
		cout << "Num(" << i << ") = " << arr[i] << endl;
	}
	// 2 ВАРИАНТ ЗАПОЛНЕНИЯ 
	int arr2[10];
	cout << "-----------------------------------------------------------------\n";
	cout << "Статический массив, адресация с помощью указателя: \n";
	int* ptr = arr2;
	for (int i = 0; i <= 9; i++) {
		*(ptr + i) = i*i;
		cout << "Num(" << i << ") = " << *(ptr+i) << endl;

	}
	// 3 ВАРИАНТ ЗАПОЛНЕНИЯ 
	cout << "-----------------------------------------------------------------\n";
	cout << "Динамический массив, индексная адресация: \n";
	int *arr3 = new int[10];
	for (int i = 0; i <= 9; i++) {
		arr3[i] = i * i;
		cout << "Num(" << i << ") = " << arr3[i] << endl;
	}
	delete[] arr3;
	// 4 ВАРИАНТ ЗАПОЛНЕНИЯ
	cout << "-----------------------------------------------------------------\n";
	cout << "Динамический массив, адресация с помощью указателя: \n";
	int* arr4 = new int[10];
	int* ptr1 = arr4;
	for (int i = 0; i <= 9; i++) {
		*(ptr1 + i) = i * i;
		cout << "Num(" << i << ") = " << *(ptr1+i) << endl;
	}
	delete[] arr4;
	cout << "-----------------------------------------------------------------\n";
	// УПРАЖНЕНИЕ 3(2)
	int size1 = 13;
	int size2 = 7; 
	int* mass1 = new int[size1];
	int* mass2 = new int[size2];
	// новый массив
	int* mass3 = new int[size1 + size2];
	
	cout << "Массив №1: ";
	for (int i = 0; i < size1; i++) {
		mass1[i] = i*2;
		cout << mass1[i] << " ";
	}
	cout << endl << endl;
	cout << "Массив №2: ";
	for (int i = 0; i < size2; i++) {
		*(mass2+i) = i*3+23;
		cout << mass2[i] << " ";
	}
	int i = 0; int  j = 0; int  k = 0;
	cout << endl;
	while (i < size1 && j < size2) {
		if (mass1[i] < *(mass2+j)) {
			mass3[k] = mass1[i];
			i++;
		}
		else {
			mass3[k] = *(mass2+ j);
			j++;
		}
		k++;
	}
	

// добавляем оставшиеся числа в массивах
	while (i < size1) {
		mass3[k] = mass1[i];
		i++;
		k++;
	}
	while (j < size2) {
		mass3[k] = *(mass2+j);
		j++;
		k++;
	}
	// вывод
	cout << endl << "Массивы после слияния: " << endl;
	for (int i = 0; i < (size1 + size2);i++) {
		cout << mass3[i] << " ";
	}
	cout << endl;
	delete[] mass1;
	delete[] mass2;
	delete[] mass3;
}
