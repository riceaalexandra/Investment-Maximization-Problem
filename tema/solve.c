#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include "solve.h"

void generare(int *capital,int *numar_oferte,int actiuni[],int profit[])
{
    srand(0);

    for(int it=0; it<numar_oferte; it++)
    {
        //Pentru fiecare oferta asociem valoarea totala a actiunilor si profitul generat
        int numar_actiuni,valoare_actiune;
        int nr=rand()%10+1;
        for(int i=0; i<nr; i++)
        {
            numar_actiuni=rand()%10+1;
            valoare_actiune=rand()%10+1;
            profit[it]=rand()%10+1;
        }
        actiuni[it]=numar_actiuni*valoare_actiune; //valoarea totala a actiunilor

    }
}

// Afiseaza proprietatile fiecarei oferte
void display(int capitall,int numar_ofertee,int actiunii[],int profitt[])
{

    printf("capital=%d \n",capitall);
    printf("Numar oferte=%d \n",numar_ofertee);
    for(int i=0; i<numar_ofertee; i++)
    {
        printf("Valoare actiuni pentru oferta %d = %d \n",i+1,actiunii[i]);
        printf("Valoare profit pentru oferta %d = %d \n",i+1,profitt[i]);
    }

}
//Determina maximul dintre doua numere
int maxx(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

int Dynamic_Solution(int C, int actiuni_val[], int profit[], int n)
{
    int i,c;
    int K[n+1][C+1];

    // Construim tabelul K de jos in sus
    for (i = 0; i <= n; i++)
    {
        for (c = 0; c <= C; c++)
        {
            if (i == 0 || c == 0)
                K[i][c] = 0;
            else if (actiuni_val[i - 1] <= c)
                K[i][c] = maxx(profit[i - 1]+ K[i - 1][c - actiuni_val[i - 1]],K[i - 1][c]);
            else
                K[i][c] = K[i - 1][c];
        }
    }

    return K[n][C];
}

int Recursion_Solution(int C, int actiuni_val[], int profit[], int n)
{

    if (n == 0 || C == 0)
        return 0;

     //Daca valoarea actiunilor este mai mare decat capitalul atunci nu o includem in solutie
    if (actiuni_val[n - 1] > C)
        return Recursion_Solution(C,actiuni_val,profit, n - 1);


    else
        return maxx(profit[n - 1]+Recursion_Solution(C - actiuni_val[n - 1],actiuni_val,profit, n - 1),Recursion_Solution(C,actiuni_val, profit, n - 1));
}


