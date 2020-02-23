program ExampleList6

	implicit none

    real :: x = 1 ,radian
    integer :: angle, factorial = 1,n,i,j
    
	read(*,*) n , angle
    radian = angle*3.14/180
	do i =0, 2*n, 2
    	factorial = 1
        if(i ==0) then
          x=1
          continue
        else
			do j =1, i, 1
    			factorial = factorial*j
    		end do
        end if
        
  	    if(mod(i/2,2) == 0) then
        	x = x+radian**2/factorial
        else
          x = x - radian**2/factorial
        end if
    end do

    write(*,*) 'x = ',x

    

end program ExampleList6