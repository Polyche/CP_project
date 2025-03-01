#include "firstQuestions.h"

/* Calculate family details */
int members(int members_number, int paying_members) {
    printf("||| \tEnter the total number of family members: ");
    scanf("%d", &members_number);
    printf("||| \tEnter the number of family members that contribute financially: ");
    scanf("%d", &paying_members);

    if (members_number != paying_members) {
        printf("||| \tYour family has %d adults and %d children. What a beautiful family!\n", paying_members, (members_number - paying_members));
    } else {
        printf("||| \tYour family has %d adults and no children. Enjoy!\n", members_number);
    }
    return paying_members;
}

/* Convert salary before and after taxes */
int salary_converter(float salary_before_taxes, float salary_after_taxes) {
    printf("||| \tEnter the total salary before taxes: ");
    scanf("%f", &salary_before_taxes);
    printf("||| \tEnter the total salary after taxes: ");
    scanf("%f", &salary_after_taxes);

    printf("||| \tYour gross salary is %.2f, and your net salary is %.2f.\n", salary_before_taxes, salary_after_taxes);
    return salary_after_taxes;
}
