PROGRAM test_170602

!	IMPLICIT NONE
    INTEGER(KIND = 4) :: factorial, i , n 
    INTEGER(KIND = 4) :: OuterFunction

    WRITE(*,*) 'Enter n of n!'
    read(*,*) n
    call InnerSubroutine();				 write(*,10) n, '!=' , factorial
    call OuterSubroutine(n,factorial);	 write(*,10) n, '!=' , factorial
    write(*,10) n, '!=', InnerFunction(); write(*,10) n, '!=', OuterFunction(n,10)
10	FORMAT(I3,A,I15)

    contains
    subroutine InnerSubroutine()
    factorial = 1

    do i=1,n
      factorial = factorial * i
    end do
    end subroutine InnerSubroutine
    
    INTEGER(KIND = 4) function InnerFunction() result(factorial)
    factorial = 1

    do i=1,n
      factorial = factorial * i
    end do
    end function InnerFunction
        

END PROGRAM test_170602


subroutine OuterSubroutine(n, factorial)
	integer(kind = 4):: i, factorial , n 
	factorial = 1
    DO i=1,n
      factorial = factorial*i
    end do
end subroutine OuterSubroutine

INTEGER(KIND = 4) function OuterFunction(n,factorial) result(factorial)
	integer(kind = 4) :: factorial ,n,i
	factorial = 1

    do i=1,n
      factorial = factorial * i
    end do
    
end function OuterFunction