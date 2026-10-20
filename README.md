🌐 **English** | [Português](README.pt-BR.md)

# 🌾 The Chessboard Legend and the Grains of Wheat

> **Group 6 · 8×8 Board in C**

According to the legend, the inventor of chess asked for **1 grain of wheat on the first square, 2 on the second, 4 on the third**, doubling on every square. It seemed like a simple request, but the 64 squares add up to **more than 18 quintillion grains**.

This project simulates the board in **C**, using an 8×8 matrix where each square is worth double the previous one.

## 📋 Problem Statement

Each square on the board receives double the grains of the previous square:

| | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|---|
| **0** | 1 | 2 | 4 | 8 | 16 | 32 | 64 | 128 |
| **1** | 256 | 512 | 1024 | 2048 | 4096 | 8192 | 16384 | 32768 |
| **...** | ... | ... | ... | ... | ... | ... | ... | ... |
| **7** | ... | ... | ... | ... | ... | ... | ... | 9223372036854775808 |

The program must:

1. Fill the board with the number of grains on each square (doubling on every square);
2. Ask the user for the **row** and **column** (from 0 to 7);
3. Show the number of grains on that square;
4. Show the **total number of grains** on the whole board.

## 🧩 Functions

| Function | Description |
|---|---|
| `preencher` | Fills the 8×8 matrix, doubling the value on each square |
| `somaLinha` | Returns the sum of the grains in a row |
| `totalGeral` | Returns the sum of all grains on the board |

## ⚠️ Mind the data type

Square 64 holds 2⁶³ grains and the board total is 2⁶⁴ − 1 = **18,446,744,073,709,551,615**. These values overflow `int` and `long`, so you need to use **`unsigned long long`** (and `%llu` in `printf`).

## ▶️ How to run

The code was developed and tested on the **[Programiz Online C Compiler](https://www.programiz.com/c-programming/online-compiler/)**, so there is nothing to install:

1. Go to the [Programiz Online C Compiler](https://www.programiz.com/c-programming/online-compiler/);
2. Paste the code from the `tabuleiro.c` file;
3. Click **Run** and enter the row and column when prompted.

To run locally with GCC:

```bash
gcc tabuleiro.c -o tabuleiro
./tabuleiro
```

## 💻 Usage example

```
Enter the row (0 to 7): 0
Enter the column (0 to 7): 7

Grains on square [0][7]: 128
Total grains on the board: 18446744073709551615
```

> The prompts above are translated for readability; your program may print them in Portuguese.

## 🛠️ Built with

- C language
- Programiz Online C Compiler

## 👥 Authors

**Group 6**

- Name 1
- Name 2
- Name 3
