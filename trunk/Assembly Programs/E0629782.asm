
;			  H.C.F. Using EUCLID's ALGORITHM
;                   -------------------------------

;								Name:   Waseem K. Ilahi
;								ID  :           0629782
; *********************************************************************
; *The Program was written in Microsoft WordPad, so it will be better *
; *to open it using Microsoft WordPad to keep the formatting intact.  *
; *-------------------------------------------------------------------*
; *This program uses the EUCLID's Algorithm to find the Highest Common*
; *Factor(HCF) of Two non-negative single digit integers.Fisrt it asks*
; *for user input, then it finds the H.C.F. and prints out the answer.*
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

	name1		DB			' Name: Waseem K. Ilahi',13,10,'$'
	id		DB			  13,10,' ID  : 0629782',13,10,'$'

	; Explain the programs using multiple strings.

	intro1	DB			' The Program takes two single$'
	intro2	DB			' digit non-negative integers as$' 
	intro3	DB			  13,10,13,10,' input and prints$' 
	intro4	DB			' out their H.C.F. using$' 
	intro5	DB			' EUCLID ALGORITHM.$'

	;The Seperator to decorate the Screen for better understanding.

	seperator1	DB			' ------------------------------$'
	seperator2	DB			'-----------------------------$'

	; Strings to ask the user to input the integers.

	prompt1	DB			' Please input first integer : $'
	prompt2	DB			' Please input second integer: $'

	; Strings to print out the answer in one sentence.

	result1	DB			' The highest common factor of $'
	result2	DB			' and $'
	result3	DB			' is $'

	; Line feed and the return key to enter a line in text.

	newline1	DB			13,10,'$'		; To add 1 line.
	newline2	DB			13,10,13,10,'$'	; To add 2 lines.

	; Variables used to represent the two input integers.

	A		DB			?	;Represents the first  input.
	B		DB			?	;Represents the second input.

	; Variables used to keep the original values to be used later.

	C		DB			?	;Represents the first  input.
	D		DB			?	;Represents the second input.

; ---------------------------------------------------------------------

; Assembler Directive for the Code Section.
; -----------------------------------------

			.CODE
		
	; Initialize ds to the segment number in order to access data.

			mov	bx,@data	
			mov	ds,bx

; Print out the Student Name and ID.
; ----------------------------------

	; Print out the formatted output using the bios commands for 
	; printing strings.

			mov	ah,09d	; bios code for print a string.
			mov	dx,OFFSET newline1	; Advance to next line.
			int	21h			; Invoke BIOS to print.

		; Print out the seperators to format the output.

			mov	ah,09d
			mov	dx,OFFSET seperator1	; String to be printed.
			int 	21h			; Invoke BIOS to print.

			mov	ah,09d
			mov	dx,OFFSET seperator2
			int 	21h			; Invoke BIOS to print.

			mov	ah,09d		; Advance to next line.
			mov	dx,OFFSET newline1
			int	21h			; Invoke BIOS to print.

	; Print your name.

			mov	ah,09d
			mov	dx,OFFSET name1
			int 	21h			; Invoke BIOS to print.

	; Print your student ID.
	
			mov	ah,09d
			mov	dx,OFFSET id
			int	21h			; Invoke BIOS to print.

	; Print out the seperators to format the output.

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

			mov	ah,09d
			mov	dx,OFFSET intro5
			int 	21h			; Invoke BIOS to print.

		; Advance to the next line.

			mov	ah,09d		
			mov	dx,OFFSET newline1
			int	21h			; Invoke BIOS to print.

	; Print out the seperators to decorate the output.	

			mov	ah,09d		
			mov	dx,OFFSET seperator1
			int 	21h			; Invoke BIOS to print.

			mov	ah,09d
			mov	dx,OFFSET seperator2
			int 	21h			; Invoke BIOS to print.

		; Advance to the next line.

			mov	ah,09d
			mov	dx,OFFSET newline1
			int	21h			; Invoke BIOS to print.

; Prompt for the first input.	
; ---------------------------

	START1:
			mov	ah,09d		; Advance one line.
			mov	dx,OFFSET newline1
			int	21h			; Invoke BIOS to print.	

			mov	ah,09d		; Ask for the first prompt.
			mov	dx,OFFSET prompt1
			int 	21h			; Invoke BIOS to print.

		; BIOS commands to get character input from the user.
		; Input's ASCII value gets stored in the al register.

			mov	ah,01d	; BIOS code to get input.
			int 	21h		; Invoke BIOS to get input.

			sub 	ah,ah		; Clearing out the 'ah' register.

		; Cheack to see if the value is a digit.
		; If not then go back and ask for the input again
		; Else continue to get the second number.

			cmp	al,'0'	
			jb	START1

			cmp	al,'9'
			ja	START1

		; Store the value so it can be used in printing the answer.

			mov	C,al

		; Turning the value from ASCII code into integer form.
		; Then storing it in the variable(A).

			sub	al,030h			
			mov	A,al

			mov	ah,09d	;Advance to the next line.
			mov	dx,OFFSET newline1
			int	21h			; Invoke BIOS to print.

		; Print out the seperators to format the output.

			mov	ah,09d
			mov	dx,OFFSET seperator1
			int 	21h			; Invoke BIOS to print.
			
			mov	ah,09d
			mov	dx,OFFSET newline1
			int	21h			; Invoke BIOS to print.

; Prompt for the second input.
; ----------------------------

	START2:
			mov	ah,09d		; Move to the next line.
			mov	dx,OFFSET newline1
			int	21h			; Invoke BIOS to print.

			mov	ah,09d		; Ask for the second prompt.
			mov	dx,OFFSET prompt2
			int 	21h			; Invoke BIOS to print.

		; BIOS commands to get character input from the user.
		; Input's ASCII value gets stored in the al register.

			mov	ah,01d	; BIOS code to get input.
			int 	21h		; Invoke BIOS to get input.

			sub 	ah,ah		; Clearing out the 'ah' register.

		; Cheack to see if the value is a digit.
		; If not then go back and ask for the input again
		; Else continue to get the second number.

			cmp	al,'0'
			jb	START2

			cmp	al,'9'
			ja	START2

	; Store the value so it can be used in printing the answer.	
			
			mov	D,al
	
	; Turning the value from ASCII code into integer form.
	; Then storing it in the variable(B).

			sub	al,030h
			mov	B,al

			mov	ah,09d		; Move to the next line.
			mov	dx,OFFSET newline1
			int	21h			; Invoke BIOS to print.	

; HCF of a positive integer and zero is always the positive integer.
; ------------------------------------------------------------------

			sub	ch,ch	; Get rid of the garbage in 'ch' register
			sub	bh,bh ; Get rid of the garbage in 'bh' register

		; Check if first number is zero.
		; If it is not then compare second input.
		; If it is then do the steps after the 'cmp' command.

			cmp	A,0			
			jne	checkb
			
		; Interchange the values in A and B to avoid all the 
		; computation in the steps to come.

			mov	cl,A
			mov	bl,B
			mov	A,bl
			mov	B,cl			

		; Check if B is zero, if it is then go directly to the 
		; printing and skip all the comparisons, because if one of 
		; the numbers is zero then the H.C.F. of the two is the 
		; other number.

	checkb:			
			cmp	B,0
			je	finalstep

; Start computing the H.C.F. using EUCLID's Algorithm.
; ----------------------------------------------------

	; We will make use of the 'cl' register to perform various 
	; operations on the inputs.
	
	; Is A > B?
	; ---------

	firststep:
			sub	ch,ch		; For the cleanest computation.
			mov	cl,A

			cmp	cl,B
			jng	nextstep1	; If not then go to next step.

		; If yes then A = A - B and then go to the next step.
	
			sub	cl,B
			mov	A,cl

	; Is A < B?
	; ---------

	nextstep1:	
			sub	ch,ch
			mov	cl,A

			cmp	cl,B
			jnl	nextstep2	; If not then go to next step.
	
		; If yes then B = B - A and then go to the next step.

			sub	B,cl
			mov	A,cl

	; Is A = B?
	; ---------

	nextstep2:
			sub	ch,ch
			mov	cl,A

			cmp	cl,B
			jne	nextstep3	; If not then go to next step.

		; If yes then we are done and 'A' contains the H.C.F.

			mov	A,cl
			jmp	finalstep

	; If you are here then jump back to the first comparison.

	nextstep3:	
			jmp	firststep

; Print out the result.
; ---------------------

	finalstep:

		; Print out the seperators to decorate the output.

			mov	ah,09d
			mov	dx,OFFSET seperator1
			int 	21h			; Invoke BIOS to print.	

			mov	ah,09d
			mov	dx,OFFSET seperator2
			int 	21h			; Invoke BIOS to print.	

			mov	ah,09d		; Advance two lines.
			mov	dx,OFFSET newline2
			int	21h			; Invoke BIOS to print.	

	; Print out the result inside a sentence.		
	
			mov	ah,09d
			mov	dx,OFFSET result1
			int 	21h			; Invoke BIOS to print.	
	
		; Print the first input entered by user.

			mov	ah,02d
			mov	dl,C	; 'C' contains the ASCII for first input.
			int	21h			; Invoke BIOS to print.	
			
			mov	ah,09d
			mov	dx,OFFSET result2
			int 	21h			; Invoke BIOS to print.	

		; Print the second input entered by user.

			mov	ah,02d
			mov	dl,D	; 'D' contains the ASCII for first input.
			int	21h			; Invoke BIOS to print.	

			mov	ah,09d
			mov	dx,OFFSET result3
			int 	21h			; Invoke BIOS to print.	

		; According to EUCLID's Algorithm 'A' holds the H.C.F.
		; So we need to convert the contents of 'A' from integer to
 		; the characters representing the integer value of 'A'.

			sub	ch,ch	; Delete the garbage.
			mov	cl,A		
			add	cl,030h ; Converting from Integer to ASCII.
			mov	A,cl

	; Print the H.C.F. that is 'A'

			mov	ah,02d
			mov	dl,A
			int	21h			; Invoke BIOS to print.	

			mov	ah,09d		; Advance two lines.
			mov	dx,OFFSET newline2
			int	21h			; Invoke BIOS to print.	

		; Print out the seperators to format the output.

			mov	ah,09d
			mov	dx,OFFSET seperator1
			int 	21h			; Invoke BIOS to print.	

			mov	ah,09d
			mov	dx,OFFSET seperator2
			int 	21h			; Invoke BIOS to print.	

			mov	ah,09d		; Move to the next line.
			mov	dx,OFFSET newline1
			int	21h			; Invoke BIOS to print.	

; Exit Gracefully.
; ----------------

			mov	ah,04Ch	; BIOS code to EXIT.
			int 	21h		; Invoke BIOS to EXIT.

			END			; END the program.

		