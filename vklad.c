#include<stdio.h>


float getPercentOfInc(int days, float deposit)
{
    float percent = 1;
    if(days <= 30) {
	percent -= 0.1;
    } else if(days <= 120) {
        if (deposit <= depDelim) { 
            percent += 0.02; 
        } else { 
            percent += 0.03; 
        };
    } else if(days <= 240) {
        if (deposit <= depDelim) {
           percent += 0.06;
        } else {
           percent += 0.08;
        }
    } else if(days <= 365) {
        if (deposit <= depDelim) {
           percent += 0.12;
        } else{
           percent += 0.15;}
    }
    return percent;
}

int correctData(int *days, int *deposit)
{
    printf("Input days: ");
    if (!scanf("%d", days)) {
        printf("Days is incorrect\n");
        return 0;
    } else if (*days < 0 || *days > 365) {
        printf("Out of range days\n");
        return 0;
    }

    printf("Please input deposit: ");
    if (!scanf("%d", deposit)) {
        printf("Deposit is incorrect\n");
        return 0;
    } else if (*deposit < 10000) {
        printf("Deposit is too small\n");
        return 0;
    }
    return 1;
}

int main()
{
    int days, deposit;
    if (inputData(&days, &deposit)) {
        float income = deposit * getPercentOfInc(days, deposit);
        printf("Income: %.2f\n", income);  
    }
    return 0;
}
