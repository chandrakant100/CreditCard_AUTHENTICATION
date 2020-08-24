#include <stdio.h>
#include <cs50.h>
#include <math.h>

int check(long num1)
{
    long temp = num1;
    int count = 0, sum1 = 0, sum2 = 0, num2, temp2;

    while (temp) //addition of each number  multiplied by 2 at even position from right to left
    {
        count += 1;
        if (count % 2 == 0)
        {
            num2 = temp % 10;
            temp2 = (2 * num2);
                    
            if (temp2 >= 10)
            {
                while (temp2) //splits number if the number extracted multiplied by 2 >= 10
                {
                    sum1 += (temp2 % 10);
                    temp2 = temp2 / 10;
                }
            }
            else
            {
                sum1 += temp2;
            }   
        }
        temp = temp / 10;
    }
    temp = num1;
    count = 0;

    while (temp) //addition of each number at odd position from right to left 
    {
        count += 1;
            
        if (count % 2 != 0)
        {
            num2 = temp % 10;
            sum2 += num2;
        }

        temp = temp / 10;
    }
    return (sum1 + sum2); //sum1 and sum2 are the sum of even and odd positions respectively.  
}
int countDigit(long num) //counting the total number of digits
{
    int count = 0;
    
    while (num)
    {
        count ++;
        num = num / 10;
    }
    return count;    
}
int main()
{
    long num, power1, power2;
    int result, count, temp;

    num = get_long("Number: ");

    result = check(num); //stores the final sum
    count = countDigit(num); //stores the total number of digits
    temp = result % 10;
    power1 = pow(10, count - 1);

    power2 = pow(10, count - 2);


    if (temp == 0 && (count <= 16 && count >= 13)) //To check the conditions for required output
    {   
        if ((num / power1) == 4)
        {
            printf("VISA\n");
        }

        else if (((num / power2) == 34) || ((num / power2) == 37))
        {
            printf("AMEX\n"); 
        }

        else if (((num / power2) >= 51) && ((num / power2) <= 55))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }        
    }

    else        
    {
        printf("INVALID\n");
    }  
    return 0;
}
