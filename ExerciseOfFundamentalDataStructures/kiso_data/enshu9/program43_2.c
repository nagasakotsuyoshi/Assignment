#include<stdio.h>
#include<stdlib.h>

/*
void select_sort(int *x, int n)
{
	int i, j, index, tmp;
	for(i = 0; i < n - 1; i++)
	{
		index = i;
		for(j = i + 1; j < n; j++)if(x[index] > x[j])index = j;
		tmp = x[i];
		x[i] = x[index];
		x[index] = tmp;
	}
}
*/

/*
void select_sort(int *x, int n)
{
	int i, j, low_index, low_data, tmp;
	for(i = 0; i < n - 1; i++)
	{
		low_data = x[i];
		low_index = i;
		for(j = i + 1; j < n; j++)if(low_data > x[j])
		{
			low_data = x[j];
			low_index = j;
		}
		tmp = x[i];
		x[i] = x[low_index];
		x[low_index] = tmp;
	}
}
*/

void bubble_sort_process(int *x, int n)
{
	int k;
	for(k = 0; k < n; k++){
		printf("%d ", x[k]);
	}
	printf("\n");
}

void bubble_sort(int *x, int n)
{
	int i, j, tmp;
	for(i = 0; i < n - 1; i++)
	{
		printf("i = %d\n", i);
		for(j = n - 1; j > i; j--)
		{
		printf("j = %d\n", j);
			if(x[j] < x[j - 1])
			{
				tmp = x[j];
				x[j] = x[j - 1];
				x[j - 1] = tmp;
			}
		bubble_sort_process(x, n);
		}
	}
}

int main(int argc, char *argv[])
{
	int i, x[100], n;
	n = atoi(argv[1]);
	for(i = 0; i < n; i++)scanf("%d", x+i);
	//select_sort(x, n);
	bubble_sort(x, n);
	printf("sort\n");
	for(i = 0; i < n; i++)printf("%d\n",x[i]);
	return EXIT_SUCCESS;	
}
