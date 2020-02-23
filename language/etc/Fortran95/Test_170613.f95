PROGRAM Test_170613

	IMPLICIT NONE

    INTEGER, DIMENSION(3,3) :: m = RESHAPE( (/1,0,1, 0,1,0, 0,0,1/) , (/3,3/) )
    INTEGER :: i , j, MAX_SIZE = 3 
    logical :: Identity1,Upper1,lower1,Symmetric1

    WRITE(6,3) ((m(i,j),j=1,3),i=1,3)
3	format(3I5)

	write(*,*) '---------------------'
	write(*,*) 'identity :', identity1(M,MAX_SIZE)
    write(*,*) 'Upper    :', upper1(M,MAX_SIZE)
    write(*,*) 'lower    :', lower1(M,MAX_SIZE)
!    write(*,*) 'Diagonal :', Diagonal(M,MAX_SIZE)
    write(*,*) 'Symmetric:', Symmetric1(M,MAX_SIZE)
    
    CONTAINS
    LOGICAL FUNCTION Identity()	result(ox)
    	IMPLICIT NONE
        INTEGER :: i,j
		
		ox = .true.
        outer: DO i=1,MAX_SIZE
        DO j=1,MAX_SIZE
          IF(I==J .AND. m(i,j)/=1) then
            ox = .false.
            EXIT outer
          else IF(I/=J .AND. m(i,j)/=0) then
            ox = .false.
            EXIT outer
          end if
		
        end do
        end do outer
    END FUNCTION Identity
        
    LOGICAL FUNCTION Upper()	result(ox)
    	IMPLICIT NONE
        INTEGER :: i,j
		
		ox = .true.
        outer: DO i=2,MAX_SIZE
        DO j=1,i-1
          IF(I==J .AND. m(i,j)/=1) then
            ox = .false.
            EXIT outer
          else IF(I/=J .AND. m(i,j)/=0) then
            ox = .false.
            EXIT outer
          end if
		
        end do
        end do outer	
    END FUNCTION Upper

    LOGICAL FUNCTION Lower()	result(ox)
    	IMPLICIT NONE
        INTEGER :: i,j =1
		
		ox = .true.
        outer: DO i=1,MAX_SIZE-1 
        DO j=2,MAX_SIZE
          IF(I==J .AND. m(i,j)/=1) then
            ox = .false.
            EXIT outer
          else IF(I/=J .AND. m(i,j)/=0) then
            ox = .false.
            EXIT outer
          end if
		
        end do
        end do outer	
    END FUNCTION Lower

!    LOGICAL FUNCTION Diagonal()	result(ox)
!    	IMPLICIT NONE
!        INTEGER :: i=1,j =1
    
!        ox = .false.
!		if( (Lower() == .TRUE. ) .AND. (Upper() == .TRUE. ) ) ox = .TRUE.
	
!    END FUNCTION Diagonal

    LOGICAL FUNCTION Symmetric()	result(ox)
    	IMPLICIT NONE
        INTEGER :: i,j =1
		
		ox = .true.
        outer: DO i=1,MAX_SIZE
        DO j=i,MAX_SIZE
          IF(m(i,j) /= m(j,i)) then
            ox = .false.
            exit outer
          end if
		end do
        end do outer	
    END FUNCTION Symmetric

    

END PROGRAM Test_170613

    LOGICAL FUNCTION Identity1(m,MAX_SIZE)	result(ox)
    	IMPLICIT NONE
        INTEGER :: i,j
		
		ox = .true.
        outer: DO i=1,MAX_SIZE
        DO j=1,MAX_SIZE
          IF(I==J .AND. m(i,j)/=1) then
            ox = .false.
            EXIT outer
          else IF(I/=J .AND. m(i,j)/=0) then
            ox = .false.
            EXIT outer
          end if
		
        end do
        end do outer
     end Function Identity1

     LOGICAL FUNCTION Upper1(m,MAX_SIZE)	result(ox)  
    	IMPLICIT NONE
        INTEGER :: i,j
		
		ox = .true.
        outer: DO i=2,MAX_SIZE
        DO j=1,i-1
          IF(I==J .AND. m(i,j)/=1) then
            ox = .false.
            EXIT outer
          else IF(I/=J .AND. m(i,j)/=0) then
            ox = .false.
            EXIT outer
          end if
		
        end do
        end do outer	
    END FUNCTION Upper1

    LOGICAL FUNCTION Lower1(M,MAX_SIZE) result(ox)
    	IMPLICIT NONE
        INTEGER :: i,j =1
		
		ox = .true.
        outer: DO i=1,MAX_SIZE-1 
        DO j=2,MAX_SIZE
          IF(I==J .AND. m(i,j)/=1) then
            ox = .false.
            EXIT outer
          else IF(I/=J .AND. m(i,j)/=0) then
            ox = .false.
            EXIT outer
          end if
		
        end do
        end do outer	
    END FUNCTION Lower1

    
!    LOGICAL FUNCTION Diagonal1(m,MAX_SIZE)	result(ox)
!    	IMPLICIT NONE
!        INTEGER :: i=1,j =1
    
!        ox = .false.
!		if( (Lower() == .TRUE. ) .AND. (Upper() == .TRUE. ) ) ox = .TRUE.
	
!    END FUNCTION Diagonal1

        LOGICAL FUNCTION Symmetric1(m,MAX_SIZE)	result(ox)
    	IMPLICIT NONE
        INTEGER :: i,j =1
		
		ox = .true.
        outer: DO i=1,MAX_SIZE
        DO j=i,MAX_SIZE
          IF(m(i,j) /= m(j,i)) then
            ox = .false.
            exit outer
          end if
		end do
        end do outer	
    END FUNCTION Symmetric1
