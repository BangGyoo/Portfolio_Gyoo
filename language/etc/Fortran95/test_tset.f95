PROGRAM test_test

	IMPLICIT NONE
    INTEGER, DIMENSION(10) :: a = reshape((/1,2,3,4,5,6,7,8,9,10/),(/10/))
    integer :: i , temp
	
    WRITE(6,10) (A(I),I=1,10)
10  FORMAT(10I3)


	temp = a(10)
	do i=9,1,-1
    	a(i+1) = a(i)
    end do
    a(1) = temp
    WRITE(6,10) (A(I),I=1,10)

    
	temp = a(1)
	do i=1,9,1
    	a(i) = a(i+1)
    end do
    a(10) = temp
    WRITE(6,10) (A(I),I=1,10)

    do i=1,5,1
      temp = a(i)
      a(i) = a(10-i+1)
      a(10-i+1) = temp
    end do
    WRITE(6,10) (A(I),I=1,10)
   


end program test_test