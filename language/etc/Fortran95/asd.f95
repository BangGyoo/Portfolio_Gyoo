program asd

	implicit none

    integer :: a

    a= 5

    select case(a)
      case(5)
      	write(*,*) a
      case default
        write(*,*) "false"
      end select

end program asd