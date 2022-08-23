#include <stdio.h>
int gcd(int a, int b)
{
    return (b) != 0 ? gcd(b, (a % b)) : a;
}
int factorial(int f)
{
    return f <= 1 ? 1 : f * factorial(f - 1);
}
int fibonacci(int i)
{
    return i == 0 ? 1 : i == 1 ? 1
                               : (fibonacci(i - 1) + fibonacci(i - 2));
}
void tower_of_hanoi(int num, char frompeg, char topeg, char auxpeg)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from from peg %c to peg %c", frompeg, topeg);
        return;
    }
    tower_of_hanoi(num - 1, frompeg, auxpeg, topeg);
    printf("\n Move disk %d from from peg %c to peg %c", num, frompeg, topeg);
    tower_of_hanoi(num - 1, auxpeg, topeg, frompeg);
}

int main()
{
    int select;
    int gNum1, gNum2; // this is the variable used in calculating gcd,
    int fNum;         // this is use to find factorail.
    int i, fabN;      // these are used for fibonacci series.
    // variable for tower of hanoi
    int nDisk;
    do
    {
    menu:
        printf("\nSelect any option you want to perform\n");
        printf("*******************\n1. Greatest common Divisor\t 2. Factorial\n3. Fibonacci series\t\t 4. Tower of hanoi\n5.Exit\n*******************\n");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            printf("*Find GCD*\n");
            printf("Enter first and second number\n");
            scanf("%d%d", &gNum1, &gNum2);
            printf("GCD is : %d\n", gcd(gNum1, gNum2));
            printf("****\n");
            break;
        case 2:
            printf("*Find Factorial*\n");
            printf("Enter number to find factorial\n");
            scanf("%d", &fNum);
            printf("Factorial is : %d\n", factorial(fNum));
            printf("****\n");
            break;
        case 3:
            printf("*Fibonacci Series*\n");
            printf("Enter the number of element in series\n");
            scanf("%d", &fabN);
            printf("The fabonacci series is:\n");
            for (i = 0; i < fabN; i++)
            {
                printf("%d", fibonacci(i));
            }
            break;
        case 4:
            printf("** Tower Of Hanoi **\n");
            printf("Enter the number of disk\n");
            scanf("%d", &nDisk);
            printf("The sequences of moves are :\n");
            tower_of_hanoi(nDisk, 'A', 'C', 'B');
            break;
        case 5:
            printf("Operation succesfull!!!");
            select = 5;
            break;
        default:
            printf("\nInvalid option selected");
            goto menu;
            break;
        }
    } while (select != 5);
    return 0;
}