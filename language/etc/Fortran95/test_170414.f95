PROGRAM test_170414
	
	IMPLICIT NONE
	INTEGER:: I
	REAL:: MONEY , RATE = 2.0 , SUM1 = 0, SUM2=0, SUM3=0 , sum4=0, sum5=0, sum6=0, sum7=0, sum8=0, sum9=0, sum10=0 , sum11= 0
	WRITE(*,*) 'ENTER MONEY(EX:1000000)'
    READ(*,*) MONEY

    SUM1 = MONEY;SUM2 = MONEY;SUM3 = MONEY;SUM4 = MONEY;SUM5 = MONEY;SUM6 = MONEY;SUM7 = MONEY;SUM8 = MONEY;SUM9 = MONEY
    SUM10 = MONEY;SUM11 = MONEY
    i=1
    DO I=1,10,1
 		sum1 = sum1 + SUM1*RATE/100; rate = rate+0.1
        sum2 = sum2 + SUM2*RATE/100; rate = rate+0.1
        sum3 = sum3 + SUM3*RATE/100; rate = rate+0.1
        sum4 = sum4 + SUM4*RATE/100; rate = rate+0.1
        sum5 = sum5 + SUM5*RATE/100; rate = rate+0.1
        sum6 = sum6 + SUM6*RATE/100; rate = rate+0.1
        sum7 = sum7 + SUM7*RATE/100; rate = rate+0.1
        sum8 = sum8 + SUM8*RATE/100; rate = rate+0.1
        sum9 = sum9 + SUM9*RATE/100; rate = rate+0.1
        sum10 = sum10 + SUM10*RATE/100; rate = rate+0.1
        sum11 = sum11 + SUM11*RATE/100; rate = rate+0.1
        write(*,*) '           2.0     2.1     2.2     2.3     2.4     2.5     2.6     2.7    2.8    2.9    2.10    2.11'
        WRITE(6,10) i,'years ago', SUM1,sum2,sum3,sum4,sum5,sum6,sum7,sum8,sum9,sum10,sum11
10		FORMAT(I2,A,F8.1,F8.1,F8.1,F8.1,F8.1,F8.1,F8.1,F8.1,F8.1,F8.1,F8.1)  
		rate = 2.0
    END DO
	WRITE(*,*) ''
    


    rate = rate + 0.1
    



END PROGRAM test_170414