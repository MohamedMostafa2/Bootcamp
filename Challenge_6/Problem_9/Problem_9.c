/*********************************************************************************
 *
 *  problem_ten.h
 *  Author: Mohamed Mostafa Abdel Karim
 *  		Mohamed Hassan
 *
 ********************************************************************************/
/****************************[Problem Description]****************************************************
 *
 * Given a number "N" find four integer numbers a, b, c and d such that b, c and d are prime numbers,
 * and a & N are odd knowing that a^3 + b^3 + c^3 + d^3 = N and a <= b <= c <= d
 *
 * Sample Input: N = 161
 * Sample Output: Numbers are 1, 2, 3 and 5
 *
 * @return: Array containing a, b, c and d respectively that satisfy the equation
 *
 * Note: 1 <= N <= 10^18
 *
 *******************************************************************************************************/

#include <stdio.h>
#include "problem_nine.h"


static unsigned long prime_numbers[4]= {1,2,0,0};

int CheckPrimeNumber(unsigned long num) {
    unsigned long k=2;
    for(k = 2 ; k<=num-1; k++) {
        if(num%k == 0) {
            return 0;
        }
    }
    return 1;
}

int* findPrimeNumbers(int N) {
    unsigned long d=5;
    unsigned long c=3;
    unsigned long c_temp;
    unsigned short end_flag=0;
    N-=9;

    /* Guessing d number */
    while( (d*d*d) < N  ) {

        do {
            d+=2;
        } while( !(CheckPrimeNumber(d)) );

    }
    do {
        d-=2;
    } while( !(CheckPrimeNumber(d)) );

    /* Guessing c number */
    while(  (c*c*c) <= (N - (d*d*d))  ) {

        do {
            c+=2;
        } while( !(CheckPrimeNumber(c)) );

    }
    do {
        c-=2;
    } while( !(CheckPrimeNumber(c)) );

    /* Get the true c and d numbers */
    if(!(((c * c * c) + (d*d*d) ) == N) ) {
        while(d>3) {
            c_temp=c;
            do {
                d-=2;
            } while( !(CheckPrimeNumber(d)) );

            while ( c_temp <= d ) {
                if( ( (c_temp * c_temp * c_temp) + (d*d*d) ) == N) {
                    prime_numbers[2]=c_temp;
                    prime_numbers[3]=d;
                    end_flag=1;
                    break;
                }
                else {
                    do {
                        c_temp+=2;
                    } while( !(CheckPrimeNumber(c)) );
                }
            }
            if(end_flag == 1) {
                break;
            }
        }
    }
    else{
        prime_numbers[2]=c;
        prime_numbers[3]=d;
        end_flag=1;
    }
    if(end_flag==0) {
        printf("N is Wrong Number\n");
    }

    return &prime_numbers;
}


int main(void) {
    int* ptrToPrimes = findPrimeNumbers(924849);
    printf("The numbers are: %d, %d, %d and %d\n",ptrToPrimes[0],ptrToPrimes[1],ptrToPrimes[2],ptrToPrimes[3]);

    return 0;
}
