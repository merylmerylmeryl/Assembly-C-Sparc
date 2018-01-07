/***********************************************************************/
/*  Meryl Mabin                                                        */
/*  Project # 10                                                       */
/*  Support Module 						       */
/***********************************************************************/



/***********************************************************************/
/*  Function:  absolute                                                */
/*  Input:  double						       */
/*  Purpose:  calculate absolute value                                 */
/*  Return value:  a double, the absolute value of input               */
/***********************************************************************/

	.global	 absolute
	.section ".text"
	.align	 4
absolute:
	save	 %sp, -112, %sp

	std	 %i0, [%sp+96]
	ldd	 [%sp+96], %f0

	set	 zero, %l0		! Put address of 0.0 into %l0
	set	 neg_one, %l1		! Put address of -1.0 into %l1

	ldd	 [%l0], %f2		! Constant (%f2/3) <== 0.0
	ldd	 [%l1], %f4		! Constant (%f4/5) <== -1.0

if1:
	fcmpd	 %f0, %f2		! Compare input to 0
	nop

	fbge	 endif1			! If greater, don't convert
	nop

	fmuld	 %f0, %f4, %f0		! Negate %f0 if it's negative
endif1:

	ret
	restore


/***********************************************************************/
/*  Function:  modulo                                                  */
/*  Input:  two doubles						       */
/*  Purpose:  Calculate remainder of X / Y                             */
/*  Return value:  a double, remainder of X / Y                        */
/***********************************************************************/

	.global	 modulo
	.section ".text"
	.align   4
modulo:
	save	 %sp, -112, %sp

	std	 %i0, [%sp+96]
	ldd	 [%sp+96], %f2		! Load input into %f2/%f3

	std	 %i2, [%sp+96]
	ldd	 [%sp+96], %f4

	set	 zero, %l0
	ldd	 [%l0], %f8
if2:
	fmovd	 %f30, %f0
	fcmpd	 %f4, %f8
	nop
	fbe	 endif2
	nop

	fdivd	 %f2, %f4, %f6
	fdtoi	 %f6, %f6
	fitod	 %f6, %f6

	fmuld	 %f6, %f4, %f6		! Y * division result
	fsubd	 %f2, %f6, %f0		! Subtract it from X
endif2:

	ret
	restore


/***********************************************************************/
/*  Function:  factorial                                               */
/*  Input:  an unsigned int					       */
/*  Purpose:  Calculate factorial                                      */
/*  Return value:  a double, the factorial of input                    */
/***********************************************************************/

	.global	 factorial
	.section ".text"
	.align	 4

factorial:
	save	 %sp, -112, %sp

	std	 %i0, [%sp+96]
	ldd	 [%sp+96], %f4		! Load argument into %f4/5

	fitod	 %f4, %f4		! Convert int to double

	set	 one, %l1		! Put address of 1.0 into %l1

	ldd	 [%l1], %f0		! Return value (%f0/1) <== 1.0
	ldd	 [%l1], %f2		! Multiplier (%f2/3) <== 1.0
	ldd	 [%l1], %f6		! Constant (%f6/7) <== 1.0

loop2:
	fcmpd	 %f4, %f2		! Compare start val to multiplier
	nop

	fbl	 endloop2		! If it's less than multiplier, quit
	nop

	fmuld	 %f0, %f2, %f0		! Multiplier * factorial
	faddd	 %f2, %f6, %f2		! Add 1 to multiplier

	ba	 loop2
	nop
endloop2:
	ret
	restore


/***********************************************************************/
/*  Function:  power                                                   */
/*  Input:  a double and an unsigned				       */
/*  Purpose:  Calculate X to the power of N                            */
/*  Return value:  a double, X to the power of N                       */
/***********************************************************************/

	.global	 power
	.section ".text"
	.align	 4

power:
	save	 %sp, -112, %sp

	std	 %i0, [%sp+96]
	ldd	 [%sp+96], %f8		! Store X into %f8/%f9
	fmovd	 %f8, %f0

	std	 %i2, [%sp+96]
	ldd	 [%sp+96], %f2		! Store Y into %f2/%f3
	fitod	 %f2, %f2		! CONVERT INT TO FLOAT

	set	 zero, %l0
	set	 one, %l1
	ldd	 [%l0], %f4		! Load 0.0 into %f4/%f5
	ldd	 [%l1], %f6		! Load 1.0 into %f6/%f7

if4:
	fcmpd	 %f2, %f4		! If Y == 0, return 1
	nop
	fbe	 then4
	nop
	ba	 endif4
	nop
then4:
	fmovd	 %f6, %f0
	ba	 endloop3
	nop
endif4:

loop3:
	fcmpd	 %f2, %f6		! If Y <= 1, QUIT
	nop
	fble	 endloop3
	nop

	fmuld	 %f0, %f8, %f0		! Multiply by X
	fsubd	 %f2, %f6, %f2		! Decrement Y

	ba	 loop3
	nop
endloop3:
	ret
	restore


/***********************************************************************/
/*  Function:  cosine                                                  */
/*  Input:  a double X  					       */
/*  Purpose:  Calculate the cosine of X                                */
/*  Return value:  a double, the cosine of input                       */
/***********************************************************************/

	.global	 cosine
	.section ".text"
	.align	 4

cosine:
	save	 %sp, -112, %sp

	std	 %i0, [%sp+96]
	ldd	 [%sp+96], %f14		! X is in %f14/%f15

	set	 two, %l0
	set	 one, %l1
	set	 E_val, %l2
	set	 M_PI, %l3
	set	 neg_one, %l4
	set	 zero, %l5
	ldd	 [%l0], %f16		! Store 2.0 in %f16/%f17
	ldd	 [%l2], %f24		! Store E_val in %f26/%f27
	ldd	 [%l3], %f28		! Store PI in %f28/%f29
	ldd	 [%l4], %f18		! Store -1.0 %f18/%f19

	fmuld	 %f28, %f16, %f28	! 2 * PI in %f28/%f29
	mov	 %i0, %o0

	std 	 %f28, [%sp+96]
	ldd	 [%sp+96], %o2
	std	 %f14, [%sp+96]
	call	 modulo			! modulo
	nop
	ldd	 [%sp+96], %f14

	mov	 0, %l6			! counter
	fmovd	 %f0, %f2		! X % 2*PI
	ldd	 [%l5], %f20		! Term sum = 0

loop4:
	std	 %f18, [%sp+96]		! -1
	ldd	 [%sp+96], %o0		! pow(-1, counter)
	std	 %f14, [%sp+96]		! SAVE X
	mov	 %l6, %o2		! counter
	call	 power
	nop
	fmovd	 %f0, %f22		! save intermediate result
	ldd	 [%sp+96], %f14

	std	 %f14, [%sp+96]		! X
	ldd	 [%sp+96], %o0		! pow(X, 2*counter)
	std	 %f14, [%sp+96]		! SAVE X
	mov	 %l6, %o2
	smul	 %o2, 2, %o2		! counter * 2
	call	 power
	nop
	ldd	 [%sp+96], %f14

	fmuld	 %f22, %f0, %f22	! multiply the intermediates

	std	 %f2, [%sp+96]
	mov	 %l6, %o0
	smul	 %o0, 2, %o0		! counter * 2
	call	 factorial
	nop
	ldd	 [%sp+96], %f12

	fdivd	 %f22, %f0, %f22	! TERM

	std	 %f22, [%sp+96]
	ldd	 [%sp+96], %o0
	std	 %f14, [%sp+96]		! SAVE X
	call	 absolute
	nop
	ldd	 [%sp+96], %f14

if5:
	fcmpd	 %f0, %f24		! Is abs(term) < E_val?
	nop
	fbl	 endloop4
	nop
then5:
	faddd	 %f20, %f22, %f20	! Cumulative sum
	inc	 %l6
	ba	 loop4
	nop
endif5:

endloop4:
	fmovd	 %f20, %f0

	ret
	restore

	 .align 8
one:	 .double  0r1.0
two:	 .double  0r2.0
place:	 .double  0r0.0
zero:	 .double  0r0.0
neg_one: .double  0r-1.0
M_PI:	 .double  0r3.14159265358979323846
E_val:   .double  0r0.000000001
