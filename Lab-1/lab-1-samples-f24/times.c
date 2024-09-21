#include <sys/times.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdint.h>


// From Wikipedia: https://en.wikipedia.org/wiki/Salsa20#ChaCha_variant
#define ROTL(a,b) (((a) << (b)) | ((a) >> (32 - (b))))
#define QR(a, b, c, d) (             \
	a += b, d ^= a, d = ROTL(d, 16), \
	c += d, b ^= c, b = ROTL(b, 12), \
	a += b, d ^= a, d = ROTL(d,  8), \
	c += d, b ^= c, b = ROTL(b,  7))
#define ROUNDS 20

uint32_t key[] = {
	1701978209,1852789803,841489017,1952807021,
	1701978209,1852789803,841489017,1952807021,
	1701978209,1852789803,841489017,1952807021,
	0,0,841489017,1952807021
};
uint32_t word[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

void chacha_block(uint32_t out[16], uint32_t const in[16])
{
	int i;
	uint32_t x[16];

	for (i = 0; i < 16; ++i)
		x[i] = in[i];
	// 10 loops × 2 rounds/loop = 20 rounds
	for (i = 0; i < ROUNDS; i += 2) {
		// Odd round
		QR(x[0], x[4], x[ 8], x[12]); // column 1
		QR(x[1], x[5], x[ 9], x[13]); // column 2
		QR(x[2], x[6], x[10], x[14]); // column 3
		QR(x[3], x[7], x[11], x[15]); // column 4
		// Even round
		QR(x[0], x[5], x[10], x[15]); // diagonal 1 (main diagonal)
		QR(x[1], x[6], x[11], x[12]); // diagonal 2
		QR(x[2], x[7], x[ 8], x[13]); // diagonal 3
		QR(x[3], x[4], x[ 9], x[14]); // diagonal 4
	}
	for (i = 0; i < 16; ++i)
		out[i] = x[i] + in[i];
}

int main(){
	struct tms t_buf;
	long ticks_per_second = sysconf(_SC_CLK_TCK);
	
	clock_t start_ticks = times(&t_buf);
	pid_t pid = fork();
	if (pid == 0){
		for (volatile long i = 0; i < 10000000; ++i)
		{
			word[i%16] = i;
			key[13] = i;
			chacha_block(word,key);	
		}
		_exit(0);
	}
	for (volatile long i = 0; i < 5000000; ++i)
	{
		word[i%16] = i;
		key[13] = i;
		chacha_block(word,key);	
	}
	wait(NULL);
	clock_t end_ticks = times(&t_buf);
	printf("Ticks: %li\n",(end_ticks - start_ticks));
	printf("User time: %lf\n", (double)t_buf.tms_utime / ticks_per_second);
	printf("System time: %lf\n", (double)t_buf.tms_stime / ticks_per_second);
	printf("Children user time: %lf\n", (double)t_buf.tms_cutime / ticks_per_second);
	printf("Children System time: %lf\n", (double)t_buf.tms_cstime / ticks_per_second);
	return 0;
}
