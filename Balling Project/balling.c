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

    printf("볼링 게임을 시작합니다.\n\n\n");
    printf("볼링 선수의 수를 입력하시오(최대4명): ");
    scanf_s("%d", &a);

    if (a > 4)
    {
        printf("최대인원은 4명입니다.\n");
        printf("다시 입력하시오: ");
        scanf_s("%d", &a);
    }



    for (i = 1; i <= 10; i++)
    {
        if (i == 10)
        {
            for (j = 1; j <= a; j++)
            {
                printf("=========================10프레임=========================\n\n\n");
                printf("%d번째 선수의 차례입니다.\n", j);

                printf("제 1구 점수를 입력하시오: ");
                scanf_s("%d", &score[10][j][1]);

                if (score[10][j][1] == 10)
                {
                    printf("스트라이크!!!\n");
                    printf("제 2구 점수를 입력하시오: ");
                    scanf_s("%d", &score[10][j][2]);
                    printf("제 3구 점수를 입력하시오: ");
                    scanf_s("%d", &score[11][j][1]);
                }

                else
                {
                    printf("제 2구 점수를 입력하시오: ");

                    scanf_s("%d", &score[10][j][2]);

                    if (score[10][j][1] + score[10][j][2] == 10)
                    {
                        printf("스페어!!!\n");
                        printf("제 3구 점수를 입력하시오: ");
                        scanf_s("%d", &score[11][j][1]);
                    }
                }
            }
        }

        else
        {

            printf("=========================%d프레임=========================\n\n\n", i);

            for (j = 1; j <= a; j++)
            {
                printf("%d번째 선수의 차례입니다.\n", j);

                printf("제 1구 점수를 입력하시오: ");
                scanf_s("%d", &score[i][j][1]);

                if (score[i][j][1] == 10)
                {
                    printf("스트라이크!!!\n");
                    score[i][j][2] = 0;
                }

                else if (score[i][j][1] < 10)
                {
                    printf("제 2구 점수를 입력하시오: ");
                    scanf_s("%d", &score[i][j][2]);

                    if (score[i][j][1] + score[i][j][2] == 10)
                    {
                        printf("스페어!!!\n");
                    }

                    else if (score[i][j][1] + score[i][j][2] > 10)
                    {
                        printf("각 프레임의 점수는 10점을 넘을 수 없습니다.\n");
                        printf("다시 입력해 주세요: ");
                        scanf_s("%d", &score[i][j][2]);
                    }
                }

                else
                {
                    printf("각 프레임의 점수는 10점을 넘을 수 없습니다.\n");
                    printf("다시 입력해 주세요: ");
                    scanf_s("%d", &score[i][j][1]);

                    printf("제 2구 점수를 입력하시오: ");
                    scanf_s("%d", &score[i][j][2]);

                    if (score[i][j][1] + score[i][j][2] == 10)
                    {
                        printf("스페어!!!\n");
                    }

                    else if (score[i][j][1] + score[i][j][2] > 10)
                    {
                        printf("각 프레임의 점수는 10점을 넘을 수 없습니다.\n");
                        printf("다시 입력해 주세요: ");
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
    printf("프레임|    1|    2|     3|     4|     5|     6|     7|     8|    9|      10|\n");
    printf("----------------------------------------------------------------------------\n");
    printf("선수%d |%d   %d|%d   %d|%d   %d|%d   %d|%d   %d|%d   %d|%d   %d|%d   %d|%d   %d|%d  %d  %d|\n", j, score[1][j][1], score[1][j][2], score[2][j][1], score[2][j][2], score[3][j][1], score[3][j][2], score[4][j][1], score[4][j][2], score[5][j][1], score[5][j][2], score[6][j][1], score[6][j][2], score[7][j][1], score[7][j][2], score[8][j][1], score[8][j][2], score[9][j][1], score[9][j][2], score[10][j][1], score[10][j][2], score[11][j][1]);
    printf("      | %d   |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d    |\n", sum[1][j], sum[2][j], sum[3][j], sum[4][j], sum[5][j], sum[6][j], sum[7][j], sum[8][j], sum[9][j], sum[10][j]);
    printf("----------------------------------------------------------------------------\n\n");
}