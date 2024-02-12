cc = gcc
flags = -Wall -Wextra -g3
flags_link = -lraylib -lm

obj_dir = ./obj
objs = $(addprefix $(obj_dir)/,$(subst .c,.o,$(wildcard *.c)))

$(obj_dir)/%.o : %.c
	$(cc) $(flags) -c $^ -o $@ $(flags_link)

all : $(objs)

rm:
	rm -f $(wildcard $(obj_dir)/*.o)

re: rm all