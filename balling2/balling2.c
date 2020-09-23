#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 19

/*
	�ۼ��� : ����Ʈ�����к� 2020271 ������
	�ۼ���¥ : 2020-06-04
	���� : ���������� �����Ͻÿ�.
	<����������>
	1. ����1, ����2�� �̸��� �Է��Ѵ�.
	2. �� 10 �������� �����Ѵ�.
	3. ���� �����Ͽ� ���� ���̺� ���
	���2(������ ���� ����): ����ڰ� ������ �Է����� �ʰ� ������ �����Ͽ� ������ ���������. 
	<���� ���� ������� ��� �� ��>
	�� �����ӿ��� 10���� ����, 7���� ����Ʈ���ٸ�, ���� �Ͽ��� 1~3 ���� ���� ����Ʈ������ ����ؾ� �Ѵ�.  
	���� 1 ~ 10 ���� ���� ���� ��, �յ��ϰ� ���� ������ Ȯ�� ���ٴ� 0~5 �� ���� ����, 6 ~ 9�� ���� ����, 10�� ���� ���� �߻��ǵ��� �Ѵ�.
*/


int i, j, k;
int score[2][2][12] = { 0 };		// score[i][j][k] i�� ���� ��ȣ, j�� ���� �������� ��, k�� ���� �������� ��
int sum[2][12] = { 0 };		// sum[i][k], ���� 2��, 10�����ӱ���
int a[12] = { 0 };
int b[12] = { 0 };
int c[12] = { 0 };


void calculate_Score();		// ���� ��� �Լ�

int main()
{


	char n1[10];
	char n2[10];

	printf("�������� �̸��� �Է��ϼ��� : ");
	scanf_s("%s %s", n1, 10, n2, 10);		// ������ �̸��� ���ڿ��� �޾� �Է�
	printf("����1 : %s  ", n1);
	printf("����2 : %s", n2);


	srand(time(NULL));				// �Ź� �ٸ� ���� ����

	/////////////���� �Է� ����/////////////
	printf("\n���������� �����մϴ�\n");

	for (k = 0; k <= 9; k++)
	{
		printf("===========================%d������===========================\n", k + 1);
		for (i = 0; i < 2; i++)
		{
			printf("����%d�� �����Դϴ�\n", i + 1);
			c[k] = rand() % MAX_NUM;
			switch (c[k])				// ����Ʈ���� �� ������ ���� Ȯ�� ����
			{
			case 0:
				score[i][0][k] = 0;
				break;
			case 1:
				score[i][0][k] = 1;
				break;
			case 2:
				score[i][0][k] = 2;
				break;
			case 3:
				score[i][0][k] = 3;
				break;
			case 4:
				score[i][0][k] = 4;
				break;
			case 5:
				score[i][0][k] = 5;
				break;
			case 6: case 7: case 8:			// 6~9�� 0~5�� 10���� ���� Ȯ��
				score[i][0][k] = 6;
				break;
			case 9: case 10: case 11:
				score[i][0][k] = 7;
				break;
			case 12: case 13: case 14:
				score[i][0][k] = 8;
				break;
			case 15: case 16: case 17:
				score[i][0][k] = 9;
				break;
			case 18:
				score[i][0][k] = 10;
				break;
			default :
				break;
			}
			printf("%d������ 1�� ������ : %d\n", k + 1, score[i][0][k]);

			if (score[i][0][k] == 10)		// 1���� ��Ʈ����ũ�� ģ ���
			{
				printf("��Ʈ����ũ!!\n");
				score[i][1][k] = 0;
			}
			else if (score[i][0][k] != 10)		// 1���� ��Ʈ����ũ�� �� ģ ���
			{
				c[k] = rand() % MAX_NUM;
				switch (c[k])				// ����Ʈ���� �� ������ ���� Ȯ�� ����
				{
				case 0:
					score[i][1][k] = 0;
					break;
				case 1:
					score[i][1][k] = 1;
					break;
				case 2:
					score[i][1][k] = 2;
					break;
				case 3:
					score[i][1][k] = 3;
					break;
				case 4:
					score[i][1][k] = 4;
					break;
				case 5:
					score[i][1][k] = 5;
					break;
				case 6: case 7: case 8:			// 6~9�� 0~5�� 10���� ���� Ȯ��
					score[i][1][k] = 6;
					break;
				case 9: case 10: case 11:
					score[i][1][k] = 7;
					break;
				case 12: case 13: case 14:
					score[i][1][k] = 8;
					break;
				case 15: case 16: case 17:
					score[i][1][k] = 9;
					break;
				case 18:
					score[i][1][k] = 10;
					break;
				default:
					break;
				}
				printf("%d������ 2�� ������ : %d\n", k + 1, score[i][1][k]);

				if (score[i][0][k] + score[i][1][k] == 10)		// ��Ʈ����ũ�� �� ġ�� ������ �������� ���
					printf("�����!!\n");
				else if (score[i][0][k] + score[i][1][k] > 10)
				{
					while ((score[i][0][k] + score[i][1][k]) > 10)
					{
						c[k] = rand() % MAX_NUM;
						switch (c[k])				// ����Ʈ���� �� ������ ���� Ȯ�� ����
						{
						case 0:
							score[i][1][k] = 0;
							break;
						case 1:
							score[i][1][k] = 1;
							break;
						case 2:
							score[i][1][k] = 2;
							break;
						case 3:
							score[i][1][k] = 3;
							break;
						case 4:
							score[i][1][k] = 4;
							break;
						case 5:
							score[i][1][k] = 5;
							break;
						case 6: case 7: case 8:			// 6~9�� 0~5�� 10���� ���� Ȯ��
							score[i][1][k] = 6;
							break;
						case 9: case 10: case 11:
							score[i][1][k] = 7;
							break;
						case 12: case 13: case 14:
							score[i][1][k] = 8;
							break;
						case 15: case 16: case 17:
							score[i][1][k] = 9;
							break;
						case 18:
							score[i][1][k] = 10;
							break;
						default:
							break;
						}
						printf("�� �����ӿ����� ���� ���� 10���� ���� �� �����ϴ�\n");
						printf("%d������ 2�� ������ : %d\n", k + 1, score[i][1][k]);

						if (score[i][0][k] + score[i][1][k] == 10)		// ��Ʈ����ũ�� �� ġ�� ������ �������� ���
							printf("�����!!\n");
					}
				}
			}
			////////////10������ ����///////////////
			if (k == 9)
			{
				if (score[i][0][k] == 10)		// 10�����ӿ��� ��Ʈ����ũ�� ģ ���
				{
					c[10] = rand() % MAX_NUM;
					switch (c[k])				// ����Ʈ���� �� ������ ���� Ȯ�� ����
					{
					case 0:
						score[i][0][10] = 0;
						break;
					case 1:
						score[i][0][10] = 1;
						break;
					case 2:
						score[i][0][10] = 2;
						break;
					case 3:
						score[i][0][10] = 3;
						break;
					case 4:
						score[i][0][10] = 4;
						break;
					case 5:
						score[i][0][10] = 5;
						break;
					case 6: case 7: case 8:			// 6~9�� 0~5�� 10���� ���� Ȯ��
						score[i][0][10] = 6;
						break;
					case 9: case 10: case 11:
						score[i][0][10] = 7;
						break;
					case 12: case 13: case 14:
						score[i][0][10] = 8;
						break;
					case 15: case 16: case 17:
						score[i][0][10] = 9;
						break;
					case 18:
						score[i][0][10] = 10;
						break;
					default:
						break;
					}
					printf("���ʽ� 1�� ������ : %d\n", score[i][0][10]);
		
					if (score[i][0][10] == 10)		// ���ʽ� 1������ ��Ʈ����ũ�� ģ ���
					{
						printf("��Ʈ����ũ!!\n");
						score[i][1][10] = 0;

						c[11] = rand() % MAX_NUM;		// ���ʽ� 1������ ��Ʈ����ũ�� ģ ��쿣 ���ʽ� 3���� ĥ �� �ִ�.
						switch (c[k])				// ����Ʈ���� �� ������ ���� Ȯ�� ����
						{
						case 0:
							score[i][0][11] = 0;
							break;
						case 1:
							score[i][0][11] = 1;
							break;
						case 2:
							score[i][0][11] = 2;
							break;
						case 3:
							score[i][0][11] = 3;
							break;
						case 4:
							score[i][0][11] = 4;
							break;
						case 5:
							score[i][0][11] = 5;
							break;
						case 6: case 7: case 8:			// 6~9�� 0~5�� 10���� ���� Ȯ��
							score[i][0][11] = 6;
							break;
						case 9: case 10: case 11:
							score[i][0][11] = 7;
							break;
						case 12: case 13: case 14:
							score[i][0][11] = 8;
							break;
						case 15: case 16: case 17:
							score[i][0][11] = 9;
							break;
						case 18:
							score[i][0][11] = 10;
							break;
						default:
							break;
						}
						printf("���ʽ� 3�� ������ : %d\n", score[i][0][11]);
						
					}
					else if (score[i][0][10] != 10)		// ���ʽ� 1������ ��Ʈ����ũ�� �� ģ ���
					{
						c[10] = rand() % MAX_NUM;
						switch (c[k])				// ����Ʈ���� �� ������ ���� Ȯ�� ����
						{
						case 0:
							score[i][0][10] = 0;
							break;
						case 1:
							score[i][0][10] = 1;
							break;
						case 2:
							score[i][0][10] = 2;
							break;
						case 3:
							score[i][0][10] = 3;
							break;
						case 4:
							score[i][0][10] = 4;
							break;
						case 5:
							score[i][0][10] = 5;
							break;
						case 6: case 7: case 8: 			// 6~9�� 0~5�� 10���� ���� Ȯ��
							score[i][0][10] = 6;
							break;
						case 9: case 10: case 11:
							score[i][0][10] = 7;
							break;
						case 12: case 13: case 14:
							score[i][0][10] = 8;
							break;
						case 15: case 16: case 17:
							score[i][0][10] = 9;
							break;
						case 18:
							score[i][0][10] = 10;
							break;
						default:
							break;
						}
						printf("���ʽ� 2�� ������ : %d\n", score[i][1][10]);

						if ((score[i][0][10] + score[i][1][10]) == 10)	// 11�����ӿ��� ������� ���
						{
							printf("�����!!\n");
						}
						else if ((score[i][0][10] + score[i][1][10] > 10))
						{
							while ((score[i][0][10] + score[i][1][10]) > 10)
							{
								c[10] = rand() % MAX_NUM;
								switch (c[k])				// ����Ʈ���� �� ������ ���� Ȯ�� ����
								{
								case 0:
									score[i][0][10] = 0;
									break;
								case 1:
									score[i][0][10] = 1;
									break;
								case 2:
									score[i][0][10] = 2;
									break;
								case 3:
									score[i][0][10] = 3;
									break;
								case 4:
									score[i][0][10] = 4;
									break;
								case 5:
									score[i][0][10] = 5;
									break;
								case 6: case 7: case 8:			// 6~9�� 0~5�� 10���� ���� Ȯ��
									score[i][0][10] = 6;
									break;
								case 9: case 10: case 11:
									score[i][0][10] = 7;
									break;
								case 12: case 13: case 14:
									score[i][0][10] = 8;
									break;
								case 15: case 16: case 17:
									score[i][0][10] = 9;
									break;
								case 18:
									score[i][0][10] = 10;
									break;
								default:
									break;
								}
								printf("�� �����ӿ����� ���� ���� 10���� ���� �� �����ϴ�\n");
								printf("���ʽ� 2�� ������ : %d\n", score[i][1][10]);

								if ((score[i][0][10] + score[i][1][10]) == 10)	// 11�����ӿ��� ������� ���
								{
									printf("�����!!\n");
								}
							}
						}
					}

				}
				else if ((score[i][0][k] + score[i][1][k]) == 10)		// 10�����ӿ��� ������ �������� ���
				{
					printf("�����!!\n");
					c[10] = rand() % MAX_NUM;		// ���ʽ� 1���� ĥ �� �ִ�.
					switch (c[k])				// ����Ʈ���� �� ������ ���� Ȯ�� ����
					{
					case 0:
						score[i][0][10] = 0;
						break;
					case 1:
						score[i][0][10] = 1;
						break;
					case 2:
						score[i][0][10] = 2;
						break;
					case 3:
						score[i][0][10] = 3;
						break;
					case 4:
						score[i][0][10] = 4;
						break;
					case 5:
						score[i][0][10] = 5;
						break;
					case 6: case 7: case 8: 			// 6~9�� 0~5�� 10���� ���� Ȯ��
						score[i][0][10] = 6;
						break;
					case 9: case 10: case 11:
						score[i][0][10] = 7;
						break;
					case 12: case 13: case 14:
						score[i][0][10] = 8;
						break;
					case 15: case 16: case 17:
						score[i][0][10] = 9;
						break;
					case 18:
						score[i][0][10] = 10;
						break;
					default:
						break;
					}
					printf("���ʽ� 1�� ������ : %d\n", score[i][0][10]);

				}
			}
		}


	}



	calculate_Score();

	//////////////���� ���� ǥ////////////////

	printf("  ================================================================================================================================================================================  \n");
	printf("         1/        2/          3/        4/        5/        6/        7/        8/        9/          10/         10-1/         10-2/   \n");
	printf("%s     %d|%d     %d|%d          %d|%d     %d|%d      %d|%d      %d|%d      %d|%d      %d|%d      %d|%d         %d|%d         %d|%d          %d|   \n", n1,
		score[0][0][0], score[0][1][0], score[0][0][1], score[0][1][1], score[0][0][2], score[0][1][2], score[0][0][3], score[0][1][3], score[0][0][4], score[0][1][4], score[0][0][5], score[0][1][5],
		score[0][0][6], score[0][1][6], score[0][0][7], score[0][1][7], score[0][0][8], score[0][1][8], score[0][0][9], score[0][1][9], score[0][0][10], score[0][1][10], score[0][0][11]);
	printf("        %d       %d           %d       %d       %d       %d      %d       %d       %d       %d       \n",
		sum[0][0],
		sum[0][0] + sum[0][1],
		sum[0][0] + sum[0][1] + sum[0][2],
		sum[0][0] + sum[0][1] + sum[0][2] + sum[0][3],
		sum[0][0] + sum[0][1] + sum[0][2] + sum[0][3] + sum[0][4],
		sum[0][0] + sum[0][1] + sum[0][2] + sum[0][3] + sum[0][4] + sum[0][5],
		sum[0][0] + sum[0][1] + sum[0][2] + sum[0][3] + sum[0][4] + sum[0][5] + sum[0][6],
		sum[0][0] + sum[0][1] + sum[0][2] + sum[0][3] + sum[0][4] + sum[0][5] + sum[0][6] + sum[0][7],
		sum[0][0] + sum[0][1] + sum[0][2] + sum[0][3] + sum[0][4] + sum[0][5] + sum[0][6] + sum[0][7] + sum[0][8],
		sum[0][0] + sum[0][1] + sum[0][2] + sum[0][3] + sum[0][4] + sum[0][5] + sum[0][6] + sum[0][7] + sum[0][8] + sum[0][9]);
	printf("  ================================================================================================================================================================================  \n");


	printf("  ================================================================================================================================================================================  \n");
	printf("         1/        2/          3/        4/        5/        6/        7/        8/        9/          10/         10-1/         10-2/   \n");
	printf("%s     %d|%d     %d|%d          %d|%d      %d|%d      %d|%d      %d|%d      %d|%d      %d|%d      %d|%d         %d|%d         %d|%d          %d|   \n", n2,
		score[1][0][0], score[1][1][0], score[1][0][1], score[1][1][1], score[1][0][2], score[1][1][2], score[1][0][3], score[1][1][3], score[1][0][4], score[1][1][4], score[1][0][5], score[1][1][5],
		score[1][0][6], score[1][1][6], score[1][0][7], score[1][1][7], score[1][0][8], score[1][1][8], score[1][0][9], score[1][1][9], score[1][0][10], score[1][1][10], score[1][0][11]);
	printf("        %d       %d           %d       %d       %d       %d      %d       %d       %d       %d          \n",
		sum[1][0],
		sum[1][0] + sum[1][1],
		sum[1][0] + sum[1][1] + sum[1][2],
		sum[1][0] + sum[1][1] + sum[1][2] + sum[1][3],
		sum[1][0] + sum[1][1] + sum[1][2] + sum[1][3] + sum[1][4],
		sum[1][0] + sum[1][1] + sum[1][2] + sum[1][3] + sum[1][4] + sum[1][5],
		sum[1][0] + sum[1][1] + sum[1][2] + sum[1][3] + sum[1][4] + sum[1][5] + sum[1][6],
		sum[1][0] + sum[1][1] + sum[1][2] + sum[1][3] + sum[1][4] + sum[1][5] + sum[1][6] + sum[1][7],
		sum[1][0] + sum[1][1] + sum[1][2] + sum[1][3] + sum[1][4] + sum[1][5] + sum[1][6] + sum[1][7] + sum[1][8],
		sum[1][0] + sum[1][1] + sum[1][2] + sum[1][3] + sum[1][4] + sum[1][5] + sum[1][6] + sum[1][7] + sum[1][8] + sum[1][9]);
	printf("  ================================================================================================================================================================================  \n");



	return 0;
}




void calculate_Score()		// ���� ��� �Լ�
{
	////////////////����� ���� ���//////////////////

	for (k = 0; k <= 9; k++)
	{
		for (i = 0; i < 2; i++)
		{
			if (((score[i][0][k] + score[i][1][k] == 10)) && score[i][0][k] != 10)		// ����� ó���� ���
				sum[i][k] += 10 + score[i][0][k + 1];		// ���� ������ 1�� ������ ���ʽ��̴�
			else if (score[i][0][k] + score[i][1][k] < 10)								// ����� ó���� ������ ���
				sum[i][k] += score[i][0][k] + score[i][1][k];

		}
	}
	/////////////��Ʈ����ũ ���� ���///////////////

	for (k = 0; k <= 9; k++)
	{
		for (i = 0; i < 2; i++)
		{
			if (score[i][0][k] == 10)		// ��Ʈ����ũ�� ģ ���
			{
				sum[i][k] = 10;
				if (score[i][0][k + 1] == 10 && score[i][1][k + 1] == 0)		// ��Ʈ����ũ�� ġ�� ���� ������ 1������ ��Ʈ����ũ�� ģ ���� �� ���� ������ 1������ ���ʽ��̴� = ����, ��Ʈ����ũ�� ������ �ݺ��Ǹ� ��Ű
					sum[i][k] += 10 + score[i][0][k + 2];
				else if ((score[i][0][k + 1] + score[i][1][k + 1] == 10))	// ��Ʈ����ũ�� ġ�� ���� ������ 2������ ���� ģ ���� 10���� ���ʽ��̴�
					sum[i][k] += 10;
				else if ((score[i][0][k + 1] + score[i][1][k + 1]) < 10)		// ��Ʈ����ũ�� ġ�� ���� �����ӿ��� ��Ʈ����ũ, ���� �Ѵ� �� ģ ���� ���� 2���� �� ������ ���ʽ��̴�
					sum[i][k] += score[i][0][k + 1] + score[i][1][k + 1];
			}
		}
	}

}