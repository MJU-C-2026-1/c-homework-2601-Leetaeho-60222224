/* 
  파일이름:  칼로리 계산기
  작 성 자: 이태호
  하 는 일: 칼로리 계산기
*/
#include <stdio.h>
#include <string.h>

#define DAYS 7

int main()
{
  //1. 변수 선언

  char user_name[50]; //사용자 이름 저장 변수

  //7일 간의 데이터 누적을 위해 배열[DAYS]로 확장
  char category_codes[DAYS]; // [문자형] 식사 카테고리 코드 [K(한식), W(양식), C(중식), F(패스트푸드), S(샐러드)]
  int  carb_grams[DAYS]; // [정수형] 탄수화물 섭취량(g)
  int protein_grams[DAYS]; // [정수형] 단백질 섭취량(g)
  double fat_grams[DAYS]; // [실수형] 지방 섭취량(g)
  double total_calories[DAYS]; // [실수형] 계산된 총 칼로리 결과 

  //7일간의 일별 실제 섭취한 탄단지 비율(%) 변수
  double carb_ratio[DAYS];
  double protein_ratio[DAYS];
  double fat_ratio[DAYS];
  
  double weekely_total = 0.0; // 주간 총 섭취 칼로리 누적 변수
  double weekly_avg = 0.0; //주간 일평균 칼로리 변수
  int max_day = 0; // 가장 많이 먹은 날 인덱스 번호
  int min_day = 0; // 가장 적게 먹은 날 인덱스 번호
  int fast_food_count = 0; // 일주일간 패스트 푸드 총 횟수 카운트 변수

  int i;
 
  //2. 프로그램 시작 및 카테고리 안내판 출력
  printf("====================================\n");
  printf(" 다이어트 점심 칼로리 계산기 \n");
  printf("====================================\n");
  
  printf("[식사 카테고리 안내] \n"); // 식사 카테고리 안내판
  printf("--------------------------------------------------------------\n");
  printf("K : 한식 / W : 양식 / C: 중식 / F: 패스트푸드 / S : 샐러드\n");
  printf("--------------------------------------------------------------\n");

  printf("1. 오늘 먹은 점심의 카테고리 코드를 입력하세요: ");
  scanf(" %c", &category_code);

  printf("2. 탄수화물 섭취량(g)을 정수로 입력하세요: ");
  scanf("%d", &carb_grams);

  printf("3. 단백질 섭취량(g)을 정수로 입력하세요: ");
  scanf("%d", &protein_grams);
  
  printf("4. 지방 섭취량(g)을 소수점 포함해서 입력하세요: ");
  scanf("%lf", &fat_grams);

  //3. 산술 연산 처리 (순차 구조 유지)
  total_calories = (carb_grams * 4) + (protein_grams * 4) + ( fat_grams * 9.0);

  if (total_calories <=0)
  {
    printf("\n 섭취한 칼로리가 없습니다. 프로그램을 종료합니다.\n");
    return 0;
  }
  

  // 실제 비율(%) 계산 = (각 영양소 칼로리 / 총 칼로리) * 100
  carb_ratio = (carb_grams * 4.0) / total_calories * 100;
  protein_ratio = ( protein_grams * 4.0) / total_calories * 100;
  fat_ratio = (fat_grams * 9.0) / total_calories * 100;

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
