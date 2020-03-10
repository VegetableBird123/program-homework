#include<stdio.h>
#pragma warning(disable:4996) 
void add();//矩阵加法
void min();//矩阵减法
int main(void)
{
	int a;
	printf("Please chose the numbers to caculate\n");
	printf("*********************************\n");
	printf("* 1 *     matrix addition       *\n");
	printf("* 2 *     matrix subtraction    *\n");
	printf("* 3 *     inverse matrix        *\n");
	printf("* 4 *     rank of matrix        *\n");
	printf("*********************************\n");
	scanf("%d", &a);
	if (a == 1)
	{
		printf("WARN:Please confirm whether the matrices are of the same type\n");
		printf("Otherwise, the program will be terminated.\n");
		add();
	}
	else if (a == 2)
	{
		printf("WARN:Please confirm whether the matrices are of the same type\n");
		min();
	}

}
void add()
{
	int m, n, i, j;//两个矩阵的行数和列数
	int a, b;//用于循环输入矩阵的整型数
	int num1, num2;

	printf("please enter two numbers for the first matrix's row and column");
	scanf("%d", &m);
	scanf("%d", &n);
	printf("please enter two numbers for the second matrix's row and column");
	scanf("%d", &i);
	scanf("%d", &j);
	if (m != i || n != j)
		exit(1);

	num1 = m;
	num2 = n;

	int matrix_tem[20][20];
	int matrix1[20][20];
	int matrix2[20][20];

	printf("please input the first matrix");
	for (a = 0; a < m; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < n; b++)
			scanf("%d", &matrix1[m][n]);
	}

	printf("please input the second matrix");
	for (a = 0; a < i; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < j; b++)
			scanf("%d", &matrix2[i][j]);
	}

	for (a = 0; a < num1; a++)
		for (b = 0; b < num2; b++)
		{
			matrix_tem [num1][num2]= matrix1[num1][num2] + matrix2[num1][num2];
		}
	printf("The result :\n");
	for (a = 0; a < num1; a++)
	{
		if (a != 0)
			printf("\n");
		for (b = 0; b < num2; b++)
			printf("%4d", matrix_tem[num1][num2]);
	}
}

void min()
{
	int m, n, i, j;//两个矩阵的行数和列数
	int a, b;//用于循环输入矩阵的整型数
	int num1, num2;

	printf("please enter two numbers for the first matrix's row and column");
	scanf("%d", &m);
	scanf("%d", &n);
	printf("please enter two numbers for the second matrix's row and column");
	scanf("%d", &i);
	scanf("%d", &j);

	num1 = m;
	num2 = n;

	int matrix_tem[20][20];
	int matrix1[20][20];
	int matrix2[20][20];

	printf("please input the first matrix");
	for (a = 0; a < m; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < n; b++)
			scanf("%d", &matrix1[m][n]);
	}

	printf("please input the second matrix");
	for (a = 0; a < i; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < j; b++)
			scanf("%d", &matrix2[i][j]);
	}

	for (a = 0; a < num1; a++)
		for (b = 0; b < num2; b++)
		{
			matrix_tem[num1][num2] = matrix1[num1][num2] - matrix2[num1][num2];
		}
	printf("The result :\n");
	for (a = 0; a < num1; a++)
	{
		if (a != 0)
			printf("\n");
		for (b = 0; b < num2; b++)
			printf("%d", matrix_tem[num1][num2]);
	}
}