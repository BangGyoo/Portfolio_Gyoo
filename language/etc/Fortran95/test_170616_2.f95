program Test_170616_2

	IMPLICIT NONE
    REAL, DIMENSION(3,3) :: M = RESHAPE ((/9,2,5,5,3,4,2,8,3/),(/3,3/))
    REAL, DIMENSION(3,3) :: S,A
    INTEGER :: i,j

	call read_matrix(m)
    CALL decomposition(m,s,a)
    call write_matrix(m,s,a,i,j)
    write(*,4) transpose(m)
4	format(3F3.0)

    
end program Test_170616_2

    subroutine decomposition(m,s,a)
  		REAL, DIMENSION(3,3) :: M  
        REAL, DIMENSION(3,3) :: S,A      
    	s = 0.5*(m + transpose(m) )
        a = 0.5*(m - transpose(m) )
    end subroutine decomposition
    subroutine write_matrix(m,s,a,i,j)	
    		REAL, DIMENSION(3,3) :: M 
    		REAL, DIMENSION(3,3) :: S,A
   			INTEGER :: i,j
		    write(6,9) ( (M(i,j), j=1,3), (s(i,j), j=1,3), (a(i,j), j=1,3), i=1,3)
		9	format(3F5.1, 5X, 3F5.1, 5X, 3F5.1) ! 5 x means a vacuum.
	end subroutine write_matrix

    subroutine read_matrix(m)
        REAL, DIMENSION(3,3) :: M
		write(*,*) 'enter a matrix (3x3)'
        read(*,*) m
    end subroutine read_matrix