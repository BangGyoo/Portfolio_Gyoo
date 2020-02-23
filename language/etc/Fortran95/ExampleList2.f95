PROGRAM ExampleList2

	IMPLICIT NONE

	INTEGER :: N,i, number ,even=0, odd=0,manus=0, zero=0, plus=0, month, score

    READ(*,*) N
    i = 0
    DO
      READ(*,*) number
      IF(MOD(number,2) ==0) then
        even = even + 1
      else
        odd  = odd  + 1
      end if
      
	  IF(number > 0) then
        plus = plus + 1
      else if(number ==0) then
        zero = zero + 1
      else
        manus = manus + 1
      end if
    
	  i = i + 1
      IF(I==N) EXIT
    end do

    WRITE(6,10) ' EVEN =' , even , ' ODD =' , odd , ' manus =' , manus , ' zero =', zero, ' plus =', plus
10  format(A,i2,A,I2,A,I2,A,I2,A,I2)

	read(*,*) month

    select case(month)
      case(1,2,12)
        write(*,*) 'winter'
      case(3,4,5)
      	write(*,*) 'spring'
      case(6,7,8)
      	write(*,*) 'summer'
      case(9,10,11)
    end select
	


END PROGRAM ExampleList2