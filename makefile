CC		= g++
CFLAGS	= -W -Wall -ansi -pedantic
LDFLAGS =
EXEC	= result
RM		= rm -f

SRC		= \
		$(wildcard object/*.cpp) \
		main.cpp

OBJ		= $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

.PHONY: clean fclean re

clean:
ifeq ($(OS),Windows_NT)
	del /s /q *.o
else
	$(RM) -rf $(OBJ)
endif

fclean: clean
ifeq ($(OS),Windows_NT)
	del /s /q $(EXEC).exe
else
	$(RM) -rf $(EXEC)
endif

re: fclean all