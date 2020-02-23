program FreeForm
	IMPlICIT NONE
    REAL::a,b
    read(*,*) a,b  
    write(*,*) a, '+', b, '=', a+b
    write(*,*) a, '-', b, '=', a-b
    write(*,*) a, '*', b, '=', a*b
    write(*,*) a, '/', b, '=', a/b
    write(*,*)	'good game'
    

 10 FORMAT(6F5.1)

     
END	PROGRAM FreeForm