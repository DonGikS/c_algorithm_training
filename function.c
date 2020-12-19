#include "function.h"
//#define max(x, y) ((x)>(y) ? (x) : (y)) //define은 호출도 빠르고 쓰이는데 좋지만 특수한 상황이 아니라면 함수자체를 만들어서 쓰자(재귀함수에 매우 취약) 
//#define min(x, y) ((x)<(y) ? (x) : (y))
//###################################################################################-0.1
//서로 비교하는 함수(숫자 2개, 숫자 3개) 

int min(int x, int y){
	if(x < y) return x;
	else return y;
}
int max(int x,int y){
	if(x > y) return x;
	else return y;
}
int min_advence(int x, int y, int z){
	if(x < y){
		if(x < z) return x;
		else return z;
	}
	else{
		if(y < z) return y;
		else return z;
	}
}
int max_advence(int x, int y, int z){
	if(x > y){
		if(x > z) return x;
		else return z;
	}
	else{
		if(y > z) return y;
		else return z;
	}
}

//배열의 최대 값을 구하는 함수 
int max_arr(int arr[], int arr_len){
	int maxa, i;
	
	maxa = arr[0];
	for (i = 1; i < arr_len; i++){
		if (arr[i] > maxa) maxa = arr[i];
	}
	
	return maxa;
}
int max_arr2(int arr[], int arr_len){
	if (arr_len == 1) return arr[0];
	else return max(arr[arr_len-1], max_arr2(arr, arr_len -1));
}
