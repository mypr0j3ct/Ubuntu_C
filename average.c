#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    double rata_rata;
    long jumlah = 0;
    printf("Masukan Nilai Yang Di-inputkan:");
    scanf("%d", &N);
    if (N < 0)
    {
        printf("Jumlah angka harus lebih dari 0.\n");
        return 1;
    }
    int *p = (int *)malloc(N * sizeof(int));
    if (p == NULL)
    {
        printf("Gagal mengalokasikan memori! Program berhenti.\n");
        return 1;
    }
    for (int i = 0; i < N; i++)
    {
        char input[100];
        printf("Angka ke-%d: ", i + 1);
        scanf("%99s", input);
        getchar();
        if (strcmp(input, "N") == 0 || strcmp(input, "n") == 0)
        {
            printf("Input dihentikan oleh pengguna.\n");
            N = i;
            break;
        }
        *(p + i) = atoi(input);
        jumlah += *(p + i);
    }
    rata_rata = (double)jumlah / N;
    printf("Nilai rata-rata: %f", rata_rata);
    free(p);
    p = NULL;
    return 0;
}