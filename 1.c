#include<stdio.h>
#include<stdlib.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996) 
int func1(int array[][20], int a, int b, int p, int q);//�����ʽ��ĳһ��չ��ֵ���ӦԪ�صĳ˻� 
void add();//����ӷ�
void sub();//�������
void mul();//����˷�
void inv();//������� 
void tran();
int main(void)
{
	int a;
	printf("                                               ��ѡ����ּ���\n\n\n\n");
	printf("                                          *********************************\n");
	printf("                                          * 1 *     ����ӷ�              *\n");
	printf("                                          * 2 *     �������              *\n");
	printf("                                          * 3 *     �������              *\n");
	printf("                                          * 4 *     ת�þ���              *\n");
	printf("                                          * 5 *     ����˷�              *\n");
	printf("                                          *********************************\n");
	scanf("%d", &a);

	if (a == 1)
	{
		printf("����:��ȷ������ľ���δͬ�о���\n\n\n\n");
		add();
	}

	else if (a == 2)
	{
		printf("����:��ȷ������ľ���δͬ�о���\n\n\n\n");
		sub();
	}

	else if (a == 3)
	{
		printf("��ȷ���������Ϊ����\n\n\n\n");
		inv();
	}

	else if (a == 4)
	{
		tran();
	}

	else if (a == 5)
	{
		printf("��ȷ�Ͼ�������й�ϵ������˷���\n\n\n\n");
		mul();
	}

}
void add()
{
	int m, n, i, j;//�������������������
	int a, b;//����ѭ����������������

	printf("�������һ��������к���:\n");
	scanf("%d", &m);
	scanf("%d", &n);

	printf("������ڶ���������к���:\n");
	scanf("%d", &i);
	scanf("%d", &j);

	if (m != i || n != j)
		exit(1);

	int matrix1[20][20];
	int matrix2[20][20];

	printf("�������һ������\n");

	for (a = 0; a < m; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < n; b++)
			scanf("%d", &matrix1[a][b]);
	}

	printf("������ڶ�������\n");

	for (a = 0; a < i; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < j; b++)
			scanf("%d", &matrix2[a][b]);
	}

	printf("���ս����:\n");

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
	int m, n, i, j;//�������������������
	int a, b;//����ѭ����������������

	printf("�������һ��������к���\n");
	scanf("%d", &m);
	scanf("%d", &n);

	printf("������ڶ���������к���\n");
	scanf("%d", &i);
	scanf("%d", &j);

	if (m != i || n != j)
		exit(1);

	int matrix1[20][20];
	int matrix2[20][20];

	printf("�������һ������\n");

	for (a = 0; a < m; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < n; b++)
			scanf("%d", &matrix1[a][b]);
	}

	printf("������ڶ�������\n");

	for (a = 0; a < i; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < j; b++)
			scanf("%d", &matrix2[a][b]);
	}

	printf("���ս����\n");

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
	int m, n, i, j;//�������������������
	int a, b, c;//����ѭ����������������
	int num1, num2;

	printf("�������һ��������к���\n");
	scanf("%d", &m);
	scanf("%d", &n);

	printf("������ڶ���������к���\n");
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

	printf("�������һ������\n");

	for (a = 0; a < m; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < n; b++)
			scanf("%d", &matrix1[a][b]);
	}

	printf("������ڶ�������\n");

	for (a = 0; a < i; a++)
	{
		if (a == 0)
			printf("\n");
		for (b = 0; b < j; b++)
			scanf("%d", &matrix2[a][b]);
	}

	for (c = 0; c < num1; c++)//--------�˷����� 
	{
		for (b = 0; b < num2; b++)
		{
			for (a = 0; a < n; a++)
				matrix_tem1[c][b] += matrix1[c][a] * matrix2[a][b];
			matrix_tem2[c][b] = matrix_tem1[c][b];
		}
	}//---------------------------------�˷����� 
	for (c = 0; c < num1; c++)
	{
		printf("\n");

		for (b = 0; b < num2; b++)
			printf("%8d", matrix_tem2[c][b]);
	}
}

void inv()
{
	int a, b;//����������� 
	int m, n;//����ѭ��������� 
	int c;//���ܺ�������ֵ &����ʽ��ֵ 
	int p, q;//ָ��ĳһ���������ʽ��ֵ 
	int number1;//����ѭ���ó�����ʽ��ֵ
	int number2;
	int number3;

	printf("����������������\n");

	scanf("%d", &a);
	scanf("%d", &b);

	if (a != b)
		exit(1);

	int matrix1[20][20];
	double matrix3[20][20];

	printf("���������\n");

	for (m = 0; m < a; m++)
		for (n = 0; n < b; n++)
		{
			scanf("%d", &matrix1[m][n]);
		}

	for (number1 = 1; number1 <= b; number1++)//-----------------------------������ʽ��ֵ 
	{
		c += func1(matrix1, a, b, number1, 1);
	}//----------------------------------------------------------------------������ʽ��ֵ */ 

	printf("����������Ϊ:\n");

	for (number2 = 0; number2 < a; number2++)//-------------------------------------��A* 
	{
		for (number3 = 0; number3 < b; number3++)
			matrix3[number3][number2] = ((double)func1(matrix1, a, b, number2 + 1, number3 + 1) / matrix1[number2][number3]);

	}//-------------------------------------------------------------------------��A* //*/ 

	for (number2 = 0; number2 < a; number2++)
	{
		printf("\n");

		for (number3 = 0; number3 < b; number3++)
			printf("%12.5lf", (double)matrix3[number2][number3] / c);
	}//*/	
}

void tran()
{
	int a, b;//��ʾ������к���
	int m, n;//ѭ���������

	int matrix[20][20];

	printf("�����������к���\n");

	scanf("%d", &a);
	scanf("%d", &b);

	printf("���������\n");

	for (m = 0; m < a; m++)
	{
		for (n = 0; n < b; n++)
			scanf("%d", &matrix[m][n]);
	}

	printf("ת�þ���Ϊ:\n");

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
	num1 = 0;//���ڴ��沢���غ���ֵ 
	num2 = 0;//����ѭ��  
	num3 = 1;//���ڱ�ʾ����ʽǰ������� 
	num4 = 0;//ͬ�� 
//-----------------------------------------------------------------------------------------------------------------------------------------������ʽ 
	p--;
	q--;
	int c;//���շ���ֵ 

	int m, n;//����ʽ�������� 
	m = 0;
	n = 0;

	int i, j;//ѭ����������ʽ 
	int matrix2[20][20];//���ڴ�������ʽ 

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
	}//----------------------------------------------------------------------------------------------------------------------------------������ʽ 

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