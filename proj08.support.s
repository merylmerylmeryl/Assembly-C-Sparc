
/******************************************************************************
  Meryl Mabin
  Project #8 -- SPARC Subprograms
  Support Module
******************************************************************************/

        .global  negate
        .section ".text"
        .align   4
negate:
        save     %sp, -96, %sp
	smul	 %i0, -1, %i0

        ret
        restore


	.global  absolute
	.section ".text"
	.align   4
absolute:
	save	 %sp, -96, %sp

if1:
	cmp	 %i0, 0		  ! Compare argument to 0
	be	 endif1		  ! If N == 0, exit if1
	nop
	bgt	 endif1		  ! If N > 0, exit if1
	nop

	smul	 %i0, -1, %i0
endif1:

	ret
	restore



	.global  power
	.section ".text"
	.align   4
power:
	save	 %sp, -96, %sp

if2:
	cmp	 %i1, 0
	bne	 endif2
	nop
then2:
	mov	 1, %i0
	ba	 done
	nop
endif2:
if3:
	cmp	 %i1, 0

	bgt	 endif3
	nop
then3:
	mov	 0, %i0
	ba	 done
	nop
endif3:

	mov	 %i0, %l0
	mov	 %i1, %l1
loop1:
	cmp	 %l1, 1
	be	 endloop1
	nop

	smul	 %i0, %l0, %i0
	dec	 %l1

	ba	 loop1		  ! Jump to top of loop
	nop
endloop1:

	rd	 %y, %l4
	cmp	 %l4, 0
	bne	 overflow
	nop

	ba	 done
	nop



	.global  factorial
	.section ".text"
	.align   4
factorial:
	save	 %sp, -96, %sp
if4:
	cmp	 %i0, 0
	bne	 endif4
	nop
then4:
	mov	 1, %i0
	ba	 done
	nop
endif4:
if5:
	cmp	 %i0, 0
	bgt	 endif5
	nop
then5:
	mov	 0, %i0
	ba	 done
	nop
endif5:

	mov	 %i0, %l0
	dec	 %l0
loop2:
	cmp	 %l0, 0
	be	 endloop2
	nop

	smul	 %i0, %l0, %i0
	dec	 %l0

	ba	 loop2
	nop
endloop2:

	rd	 %y, %l4
	cmp	 %l4, 0
	bne	 overflow
	nop

	ba	 done
	nop



	.global  sum
	.section ".text"
	.align	 4

sum:
	save	 %sp, -96, %sp

if6:
	cmp	 %i0, %i1
	ble	 endif6
	nop
then6:
	mov	 0, %i0
	ba	 done
	nop
endif6:

	mov	 %i0, %l0
	mov	 %i1, %l1
	mov	 0, %i0

loop3:
	cmp	 %l0, %l1
	bgt	 endloop3
	nop

	addcc	 %i0, %l0, %i0

	inc	 %l0

	ba	 loop3
	nop
endloop3:

	rd	 %y, %l6
	cmp	 %l6, 0
	bne	 overflow
	nop

	ba	 done
	nop


	.global  ceiling
	.section ".text"
	.align   4

ceiling:
	save	 %sp, -96, %sp

	ld	 [%i0], %f0
	fstoi	 %f0, %f1
	st	 %f1, [%i0]

	ba	 done
	nop

	.global  flooring
	.section ".text"
	.align   4

flooring:
	save	 %sp, -96, %sp

	ld	 [%i0], %f0
	fstoi	 %f0, %f1
	st	 %f1, [%i0]

	ba	 done
	nop

overflow:
	mov	 0, %i0

	ret
	restore

done:
	ret
	restore
