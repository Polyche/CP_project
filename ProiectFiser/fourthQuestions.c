/*********************************************************/
/* fourthQuestions.c - See firstQuestions.h for copyright and info    */
/*********************************************************/

/* System headers and application specific headers: */
#include "firstQuestions.h"

/* Private constants: */

/* Private types: */

/* Private global variables: */

/* Public global variables: */

/* Implementation of the private functions */

/* Implementation of the public functions */

/***************************************************************************/
/* FUNCTION NAME: members                                                  */
/* DESCRIPTION: family members questions                                   */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* int        members_number     I                                         */
/* int        paying_members     I                                         */
/* RETURN VALUE:  int                                                      */
/* CHANGES: -                                                              */
/***************************************************************************/

int members(int members_number, int paying_members){

    printf("||| \tEnter the total number of family members in your family:\n");
    printf("||| \t");
    scanf("%d", &members_number);
    printf("||| \tEnter the number of your family members that are hired and contribute financially to your family :\n");
    printf("||| \t");
    scanf("%d", &paying_members);
    if (members_number != paying_members)
        printf("||| \tSo, it seems that your family has %d adults and %d child/children. What a beautiful family! <3\n", paying_members, (members_number-paying_members));
        else printf("||| \tSo, it seems that your family has %d adults and no children!\n");
    return paying_members;}

/***************************************************************************/
/* FUNCTION NAME: salary_converter                                         */
/* DESCRIPTION: salary calculation after taxes                             */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* float        salary_vefore_taxes     I                                  */
/* float        salary_after_taxes      I                                  */
/* RETURN VALUE:  int                                                      */
/* CHANGES: -                                                              */
/***************************************************************************/

int salary_converter(float salary_before_taxes, float salary_after_taxes){
printf("||| \tPlease enter your family's monthly total salary before taxes are collected by the state.\n");
printf("||| \t");
scanf("%f", &salary_before_taxes);
salary_after_taxes= salary_before_taxes-(0.45*salary_before_taxes);
printf("||| \tSo, your family's total salary after taxes are collected by the state is %.2f.\n", salary_after_taxes);
return salary_after_taxes;
}

/***************************************************************************/
/* FUNCTION NAME: askMoreQuestions                                         */
/* DESCRIPTION: asks extra activities questions                            */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* bool*        hasMedicalSubs    I                                        */
/* bool*        hasGymSubs        I                                        */
/* bool*        hasBeautySubs     I                                        */
/* float*       Medprice          I                                        */
/* float*       Beautyprice       I                                        */
/* float*       Gymprice          I                                        */
/* RETURN VALUE:  void                                                     */
/* CHANGES: -                                                              */
/***************************************************************************/


void askMoreQuestions(float *Medprice, float *Beautyprice, float *Gymprice) {
  char c = '\0';
  printf("||| \tDo you have a monthly subscription to a Medical Center? (y/n) \n");
  printf("||| \t");
  scanf(" %c", &c);
  if (c == 'y' || c == 'Y') {
    printf("||| \tPlease enter the monthly price of the Medical Center subscription:\n");
    printf("||| \t");
    scanf("%f", Medprice);
  } else {
    printf("||| \tIt seems that you don't have any subscription to a medical center.\n");
  }

  printf("||| \tDo you have a monthly subscription to any Gym? (y/n) \n");
  printf("||| \t");
  scanf(" %c", &c);
  if (c == 'y' || c == 'Y') {
    printf("||| \tPlease enter the monthly price of the Gym subscription:\n");
    printf("||| \t");
    scanf("%f", Gymprice);
  } else {
    printf("||| \tIt seems that you don't have any subscription to a gym.\n");
  }

  printf("||| \tDo you have a monthly subscription to any Beauty pack? (y/n) \n");
  printf("||| \t");
  scanf(" %c", &c);
  if (c == 'y' || c == 'Y') {
    printf("||| \tPlease enter the monthly price of the Beauty pack subscription:\n");
    printf("||| \t");
    scanf("%f", Beautyprice);
  } else {
    printf("||| \tIt seems that you don't have any subscription to a beauty pack.\n");
  }
}

/***************************************************************************/
/* FUNCTION NAME: sum_of_activities                                        */
/* DESCRIPTION: sum of all other activities                                */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* float        Beautyprice     I                                          */
/* float        Medprice        I                                          */
/* float        Gymprice        I                                          */
/* RETURN VALUE:  float                                                    */
/* CHANGES: -                                                              */
/***************************************************************************/

float sum_of_activities(float Beautyprice, float Medprice, float Gymprice) {
  float sum = 0;
  sum = Beautyprice + Gymprice + Medprice;
  return sum;
}

/***************************************************************************/
/* FUNCTION NAME: totalSum                                                 */
/* DESCRIPTION: sum of all expenses                                        */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* float        sumBills        I                                          */
/* float        sumInsurance    I                                          */
/* float        sum             I                                          */
/* float        total           I                                          */
/* int          vacationCost    I                                          */
/* RETURN VALUE:  float                                                    */
/* CHANGES: -                                                              */
/***************************************************************************/

float totalSum(float sumbills, int sumInsurance, float sum, float total, int vacationCost){
    float sumOfThese = 0.0f;
    sumOfThese = sumbills + sumInsurance + sum + total + vacationCost;
    printf("||| \tThe total monthly sum of your bills is: %.2f. Quite a lot sadly...\n", sumOfThese);
    return sumOfThese;
}

/***************************************************************************/
/* FUNCTION NAME: moneyLeft                                                */
/* DESCRIPTION: money left from initial salary                             */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* float        money            I                                         */
/* float        salaryTaxed      I                                         */
/* RETURN VALUE:  float                                                      */
/* CHANGES: -                                                              */
/***************************************************************************/

float moneyLeft(float money, int salaryTaxed){
///salaryTaxed = salary after taxes, money = money spent this month
    return salaryTaxed - money;
}

/***************************************************************************/
/* FUNCTION NAME: percentages                                              */
/* DESCRIPTION: computes percentages of everything                         */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* float        sumbills            I                                      */
/* int          sumInsurance        I                                      */
/* float        sum                 I                                      */
/* float        total               I                                      */
/* int          vacationCost        I                                      */
/* int          salaryTaxed         I                                      */
/* float        money               I                                      */
/* float        allTaxesCombined    I                                      */
/* RETURN VALUE:  void                                                     */
/* CHANGES: -                                                              */
/***************************************************************************/

void percentages(float sumbills, int sumInsurance, float sum, float total, int vacationCost, int salaryTaxed, float money, float allTaxesCombined){
    printf("||| \tHere are the percentages that show you how you spent your money this month.\n");
    printf("||| \tThis month %.2f %c of your income went towards paying bills. Truly tragic!\n", (sumbills*100)/money, '%');
    printf("||| \tThis month %.2f %c of your income went towards paying your insurances. Terrible...\n", ((float)sumInsurance*100)/money, '%');
    printf("||| \tThis month %.2f %c of your income went towards your extra subscriptions. That's not a problem!\n", (sum*100)/money, '%');
    printf("||| \tThis month %.2f %c of your income went towards your streaming subscriptions. Maybe watch less Netflix. Just saying.\n", (total*100)/money, '%');
    printf("||| \tThis month %.2f %c of your income went towards your upcoming vacation. Awesome!\n", ((float)vacationCost*100)/money, '%');
    printf("||| \tThis month after all your expenses you still have %f %c of your initial salary. You are doing good!\n", ((money-allTaxesCombined)*100)/money, '%');

}
