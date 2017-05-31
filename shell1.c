#include "sorts.h"

void shell1(int *mass,int size){
int i,j,step,tmp;
 for (step =size / 2; step > 0; step /= 2)
      {
        for (i = step; i < size; i++) 
 {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp<mass[j-1])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j]=tmp;
}
  }
}

