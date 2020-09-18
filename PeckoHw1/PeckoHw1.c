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

void sArray(int* a, const int size){
    int i;
    srand((unsigned int)time((time_t)0));
    for (i = 0; i < size; i++) a[i] = rand();
}

void pArray(int* a, const int size) {
    int i;
    for (i = 0; i < size; i++) printf("%d \n", a[i]);
}

int main()
{
    int A[5000];
    int B[5000];
    int C[5000];
    int D[5000];

    sArray(A, 5000);
    sArray(C, 5000);

    mergesort(A, B, 5000);
    mergesort(C, D, 5000);
    
    pArray(A, 5000);
    //pArray(C, 5);

    printf("Common elements: %d \n", common(A, C, 5000, 5000));

    return 0;
}