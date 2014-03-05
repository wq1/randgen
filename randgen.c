#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

int main(void)
{
	fflush(stdout);
	_setmode(_fileno(stdout), _O_BINARY);

	srand((unsigned) time(NULL));

	int i,j;
	int m = 0;
	int M = 255;

	while (1) {
	//i = rand()%256; // 0x00-0xFF 低精度
	i = m + (int)( (double) rand() * (double)(M-m+1) / (double)(RAND_MAX+1) ); // 高精度
	j = fwrite(&i,1,1,stdout);
	if (j != 1)
		break; // stdoutの受取先がなくなったら抜ける
	}
	
	return 0;
}
