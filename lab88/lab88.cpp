// lab88.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <cmath>
#include <iostream>

using namespace std; 
void summa(int& a, int* b, int c);
struct spisok {
	int data;
	spisok* next;
	spisok* back;
};
int main()
{
	// Упражнение 3(1)
	// 1 ВАРИАНТ ЗАПОЛНЕНИЯ
	cout << "3 УПРАЖНЕНИЕ(1) \n";
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
	cout << "3 УПРАЖНЕНИЕ(2) \n";
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

	cout << "-----------------------------------------------------------------\n";
	cout << "4 УПРАЖНЕНИЕ\n";
	// ЗАДАНИЕ 4 
	spisok* head;
	spisok* posled;  // указатели
	spisok* current;
	head = new spisok;
	head->data = 1; // 1 элемент списка
	head->next = nullptr; // следующий пока пустой 
	head->back = nullptr; // предыдущий тоже
	posled = head;
	current = head;
	// Создаём с 2 - 10 
	for (int i = 2; i <= 10; i++) {
		spisok* newc = new spisok;
		newc->data = i;
		newc->next = nullptr;

		newc->back = current;
		current->next = newc;

		current = newc;
		posled = newc;
	}
		cout << "Вывод списка от 1 до 10: ";
		current = head;
		while (current != nullptr) {
			cout << current->data << " | ";
			current = current->next;
	}
		cout << endl << endl;

// 2 Упражнение 2 задание
		cout << "-----------------------------------------------------------------\n";
		cout << "2 УПРАЖНЕНИЕ\n";
		cout << endl;
		cout << "Введите a,b,c: ";
		int a, b, c;
		cin >> a >> b >> c; 
		summa(a, &b, c);
		cout << " A: " << a;
		cout << " B: " << b; 


}
// 2 УПРАЖНЕНИЕ 2 ЗАДАНИЕ
void summa(int& a, int* b, int c) {
	a = a + c;
	*b = *b + c;
}