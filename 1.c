#include<stdio.h>
#include<stdlib.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996) 
int func1(int array[][20], int a, int b, int p, int q);//求代余式的某一项展开值与对应元素的乘积 
void add();//矩阵加法
void sub();//矩阵减法
void mul();//矩阵乘法
void inv();//求逆矩阵 
void tran();
int main(void)
{
	int a;
	printf("                                               请选择何种计算\n\n\n\n");
	printf("                                          *********************************\n");
	printf("                                          * 1 *     矩阵加法              *\n");
	printf("                                          * 2 *     矩阵减法              *\n");
	printf("                                          * 3 *     矩阵的逆              *\n");
	printf("                                          * 4 *     转置矩阵              *\n");
	printf("                                          * 5 *     矩阵乘法              *\n");
	printf("                                          *********************************\n");
	scanf("%d", &a);

	if (a == 1)
	{
		printf("警告:请确保输入的矩阵未同行矩阵\n\n\n\n");
		add();
	}

	else if (a == 2)
	{
		printf("警告:请确保输入的矩阵未同行矩阵\n\n\n\n");
		sub();
	}

	else if (a == 3)
	{
		printf("请确认输入矩阵为方阵\n\n\n\n");
		inv();
	}

	else if (a == 4)
	{
		tran();
	}

	else if (a == 5)
	{
		printf("请确认矩阵的行列关系满足相乘法则\n\n\n\n");
		mul();
	}

}
void add()
{
	int m, n, i, j;//两个矩阵的行数和列数
	int a, b;//用于循环输入矩阵的整型数

	printf("请输入第一个矩阵的行和列:\n");
	scanf("%d", &m);
	scanf("%d", &n);

	printf("请输入第二个矩阵的行和列:\n");
	scanf("%d", &i);
	scanf("%d", &j);

	if (m != i || n != j)
		exit(1);

	int matrix1[20][20];
	int matrix2[20][20];

	printf("请输入第一个矩阵\n");

	for (a = 0; a < m; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < n; b++)
			scanf("%d", &matrix1[a][b]);
	}

	printf("请输入第二个矩阵\n");

	for (a = 0; a < i; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < j; b++)
			scanf("%d", &matrix2[a][b]);
	}

	printf("最终结果是:\n");

	for (a = 0; a < m; a++)
	{
		if (a != 0)
			printf("\n");
		for (b = 0; b < n; b++)
			printf("%-8d", matrix1[a][b] + matrix2[a][b]);
	}
}

void sub()
{
	int m, n, i, j;//两个矩阵的行数和列数
	int a, b;//用于循环输入矩阵的整型数

	printf("请输入第一个矩阵的行和列\n");
	scanf("%d", &m);
	scanf("%d", &n);

	printf("请输入第二个矩阵的行和列\n");
	scanf("%d", &i);
	scanf("%d", &j);

	if (m != i || n != j)
		exit(1);

	int matrix1[20][20];
	int matrix2[20][20];

	printf("请输入第一个矩阵\n");

	for (a = 0; a < m; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < n; b++)
			scanf("%d", &matrix1[a][b]);
	}

	printf("请输入第二个矩阵\n");

	for (a = 0; a < i; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < j; b++)
			scanf("%d", &matrix2[a][b]);
	}

	printf("最终结果是\n");

	for (a = 0; a < m; a++)
	{
		if (a != 0)
			printf("\n");
		for (b = 0; b < n; b++)
			printf("%-8d", matrix1[a][b] - matrix2[a][b]);
	}

}

void mul()
{
	int m, n, i, j;//两个矩阵的行数和列数
	int a, b, c;//用于循环输入矩阵的整型数
	int num1, num2;

	printf("请输入第一个矩阵的行和列\n");
	scanf("%d", &m);
	scanf("%d", &n);

	printf("请输入第二个矩阵的行和列\n");
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

	printf("请输入第一个矩阵\n");

	for (a = 0; a < m; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < n; b++)
			scanf("%d", &matrix1[a][b]);
	}

	printf("请输入第二个矩阵\n");

	for (a = 0; a < i; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < j; b++)
			scanf("%d", &matrix2[a][b]);
	}

	for (c = 0; c < num1; c++)//--------乘法核心 
	{
		for (b = 0; b < num2; b++)
		{
			for (a = 0; a < n; a++)
				matrix_tem1[c][b] += matrix1[c][a] * matrix2[a][b];
			matrix_tem2[c][b] = matrix_tem1[c][b];
		}
	}//---------------------------------乘法核心 
	for (c = 0; c < num1; c++)
	{
		printf("\n");

		for (b = 0; b < num2; b++)
			printf("%8d", matrix_tem2[c][b]);
	}
}

void inv()
{
	int a, b;//矩阵的行列数 
	int m, n;//用于循环输入矩阵 
	int c;//接受函数返回值 &行列式的值 
	int p, q;//指定某一项代数余子式的值 
	int number1;//用于循环得出行列式的值
	int number2;
	int number3;

	printf("请输入矩阵的行列数\n");

	scanf("%d", &a);
	scanf("%d", &b);

	if (a != b)
		exit(1);

	int matrix1[20][20];
	double matrix3[20][20];

	printf("请输入矩阵\n");

	for (m = 0; m < a; m++)
		for (n = 0; n < b; n++)
		{
			scanf("%d", &matrix1[m][n]);
		}

	for (number1 = 1; number1 <= b; number1++)//-----------------------------求行列式的值 
	{
		c += func1(matrix1, a, b, number1, 1);
	}//----------------------------------------------------------------------求行列式的值 */ 

	printf("所求得逆矩阵为:\n");

	for (number2 = 0; number2 < a; number2++)//-------------------------------------求A* 
	{
		for (number3 = 0; number3 < b; number3++)
			matrix3[number3][number2] = ((double)func1(matrix1, a, b, number2 + 1, number3 + 1) / matrix1[number2][number3]);

	}//-------------------------------------------------------------------------求A* //*/ 

	for (number2 = 0; number2 < a; number2++)
	{
		printf("\n");

		for (number3 = 0; number3 < b; number3++)
			printf("%12.5lf", (double)matrix3[number2][number3] / c);
	}//*/	
}

void tran()
{
	int a, b;//表示矩阵的行和列
	int m, n;//循环输入矩阵

	int matrix[20][20];

	printf("请输入矩阵的行和列\n");

	scanf("%d", &a);
	scanf("%d", &b);

	printf("请输入矩阵\n");

	for (m = 0; m < a; m++)
	{
		for (n = 0; n < b; n++)
			scanf("%d", &matrix[m][n]);
	}

	printf("转置矩阵为:\n");

	for (n = 0; n < b; n++)
	{
		printf("\n");

		for (m = 0; m < a; m++)
			printf("%8d", matrix[m][n]);
	}

}

int func1(int array[][20], int a, int b, int p, int q)
{
	int num1, num2, num3, num4;
	num1 = 0;//用于储存并返回函数值 
	num2 = 0;//用于循环  
	num3 = 1;//用于表示余子式前面的正负 
	num4 = 0;//同上 
//-----------------------------------------------------------------------------------------------------------------------------------------求余子式 
	p--;
	q--;
	int c;//接收返回值 

	int m, n;//余子式的行列数 
	m = 0;
	n = 0;

	int i, j;//循环输入余子式 
	int matrix2[20][20];//用于储存余子式 

	for (i = 0; i < a; i++)
	{
		n = 0;

		for (j = 0; j < b; j++)
		{
			if (i == p || j == q)
				continue;

			matrix2[m][n] = array[i][j];

			n++;
		}

		if (i == p)
			continue;

		m++;
	}//----------------------------------------------------------------------------------------------------------------------------------求余子式 

	if (a > 3)
	{
		a--;
		b--;

		for (num2 = 1; num2 <= a; num2++)
		{
			num1 += func1(matrix2, a, b, 1, num2);
		}


		for (num4 = 0; num4 < (p + 1) + (q + 1); num4++)
			num3 = num3 * (-1);

		num1 = num3 * array[p][q] * num1;

		return num1;
	}

	else if (a == 3)//---------------------------------------------------No Problem
	{
		num2 = matrix2[0][0] * matrix2[1][1] - matrix2[0][1] * matrix2[1][0];

		for (num4 = 0; num4 < (p + 1) + (q + 1); num4++)
			num3 = num3 * (-1);

		num1 = array[p][q] * num3 * num2;

		return num1;
	}//----------------------------------------------------------------No Problem

	else if (a == 2)//---------------------------------------------------------No Problem
	{

		for (num4 = 0; num4 < (p + 1) + (q + 1); num4++)
			num3 = num3 * (-1);

		num1 = array[p][q] * num3 * matrix2[0][0];

		return num1;
	}//----------------------------------------------------------------------No Problem
}