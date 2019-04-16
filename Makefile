NAME = ft_gkrellm

SRCS = Cpuu.cpp Cpui.cpp Data.cpp \
		Lan.cpp OSi.cpp User.cpp\
		Ponny.cpp Ramu.cpp main_viso.cpp\
		ConsoleMonitor.cpp GraphicalMonitor.cpp

HDRS = Cpuu.hpp Cpui.hpp Data.hpp \
		IMonitorModule.hpp Lan.hpp OSi.hpp\
		Ponny.hpp Ramu.hpp User.hpp\
		mlx.h ConsoleMonitor.hpp GraphicalMonitor.hpp\
		IMonitorDisplay.hpp
MLX =	-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

OBJECTS = $(SRCS:.cpp=.o)

FLAGS =  -Wall -Werror -Wextra

CC = clang++

all: $(NAME)

$(NAME): $(OBJECTS) $(HDRS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)  -lncurses $(MLX)
%.o: %.cpp
	@$(CC) $(FLAGS) -c $<
clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)	

re: fclean all

.PHONY: re all clean fclean