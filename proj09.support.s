/***********************************************************************/
/*  Meryl Mabin                                                        */
/*  Project #9                                                         */
/*  Support Module 						       */
/***********************************************************************/



/***********************************************************************/
/*  Function:  search                                                  */
/*                                                                     */
/*  Purpose:  locate and return a pointer to a student, if the         */
/*    student is present in the table.                                 */
/*                                                                     */
/*  Arguments:                                                         */
/*    pointer to table of students                                     */
/*    ID number of student to be located                   	       */
/*    pointer to pointer to student                                    */
/*                                                                     */
/*  Return value:                                                      */
/*    1 (true) if student located, 0 (false) otherwise                 */
/***********************************************************************/

	.global	 search
	.section ".text"
	.align	 4
search:
	save	 %sp, -96, %sp

	ld	 [%i0+8], %l7		! pointer to array of students
	lduh	 [%i0+2], %l6		! number of students

	mov	 1, %l4
	mov	 0, %i0

loop1:
	ld	 [%l7], %l5		! student ID
if1:
	cmp	 %l4, %l6		! cmp counter to #students
	bg	 endloop1
	nop

	cmp	 %i1, %l5		! cmp ID to the one we're looking for
	ble	 then1
	nop

	ba	 endif1
	nop
then1:
	cmp	 %l5, %i1
	bne	 endloop1
	nop

	mov	 1, %i0

	ba	 endloop1
	nop
endif1:
	add	 %l7, 48, %l7		! add 48 to address
	inc	 %l4
	ba	 loop1
	nop
endloop1:
	st	 %l7, [%i2]
	ret
	restore


/***********************************************************************/
/*  Function:  delete                                                  */
/*                                                                     */
/*  Purpose:  delete a student from the table, if the                  */
/*    student is present in the table.                                 */
/*                                                                     */
/*  Arguments:                                                         */
/*    pointer to table of students                                     */
/*    identification number of student to be deleted                   */
/*                                                                     */
/*  Return value:                                                      */
/*    1 (true) if student deleted, 0 (false) otherwise                 */
/***********************************************************************/

	.global	 delete
	.section ".text"
	.align   4
delete:
	save	 %sp, -96, %sp

	/**************************************************
	  Make sure deletion student is in the table
	**************************************************/
	mov	 %i0, %o0		! pointer to table
	mov	 %i1, %o1		! student ID
	set	 finder, %l7
	mov	 %l7, %o2		! pointer to pointer

	call	 search			! call search
	nop

	mov	 %i0, %l3
	mov	 0, %i0
if2:
	cmp	 %o0, 1			! check if search worked
	bne	 endif2
	nop
then2:
	/**************************************************
	  Move memory to overwrite deletion student's data
	**************************************************/
	ld	 [%l7], %o0		! beginning of the guy
	add	 %o0, 48, %o1		! the end of the guy

	lduh	 [%l3+2], %l5
	mov	 %l5, %l2
	smul	 %l5, 48, %l5		! all students' bytes
	ld	 [%l3+8], %l4		! first student's address
	add	 %l5, %l4, %l5		! the end of the array of students
	sub	 %l5, %o1, %l5		! subtract guy end from array end
	mov	 %l5, %o2
	call	 memmove
	nop

	dec	 %l2
	stuh	 %l2, [%l3+2]		! decrease # of students

	mov	 1, %i0
endif2:
	ret
	restore


	.section ".data"
	.align	 4
finder:
	.word	 30

/***********************************************************************/
/*  Function:  insert                                                  */
/*                                                                     */
/*  Purpose:  insert a student into the table, as long                 */
/*    as there is room in the table and the student is not             */
/*    already present in the table.                                    */
/*                                                                     */
/*  Arguments:                                                         */
/*    pointer to table of students                                     */
/*    identification number of student to be inserted                  */
/*    pointer to name of student                                       */
/*    points on Exam #1                                                */
/*    points on Exam #2                                                */
/*    points on homework                                               */
/*                                                                     */
/*  Return value:                                                      */
/*    1 (true) if student inserted, 0 (false) otherwise                */
/***********************************************************************/

	.global	 insert
	.section ".text"
	.align	 4

insert:
	save	 %sp, -96, %sp

	/**************************************************
	  Make sure new student isn't already in the table
	**************************************************/
	mov	 %i0, %o0		! pointer to table
	mov	 %i0, %l6
	mov	 %i1, %o1		! student ID
	set	 finder2, %l7
	mov	 %l7, %o2		! pointer to pointer

	call	 search			! call search
	nop

	mov	 %i0, %l3
	mov	 0, %i0
if3:
	cmp	 %o0, 1			! check if search worked
	be	 endif3			! if found, don't insert
	nop
	lduh	 [%l3+2], %l5		! load count
	lduh	 [%l3], %o3		! load capacity
	cmp	 %l5, %o3		! check equality: count and capacity
	be	 endif3			! if equal, table is already full
	nop
then3:
	/**************************************************
	  Move memory down to make room for new student
	**************************************************/
	ld	 [%l7], %l0		! student ptr to guy beginning
	mov	 %l0, %o1

	add	 %o1, 48, %o0		! the end of the guy

	mov	 %l5, %l2		! copy count into %l2

	smul	 %l5, 48, %l5		! all students' bytes
	ld	 [%l3+8], %l4		! first student's address
	add	 %l5, %l4, %l5		! the end of the array of students
	sub	 %l5, %o1, %l5		! subtract guy start from array end
	mov	 %l5, %o2
	call	 memmove
	nop

	/**************************************************
	  Increase number of students in table
	**************************************************/
	inc	 %l2
	stuh	 %l2, [%l3+2]
	mov	 1, %i0


	/**************************************************
	  Store new student's data in newly opened space
	**************************************************/
	st	 %i1, [%l0]		! store ID number
	stuh	 %i3, [%l0+40]		! store exam1
	stuh	 %i4, [%l0+42]		! store exam2
	stuh	 %i5, [%l0+44]		! store hw

	add	 %i3, %i4, %l1
	add	 %l1, %i5, %l1		! calculate total points

	st	 %l1, [%l0+36]		! store total points

	ld	 [%l0+36], %f22
	fitos	 %f22, %f22		! convert total pts to float
	ld	 [%l6+4], %f24
	fitos	 %f24, %f24		! convert max pts to float

	fdivs	 %f22, %f24, %f22	! calculate average
	st	 %f22, [%l0+32]		! store average

	mov	 %i2, %o1
	add	 %l0, 4, %o5
	mov	 %o5, %o0
	mov	 25, %o2
	call	 memmove
	nop


endif3:
	ret
	restore

	.section ".data"
	.align	 4
finder2:
	.word	 30
