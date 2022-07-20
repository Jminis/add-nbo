#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <netinet/in.h>

int main(int argc,char* argv[]){
	setvbuf(stdin,0,2,0);
	setvbuf(stdout,0,2,0);
	FILE *fp1 = fopen (argv[1], "r");
	FILE *fp2 = fopen (argv[2], "r");
	uint32_t tmp;
	uint32_t a=0,b=0,res=0;

	if( fp1 == NULL || fp2 == NULL || argc != 3)
		return -1;
	
	fread(&tmp, sizeof(uint32_t), 1, fp1);
	a = ntohl(tmp);
	fread(&tmp, sizeof(uint32_t), 1, fp2);
	b = ntohl(tmp);
	res = a + b;
	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n",a,a,b,b,res,res);
	
	fclose(fp1);
	fclose(fp2);
}
