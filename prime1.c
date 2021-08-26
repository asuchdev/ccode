//Aim: Given a prime number, express it as a sum of two prime numbers, if possible
#include<stdio.h>
#include<stdlib.h>

static int count_of_prime_check = 0;
//return 1 if x is a prime number
int checkPrime(int x){
	count_of_prime_check++;
	for ( int i = 2; i < x;i++){
		if ( x%i == 0){
			printf(" %d is divisible by %d\n",x,i);
			return -1;
		}
	}
	return 1;
}

void printKnownPrimes(int len, int* p_arr){
	int i = 0;
	printf("printKnownPrimes:");
	for (0; i<len ; i++)
		if(1 == p_arr[i])
			printf(" %d", i);
	printf("\n");
}

//returns 1 if found to be prime 
int checkAndMarkPrime(int x, int* p_arr){
	if ( 1 != p_arr[x]){
		if ( -1 != p_arr[x])
		//not marked earlier at all. now check and mark. this is memoization step
			p_arr[x] = checkPrime(x);
		else{
			printf("already marked not prime %d\n",x);
		}

		return p_arr[x];
	}
	printf("already marked prime %d\n",x);
	return 1;
}

int findPrimeComponents(int x){
	//Iterate from 2 to x-1 to find components. and check for prime property
	//store prime property value, and use it as part of memoization
	//first allocate an array of integers
	int *p_arr = (int*)malloc(x*sizeof(int));
	int i = 2, retval = 0, count = 0;
	for (; i<x; i++){
		count++;
		printf(" will check for %d %d\n", i, x-i);
		printKnownPrimes(x,p_arr);
		if( 1 == checkAndMarkPrime(i, p_arr) && 
				1 == checkAndMarkPrime(x-i, p_arr)){
			printf("found prime components: %d %d\n",i, x-i);
			retval = 1;
			break;
		}
		/*if( 1 == checkPrime(i) && 
				1 == checkPrime(x-i)){
			printf("found prime components: %d %d\n",i, x-i);
			return 1;
		}*/

	}
	printf("\nTotal possible prime check if memoization not done %d\n",count*2);
	return retval;
}

int main(){
	int input;
	printf("Hello, input prime \n");
	scanf(" %d", &input);
	printf("You entered %d\n",input);
	if (1 == checkPrime(input)){
		printf("%d is prime\n",input);
		if ( 0 == findPrimeComponents(input))
			printf("Could not find prime components for %d\n",input);
	}
	printf("Total number of prime checks done %d\n", count_of_prime_check);

}
