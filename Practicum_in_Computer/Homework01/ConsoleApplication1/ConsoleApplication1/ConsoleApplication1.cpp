#include <stdio.h>

int main(void)
{
    char name[10];
    char department;
    int score1, score2;
    float avg;

    printf("Please input your name: ");
    scanf("%s", name);

    printf("Please select your department (a:資工 b:電機 c:電子): ");
    scanf(" %c", &department);

    printf("Please input your score on test 1: ");
    scanf("%d", &score1);

    printf("Please input your score on test 2: ");
    scanf("%d", &score2);

    avg = ((float)score1 + (float)score2) / 2;

    printf("|-----------------------------------------------------|\n");
    printf("|    Name    | Department | Test 1 | Test 2 | Average |\n");
    printf("|------------+------------+--------+--------+---------|\n");
    printf("|%-10s  |%-10c  | %6d | %6d |%8.2f |\n", name, department, score1, score2, avg);
    printf("|-----------------------------------------------------|\n");

}
