/*********************************************************/
/* thirdQuestions.c - See firstQuestions.h for copyright and info        */
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
/* FUNCTION NAME: current                                                  */
/* DESCRIPTION: electric energy/month computation                          */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* float        elenergy_consumed     I                                    */
/* RETURN VALUE:  float                                                    */
/* CHANGES: -                                                              */
/***************************************************************************/

float current(float elenergy_consumed){
float elenergy_price = 0.0f;
printf("||| \tPlease enter the quantity of electric energy, written on the counter, that you consumed this month, measured in w/h:\n");
printf("||| \t");
scanf("%f", &elenergy_consumed);
if (elenergy_consumed>0 && elenergy_consumed<=100)
    { elenergy_price= 0.68*elenergy_consumed;}
    else if (elenergy_consumed>100 && elenergy_consumed<=255)
    {elenergy_price= 0.80*elenergy_consumed;}
        else elenergy_price= 1.30*elenergy_consumed;
    printf("||| \tThis month, you need to pay %.2f lei for the electric energy.\n", elenergy_price);
return elenergy_price;}

/***************************************************************************/
/* FUNCTION NAME: water                                                    */
/* DESCRIPTION: water consumed/month computation                           */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* float         water_consumed    I                                       */
/* RETURN VALUE:  float                                                    */
/* CHANGES: -                                                              */
/***************************************************************************/

float water(float water_consumed){
float water_price=0.0f;
printf("||| \tPlease enter the number of cube meters of water consumed, written on the water counter:\n");
printf("||| \t");
scanf("%f", &water_consumed);
water_price=water_consumed*7.82;
printf("||| \tThis month, you need to pay %.2f lei for water.\n", water_price);
return water_price;
}

/***************************************************************************/
/* FUNCTION NAME: gas                                                      */
/* DESCRIPTION: gas consumed/month computation                             */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* float         gas_consumed     I                                        */
/* RETURN VALUE:  float                                                    */
/* CHANGES: -                                                              */
/***************************************************************************/

float gas(float gas_consumed){
float gas_price=0.0f;
printf("||| \tPlease enter the quantity of gas, written on the counter of gas, that you consumed this month, measured in kWh:\n");
printf("||| \t");
scanf("%f", &gas_consumed);
gas_price= gas_consumed*0.31;
    printf("||| \tThis month, you need to pay %.2f lei for the gas.\n", gas_price);
return gas_price;
}
/***************************************************************************/
/* FUNCTION NAME: rent                                                     */
/* DESCRIPTION: rates/rent questions                                       */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* float*        rate           I                                          */
/* float*        ap_rent        I                                          */
/* RETURN VALUE:  int                                                    */
/* CHANGES: -                                                              */
/***************************************************************************/
int rent(float *rate, float *ap_rent) {
    printf("||| \tDo you have any rates at the bank? y/n\n");
    char c = '\0';
    printf("||| \t");
    scanf(" %c", &c);
    if (c == 'y' || c == 'Y') {
        printf("||| \tPlease enter the monthly price of the rate:\n");
        printf("||| \t");
        scanf("%f", rate);
    } else {
        printf("||| \tIt seems that you don't have any rate. Good for you!\n");
    }
       printf("||| \tDo you pay rent for your apartment? y/n\n");
       printf("||| \t");
     scanf(" %c", &c);
    if (c == 'y' || c == 'Y') {
        printf("||| \tPlease enter the monthly price of the rent:\n");
        printf("||| \t");
        scanf("%f", ap_rent);
    } else {
        printf("||| \tIt seems that you live in your own apartment. Good for you!\n");
    }
    return *rate + *ap_rent;

}
/***************************************************************************/
/* FUNCTION NAME: telephony                                                */
/* DESCRIPTION: telephony questions                        */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* float*        telefonie     I                                           */
/* RETURN VALUE:  int                                                    */
/* CHANGES: -                                                              */
/***************************************************************************/

int telephony(float *telefonie) {
    int choice;
    int subscriptions_number;
    printf("||| \tPlease choose which telephony company are you with from the list:\n");
    printf("||| \t\t\t\t\t\t\t\t Enter 1 if you have a subscription at Digi Mobile\n");
    printf("||| \t\t\t\t\t\t\t\t Enter 2 if you have a subscription at Orange\n");
    printf("||| \t\t\t\t\t\t\t\t Enter 3 if you have a subscription at Telekom\n");
    printf("||| \t");
    scanf("%d", &choice);
    printf("||| \tEnter the number of members that have a subscription at this company:\n");
    printf("||| \t");
    scanf("%d", &subscriptions_number);
    switch (choice) {
        case 1:
            *telefonie = subscriptions_number * 32.99;
            break;
        case 2:
            *telefonie = subscriptions_number * 26.99;
            break;
        case 3:
            *telefonie = subscriptions_number * 29.00;
            break;
    }
    printf("||| \tThis month, you need to pay %.2f lei for the telephony.\n", *telefonie);
    return telefonie;
}

/***************************************************************************/
/* FUNCTION NAME: sum_of_bills                                             */
/* DESCRIPTION: calculates the total sum of the bills                      */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* float        elenergy_price     I                                       */
/* float        water_price        I                                       */
/* float        gas_price          I                                       */
/* float        sumrent            I                                       */
/* float        telefonie          I                                       */
/* RETURN VALUE:  int                                                    */
/* CHANGES: -                                                              */
/***************************************************************************/

int sum_of_bills(float elenergy_price, float water_price, float gas_price, float sumrent, float telefonie){
   float bills_sum;
    bills_sum= telefonie + sumrent + elenergy_price + water_price + gas_price;
    return  bills_sum;
}
