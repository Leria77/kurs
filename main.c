#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>
#include <string.h>
#include "sorts.h"

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int main(int argc, char *argv[]){
int low=0;
int n=atoi(argv[1]);
int high=n;
int m=0;
double t;
do{if(m!=0){
printf("%s\n","Введите размер массива");
scanf("%d",&n);}
if(n<=0)
printf("%s","Размер массива должен быть больше 0.\n");
m++;
}while(n<=0);
int *mass;
mass=(int*)malloc(n*sizeof(int));
if(strcmp(argv[2],"vvod")==0 && strcmp(argv[3],"shell")==0){
printf("%s","Вы выбрали сортировку Шелла и ввод с клавиатуры\nВведите массив:\n");
for(int i=0;i<n;i++)
{
scanf("%d",&mass[i]);
}
t=wtime();
shell1(mass,n);
t=wtime()-t;
}
if(strcmp(argv[2],"rand")==0 && strcmp(argv[3],"shell")==0){
printf("%s","Вы выбрали сортировку Шелла и рандомный ввод\nВаш массив:\n");
for(int i=0;i<n;i++)
{
mass[i]=getrand(1,100);
printf("%3d",mass[i]);
}
printf("%s\n"," ");
t=wtime();
shell1(mass,n);
t=wtime()-t;
}
if(strcmp(argv[2],"vvod")==0 && strcmp(argv[3],"merge")==0){
printf("%s","Вы выбрали сортировку слиянием и ввод с клавиатуры\nВведите массив:\n");
for(int i=0;i<n;i++)
{
scanf("%d",&mass[i]);
}
t=wtime();
MergeSort(mass,low,high,n);
t=wtime()-t;}
if(strcmp(argv[2],"rand")==0 && strcmp(argv[3],"merge")==0){
printf("%s","Вы выбрали сортировку слиянием и рандомный ввод\nВаш массив:\n");
for(int i=0;i<n;i++)
{
mass[i]=getrand(1,100);
printf("%3d",mass[i]);
}
printf("%s\n"," ");
t=wtime();
MergeSort(mass,low,high,n);
t=wtime()-t;}
printf("%s","Отсортированный массив:\n");
for(int i=0;i<n;i++){
printf("%3d",mass[i]);
}
printf("%s\n"," ");
printf("Время сортировки: %.6f сек.\n", t);
free(mass);
return 0;
}
