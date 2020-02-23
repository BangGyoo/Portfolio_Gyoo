program testing

	implicit none
    integer :: a=10
    integer :: test

    write(*,*) test(a)

end program testing

integer function test(a) result(a)
		integer:: a
        a= 20
end function test