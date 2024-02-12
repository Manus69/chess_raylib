cc = gcc
flags = -Wall -Wextra -g
obj_dir = ./obj
headers = $(wildcard *.h)
src = $(wildcard *.c)
objs = $(addprefix $(obj_dir)/,$(src:.c=.o))
lib = ../lib/libmy.a

$(obj_dir)/%.o : %.c $(headers)
	$(cc) $(flags) -c $< -o $@

all: $(objs)

rm:
	rm -f $(obj_dir)/*

re: rm all	
