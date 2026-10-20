🌐 [English](README.md) | **Português**

# 🌾 A lenda do xadrez e os grãos de trigo

> **Grupo 6 · Tabuleiro 8×8 em C**

Segundo a lenda, o inventor do xadrez pediu como recompensa **1 grão de trigo na primeira casa, 2 na segunda, 4 na terceira**, dobrando a cada casa. Parecia um pedido simples, mas as 64 casas somam **mais de 18 quintilhões de grãos**.

Este projeto simula o tabuleiro em linguagem **C**, usando uma matriz 8×8 em que cada casa vale o dobro da anterior.

## 📋 Enunciado

Cada casa do tabuleiro recebe o dobro de grãos da casa anterior:

| | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|---|
| **0** | 1 | 2 | 4 | 8 | 16 | 32 | 64 | 128 |
| **1** | 256 | 512 | 1024 | 2048 | 4096 | 8192 | 16384 | 32768 |
| **...** | ... | ... | ... | ... | ... | ... | ... | ... |
| **7** | ... | ... | ... | ... | ... | ... | ... | 9223372036854775808 |

O programa deve:

1. Preencher o tabuleiro com os grãos de cada casa (dobrando a cada casa);
2. Receber do usuário a **linha** e a **coluna** (de 0 a 7);
3. Mostrar a quantidade de grãos daquela casa;
4. Mostrar o **total de grãos** do tabuleiro inteiro.

## 🧩 Funções

| Função | Descrição |
|---|---|
| `preencher` | Preenche a matriz 8×8, dobrando o valor a cada casa |
| `somaLinha` | Retorna a soma dos grãos de uma linha |
| `totalGeral` | Retorna a soma de todos os grãos do tabuleiro |

## ⚠️ Atenção ao tipo de dado

A casa 64 tem 2⁶³ grãos e o total do tabuleiro é 2⁶⁴ − 1 = **18.446.744.073.709.551.615**. Esses valores estouram `int` e `long`, por isso é necessário usar **`unsigned long long`** (e `%llu` no `printf`).

## ▶️ Como executar

O código foi desenvolvido e testado no **[Programiz Online C Compiler](https://www.programiz.com/c-programming/online-compiler/)**, então não precisa instalar nada:

1. Acesse o [Programiz Online C Compiler](https://www.programiz.com/c-programming/online-compiler/);
2. Cole o código do arquivo `tabuleiro.c`;
3. Clique em **Run** e digite a linha e a coluna quando o programa pedir.

Para rodar localmente com o GCC:

```bash
gcc tabuleiro.c -o tabuleiro
./tabuleiro
```

## 💻 Exemplo de uso

```
Digite a linha (0 a 7): 0
Digite a coluna (0 a 7): 7

Grãos na casa [0][7]: 128
Total de grãos no tabuleiro: 18446744073709551615
```

## 🛠️ Tecnologias

- Linguagem C
- Programiz Online C Compiler

## 👥 Autores

**Grupo 6**

- Nome 1
- Nome 2
- Nome 3
