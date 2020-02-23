PROGRAM test_170530

	IMPLICIT NONE
    integer :: fact=1 , i
    call fact1(3)
    write(*,10) '3! = ', fact
    call fact2(5,fact)
    write(*,10) '5! = ', fact
    fact=1
    call fact3(7,fact)
    write(*,10) '7! = ', fact
10  format(a,i3)

	contains
    SUBROUTINE fact1(n)
    integer :: n,i
    do i=1, n,1
		fact = fact * i
    end do
    end subroutine fact1

END PROGRAM test_170530

SUBROUTINE fact2(n,fact)
	integer :: i
    do i=1, n, 1
		fact = fact * i
    end do
end subroutine fact2

Recursive Subroutine fact3(n,fact)
    if(n==0)	then
      fact = 1
    else
      call fact3(n-1,fact)
      fact = n * fact
    end if
end Subroutine fact3
	
	
