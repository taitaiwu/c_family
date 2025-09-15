#include <stdio.h>

int main (void)
{
    printf("BMI VALUES\n");

    double height,weight,BMI;
    printf("Please enter your height(m) & weight(kg):");
    scanf("%lf%lf",&height,&weight);

    BMI=(weight)/(height*height);

    if (BMI<18.5)
    {
        printf("Your BMI is %lf,you are underweight.\n",BMI);
    }

    else if (BMI >= 18.5 && BMI <= 24.9)
    {
        printf("Your BMI is %lf,you are normal.\n",BMI);
    }

    else if (BMI >= 25 && BMI <= 29.9)
    {
        printf("Your BMI is %lf,you are overweight.\n",BMI);
    }

    else
    {
        printf("Your BMI is %lf,you are obese\n.",BMI);
    }

    printf("\nUnderweight:less than 18.5.\n");
    printf("Normal     :between 18.5 and 24.9.\n");
    printf("Normal     :between 25.0 and 29.9.\n");
    printf("Normal     :30 or greater\n");
}

