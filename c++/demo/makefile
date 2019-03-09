DIRS = 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

c = gcc 
cc = g++ 
prom = test
source = test.cc account.cpp Date.cpp 
deps = stdafx.h
obj = test.o account.o Date.o 


$(prom) : $(obj)
	$(cc) -o $(prom) $(obj)
##$(prom) : $(source)
##	$(cc) -o $(prom) $(source) 

test.o : test.cc $(deps)
	$(cc) -c test.cc
account.o : account.cpp $(deps)
	$(cc) -c account.cpp
Date.o : DAte.cpp $(deps)
	$(cc) -c Date.cpp
## %.o : %.c $(deps)
##    $(cc) -c $<-o $@





all:  
	cd 1; make 
	cd 2; make 
	cd 3; make 
	cd 4; make 
	cd 5; make 
	cd 6; make
	cd 7; make 
	cd 8; make 
	cd 9; make
	cd 10; make
	cd 11; make
	cd 12; make
	cd 13; make 
	cd 14; make 
	cd 15; make 
	cd 16; make 
	cd 17; make 
	cd 18; make 
	cd 19; make

clean: 
	cd 1; make clean 
	cd 2; make clean 
	cd 3; make clean 
	cd 4; make clean 
	cd 5; make clean 
	cd 6; make clean 
	cd 7; make clean 
	cd 8; make clean 
	cd 9; make clean
	cd 10; make clean
	cd 11; make clean
	cd 12; make clean
	cd 13; make clean 
	cd 14; make clean 
	cd 15; make clean 
	cd 16; make clean 
	cd 17; make clean 
	cd 18; make clean 
	cd 19; make clean
	rm -rf $(obj) $(prom)

clobber: 
	cd 1; make clobber 
	cd 2; make clobber 
	cd 3; make clobber 
	cd 4; make clobber 
	cd 5; make clobber 
	cd 6; make clobber 
	cd 7; make clobber 
	cd 8; make clobber 
	cd 9; make clobber
	cd 10; make clobber
	cd 11; make clobber
	cd 12; make clobber
	cd 13; make clobber 
	cd 14; make clobber 
	cd 15; make clobber 
	cd 16; make clobber 
	cd 17; make clobber 
	cd 18; make clobber 
	cd 19; make clobber

