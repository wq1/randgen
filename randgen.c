﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

int main (int argc, char *argv[]) {

	int i;
	int j;
	int m = 0x00;
	int M = 0xFF;
	long long tgt = 0;
	long long out = 0;

	if ( argv[1] != NULL ) {

		char num[32];
		sprintf(num, "%s", argv[1]);

		char si[2];
		sprintf(si, "%c", num[strlen(num)-1]);

		num[strlen(num)-1] = '\0';

		if      ( strcmp(si, "K") == 0 )
			tgt = atoll(num)*1024;
		else if ( strcmp(si, "M") == 0 )
			tgt = atoll(num)*1024*1024;
		else if ( strcmp(si, "G") == 0 )
			tgt = atoll(num)*1024*1024*1024;
		else if ( strcmp(si, "T") == 0 )
			tgt = atoll(num)*1024*1024*1024*1024;
		else if ( strcmp(si, "P") == 0 )
			tgt = atoll(num)*1024*1024*1024*1024*1024;
		else if ( strcmp(si, "E") == 0 )
			tgt = atoll(num)*1024*1024*1024*1024*1024*1024;
		else {
			sprintf(num, "%s", argv[1]);
			tgt = atoll(num);
		}

	}

	fflush(stdout);
	_setmode(_fileno(stdout), _O_BINARY);

	srand((unsigned) time(NULL));

	while (1) {

		//i = rand()%0x100; // 0x00-0xFF 低精度
		i = m + (int)( (double) rand() * (double)(M-m+1) / (double)(RAND_MAX+1) ); // 高精度
		j = fwrite(&i,1,1,stdout);
		out = out+1;
		if ( out == tgt || j != 1 ) // 目標サイズに達するか受取先が終了する
			break;

	}

	return 0;

}
