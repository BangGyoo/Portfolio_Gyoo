Program test_test2

	implicit none

	integer :: i, dan1,dan2 ,dan

    write(*,*) 'gugudan ibreokhe juseyo.'
	read(*,*) dan1 , dan2

    do dan = dan1, dan2, 1
      do i=1,9
        write(*,*) dan, 'x', i, '=', dan*i
      end do
    end do

    
	write(*,*) '////////////////////////////////////////////////'    
	dan = dan1;
    do   
      i = 1
      do
        write(*,*) dan, 'x', i, '=', dan*i
        i = i+1
		if(i == 9) exit
      end do
      dan = dan+1
      if(dan > dan2) exit;
    end do

    
	write(*,*) '////////////////////////////////////////////////'
    dan = dan1
    do while(dan <= dan2)
      i = 1
      do while(i<=9)
        write(*,*) dan, 'x', i, '=', dan*i
        i = i+1
      end do
    dan = dan+1  
	end do

end program test_test2