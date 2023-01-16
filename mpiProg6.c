#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Enter the value of n");
  scanf("%d", &n);

  int a[100], b[100], c[100];
  printf("\n Array A\n");
  for (int i = 0; i < n; i++) {
    a[i] = rand() % 10;
    printf(" %d ", a[i]);
  }
  printf("\n Array B \n");
  for (int i = 0; i < n; i++) {
    b[i] = rand() % 10;
    printf(" %d ", b[i]);
  }
  printf("\n result \n");
#pragma omp parallel for
      for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
        int t = omp_get_thread_num();
    printf("\n Task : %d, A[i] = %d + B[i] = %d = %d ",t,a[i],b[i],c[i]);
  }
}
