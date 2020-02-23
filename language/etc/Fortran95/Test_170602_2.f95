PROGRAM Test_170602_2

	IMPLICIT NONE
    integer :: a=10,b=20, output
    integer :: outerfunction

    write(*,*) 	innerfunction()
  	write(*,*)  outerfunction(a,b)
    call innersubroutine(); write(*,*) output
	call outersubroutine(a,b,output); write(*,*) output
        

    contains
integer function innerfunction() result(output)
		integer :: output
		if(a>b) then	
        	output = a
        else if(a==b) then
          	output = a
        else
          	output = b
        end if  
end function innerfunction

subroutine innersubroutine()
		if(a>b) then	
        	output = a
        else if(a==b) then
          	output = a
        else
          	output = b
        end if 
end subroutine innersubroutine	


        
end program Test_170602_2

integer function outerfunction(a,b) result(output)
		integer ::a,b, output
		if(a>b) then	
        	output = a
        else if(a==b) then
          	output = a
        else
          	output = b
        end if  
end function outerfunction


subroutine outersubroutine(a,b,output)
		integer :: a, b, output
		if(a>b) then	
        	output = a
        else if(a==b) then
          	output = a
        else
          	output = b
        end if 
end subroutine outersubroutine