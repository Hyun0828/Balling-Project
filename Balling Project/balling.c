#include <stdio.h>

void chart();


int i, j, k, a;
int score[11][4][2];
int sum[11][4];


int main()
{
    sum[0][1] = 0;
    sum[0][2] = 0;
    sum[0][3] = 0;
    sum[0][4] = 0;

    printf("���� ������ �����մϴ�.\n\n\n");
    printf("���� ������ ���� �Է��Ͻÿ�(�ִ�4��): ");
    scanf_s("%d", &a);

    if (a > 4)
    {
        printf("�ִ��ο��� 4���Դϴ�.\n");
        printf("�ٽ� �Է��Ͻÿ�: ");
        scanf_s("%d", &a);
    }



    for (i = 1; i <= 10; i++)
    {
        if (i == 10)
        {
            for (j = 1; j <= a; j++)
            {
                printf("=========================10������=========================\n\n\n");
                printf("%d��° ������ �����Դϴ�.\n", j);

                printf("�� 1�� ������ �Է��Ͻÿ�: ");
                scanf_s("%d", &score[10][j][1]);

                if (score[10][j][1] == 10)
                {
                    printf("��Ʈ����ũ!!!\n");
                    printf("�� 2�� ������ �Է��Ͻÿ�: ");
                    scanf_s("%d", &score[10][j][2]);
                    printf("�� 3�� ������ �Է��Ͻÿ�: ");
                    scanf_s("%d", &score[11][j][1]);
                }

                else
                {
                    printf("�� 2�� ������ �Է��Ͻÿ�: ");

                    scanf_s("%d", &score[10][j][2]);

                    if (score[10][j][1] + score[10][j][2] == 10)
                    {
                        printf("�����!!!\n");
                        printf("�� 3�� ������ �Է��Ͻÿ�: ");
                        scanf_s("%d", &score[11][j][1]);
                    }
                }
            }
        }

        else
        {

            printf("=========================%d������=========================\n\n\n", i);

            for (j = 1; j <= a; j++)
            {
                printf("%d��° ������ �����Դϴ�.\n", j);

                printf("�� 1�� ������ �Է��Ͻÿ�: ");
                scanf_s("%d", &score[i][j][1]);

                if (score[i][j][1] == 10)
                {
                    printf("��Ʈ����ũ!!!\n");
                    score[i][j][2] = 0;
                }

                else if (score[i][j][1] < 10)
                {
                    printf("�� 2�� ������ �Է��Ͻÿ�: ");
                    scanf_s("%d", &score[i][j][2]);

                    if (score[i][j][1] + score[i][j][2] == 10)
                    {
                        printf("�����!!!\n");
                    }

                    else if (score[i][j][1] + score[i][j][2] > 10)
                    {
                        printf("�� �������� ������ 10���� ���� �� �����ϴ�.\n");
                        printf("�ٽ� �Է��� �ּ���: ");
                        scanf_s("%d", &score[i][j][2]);
                    }
                }

                else
                {
                    printf("�� �������� ������ 10���� ���� �� �����ϴ�.\n");
                    printf("�ٽ� �Է��� �ּ���: ");
                    scanf_s("%d", &score[i][j][1]);

                    printf("�� 2�� ������ �Է��Ͻÿ�: ");
                    scanf_s("%d", &score[i][j][2]);

                    if (score[i][j][1] + score[i][j][2] == 10)
                    {
                        printf("�����!!!\n");
                    }

                    else if (score[i][j][1] + score[i][j][2] > 10)
                    {
                        printf("�� �������� ������ 10���� ���� �� �����ϴ�.\n");
                        printf("�ٽ� �Է��� �ּ���: ");
                        scanf_s("%d", &score[i][j][2]);
                    }
                }
            }
        }
    }



    for (i = 1; i <= 10; i++)
    {
        for (j = 1; j <= a; j++)
        {
            if (score[i][j][1] == 10)
            {


                if (score[i + 1][j][1] == 10)
                {
                    sum[i][j] = sum[i - 1][j] + score[i][j][1] + score[i][j][2] + score[i + 1][j][1] + score[i + 2][j][1];
                }

                else
                {
                    sum[i][j] = sum[i - 1][j] + score[i][j][1] + score[i][j][2] + score[i + 1][j][1] + score[i + 1][j][2];
                }
            }

            else if (score[i][j][1] + score[i][j][2] == 10)
            {
                sum[i][j] = sum[i - 1][j] + score[i][j][1] + score[i][j][2] + score[i + 1][j][1];
            }

            else
            {
                sum[i][j] = sum[i - 1][j] + score[i][j][1] + score[i][j][2];
            }

        }
    }


    for (j = 1; j <= a; j++)
    {
        chart();
    }


    return 0;

}

void chart()
{
    printf("----------------------------------------------------------------------------\n");
    printf("������|    1|    2|     3|     4|     5|     6|     7|     8|    9|      10|\n");
    printf("----------------------------------------------------------------------------\n");
    printf("����%d |%d   %d|%d   %d|%d   %d|%d   %d|%d   %d|%d   %d|%d   %d|%d   %d|%d   %d|%d  %d  %d|\n", j, score[1][j][1], score[1][j][2], score[2][j][1], score[2][j][2], score[3][j][1], score[3][j][2], score[4][j][1], score[4][j][2], score[5][j][1], score[5][j][2], score[6][j][1], score[6][j][2], score[7][j][1], score[7][j][2], score[8][j][1], score[8][j][2], score[9][j][1], score[9][j][2], score[10][j][1], score[10][j][2], score[11][j][1]);
    printf("      | %d   |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d    |\n", sum[1][j], sum[2][j], sum[3][j], sum[4][j], sum[5][j], sum[6][j], sum[7][j], sum[8][j], sum[9][j], sum[10][j]);
    printf("----------------------------------------------------------------------------\n\n");
}