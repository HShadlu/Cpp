// C program to check if a 
// number is prime 
  
#include <stdio.h> 
#include<math.h> 
int isprime(int n){
	int flag=1;
	for (int i = 2; i <= sqrt(n); i=i+1) { 
  
        // If n is divisible by any number between 
        // 2 and n/2, it is not prime 
        if (n % i == 0) { 
            flag = 0; 
            break; 
        } 
    } 
  
    if(n<=1) 
    flag=0; 
    else if(n==2) 
    flag=1;  
  
    if (flag == 1) { 
        return 1; 
    } 
    else { 
        return 0;
    } 
	
	
}
int main() 
{   long int mul=0;
    long int x;
    
    long int mulmin=(10000*10000);
    scanf("%d",&x);
    for(int n=10000;n>1;n=n-1){
    	if(isprime(n)){
    	   for(int c=10000;c>1;c=c-1){
    		if(isprime(c)){
    			if(c!=n){
				
    			mul=c*n;
    			if(mul>x && mul%3==2 && mul<mulmin){
    				mulmin=mul;
    				
				}
			}	
			}
    		
		}	
    		
		}
   
	}
printf("%d",mulmin);
  
} 

