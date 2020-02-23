PROGRAM ExampleList

	IMPLICIT NONE

    integer :: i ,loopStart, factorial = 1, loopEnd ,sum=0 , maxFactorial = 1
	REAL    :: a,b,c	

	READ(*,*) loopStart,loopEnd 
	IF(loopStart >= loopEnd)then
    	i = loopEnd
        loopEnd = loopStart
        loopstart = i
    else
    end if
    
    DO i = loopStart , loopEnd , 1
      sum = sum + i
    END DO
	WRITE(*,*) sum

 

    do i=1, 5, 1
      factorial = factorial*i
    end do
    write(*,*) i-1, '! = ' , factorial
    
	factorial = 1
	read(*,*) maxFactorial
    do i=1, maxFactorial , 1
      factorial = factorial*i
    end do
    write(*,*) i-1, '! = ' , factorial

!///////////////////////////////////////////////////////////////////////////////////////////
	
	READ(*,*) a,b,c
	if(0 > b**2- 4*a*c) THEN
      WRITE(*,*) 'heogn'
    else if( 0 == b**2-4*a*c) THEN
      WRITE(*,*) (-b/(2*a*c))
	else
      WRITE(*,*) -b-sqrt(b**2-4*a*c)/(2*a*c), -b+sqrt(b**2-4*a*c)/(2*a*c)
    end if
	
	
	
	
	
	
    

END PROGRAM ExampleList