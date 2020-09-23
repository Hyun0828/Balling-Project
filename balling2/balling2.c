#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 19

/*
	작성자 : 소프트웨어학부 2020271 신현우
	작성날짜 : 2020-06-04
	문제 : 볼링게임을 제작하시오.
	<게임진행방식>
	1. 선수1, 선수2의 이름을 입력한다.
	2. 총 10 프레임을 진행한다.
	3. 점수 생성하여 점수 테이블 출력
	방법2(난수를 점수 생성): 사용자가 점수를 입력하지 않고 난수를 생성하여 점수가 만들어진다. 
	<난수 생성 방법에서 고려 할 점>
	한 프레임에서 10개의 핀중, 7개를 쓰러트린다면, 다음 턴에는 1~3 개의 핀을 쓰러트리도록 고려해야 한다.  
	보통 1 ~ 10 개의 핀이 있을 때, 균등하게 핀이 쓰러질 확률 보다는 0~5 는 조금 낮게, 6 ~ 9은 조금 높게, 10은 조금 낮게 발생되도록 한다.
*/


int i, j, k;
int score[2][2][12] = { 0 };		// score[i][j][k] i는 선수 번호, j는 볼링 점수판의 행, k는 볼링 점수판의 열
int sum[2][12] = { 0 };		// sum[i][k], 선수 2명, 10프레임까지
int a[12] = { 0 };
int b[12] = { 0 };
int c[12] = { 0 };


void calculate_Score();		// 점수 계산 함수

int main()
{


	char n1[10];
	char n2[10];

	printf("선수들의 이름을 입력하세요 : ");
	scanf_s("%s %s", n1, 10, n2, 10);		// 선수의 이름을 문자열로 받아 입력
	printf("선수1 : %s  ", n1);
	printf("선수2 : %s", n2);


	srand(time(NULL));				// 매번 다른 난수 생성

	/////////////점수 입력 과정/////////////
	printf("\n볼링게임을 시작합니다\n");

	for (k = 0; k <= 9; k++)
	{
		printf("===========================%d프레임===========================\n", k + 1);
		for (i = 0; i < 2; i++)
		{
			printf("선수%d의 차례입니다\n", i + 1);
			c[k] = rand() % MAX_NUM;
			switch (c[k])				// 쓰러트리는 핀 개수에 대한 확률 조정
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
			case 6: case 7: case 8:			// 6~9는 0~5와 10보다 높은 확률
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
			printf("%d프레임 1구 점수는 : %d\n", k + 1, score[i][0][k]);

			if (score[i][0][k] == 10)		// 1구에 스트라이크를 친 경우
			{
				printf("스트라이크!!\n");
				score[i][1][k] = 0;
			}
			else if (score[i][0][k] != 10)		// 1구에 스트라이크를 못 친 경우
			{
				c[k] = rand() % MAX_NUM;
				switch (c[k])				// 쓰러트리는 핀 개수에 대한 확률 조정
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
				case 6: case 7: case 8:			// 6~9는 0~5와 10보다 높은 확률
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
				printf("%d프레임 2구 점수는 : %d\n", k + 1, score[i][1][k]);

				if (score[i][0][k] + score[i][1][k] == 10)		// 스트라이크를 못 치고 스페어로 마무리한 경우
					printf("스페어!!\n");
				else if (score[i][0][k] + score[i][1][k] > 10)
				{
					while ((score[i][0][k] + score[i][1][k]) > 10)
					{
						c[k] = rand() % MAX_NUM;
						switch (c[k])				// 쓰러트리는 핀 개수에 대한 확률 조정
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
						case 6: case 7: case 8:			// 6~9는 0~5와 10보다 높은 확률
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
						printf("각 프레임에서의 점수 합은 10점을 넘을 수 없습니다\n");
						printf("%d프레임 2구 점수는 : %d\n", k + 1, score[i][1][k]);

						if (score[i][0][k] + score[i][1][k] == 10)		// 스트라이크를 못 치고 스페어로 마무리한 경우
							printf("스페어!!\n");
					}
				}
			}
			////////////10프레임 이후///////////////
			if (k == 9)
			{
				if (score[i][0][k] == 10)		// 10프레임에서 스트라이크를 친 경우
				{
					c[10] = rand() % MAX_NUM;
					switch (c[k])				// 쓰러트리는 핀 개수에 대한 확률 조정
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
					case 6: case 7: case 8:			// 6~9는 0~5와 10보다 높은 확률
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
					printf("보너스 1구 점수는 : %d\n", score[i][0][10]);
		
					if (score[i][0][10] == 10)		// 보너스 1구에서 스트라이크를 친 경우
					{
						printf("스트라이크!!\n");
						score[i][1][10] = 0;

						c[11] = rand() % MAX_NUM;		// 보너스 1구에서 스트라이크를 친 경우엔 보너스 3구를 칠 수 있다.
						switch (c[k])				// 쓰러트리는 핀 개수에 대한 확률 조정
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
						case 6: case 7: case 8:			// 6~9는 0~5와 10보다 높은 확률
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
						printf("보너스 3구 점수는 : %d\n", score[i][0][11]);
						
					}
					else if (score[i][0][10] != 10)		// 보너스 1구에서 스트라이크를 못 친 경우
					{
						c[10] = rand() % MAX_NUM;
						switch (c[k])				// 쓰러트리는 핀 개수에 대한 확률 조정
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
						case 6: case 7: case 8: 			// 6~9는 0~5와 10보다 높은 확률
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
						printf("보너스 2구 점수는 : %d\n", score[i][1][10]);

						if ((score[i][0][10] + score[i][1][10]) == 10)	// 11프레임에서 스페어인 경우
						{
							printf("스페어!!\n");
						}
						else if ((score[i][0][10] + score[i][1][10] > 10))
						{
							while ((score[i][0][10] + score[i][1][10]) > 10)
							{
								c[10] = rand() % MAX_NUM;
								switch (c[k])				// 쓰러트리는 핀 개수에 대한 확률 조정
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
								case 6: case 7: case 8:			// 6~9는 0~5와 10보다 높은 확률
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
								printf("각 프레임에서의 점수 합은 10점을 넘을 수 없습니다\n");
								printf("보너스 2구 점수는 : %d\n", score[i][1][10]);

								if ((score[i][0][10] + score[i][1][10]) == 10)	// 11프레임에서 스페어인 경우
								{
									printf("스페어!!\n");
								}
							}
						}
					}

				}
				else if ((score[i][0][k] + score[i][1][k]) == 10)		// 10프레임에서 스페어로 마무리한 경우
				{
					printf("스페어!!\n");
					c[10] = rand() % MAX_NUM;		// 보너스 1구만 칠 수 있다.
					switch (c[k])				// 쓰러트리는 핀 개수에 대한 확률 조정
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
					case 6: case 7: case 8: 			// 6~9는 0~5와 10보다 높은 확률
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
					printf("보너스 1구 점수는 : %d\n", score[i][0][10]);

				}
			}
		}


	}



	calculate_Score();

	//////////////볼링 점수 표////////////////

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




void calculate_Score()		// 점수 계산 함수
{
	////////////////스페어 점수 계산//////////////////

	for (k = 0; k <= 9; k++)
	{
		for (i = 0; i < 2; i++)
		{
			if (((score[i][0][k] + score[i][1][k] == 10)) && score[i][0][k] != 10)		// 스페어 처리한 경우
				sum[i][k] += 10 + score[i][0][k + 1];		// 다음 프레임 1구 점수가 보너스이다
			else if (score[i][0][k] + score[i][1][k] < 10)								// 스페어 처리에 실패한 경우
				sum[i][k] += score[i][0][k] + score[i][1][k];

		}
	}
	/////////////스트라이크 점수 계산///////////////

	for (k = 0; k <= 9; k++)
	{
		for (i = 0; i < 2; i++)
		{
			if (score[i][0][k] == 10)		// 스트라이크를 친 경우
			{
				sum[i][k] = 10;
				if (score[i][0][k + 1] == 10 && score[i][1][k + 1] == 0)		// 스트라이크를 치고 다음 프레임 1구에서 스트라이크를 친 경우는 그 다음 프레임 1구까지 보너스이다 = 더블, 스트라이크와 더블이 반복되면 터키
					sum[i][k] += 10 + score[i][0][k + 2];
				else if ((score[i][0][k + 1] + score[i][1][k + 1] == 10))	// 스트라이크를 치고 다음 프레임 2구에서 스페어를 친 경우는 10점만 보너스이다
					sum[i][k] += 10;
				else if ((score[i][0][k + 1] + score[i][1][k + 1]) < 10)		// 스트라이크를 치고 다음 프레임에서 스트라이크, 스페어를 둘다 못 친 경우는 다음 2개의 구 점수가 보너스이다
					sum[i][k] += score[i][0][k + 1] + score[i][1][k + 1];
			}
		}
	}

}