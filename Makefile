NAME = cub3D
NAME_BONUS = cub3D_bonus

SRC = 	main.c \
		srcs/mandatory/parsing/parsing_main.c srcs/mandatory/parsing/checkmap_newline.c srcs/mandatory/parsing/checkmap_closed.c srcs/mandatory/parsing/checkmap_init.c srcs/mandatory/parsing/checkmap.c srcs/mandatory/parsing/check_elems.c srcs/mandatory/parsing/check_elems2.c srcs/mandatory/parsing/get_elems.c srcs/mandatory/parsing/print_cubeinfos.c srcs/mandatory/parsing/free.c \
		srcs/mandatory/visual/visual_main.c srcs/mandatory/visual/hooks.c srcs/mandatory/visual/image.c srcs/mandatory/visual/window.c srcs/mandatory/visual/display2d.c srcs/mandatory/visual/display3d.c srcs/mandatory/visual/display_walls3d.c srcs/mandatory/visual/display_rays.c srcs/mandatory/visual/display_utils.c srcs/mandatory/visual/move.c srcs/mandatory/visual/fps_mouse.c srcs/mandatory/visual/init.c

SRC_BONUS = 	main_bonus.c \
		srcs/bonus/parsing/parsing_main_bonus.c srcs/bonus/parsing/checkmap_newline_bonus.c srcs/bonus/parsing/checkmap_closed_bonus.c srcs/bonus/parsing/checkmap_init_bonus.c srcs/bonus/parsing/checkmap_bonus.c srcs/bonus/parsing/check_elems_bonus.c srcs/bonus/parsing/get_elems_bonus.c srcs/bonus/parsing/check_elems2_bonus.c srcs/bonus/parsing/print_cubeinfos_bonus.c srcs/bonus/parsing/free_bonus.c \
		srcs/bonus/visual/visual_main_bonus.c srcs/bonus/visual/hooks_bonus.c srcs/bonus/visual/image_bonus.c srcs/bonus/visual/window_bonus.c srcs/bonus/visual/display2d_bonus.c srcs/bonus/visual/display3d_bonus.c srcs/bonus/visual/display_walls3d_bonus.c srcs/bonus/visual/display_rays_bonus.c srcs/bonus/visual/display_utils_bonus.c srcs/bonus/visual/move_bonus.c srcs/bonus/visual/fps_mouse_bonus.c srcs/bonus/visual/init_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJSDIR	= objs/
OBJSDIR_BONUS	= objs_bonus/
OBJS = $(addprefix $(OBJSDIR), $(OBJ))
OBJS_BONUS = $(addprefix $(OBJSDIR_BONUS), $(OBJ_BONUS))

FLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

LINKS = libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -Imlx -L./mlx

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: maker $(NAME)
bonus : maker $(NAME_BONUS)
$(OBJSDIR)%.o : %.c hdrs/cub3d.h libft/libft.a Makefile
	@mkdir -p $(OBJSDIR)
	@mkdir -p $(OBJSDIR)srcs
	@mkdir -p $(OBJSDIR)srcs/mandatory
	@mkdir -p $(OBJSDIR)srcs/mandatory/parsing
	@mkdir -p $(OBJSDIR)srcs/mandatory/visual
	@gcc $(FLAGS) -c $< -o $@
	@echo $(CURSIVE)$(GRAY) "     - creating .o ..." $(NONE)

$(OBJSDIR_BONUS)%.o : %.c hdrs/cub3d.h libft/libft.a Makefile
	@mkdir -p $(OBJSDIR_BONUS)
	@mkdir -p $(OBJSDIR_BONUS)srcs
	@mkdir -p $(OBJSDIR_BONUS)srcs/bonus
	@mkdir -p $(OBJSDIR_BONUS)srcs/bonus/parsing
	@mkdir -p $(OBJSDIR_BONUS)srcs/bonus/visual
	@gcc $(FLAGS) -c $< -o $@
	@echo $(CURSIVE)$(GRAY) "     - creating .o ..." $(NONE)

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJS) $(LINKS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

$(NAME_BONUS): $(OBJS_BONUS)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME_BONUS)..." $(NONE)
	@gcc $(FLAGS) $(OBJS_BONUS) $(LINKS) -o $(NAME_BONUS)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

maker:
		@make -C libft

exe: all
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n     - Done -"

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@make clean -C libft
	@rm -rf $(OBJ)
	@rm -rf $(OBJSDIR)

clean_bonus:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@make clean -C libft
	@rm -rf $(OBJ_BONUS)
	@rm -rf $(OBJSDIR_BONUS)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@rm -rf libft/libft.a

fclean_bonus: clean_bonus
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME_BONUS)..." $(NONE)
	@rm -rf $(NAME_BONUS)
	@rm -rf libft/libft.a


re: fclean all 

.phony: re fclean all clean exe maker fclean_bonus clean_bonus bonus