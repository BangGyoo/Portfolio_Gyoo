PROGRAM test_170328

	IMPLICIT NONE
	
!	INTEGER:: n
!	READ(*,*) n	
	
!	IF(MOD(n,2) ==0) THEN
!    	WRITE(*,*) 'EVEN' 
!	ELSE
!    	WRITE(*,*) 'ODD'
!    END IF
																		! i have a pan , i have a apple ahh~
!	SELECT CASE (MOD(n,2) == 0)
!    	CASE(.TRUE.)
!        	WRITE(*,*) 'even'
!        
!		CASE (.FALSE.)
!        	WRITE(*,*) 'ODD'
!	END SELECT
	
!    INTEGER:: a,b,c,max
!	READ(*,*) a,b,c
    
!    IF( a>b)	THEN
!      M = a											! where is loop :(((((((((((((( sadddddddddd
!    ELSE
!      M = b      	
!    END IF
!	WRITE(*,*) m
		
!	SELECT CASE(a>b)
!    	CASE(.TRUE.) THEN
!        	IF(a>c) 	THEN
!            	max = a	
!            ELSE 
!              	max = c
!            END IF
!        CASE(.FALSE.) THEN
!        	IF(b>c)		THEN
!            	max = b
!            ELSE 
!                max = c
!            END IF
!        END SELECT
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

!	IF(a>=b .and. a>=c) max = a	
!	IF(b>=a .and. b>=c) max = b              
!    IF(c>=a .and. c>=b) max = c
	
!	WRITE(*,*) max	
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

!	INTEGER :: n ,i, factorial = 1

!	WRITE(*,*) 'Type a integer'
!    READ(*,*) n

!    DO i = 1,5,1				! 'do' loop same 'for' of c lauquege 
!	  factorial = factorial*i
!      WRITE(6,11) i,'! :',factorial
!11    FORMAT(I2,A,I7)
!	END DO
!
!	WRITE(6,10) 'factorial of 1 ~', 'n    ', factorial
!10 	FORMAT(A,A,I7)

	INTEGER :: i,j, count,n,even=0,odd=0,minus=0,zero=0
   	
	READ(*,*) count

    DO i = 1 , count, 1
       read(*,*) n
       
	   IF(n<0)				THEN
         minus = minus + 1	
       ELSE IF(n==0) THEN
       	 zero = zero + 1
	   ELSE IF(MOD(n,2)==0) THEN
         even = even + 1
       ELSE
         odd = odd + 1
       END IF
    END DO

    WRITE(*,*) 'EVEN : ', even
    WRITE(*,*) 'ODD : ', odd    
    WRITE(*,*) 'MINUS : ', minus  
    WRITE(*,*) 'ZERO : ', zero

      
	i=1
    do while(i<10)
      j=1
      do while(j<10)
        write(*,*) i, 'X', j, '=', i*j
        j = j+1
      end do
      i = i+1
    end do




	

END PROGRAM