PROGRAM test_170523

	IMPLICIT NONE

    INTEGER :: i
    INTEGER, DIMENSION(20:40):: TEM = 0
    INTEGER, DIMENSION(31) :: TEMP
    OPEN(1,FILE='201607.txt')

    READ(1,*) TEMP
    DO I=1 , 31, 1
      TEM(TEMP(I)) = TEM(TEMP(I)) + 1
    END DO

    CLOSE(1)
    WRITE(*,10) TEMP

    OPEN(2,FILE='return.txt')
	write(*,*) 'max is',MAXVAL(TEMP) ,'     min is', MINVAL(TEMP), '     avarage is',SUM(TEMP)/30.0
    do i=MINVAL(TEMP),MAXVAL(TEMP),1
		if( tem(i) == 0 ) then
        	cycle
		else
			WRITE(2,11) i,' is ',TEM(i)
        end if
    end do
    close(2)


10  format(5I3)
11  format(I3 , A5,2I3)

END PROGRAM test_170523