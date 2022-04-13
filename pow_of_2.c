nclude <stdio.h>


int Powerof2(int number);
int main()
{
    int num;
    printf("Enter an integer number: ");
    scanf("%d",&num);

    if(Powerof2(num))
        printf("%d is the power of 2.",num);
    else
        printf("%d is not the power of 2.",num);

    return 0;
}

int Powerof2(int number)
{
    int i=0;
    while(number!=1)
    {
        if(number%2!=0)
            return 0;
        number=number/2;
        i++;

    }
    printf("the num pow is %d\n",i);
    return 1;
}

