PROGRAM Test

	IMPLICIT NONE
    real :: root
   	integer :: i
    real :: f, f1

    write(*,*) 'si'
    read(*,*) root
    write(6,10) root
10  format(f20.15)

	do i=1,10
    	root = root - f(root)/f1(root)
        write(6,10)


REAL FUNCTION f(x) result(y)
	y = x**2 - 2
end function f