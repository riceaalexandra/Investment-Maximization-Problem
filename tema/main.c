#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

int main()
{
    int actiuni[10000],profit[10000],capital,nr_oferte;
    printf("Introduceti numarul de oferte: ");
    scanf("%d",&nr_oferte);
    printf("Introduceti valoarea capitalului: ");
    scanf("%d",&capital);
    generare(capital,nr_oferte,actiuni,profit); // Prin generare asociem valori random pentru toate ofertele
    display(capital,nr_oferte,actiuni,profit);

        printf("Recursiv: %d \n", Recursion_Solution(capital,actiuni,profit,nr_oferte));
        printf("Dinamic:  %d \n", Dynamic_Solution(capital,actiuni,profit,nr_oferte));

    return 0;
}

