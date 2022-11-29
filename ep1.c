#include <stdio.h>
#include <time.h>
int n;
float tempo = 0;

void Clock(int stat){		//0 retorna o tempo, 1 reseta o relógio. Qualquer outro input retorna -1
	static clock_t start;
	if(stat ==1){
		start = clock();
	}
	else{
		if (stat == 0){
			clock_t end = clock();
			tempo =  1000*(((float)(end-start))/CLOCKS_PER_SEC);
		}
	}
}

void PrintArray(int array[], int sizeOfArray){
	for (int i=0; i < sizeOfArray; i++){
		printf("%i ", array[i]);
	}
	printf("\n");
}

void SwapNumber(int *a, int *b){
	int i = *a;
	*a = *b;
	*b = i;
}

int Particao(int array[], int min, int max){
	int pivot = array[max];
	int i = min;
	for (int j = min; j < max; j++){
		if (array[j] < pivot){
			SwapNumber(&array[j], &array[i]);
			i++;
		}
	}
	SwapNumber(&array[i], &array[max]);
	return i;
}

void QuickSort(int array[], int min, int max){
	if (min < max){
		int pi = Particao(array, min, max);
		QuickSort(array, min, pi-1);
		QuickSort(array, pi+1, max);
	}
}

int Selecao1(int array[], int tamanho, int i){
	QuickSort(array, 0, tamanho-1);
	return array[i];
}

int Selecao2(int array[], int min, int max, int i){
	int q = Particao(array, min, max);
	if (n == 1){
		return array[1];
	}
	if (i < q){
		return Selecao2(array, min, q-1, i);
	}
	else{
		if (i > q){
			return Selecao2(array, q+1, max, i);
		}
		else{
			return array[q];
		}
	}
}

int main(){
	scanf("%i", &n);
	int array[n];
	int array2[n];
	for (int i=0; i<n; i++){
		scanf("%i", &array[i]);
		array2[i] = array[i];
	}
	printf("\npronto\n");
	Clock(1);
	Selecao1(array, n, n-1);
	Clock(0);
	printf("\n\nDuração Selecao1: %.2fms\n", tempo);
	Clock(1);
	Selecao2(array2, 0, n, n-1);
	Clock(0);
	printf("\nDuração Selecao2: %.2fms\n", tempo);
}
