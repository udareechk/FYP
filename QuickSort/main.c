#include <stdio.h>
#define SIZE 2000

int primes[SIZE] = {2, 0};

int isPrime(int n){
	int i;
	for (i = 2; i<n; i++){
		if (n%i == 0){
			return 0;
		}
	}
	return 1;
}

int findNextPrime(int previous){
	int current = previous+1;
	while(isPrime(current) == 0){
		current++;
	}
	printf("Prime Found: %d\n", current);
	return current;
}

void printPrimes(){
	int i;
	for (i = 0; i<SIZE; i++){
		printf("%d ", primes[i]);
	}
	printf("\n");
}

void findPrimes(){
	int i, previous = 2;
	for (i = 1; i<SIZE; i++){
		primes[i] = findNextPrime(previous);
		previous = primes[i];
	}
	printPrimes();
}


void swap(int x, int y) 
{ 
    int temp = primes[x]; 
    primes[x] = primes[y]; 
    primes[y] = temp; 
} 
  

void reverseSortArray(){
	int i,j;
	for (i = 0; i<SIZE; i++){
		for (j = 0; j<SIZE-i-1; j++){
			if (primes[j]<primes[j+1]){
				swap(j, j+1);
			}
		}
	}
}

int main(){
	findPrimes();
	reverseSortArray();
	printPrimes();
	return 0;

}