PROGRAM MatrixTest

	IMPLICIT NONE

    INTEGER DIMENSION(3,3) :: variable =  before = RESHAPE(/1,0,0,0,1,0,0,0,1/),(/3,3/)
	INTEGER :: i,j

    WRITE(*,*) 'Enter matrix(3,3)'
    READ(*,*)  ((variable(i,j),j=1,3)i=1,3); write(*,*) ' '
    WRITE(*,3) ((variable(i,j),j=1,3)i=1,3); write(*,*) ' '
3	format(3I3)