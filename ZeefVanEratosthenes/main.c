/******************************************************
 main.c
 ZeefVanEratosthenes
 
 Created by Matthias Lemmens on 10/10/11.
 Thanks to Pieter Gunst
 
 Copyright (c) 2011 Lemmens inc. All rights reserved.
 ******************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void printZeef (int* p, int length)
{
    int getal;
    
    printf ("\n\n     ");
    
    for (getal=2; getal<=length; getal++)
    {
        if (p[getal]==0)
        {
            if (getal<10)
            {
                printf("|0%d| ", getal);
            } else {
                printf("|%d| ", getal);
            }
        } else {
            if (getal<10)
            {
                printf(" 0%d  ", getal);
            } else {
                printf(" %d  ", getal);
            }
        }
        
        if (getal%(int)(sqrt(length))==0)
        {
            printf("\n");
        }
    }
    
    printf("\n\n");
}

void zeef (int x)
{
    
    int length=x, getal, veelvoud;
    int* list =(int*) calloc(x, sizeof(int));
    
    for (getal=2; getal<=sqrt(length); getal++)
    {
        if (list[getal]==0)
        {
            for (veelvoud=(2*getal); veelvoud<=length; veelvoud+=getal)
            {
                list[veelvoud]=1;
            }
        }
    }
    
    printZeef(list, x);
}

int main (int argc, const char * argv[])
{
    int length;
    
    printf("Hello, Ladies! Give me a number and I'll show you Eratosthenes' sieve like no man has ever done before!\n");
    
    printf("Enter your number;  ");
    scanf("%d", &length);
    
    length=(int) length;
    zeef(length);
    
    return 0;
}

