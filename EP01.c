#include <stdio.h>
#include <stdlib.h>

void insercao (int n, int v[]);
void selecao (int n, int v[]);
static void intercala1 (int p, int q, int r, int v[]);
void mergesort (int p, int r, int v[]);


void main()
{
// Esta função rearranja o vetor v[0..n-1]
// em ordem crescente.


}

void insercao (int n, int v[])
{
    int i, j, x;
    for (j = 1; j < n; ++j)
    {
        x = v[j];
        for (i = j-1; i >= 0 && v[i] > x; --i)
            v[i+1] = v[i];
        v[i+1] = x;
    }
}

// Esta função rearranja o vetor v[0..n-1]
// em ordem crescente.

void selecao (int n, int v[])
{
    int i, j, min, x;
    for (i = 0; i < n-1; ++i)
    {
        min = i;
        for (j = i+1; j < n; ++j)
            if (v[j] < v[min])  min = j;
        x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
}

// A função recebe vetores crescentes v[p..q-1]
// e v[q..r-1] e rearranja v[p..r-1] em ordem
// crescente.

static void intercala1 (int p, int q, int r, int v[])
{
    int i, j, k, *w;                        //  1
    w = mallocc ((r-p) * sizeof (int));     //  2
    i = p;
    j = q;                           //  3
    k = 0;                                  //  4

    while (i < q && j < r)                  //  5
    {
        if (v[i] <= v[j])  w[k++] = v[i++];  //  6
        else  w[k++] = v[j++];               //  7
    }                                       //  8
    while (i < q)  w[k++] = v[i++];         //  9
    while (j < r)  w[k++] = v[j++];         // 10
    for (i = p; i < r; ++i)  v[i] = w[i-p]; // 11
    free (w);                               // 12
}

// A função mergesort rearranja o vetor
// v[p..r-1] em ordem crescente.

void mergesort (int p, int r, int v[])
{
    if (p < r-1)                   // 1
    {
        int q = (p + r)/2;          // 2
        mergesort (p, q, v);        // 3
        mergesort (q, r, v);        // 4
        intercala (p, q, r, v);     // 5
    }
}
