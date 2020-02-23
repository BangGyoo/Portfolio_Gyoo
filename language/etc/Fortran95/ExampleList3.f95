PROGRAM ExampleList3

	IMPLICIT NONE

    INTEGER :: score

 

	do
    	READ(*,*) score
    	IF(score>=0 .AND. score<=100) exit
    end do

	if(100>=score .AND. 90 <=score) write(*,*) 'a'
	if(90>score .AND. 80 <=score) write(*,*) 'b'
	if(80>score .AND. 70 <=score) write(*,*) 'c'
	if(70>score .AND. 60 <=score) write(*,*) 'd'
	if(60>score .AND. 0 <=score) write(*,*) 'f'   
	write(*,*) ' '

    !/////////////////////////////////////////////////////////

    IF(100>=score .AND. 90 <= score) then
      write(*,*) 'a'
    else if(80 <= score) then
      write(*,*) 'b'
    else if(70 <= score) then
      write(*,*) 'c'
    else if(60 <= score) then
      write(*,*) 'd'
    else
      write(*,*) 'f'
    end if

    write(*,*) ' '
    !//////////////////////////////////////////////////////////

	SELECT CASE(score) 
      case(90:100)
        write(*,*) 'a'
      case(80:89)
        write(*,*) 'b'
      case(70:79)
        write(*,*) 'c'
      case(60:69)
        write(*,*) 'd'
      case default
        write(*,*) 'f'
    end select

end program ExampleList3