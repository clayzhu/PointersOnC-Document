|
| Sum three integer arguments and return the 
| total.
|
	.text

	.globl	_sum_three_values
_sum_three_values:
	movl	sp@(4),d0	|Get 1st arg,
	addl	sp@(8),d0	|add 2nd arg,
	addl	sp@(12),d0	|add last arg.
	rts			|Return.
