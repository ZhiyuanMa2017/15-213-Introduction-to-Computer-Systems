/*
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/*
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded.
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    int a1, a2, a3, a4, a5, a6, a7, a8;
    int i, j, x, y;
    if (M == 32 && N == 32)
    {
        for (i = 0; i < 32; i += 8)
        {
            for (j = 0; j < 32; j += 8)
            {
                for (x = i; x < i + 8; x++)
                {
                    a1 = A[x][j];
                    a2 = A[x][j + 1];
                    a3 = A[x][j + 2];
                    a4 = A[x][j + 3];
                    a5 = A[x][j + 4];
                    a6 = A[x][j + 5];
                    a7 = A[x][j + 6];
                    a8 = A[x][j + 7];
                    B[j][x] = a1;
                    B[j + 1][x] = a2;
                    B[j + 2][x] = a3;
                    B[j + 3][x] = a4;
                    B[j + 4][x] = a5;
                    B[j + 5][x] = a6;
                    B[j + 6][x] = a7;
                    B[j + 7][x] = a8;
                }
            }
        }
    }
    else if (M == 64 && N == 64)
    {
        for (i = 0; i < 64; i += 8)
        {
            for (j = 0; j < 64; j += 8)
            {
                // A: top left & top right
                for (x = i; x < i + 4; x++)
                {
                    a1 = A[x][j];a2 = A[x][j + 1];a3 = A[x][j + 2];a4 = A[x][j + 3];a5 = A[x][j + 4];a6 = A[x][j + 5];a7 = A[x][j + 6];a8 = A[x][j + 7];

                    B[j][x] = a1;       B[j][x + 4] = a5;
                    B[j + 1][x] = a2;   B[j + 1][x + 4] = a6;
                    B[j + 2][x] = a3;   B[j + 2][x + 4] = a7;
                    B[j + 3][x] = a4;   B[j + 3][x + 4] = a8;

                }
                // A: bottom left
                for (y = j; y < j + 4; y++)
                {
                    a1 = A[i + 4][y];
                    a2 = A[i + 5][y];
                    a3 = A[i + 6][y];
                    a4 = A[i + 7][y];

                    a5 = B[y][i + 4];a6 = B[y][i + 5];a7 = B[y][i + 6];a8 = B[y][i + 7];

                    B[y][i + 4] = a1;B[y][i + 5] = a2;B[y][i + 6] = a3;B[y][i + 7] = a4;

                    B[y + 4][i] = a5;B[y + 4][i + 1] = a6;B[y + 4][i + 2] = a7;B[y + 4][i + 3] = a8;
                }
                // A: bottom right
                for (x = i + 4; x < i + 8; x++)
                {
                    a1 = A[x][j + 4];a2 = A[x][j + 5];a3 = A[x][j + 6];a4 = A[x][j + 7];

                    B[j + 4][x] = a1;
                    B[j + 5][x] = a2;
                    B[j + 6][x] = a3;
                    B[j + 7][x] = a4;
                }
            }
        }
    }
    else if (M == 61 && N == 67)
    {
        for (i = 0; i < 67; i += 16)
        {
            for (j = 0; j < 61; j += 16)
            {
                for (x = i; x < i + 16 && x < 67; x++)
                {
                    for (y = j; y < j + 16 && y < 61; y++)
                    {
                        B[y][x] = A[x][y];
                    }
                }
            }
        }
    }
}
/*
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started.
 */

/*
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }
}

char transpose_M4N4_desc[] = "M4 N4 transpose";
void transpose_M4N4(int M, int N, int A[N][M], int B[M][N])
{
    int a1, a2, a3, a4, a5, a6, a7, a8;
    if (M == 4 && N == 4)
    {
        a1 = A[0][0];
        a2 = A[0][1];
        a3 = A[0][2];
        a4 = A[0][3];
        a5 = A[1][0];
        a6 = A[1][1];
        a7 = A[1][2];
        a8 = A[1][3];
        B[0][0] = a1;
        B[1][0] = a2;
        B[2][0] = a3;
        B[3][0] = a4;
        B[0][1] = a5;
        B[1][1] = a6;
        B[2][1] = a7;
        B[3][1] = a8;

        a1 = A[2][0];
        a2 = A[2][1];
        a3 = A[2][2];
        a4 = A[2][3];
        a5 = A[3][0];
        a6 = A[3][1];
        a7 = A[3][2];
        a8 = A[3][3];
        B[0][2] = a1;
        B[1][2] = a2;
        B[2][2] = a3;
        B[3][2] = a4;
        B[0][3] = a5;
        B[1][3] = a6;
        B[2][3] = a7;
        B[3][3] = a8;
    }
}

char transpose_M32N32_desc[] = "M32 N32 transpose";
void transpose_M32N32(int M, int N, int A[N][M], int B[M][N])
{
    int a1, a2, a3, a4, a5, a6, a7, a8;
    int i, j, k;
    if (M == 32 && N == 32)
    {
        for (i = 0; i < 32; i += 8)
        {
            for (j = 0; j < 32; j += 8)
            {
                for (k = i; k < i + 8; k++)
                {
                    a1 = A[k][j];
                    a2 = A[k][j + 1];
                    a3 = A[k][j + 2];
                    a4 = A[k][j + 3];
                    a5 = A[k][j + 4];
                    a6 = A[k][j + 5];
                    a7 = A[k][j + 6];
                    a8 = A[k][j + 7];
                    B[j][k] = a1;
                    B[j + 1][k] = a2;
                    B[j + 2][k] = a3;
                    B[j + 3][k] = a4;
                    B[j + 4][k] = a5;
                    B[j + 5][k] = a6;
                    B[j + 6][k] = a7;
                    B[j + 7][k] = a8;
                }
            }
        }
    }
}

char transpose_M64N64_desc[] = "M64 N64 transpose";
void transpose_M64N64(int M, int N, int A[N][M], int B[M][N])
{
    int a1, a2, a3, a4, a5, a6, a7, a8;
    int i, j, x, y;
    if (M == 64 && N == 64)
    {
        for (i = 0; i < 64; i += 8)
        {
            for (j = 0; j < 64; j += 8)
            {
                // A: top left & top right
                for (x = i; x < i + 4; x++)
                {
                    a1 = A[x][j];a2 = A[x][j + 1];a3 = A[x][j + 2];a4 = A[x][j + 3];a5 = A[x][j + 4];a6 = A[x][j + 5];a7 = A[x][j + 6];a8 = A[x][j + 7];

                    B[j][x] = a1;       B[j][x + 4] = a5;
                    B[j + 1][x] = a2;   B[j + 1][x + 4] = a6;
                    B[j + 2][x] = a3;   B[j + 2][x + 4] = a7;
                    B[j + 3][x] = a4;   B[j + 3][x + 4] = a8;

                }
                // A: bottom left
                for (y = j; y < j + 4; y++)
                {
                    a1 = A[i + 4][y];
                    a2 = A[i + 5][y];
                    a3 = A[i + 6][y];
                    a4 = A[i + 7][y];

                    a5 = B[y][i + 4];a6 = B[y][i + 5];a7 = B[y][i + 6];a8 = B[y][i + 7];

                    B[y][i + 4] = a1;B[y][i + 5] = a2;B[y][i + 6] = a3;B[y][i + 7] = a4;

                    B[y + 4][i] = a5;B[y + 4][i + 1] = a6;B[y + 4][i + 2] = a7;B[y + 4][i + 3] = a8;
                }
                // A: bottom right
                for (x = i + 4; x < i + 8; x++)
                {
                    a1 = A[x][j + 4];a2 = A[x][j + 5];a3 = A[x][j + 6];a4 = A[x][j + 7];

                    B[j + 4][x] = a1;
                    B[j + 5][x] = a2;
                    B[j + 6][x] = a3;
                    B[j + 7][x] = a4;
                }
            }
        }
    }
}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc);

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc);

    registerTransFunction(transpose_M4N4, transpose_M4N4_desc);

    registerTransFunction(transpose_M32N32, transpose_M32N32_desc);

    registerTransFunction(transpose_M64N64, transpose_M64N64_desc);
}

/*
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; ++j)
        {
            if (A[i][j] != B[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}
