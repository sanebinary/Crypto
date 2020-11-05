#include <iostream>
using namespace std;
int modInverse(int e, int pq_product)
{
    e = e % pq_product; 
    for (int x=1; x<pq_product; x++) 
       if ((e*x) % pq_product == 1) 
          return x; 
}

int main(){
    cout << modInverse(15,2);
    return 0;
}