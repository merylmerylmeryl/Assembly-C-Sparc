# proj04 Makefile
#
# Usage:  make -f mabinh1.makefile
#

proj04: proj04.driver.o proj04.support.o
	gcc -o proj04 proj04.driver.o proj04.support.o

proj04.driver.o: proj04.driver.c
	gcc -Wall -c proj04.driver.c

proj04.support.o: proj04.support.c
	gcc -Wall -c proj04.support.c
