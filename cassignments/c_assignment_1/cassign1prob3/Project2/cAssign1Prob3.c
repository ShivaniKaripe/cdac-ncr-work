#include<stdio.h>
int main()
{
	int val = 0xCAFE;
	int mask = 0x000F;
	int res1,res2,count;
	res1 = val&mask;
	
	
	for (count = 0; res1; res1 >>= 1)
	{
		count = count + (res1 & 1);

	}
	
	
	if (count >= 3)
	{
		printf_s("the atleast 3 of last 4 bits are on ");
	}
	res1 = val & 0x00FF;
	res2 = val & 0xFF00;
	res1 = res1 << 8;
	res2 = res2 >> 8;
	
	printf_s("\n reverse byte order of CAFE is %X", res1 | res2);
	
	res1 = ((val >> 4) | ((val & 0x000F)<<12));
	printf_s("right rotation by 4 bits %X",res1 );
	scanf_s("%d", res1);
}