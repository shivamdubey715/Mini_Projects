#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void HourMin(int arr[])
{
    time_t seconds;
    struct tm *timeStruct;

    seconds = time(NULL);

    timeStruct = localtime(&seconds);

    arr[0] = timeStruct->tm_hour;
    arr[1] = timeStruct->tm_min;
}

int sumofDigits(int i)
{
    int num = i, sum = 0, x;
    while (num != 0)
    {
        x = num % 10;
        sum = sum + x;
        num = num / 10;
    }
    return sum;
}

int isPrime(int n)
{
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int function2(int minute)
{
    int final_prime = 0, k =1;
    for (int i = 950000101; i >= 0; i -= 18)
    {
        if (k == minute)
        {
            break;
        }
        if (i % 10 != 5)
        {
            if (sumofDigits(i) == 16)
            {
                if (isPrime(i))
                {
                    final_prime = i;
                    k++;
                }
            }
        }
    }
    return final_prime;
}
int function1(int power)
{
    long long final_prime = 0;
    for (int i = 59; i <= 1000000000; i += 18)
    {
        if (i < power)
        {
            continue;
        }
        if (i % 10 != 5)
        {
            if (sumofDigits(i) == 14)
            {
                if (isPrime(i))
                {
                    final_prime = i;
                    break;
                }
            }
        }
    }
    
    return final_prime;
}

double myPow(double x, int n)
{
    double ans = 1.0;
    long long nn = n;
    if (nn < 0)
    {
        -1 * nn;
    }
    while (nn)
    {
        if (nn % 2)
        {
            ans = ans * x;
            nn = nn - 1;
        }
        else
        {
            x = x * x;
            nn = nn / 2;
        }
    }
    if (n < 0)
    {
        ans = (double)(1.0) / (double)(ans);
    }
    return ans;
}

int check(int hour, int minute, int day, int month, int year)
{
    int sum = hour + minute + day + month + year;
    int power = sum % 10;
    if (power == 0)
    {
        power = 5;
    }
    else if (power == 1)
    {
        power = 5;
    }
    else if (power == 2)
    {
        power = 6;
    }
    else if (power == 2)
    {
        power = 7;
    }
    else if (power == 2)
    {
        power = 8;
    }
    int limit = myPow(10, power);

    int temp1 = function1(limit) % 10000 + function1(limit) / 10000;

    int temp2 = function2(minute) % 10000 + function2(minute) / 10000;

    int ans = (temp1 + temp2 + year + minute + hour) % 10000;
    printf("%d\n", ans);
    return ans;
}
int main(void)
{
    int arr[2];
    HourMin(arr);
    int hour = arr[0];
    int minute = arr[1];
    SYSTEMTIME stime;
    GetSystemTime(&stime);

    int day = stime.wDay;
    int month = stime.wMonth;
    int year = stime.wYear;

    int password;
    printf("Enter the password\n");
    scanf("%d", &password);
    if (check(hour, minute, day, month, year) == password)
    {
        printf("Unlocked\n");
    }
    else
    {
        printf("Incorrect Password\n");
    }
    return 0;
}
