/* 
 *Author		:	Ashish Kumar
 *Date Created	:	17April2010
 *Last Modified	:	17April2010
 *Descrition	:	Prints the pascal triangle.
 */

#include <iostream>
#include <conio.h>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

void Pascal(int num);
void Display (int num, int **memPtr);

int main(int argc , char* argv[])
{
	system("TITLE Pascal Triangle");
	int num = 0;
	if(argc != 2)
	{
		cout << " Enter the value to which the triangle is to be printed."
		 << endl;
		cin >> num;
	}
	else
		num = atoi(argv[1]);
	Pascal(num);
	return 0;
}

void Pascal(int num)
{
	int **memPtr = new int *[num];
	int i = 0, j = 0;
	for(i = 1; i <= num; i++)
	{
		*(memPtr + i - 1)  = new int[i];
		for(j = 1; j <= i; j++)
		{
			if(j == 1)
				*(*(memPtr + i - 1) + j - 1) = 1;
			else if(j == i)
				*(*(memPtr + i - 1) + j - 1) = 1;
			else if(j != i)
				*(*(memPtr + i - 1) + j - 1) = *(*(memPtr + i - 2) + j - 2) + *(*(memPtr + i - 2) + j - 1);		
		}
	}

	Display(num, memPtr);
	for(i = 0; i < num ; i++)
	{
			delete []memPtr[i];
	}
	delete []memPtr;
}

void Display(int num, int **memPtr)
{
	for(int i = 0; i < num; i++)
	{
		std::cout << endl;
		for(int a = 0; a < num; a++)
			cout << " ";
		for(int j = 0; j <= i ; j++)
		{
			cout << setw(4) << *(*(memPtr + i) + j);
		}
	}
}
