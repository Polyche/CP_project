/*********************************************************/
/* firstQuestions.c - See firstQuestions.h for copyright and info        */
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
/* FUNCTION NAME: runProgram                                               */
/* DESCRIPTION: runs the whole program/basically the main function         */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* RETURN VALUE:  void                                                     */
/* CHANGES: -                                                              */
/***************************************************************************/

void runProgram(){
char id[20];
  char password[20];
  char response = '\0';
  char c = '\0';
  char hasCarInsurance = '\0', hasMedicalInsurance = '\0';

  bool hasPassed;

  float netflixBill = 0.0f, disneyBill = 0.0f, hboBill = 0.0f, spotifyBill = 0.0f;
  float allTaxesCombined = 0.0f;
  float salaryTaxed = 0.0f;
  float sumOfSubscriptions = 0.0f;
  float Beautyprice = 0.0f, Medprice = 0.0f, Gymprice = 0.0f;
  float sum = 0.0f;
  float elenergy_price=0.0f, water_price=0.0f ,gas_price=0.0f, sumrent=0.0f, telefonie=0.0f;
  float energie=0.0f;
  float sumaRate = 0.0f;
  float currentCost = 0.0f;
  float salary_before_taxes = 0.0f;
  float salary_after_taxes = 0.0f;
  float money = 0.0f;
  float gaz=0.0f, gazCost = 0.0f;
  float apa=0.0f, apaCost = 0.0f;
  float ratebanca = 0.0f, chirie = 0.0f;
  float sumbills=0.0f;

  int num_subscriptions = 0;
  int carInsuranceCost = 0, medicalInsuranceCost = 0;
  int sumInsurance = 0;
  int members_number = 0;
  int paying_members = 0;
  int vacationCost = 0;

  struct Subscription subscriptions[100];

  printf("\t\t\t\t\t _____         _   _   _        _   _ _ _            _         _     _           \n");
  printf("\t\t\t\t\t|     |___ ___| |_| |_| |_ _   | |_|_| | |   ___ ___| |___ _ _| |___| |_ ___ ___ \n");
  printf("\t\t\t\t\t| | | | . |   |  _|   | | | |  | . | | | |  |  _| .'| |  _| | | | .'|  _| . |  _|\n");
  printf("\t\t\t\t\t|_|_|_|___|_|_|_| |_|_|_|_  |  |___|_|_|_|  |___|__,|_|___|___|_|__,|_| |___|_|  \n");
  printf("\t\t\t\t\t                        |___|                                                    \n");
  printf("||| \tHello and welcome to our program. \n||| \tThis program helps you calculate and manage your monthly bills/income.\n");
  printf("||| \tEnter your login credentials. You will find these in the code, in the firstQuestions.c module(line 33).\n");

  while (1) {
    printf("||| \tEnter your ID: ");
    scanf("%s", id);

    printf("||| \tEnter your password: ");
    scanf("%s", password);

        if (check_login(id, password)) {
            printf("||| \tAccess granted.\n");
            hasPassed = true;
            break;
    }       else {
                hasPassed = false;
                printf("||| \tAccess denied.\n");
    }
  }

    members(members_number, paying_members);

    money = salary_converter(salary_before_taxes, salary_after_taxes);

    printf("||| \tNow you will need to enter some information about your bills for this month.\n");

    currentCost = current(energie);

    apaCost = water(apa);

    gazCost = gas(gaz);

    telephony(&telefonie);

    sumaRate = rent(&ratebanca, &chirie);

   printf("||| \tIt seems that you pay %.2f lei monthly to the bank and %.2f to the owner of your apartment.\n", ratebanca, chirie);

    sumbills=sum_of_bills(currentCost, apaCost, gazCost, sumaRate, telefonie);

    printf("||| \tYour total sum of this month's bills is: %.2f lei\n", sumbills);

    askAboutCarInsurance(&hasCarInsurance, &carInsuranceCost);

    askAboutMedicalInsurance(&hasMedicalInsurance, &medicalInsuranceCost);

    sumInsurance = sumOfInsurance(carInsuranceCost, medicalInsuranceCost);

  printf("||| \tYou pay for insurances: %d lei. \n", sumInsurance);

  printf("||| \tDo you have any monthly subscriptions to these streaming services? (y/n) \n");
  printf("||| \t\t\t\t\t\t\t\t//Netflix//Disney+//HBO//Spotify//\n");

  while (c != 'y' && c != 'Y' && c != 'n' && c != 'N') {
    printf("||| \t");
    scanf(" %c", &c);
    if (c != 'y' && c != 'Y' && c != 'n' && c != 'N'){
      printf("||| \tInvalid input. Please enter 'y' or 'n': \n");
    }
  }
  if (c == 'y' || c == 'Y') {
    sumOfSubscriptions = askSubscriptionQuestions();
  } else if (c == 'n' || c == 'N') {
    printf("||| \tOK, thank you for your answer.\n");
  }

  printf("||| \tDo you have any other monthly subscriptions (Y/N)? \n");
  printf("||| \t\t\t\t\t\t\t\t//YT Premium//iCloud//Amazon Prime//etc.//\n");
  printf("||| \t");
  scanf(" %c", &response);


  while (response == 'Y' || response == 'y') {
    subscriptions[num_subscriptions] = ask_subscription();
    num_subscriptions++;

    printf("||| \tDo you have any other monthly subscriptions (Y/N)? \n");
    printf("||| \t");
    scanf(" %c", &response);
  }

  if (num_subscriptions > 0) {
    printf("||| \tYour subscriptions are:\n");
    for (int i = 0; i < num_subscriptions; i++) {
      printf("||| \t - %s: %.2f lei \n", subscriptions[i].name, subscriptions[i].price);
    }
  } else {
    printf("||| \tYou do not have any other monthly subscriptions.\n");
  }

  float total = total_price(subscriptions, num_subscriptions, sumOfSubscriptions);

    printf("||| \tThe total cost of all your subscriptions is %.2f lei\n", total);
    c = '\0';
      printf("||| \tDo you have any monthly subscriptions to one of these? (y/n) \n");
      printf("||| \t\t\t\t\t\t//Medical/Clinic Subscription // Gym Subscription // Beauty Pack Subscription//\n");
      printf("||| \t");
      scanf(" %c", &c);
  if (c == 'y' || c == 'Y') {
    askMoreQuestions(&Medprice, &Beautyprice, &Gymprice);

    sum = sum_of_activities(Beautyprice, Medprice, Gymprice);

    printf("||| \tThe sum of the monthly taxes for extra activities is %.2f\n", sum);
  }     else {
        printf("||| \tOK, thank you for your answer.\n");
  }

        vacationCost = vacation_plan();

        allTaxesCombined = totalSum(sumbills, sumInsurance, sum, total, vacationCost);

        salaryTaxed = moneyLeft(allTaxesCombined, money);
        ///salaryTaxed = money left, money = salary(net), allTaxesCombined = all taxes combined
   printf("||| \tThis month, you have %.2f money left, out of your total of %.2f. \n", salaryTaxed, money);
        percentages(sumbills,sumInsurance,sum,total,vacationCost,salaryTaxed,money, allTaxesCombined);
        printf("||| \tUse that money to treat yourself!");


 printf("\t\t\t                                                                                                                __ \n");
 printf("\t\t\t _____ _           _                     ___                                   _   _           _   _           |  |\n");
 printf("\t\t\t|_   _| |_ ___ ___| |_    _ _ ___ _ _   |  _|___ ___    _ _ ___ _ _ ___    ___| |_| |_ ___ ___| |_|_|___ ___   |  |\n");
 printf("\t\t\t  | | |   | .'|   | '_|  | | | . | | |  |  _| . |  _|  | | | . | | |  _|  | .'|  _|  _| -_|   |  _| | . |   |  |__|\n");
 printf("\t\t\t  |_| |_|_|__,|_|_|_,_|  |_  |___|___|  |_| |___|_|    |_  |___|___|_|    |__,|_| |_| |___|_|_|_| |_|___|_|_|  |__|\n");
 printf("\t\t\t                         |___|                         |___|                                                       \n");




}
/***************************************************************************/
/* FUNCTION NAME: check_login                                              */
/* DESCRIPTION: login system                                               */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* char*          id           I        program id                         */
/* char*          password     I        program password                   */
/* RETURN VALUE:  int                                                      */
/* CHANGES: -                                                              */
/***************************************************************************/

int check_login(char *id, char *password) {
  if (strcmp(id, "studentUTCN") == 0 && strcmp(password, "CJCP") == 0) {
    return 1;
  }     else {
        return 0;
  }
}
/***************************************************************************/
/* FUNCTION NAME: askSubscriptionQuestions                                 */
/* DESCRIPTION: asks subscription questions                                */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* bool*          hasNetflix   I        ask Netlfix question               */
/* bool*          hasDisney+   I        ask Disney+ question               */
/* bool*          hasHBO       I        ask HBO question                   */
/* bool*          hasSpotify   I        ask spotify question               */
/* RETURN VALUE:  int                                                      */
/* CHANGES: -                                                              */
/***************************************************************************/

int askSubscriptionQuestions() {
  char c = '\0';
  int netflixPlan, spotifyPlan;
  float netflixBill = 0.0f, disneyBill = 0.0f, hboBill = 0.0f, spotifyBill = 0.0f;
  printf("||| \tDo you have a subscription to Netflix? (y/n) \n");
  printf("||| \t");
  scanf(" %c", &c);
  if (c == 'y' || c == 'Y') {
    printf("||| \tWhich monthly plan do you have? Here is a list: \n");
    printf("||| \t\t\t\t\t\t\t\t Enter 1 for Minimum = 7.99lei/month\n");
    printf("||| \t\t\t\t\t\t\t\t Enter 2 for Standard = 9.99lei/month\n");
    printf("||| \t\t\t\t\t\t\t\t Enter 3 for Premium = 11.99lei/month\n");
    printf("||| \t");
    scanf("%d", &netflixPlan);
    if(netflixPlan == 1){
        netflixBill = 7.99f;
    }
        else if(netflixPlan == 2){
            netflixBill = 9.99f;
        }
            else
                netflixBill = 11.99f;
        } else {
            printf("||| \tYou don't have a Netflix subscription. \n");
            netflixBill = 0.0f;
  }

  printf("||| \tDo you have a subscription to Disney+? (y/n)\n");
  printf("||| \t");
  scanf(" %c", &c);
  if (c == 'y' || c == 'Y') {
    disneyBill = 5.99f;
    printf("||| \tThe subscription for Disney+ is 5.99lei/month.\n");
  }     else {
        printf("||| \tYou don't have a Disney+ subscription. \n");
        disneyBill = 0.0f;
  }

  printf("||| \tDo you have a subscription to HBO? (y/n)\n");
  printf("||| \t");
  scanf(" %c", &c);
  if (c == 'y' || c == 'Y') {
    hboBill = 4.99f;
    printf("||| \tThe subscription for HBO is 4.99lei/month.\n");
  }     else {
        printf("||| \tYou don't have a HBO subscription. \n");
        hboBill = 0.0f;
  }

  printf("||| \tDo you have a subscription to Spotify? (y/n) \n");
  printf("||| \t");
  scanf(" %c", &c);
  if (c == 'y' || c == 'Y') {
    printf("||| \tWhich monthly plan do you have? Here is a list: \n");
    printf("||| \t\t\t\t\t\t\t\t Enter 1 for Premium = 4.99lei/month\n");
    printf("||| \t\t\t\t\t\t\t\t Enter 2 for Premium for students = 2.49lei/month\n");
    printf("||| \t");
    scanf("%d", &spotifyPlan);
    if(spotifyPlan == 1)
        spotifyBill = 4.99f;
        else
            spotifyBill = 2.49f;
  }     else {
        printf("||| \tYou don't have a Spotify subscription. \n");
        spotifyBill = 0.0f;
  }
return netflixBill + spotifyBill + disneyBill + hboBill;
}

/***************************************************************************/
/* FUNCTION NAME: ask_subscription                                         */
/* DESCRIPTION: asks for other subscriptions                               */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* RETURN VALUE:  void                                                     */
/* CHANGES: -                                                              */
/***************************************************************************/

struct Subscription ask_subscription(void) {
  struct Subscription subscription;
  printf("||| \tWhat is the name of the subscription?\n");
  printf("||| \t");
  scanf("%s", subscription.name);
  printf("||| \tHow much do you pay every month for it?\n");
  printf("||| \t");
  scanf("%f", &subscription.price);
  return subscription;
}

/***************************************************************************/
/* FUNCTION NAME: total_price                                              */
/* DESCRIPTION: sum of all subscriptions                                   */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* struct       subscriptions         I                                    */
/* int          num_subscriptions     I                                    */
/* float        sumOfSubscriptions    I                                    */
/* RETURN VALUE:  float                                                    */
/* CHANGES: -                                                              */
/***************************************************************************/

float total_price(struct Subscription subscriptions[], int num_subscriptions, float sumOfSubscriptions) {
  float total = 0.0f;
  for (int i = 0; i < num_subscriptions; i++) {
    total += subscriptions[i].price;
  }
  return total + sumOfSubscriptions;
}

/***************************************************************************/
/* FUNCTION NAME: vacation_plan                                            */
/* DESCRIPTION: asks vacation questions                                    */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* RETURN VALUE:  int                                                      */
/* CHANGES: -                                                              */
/***************************************************************************/

int vacation_plan() {
  char decision;
  float money;

  printf("||| \tDo you want to go on vacation this year? (Y/N): \n");
  printf("||| \t");
  scanf(" %c", &decision);

  if (decision == 'Y' || decision == 'y') {
    printf("||| \tHow much money do you want to put away this month?: \n");
    printf("||| \t");
    scanf("%f", &money);
    printf("||| \tOk, you will put away %.2f lei this month.\n", money);
  } else {
    printf("||| \tOk, so you don't plan on going on vacation this year.\n");
  }
  return money;
}
