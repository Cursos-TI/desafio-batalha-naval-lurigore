#include <stdio.h>

int main() {
    int tabuleiro[10][10];

    const int tamanhoNavio = 3;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }
    
    for(int i = 0; i < tamanhoNavio; i++)
    {
        tabuleiro[2][i] = 3;
    }

    for(int i = 5; i < tamanhoNavio + 5; i++)
    {
        tabuleiro[i][7] = 3;
    }

    for(int i = 0; i < tamanhoNavio; i++)
    {
        tabuleiro[i+5][i+2] = 3;
    }
    for(int i = 0; i < tamanhoNavio; i++)
    {
        tabuleiro[i+1][i+6] = 3;
    }for(int i = tamanhoNavio; i < tamanhoNavio; i--)
    {
        tabuleiro[i][i] = 3;
    }
    
    //cruz
    for(int i = 0; i < 3; i++)
    {
        int yOfset = 4;
        int xOfset = 5;
        for(int j = 0; j < 5; j++)
        {
            if(j == 2)
            tabuleiro[i + yOfset][j + xOfset] = 5;
            if(i == 1)
            tabuleiro[i + yOfset][j + xOfset] = 5;
        }
    }

    /*
    00500
    05550
    55555

    tab[0][2]
    tab[1][1,2,3]
    tab[2][0,1,2,3,4]
    */
    int tamanho = 5;
    for(int i = 0; i < 3; i++)
    {
        int yOfset = 0;
        int xOfset = 1;
        int final = 3 + i;
        int inicio = 2 - i;
        for(int j = inicio; j < tamanho; j++)
        {
            tabuleiro[i + yOfset][j + xOfset] = 5;
        }
        for(int j = final; j < tamanho; j++)
        {
            tabuleiro[i + yOfset][j + xOfset] = 0;
        }
    }
    
    /*
    00500
    05550
    00500
    */
    int inicio = 2;
    int final = 3;
    for(int i = 0; i < 3; i++)
    {
        int xOfset = 0;
        int yOfset = 7;
        int tamanho = 5;
        if(inicio > 1)
        {
            inicio = inicio - i;
        }else{
            inicio = inicio + 1;
        }
        for(int j = inicio; j < tamanho; j++)
        {
            tabuleiro[i + yOfset][j + xOfset] = 5;
        }
        printf("%d", final);
        for(int j = final; j < tamanho; j++)
        {
            tabuleiro[i + yOfset][j + xOfset] = 0;
        }   
        if(final == 4)
        {
            final = final - i;
        }else{
            final = final + 1;
        }
    }

    printf("--- Tabuleiro Batalha Naval ---\n");
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
