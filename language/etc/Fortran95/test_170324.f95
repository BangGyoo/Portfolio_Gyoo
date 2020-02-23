PROGRAM test_170324

	IMPLICIT NONE

!    REAL:: a,b,c,cool						! i have a pen , i have a apple , ahhhhh, applepen ~ , i have pen , i have a fineapple ~
    										! ahhhh ~~ , fineapplepen ~ , applepen ~, fineapplepen ~ , ahhhhh
                                            ! fineapplepen ~
                                            ! doom chi ta chi doom chi ta chi doom chi ta chi

!    WRITE(*,*) 'Enter 3 input'

!    READ(*,*) a,b,c

!	IF	(a == MAX(a,b,c)) THEN
!    	cool = SQRT(b*b + c*c)
!	ELSE IF (b == MAX(a,b,c))THEN
!	 	cool = SQRT(a*a + c*c) 
!    ELSE
!      	cool = SQRT(a*a + b*b)
!    END IF

!    IF (cool == MAX(a,b,c)) THEN
!      WRITE(*,*) 'nice~'
!    ELSE
!      WRITE(*,*) 'NONO'
!    END IF


!    s = (a+b+c)/2.0

!    area = SQRT(s*(s-a)*(s-b)*(s-c))

!    WRITE(*,*) 'area = ', area
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!	INTEGER:: month
!10    READ(*,*) month
!    
!
!    IF			(month==1 .OR. month==2 .OR. month==12) THEN
!     	 WRITE(*,*) 'WINTER'
!    ELSE IF		(month==4 .OR. month==5 .OR. month==3)  THEN
!     	 WRITE(*,*) 'SPRING'
!    ELSE IF		(month==7 .OR. month==8 .OR. month==6)  THEN
!         WRITE(*,*) 'SUMMER'
!    ELSE IF		(month==9 .OR. month==10 .OR. month==11) THEN 
!    	 WRITE(*,*) 'AUTUMN'
!	ELSE 
!     	 GOTO 10 !WRITE(*,*) "Are you crazy?"
!    END IF
!
!	IF			(month==1 .OR. month==3 .OR. month==5 .OR. month==7 .OR. month==8 .OR. month==10 .OR. month==12)	THEN
!    	WRITE(*,*) month, " month is 31 days"
!	ELSE IF (month ==2)			THEN
!    	WRITE(*,*) month, " month is 28 days"	
!	ELSE 
!    	WRITE(*,*) month, " month is 30 days"
!	END IF
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!	INTEGER :: m

!    WRITE(*,*) 'Type a month'
!    READ(*,*) m

!    SELECT CASE (m)

!      CASE(1,2,12)
!      	WRITE(*,*) 'WINTER'
!      CASE(3,4,5)
!      	WRITE(*,*) 'SPRING'
!      CASE(6,7,8)
!      	WRITE(*,*) 'SUMMER'
!      CASE(9,10,11)
!      	WRITE(*,*) 'AUTUMN'
!      CASE DEFAULT
!      	WRITE(*,*) 'OUT OF RANCE'

!    END SELECT
        
!          SELECT CASE (m)

!      CASE(1,3,5,7,8,10,12)
!      	WRITE(*,*)  m, 'month is 31days'
!      CASE(2)
!      	WRITE(*,*)  m, 'month is 28days'
!      CASE(4,6,9,11)
!      	WRITE(*,*) m, 'month is 30days'   
             
!    END SELECT
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


	CHARACTER(LEN=14) :: ID='941119-1231231'

!	SELECT CASE(ID(8:8))
!    	CASE('1')
!        	WRITE(*,*) 'male'
!        CASE('2')
!        	WRITE(*,*) 'female'
!    END SELECT
	
	IF(ID(8:8) == '1' .OR. ID(8:8) == '3') THEN
    	WRITE(*,*) 'MALE'
    ELSE IF(ID(8:8) == '2' .OR. ID(8:8) == '4') THEN
    	WRITE(*,*) 'FEMALE'
    ELSE
      STOP
      
    END IF
	SELECT CASE(	ID(8:8))
    	CASE('1','3')

    		IF(ID(3:4) == '1' .OR. ID(3:4) == '2' .OR. ID(3:4) == '12') THEN
    			WRITE(*,*) 'MALE BURTHDAY IS WINTER'
    		ELSE IF(ID(3:4) == '3' .OR. ID(3:4) == '4' .OR. ID(3:4) == '5') THEN
    			WRITE(*,*) 'MALE BURTHDAY IS SPRING'
    		ELSE IF(ID(3:4) == '6' .OR. ID(3:4) == '7' .OR. ID(3:4) == '8') THEN
    			WRITE(*,*) 'MALE BURTHDAY IS SPRING'    
    		ELSE IF(ID(3:4) == '9' .OR. ID(3:4) == '10' .OR. ID(3:4) == '11') THEN
    			WRITE(*,*) 'MALE BURTHDAY IS SPRING'
    		ELSE 
    			WRITE(*,*) 'ERROR'        
   			 END IF
		CASE('2','4')

    		IF(ID(3:4) == '1' .OR. ID(3:4) == '2' .OR. ID(3:4) == '12') THEN
    			WRITE(*,*) 'FEMALE BURTHDAY IS WINTER'
    		ELSE IF(ID(3:4) == '3' .OR. ID(3:4) == '4' .OR. ID(3:4) == '5') THEN
    			WRITE(*,*) 'FEMALE BURTHDAY IS SPRING'
    		ELSE IF(ID(3:4) == '6' .OR. ID(3:4) == '7' .OR. ID(3:4) == '8') THEN
    			WRITE(*,*) 'FEMALE BURTHDAY IS SPRING'    
    		ELSE IF(ID(3:4) == '9' .OR. ID(3:4) == '10' .OR. ID(3:4) == '11') THEN
    			WRITE(*,*) 'FEMALE BURTHDAY IS SPRING'
    		ELSE 
    			WRITE(*,*) 'ERROR'        
   			 END IF

		END SELECT


END PROGRAM