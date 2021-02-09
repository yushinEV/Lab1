#pragma once
#include <iostream>
#include <stdexcept>
#include <chrono>
using namespace std;
class char_arr
{
	char* char_ar;
	size_t sizee;
public:
	char_arr(size_t size)
	{
		if (size == 0)
			throw out_of_range("Incorrect size!\n");
		char_ar = new char[size];
		sizee = size;
		for (int i = 0; i < sizee; i++)
		{
			char_ar[i] = rand() % sizee;
			char_ar[i] *= pow(-1, rand() % 2);
		}
	}
	bool sorted()
	{
		for (int i = 0; i < (sizee - 1); i++)
		{
			if (char_ar[i] > char_ar[i + 1])
				return false;
		}
		return true;
	}
	void CountingSort()
	{
		int i;
		int max = char_ar[0];
		int min = char_ar[0];
		int* tmp_arr = nullptr;
		int* tmp_arr2 = nullptr;
		for (i = 1; i < sizee; i++)
		{
			if (char_ar[i] > max)
				max = char_ar[i];
			else if (char_ar[i] < min)
				min = char_ar[i];
		}
		if (max >= 0)
		{
			tmp_arr = new int[max + 1];
			for (i = 0; i <= max; i++)
				tmp_arr[i] = 0;
		}
		if (min < 0)
		{
			tmp_arr2 = new int[min * (-1) + 1];
			for (i = 0; i <= (min * (-1)); i++)
				tmp_arr2[i] = 0;
		}
		for (i = 0; i < sizee; i++)
		{
			if (char_ar[i] < 0)
				tmp_arr2[char_ar[i] * (-1)]++;
			else
				tmp_arr[char_ar[i]]++;
		}
		int j = 0;
		if (min < 0)
		{
			for (i = (min * (-1)); i > 0; i--)
			{
				while (tmp_arr2[i] != 0)
				{
					char_ar[j] = i * (-1);
					j++;
					tmp_arr2[i]--;
				}
			}
			delete[] tmp_arr2;
		}
		if (max >= 0)
		{
			for (i = 0; i <= max; i++)
			{
				while (tmp_arr[i] != 0)
				{
					char_ar[j] = i;
					j++;
					tmp_arr[i]--;
				}
			}
			delete[] tmp_arr;
		}
	}
	void print_to_console()
	{
		for (int i = 0; i < sizee; i++)
		{
			cout << char_ar[i] << ' ';
		}
		cout << endl;
	}
	~char_arr()
	{
		delete[] char_ar;
	}
};
class Array
{
	int* int_ar;
	size_t sizee;
	void QuickSort(int first, int last)
	{
		int middle = last;
		int temp, i, j;
		for (i = first; i < middle; i++)
		{
			if (int_ar[i] > int_ar[middle])
			{
				for (j = i; j < middle; j++)
				{
					temp = int_ar[j];
					int_ar[j] = int_ar[j + 1];
					int_ar[j + 1] = temp;
				}
				middle--;
				i--;
			}
		}
		if (first < (middle - 1))
			QuickSort(first, middle - 1);
		if ((middle + 1) < last)
			QuickSort(middle + 1, last);
	}
	int BinarySearch(int left, int right, int elem)
	{
		if (left > right)
			return -1;
		size_t mid = ((right - left) / 2) + left;
		size_t answerr;
		if (int_ar[mid] == elem)
			answerr = mid;
		else if (int_ar[mid] < elem)
			answerr = BinarySearch(mid + 1, right, elem);
		else
			answerr = BinarySearch(left, mid - 1, elem);
		return answerr;
	}
public:
	Array(size_t size)
	{
		if (size == 0)
			throw out_of_range("Incorrect size!\n");
		int_ar = new int[size];
		sizee = size;
		for (int i = 0; i < sizee; i++)
		{
			int_ar[i] = rand() % sizee;
			int_ar[i] *= pow(-1, rand() % 2);
		}
	}
	int getelem(size_t index)
	{
		if (index >= sizee)
			throw out_of_range("Index is bigger than size of array!\n");
		return int_ar[index];
	}
	bool sorted()
	{
		for (int i = 0; i < (sizee - 1); i++)
		{
			if (int_ar[i] > int_ar[i + 1])
				return false;
		}
		return true;
	}
	size_t BiniarySearch(int search)
	{
		if (!sorted())
			throw runtime_error("Array must be sorted!\n");
		if (search<int_ar[0] || search>int_ar[sizee - 1])
			throw runtime_error("There is no element!\n");
		int index = BinarySearch(0, sizee - 1, search);
		if (index < 0)
			throw runtime_error("There is no element!\n");
		return index;
	}
	void QuickSort()
	{
		QuickSort(0, sizee - 1);
	}
	void InsertionSort()
	{
		int key;
		for (int i = 0; i < sizee - 1; i++)
		{
			key = int_ar[i + 1];
			for (int j = i; j >= 0; j--)
			{
				if (key < int_ar[j])
				{
					int_ar[j + 1] = int_ar[j];
					int_ar[j] = key;
				}
				else
				{
					break;
				}
			}
		}
	}
	void BogoSort()
	{
		int temp;
		int index;
		for (int i = 0; i < sizee; i++)
		{
			temp = int_ar[i];
			index = rand() % sizee;
			int_ar[i] = int_ar[index];
			int_ar[index] = temp;
		}
		if (!sorted())
		{
			BogoSort();
		}
	}
	void print_to_console()
	{
		for (int i = 0; i < sizee; i++)
		{
			cout << int_ar[i] << ' ';
		}
		cout << endl;
	}
	~Array()
	{
		delete[] int_ar;
	}
};