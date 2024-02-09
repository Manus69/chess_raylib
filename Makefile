cc = gcc
flags_base = -Wall -Wextra
flags_dbg = $(flags_base) -g3
l_flags = -lm -lraylib
game_dir = ./game
lib_dir = ./lib
obj_dir = ./obj

obj = $(wildcard $(obj_dir)/*.o)
main = main.c
target = _chess
lib = $(lib_dir)/libmy.a

.PHONY: build_game build_lib $(target)

all: flags = $(flags_dbg)
all: build_game build_lib $(target)

$(target) : $(main)
	$(cc) $(flags) $(main) $(obj) $(lib) -o $(target) $(l_flags)

build_game:
	make flags="$(flags)" -C $(game_dir)

build_lib:
	make flags="$(flags)" -C $(lib_dir)

rm:
	make rm -C $(game_dir)

re: rm all