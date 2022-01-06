# Style
_END		:=	\033[0m
_BOLD		:=	\033[1m
_UNDER		:=	\033[4m
_REV		:=	\033[7m

# Colors
_GREY		:=	\033[30m
_RED		:=	\033[31m
_GREEN		:=	\033[32m
_YELLOW		:=	\033[33m
_BLUE		:=	\033[34m
_PURPLE		:=	\033[35m
_CYAN		:=	\033[36m
_WHITE		:=	\033[37m

CC := gcc

CFLAGS := -Wall -Wextra -Werror

PROJECT := libftprintf.a

HEADER_SRCS := includes/ft_printf.h

SRCS :=		ft_printf.c \
			ft_printf_put.c \
			ft_printf_put_hex.c

OBJS := $(addprefix objs/, $(SRCS:.c=.o))

OBJS_DIRS := $(sort $(dir $(OBJS)))

INCLUDE := $(addprefix -I,$(dir $(HEADER_SRCS)))

NAME := $(PROJECT)

all: $(NAME)

$(NAME): Makefile $(OBJS)
	@ar rcs $@ $(OBJS)
	@printf "%-30b%b" "\033[2K\r$(_GREEN)  ft_printf" "$(_BOLD)[OK]$(_END)\n"

$(OBJS): | $(OBJS_DIRS)

$(OBJS_DIRS):
	@mkdir -p $@
	@printf "%-30b%b" "\033[2K\r$(_GREEN)  ft_printf" "$(_CYAN)[$@ created]$(_END)\n"

objs/%.o: srcs/%.c $(HEADER_SRCS)
	@printf "%-30b%b" "\033[2K\r$(_YELLOW)  ft_printf:" "$(_BOLD)[$<]\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@printf "\033[2K\r$(_RED)ft_printf: All objects files have been deleted. $(_END)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "\033[2K\r$(_RED)ft_printf: '"$(NAME)"' has been deleted. $(_END)\n"

ffclean:
	@rm -rf $(OBJS_DIRS)
	@$(RM) $(NAME)
	@printf "\033[2K\r$(_RED)ft_printf: objs folder has been deleted. $(_END)\n"
	@printf "\033[2K\r$(_RED)ft_printf: '"$(NAME)"' has been deleted. $(_END)\n"

fcleaned:
	@rm -rf $(OBJS)
	@$(RM) $(NAME)
	@printf "\033[2K\r$(_RED)ft_printf: '"$(NAME)"' has been deleted. $(_END)\n"

re: fclean all

norme:
	@norminette

.PHONY: all clean fclean ffclean fcleaned re norme