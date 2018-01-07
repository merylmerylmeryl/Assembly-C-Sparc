# proj08 Makefile
#
# Usage:  make -f proj08.makefile
#

proj08: proj08.driver.o proj08.support.o
	gcc -o proj08 proj08.driver.o proj08.support.o

proj08.driver.o: proj08.driver.c
	gcc -Wall -c proj08.driver.c

proj08.support.o: proj08.support.s
	gcc -Wall -c proj08.support.s
