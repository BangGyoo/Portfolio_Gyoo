PROGRAM test_170317 						! The name of the program can be up to 31 characters.

    	IMPLICIT NONE

!	        REAL :: LT = 3.14159				! When & is attached, the top and bottom are the same line.

!    	    write(*,*) 2*LT
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1      
!		INTEGER :: a,b,c
!        WRITE(*,*) 'Enter 2 Integer...'
!        READ(*,*) a,b,c
            
!		WRITE(6,10) 'max(',a,',',b,',',c,')',  MAX(a,b,c)
!        WRITE(6,10) 'min(',a,',',b,',',c,')',  MIN(a,b,c)
!10   	FORMAT(A4 , I4 , A1 , I4 , A1 , I4, A4, I4)
!
!        WRITE(6,13) 'abs(', a,')',  ABS(a)
!        WRITE(6,13) 'abs(', b,')',  ABS(b)
!        WRITE(6,13) 'abs(', c,')',  ABS(c)
!13     	FORMAT(A4 , I4 , A4 , I4)
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
!		REAL :: angle , PI =3.14159
!		WRITE(*,*) 'Enter a angle'
!        READ(*,*) angle
!        WRITE(*,*) 'angle    sin()  cos()'
!        WRITE(*,*) '----------------------'
!        WRITE(6,10) angle, SIN(angle*PI/180), COS(angle*PI/180)		!I want to input the pi value as a macro constant.
!10		FORMAT(F5.1, ':', 2F8.3)
!		WRITE(*,*) '----------------------'
!        
!        WRITE(6,11) 10., SIN(10.*PI/180), COS(10.*PI/180) , tan(10.*PI/180)
!        WRITE(6,11) 20., SIN(20.*PI/180), COS(20.*PI/180) , tan(20.*PI/180)            
!        WRITE(6,11) 30., SIN(30.*PI/180), COS(30.*PI/180) , tan(30.*PI/180)	
!        WRITE(6,11) 40., SIN(40.*PI/180), COS(40.*PI/180) , tan(40.*PI/180)
!        WRITE(6,11) 50., SIN(50.*PI/180), COS(50.*PI/180) , tan(50.*PI/180)              
!        WRITE(6,11) 60., SIN(60.*PI/180), COS(60.*PI/180) , tan(60.*PI/180)              
!        WRITE(6,11) 70., SIN(70.*PI/180), COS(70.*PI/180) , tan(70.*PI/180)              
!        WRITE(6,11) 80., SIN(80.*PI/180), COS(80.*PI/180) , tan(80.*PI/180)  
!        WRITE(6,11) 90., SIN(90.*PI/180), COS(90.*PI/180) , tan(90.*PI/180)            
!11		FORMAT(F5.1, ':', 2F8.4,2F8.4,2F8.4)
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	REAL:: LOOP=2.
    WRITE(6,10) 'SQRT(',LOOP,') =',SQRT(LOOP)
    LOOP = LOOP+1.

    WRITE(6,10) 'SQRT(',LOOP,') =',SQRT(LOOP)
    LOOP = LOOP+1.
    WRITE(6,10) 'SQRT(',LOOP,') =',SQRT(LOOP)
    LOOP = LOOP+1.
    WRITE(6,10) 'SQRT(',LOOP,') =',SQRT(LOOP)
    LOOP = LOOP+1.         
    WRITE(6,10) 'SQRT(',LOOP,') =',SQRT(LOOP)
    LOOP = LOOP+1.
    WRITE(6,10) 'SQRT(',LOOP,') =',SQRT(LOOP)
    LOOP = LOOP+1.
    WRITE(6,10) 'SQRT(',LOOP,') =',SQRT(LOOP)
    LOOP = LOOP+1.
10  FORMAT(A6,3,A4,E20.7)




END PROGRAM test_170317
