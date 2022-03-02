#include<stdio.h>
#include<inttypes.h>

void main()
{
	printf("Enter text - ");
	uint64_t p, c, temp;
	uint32_t k, r0, l0, r1, l1;
	scanf("%" SCNu64, &p);
	printf("Enter key - ");
	scanf("%" SCNu32, &k);
	r0 = p & UINT32_MAX;
	l0 = p >> 32;
	printf("right part - %"PRIu32", left part - %"PRIu32"\n",r0,l0);
	temp = (k^r0)+1;
	temp &= UINT32_MAX;
	printf("After applying function to r0 output - %"PRIu32"\n",(uint32_t)temp);
	l1 = r0;
	r1 = l0^(uint32_t)temp;
	printf("After XORing with l0 - %"PRIu32"\n",r1);
	c = l1;
	c = c << 32;
	c += r1;
	printf("Cipher text - %"PRIu64"\n", c);
	r1 = c & UINT32_MAX;
	l1 = c >> 32;
	printf("\nL1 - %"PRIu32" , R1 - %"PRIu32"\n",l1,r1);
	temp = (k^l1) + 1;
	temp &= UINT32_MAX;
	l0 = (uint32_t)temp ^ r1;
	r0 = l1;
	temp = l0;
	temp << 32;
	temp += r0;
	printf("Decrypted text - %"PRIu64"\n", temp);
}