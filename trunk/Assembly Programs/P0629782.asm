
;			Print All 'Three Digit' Prime Numbers
;                 -------------------------------------
;
;								Name:   Waseem K. Ilahi
;								ID  :           0629782
; *********************************************************************
; * The Program was written in Microsoft WordPad,so it will be better *
; * to open it using Microsoft WordPad to keep the formatting intact. *
; * ----------------------------------------------------------------- *
; * This program loops through three digit numbers and prints out     * ; * the ones that are prime. {Range = (100- 999 )}                    *
; *********************************************************************

; Assembler Directive for the program.
; ------------------------------------

			.MODEL 		SMALL		

; Assembler Directive for Stack initiation.
; -----------------------------------------

			.STACK		200h		

; Assembler Directive for the Data Section.
; -----------------------------------------

			.DATA

	; Declare the strings to print name and ID.
	; -----------------------------------------

	name1		DB			' Name: Waseem K. Ilahi',13,10,'$'
	id		DB			  13,10,' ID  : 0629782',13,10,'$'

	; The Seperator to decorate the Screen for better understanding.
	; --------------------------------------------------------------

	seperator1	DB			' ------------------------------$'
	seperator2	DB			'-----------------------------$'

	; Line feed and the return key to enter a line in text.
	; -----------------------------------------------------

	newline1	DB			13,10,'$'		; To add 1 line.
	newline2	DB			13,10,13,10,'$'	; To add 2 lines.

	; Strings for the explaination of the program.
	; --------------------------------------------

	intro1	DB			' The program loops through THREE$'
	intro2	DB			' DIGIT numbers (100 - 999) $'
	intro3	DB			  13,10,13,10,' and prints out $'
	intro4	DB			' only the ones that are prime.$'

	; Variable to Store the Prime Number. Initialized at 100.
	; -------------------------------------------------------

	A		DW			100
	
	; Variable for the maximum limit for three digit numbers.
	; -------------------------------------------------------

	max		DW			999	; It remains 999 always.
	
	; Flag to indicate the result of modulo.
	; --------------------------------------

	flag		DB			?

	; Three Variables to save three digits.
	; -------------------------------------

	leftmost	DW			?
	middle	DW			?
	rightmost	DW			?

	; The counter gives the total prime numbers in the range.
	; -------------------------------------------------------

	counter	DW			0	; Initialized to zero.

	; How many prime numbers?
	; -----------------------

	final1	DB			' There are $'
	final2	DB			' THREE DIGIT Prime Numbers.$'

	; Announce the end of the program.
	; --------------------------------

	termination DB			' Program Terminated. $'
	terminate	DB			' ------------------- $'

; ---------------------------------------------------------------------

; Assembler Directive for the Code Section.
; -----------------------------------------

			.CODE
		
	; Initialize ds to the segment number in order to access data.
	; ------------------------------------------------------------

			mov	bx,@data	
			mov	ds,bx

; Print out the Student Name and ID.
; ----------------------------------

	; Print out the formatted output using the bios commands for 
	; printing strings.
	; ----------------------------------------------------------

		; Advance one line.

			mov	ah,09d	; bios code for print a string.
			mov	dx,OFFSET newline1	; Advance to next line.
			int	21h			; Invoke BIOS to print.

		; Print out the seperators to format the output.
		; ----------------------------------------------

			mov	ah,09d
			mov	dx,OFFSET seperator1	; String to be printed.
			int 	21h			; Invoke BIOS to print.

			mov	ah,09d
			mov	dx,OFFSET seperator2
			int 	21h			; Invoke BIOS to print.

		; Advance one line.

			mov	ah,09d		; Advance to next line.
			mov	dx,OFFSET newline1
			int	21h			; Invoke BIOS to print.

	; Print your name.
	; ----------------

			mov	ah,09d
			mov	dx,OFFSET name1
			int 	21h			; Invoke BIOS to print.

	; Print your student ID.
	; ----------------------
	
			mov	ah,09d
			mov	dx,OFFSET id
			int	21h			; Invoke BIOS to print.

	; Print out the seperators to format the output.
	; ----------------------------------------------

			mov	ah,09d
			mov	dx,OFFSET seperator1
			int 	21h			; Invoke BIOS to print.

			mov	ah,09d
			mov	dx,OFFSET seperator2
			int 	21h			; Invoke BIOS to print.

		; Advance two lines.

			mov	ah,09d		
			mov	dx,OFFSET newline2
			int	21h			; Invoke BIOS to print.

	
; Printout the purpose of the program using multiple commands.
; ------------------------------------------------------------	

			mov	ah,09d
			mov	dx,OFFSET intro1
			int 	21h			; Invoke BIOS to print.

			mov	ah,09d
			mov	dx,OFFSET intro2
			int 	21h			; Invoke BIOS to print.

			mov	ah,09d
			mov	dx,OFFSET intro3
			int 	21h			; Invoke BIOS to print.
			
			mov	ah,09d
			mov	dx,OFFSET intro4
			int 	21h			; Invoke BIOS to print.

		; Advance two lines.

			mov	ah,09d		
			mov	dx,OFFSET newline2
			int	21h			; Invoke BIOS to print.

		; Print out the seperators to format the output.
		; ----------------------------------------------

			mov	ah,09d
			mov	dx,OFFSET seperator1
			int 	21h			; Invoke BIOS to print.

			mov	ah,09d
			mov	dx,OFFSET seperator2
			int 	21h			; Invoke BIOS to print.

; Calculate the Prime Numbers and Print out the formatted output.
; ---------------------------------------------------------------	
	
	; First loop, sets up the number to test 'A'.
	; -------------------------------------------	

	loop1:	
			sub	dx,dx		; Clear out dx for division.
			mov	ax,A		; ax holds the number to be tested.

			mov 	cx,2d
			div	cx

			INC	ax		; ax = (A/2)+1
			mov	bx,ax		; bx contains the number(A/2)+1.

	; Second loop: test the number.
	; -----------------------------

	loop2:	
			mov	flag,0	; reset the flag: 'A' may be prime.
			sub	dx,dx
			mov	ax,A		; Now again ax holds the number
			div	bx

			cmp	dx,0d
			jne	loop3		; Number is not divisible: continue

			mov	flag,1	; The number is not prime: flag it.
			jmp	loop4		; Skip the next level.

	; We get here only if the number was not divisible.
	; -------------------------------------------------	

	loop3:
			dec 	bx		; bx goes from (A/2)+1 to 2.
			cmp	bx,1
			jg	loop2		; Still some numbers left to check.

	; Break out of the loop2. and check the flag.	
	; -------------------------------------------

	loop4:
			cmp	flag,0
			jne	n_prime		; Number not prime skip ahead

			sub	dx,dx
			mov	ax,counter		; ax represents the counter

			mov	cx,08d	; Divide output in eight columns.
			div	cx
			
			cmp	dx,0
			jne	skip		; don't go to next line yet.
			
		; Advance two lines.

			mov	ah,09d		
			mov	dx,OFFSET newline2
			int	21h			; Invoke BIOS to print.

	; Add a space in the beginning of each line of output.
	; ----------------------------------------------------

			mov	ah,02d
			mov	dl,' '
			int	21h
	
	; Continue with printing out the prime number.
	; --------------------------------------------

	skip:

		; Assign the three digits to three variables to print out.
		; --------------------------------------------------------

			mov	cx,10d			; the divisor

			sub	dx,dx
			mov	ax,A
			div	cx
			mov	rightmost,dx
			add	rightmost,030h		; Convert to ASCII

			sub	dx,dx
			div	cx			
			mov	middle,dx
			add	middle,030h			; Convert to ASCII

			sub	dx,dx
			div	cx
			mov	leftmost,dx
			add	leftmost,030h		; Convert to ASCII

	; Print out the current Prime Number.
	; -----------------------------------
						
			mov	ah,02d
			mov	dx,leftmost 
			int	21h			; Invoke BIOS to print.	

			mov	ah,02d
			mov	dx,middle 
			int	21h			; Invoke BIOS to print.

			mov	ah,02d
			mov	dx,rightmost 
			int	21h			; Invoke BIOS to print.

		; Print a Tab between numbers on the same line.
		; ---------------------------------------------
		
			mov	ah,02d
			mov	dl,09d
			int	21h
		
		; Indicated that this many numbers have been found.
		; -------------------------------------------------

			add	counter,1		; Increment the counter.

	n_prime:
			INC 	A			; Get the next number.
	
			mov	ax,max	; ax now holds the max limit.
			
			cmp 	A,ax		; Have we reached the limit.
			jg	finish	; Reached the limit: break out

			jmp	loop1		; Go back to the top.

; Found & Printed all the prime numbers: now print out the counter.
; -----------------------------------------------------------------

	finish:			
		
		; Advance two lines.

			mov	ah,09d		
			mov	dx,OFFSET newline2
			int	21h			; Invoke BIOS to print.

		; Print out the seperators to format the output.
		; ----------------------------------------------

			mov	ah,09d
			mov	dx,OFFSET seperator1	; String to be printed.
			int 	21h			; Invoke BIOS to print.

			mov	ah,09d
			mov	dx,OFFSET seperator2
			int 	21h			; Invoke BIOS to print.

		; Advance one line.

			mov	ah,09d		; Advance to next line.
			mov	dx,OFFSET newline1
			int	21h			; Invoke BIOS to print.
			
			mov	ah,09d
			mov	dx,OFFSET final1	; String to be printed.
			int 	21h			; Invoke BIOS to print.

		; Setup the counter to be printed out.
		; ------------------------------------

			mov	ax,counter
			mov	cx,10d

			sub	dx,dx			
			div	cx
			mov	rightmost,dx
			add	rightmost,030h		; Convert to ASCII

			sub	dx,dx
			div	cx			
			mov	middle,dx
			add	middle,030h			; Convert to ASCII

			sub	dx,dx
			div	cx
			mov	leftmost,dx
			add	leftmost,030h		; Convert to ASCII
		
		; Print out the three digits representing the counter.
		; ----------------------------------------------------
				
			mov	ah,02d
			mov	dx,leftmost 
			int	21h			; Invoke BIOS to print.	

			mov	ah,02d
			mov	dx,middle 
			int	21h			; Invoke BIOS to print.

			mov	ah,02d
			mov	dx,rightmost 
			int	21h			; Invoke BIOS to print.

			mov	ah,09d
			mov	dx,OFFSET final2	; String to be printed.
			int 	21h			; Invoke BIOS to print.

		; Advance one line.

			mov	ah,09d		; Advance to next line.
			mov	dx,OFFSET newline1
			int	21h			; Invoke BIOS to print.

		; Print out the seperators to format the output.
		; ----------------------------------------------

			mov	ah,09d
			mov	dx,OFFSET seperator1	; String to be printed.
			int 	21h			; Invoke BIOS to print.

			mov	ah,09d
			mov	dx,OFFSET seperator2
			int 	21h			; Invoke BIOS to print.

		; Advance one line.

			mov	ah,09d		; Advance to next line.
			mov	dx,OFFSET newline1
			int	21h			; Invoke BIOS to print.

		; Advance two lines.

			mov	ah,09d		
			mov	dx,OFFSET newline2
			int	21h			; Invoke BIOS to print.	

; Exit Gracefully.
; ----------------

	; End of the Program.
	; -------------------

		; Print Tabs for decoration purposes.
		; ------------------------------------
		
			mov	ah,02d
			mov	dl,09d
			int	21h

			mov	ah,02d
			mov	dl,09d
			int	21h

			mov	ah,02d
			mov	dl,' '
			int	21h

		; multiple interrupts to print space.
		; -----------------------------------

			int	21h		
			int	21h

	; Declare end of the program.
	; ---------------------------

			mov	ah,09d		
			mov	dx,OFFSET termination
			int	21h			; Invoke BIOS to print.

		; Advance one line.

			mov	ah,09d		
			mov	dx,OFFSET newline1
			int	21h			; Invoke BIOS to print.	

		; Print Tabs for decoration purposes.
		; ------------------------------------
		
			mov	ah,02d
			mov	dl,09d
			int	21h

			mov	ah,02d
			mov	dl,09d
			int	21h

			mov	ah,02d
			mov	dl,' '
			int	21h

		; multiple interrupts to print space.
		; -----------------------------------

			int	21h		
			int	21h
			
	; Decoration string for end of program.
	; -------------------------------------

			mov	ah,09d		
			mov	dx,OFFSET terminate
			int	21h			; Invoke BIOS to print

		; Advance two lines.

			mov	ah,09d		
			mov	dx,OFFSET newline2
			int	21h			; Invoke BIOS to print.

	; Exit the Program and give the control to OS.
	; --------------------------------------------

			mov	ah,04Ch	; BIOS code to EXIT.
			int 	21h		; Invoke BIOS to EXIT.

			END			; END the program.

