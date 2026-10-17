#include <iostream>
int main(){for(int n=2;n<100;n++){int i=2;while(n%i)i++;if(i==n)std::cout<<n<<" ";}}