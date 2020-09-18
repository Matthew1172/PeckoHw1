#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* mergesort: sort integer array a[length] ; standard mergesort */
/* sorts in increasing order, requires auxiliary array */
void mergesort(int* a, int* aux, int length)
{
    int i;
    int j1;
    int j2;
    if (length > 1)
    {
        mergesort(a, aux, (length / 2)); /* recursive calls */
        mergesort(a + (length / 2), aux, (length - (length / 2)));
        for (i = 0, j1 = 0, j2 = (length / 2); i < length; ) /* merging */
        {
            if ((j1 < (length / 2) && a[j1] < a[j2]) || j2 == length)
                aux[i++] = a[j1++];
            else
                aux[i++] = a[j2++];

        }
        for (i = 0; i < length; i++) /* copying back */
            a[i] = aux[i];
    }
}

void sArray(int* a, const int size) {
    int i;
    srand((unsigned int)time((time_t)0));
    for (i = 0; i < size; i++) a[i] = rand();
}

void pArray(int* a, const int size) {
    int i;
    for (i = 0; i < size; i++) printf("%d \n", a[i]);
}

/*
int common(int* a, int* b, const int as, const int bs) {
    int c = 0;
    int i = 0;
    int j = 0;
    int z = 0; 
    int flag = 0;
    int* bf = (int*)malloc(as * sizeof(int));

    while (i < as) {
        while (j < bs) {
            if (a[i] == b[j]) {
                flag = 0;
                for (z = 0; z < as; ++z) {
                    if (bf[z] == a[i]) flag = 1;
                }
                if (flag == 0) {
                    c++;
                    *(bf + c) = a[i];
                }
                i++;
                j++;
            }
            else {
                if (a[i] < b[j]) i++;
                else j++;
            }
        }
        break;
    }
    return c;
}
*/


int common(int* a, int* b, const int as, const int bs) {
    int c = 0;
    int i = 0;
    int j = 0;
    int m = 0;

        while (j < bs || i < as) {
            if (a[i] != m && a[i] == b[j]) {
                m = a[i];
                c++;
                i++;
                j++;
            }
            else {
                if (a[i] < b[j]) i++;
                else j++;
            }
        }
    return c;
}


/*
int common(int* a, int* b, const int as, const int bs) {
    int c = 0;
    int i = 0;
    int j = 0;
    int z = 0;
    int flag = 0;
    int* bf = (int*)malloc(as * sizeof(int));

    while (i < as || j < bs) {
            if (a[i] == b[j]) {
                flag = 0;
                for (z = 0; z < as; ++z) {
                    if (bf[z] == a[i]) flag = 1;
                }
                if (flag == 0) {
                    c++;
                    *(bf + c) = a[i];
                }
                i++;
                j++;
            }
            else {
                if (a[i] < b[j]) i++;
                else j++;
            }
        }
    pArray(bf, c);
    return c;
}
*/

main()
{
    int P[500000];
    int Q[200000];
    int i, t1, t2, result;
    time_t t;
    srand((unsigned)time(&t)); /*initialize random numbers */
    for (i = 0; i < 500000; i++) /* fill P with even numbers */
        P[i] = 2 * ((579 * i + 234987) % 500000);
    for (i = 0; i < 200000; i++)/* fill Q with odd numbers */
        Q[i] = 2 * ((997 * i + 98771) % 200000) + 1;
    t1 = (rand() % 10) + 1;
    t2 = (rand() % 10) + 1;
    for (i = 0; i < t1; i++) /* put some odd numbers in P */
    {
        P[rand() % 500000] = 2 * (51 * i + 237) + 1;
        P[rand() % 500000] = 2 * (51 * i + 237) + 1;
        P[rand() % 500000] = 2 * (51 * i + 237) + 1;
        Q[2 * i] = 2 * (51 * i + 237) + 1;
    }
    for (i = 0; i < t2; i++) /* put some even numbers in Q */
    {
        Q[rand() % 200000] = 2 * (53 * i + 732);
        Q[rand() % 200000] = 2 * (53 * i + 732);
        Q[rand() % 200000] = 2 * (53 * i + 732);
        P[5 * i] = 2 * (53 * i + 732);
    }
    printf(" finished preparing two arrays. they have %d elements in common\n",
        t1 + t2);
    result = common(P, Q, 500000, 200000);
    printf(" found %d elements in common.\n", result);
    if (result == t1 + t2)
        printf(" Passed test.\n");
    else
        printf(" Failed test.\n");

}


/*
int main()
{


    int A[500];
    int B[500];
    int C[500];
    int D[500];

    sArray(A, 500);
    sArray(C, 500);

    mergesort(A, B, 500);
    mergesort(C, D, 500);
    
    //pArray(A, 500);
    //pArray(C, 500);

    printf("Common elements: %d \n", common(A, C, 500, 500));
    

    return 0;
}
*/