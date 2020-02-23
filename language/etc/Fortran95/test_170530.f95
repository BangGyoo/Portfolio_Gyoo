PROGRAM test_170530

	IMPLICIT NONE

	call s1()
    call s1()
    call s1()

    
    CONTAINS
    SUBROUTINE s1()
    	write(*,*) 'I AM SUBROUTINE'

    END SUBROUTINE s1

    

END PROGRAM test_170530