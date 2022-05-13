/* @Parameters
 * minLength = 5
 * maxLength = 1000
 * seed = 50 for the function srand(seed)
 * maxInstance = 50 number of instance for each attempt 
 * STEP = 10 incrementing value for each experiment
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Merge Algorithm */
void Merge(int *A, int p, int q, int r)
{
    int n1, n2, i, j, k;
    n1 = q - p + 1;
    n2 = r - q;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = A[p + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = A[q + j + 1];
    }
    i = 0;
    j = 0;
    for (k = p; k < r + 1; k++)
    {
        if (i < n1)
        {
            if (j < n2)
            {
                if (L[i] <= R[j])
                {
                    A[k] = L[i];
                    i++;
                }
                else
                {
                    A[k] = R[j];
                    j++;
                }
            }
            else
            {
                A[k] = L[i];
                i++;
            }
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

/* MergeSort Algorithm */
void MergeSort(int *A, int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

/* Single Expertiment */
float singoloEsperimento(int len, int maxInstance)
{
    float timeTot = 0;
    float timeStart, timeEnd, timeElapsed;
    int A[len];

    for (int i = 0; i < maxInstance; i++)
    {

        for (int j = 0; j < len; j++)    // Generator Array of casual numbers:
        {                                // through rand()%N, it generates a number between 0 e N-1
            A[j] = 1 + rand() % 1000000; // and i put this number into the array
        }

        timeStart = clock();
        MergeSort(A, 0, len - 1);
        timeEnd = clock();

        timeElapsed = timeEnd - timeStart;
        timeTot = timeTot + timeElapsed;
    }
    return timeTot / maxInstance;
}

/* ESPERIMENTO MERGE SORT */
void esperimento(int minLen, int maxLen)
{
    int maxInstances = 50; // number of instance for each attempt
    int STEP = 10;         // increments elements of array one-by-one
                           // es: step = 3, 1° trial = 1 elemento nell'array, 2° trial = 4 elementi nell'array
                           // e mi da 4 tentativi perche step = 3 per arrivare a maxIstanza = 12 è 3*4salti = 12
    float time;
    for (int i = minLen; i < maxLen; i = i + STEP)
    {
        time = singoloEsperimento(i, maxInstances);
        //printf("Tempo per %d elementi per array: %.3f\n", i, time);
        printf("%.2f \n", time);
    }
}

/* Funzione Main */
int main()
{
    srand(50);
    int minLength = 5;
    int maxLength = 1000;
    esperimento(minLength, maxLength);

    return 0;
}
