#include <iostream>
#include <cstdint>
#include <fstream>
#include <algorithm> 
#include <string>
#include <string.h>

int modInverse(int e, int pq_product);
bool isPrime(int e);
int log_power(int n, int p, int mod);
int encrypt(int plain, int key1, int key2);
int decrypt(int cipher, int key1, int key2);
int gcd(int num1, int num2);
using namespace std;
int main(int argc, char** argv)
	{
    cout << "Usage: rsa.o p q [-e] [-d] val plain";
	int64_t p=0,q=0,e=0,f=0,d=0,n=0;
	p = atoi(argv[1]);
	if (!isPrime(p)){
        cout << "Choose p again, it is not a prime number";
        exit(1);
    }
	q = atoi(argv[2]);
    if (!isPrime(q)){
        cout << "Choose p again, it is not a prime number";
        exit(1);
    }
	
	cout << "P is " << p << " q is " << q;
	
	n  = (p*1) * (q*1);
	
	f = (p-1)*1 * (q-1)*1;
	
    while (gcd(e , f) != 1)
	    e = (rand()%61440) +4096;
	
	cout << " e is" << e << " f is " << f << endl;
	
	d = modInverse(e,f);
	
	cout << "d is " << d << endl;
	
    //Public Key Pair
	cout << "The Public Key Pair is (n,e) " << n << " " << e << endl;
	cout << "The Private Key Pair is (n,d) " << n << " " << d << endl;
	
	if (strcmp(argv[3],"-e") == 0){
		int input = atoi(argv[5]);
        int result = encrypt(input, n,e);
		cout << "Encryption: " << result;
	}
	else if (strcmp(argv[3],"-d") == 0)
	{
		int input = atoi(argv[4]);
		cout << "Decryption:" << decrypt(input, n,d);
	}	
	return 0;
}

int encrypt(int plain, int key1, int key2)
{
    return log_power(plain, key1, key2);
}

int decrypt(int cipher, int key1, int key2)
{
    return log_power(cipher, key1, key2);
}

int gcd(int num1, int num2){
    int temp;

    while(num2 > 0){
      temp = num1 % num2;
      num1 = num2;
      num2 = temp;
    }
     
    return num1;
}

bool isPrime(int e)
{
	if (e ==0 || e == 1)
		return 0;
	for (int i=2; i < e; i++)
	{
		if (e % i == 0){
			return  0; //return false is there is an other factor of the number and hence the number is non __prime
		}
	}
	return true; //return this is the number is __prime
}

// This function returns the modular exponenetatiation of the numbers
int MEA(int x, unsigned int y, int p)  
{  
    int res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}  

int log_power(int n, int p, int mod)
{
    int result = 1;
    for (; p; p >>= 1)
    {
        if (p & 1)
            result = (1LL * result * n) % mod;
        n = (1LL * n * n) % mod;
    }
    return result;
}

//This-function-is-used-to-return-the-d-number-of-the-private-key
int modInverse(int e, int pq_product)
{
    e = e % pq_product; 
    for (int x=1; x<pq_product; x++) 
       if ((e*x) % pq_product == 1) 
          return x; 
}