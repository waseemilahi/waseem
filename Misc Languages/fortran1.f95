/* This program takes an array of 15 integers and sorts 
/* it using bubble sort and prints out the sorted array.

program BubbleSort

      integer NUMS,N
            
      DIMENSION NUMS(15)
      
      N = 1      

      write (*,*) 'Enter 15 integers to be sorted:'
      write (*,*) ' '

/* Read in the integers.
      
 10   READ 15, IN
 
 15   FORMAT(I3)
 
      IF(IN + 1) 20,40,20
 20   NUMS(N) = IN
 
      IF(N - 15) 25,70,70
 25   N = N + 1
      GOTO 10

 40   N = N - 1
 
 70   ISCAN = 1
 
      IOK = 1
      ISTOP = N
      ISTART=1
      
      IF(ISTART - ISTOP) 50, 110, 110
        
 50   IF(NUMS(ISCAN) - NUMS(ISCAN+1)) 90,90,60

 60   J = NUMS(ISCAN)
 
      NUMS(ISCAN) = NUMS(ISCAN+1)
      NUMS(ISCAN+1) = J
      IOK = 0

 90   IF(ISCAN - (ISTOP - 1)) 80,100,100

 80   ISCAN = ISCAN + 1
      GOTO 50
      
 100  IF(IOK) 105,105,110
 105  ISTOP = ISTOP - 1
      GOTO 70

/* Print out the sorted array.

 110  write (*,*) ' '
 	  write (*,*) 'The Sorted list is:'
      write (*,*) ' '
      
      DO 120 I=1, N
 120  PRINT 130, NUMS(I)
 130  FORMAT(I10)

      STOP
      END