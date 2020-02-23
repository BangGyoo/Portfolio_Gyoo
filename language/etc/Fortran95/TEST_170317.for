		PROGRAM test_170317 						! The name of the program can be up to 31 characters.

      		IMPLICIT NONE

!	        REAL :: LT = 3.14159				! When & is attached, the top and bottom are the same line.

!    	    write(*,*) 2*LT
      
			INTEGER :: a,b,c
            WRITE(*,*) 'Enter 2 Integer...'
            READ(*,*) a,b,c
            
			WRITE(6,10) 'max(',a,',',b,',',c,')',  MAX(a,b,c)
            WRITE(6,10) 'min(',a,',',b,',',c,')',  MIN(a,b,c)
10       	FORMAT(A4 , I4 , A1 , I4 , A1 , I4, A4, I4)

            WRITE(6,13) 'abs(', a,')',  ABS(a)
            WRITE(6,13) 'abs(', b,')',  ABS(b)
            WRITE(6,13) 'abs(', c,')',  ABS(c)
13         	FORMAT(A4 , I4 , A4 , I4)
			

        END PROGRAM test_170317