PROGRAM MatrixTest

	IMPLICIT NONE

    INTEGER, DIMENSION(3,3) :: variable = RESHAPE((/1,0,3,0,1,0,3,0,1/),(/3,3/))
	INTEGER :: i,j,VAR_MAX_SIZE =3 
    logical :: Outer_Identity

    WRITE(*,*) 'Enter matrix(3,3)'
!    READ(*,*)  ((variable(i,j),j=1,3),i=1,3); write(*,*) ' '
    WRITE(*,3) ((variable(i,j),j=1,3),i=1,3); write(*,*) ' '

    write(*,*) Identity()
	WRITE(*,*) Upper()
    WRITE(*,*) Lower()
    WRITE(*,*) Diagonal()
    write(*,*) XY()
   	call Sub_Identity
    write(*,*) Outer_Identity(variable,VAR_MAX_SIZE)

3	format(3I3)
	
	contains

    subroutine Sub_Identity()
    	logical :: ox = .true.
    	do i=1,VAR_MAX_SIZE,1
        	do j=1,VAR_MAX_SIZE,1
            	IF( i==j .and. variable(i,j) /= 1) then
                	ox = .false.
                end if
            end do
        end do
        write(*,*) ox
    end subroutine
    
    logical function Identity() result(OX)
    	outer : do i=1,VAR_MAX_SIZE,1
        	do j=1,VAR_MAX_SIZE,1
            	if( i==j .and. variable(i,j) /= 1) then
                	OX = .false.
                    exit outer
                else if( i/=j .and. variable(i,j) /=0) then
                  	OX = .false.
                    exit outer
                end if
            end do
	   end do Outer
    end function         

    logical function Upper()   result (OX)
    	do i=2,VAR_MAX_SIZE,1
        	do j=1,i-1,1
            	if(variable(i,j) /= 0) then
                	OX = .FALSE.
                END IF
            END DO
        END DO
    END FUNCTION
    
    logical function Lower() result(OX)
    	outer : do i=1,VAR_MAX_SIZE,1
        	do j=1,VAR_MAX_SIZE,1
            	if( i<j .and. variable(i,j) /= 0) then
                	OX = .false.
                    exit outer
                end if
            end do
	   end do Outer
    end function

    logical function Diagonal() result(OX)
    	outer : do i=1,VAR_MAX_SIZE,1
        	do j=1,VAR_MAX_SIZE,1
            	if( i<j .and. variable(i,j) /= 0) then
                	OX = .false.
                    exit outer
                else if( i>j .and. variable(i,j) /=0) then
                    OX = .FALSE.
                    EXIT OUTER
                end if
            end do
	   end do Outer
    end function  

    logical function XY() result(OX)
    	outer : do i=1,VAR_MAX_SIZE,1
        	do j=1,VAR_MAX_SIZE,1
            	if( variable(i,j) /= variable(j,i)) then
                	OX = .false.
                    exit outer
                end if
            end do
	   end do Outer
    end function  

!Upper , Lower , Symmetric , Diagonal   	

end program MatrixTest

    logical function Outer_Identity(variable,VAR_MAX_SIZE) result(OX)
		integer,dimension(3,3) :: variable
    	INTEGER :: i,j,VAR_MAX_SIZE
    	outer : do i=1,VAR_MAX_SIZE,1
        	do j=1,VAR_MAX_SIZE,1
            	if( i==j .and. variable(i,j) /= 1) then
                	OX = .false.
                    exit outer
                else if( i/=j .and. variable(i,j) /=0) then
                  	OX = .false.
                    exit outer
                end if
            end do
	    end do Outer
    end function        

    subroutine Outer_Sub_Upper(variable)
    	integer , dimension(3,3) :: variable
        
      
    	do i=2,VAR_MAX_SIZE,1
        	do j=1,i-1,1
            	if(variable(i,j) /= 0) then
                	OX = .FALSE.
                END IF
            END DO
        END DO
    END FUNCTION