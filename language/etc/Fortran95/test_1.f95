PROGRAM test_1

!	INTEGER::I, j, k  ! Since the integer type is 8 bits, seven spaces are left when output.
!    i = 1
!    j = 2
!    k = 3

!    WRITE(*,*) i,j,k 
	
!	i = 1+2+3+4+5 &			!  & Connects sentences.
!    +6+7+8+9+10+  &
!    11
!    WRITE(*,*) i			!  I did not declare j, k.
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!	
	
!	WRITE(6,10) i
!10  FORMAT(I5)
!	WRITE(6,11) i
!11  FORMAT(I6)
!	WRITE(6,12) i
!12  FORMAT(I7)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!	INTEGER::i
!
!    i = 214783647

!    WRITE(6,10) i			!  When it overflows, it is marked with *.
!10	FORMAT(I5)
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!	WRITE(*,*) 2+3
!	WRITE(*,*) 2-3
!	WRITE(*,*) 2*3
!	WRITE(*,*) 2/3.				!   If you type. At the end of a sentence, a decimal point is printed.
!	WRITE(*,*) 2**3    

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

!	INTEGER::i,j

!    i = 30 
!    j = 30.7

!    WRITE(*,*) i,j

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

!	REAL::r1,r2

!    real_number_1 = 3.14159
!    real_number_2 = 3.14159E1

!    WRITE(6,10) real_number_1
!10  FORMAT(E10.1)
!    WRITE(6,11) real_number_1
!11  FORMAT(E10.2)
!    WRITE(6,12) real_number_1
!12  FORMAT(E10.3)
!    WRITE(6,13) real_number_1
!13 FORMAT(E10.4)
!	WRITE(6,14) real_number_1
!14 FORMAT(F2.1)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

!	IMPLICIT NONE				!	IMPLICIT NONE is used to check declarations.
!    INTEGER:: int_number=10

!    int_number = 100
!    WRITE(*,*) mumber

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!	IMPLICIT NONE
!    LOGICAL::l1 = .TRUE.
!    LOGICAL::l2 = .FALSE.

!    WRITE(*,*) l1,l2

!    CHARACTER(LEN=10)::A = 'FORTRAN'
!    CHARACTER(LEN=5)::B = 'FORTRAN'

!    WRITE(*,*) l1,l2
!    WRITE(6,10) A,B
!10	FORMAT(A7,A7)
	
	IMPLICIT NONE

    REAL::NUMBER_1,NUMBER_2,NUMBER_3,NUMBER_4,NUMBER_5,NUMBER_6

    NUMBER_1 = 2
    NUMBER_2 = 3
    NUMBER_3=NUMBER_1 + NUMBER_2
    NUMBER_4=NUMBER_1 - NUMBER_2
    NUMBER_5=NUMBER_1 * NUMBER_2
    NUMBER_6=NUMBER_1 / NUMBER_2

    WRITE(*,*) NUMBER_1, '+', NUMBER_2, '=', NUMBER_3
    WRITE(*,*) NUMBER_1, '-', NUMBER_2, '=', NUMBER_4
    WRITE(*,*) NUMBER_1, '*', NUMBER_2, '=', NUMBER_5
    WRITE(*,*) NUMBER_1, '/', NUMBER_2, '=', NUMBER_6

    

END PROGRAM test_1