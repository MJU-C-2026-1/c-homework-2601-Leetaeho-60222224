/* 
  파일이름:  칼로리 계산기
  작 성 자: 이태호
  하 는 일: 칼로리 계산기
*/
#include <stdio.h>

int main()
{
  //1. 변수 선언
  char category_code; // [문자형] 식사 카테고리 코드 [K(한식), W(양식), C(중식), F(패스트푸드), S(샐러드)]
  int  crab_grams; // [정수형] 탄수화물 섭취량(g)
  int protein_grams; // [정수형] 단백질 섭취량(g)
  double fat_grams; // [실수형] 지방 섭취량(g)
  double total_calories; // [실수형] 계산된 총 칼로리 결과 

  //2. 프로그램 시작 및 카테고리 안내판 출력
  printf("====================================\n");
  printf(" 다이어트 점심 칼로리 계산기 \n");
  printf("====================================\n");
  
  printf("[식사 카테고리 안내] \n"); // 식사 카테고리 안내판
  printf("--------------------------------------------------------------\n");
  printf("K : 한식 / W : 양식 / C: 중식 / F: 패스트푸드 / S : 샐러드\n");
  printf("--------------------------------------------------------------\n");

  printf(" 1. 오늘 먹은 점심의 카테고리 코드를 입력하세요: ");
  scanf("%c", &category_code);

  printf("2. 탄수화물 섭취량(g)을 정수로 입력하세요: ");
  scanf("%d", &crab_grams);

  printf("3. 단백질 섭취량(g)을 정수로 입력하세요: ");
  scanf("%d", &protein_grams);
  
  printf("4. 지방 섭취량(g)을 소수점 포함해서 입력하세요: ");
  scanf("%lf", &fat_grams);

  //3. 산술 연산 처리 (순차 구조 유지)
  total_calories = (crab_grams * 4) + (protein_grams * 4) + ( fat_grams * 9.0);

  //4. 결과 출력
  printf("\n=== 카테고리 '%c'의 칼로리 계산 결과===\n", category_code );
  printf("- 탄수화물 %dg : %dg kcal\n", crab_grams, crab_grams * 4);
  printf("- 단백질 %dg : %dg kcal\n", protein_gram, protein_gram * 4);
  printf("- 지방 %.lfg : %lfg kcal\n", fat_grams, fat_grams * 9.0);
  printf("--------------------------------------------------------------\n");
  printf("▶ 총 섭취 칼로리 : %.lf kcal\n", total_calories);
  printf("==============================================================\n");
  
  return 0;
}
