#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	FILE *fp1;
	FILE *fp2;
	uint32_t a, b, c;

	fp1=fopen(argv[1], "rb");
	fp2=fopen(argv[2], "rb");

	fread(&a, sizeof(uint32_t), 1, fp1);
	fread(&b, sizeof(uint32_t), 1, fp2);

	a=htonl(a);
	b=htonl(b);

	c=a+b;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, c, c);

	fclose(fp1);
	fclose(fp2);
	return 0;
}
