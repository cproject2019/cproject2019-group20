// merge sort

#include "head.h"
#define NUM 10
int merge(int arr[], int start, int middle, int end)
{
	int n1 = middle - start + 1;
	int n2 = end - middle;
	int i, j, k;
	int *L = (int*)malloc((n1 + 1) * sizeof(int));
	int *R = (int*)malloc((n2 + 1) * sizeof(int));
	for (i = 0; i < n1; i++)
	{
		L[i] = arr[start + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = arr[middle + j + 1];
	}
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	i = 0;
	j = 0;
	for (k = start; k <= end; k++)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
	}
	free(L);
	free(R);
	L = NULL;
	R = NULL;
	return 0;
}

int mergeSort(int arr[], int start, int end)
{
	int middle = (start + end) / 2;
	if (start < end)
	{
		mergeSort(arr, start, middle);
		mergeSort(arr, middle + 1, end);
		merge(arr, start, middle, end);
	}
	return 0;
}

int scoreSort()
{

	int y[NUM];
	fopen_s(&fp1, "score.txt", "r");
	for (int x = 0; x < NUM; x++) 
		fscanf_s(fp1, "%d", &y[x]);
	mergeSort(y, 0, NUM - 1);
	fclose(fp1);
	for (int x = NUM-1; x >= 0; x--)
		printf("                       %d\n", y[x]);
	return 0;
}
