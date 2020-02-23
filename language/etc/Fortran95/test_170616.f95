PROGRAM test_170616
	IMPLICIT NONE
	REAL, DIMENSION(3,3) :: m1,m2,hap,cha,gop
	INTEGER:: i,j

    call read_matrix(m1,m2,i,j)
	call  HapChaGop(m1,m2,hap,cha,gop)
    call write_matrix(m1,m2,hap,cha,gop,i,j)


    
END PROGRAM test_170616
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	subroutine read_matrix(m1,m2,i,j)
		REAL, DIMENSION(3,3) :: m1,m2
		INTEGER:: i,j
 	 	write(*,*) 'ENTER MATRIX1 (3X3)...'; READ(*,*) m1; write(*,*) ' '
		write(*,*) 'ENTER MATRIX2 (3X3)...'; READ(*,*) m2; write(*,*) ' '
		write(6,3) ((m1(i,j),j=1,3),i=1,3); write(*,*) ' '
   		write(6,3) ((m2(i,j),j=1,3),i=1,3); write(*,*) ' '
3  		format(3F5.1)
	end subroutine read_matrix

	subroutine HapChaGop(m1,m2,hap,cha,gop)
		REAL, DIMENSION(3,3) :: m1,m2,hap,cha,gop	
	   	hap = m1 + m2
        cha = m1 - m2
        gop = MATMUL(M1,M2)
	end subroutine HapChaGop    

	subroutine write_matrix(m1,m2,hap,cha,gop,i,j)
		REAL, DIMENSION(3,3) :: m1,m2,hap,cha,gop
		INTEGER:: i,j	
		write(6,3) ((m1(i,j),j=1,3),i=1,3); write(*,*) ' '
   		write(6,3) ((m2(i,j),j=1,3),i=1,3); write(*,*) ' '
		write(6,3) ((hap(i,j),j=1,3),i=1,3); write(*,*) ' '
   		write(6,3) ((cha(i,j),j=1,3),i=1,3); write(*,*) ' '
		write(6,3) ((gop(i,j),j=1,3),i=1,3); write(*,*) ' '
3  		format(3F5.1)
	end subroutine write_matrix       