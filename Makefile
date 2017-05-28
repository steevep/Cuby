##
## Makefile for  in /home/costardrouge
##
## Made by steeve pommier
## Login   <costardrouge@epitech.net>
##
## Started on  Mon Mar 12 12:12:36 2012 steeve pommier
## Last update Sun Apr 15 15:01:27 2012 steeve pommier
##

NAME_EXE	=	cuby

SRC_EXE		=	AObject.cpp  		\
				Block.cpp   		\
				Cuby.cpp        	\
				Exception.cpp		\
				Ressources.cpp  	\
				SDLDisplay.cpp  	\
				ASection.cpp  		\
				Colors.cpp  		\
				CubyHelper.cpp  	\
				FPS.cpp  			\
				ScreenSaver.cpp  	\
				Settings.cpp

OBJ_EXE		=	$(SRC_EXE:.cpp=.o)

LDFLAGS		+=	-lSDL -lSDL_ttf -lfreetype -lSDL_image `sdl-config --libs`
CXXFLAGS	+=	-std=gnu++0x

CXX		=	g++

all:		$(NAME_LIB) $(NAME_LIB2) $(NAME_LIB3) $(NAME_EXE)

$(NAME_EXE):	$(OBJ_EXE)
		$(CXX) -o $(NAME_EXE) $(OBJ_EXE) $(LDFLAGS)

clean:
		rm -f  $(OBJ_EXE)

fclean:		clean
		rm -f $(NAME_EXE)

re:		fclean all
