PROGRAM test_test

	IMPLICIT NONE	

    REAL:: a,b,c,d

    WRITE(*,*) 'Enter a,b,c'
	READ(*,*) a,b,c

	d =  (b**2)-(4*a*c)

    select case(D<0)
    	case (.true.)
      		WRITE(*,*) 'imaginary roots'
    	case (.false.)
        	select case(D==0)
                case (.true.)
     				write(*,*) 'root : ' , -b/2*a
                case (.false.)
     				write(*,*) 'root-1 : ' , ((-b + sqrt(d))/(2*a))
      				write(*,*) 'root-2 : ' , ((-b - sqrt(d))/(2*a))
            end select
    end select

END PROGRAM test_test