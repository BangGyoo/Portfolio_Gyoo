PROGRAM test_170321
	
	IMPLICIT NONE

!    WRITE(*,*) '(1) : '	,8-15+3
!    WRITE(*,*) '(2) : '	,4.0-2.0/5.0
!    WRITE(*,*) '(3) : '	, 4 + 2/5
!    WRITE(*,*) '(4) : '	, 5/2 + 6
!    WRITE(*,*) '(5) : '	, 11+3**2
!	WRITE(*,*) '(6) : '	,(2+3)**2
!    WRITE(*,*) '(7) : '	,25.0**1/2
!    WRITE(*,*) '(8) : '	,25.0**(1/2)
!    WRITE(*,*) '(9) : '	,25.0**(1.0/2.0)
!    WRITE(*,*) '(10) : ',12.0/1.0**3.0
!    WRITE(*,*) '(11) : ',(2*3-4)/(8-2-1)*2
!    WRITE(*,*) '(12) : ',((2*3-4)/(8-2-1))*2
!    WRITE(*,*) '(13) : ',(2+3**2)/(8-2-1)
!    WRITE(*,*) '(14) : ',(1.0+3**2)/(8-2-1)
!    WRITE(*,*) '(15) : ',13.0**2
!    WRITE(*,*) '(16) : ',SQRT(6.0+3.0)
!	WRITE(*,*) '(17) : ',ABS(1-2-3)
!	WRITE(*,*) '(18) : ',EXP(4.0-2.0-1.0)
!	WRITE(*,*) '(19) : ',INT(6.5+4.0/3.0)
!	WRITE(*,*) '(20) : ',"one"//','//"two"
!	WRITE(*,*) '(21) : ',"ma"//"depth"(:2)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!	REAL :: two=2.0 , three = 3.0 , four = 4.0 
!	INTEGER :: five = 5, six = 6
!	CHARACTER(len = 3) :: cA='for' 
!	CHARACTER(len = 4) :: cB="tran", cC='inch'
!	WRITE(*,*) '(1) : ', two*three+three
!   WRITE(*,*) '(2) : ', five/3
!   WRITE(*,*) '(3) : ', (three+two/four)**2
!	WRITE(*,*) '(4) : ', six/five*3.14
!    WRITE(*,*) '(5) : ', four**2/two**2
!	WRITE(*,*) '(6) : ', five**2/two**2
!    WRITE(*,*) '(7) : ', SQRT(two+three+four)
!    WRITE(*,*) '(8) : ', cA//cB//"-95"
!    WRITE(*,*) '(9) : ', 'feet'//"="//'24'//cC
!    WRITE(*,*) '(10) : ', cA//cB(:1)
!    WRITE(*,*) '(11) : ', cB(2:3)//"dius"
!    WRITE(*,*) '(12) : ', cA(2:3)//"dinate"

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
!    REAL :: a
!10  WRITE(*,*) 'Enter a digit...'
!	READ(*,*) a
	
!	IF(a > 0)		THEN
!    	 WRITE(*,*) '+'
!    ELSE IF(A ==0)	THEN
!      	 WRITE(*,*) '0'
!   	ELSE				
!      	 WRITE(*,*) '-'
!	END IF
      
!	GOTO 10

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
!	INTEGER :: month
!10  READ(*,*) month

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
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
!	INTEGER :: scare
!
!10	WRITE(*,*) "Hello man ~ , If you can your scare?"
!	READ(*,*) scare
    
!    IF				(scare <= 100 .OR. scare >= 90) THEN
!      	WRITE(*,*) 'A'
!    ELSE IF			(scare < 90 .OR. scare >= 80) THEN
!      	WRITE(*,*) 'B'
!    ELSE IF			(scare < 80 .OR. scare >= 70) THEN
!      	WRITE(*,*) 'C'
!    ELSE IF			(scare < 70 .OR. scare >= 60) THEN
!      	WRITE(*,*) 'D'
!    ELSE IF			(scare < 60 .OR. scare >= 0) THEN
!      	WRITE(*,*) 'F'
!    ELSE
!      	WRITE(*,*) "OH ~ NO ~ ONE MORE TIME"			
!      	GOTO 10
!    END IF

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	REAL :: A,B,C,D

    WRITE(*,*) 'ENTER A,B,C OF QUADRATIC EQUATION ...'
    READ(*,*) A,B,C
    D = B*B - 4*A*C

    IF(D<0) THEN
      WRITE(*,*) 'IMAGINARY ROOS'
    ELSE IF(D==0) THEN
      WRITE(*,*) (-B+ SQRT(D))/(2*A)
    ELSE
      WRITE(*,*) (-B+SQRT(D))/(2*A), (-B-SQRT(D))/(2*A)
    END IF
      
END PROGRAM test_170321