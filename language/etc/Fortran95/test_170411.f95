PROGRAM test_170411


	IMPLICIT NONE
    INTEGER :: I , input, sum =0
	WRITE(*,*) 'ENTER A number'
    
    DO I=1, 1000000, 1
      READ(*,*) INPUT
      SUM = SUM +INPUT
	  IF (INPUT==0) EXIT
    END DO

	WRITE(*,*) SUM

END PROGRAM test_170411