#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RESET "\033[0m"
#define RED "\033[1;31m"

int BinarSearchForInsert (int count, int* arr, int value);
void BinarInsertSort (int size, int* arr);
void PrintArr(int size, int* arr);

int main()
{
	srand(time(0));
	int N = 0;
    printf("Введіть кількість елементів масиву:");
    scanf("%i",&N);
	int arr[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand()%51 - 10;
	}
	PrintArr (N, arr);
	BinarInsertSort(N, arr);
	puts("");
	PrintArr (N, arr);
	return 0;
}

void PrintArr(int size, int* arr)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= size/2)
		{
			printf("%s%i%s ",RED, arr[i], RESET);
		}              
		else printf("%i ", arr[i]);
	}
	puts("");
}

int BinarSearchForInsert (int x, int* arr, int value)
{
    if (x == 0 || value > arr[0]) return 0;
    if (value <= arr[x-1]) return x;
	int low = x - 1;
	int high = 0;
	while (low - high != 1)
	{
		int mid = (low + high)/2;
		if (arr[mid] >= value )
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
	}
    return low;
}

void BinarInsertSort (int size, int* arr)
{
    int x  = 0;
	for (int i = 0; i < size; i++)
	{
        if (arr[i] < size/2)
        {
            int buffer = arr[i];
            int index = BinarSearchForInsert(x, arr, arr[i]);
            if (i != index)
            {
                for (int j = i; j > index; j--)
                {
                    arr[j] = arr [j-1];
                }
                arr[index] = buffer;
            }
            x++;
        }
	}
}