#include"sorts.h"

void merge(int* mass, int low, int mid, int high,int k){

	 int b[k];
	 for(int i=low;i<high;i++){
	 	b[i]=mass[i];
	 }	
	int l=low;
	 int r=mid+1;
	 int i=low;
	 while(l<=mid && r<=high){
	 	if(b[l]<=b[r]){
	 		mass[i]=b[l];
	 		l++;
	 	}
	 	else{
	 		mass[i]=b[r];
	 		r++;
	 	}
	 	i++;
	 }
	 while(l<=mid){
	 	mass[i]=b[l];
	 	l++;
	 	i++;
	 }
	 while(r<=high){
	 	mass[i]=b[r];
	 	r++;
	 	i++;
	 }

}
void MergeSort(int *mass, int low, int high,int l){
	int mid;
	
	if(low<high){
		mid=((low+high)/2);
		MergeSort(mass,low,mid,l);
		MergeSort(mass,mid+1,high,l);
		merge(mass,low,mid,high,l);
	}	
}
