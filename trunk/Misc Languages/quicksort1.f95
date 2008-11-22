program QuickSort

	implicit integer ( a - z )

	parameter ( Mnodes = 50000, Marcs = 500000, mMarcs = -Marcs )

	common/inputnet/tail(Marcs), head(Marcs), cost(Marcs), n, m
	common/outputnet/up(Mnodes), down(Mnodes)
	common/stack/stackL(mMarcs:Marcs), stackR(mMarcs:Marcs)


	s = 1
	stackR(1) = m
	stackL(1) = 1
5	L = stackL(s)
	R = stackR(s)
	s = s - 1
10	i = L
	j = R
	half = ( L + R ) / 2
	meio = cost(half)
20	if ( cost(i) .lt. meio ) then
		i = i + 1
		go to 20
	end if
30      if ( cost(j) .gt. meio ) then
		j = j - 1
		go to 30
	end if
	if ( i .le. j ) then
		aux = head(i)
		head(i) = head(j)
		head(j) = aux
		aux = tail(i)
		tail(i) = tail(j)
		tail(j) = aux
		aux = cost(i)
		cost(i) = cost(j)
		cost(j) = aux
		i = i + 1
		j = j - 1
	end if
	if ( i .le. j ) go to 20
	if ( i .lt. R ) then
		s = s + 1
		stackL(s) = i
		stackR(s) = R
	end if
	R = j
	if ( L .lt. R ) go to 10
	if ( s .ne. 0 ) go to 5

    write (*,*) stackR

    stop

	end