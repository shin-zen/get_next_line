# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skodama <skodama@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 22:51:49 by skodama           #+#    #+#              #
#    Updated: 2020/12/31 11:51:37 by skodama          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# change INCDIR and SRCDIR
# type "make test" and type something, check io
# type "make test_BONUS
# type "make leaks"

NAME	= ${SRCDIR}/a.out
CFLAGS	= -Wall -Wextra -Werror -g -I ${INCDIR}
RM		= rm -f

# path
INCDIR	= ../
SRCDIR	= ../
SRC		= ${addprefix ${SRCDIR}/, get_next_line.c get_next_line_utils.c} main.c
OBJ		= ${SRC:%.c=%.o}
SRC_BO	= ${addprefix ${SRCDIR}/, get_next_line_bonus.c get_next_line_utils_bonus.c} main_ret.c
OBJ_BO	= ${SRC_BO:%.c=%.o}

TESTDIR	= ./test
ODIR	= ./out
CDIR	= ./correct


# compile
all: ${NAME}

OBJ:
	gcc ${CFLAGS} -c $<

OBJ_BO:
	gcc ${CFLAGS} -c $<

ret:
	gcc ${CFLAGS} -c main_ret.c -o main_ret.o

${NAME}: ${OBJ}
	gcc ${CFLAGS} -o $@ ${OBJ}
	@echo "\`gnl\` [INFO] Complied"

BONUS: ${OBJ_BO}
	gcc ${CFLAGS} -o ${NAME} ${OBJ_BO}

leaks: ${OBJ}
	gcc ${CFLAGS} -o ${NAME} ${OBJ} -fsanitize=address
	@${NAME} ${TESTDIR}/test1.txt

val:
	valgrind --leak-check=full ${NAME} ${TESTDIR}/test1.txt



# test
run:
	@${SRCDIR}/gnl

test_all: test BONUS test_leak

test: test1 test2 test3 test4 test5 test6 test7 test8

test1: ${NAME}
	@echo __________________________________________________________
	@echo test1
	@gcc ${CFLAGS} -o ${NAME} main.o ${SRCDIR}/get_next_line.o ${SRCDIR}/get_next_line_utils.o
	@${NAME} ${TESTDIR}/test1.txt
	@echo
	@echo
test_short_line: ${NAME}
	@echo __________________________________________________________
	@echo test_short_line_________________________________________________________
	@${NAME} ${TESTDIR}/test_short_line.txt > ${ODIR}/out3.txt
	diff ${TESTDIR}/test_short_line.txt ${ODIR}/out3.txt
	@echo
	@echo


test_BUFFER_SIZE_1:
	@echo __________________________________________________________
	@echo test_BUFFER_SIZE_1
	@gcc ${CFLAGS} -D BUFFER_SIZE=1 ${SRCDIR}/get_next_line.c ${SRCDIR}/get_next_line_utils.c main.c -o ${NAME}
	@${NAME} ${TESTDIR}/test1.txt > ${ODIR}/out_buff1.txt
	diff ${TESTDIR}/test1.txt ${ODIR}/out_buff1.txt
	@echo
	@echo

test_BUFFER_SIZE_1025:
	@echo __________________________________________________________
	@echo test_BUFFER_SIZE_1025
	@gcc ${CFLAGS} -D BUFFER_SIZE=1025 ${SRCDIR}/get_next_line.c ${SRCDIR}/get_next_line_utils.c main.c -o ${NAME}
	@${NAME} ${TESTDIR}/test1.txt > ${ODIR}/out_buff1025.txt
	diff ${TESTDIR}/test1.txt ${ODIR}/out_buff1025.txt
	@echo
	@echo

test_BUFFER_SIZE_1000000000:
	@echo __________________________________________________________
	@echo test_BUFFER_SIZE_1000000000
	@gcc ${CFLAGS} -D BUFFER_SIZE=1000000000 ${SRCDIR}/get_next_line.c ${SRCDIR}/get_next_line_utils.c main.c -o ${NAME}
	@${NAME} ${TESTDIR}/test1.txt > ${ODIR}/out_buff1000000000.txt
	diff ${TESTDIR}/test1.txt ${ODIR}/out_buff1000000000.txt
	@echo
	@echo

test_ret: ret
	@echo __________________________________________________________
	@echo test_ret
	@gcc ${CFLAGS} -o ${NAME} main_ret.o ${SRCDIR}/get_next_line.o ${SRCDIR}/get_next_line_utils.o
	@${NAME} ${TESTDIR}/test1.txt > ${ODIR}/out_ret.txt
	diff ${CDIR}/correct_ret.txt ${ODIR}/out_ret.txt
	@echo
	@echo
	@echo __________________________________________________________


test2:
	@echo __________________________________________________________
	@echo test2
	@${NAME} ${TESTDIR}/without_line_breaks_1.txt
	@echo
	@echo
	@echo __________________________________________________________

test3: ${NAME}
	@echo __________________________________________________________
	@echo test_nothing
	@${NAME} ${TESTDIR}/test_nothing.txt
	@echo
	@echo

test4: ${NAME}
	@echo __________________________________________________________
	@echo test_long_line
	@${NAME} ${TESTDIR}/test_long_line.txt
	@echo
	@echo

test5: ${NAME}
	@echo __________________________________________________________
	@echo normal
	@${NAME} ${TESTDIR}/normal.txt
	@echo
	@echo

test6: ${NAME}
	@echo __________________________________________________________
	@echo only_newline
	@${NAME} ${TESTDIR}/only_newline.txt
	@echo
	@echo

test7: ${NAME}
	@echo __________________________________________________________
	@echo fewchar
	@${NAME} ${TESTDIR}/fewchar_perline.txt
	@echo
	@echo

test8: ${NAME}
	@echo __________________________________________________________
	@echo 64bit_paragraph
	@${NAME} ${TESTDIR}/64bit_paragraph.txt
	@echo
	@echo

# ここからがメイン

BONUS: test_B1 test_B2 test_B3 test_files

test_B0: ${OBJ_BO}
	@echo __________________________________________________________
	@echo test_B1
	@gcc ${CFLAGS} -o ${NAME} ${OBJ_BO}
	@${NAME} ${TESTDIR}/test1.txt ${TESTDIR}/test

test_B1: ${OBJ_BO}
	@echo __________________________________________________________
	@echo test_B1
	@gcc ${CFLAGS} -o ${NAME} ${OBJ_BO}
	@${NAME} ${TESTDIR}/test1.txt ${TESTDIR}/test2.txt

test_B2: ${OBJ_BO}
	@echo __________________________________________________________
	@echo test_B2
	@gcc ${CFLAGS} -o ${NAME} ${OBJ_BO}
	@${NAME} ${TESTDIR}/test_nothing.txt ${TESTDIR}/test2.txt

test_B3: ${OBJ_BO}
	@echo __________________________________________________________
	@echo test_B3
	@gcc ${CFLAGS} -o ${NAME} ${OBJ_BO}
	@${NAME} ${TESTDIR}/test1.txt ${TESTDIR}/without_line_breaks_1.txt

test_B4: ${OBJ_BO}
	@echo __________________________________________________________
	@echo test_B4
	@gcc main_seg.c ../get_next_line_bonus.c ../get_next_line_utils_bonus.c ${CFLAGS} -o ${NAME}
	@${NAME} ${TESTDIR}/test1.txt ${TESTDIR}/without_line_breaks_1.txt

test_files: ${OBJ_BO}
	@echo __________________________________________________________
	@echo test_files
	@gcc ${CFLAGS} -c main_files.c -o main_files.o
	@gcc ${CFLAGS} -o ${NAME} main_files.o ${SRCDIR}/get_next_line_bonus.o ${SRCDIR}/get_next_line_utils_bonus.o
	@${NAME} ${TESTDIR}/files/no*.txt
	@echo
	@echo

#memory leak
test_leak : test_leak0 test_leak1 test_leak2 test_leak3 test_leak4
# mandatory

test_leak0: ${OBJ}
	@echo __________________________________________________________
	@echo test_files
	@gcc ${CFLAGS} -o ${NAME} main.o ${SRCDIR}/get_next_line.o ${SRCDIR}/get_next_line_utils.o
	@valgrind --leak-check=full --show-leak-kinds=all -s ${NAME} ${TESTDIR}/test_nothing.txt
	@echo
	@echo

test_leak1: ${OBJ}
	@echo __________________________________________________________
	@echo test_files
	@gcc ${CFLAGS} -o ${NAME} main.o ${SRCDIR}/get_next_line.o ${SRCDIR}/get_next_line_utils.o
	@valgrind --leak-check=full --show-leak-kinds=all -s ${NAME} ${TESTDIR}/test1.txt
	@echo
	@echo


test_leak2: ${OBJ}
	@echo __________________________________________________________
	@echo test_files
	@gcc ${CFLAGS} -o ${NAME} main.o ${SRCDIR}/get_next_line.o ${SRCDIR}/get_next_line_utils.o
	@valgrind --leak-check=full --show-leak-kinds=all -s ${NAME} ${TESTDIR}/without_line_breaks_1.txt
	@echo
	@echo

test_leak3: ${OBJ}
	@echo __________________________________________________________
	@echo test_files
	@gcc ${CFLAGS} -o ${NAME} main.o ${SRCDIR}/get_next_line.o ${SRCDIR}/get_next_line_utils.o
	@valgrind --leak-check=full --show-leak-kinds=all  -s ${NAME} ${TESTDIR}/test_nothing.txt
	@echo
	@echo

# bonus
test_leak4: ${OBJ_BO}
	@echo __________________________________________________________
	@echo test_files
	@gcc ${CFLAGS} -o ${NAME} main_ret.o ${SRCDIR}/get_next_line_bonus.o ${SRCDIR}/get_next_line_utils_bonus.o
	@valgrind --leak-check=full --show-leak-kinds=all  -s ${NAME} ${TESTDIR}/test1.txt ${TESTDIR}/test2.txt
	@echo
	@echo

test_leak5: ${OBJ_BO}
	@echo __________________________________________________________
	@echo test_files
	@gcc ${CFLAGS} -c main_files.c -o main_files.o
	@gcc ${CFLAGS} -o ${NAME} main_files.o ${SRCDIR}/get_next_line_bonus.o ${SRCDIR}/get_next_line_utils_bonus.o
	@valgrind --leak-check=full --show-leak-kinds=all -s ${NAME} ${TESTDIR}/files/no*.txt
	@echo
	@echo
# Error
test_e1: ${OBJ}
	@echo __________________________________________________________
	@echo nofile
	@gcc ${CFLAGS} -o ${NAME} main.o ${SRCDIR}/get_next_line.o ${SRCDIR}/get_next_line_utils.o
	@@valgrind --leak-check=full --show-leak-kinds=all  -s ${NAME} ${TESTDIR}/test_nofile.txt
	@echo
	@echo

# new test
t1:
	@clear
	@echo fd error check fd=42
	@echo you should do error handling and free after read bufs
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_fd_error.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_fd_error.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_fd_error.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_fd_error.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_fd_error.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc -Wno-format -I ${INCDIR} -g -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_fd_error.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out

t2:
	@clear
	@echo fd error check fd=5000
	@echo you should do error handling and free after read bufs
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_fd_error2.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_fd_error2.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_fd_error2.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_fd_error2.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_fd_error2.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_fd_error2.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out

t3:
	@clear
	@echo stdio check
	@echo you should do free saved_line/static
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_stdio.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_stdio.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_stdio.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_stdio.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_stdio.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_stdio.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out

t4:
	@clear
	@echo test2 check
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/empty.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/empty.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/empty.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/empty.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/empty.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/empty.txt

t5:
	@clear
	@echo without_line_breaks_1 check
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/without_line_breaks_1.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/without_line_breaks_1.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/without_line_breaks_1.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/without_line_breaks_1.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/without_line_breaks_1.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/without_line_breaks_1.txt

t6:
	@clear
	@echo test2 check
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/test2.txt

t7:
	@clear
	@echo test_long_line check
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/test_long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/test_long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/test_long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/test_long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/test_long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/test_long_line.txt

tb1:
	@clear
	@echo test1 check
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/test1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/test1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/test1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/test1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/test1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/test1.txt ${TESTDIR}/test2.txt

tb2:
	@clear
	@echo test1 check
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/empty.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/empty.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/empty.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/empty.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/empty.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/empty.txt ${TESTDIR}/test2.txt

tb3:
	@clear
	@echo test1 check
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/without_line_breaks_1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/without_line_breaks_1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/without_line_breaks_1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/without_line_breaks_1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/without_line_breaks_1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/without_line_breaks_1.txt ${TESTDIR}/test2.txt

tb4:
	@clear
	@echo test1 check
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/long_line.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/long_line.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/long_line.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/long_line.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/long_line.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/long_line.txt ${TESTDIR}/test2.txt

tb5:
	@clear
	@echo test1 check
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_io_file.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_io_file.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_io_file.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_io_file.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_io_file.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_io_file.c
	@valgrind --leak-check=full --show-leak-kinds=all -s ./a.out ${TESTDIR}/long_line.txt

# for guacamole
tg1:
	@clear
	@echo fd error check fd=42
	@echo you should do error handling and free after read bufs
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_fd_error.c
	@./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_fd_error.c
	@./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_fd_error.c
	@./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_fd_error.c
	@./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_fd_error.c
	@./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc -Wno-format -I ${INCDIR} -g -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_fd_error.c
	@./a.out

tg2:
	@clear
	@echo fd error check fd=5000
	@echo you should do error handling and free after read bufs
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_fd_error2.c
	@./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_fd_error2.c
	@./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_fd_error2.c
	@./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_fd_error2.c
	@./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_fd_error2.c
	@./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_fd_error2.c
	@./a.out

tg3:
	@clear
	@echo stdio check
	@echo you should do free saved_line/static
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_stdio.c
	@./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_stdio.c
	@./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_stdio.c
	@./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_stdio.c
	@./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_stdio.c
	@./a.out
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_stdio.c
	@./a.out

tg4:
	@clear
	@echo test2 check
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/empty.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/empty.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/empty.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/empty.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/empty.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/empty.txt

tg5:
	@clear
	@echo without_line_breaks_1 check
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/without_line_breaks_1.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/without_line_breaks_1.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/without_line_breaks_1.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/without_line_breaks_1.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/without_line_breaks_1.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/without_line_breaks_1.txt

tg6:
	@clear
	@echo test2 check
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/test2.txt

tg7:
	@clear
	@echo test_long_line check
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/test_long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/test_long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/test_long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/test_long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/test_long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_s.c
	@./a.out ${TESTDIR}/test_long_line.txt

tgb1:
	@clear
	@echo test1 check
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/test1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/test1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/test1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/test1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/test1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/test1.txt ${TESTDIR}/test2.txt

tgb2:
	@clear
	@echo test1 check
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/empty.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/empty.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/empty.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/empty.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/empty.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/empty.txt ${TESTDIR}/test2.txt

tgb3:
	@clear
	@echo test1 check
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/without_line_breaks_1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/without_line_breaks_1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/without_line_breaks_1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/without_line_breaks_1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/without_line_breaks_1.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/without_line_breaks_1.txt ${TESTDIR}/test2.txt

tgb4:
	@clear
	@echo test1 check
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/long_line.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/long_line.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/long_line.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/long_line.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/long_line.txt ${TESTDIR}/test2.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_seg.c
	@./a.out ${TESTDIR}/long_line.txt ${TESTDIR}/test2.txt

tgb5:
	@clear
	@echo test1 check
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_io_file.c
	@./a.out ${TESTDIR}/long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1025
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1025 ../get_next_line.c ../get_next_line_utils.c main_io_file.c
	@./a.out ${TESTDIR}/long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=1023
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=1023 ../get_next_line.c ../get_next_line_utils.c main_io_file.c
	@./a.out ${TESTDIR}/long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483647
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483647 ../get_next_line.c ../get_next_line_utils.c main_io_file.c
	@./a.out ${TESTDIR}/long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=2147483648 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=2147483648 ../get_next_line.c ../get_next_line_utils.c main_io_file.c
	@./a.out ${TESTDIR}/long_line.txt
	@echo ________________________________________________________________________________________
	@echo BUFFER_SIZE=-100 error
	@gcc ${CFLAGS} -fsanitize=address -D BUFFER_SIZE=-100 ../get_next_line.c ../get_next_line_utils.c main_io_file.c
	@./a.out ${TESTDIR}/long_line.txt


clean:
	${RM} ${OBJ} ${OBJ_BO} main_ret.o main_files.o
	@echo "\`gnl\` [INFO] Object files removed"

fclean: clean
	${RM} ${NAME}
	@echo "\`gnl\` [INFO] Executable removed"

re: fclean all

.PHONY: clean fclean re all test test_BONUS test1
