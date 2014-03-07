#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	int i = 0;
	int j = 0;
	int z = 0;
	int m = 0x00;
	int M = 0xFF;
	long long tgt = 0;
	long long out = 0;
	int c;
	time_t t0,t1;

	while ((c = getopt(argc, argv, "zs:")) != -1) {
		switch (c) {

		case 'z':
			z = 1;
			break;

		case 's': {
			char num[32];
			sprintf(num, "%s", optarg);

			int si = num[strlen(num)-1];
			num[strlen(num)-1] = '\0';

			switch (si) {
			case 'K':
				tgt = atoll(num)*1024;
				break;
			case 'M':
				tgt = atoll(num)*1024*1024;
				break;
			case 'G':
				tgt = atoll(num)*1024*1024*1024;
				break;
			case 'T':
				tgt = atoll(num)*1024*1024*1024*1024;
				break;
			case 'P':
				tgt = atoll(num)*1024*1024*1024*1024*1024;
				break;
			case 'E':
				tgt = atoll(num)*1024*1024*1024*1024*1024*1024;
				break;
			default:
				sprintf(num, "%s", optarg);
				tgt = atoll(num);
				break;
			}

			break;
		}

		default: // case '?':
			break;

		}
	}

	fflush(stdout);
	_setmode(_fileno(stdout), _O_BINARY);

	srand((unsigned) time(NULL));

	t0 = time(NULL);

	while (1) {
		if (z != 1) {
			//i = rand()%0x100; // 0x00-0xFF 低精度
			i = m + (int)((double) rand() * (double)(M-m+1) / (double)(RAND_MAX+1)); // 高精度
		}
		j = fwrite(&i,1,1,stdout);
		out++; // out = out+1;
		if (out == tgt || j != 1) // 目標サイズに達するか受取先が終了する
			break;
	}

	t1 = time(NULL);

	fprintf(stderr, "%d byte(s) out\n", out);
	fprintf(stderr, "%d second(s) elapsed\n", (long)(t1 - t0));

	return 0;
}
