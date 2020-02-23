PROGRAM test_170314

	IMPLICIT	NONE

!    INTEGER:: i1, i2
!    REAL::	r1, r2
!    COMPLEX:: c1, c2					! 

!    CHARACTER:: ch1, ch2
!    LOGICAL:: l1, l2
	
!	WRITE(*,*) "Enter an integer."
!	READ(*,*) i1,i2
!    WRITE(*,*) "Enter your real number."
!	READ(*,*) r1,r2
!	WRITE(*,*) "Enter your charcter."
!	READ(*,*) ch1,ch2
!	WRITE(*,*) "Enter your true or false."
!	READ(*,*) l1,l2
	
	
!	WRITE(6,10) i1, i2
!10  FORMAT(2i5)
!    WRITE(6,11) r1, r2
!11  FORMAT(2F5.2)
!	WRITE(6,12) ch1, ch2
!12  FORMAT(2A5)	
!	WRITE(6,13) l1, l2
!13  FORMAT(2L5)
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

!	INTEGER:: i1,i2
!	READ(*,*)i1,i2
!	IF(i1 == i2) WRITE(*,*) 'same'
!	IF(i1 /= i2) WRITE(*,*) 'not same'

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	INTEGER :: m

    WRITE(*,*) 'Type a month'
    READ(*,*) m

	IF (M==1 .OR. M==2 .OR. M==12) WRITE(*,*) 'winter'
	IF (M==3 .OR. M==4 .OR. M==5) WRITE(*,*) 'spring'
	IF (M==6 .OR. M==7 .OR. M==8) WRITE(*,*) 'summer'
    IF (M>=9 .AND. M<=11) WRITE(*,*) 'FALL'

!    IF (M==1) WRITE(*,*) 'winter'
!    IF (M==2) WRITE(*,*) 'winter'
!    IF (M==3) WRITE(*,*) 'spring'
!    IF (M==4) WRITE(*,*) 'spring'
!    IF (M==5) WRITE(*,*) 'spring'
!    IF (M==6) WRITE(*,*) 'summer'
!    IF (M==7) WRITE(*,*) 'summer'
!    IF (M==8) WRITE(*,*) 'summer'
!    IF (M==9) WRITE(*,*) 'FALL'
!    IF (M==10) WRITE(*,*) 'FALL'
!    IF (M==11) WRITE(*,*) 'FALL'
!    IF (M==12) WRITE(*,*) 'winter'

	
END PROGRAM test_170314