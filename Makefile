NAME		=	main.exe #output name

CXX		=	g++

SRCDIR = ./src/

INCDIR = ./include/

#sources
SRC		=	$(SRCDIR)main.cpp \
			$(SRCDIR)Animal.cpp \
			$(SRCDIR)World.cpp

CXXFLAGS	+= -std=c++11 -g -Wall -Wextra -I$(INCDIR) #compilation flags

LDFLAGS		= #libraries link (-lsfml etc ...)

OBJ		=	$(SRC:.cpp=.o) #compile .cpp to .o

RM		=	rm -f

all:		$(NAME) #entry point

$(NAME):	$(OBJ)
		@$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re #declaration of makefile commands
