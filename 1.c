#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996) 
void add();//矩阵加法
void sub();//矩阵减法
void mul();//矩阵乘法
int main(void)
{
	int a;
	printf("Please chose the numbers to caculate\n");
	printf("*********************************\n");
	printf("* 1 *     matrix addition       *\n");
	printf("* 2 *     matrix subtraction    *\n");
	printf("* 3 *     inverse matrix        *\n");
	printf("* 4 *     rank of matrix        *\n");
	printf("* 5 *     matrix multiplication *\n");
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
		sub();
	}
	else if (a == 5)
	{
		printf("Please confirm whether the matrix row-column relationship is reasonable\n");
		mul();
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
			scanf("%d", &matrix1[a][b]);
	}

	printf("please input the second matrix");
	for (a = 0; a < i; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < j; b++)
			scanf("%d", &matrix2[a][b]);
	}

	for (a = 0; a < num1; a++)
		for (b = 0; b < num2; b++)
		{
			matrix_tem[num1][num2] = matrix1[num1][num2] + matrix2[num1][num2];
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

void sub()
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
			scanf("%d", &matrix1[a][b]);
	}

	printf("please input the second matrix");
	for (a = 0; a < i; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < j; b++)
			scanf("%d", &matrix2[a][b]);
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
void mul()
{
	int m, n, i, j;//两个矩阵的行数和列数
	int a, b, c;//用于循环输入矩阵的整型数
	int num1, num2;

	printf("please enter two numbers for the first matrix's row and column");
	scanf("%d", &m);
	scanf("%d", &n);
	printf("please enter two numbers for the second matrix's row and column");
	scanf("%d", &i);
	scanf("%d", &j);

	num1 = m;
	num2 = j;

	if (n != i)
		exit(1);

	int matrix_tem1[20][20];
	int matrix_tem2[20][20];
	int matrix1[20][20];
	int matrix2[20][20];

	printf("please input the first matrix");
	for (a = 0; a < m; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < n; b++)
			scanf("%d", &matrix1[a][b]);
	}

	printf("please input the second matrix");
	for (a = 0; a < i; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < j; b++)
			scanf("%d", &matrix2[a][b]);
	}

	for (c = 0; c < num1; c++)
	{
		for (b = 0; b < num2; b++)
		{
			for (a = 0; a < n; a++)
				matrix_tem1[c][b] += matrix1[c][a] * matrix2[a][b];
			matrix_tem2[c][b] = matrix_tem1[c][b];
		}
	}
	for (c = 0; c < num1; c++)
	{
		printf("\n");
		for (b = 0; b < num2; b++)
			printf("%8d", matrix_tem2[c][b]);
	}
}