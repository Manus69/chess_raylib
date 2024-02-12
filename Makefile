cc = gcc
flags_base = -Wall -Wextra
flags_dbg = $(flags_base) -g3
l_flags = -lraylib -lm
game_dir = ./game
lib_dir = ./lib
gui_dir = ./gui
game_obj_dir = $(game_dir)/obj
gui_obj_dir = $(gui_dir)/obj

obj = $(wildcard $(game_obj_dir)/*.o) $(wildcard $(gui_obj_dir)/*.o)
main = main.c
target = _chess
lib = $(lib_dir)/libmy.a

.PHONY: build_game build_lib $(target)

all: flags = $(flags_dbg)
all: build_game build_lib build_gui $(target)

$(target) : $(main)
	$(cc) $(flags) $(main) $(obj) $(lib) -o $(target) $(l_flags)

build_game:
	make flags="$(flags)" -C $(game_dir)

build_lib:
	make flags="$(flags)" -C $(lib_dir)

build_gui:
	make flags="$(flags)" -C $(gui_dir)

rm:
	make rm -C $(game_dir)
	make rm -C $(gui_dir)

re: rm all