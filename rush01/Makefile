#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/02 23:38:40 by istalevs          #+#    #+#              #
#    Updated: 2018/10/02 23:38:43 by istalevs         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all clean fclean re

NAME		=	ft_gkrellm
CC			=	clang++
FLG			=	-Wall -Wextra -Werror

SRCDIR		=	./src/
INCDIR		=	./includes/
OBJDIR		=	./obj/

HEADERS     =   Cor.hpp CpuUsageModule.hpp DisksModule.hpp FactoryMethod.hpp IMonitorDisplay.hpp \
                IMonitorModule.hpp main.hpp NcursesDisplay.hpp NetworksModule.hpp OSHostModule.hpp \
                PhysMemModule.hpp SDLDisplay.hpp TimeDateModule.hpp VirtualMemModule.hpp ZazModule.hpp

SRC			=	Cor.cpp CpuUsageModule.cpp DisksModule.cpp FactoryMethod.cpp main.cpp \
				NcursesDisplay.cpp NetworksModule.cpp OSHostModule.cpp PhysMemModule.cpp \
				SDLDisplay.cpp TimeDateModule.cpp VirtualMemModule.cpp ZazModule.cpp

OBJ			=	$(addprefix $(OBJDIR),$(SRC:.cpp=.o))

HEAD        =   $(addprefix $(INCDIR),$(HEADERS))

#SDL frameworks
SD			=	./SDL
INCLUDES	=	-I $(SD)/SDL2.framework/Headers \
				-I $(SD)/SDL2_image.framework/Headers \
				-I $(SD)/SDL2_ttf.framework/Headers \

FRAMEWORKS	=	-F $(SD) -rpath $(SD) \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image

all: obj $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.cpp $(HEAD)
	@$(CC) $(FLG) $(INCLUDES) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(INCLUDES) $(FRAMEWORKS) -lncurses -o $(NAME)
	@printf "RUSH:  %-25s$(C_GREEN)[done]$(C_NONE)\n" "$(NAME)"

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
