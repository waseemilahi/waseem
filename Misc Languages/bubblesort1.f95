/* Bubble Sort In Fortran By Waseem Ilahi
/* This program takes an array of 15 integers and sorts 
/* it using bubble sort and prints out the sorted array.

Program BubbleSort

parameter(MAX=15)

integer A(MAX)

  n=15
  A = 0

  print *,' Please Enter The Integers for sorting: '
  do 5 I=1,15

    read (*,*) A(I)

 5 continue

  print *,' '
  print *,' Initial Array:'
  print *,' '
  write(*,10) (A(i),i=1,n)
  print *,' '

  call Bubble(A,n)

  print *,' Sorted Array:'
  print *,' '
  write(*,10) (A(i),i=1,n)
  print *,' '
  print *,' '
  stop
  
10 format(15I5)

END

/*return p,q in ascending order
Subroutine Order(p,q)
integer p,q,temp
  if (p>q) then
    temp=p
    p=q
    q=temp
  end if
  return
end

/*Buuble sorting of integer array A
Subroutine Bubble(A, n)
integer A(1:n)
  do i=1, n
    do j=n, i+1, -1
      call Order(A(j-1), A(j))
    end do
  end do
  return
end