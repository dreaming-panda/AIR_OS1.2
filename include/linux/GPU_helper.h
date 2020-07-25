#ifndef _GPU_HELPER_H
#define _GPU_HELPER_H
#include"stdint.h"
#define Memory_Intensive true
#define Compute_Intensive false
enum AppType { GPU_APP, CPU_APP };
enum KernelType { Memory_Intensive, Compute_Intensive };
enum State { Memory_Load, Compute_Load, Balance_Load };
static inline bool Getbit(uint64_t x, unsigned int n)
{
	return (x >> (n - 1)) & 1;
}
static inline uint64_t Setbit(uint64_t n, unsigned int k)
{
	uint64_t nx;
	nx = 0x1 << k;
	return n = nx | n;
}
static inline uint64_t Resetbit(uint64_t n, unsigned int k)
{
	uint64_t nx;

	nx = 0x1 << k;
	nx = ~nx;
	n = n & nx;
	return n;
}
static inline unsigned int check_first_empty_bit(uint64_t n)
{
	for (unsigned int i = 1; i <= 64; i++)
	{
		if (Getbit(n, i) == false)
		{
			return i;
		}
	}
}
#endif
