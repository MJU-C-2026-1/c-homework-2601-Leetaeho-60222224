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
  
  whiile (1)
    {
      display_menu(); //함수 호출

      printf("원하는 메뉴 번호를 입력하세요 :");
      printf("%d", &menu_choice);

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
        scanf("%s", &user_name);

        printf("며칠 동안의 식단을 기록하시곘습니까? (1~%d일:)", MAX_DAYS);
        scanf("%d", &input_days);

        if (input_days <1 || input_days > MAX_DAYS)
        {
          printf("입력 범위를 벗어났습니다. 메인 메뉴로 돌아갑니다.\n");
          continue;
        }
        
        input_diet_data(input_days);
        print_daily_feedback(username, input_days);
        print_final_analysis(user_naame, input_days);
      }
      
      else
      {
        printf("잘못된 메뉴 번호입니다. 다시 선택해주세요\n");
      }
    }

    return 0;
}

//메뉴 UI 출력
void display_menu()
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
          scanf("%d", $carb_grams[i]);

          printf("단백질(g): ");
          scanf("%d", $pritein_grams[i]);

          printf("지방(g): ");
          scanf("%lf", $fat_grams[i]);

          total_calories[i] = compute_claories(carb_grams[i], protein_grams[i], fat_grams[i]);
          
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
void print_dauly_feedback(char name[], int input_days)
{
  int i;
  printf("\n====================================\n");
  printf(" [%s 님의 일별 상세 결과] \n", user_name);
  printf("\n====================================\n");

  for (i = 0; i < input_days; i++)
  {
    double target_carb = (total_calories * 0.50) / 4.0;
    double target_protein = (total_calories * 0.30) / 4.0;
    double target_carb = (total_calories * 0.20) / 9.0;

    printf("\ㅡ ---%일차 [", i + 1);
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
      if (carb_ratio[i] >= 45.0 && carb_ratio[i]) <=55.0 && 
          protein_ratio[i] >= 25.0 && protein_ratio[i]) <=35.0 &&
          fat_ratio[i] >= 15.0 && fat_ratio[i]) <=25.0
    }
      
  }

  
}








---------------------------------------------------------------------------------




int main()
{
    int menu_choice; // 메뉴 선택 변수

    //무한 루프 적용하여 사용자가 종료를 선택할 때까지 프로그램 반복
    whiile (1)
    {
      printf("====================================\n");
      printf(" 다이어트 점심 칼로리 계산기 \n");
      printf("====================================\n");
      printf("1. 새로운 식단 기록 및 분석 시작\n");
      printf("2. 프로그램 종료\n");
      printf("====================================\n");
      printf("원하는 메뉴 번호를 입력하세요 :");
      printf("%d", &menu_choice);
      
      //2번 선택시 프로글매 종료
      if(menu_choice == 2)
      {
        printf("\n 프로그램을 종료합니다. \n");
        break;
      }

      else if (menu_choice == 1)
      {
        //변수 선언
        
        char user_name[50]; // 사용자 이름 저장 변수
        int input_days; // 원하는 일 수 
        
        //7일 간의 데이터 누적을 위해 배열[DAYS]로 확장
        char category_codes[MAX_DAYS]; // [문자형] 식사 카테고리 코드 [K(한식), W(양식), C(중식), F(패스트푸드), S(샐러드)]
        int  carb_grams[MAX_DAYS]; // [정수형] 탄수화물 섭취량(g)
        int protein_grams[MAX_DAYS]; // [정수형] 단백질 섭취량(g)
        double fat_grams[MAX_DAYS]; // [실수형] 지방 섭취량(g)
        double total_calories[MAX_DAYS]; // [실수형] 계산된 총 칼로리 결과 

        //7일간의 일별 실제 섭취한 탄단지 비율(%) 변수
        double carb_ratio[MAX_DAYS];
        double protein_ratio[MAX_DAYS];
        double fat_ratio[MAX_DAYS];
        
        double weekely_total = 0.0; // 주간 총 섭취 칼로리 누적 변수
        double weekly_avg = 0.0; //주간 일평균 칼로리 변수
        
        int max_day = 0; // 가장 많이 먹은 날
        int min_day = 0; // 가장 적게 먹은 날
        int fast_food_count = 0; // 일주일간 패스트 푸드 총 횟수
        int i;
      
        //프로그램 시작
        printf("환영합니다! 사용자 이름을 입력해주세요 :");
        scanf("%s", &user_name);

        printf("며칠 동안의 식단을 기록하시곘습니까? (1~%d일:)", MAX_DAYS);
        scanf("%d", &input_days);

        if (input_days <1 || input_days > MAX_DAYS)
        {
          printf("입력 범위를 벗어났습니다. 메인 메뉴로 돌아갑니다.\n");
          continue;
        }

        printf("[식사 카테고리 안내] \n"); // 식사 카테고리 안내판
        printf("--------------------------------------------------------------\n");
        printf("K : 한식 / W : 양식 / C: 중식 / F: 패스트푸드 / S : 샐러드\n");
        printf("--------------------------------------------------------------\n");

       //데이터 입력
        for (i = 0; i<input_days; i++)
        {
          printf("[%d일차 점심 입력]\n", i + 1);

          printf("카테고리 (K/W/C/F/S) : ");
          scanf(" %c", &category_codes[i]);

          printf("탄수화물(g): ");
          scanf("%d", $carb_grams[i]);

          printf("단백질(g): ");
          scanf("%d", $pritein_grams[i]);

          printf("지방(g): ");
          scanf("%lf", $fat_grams[i]);

          //칼로리 계산식 (탄*4, 단*4, 지*9)
          total_calories[i] = (carb_grams[i] * 4) + (protein_grams[i] * 4) + (fat_grams[i] * 9.0);
          
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
        
        // 통계 및 연산
        for (i = 0; i<input_days; 1++)
        {
          weekly_total += total_calories[i];
          if (category_codes[i] == 'F' || category_codes[i] == 'f')
          {
            fast_food_count++;
          }

          weekly_avg = weekly_total / input_days; // 입력받은 실제 일수 기준 평균

          for (i = 1; i < input_days; 1++) //최대, 최소 칼로리 일차 
          {
            if (total_calories[i] > total_calories[max_day])
            {
              max_days = i;
            }
            if (total_calories[i] > total_calories[mix_day])
            {
              min_day = i;
            }
          }

          printf("\n====================================\n");
          printf(" [%s 님의 일별 상세 결과] \n", user_name);
          printf("\n====================================\n");
        
          for (i = 0; i<input_days; i++)
          {

          }
        }

        

        if (total_calories <=0)
        {
          printf("\n 섭취한 칼로리가 없습니다. 프로그램을 종료합니다.\n");
          return 0;
        }
        

        

        // 목표 섭취량(g) 계산 (총칼로리 기준 비율 5:3:2로 역산)
        target_carb = (total_calories * 0.50) / 4.0;
        target_protein = (total_calories * 0.30) / 4.0;
        target_carb = (total_calories * 0.20) / 9.0;
        
        //4. 결과 출력
        printf("\n=== ");

        switch (category_code)
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
            printf("알 수 없는 메뉴");
            break;
        }
        
        printf(" 의 칼로리 계산 결과===\n");
        printf("- 탄수화물 %dg : %d kcal\n", carb_grams, carb_grams * 4);
        printf("- 단백질 %dg : %d kcal\n", protein_grams, protein_grams * 4);
        printf("- 지방 %.1fg : %.1f kcal\n", fat_grams, fat_grams * 9.0);
        printf("--------------------------------------------------------------\n");
        printf("▶ 총 섭취 칼로리 : %.1f kcal\n", total_calories);
        //계산된 비율 화면 출력
        printf("▶ 탄/단/지 비율 : %.1f%% / %.1f%%/ %.1f%%\n",carb_ratio, protein_ratio, fat_ratio);
        printf("--------------------------------------------------------------\n");

      //5. 다이어트 피드백
      printf("[영양 정밀 분석]\n");

      // 500kcal 이하
      if (total_calories <= 500.0)
      {
        printf("다이어트에 완벽한 저칼로리 식단입니다.\n");
        
        if(carb_ratio >= 45.0 && carb_ratio <= 55.0 && protein_ratio>=25.0 && protein_ratio <= 35.0 && fat_ratio>= 15.0 && fat_ratio <=25.0)
        {
          printf(" 탄단지 5:3:2 황금비율까지 맞췄습니다.\n");
        }
        else
        {
          printf("피드백:\n");
          //탄수화물 검사
          if (carb_ratio > 55.0)
          {
            printf(" - 탄수화물 초과: 밥이나 면을 약 %.1fg 줄이세요.\n", carb_grams - target_carb);
          }
        if (carb_ratio < 45.0)
          {
            printf(" - 탄수화물 부족: 밥이나 면을 약 %.1fg 늘리세요.\n", target_carb - carb_grams);
          }
          //단백질 검사
          if (protein_ratio > 35.0)
          {
            printf(" -단백질 초과: 고기/계란을 약 %.1fg 줄이세요.\n", protein_grams - target_protein);
          }
          if (protein_ratio < 25.0)
          {
            printf(" -단백질 부족: 고기/계란을 약 %.1fg 늘리세요.\n", target_protein - protein_grams);
          }
          //지방 검사
          if (fat_ratio > 15.0)
          {
            printf(" -지방 초과: 기름진 음식 약 %.1fg 줄이세요.\n", fat_grams - target_fat);
          }
          if (protein_ratio < 25.0)
          {
            printf(" -지방 부족: 견과류 등으로 약 %.1fg 늘리세요.\n", target_fat - fat_grams);
          }
        }
      }
        
      // 800kcal 이하
      else if (total_calories <= 800.0)
      {
        printf("일반적 식단입니다.\n");
        
        if(carb_ratio >= 45.0 && carb_ratio <= 55.0 && protein_ratio>=25.0 && protein_ratio <= 35.0 && fat_ratio>= 15.0 && fat_ratio <=25.0)
        {
          printf(" 칼로리는 무난하고, 탄단지 비율이 훌륭합니다.\n");
        }
        else
        {
          printf("피드백:\n");
          //탄수화물 검사
          if (carb_ratio > 55.0)
          {
            printf(" - 탄수화물 주의: 밥이나 면을 약 %.1fg 줄이세요.\n", carb_grams - target_carb);
          }
        if (carb_ratio < 45.0)
          {
            printf(" - 탄수화물 부족: 밥이나 면을 약 %.1fg 늘리세요.\n", target_carb - carb_grams);
          }
          //단백질 검사
          if (protein_ratio > 35.0)
          {
            printf(" -단백질 주의: 고기/계란을 약 %.1fg 줄이세요.\n", protein_grams - target_protein);
          }
          if (protein_ratio < 25.0)
          {
            printf(" -단백질 부족: 고기/계란을 약 %.1fg 늘리세요.\n", target_protein - protein_grams);
          }
          //지방 검사
          if (fat_ratio > 15.0)
          {
            printf(" -지방 주의: 기름진 음식 약 %.1fg 줄이세요.\n", fat_grams - target_fat);
          }
          if (protein_ratio < 25.0)
          {
            printf(" -지방 부족: 견과류 등으로 약 %.1fg 늘리세요.\n", target_fat - fat_grams);
          }
        }
      }

      //800kcal 초과
      else
      {
        printf("다이어트 기준을 크게 초과한 고칼로리입니다. 내일 운동 필수!\n");
        
        if(carb_ratio >= 45.0 && carb_ratio <= 55.0 && protein_ratio>=25.0 && protein_ratio <= 35.0 && fat_ratio>= 15.0 && fat_ratio <=25.0)
        {
          printf(" 양이 많지만, 비율 자체는 훌륭합니다. 다음엔 양만 줄이세요\n");
        }
        else
        {
          printf("피드백:\n");
          //탄수화물 검사
          if (carb_ratio > 55.0)
          {
            printf(" - 탄수화물 폭탄: 많은 탄수화물은 살로 갑니다! 약 %.1fg 줄이세요!\n", carb_grams - target_carb);
          }
        if (carb_ratio < 45.0)
          {
            printf(" - 탄수화물 부족: 고칼로리인데 탄수화물은 부족하네요. 밥이나 면을 약 %.1fg 늘리세요.\n", target_carb - carb_grams);
          }
          //단백질 검사
          if (protein_ratio > 35.0)
          {
            printf(" -단백질 폭식: 단백질도 많이 먹으면 살찝니다. 약 %.1fg 줄이세요.\n", protein_grams - target_protein);
          }
          if (protein_ratio < 15.0)
          {
            printf(" -단백질 부족: 칼로리만 높고 영양가가 없네요. 고기/계란을 약 %.1fg 늘리세요.\n", target_protein - protein_grams);
          }
          //지방 검사
          if (fat_ratio > 35.0)
          {
            printf(" -지방 폭탄: 혈관이 비명을 지릅니다! 기름진 음식 약 %.1fg 줄이세요.\n", fat_grams - target_fat);
          }
          if (protein_ratio < 25.0)
          {
            printf(" -지방 부족: 지방이 아닌 다른 걸로 과식하셨군요. 견과류 등으로 약 %.1fg 늘리세요.\n", target_fat - fat_grams);
          }
        }
      }

      // 패스트 푸드 경고
        if (category_code == 'F' || category_code =='f')
        {
          printf("경고 : 패스트 푸드를 드셨군요!\n");
          printf("칼로리와 비율이 좋더라도 안심할 수 없습니다.\n");
        }
        return 0;
      }
            }
          
          }


  


 
