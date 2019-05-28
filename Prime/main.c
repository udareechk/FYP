#include <stdio.h>

int primes[1000] = {2,3,0};

int* primesBelowX(int x){
	int i,counter,check, temp;
	
    i = 0;

    while (primes[i] <= x){
        i = i+1;

        if (primes[i] == 0){
            counter = primes[i-1];
		    check = 0;
			while (check == 0){
				counter++;
				if (counter%2 !=0 && counter%3 !=0){
					temp = 4;
					while (temp*temp <= counter){
						if (counter%temp == 0){
							break;
						}
						temp = temp+1;
					}
					if (temp*temp>counter){
						primes[i] = counter;
						check = 1;
					}
				}    
			}
		}
	}
	return primes;
}

int maxPrime(int n){
	int i = 0;
	int largestPrime = 0;
	while (primes[i]<n){
		if (n % primes[i] == 0){
			largestPrime = primes[i];
		}
		i++;
	}
	return largestPrime;
}

int add(){

	int a, i;
	for (i = 0; i<10000; i++){
		a = 2+3;
		printf("%d\n", a);
	}
	return 0;
}


int main(){
	primesBelowX(1000);
	int i;
	for (i = 0; i<100; i++){
		printf("%d, %d\n",i, maxPrime(i));
	}

	add();

	return 0;
}