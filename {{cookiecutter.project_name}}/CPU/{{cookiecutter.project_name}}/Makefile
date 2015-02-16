NAME		= {{cookiecutter.stem_name}}
EXEC		= $(NAME)

CC		= gcc
CFLAGS		= -std=gnu99 -Wall
LDFLAGS		= -lm

OBJ		= {{cookiecutter.stem_name}}.o

all:		run

$(EXEC):	$(OBJ)
		$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

run:		$(EXEC)

.INTERMEDIATE:	$(OBJ)

clean:
		rm $(EXEC)	
