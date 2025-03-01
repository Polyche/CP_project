/*********************************************************/
/* secondQuestions.c - See firstQuestions.h for copyright and info        */
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
/* FUNCTION NAME: askAboutCarInsurance                                     */
/* DESCRIPTION: asks the user if they have car Insurance                   */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* char*          hasCarInsurance     I      car insurance question        */
/* int*           carInsuranceCost     I     cost of it                    */
/* RETURN VALUE:  int                                                      */
/* CHANGES: -                                                              */
/***************************************************************************/

int askAboutCarInsurance(char* hasCarInsurance, int* carInsuranceCost) {
  printf("||| \tDo you have car insurance (Y/N)? \n");
  printf("||| \t");
  scanf(" %c", hasCarInsurance);

  if (*hasCarInsurance == 'Y' || *hasCarInsurance == 'y' ) {
    printf("||| \tHow much do you pay for car insurance per month? lei ");
    scanf("%d", carInsuranceCost);
  }
  return carInsuranceCost;
}

/***************************************************************************/
/* FUNCTION NAME: askAboutMedicalInsurance                                 */
/* DESCRIPTION: asks the user if they have medical Insurance               */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* char*          hasMedicalInsurance    I   medical insurance question    */
/* int*           medicalInsuranceCost   I   cost of it                    */
/* RETURN VALUE:  int                                                      */
/* CHANGES: -                                                              */
/***************************************************************************/

int askAboutMedicalInsurance(char* hasMedicalInsurance, int* medicalInsuranceCost) {
  printf("||| \tDo you have medical insurance (Y/N)? \n");
  printf("||| \t");
  scanf(" %c", hasMedicalInsurance);

  if (*hasMedicalInsurance == 'Y' || *hasMedicalInsurance == 'y') {
    printf("||| \tHow much do you pay for medical insurance per month? lei ");
    scanf("%d", medicalInsuranceCost);
  }
  return medicalInsuranceCost;
}

/***************************************************************************/
/* FUNCTION NAME: sumOfInsurance                                           */
/* DESCRIPTION: calculates the sum of the insurances                       */
/* ARGUMENT LIST:                                                          */
/* Argument        Type       IO        Description                        */
/* ------------- ----------- -------- ----------------------               */
/* int          medicalInsuranceCost  I     cost of it                     */
/* int          carInsuranceCost      I     cost of it                     */
/* RETURN VALUE:  int                                                      */
/* CHANGES: -                                                              */
/***************************************************************************/

int sumOfInsurance(int carInsuranceCost, int medicalInsuranceCost){
    return carInsuranceCost + medicalInsuranceCost;
}
