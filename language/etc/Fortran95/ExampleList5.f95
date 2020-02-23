PROGRAM ExampleList5

	IMPLICIT NONE

    INTEGER :: i,j, dan1, dan2 , index ,f1=1,f2=1,f3 , count1, count2

    read(*,*) dan1, dan2

    if(dan1 > dan2) then
      index = dan2
      dan2  = dan1
      dan1  = dan2
    end if

    do i=dan1, dan2, 1
      do j=1, 9, 1
        write(*,*) i , 'X', j, i*j
      end do
    end do 

	do i=dan2, dan1, -1
      do j=9, 1, -1
        write(*,*) i , 'x', j, i*j
      end do
    end do


    write(*,*) '////////////////////////////////////////////////////'
	read(*,*) count1, count2
	i=1
    do 
      f3 = f1 + f2
      if(f3>=count1 .and. f3<=count2) write(*,*) f1 ,'(f1) + ', f2, '(f2) = ', f3      
      f1 = f2
      f2 = f3
      if(f3 >=1000) exit
      i= i+1

    end do

	

END PROGRAM ExampleList5