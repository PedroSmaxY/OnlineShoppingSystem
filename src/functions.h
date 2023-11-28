#include <stdio.h>

int calcularFrete(int regiao, float peso)
{
    float fretePadrao, fretePeso;
    switch (regiao)
    {
    case 1:
        fretePadrao = 35.00;
        fretePeso = 50.00;
        break;
    case 2:
        fretePadrao = 40.00;
        fretePeso = 60.00;
        break;
    case 3:
        fretePadrao = 30.00;
        fretePeso = 50.00;
        break;
    case 4:
        fretePadrao = 25.00;
        fretePeso = 45.00;
        break;
    default:
        printf("Região inválida\n");
        return -1;
        break;
    }

    if (peso > 2)
    {
        return fretePeso;
    }
    else
    {
        return fretePadrao;
    }
}


