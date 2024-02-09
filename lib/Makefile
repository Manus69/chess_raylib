cc = gcc
ar_tool = gcc-ar
flags_base = -Wall -Wextra 
flags_dbg = $(flags_base) -g3
flags_release = $(flags_base) -O3 -flto
flags = $(flags_dbg)

obj_dir = obj
src_dir = src

test_src = test.c
target_lib = libmy.a
target_test = _test

objs = $(addprefix $(obj_dir)/,$(subst .c,.o,$(notdir $(wildcard $(src_dir)/*.c))))

$(obj_dir)/%.o : $(src_dir)/%.c
	$(cc) $(flags) -c $^ -o $@

$(target_lib) : $(objs)
	$(ar_tool) -rcsv $(target_lib) $(objs)

$(target_test) : $(target_lib) $(test_src)
	$(cc) $(flags) $(test_src) -o $(target_test) $(target_lib)

.PHONY: lib test

all: lib

lib: $(target_lib)

test: lib $(target_test)

rm:
	rm $(objs)

re: rm all
