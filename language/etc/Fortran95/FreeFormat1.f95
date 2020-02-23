PROGRAM test_test_test

	implicit none
    
	integer,dimension(3,2):: a = reshape((/1,2,3,1,2,3/),(/3,2/))
    integer :: i,j
    logical :: yeal,loco

	write(*,3) ((a(i,j),i=1,3),j=1,2)
3   format(2I3)

	call x
    call x
    if( yeal() == .true. ) then
      loco = yeal()
    end if

	contains

    subroutine x()
    	write(*,*) 'hello'
    end subroutine


end program test_test_test

logical function yeal() result(ox)
    write(*,*) 'hello'
	ox = .true.
	
end function