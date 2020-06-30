#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){     /* counting person */
  int person=1,sum=0;
  for(int i=0;i<n;i++){
    if(x < A[i]) return 0;  /* can't solve the work */
    else{
      if(x >= sum + A[i]){
        sum += A[i];        /* solve work */
      }else{
        person++;           /* switch person */
        sum = A[i];         /* solve work */
      }
    }
  }
  return k >= person;   /* meet a requirement(k <= person) -> 1 */
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1e4;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  printf("%d\n",ub);

  return 0;
}
