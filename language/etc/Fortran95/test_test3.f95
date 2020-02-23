program test_test3

	implicit none

    integer :: angle , line = 0
    real :: rad

    do angle = 0 , 360, 10
      rad = angle *3.14159/180
      write(6,10) angle, sin(rad), cos(rad)
10    format(i3,2f12.7)
	  line = line + 1
      if(mod(line,5) == 0) write(*,*) ''
    end do


    
end program test_test3