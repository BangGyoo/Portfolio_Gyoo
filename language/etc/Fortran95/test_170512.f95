PROGRAM test1

	IMPLICIT NONE

    INTEGER , DIMENSION(10,4) :: score
    INTEGER :: i,j,temp,searchNum
    READ(5,10) ((score(i,j),j=1,3),i=1,10)
10  format(3i3)

	DO j=1, j=10, 1
		DO i=1 , 4, 1
    		if(temp > score(j,i)) temp = score(j,i)
        end do
        
    end do 

    DO I=1 , 10
      SCORE(I,4) = (SCORE(I,1) + SCORE(I,2) + SCORE(I,3))
    END DO

    write(6,20) ((score(i,j),j=1,4),i=1,10)
20  format(4i3)

	

END PROGRAM test1