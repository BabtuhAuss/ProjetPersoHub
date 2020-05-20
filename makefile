CC		= g++
DEBUG=yes
CFLAGS	= -W -Wall -ansi -pedantic
LDFLAGS =
EXEC	= result
RM		= rm -f
RM_WINDOWS = del /s /q

RECWILDCARD	=	$(foreach d,$(wildcard $(1:=/*)),$(call RECWILDCARD,$d,$2) $(filter $(subst *,%,$2),$d))


# SRC		= \
# 		$(wildcard object/*.cpp) \
# 		$(wildcard object/*/*.cpp) \
# 		main.cpp

SRC_C = $(call RECWILDCARD,.,*.cpp)


OBJ		= $(SRC_C:.cpp=.o)

all: $(EXEC)
ifeq ($(DEBUG),yes)
	@echo "Génération en mode debug"
else
	@echo "Génération en mode release"
endif



$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

.PHONY: clean fclean re

clean:
ifeq ($(OS),Windows_NT)
	$(RM_WINDOWS) *.o
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