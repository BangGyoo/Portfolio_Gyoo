program t1
	
	implicit none

    integer :: n ,factorial = 1 ,i=1 ,j 

    real :: angle , radian , sinx

    write(*,*) 'enter a abgle'
    read(*,*) angle
    radian = angle * 3.14159/180

    write(*,*) sin(radian)
    write(*,*) cos(radian)
    write(*,*) ''
    
	write(*,*) 'enter a number of term'
    READ(*,*) n
    
	sinx = 0
    do i=1, 2*n-1 , 2
      write(*,*) sinx
      factorial = 1
      do j=1, i, 1
        factorial = factorial*j
      end do
	  
	  if(mod((i-1)/2,2)==0) then
	  	sinx =sinx + (radian**(i))/factorial 
	  else
        sinx =sinx - (radian**(i))/factorial
      end if
    end do
    

end program t1