PROGRAM ExampleList4

	IMPLICIT NONE

    INTEGER :: angle , i, j , dan
    real :: radian

    read(*,*) angle

    radian = angle * 3.14159/180

    write(*,*) sin(radian)
    write(*,*) cos(radian)
    
	write(*,*) ' '

    do i=0 , 360, 10
      write(*,*) i , ' angle ////// sin is ', sin(i*3.14159/180), 'cos is', cos(i*3.14159/180)
    end do

	do i=0 , 10 , 1
      write(*,*) ' '
    end do

    do i=1, 9 , 1
      do j= 1, 9, 1
      	write(*,*) i, 'X', j, '=', i*j
      end do
    end do
	
    write(*,*) 'a'

    
	i=1
    do while(i<10)
      j = 1
      do while(j<10)
        write(*,*) i, 'X', j, '=', i*j
        j = j+1
      end do
      i = i+1
    end do
	
	write(*,*) ' '
	
	i = 1
    do
      j = 1
      do
        write(*,*) i, 'X', j, '=', i*j
        if(j==9) exit
        j= j+1
      end do
      if(i==9) exit
      i = i+1
	end do

END PROGRAM ExampleList4