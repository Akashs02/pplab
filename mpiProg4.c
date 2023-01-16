#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int fib(int n){
  int i,j;
  if(n < 2){
    return n;
  }else{

    #pragma omp task shared(i) firstprivate(n)
    i = fib(n-1);
    #pragma omp task shared(j) firstprivate(n)
    j = fib(n-2);
    #pragma omp taskwait
    return i+j;
  }
  
}

int main(){
  int n = 10;
  double start = omp_get_wtime();
  #pragma omp parallel for
  for(int i = 0; i < n; i++){
    int t = omp_get_thread_num();
    printf("Task : %d fib(%d) = %d \n",t,i,fib(i));
  }
  double end = omp_get_wtime();
  printf("the taken is %lf ",end - start);
}
