PROGRAM test

	IMPLICIT NONE
!    INTEGER:: i,  j, dan_start,dan_end, dan1, dan2
	
!	WRITE(*,*) "From"
!    READ(*,*) dan1,dan2
	
!	IF(dan1 < dan2) THEN
!    	dan_start = dan1
!        dan_end   = dan2
!    ELSE	
!      	dan_start = dan2
!        dan_end	  = dan1
!    END IF


!    DO i = dan_start,dan_end,1
!      	DO j=1,9,1
!      	WRITE(6,10) i, '*', dan_end, '=', i*dan_start
!10     	FORMAT(I4,A,I4,A,I4)
!      	END DO
!   	WRITE(*,*) ' '
!   	END DO
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

!	INTEGER :: i , n , minus_sum = 0, plus_sum = 0 , minus_count = 0, plus_count = 0

!    DO i=1,10,1
!      	READ(*,*) n
!        IF(n <0)		THEN;		minus_sum = minus_sum + n ; minus_count = minus_count + 1
!        ELSE IF(n ==0)  THEN;		cycle
!        ELSE
!			plus_sum = plus_sum  + n  					! exit same break; cycle same continue.
!            plus_count = plus_count + 1
!		END IF
!	END DO
!    WRITE(6,11) 'minus_sum= ',minus_sum, '  count=', minus_count , '  plus_sum=', plus_sum , '  plus_count=', plus_count
!11	FORMAT(A,I5,A,I5,A,I5,A,I5)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	INTEGER :: angle , angle1, angle2 , angle_start , angle_end, x
    REAL	:: PI = 3.14159
    READ(*,*) angle1, angle2 , x

    IF(angle1 < angle2) THEN
      angle_start = angle1
      angle_end	  = angle2
    ELSE
      angle_start = angle2
      angle_end   = angle1
	END IF

    WRITE(*,*) 'ang    radian      SIN(x)   '
    WRITE(*,*) '----------------------------'

	DO angle = angle_start , angle_end , x
    	WRITE(6,10) angle , angle *PI / 180 ,SIN(angle * PI / 180)
10     	FORMAT(I3,F13.7,F13.7)

    END DO
    
END PROGRAM