/* 
  파일이름:  칼로리 계산기
  작 성 자: 이태호
  하 는 일: 칼로리 계산기
*/
#include <stdio.h>
#include <string.h>

#define MAX_DAYS 7

char category_codes[MAX_DAYS]; // [문자형] 식사 카테고리 코드 [K(한식), W(양식), C(중식), F(패스트푸드), S(샐러드)]
int  carb_grams[MAX_DAYS]; // [정수형] 탄수화물 섭취량(g)
int protein_grams[MAX_DAYS]; // [정수형] 단백질 섭취량(g)
double fat_grams[MAX_DAYS]; // [실수형] 지방 섭취량(g)
double total_calories[MAX_DAYS]; // [실수형] 계산된 총 칼로리 결과 

//7일간의 일별 실제 섭취한 탄단지 비율(%) 변수
double carb_ratio[MAX_DAYS];
double protein_ratio[MAX_DAYS];
double fat_ratio[MAX_DAYS];       

void disply_menu(); // 메뉴 UI 출력
double compute_calories(int carb, int protein, double fat); // 칼로리 연산
void input_diet_data(int input_days); // 식단 데이터 입력
void print_daily_feedback(char name[], int input_days); // 일별 영양 피드백
void print_final_analysis(char name[], int input_days); // 종합 통계

//메인 함수
int main()
{
  int menu_choice; // 메뉴 선택 변수
  
  while (1)
    {
      disply_menu(); //함수 호출

      printf("원하는 메뉴 번호를 입력하세요 :");
      scanf("%d", &menu_choice);

      if (menu_choice == 2)
      {
        printf("\n 프로그램을 종료합니다. \n");
        break;
      }
      
      else if (menu_choice == 1)
      {
        char user_name[50];
        int input_days; // 원하는 일수 저장 변수

        printf("환영합니다! 사용자 이름을 입력해주세요 :");
        scanf("%s", user_name);

        printf("며칠 동안의 식단을 기록하시곘습니까? (1~%d일:)", MAX_DAYS);
        scanf("%d", &input_days);

        if (input_days <1 || input_days > MAX_DAYS)
        {
          printf("입력 범위를 벗어났습니다. 메인 메뉴로 돌아갑니다.\n");
          continue;
        }
        
        input_diet_data(input_days);
        print_daily_feedback(user_name, input_days);
        print_final_analysis(user_name, input_days);
      }
      
      else
      {
        printf("잘못된 메뉴 번호입니다. 다시 선택해주세요\n");
      }
    }

    return 0;
}

//메뉴 UI 출력
void disply_menu()
{
  printf("====================================\n");
  printf(" 다이어트 점심 칼로리 계산기 \n");
  printf("====================================\n");
  printf("1. 새로운 식단 기록 및 분석 시작\n");
  printf("2. 프로그램 종료\n");
  printf("====================================\n");
}

//칼로리 계산
double compute_calories(int carb, int protein, double fat)
{
  //탄수화물*4, 단백질*4, 지방*9.0 
  return (carb * 4) + (protein * 4) + (fat * 9.0); 
}

//영양소 데이터 입력 및 비율 연산
void input_diet_data(int input_days)
{
  int i;

  printf("[식사 카테고리 안내] \n"); // 식사 카테고리 안내판
  printf("--------------------------------------------------------------\n");
  printf("K : 한식 / W : 양식 / C: 중식 / F: 패스트푸드 / S : 샐러드\n");
  printf("--------------------------------------------------------------\n");

  for (i = 0; i<input_days; i++)
        {
          printf("[%d일차 점심 입력]\n", i + 1);

          printf("카테고리 (K/W/C/F/S) : ");
          scanf(" %c", &category_codes[i]);

          printf("탄수화물(g): ");
          scanf("%d", &carb_grams[i]);

          printf("단백질(g): ");
          scanf("%d", &protein_grams[i]);

          printf("지방(g): ");
          scanf("%lf", &fat_grams[i]);

          total_calories[i] = compute_calories(carb_grams[i], protein_grams[i], fat_grams[i]);
          
          if (total_calories[i] > 0)
          {
          // 실제 비율(%) 계산 = (각 영양소 칼로리 / 총 칼로리) * 100
          carb_ratio[i] = (carb_grams[i] * 4.0) / total_calories[i] * 100;
          protein_ratio[i] = ( protein_grams[i] * 4.0) / total_calories[i] * 100;
          fat_ratio[i] = (fat_grams[i] * 9.0) / total_calories[i] * 100;
          }
          else
          {
            carb_ratio[i] = protein_ratio[i] = fat_ratio[i] = 0.0;
          }
          printf("-> %.1f kcal 기록 완료.\n", total_calories[i]);
        }
}

//일별 탄단지 황금비율 매칭 및 피드백 출력
void print_daily_feedback(char name[], int input_days)
{
  int i;
  printf("\n====================================\n");
  printf(" [%s 님의 일별 상세 결과] \n", name);
  printf("\n====================================\n");

  for (i = 0; i < input_days; i++)
  {
    double target_carb = (total_calories[i] * 0.50) / 4.0;
    double target_protein = (total_calories[i] * 0.30) / 4.0;
    double target_fat = (total_calories[i] * 0.20) / 9.0;

    printf("\n ---%d일차 [", i + 1);
    switch (category_codes[i])
    {
      case 'K': case'k':
        printf("한식");
        break;
      case 'W': case'w':
        printf("양식");
        break;
      case 'C': case'c':
        printf("중식");
        break;
      case 'F': case'f':
        printf("패스트푸드");
        break;
      case 'S': case's':
        printf("샐러드");
        break;
      default:
        printf("기타");
        break;
      }
    
    printf("] ---\n");

    printf(" 탄수화물 : %dg | 단백질 : %dg | 지방 : %.1fg\n", carb_grams[i], protein_grams[i], fat_grams[i]);
    printf("총 칼로리 : %.1fkcal (탄수화물 : %.1f%% | 단백질 : %.1f%% | 지방 : %.1f%%)\n", total_calories[i], carb_ratio[i], protein_ratio[i], fat_ratio[i]);

    if (total_calories[i] > 0)
    {
      if (carb_ratio[i] >= 45.0 && carb_ratio[i] <=55.0 && protein_ratio[i] >= 25.0 && protein_ratio[i] <=35.0 &&fat_ratio[i] >= 15.0 && fat_ratio[i] <=25.0)
      {
        printf(" [피드백]\n 탄단지 황금비율이 완벽합니다.\n");
      }

      else
      {
        printf("[상세 피드백]\n");
        {
          //탄수화물 검사
          if (carb_ratio[i] > 55.0)
          {
            printf(" - 탄수화물 초과: 밥이나 면을 약 %.1fg 줄이세요.\n", carb_grams[i] - target_carb);
          }
          if (carb_ratio[i] < 45.0)
          {
            printf(" - 탄수화물 부족: 밥이나 면을 약 %.1fg 늘리세요.\n", target_carb - carb_grams[i]);
          }
          //단백질 검사
          if (protein_ratio[i] > 35.0)
          {
            printf(" -단백질 초과: 고기/계란을 약 %.1fg 줄이세요.\n", protein_grams[i] - target_protein);
          }
          if (protein_ratio[i] < 25.0)
          {
            printf(" -단백질 부족: 고기/계란을 약 %.1fg 늘리세요.\n", target_protein - protein_grams[i]);
          }
          //지방 검사
          if (fat_ratio[i] > 25.0)
          {
            printf(" -지방 초과: 기름진 음식 약 %.1fg 줄이세요.\n", fat_grams[i] - target_fat);
          }
          if (fat_ratio[i] < 15.0)
          {
            printf(" -지방 부족: 견과류 등으로 약 %.1fg 늘리세요.\n", target_fat - fat_grams[i]);
          }
        }
      }
    }
    
    if (category_codes[i] == 'F' || category_codes[i] == 'f')
    {
      printf("경고 : 패스트 푸드를 드셨군요! 칼로리와 지방이 좋더라도 안심할 수 없습니다.");
    }
  }
}

// 종합 분석 출력
void print_final_analysis(char name[], int input_days)
{
  double weekly_total = 0.0; // 주간 총 섭취 칼로리 누적 변수
  double weekly_avg = 0.0; //주간 일평균 칼로리 변수
        
  int max_day = 0; // 가장 많이 먹은 날
  int min_day = 0; // 가장 적게 먹은 날
  int fast_food_count = 0; // 일주일간 패스트 푸드 총 횟수
  int i;

  for (i = 0; i < input_days; i++)
  {
    weekly_total += total_calories[i];

    if (category_codes[i] == 'F' || category_codes[i] == 'f')
    {
      fast_food_count++;
    }
  }

  weekly_avg = weekly_total / input_days; // 입력받은 실제 일수 기준 평균

  for (i = 1; i < input_days; i++) //최대, 최소 칼로리 일차 
  {
    if (total_calories[i] > total_calories[max_day])
    {
      max_day = i;
    }
    if (total_calories[i] < total_calories[min_day])
    {
      min_day = i;
    }
  }

  printf("\n====================================\n");
  printf("[%s 님의 %d일간 종합 분석\n]", name, input_days);
  printf("\n====================================\n");
  
  printf("%d일간 총 섭취 칼로리 : %.1f kcal\n", input_days, weekly_total);
  printf(" 일 평균 칼로리 : %.1f kcal\n", weekly_avg);

  if (input_days > 1)
  {
    printf("가장 많이 먹은 날: %d일차 (%.1f kcal)\n", max_day +1, total_calories[max_day]);
    printf("가장 적게 먹은 날: %d일차 (%.1f kcal)\n", min_day +1, total_calories[min_day]);
  }

  printf(" 패스트푸드 섭취 횟수 : %d회", fast_food_count);
  if (fast_food_count >=3)
  {
    printf("이번 기간 패스트 푸드가 너무 많이요.");
  }
  else if (fast_food_count >=1)
  {
    printf("주의하세요.");
  }
  else
  {
    printf("훌륭합니다.");
  }

  printf("\n[종합 평가]\n");
  if (weekly_avg <= 500.0)
  {
    printf("평균 칼로리가 낮습니다! 영양 부족 주의!\n");
  }
  else if(weekly_avg <= 800)
  {
    printf("식단 관리 훌륭합니다! 유지하세요!");
  }
  else
  {
    printf("평균 칼로리가 높습니다! 식단 조절 필수!");
  }

  printf("\n====================================\n");
}