#include <stdio.h>
#include <stdlib.h>

void insercao (int n, int v[]);
void selecao (int n, int v[]);
static void intercala (int p, int q, int r, int v[]);
void mergesort (int p, int r, int v[]);
int separa (int v[], int p, int r);
void quicksort (int v[], int p, int r);
static void constroiHeap (int m, int v[]);
static void peneira (int m, int v[]);

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

static void intercala (int p, int q, int r, int v[])
{
    int i, j, k, *w;                        //  1
    w = malloc ((r-p) * sizeof (int));     //  2
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


int separa (int v[], int p, int r)
{
    int c = v[p], i = p+1, j = r, t;         // 1
    while (1)                                // 2
    {
        while (i <= r && v[i] <= c) ++i;      // 3
        while (c < v[j]) --j;                 // 4
        if (i >= j) break;                    // 5
        t = v[i], v[i] = v[j], v[j] = t;      // 6
        ++i;
        --j;                             // 7
    }                                        // 8
    v[p] = v[j], v[j] = c;                   // 9
    return j;                                // 10
}


// Esta função rearranja qualquer vetor
// v[p..r] em ordem crescente.

void quicksort (int v[], int p, int r)
{
    int j;                         // 1
    if (p < r)                     // 2
    {
        j = separa (v, p, r);       // 3
        quicksort (v, p, j-1);      // 4
        quicksort (v, j+1, r);      // 5
    }
}




// Rearranja um vetor v[1..m] de modo a
// transformá-lo em heap.

static void constroiHeap (int m, int v[])
{
    int k;
    for (k = 1; k < m; ++k)
    {
        // v[1..k] é um heap
        int f = k+1;
        while (f > 1 && v[f/2] < v[f])    // 5
        {
            troca (v[f/2], v[f]);          // 6
            f /= 2;                        // 7
        }
    }
}


// Recebe um vetor v[1..m] que é um heap
// exceto talvez pelos índices 2 e 3 e
// rearranja o vetor de modo a
// transformá-lo em heap.

static void peneira (int m, int v[])
{
    int p = 1, f = 2, t = v[1];
    while (f <= m)
    {
        if (f < m && v[f] < v[f+1])  ++f;
        if (t >= v[f]) break;
        v[p] = v[f];
        p = f, f = 2*p;
    }
    v[p] = t;
}
