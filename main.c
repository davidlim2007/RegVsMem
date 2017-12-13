// Execution time of C program
// https://stackoverflow.com/questions/5248915/execution-time-of-c-program
//
// How do I set a UInt32 to it's maximum value
// https://stackoverflow.com/questions/20070374/how-do-i-set-a-uint32-to-its-maximum-value
//
// Gen code without runtime checks in VC++
// https://stackoverflow.com/questions/7172315/gen-code-without-runtime-checks-in-vc
//

#include <stdio.h>
#include <stdint.h>
#include <time.h>





void DoMaxLoopMem()
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int max = UINT32_MAX; // Must be Unsigned int
	clock_t begin = 0;
	clock_t end = 0;
	double time_spent = 0;

	begin = clock();

	for (i = 0; i < max; i++)
	{
		j++;
	}

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Time taken : %f\n", time_spent);
}




// Note: Registers use Unsigned integers.
void DoMaxLoopReg()
{
	clock_t begin = 0;
	clock_t end = 0;
	double time_spent = 0;

	begin = clock();

	__asm
	{
		// ecx represents the variable "j".
		// Here we initialize it to 0.
		mov ecx, 0
		// eax represents the variable "i".
		//for (i = 0; i < max; i++)
		mov	eax, 0
		jmp	SHORT LN4_DoMaxLoopReg
LN2_DoMaxLoopReg:
		add	eax, 1
LN4_DoMaxLoopReg:
		cmp	eax, 0xFFFFFFFF
		jae	SHORT LN3_DoMaxLoopReg
		//{
			//j++;
			add	ecx, 1
		//}
		jmp	SHORT LN2_DoMaxLoopReg

LN3_DoMaxLoopReg:

	}

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Time taken : %f\n", time_spent);
}





void main()
{
	DoMaxLoopMem();
	DoMaxLoopReg();
}
