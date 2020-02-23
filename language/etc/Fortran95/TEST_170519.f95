PROGRAM TEST_170519

	IMPLICIT NONE
		
	integer, dimension(5,5) :: a = 0
    integer :: i,j
	write(6,5) ((a(i,j),j=1,5), i=1,5); write(*,*) ' '
    a(1, 1:5) = 1

    write(6,5) ((a(i,j),j=1,5),i=1,5)
5   format(5i3)
    
END PROGRAM TEST_170519