#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	fflush(stdout);
	_setmode(_fileno(stdout), _O_BINARY);

	int i = 0;
	int j;

	while (1) {
	i = 0;
	j = fwrite(&i,1,1,stdout);
	if (j != 1)
		break; // stdoutの受取先がなくなったら抜ける
	}
	
	return 0;
}
