/***********************************************************/
/* firstQuestions.h - Header file for module               */
/* Copyright: 2023                                         */
/* License: Tehnical University of Cluj-Napoca             */
/* Author: Pal Robert and Cuc Alexia                       */
/* Version: 01-08-2023                                     */
/***********************************************************/

#ifndef FIRSTQUESTIONS_H_INCLUDED
#define FIRSTQUESTIONS_H_INCLUDED


/* Headers required by the following definitions/declarations: */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/* Constant definitions: */

/* Types definitions: */

/* Global variables declarations: */

struct Subscription {
  char name[100];
  float price;
};

extern void runProgram();
extern int check_login(char *, char *);
extern int askSubscriptionQuestions();
extern struct Subscription ask_subscription();
extern float total_price(struct Subscription subscriptions[], int, float);
extern int vacation_plan();
extern int askAboutCarInsurance(char*, int* );
extern int askAboutMedicalInsurance(char*, int*);
extern int sumOfInsurance(int, int);
extern float current(float);
extern float water(float);
extern float gas(float);
extern int rent(float *, float *);
extern void askMoreQuestions(float *, float *, float *);
extern int sum_of_bills(float, float, float, float, float );
extern float sum_of_activities(float, float, float);
extern int members(int, int);
extern int salary_converter(float, float);
extern float totalSum(float , int , float , float , int);
extern float moneyLeft(float, int);
extern void percentages(float , int , float , float , int, int, float, float);

#endif // FIRSTQUESTIONS_H_INCLUDED
