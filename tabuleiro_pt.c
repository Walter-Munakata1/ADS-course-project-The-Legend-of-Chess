#include <stdio.h>
#define N 8

// Uso unsigned long long porque o int guarda no máximo ~4 bilhões, e a última casa
// tem 2^63 grãos e o total do tabuleiro chega a 2^64 - 1, que é o limite desse tipo.
unsigned long long graos[N][N];

// FUNÇÃO PREENCHER: preenche as 64 casas da matriz. A primeira casa tem 1 grão
// e cada casa seguinte tem o dobro da anterior.
void preencher() {
    graos[0][0] = 1;
    unsigned long long resultado = 0;

    // Os dois for percorrem todas as linhas (i) e colunas (j).
    // Como a matriz global começa zerada, "resultado += graos[i][j]" soma 0 em quase
    // todas as casas (só a [0][0] vale 1). Depois o resultado é guardado na casa
    // atual e multiplicado por 2 para servir de valor da próxima casa.
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

// FUNÇÃO SOMALINHA: soma os grãos de uma única linha (a linha i) da matriz
// e devolve o resultado.
unsigned long long somaLinha(int i)
{
    unsigned long long soma = 0;
    int j;

    // O for percorre as colunas (j) da linha i, somando cada casa.
    for(j = 0; j < N; j++)
    {
        soma += graos[i][j];
    }
    return soma;
}

// FUNÇÃO TOTALGERAL: soma os grãos do tabuleiro inteiro, chamando a somaLinha
// para cada uma das 8 linhas.
unsigned long long totalGeral()
{
    unsigned long long resultado = 0;
    int n;

    // O for passa por todas as linhas (de 0 a 7) e envia cada uma para a somaLinha.
    // O total de cada linha é acumulado em resultado.
    for(n = 0; n < N; n++)
    {
        resultado += somaLinha(n);
    }
    return resultado;
}

// MAIN: preenche o tabuleiro, pede ao usuário a linha e a coluna da casa que ele
// quer consultar, mostra o número da casa e a quantidade de grãos nela, e também
// mostra o total de grãos do tabuleiro inteiro.
int main()
{
    int l,c;
    preencher();
    printf("|=======================================|\n");
    printf("| informe a linha e coluna (de 0 a 7):  |\n");
    printf("|=======================================|\n\n");
    scanf("%d %d", &l, &c);

    // O if verifica se a linha e a coluna digitadas estão entre 0 e 7.
    // Se não estiverem, o else exibe "Posição invalida!".
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
