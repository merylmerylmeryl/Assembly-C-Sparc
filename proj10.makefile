# proj10 Makefile
#
# Usage:  make -f proj10.makefile
#

proj10: proj10.driver.o proj10.support.o /user/cse320/lib/reglib.o
	gcc -o proj10 proj10.driver.o proj10.support.o /user/cse320/lib/reglib.o

proj10.driver.o: proj10.driver.c
	gcc -Wall -c proj10.driver.c

proj10.support.o: proj10.support.s
	gcc -Wall -c proj10.support.s
