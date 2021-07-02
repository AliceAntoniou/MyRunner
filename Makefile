##
## EPITECH PROJECT, 2020
## make file
## File description:
## compile all the files
##

FILE	=	game/game.c						\
			game/system_fonctions.c			\
			game/move_sprite.c				\
			game/render_map.c				\
			game/pause.c					\
			game/move_mobs.c				\
			initialisation/free_all.c		\
			initialisation/create_lvl.c		\
			initialisation/lvl_sprites.c	\
			initialisation/sprite_creator.c	\
			initialisation/init_structs.c	\
			initialisation/reset.c			\
			initialisation/create_mob.c		\
			player/calc_hibox.c				\
			player/init_player.c			\
			player/move_player.c			\
			player/player_physics.c			\
			player/player_rotation.c		\
			menu/menu.c						\
			menu/init_all.c					\
			menu/choose_levels.c

all:    lib
		cd lib/my && make
		gcc -o my_runner $(FILE) $(NORMAL) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm -L lib -lmy

run:
		gcc -o my_runner $(FILE) $(NORMAL) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm -L lib -lmy
		./my_runner

g:
		gcc -o my_runner $(FILE) $(NORMAL) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm -L lib -lmy -g

valgrind: g
		valgrind ./my_runner
clean:
		rm -f *.o

fclean:	clean
		rm -f my_runner
		cd lib/my && make fclean
		rm -f lib/libmy.a
		rm -f my_runner

re:		fclean all