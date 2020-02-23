PROGRAM T2

	IMPLICIT NONE
    real::sum1 =0, factorial = 1
    INTEGER :: i,n ,j
    read(*,*) n
    
    DO I=1,n*2-1, 2
      factorial = 1
      do j=1,i,1
      	factorial = j*factorial
      end do
      if(mod(i-1,4)==0) then
        SUM1 = SUM1 + 1.0/factorial
      else
        sum1 = sum1 - 1.0/factorial
      end if
      WRITE(*,*) i/2+1, SUM1
    END do

	WRITE(*,*) SUM1
    
END PROGRAM T2