#include "Func.h"
#include <iostream>
#include <stdexcept>
#include <chrono>
using namespace std;
int main()
{
	Array Arr(5);
	Arr.print_to_console();
	Arr.InsertionSort();
	Arr.print_to_console();
	for (int i = 0; i < 10; i++)
	{
		int length = 1000;
		Array ar(length);
		chrono::system_clock::time_point begin = chrono::system_clock::now();
		ar.QuickSort();
		chrono::system_clock::time_point end = chrono::system_clock::now();
		chrono::duration<double> sec = end - begin;
		cout << "Sorting durates for " << sec.count() << " seconds" << endl << endl;
	}
}