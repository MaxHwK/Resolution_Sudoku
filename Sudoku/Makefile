SRC=main.c \
	lireGrille.c \
	ecrireGrille.c \
	ft_strlen.c \
	ft_strcpy.c \
	shaker.c \
	ecrireCand.c \
	initJeu.c \
	appartient.c \
	estCandUnique.c \
	rechCaseUnique.c \
	fermerCase.c \
	fermerGrille.c

OBJ=main.o \
	lireGrille.o \
	ecrireGrille.o \
	ft_strlen.o \
	ft_strcpy.o \
	shaker.o \
	ecrireCand.o \
	initJeu.o \
	appartient.o \
	estCandUnique.o \
	rechCaseUnique.o \
	fermerCase.o \
	fermerGrille.o

all: solver

solver: gobjects
	gcc -o solver $(OBJ) -Wall -Werror -Wextra

gobjects:
	gcc -c $(SRC) -Wall -Werror -Wextra

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf solver

re: fclean all
