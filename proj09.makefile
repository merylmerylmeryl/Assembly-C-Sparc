# proj09 Makefile
#
# Usage:  make -f proj09.makefile
#

proj09: /user/cse320/Projects/project09.driver.o proj09.support.o
	gcc -o proj09 /user/cse320/Projects/project09.driver.o proj09.support.o

proj09.support.o: proj09.support.s
	gcc -Wall -c proj09.support.s
