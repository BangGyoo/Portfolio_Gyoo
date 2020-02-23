PROGRAM homework2016

	IMPLICIT NONE

    INTEGER :: i,j , count=1 ,monthcount=0
    INTEGER, DIMENSION(366) :: TEMP
    INTEGER, DIMENSION(-50:50,12):: TEM = 0   
   


    OPEN(1,FILE='2016.txt')
    READ(1,*) TEMP    
    close(1)
    
	do i=1,12,1
		if(i == 1.OR.i==3.OR.i==5.OR.i==7.OR.i==8.OR.i==10.OR.i==12) then
        	do j=1,31,1
        		TEM(TEMP(count),i) = TEM(TEMP(count),i) + 1
       	    	count = count + 1
      		end do
        else if(i == 4.OR.i==6.OR.i==9.OR.i==11) then
            do j=1,30,1
                TEM(TEMP(count),i) = TEM(TEMP(count),i) + 1
       	    	count = count + 1
            end do
        else
            do j=1,29,1
                TEM(TEMP(count),i) = TEM(TEMP(count),i) + 1
       	    	count = count + 1
            end do
        end if
    end do
 
	write(*,11) '  temp   1    2    3    4    5    6    7    8    9    10   11   12'
    write(*,*)  '------------------------------------------------------------------'
    do i=MINVAL(TEMP),MAXVAL(TEMP),1
      do j=1,12,1
        if(tem(i,j) == 0) monthcount = monthcount+1
      end do
        if(monthcount == 12) then
          monthcount = 0
          cycle
        else
          monthcount = 0     
		  write(*,10) i,tem(i,1:12)
        end if
    end do

	
10  format(i5,12I5)
11  format(A)

end program homework2016