
/******************************************************************************
  Meryl Mabin
  Project #7 -- SPARC Assembly Language
******************************************************************************/

        .global  main

        .section ".text"
        .align   4
main:
        save     %sp, -96, %sp

        clr      %r16             ! Initialize total character count
	clr	 %r17		  ! Initialize control character count
	clr 	 %r18		  ! Initialize printable character count
	clr	 %r19		  ! Initialize newline character count
	clr	 %r20		  ! Initialize whitespace character count
	clr	 %r21		  ! Initialize letter count
	clr	 %r22		  ! Initialize octal digit count
	clr	 %r23		  ! Initialize decimal digit count
	clr	 %r24		  ! Initialize hexadecimal digit count
loop:
        call     getchar          ! Read one character (returned in %r8)
        nop

        cmp      %r8, -1          ! Compare return value to EOF
        be       endloop          ! If EOF found, exit loop
	nop

	call	 putchar
        nop

if1:
	cmp	 %r8, 0x00	  ! Compare character to 0x00
	blt	 endif1
	nop
	cmp	 %r8, 0x1F	  ! Compare character to 0x1F
	bgt	 endif1
	nop
then1:
	inc	 %r17		  ! Increment control character count
	nop
endif1:

if2:
	cmp	 %r8, 0x7F	  ! Compare character to 0x7F
	bne	 endif2
	nop
then2:
	inc	 %r17		  ! Increment control character count
	nop
endif2:

if3:
	cmp	 %r8, 0x20	  ! Compare character to 0x20
	blt	 endif3
	nop
	cmp	 %r8, 0x7E	  ! Compare character to 0x7E
	bgt	 endif3
	nop
then3:
	inc	 %r18		  ! Increment printable character count
	nop
endif3:

if4:
	cmp	 %r8, 0x0A	  ! Compare character to 0x0A
	bne	 endif4
	nop
then4:
	inc	 %r19		  ! Increment newline character count
endif4:

if5:
	cmp	 %r8, 0x09	  ! Compare character to 0x09
	bne	 endif5
	nop
then5:
	inc	 %r20		  ! Increment whitespace character count
endif5:

if6:
	cmp	 %r8, 0x0A	  ! Compare character to 0x0A
	bne	 endif6
	nop
then6:
	inc	 %r20		  ! Increment whitespace character count
endif6:

if7:
	cmp	 %r8, 0x20	  ! Compare character to 0x20
	bne	 endif7
	nop
then7:
	inc	 %r20		  ! Increment whitespace character count
endif7:

if8:
	cmp	 %r8, 0x41	  ! Compare character to 0x41
	blt	 endif8
	nop
	cmp	 %r8, 0x5A	  ! Compare character to 0x5A
	bgt	 endif8
	nop
then8:
	inc	 %r21		  ! Increment letter count
endif8:

if9:
	cmp	 %r8, 0x61	  ! Compare character to 0x61
	blt	 endif9
	nop
	cmp	 %r8, 0x7A	  ! Compare character to 0x7A
	bgt	 endif9
	nop
then9:
	inc	 %r21		  ! Increment letter count
endif9:


if10:
	cmp	 %r8, 0x30	  ! Compare character to 0x30
	blt	 endif10
	nop
	cmp	 %r8, 0x37	  ! Compare character to 0x37
	bgt	 endif10
	nop
then10:
	inc	 %r22		  ! Increment octal digit count
endif10:

if11:
	cmp	 %r8, 0x30	  ! Compare character to 0x30
	blt	 endif11
	nop
	cmp	 %r8, 0x39	  ! Compare character to 0x39
	bgt	 endif11
	nop
then11:
	inc	 %r23 		  ! Increment decimal digit count
endif11:

if12:
	cmp	 %r8, 0x30	  ! Compare character to 0x30
	blt	 endif12
	nop
	cmp	 %r8, 0x39	  ! Compare character to 0x39
	bgt	 endif12
	nop
then12:
	inc	 %r24		  ! Increment hexadecimal digit count
endif12:

if13:
	cmp	 %r8, 0x41	  ! Compare character to 0x41
	blt	 endif13
	nop
	cmp	 %r8, 0x46	  ! Compare character to 0x46
	bgt	 endif13
	nop
then13:
	inc	 %r24		  ! Increment hexadecimal digit count
endif13:

if14:
	cmp	 %r8, 0x61	  ! Compare character to 0x61
	blt	 endif14
	nop
	cmp	 %r8, 0x66	  ! Compare character to 0x66
	bgt	 endif14
	nop
then14:
	inc	 %r24
endif14:

        inc      %r16             ! Increment total character count

        ba       loop             ! Jump to top of loop
        nop
endloop:
        set      fmt1, %r8        ! First arg  -- address of format string
        mov      %r16, %r9        ! Second arg -- character count
	call	 printf		  ! Print total number of characters
	nop

	set	 fmt2, %r8
	mov	 %r17, %r9
        call     printf           ! Print number of control characters
        nop

	set	 fmt3, %r8
	mov	 %r18, %r9
	call	 printf		  ! Print number of printable characters
	nop

	set	 fmt4, %r8
	mov	 %r19, %r9
	call	 printf		  ! Print number of newline characters
	nop

	set	 fmt5, %r8
	mov	 %r20, %r9
	call	 printf		  ! Print number of whitespace characters
	nop

	set	 fmt6, %r8
	mov	 %r21, %r9
	call	 printf		  ! Print number of letters
	nop

	set	 fmt7, %r8
	mov	 %r22, %r9
	call	 printf		  ! Print number of decimal digits
	nop

	set	 fmt8, %r8
	mov	 %r23, %r9
	call	 printf		  ! Print number of octal digits
	nop

	set	 fmt9, %r8
	mov	 %r24, %r9
	call	 printf		  ! Print number of decimal digits
	nop

        ret
        restore
fmt1:
        .asciz   "\nTotal Characters = %d\n"
        .align   4
fmt2:
	.asciz	 "\nControl Characters = %d\n"
	.align   4
fmt3:
	.asciz   "\nPrintable Characters = %d\n"
	.align   4
fmt4:
	.asciz	 "\nNewline Characters = %d\n"
	.align   4
fmt5:
	.asciz	 "\nWhitespace Characters = %d\n"
	.align   4
fmt6:
	.asciz	 "\nLetters = %d\n"
	.align   4
fmt7:
	.asciz	 "\nOctal Digits = %d\n"
	.align   4
fmt8:
	.asciz   "\nDecimal Digits = %d\n"
	.align   4
fmt9:
	.asciz	 "\nHexadecimal Digits = %d\n"
	.align   4
