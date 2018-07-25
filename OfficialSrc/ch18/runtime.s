	.data
	.even
	.globl	_static_variable
_static_variable:
	.long	5
	.text

	.globl	_f
_f:	link	a6,#-88
	moveml	#0x3cfc,sp@
	moveq	#1,d7
	moveq	#2,d6
	moveq	#3,d5
	moveq	#4,d4
	moveq	#5,d3
	moveq	#6,d2
	movl	#7,a6@(-4)
	movl	#8,a6@(-8)
	movl	#9,a6@(-12)
	movl	#10,a6@(-16)
	movl	#110,a5
	movl	#120,a4
	movl	#130,a3
	movl	#140,a2
	movl	#150,a6@(-20)
	movl	#160,a6@(-24)
	movl	#170,a6@(-28)
	movl	#180,a6@(-32)
	movl	#190,a6@(-36)
	movl	#200,a6@(-40)
	movl	#1,_a_very_long_name_to_see_how_long_they_can_be
	movl	a6@(-16),sp@-
	movl	d7,sp@-
	pea	10
	jbsr	_func_ret_int
	lea	sp@(12),sp
	movl	d0,d6
	jbsr	_func_ret_double
	movl	d0,a6@(-48)
	movl	d1,a6@(-44)
	pea	a5@
	jbsr	_func_ret_char_ptr
	addqw	#4,sp
	movl	d0,a5
	moveml	a6@(-88),#0x3cfc
	unlk	a6
	rts

	.globl	_func_ret_int
_func_ret_int:
	link	a6,#-8
	moveml	#0x80,sp@
	movl	a6@(16),d7
	movl	a6@(12),d0
	subql	#6,d0
	movl	d0,a6@(-4)
	movl	a6@(8),d0
	addl	a6@(12),d0
	addl	d7,d0
	moveml	a6@(-8),#0x80
	unlk	a6
	rts

	.globl	_func_ret_double
_func_ret_double:
	link	a6,#0
	moveml	#0,sp@
	movl	L2000000,d0
	movl	L2000000+4,d1
	unlk	a6
	rts
L2000000:	.long	0x40091eb8,0x51eb851f

	.globl	_func_ret_char_ptr
_func_ret_char_ptr:
	link	a6,#0
	moveml	#0,sp@
	movl	a6@(8),d0
	addql	#1,d0
	unlk	a6
	rts
