#include <stdio.h>
#define N 8

// I use unsigned long long because an int holds at most ~4 billion, and the last square
// has 2^63 grains and the board total reaches 2^64 - 1, which is the limit of this type.
unsigned long long graos[N][N];

// PREENCHER FUNCTION: fills the 64 squares of the matrix. The first square has 1 grain
// and each following square has double the previous one.
void preencher() {
    graos[0][0] = 1;
    unsigned long long resultado = 0;

    // The two for loops go through all rows (i) and columns (j).
    // Since the global matrix starts zeroed, "resultado += graos[i][j]" adds 0 in almost
    // every square (only [0][0] is worth 1). Then the result is stored in the current
    // square and multiplied by 2 to be used as the value of the next square.
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            resultado += graos[i][j];
            graos[i][j] = resultado;
            resultado *= 2;
        }
    }
}

// SOMALINHA FUNCTION: adds up the grains of a single row (row i) of the matrix
// and returns the result.
unsigned long long somaLinha(int i)
{
    unsigned long long soma = 0;
    int j;

    // The for loop goes through the columns (j) of row i, adding up each square.
    for(j = 0; j < N; j++)
    {
        soma += graos[i][j];
    }
    return soma;
}

// TOTALGERAL FUNCTION: adds up the grains of the entire board, calling somaLinha
// for each of the 8 rows.
unsigned long long totalGeral()
{
    unsigned long long resultado = 0;
    int n;

    // The for loop goes through all rows (from 0 to 7) and sends each one to somaLinha.
    // The total of each row is accumulated in resultado.
    for(n = 0; n < N; n++)
    {
        resultado += somaLinha(n);
    }
    return resultado;
}

// MAIN: fills the board, asks the user for the row and column of the square they
// want to look up, shows the square number and the amount of grains on it, and also
// shows the total number of grains on the entire board.
int main()
{
    int l,c;
    preencher();
    printf("|=======================================|\n");
    printf("| informe a linha e coluna (de 0 a 7):  |\n");
    printf("|=======================================|\n\n");
    scanf("%d %d", &l, &c);

    // The if checks whether the row and column entered are between 0 and 7.
    // If they are not, the else displays "Posição invalida!".
    if(l >= 0 && l < N && c >= 0 && c < N)
    {
        printf("|=======================================================|\n");
        printf("| casa %d tem %llu graos\n", l * N + c + 1, graos[l][c], "\n");
        printf("|=======================================================|\n");
        printf("|==================================================================|\n");
        printf("|Total das linhas somadas do tabuleiro: %llu graos |\n", totalGeral(), "\n");
        printf("|==================================================================|\n");
    }
    else
    {
        printf("Posição invalida!");
    }
    return 0;
}
