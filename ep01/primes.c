#include <stdio.h>
int main(void){int n,i;for(n=1;++n<100;){for(i=1;n%++i;);i==n&&printf("%d ",n);}}
