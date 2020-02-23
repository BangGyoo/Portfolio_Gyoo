PROGRAM test_170407

	IMPLICIT NONE

	! Max_count is 100
    
	INTEGER :: i,j , count=1
    REAL :: angle ,cosX=1 , fatorial , radian
    READ(*,*) angle

    radian = angle*3.14159/180

	DO i=2, 20, 2
    	count = count+1
        fatorial=1
        DO j=1 ,i, 1
          fatorial = j*fatorial
        END DO
    	if(MOD(count,2) == 0) THEN
    	   cosX = cosX-((radian**i)/fatorial)
    	else
      	   cosX = cosX+((radian**i)/fatorial)
    	END IF
    END DO
    WRITE(6,10) cosX
10	FORMAT(f10.7)





END PROGRAM test_170407