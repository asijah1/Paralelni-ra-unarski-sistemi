// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "stdio.h"
#include "stdlib.h"
#include <vector>
#include <iostream>
#include <omp.h>

//4core threads
int Thread1(std::vector<int> vector, int searchValue)
{
	int left = 0;
	int right = vector.size() - 1;

	while (right % 4 != 0)
	{
		right--;
	}

	int mid = (int)((right + left) / 2);

	while (mid % 4 != 0)
	{
		mid--;
	}

	while (left <= right)
	{
		if (searchValue == vector[mid])
		{
			return mid;
		}
		else if (vector[mid] > searchValue)
		{
			right = mid - 4; //4 threads -> 4 index search(therefore reduce it by 4)
			mid = (int)((right + left) / 2);
			while (mid % 4 != 0)
			{
				mid--;
			}
		}
		else
		{
			left = mid + 4;
			mid = (int)((right + left) / 2);
			while (mid % 4 != 0)
			{
				mid--;
			}
		}
	}
	return -1;
}

int Thread2(std::vector<int> vector, int searchValue)
{
	int left = 1;
	int right = vector.size() - 1;

	while (right % 4 != 1)
	{
		right--;
	}

	int mid = (int)((right + left) / 2);

	while (mid % 4 != 1)
	{
		mid--;
	}

	while (left <= right)
	{
		if (searchValue == vector[mid])
		{
			return mid;
		}
		else if (vector[mid] > searchValue)
		{
			right = mid - 4; //4 threads -> 4 index search(therefore reduce it by 4)
			mid = (int)((right + left) / 2);
			while (mid % 4 != 1)
			{
				mid--;
			}
		}
		else
		{
			left = mid + 4;
			mid = (int)((right + left) / 2);
			while (mid % 4 != 1)
			{
				mid--;
			}
		}
	}
	return -1;
}

int Thread3(std::vector<int> vector, int searchValue)
{
	int left = 2;
	int right = vector.size() - 1;

	while (right % 4 != 2)
	{
		right--;
	}

	int mid = (int)((right + left) / 2);

	while (mid % 4 != 2)
	{
		mid--;
	}

	while (left <= right)
	{
		if (searchValue == vector[mid])
		{
			return mid;
		}
		else if (vector[mid] > searchValue)
		{
			right = mid - 4; //4 threads -> 4 index search(therefore reduce it by 4)
			mid = (int)((right + left) / 2);
			while (mid % 4 != 2)
			{
				mid--;
			}
		}
		else
		{
			left = mid + 4;
			mid = (int)((right + left) / 2);
			while (mid % 4 != 2)
			{
				mid--;
			}
		}
	}
	return -1;
}

int Thread4(std::vector<int> vector, int searchValue)
{
	int left = 3;
	int right = vector.size() - 1;

	while (right % 4 != 3)
	{
		right--;
	}

	int mid = (int)((right + left) / 2);

	while (mid % 4 != 3)
	{
		mid--;
	}

	while (left <= right)
	{
		if (searchValue == vector[mid])
		{
			return mid;
		}
		else if (vector[mid] > searchValue)
		{
			right = mid - 4; //4 threads -> 4 index search(therefore reduce it by 4)
			mid = (int)((right + left) / 2);
			while (mid % 4 != 3)
			{
				mid--;
			}
		}
		else
		{
			left = mid + 4;
			mid = (int)((right + left) / 2);
			while (mid % 4 != 3)
			{
				mid--;
			}
		}
	}
	return -1;
}

//2core threads
int Thread21(std::vector<int> vector, int searchValue)
{
	int left = 0;
	int right = vector.size() - 1;

	while (right % 2 != 0)
	{
		right--;
	}

	int mid = (int)((right + left) / 2);

	while (mid % 2 != 0)
	{
		mid--;
	}

	while (left <= right)
	{
		if (searchValue == vector[mid])
		{
			return mid;
		}
		else if (vector[mid] > searchValue)
		{
			right = mid - 2; //2 threads -> 2 index search(therefore reduce it by 2)
			mid = (int)((right + left) / 2);
			while (mid % 2 != 0)
			{
				mid--;
			}
		}
		else
		{
			left = mid + 2;
			mid = (int)((right + left) / 2);
			if (mid % 2 != 0)
			{
				mid--;
			}
		}
	}
	return -1;
}

int Thread22(std::vector<int> vector, int searchValue)
{
	int left = 1;
	int right = vector.size() - 1;

	while (right % 2 != 1)
	{
		right--;
	}

	int mid = (int)((right + left) / 2);

	while (mid % 2 != 1)
	{
		mid--;
	}

	while (left <= right)
	{
		if (searchValue == vector[mid])
		{
			return mid;
		}
		else if (vector[mid] > searchValue)
		{
			right = mid - 2; //2 threads -> 2 index search(therefore reduce it by 2)
			mid = (int)((right + left) / 2);
			while (mid % 2 != 1)
			{
				mid--;
			}
		}
		else
		{
			left = mid + 2;
			mid = (int)((right + left) / 2);
			if (mid % 2 != 1)
			{
				mid--;
			}
		}
	}
	return -1;
}

//6core threads
int Thread31(std::vector<int> vector, int searchValue)
{
	int left = 0;
	int right = vector.size() - 1;

	while (right % 6 != 0)
	{
		right--;
	}

	int mid = (int)((right + left) / 2);

	while (mid % 6 != 0)
	{
		mid--;
	}

	while (left <= right)
	{
		if (searchValue == vector[mid])
		{
			return mid;
		}
		else if (vector[mid] > searchValue)
		{
			right = mid - 6; //6 threads -> 6 index search(therefore reduce it by 6)
			mid = (int)((right + left) / 2);
			while (mid % 6 != 0)
			{
				mid--;
			}
		}
		else
		{
			left = mid + 6;
			mid = (int)((right + left) / 2);
			while (mid % 6 != 0)
			{
				mid--;
			}
		}
	}
	return -1;
}

int Thread32(std::vector<int> vector, int searchValue)
{
	int left = 1;
	int right = vector.size() - 1;

	while (right % 6 != 1)
	{
		right--;
	}

	int mid = (int)((right + left) / 2);

	while (mid % 6 != 1)
	{
		mid--;
	}

	while (left <= right)
	{
		if (searchValue == vector[mid])
		{
			return mid;
		}
		else if (vector[mid] > searchValue)
		{
			right = mid - 6; //6 threads -> 6 index search(therefore reduce it by 6)
			mid = (int)((right + left) / 2);
			while (mid % 6 != 1)
			{
				mid--;
			}
		}
		else
		{
			left = mid + 6;
			mid = (int)((right + left) / 2);
			while (mid % 6 != 1)
			{
				mid--;
			}
		}
	}
	return -1;
}

int Thread33(std::vector<int> vector, int searchValue)
{
	int left = 2;
	int right = vector.size() - 1;

	while (right % 6 != 2)
	{
		right--;
	}

	int mid = (int)((right + left) / 2);

	while (mid % 6 != 2)
	{
		mid--;
	}

	while (left <= right)
	{
		if (searchValue == vector[mid])
		{
			return mid;
		}
		else if (vector[mid] > searchValue)
		{
			right = mid - 6; //6 threads -> 6 index search(therefore reduce it by 6)
			mid = (int)((right + left) / 2);
			while (mid % 6 != 2)
			{
				mid--;
			}
		}
		else
		{
			left = mid + 6;
			mid = (int)((right + left) / 2);
			while (mid % 6 != 2)
			{
				mid--;
			}
		}
	}
	return -1;
}

int Thread34(std::vector<int> vector, int searchValue)
{
	int left = 3;
	int right = vector.size() - 1;

	while (right % 6 != 3)
	{
		right--;
	}

	int mid = (int)((right + left) / 2);

	while (mid % 6 != 3)
	{
		mid--;
	}

	while (left <= right)
	{
		if (searchValue == vector[mid])
		{
			return mid;
		}
		else if (vector[mid] > searchValue)
		{
			right = mid - 6; //6 threads -> 6 index search(therefore reduce it by 6)
			mid = (int)((right + left) / 2);
			while (mid % 6 != 3)
			{
				mid--;
			}
		}
		else
		{
			left = mid + 6;
			mid = (int)((right + left) / 2);
			while (mid % 6 != 3)
			{
				mid--;
			}
		}
	}
	return -1;
}

int Thread35(std::vector<int> vector, int searchValue)
{
	int left = 4;
	int right = vector.size() - 1;

	while (right % 6 != 4)
	{
		right--;
	}

	int mid = (int)((right + left) / 2);

	while (mid % 6 != 4)
	{
		mid--;
	}

	while (left <= right)
	{
		if (searchValue == vector[mid])
		{
			return mid;
		}
		else if (vector[mid] > searchValue)
		{
			right = mid - 6; //6 threads -> 6 index search(therefore reduce it by 6)
			mid = (int)((right + left) / 2);
			while (mid % 6 != 4)
			{
				mid--;
			}
		}
		else
		{
			left = mid + 6;
			mid = (int)((right + left) / 2);
			while (mid % 6 != 4)
			{
				mid--;
			}
		}
	}
	return -1;
}

int Thread36(std::vector<int> vector, int searchValue)
{
	int left = 5;
	int right = vector.size() - 1;

	while (right % 6 != 5)
	{
		right--;
	}

	int mid = (int)((right + left) / 2);

	while (mid % 6 != 5)
	{
		mid--;
	}

	while (left <= right)
	{
		if (searchValue == vector[mid])
		{
			return mid;
		}
		else if (vector[mid] > searchValue)
		{
			right = mid - 6; //6 threads -> 6 index search(therefore reduce it by 6)
			mid = (int)((right + left) / 2);
			while (mid % 6 != 5)
			{
				mid--;
			}
		}
		else
		{
			left = mid + 6;
			mid = (int)((right + left) / 2);
			while (mid % 6 != 5)
			{
				mid--;
			}
		}
	}
	return -1;
}

int main()
{
	//randomized sorted vector/array
	std::vector<int> vector1, vector2, vector3, vector4, vector;

	int first, second, third, fourth, first2, second2, first3, second3, third3, fourth3, fifth3, sixth3;
	int n = 3250; //searchValue        great speedup for value 2
	int nMax = 10000000; //size of vector
	for (int i = 0; i <= nMax; i++)
	{
		vector.push_back(i);
	}

	double time1, time2, time3, time4, stime1, stime2, stime3, stime4, time21, stime21, time22, stime22, time31, time32, time33, time34, time35, time36, stime31, stime32, stime33, stime34, stime35, stime36;

#pragma omp parallel sections
	{
#pragma omp section
		{
			stime1 = omp_get_wtime();
			first = Thread1(vector, vector[n]);
			time1 = omp_get_wtime() - stime1;
		}
#pragma omp section
		{
			stime2 = omp_get_wtime();
			second = Thread2(vector, vector[n]);
			time2 = omp_get_wtime() - stime2;
		}
#pragma omp section
		{
			stime3 = omp_get_wtime();
			third = Thread3(vector, vector[n]);
			time3 = omp_get_wtime() - stime3;
		}
#pragma omp section
		{
			stime4 = omp_get_wtime();
			fourth = Thread4(vector, vector[n]);
			time4 = omp_get_wtime() - stime4;
		}
	}

	if (first != -1)
		std::cout << "Thread1 returned: " << first << "\nExecution time of 4-core parallel congruent Binary Search " << time1;
	if (second != -1)
		std::cout << "Thread2 returned: " << second << "\nExecution time of 4-core parallel congruent Binary Search " << time2;
	if (third != -1)
		std::cout << "Thread3 returned: " << third << "\nExecution time of 4-core parallel congruent Binary Search " << time3;
	if (fourth != -1)
		std::cout << "Thread4 returned: " << fourth << "\nExecution time of 4-core parallel congruent Binary Search " << time4;

	std::cout << std::endl;
#pragma omp parallel sections
	{
#pragma omp section
		{
			stime21 = omp_get_wtime();
			first2 = Thread21(vector, vector[n]);
			time21 = omp_get_wtime() - stime1;
		}
#pragma omp section
		{
			stime22 = omp_get_wtime();
			second2 = Thread22(vector, vector[n]);
			time22 = omp_get_wtime() - stime2;
		}
	}
	if (first2 != -1)
		std::cout << "Thread21 returned: " << first2 << "\nExecution time of 2-core parallel congruent Binary Search " << time21;
	if (second2 != -1)
		std::cout << "Thread22 returned: " << second2 << "\nExecution time of 2-core parallel congruent Binary Search " << time22;
	std::cout << std::endl;

#pragma omp parallel sections
	{
#pragma omp section
		{
			stime31 = omp_get_wtime();
			first3 = Thread31(vector, vector[n]);
			time31 = omp_get_wtime() - stime31;
		}
#pragma omp section
		{
			stime32 = omp_get_wtime();
			second3 = Thread32(vector, vector[n]);
			time32 = omp_get_wtime() - stime32;
		}
#pragma omp section
		{
			stime33 = omp_get_wtime();
			third3 = Thread33(vector, vector[n]);
			time33 = omp_get_wtime() - stime33;
		}
#pragma omp section
		{
			stime34 = omp_get_wtime();
			fourth3 = Thread34(vector, vector[n]);
			time34 = omp_get_wtime() - stime34;
		}
#pragma omp section
		{
			stime35 = omp_get_wtime();
			fifth3 = Thread35(vector, vector[n]);
			time35 = omp_get_wtime() - stime35;
		}
#pragma omp section
		{
			stime36 = omp_get_wtime();
			sixth3 = Thread36(vector, vector[n]);
			time36 = omp_get_wtime() - stime36;
		}
	}

	if (first3 != -1)
		std::cout << "Thread31 returned: " << first3 << "\nExecution time of 6-core parallel congruent Binary Search " << time31;
	if (second3 != -1)
		std::cout << "Thread32 returned: " << second3 << "\nExecution time of 6-core parallel congruent Binary Search " << time32;
	if (third3 != -1)
		std::cout << "Thread33 returned: " << third3 << "\nExecution time of 6-core parallel congruent Binary Search " << time33;
	if (fourth3 != -1)
		std::cout << "Thread34 returned: " << fourth3 << "\nExecution time of 6-core parallel congruent Binary Search " << time34;
	if (fifth3 != -1)
		std::cout << "Thread35 returned: " << fifth3 << "\nExecution time of 6-core parallel congruent Binary Search " << time35;
	if (sixth3 != -1)
		std::cout << "Thread36 returned: " << sixth3 << "\nExecution time of 6-core parallel congruent Binary Search " << time36;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file