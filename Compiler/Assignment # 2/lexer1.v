#############################################################################
#                         A C A D E M I C   C O P Y
# 
# This file was produced by an ACADEMIC COPY of Parser Generator. It is for
# use in non-commercial software only. An ACADEMIC COPY of Parser Generator
# can only be used by a student, or a member of an academic community. If
# however you want to use Parser Generator for commercial purposes then you
# will need to purchase a license. For more information see the online help or
# go to the Bumble-Bee Software homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# lexer1.v
# Lex verbose file generated from lexer1.l.
# 
# Date: 06/06/05
# Time: 21:44:43
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  [ \t]+

    2  [A-Za-z]([A-Za-z]|[0-9])*

    3  \=

    4  \+

    5  \-

    6  \-\=

    7  \+\=

    8  ;

    9  [0]|[1-9][0-9]*

   10  [0]|[1-9][0-9]*\.[0]|[1-9][0-9]*

   11  .


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x00 - 0x08 (9)    goto 3
	0x09               goto 4
	0x0b - 0x1f (21)   goto 3
	0x20               goto 4
	0x21 - 0x2a (10)   goto 3
	0x2b               goto 5
	0x2c               goto 3
	0x2d               goto 6
	0x2e - 0x2f (2)    goto 3
	0x30               goto 7
	0x31 - 0x39 (9)    goto 8
	0x3a               goto 3
	0x3b               goto 9
	0x3c               goto 3
	0x3d               goto 10
	0x3e - 0x40 (3)    goto 3
	0x41 - 0x5a (26)   goto 11
	0x5b - 0x60 (6)    goto 3
	0x61 - 0x7a (26)   goto 11
	0x7b - 0xff (133)  goto 3


state 2
	^INITIAL

	0x00 - 0x08 (9)    goto 3
	0x09               goto 4
	0x0b - 0x1f (21)   goto 3
	0x20               goto 4
	0x21 - 0x2a (10)   goto 3
	0x2b               goto 5
	0x2c               goto 3
	0x2d               goto 6
	0x2e - 0x2f (2)    goto 3
	0x30               goto 7
	0x31 - 0x39 (9)    goto 8
	0x3a               goto 3
	0x3b               goto 9
	0x3c               goto 3
	0x3d               goto 10
	0x3e - 0x40 (3)    goto 3
	0x41 - 0x5a (26)   goto 11
	0x5b - 0x60 (6)    goto 3
	0x61 - 0x7a (26)   goto 11
	0x7b - 0xff (133)  goto 3


state 3
	match 11


state 4
	0x09               goto 4
	0x20               goto 4

	match 1


state 5
	0x3d               goto 12

	match 4


state 6
	0x3d               goto 13

	match 5


state 7
	match 9


state 8
	0x2e               goto 14
	0x30 - 0x39 (10)   goto 8

	match 9


state 9
	match 8


state 10
	match 3


state 11
	0x30 - 0x39 (10)   goto 11
	0x41 - 0x5a (26)   goto 11
	0x61 - 0x7a (26)   goto 11

	match 2


state 12
	match 7


state 13
	match 6


state 14
	0x30               goto 15


state 15
	match 10


#############################################################################
# Summary
#############################################################################

1 start state(s)
11 expression(s), 15 state(s)


#############################################################################
# End of File
#############################################################################
