#include <stdio.h>
#include <cs50.h>
#include <math.h>

int check(long num1)
{
    long temp = num1;
    int count = 0, sum1 = 0, sum2 = 0, num2,temp2;

    while (temp)
         {
             count += 1;
             if ( count % 2 == 0)
                {
                    num2 = temp % 10;
                    temp2 = (2 * num2);
                    
                    if (temp2 >= 10)
                    {
                        while(temp2)
                        {
                            sum1 += (temp2 % 10);
                            temp2 = temp2/10;
                        }
                     }
                     else
                     {
                         sum1 += temp2;
                     }   
                }
             temp = temp/10;
         }
     temp = num1;
     count = 0;

     while (temp)
        {
        count += 1;
            
            if ( count % 2 != 0)
            {
                num2 = temp % 10;
                sum2 += num2;
            }
            temp = temp /10;
        }
return (sum1 + sum2);      
}
int countDigit(long num)
{
    int count = 0;
    
    while (num)
    {
        count ++;
        num = num /10;
    }
    return count;    
}
int main()
{
    long num,power1,power2;
    int result, count, temp;

    num = get_long("Number: ");

     result = check (num);
     count = countDigit (num);
     temp = result % 10;
     power1 = pow(10,count-1);
     power2 = pow(10,count-2);   
    
     if (temp == 0 && ( count <= 16 && count >=13) )
     {   
            if ( (num / power1) == 4)
            {
                printf("VISA\n");
            }

            else if ( ((num / power2) == 34) || ((num / power2) == 37))
            {
               printf("AMEX\n"); 
            }

            else if ( ((num / power2) >= 51) && ((num / power2) <= 55))
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
