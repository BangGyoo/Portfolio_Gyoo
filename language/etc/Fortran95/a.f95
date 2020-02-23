program a

	implicit none

    integer :: aob

    aob=5

    select case(aob)
      case(5)
      	write(*,*) aob
      case default
        write(*,*) "false"
    end case

end program a