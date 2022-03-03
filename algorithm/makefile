
CC = g++  # use g++ compiler

FLAGS = -std=c++17  # compile with C++ 17 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -I.. -I.     # compile with parent directory on #include system path

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files


quicksort : src/quicksort.cc inc/quicksort.h
	$(LINK) $@ $<

test : quicksort
	@./quicksort


clean:
	@rm -f quicksort \
	@rm -f output.txt