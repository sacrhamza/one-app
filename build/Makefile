CC = cc

RM = rm

RM_OPTION = rm -rf

CFLAGS = -Wall -Werror -Wextra -g

TARGET = one

SRC = src

# OLD WAY TO SET VAR FILES
#SOURCE_FILES = $(SRC)/one.c $(SRC)/set_cursor.c $(SRC)/size_warning_message.c $(SRC)/key_events.c $(SRC)/mouse_events.c $(SRC)/load_textures.c \
#		$(SRC)/status_bar.c $(SRC)/status_bar.c $(SRC)/clean.c $(SRC)/join.c

#NEW WAY USING WILDCARD
SOURCE_FILES = $(wildcard $(SRC)/*.c)

all: $(TARGET)


display:
	@echo $(SOURCE_FILES)

SOURCE_OBJECTS = $(SOURCE_FILES:%.c=%.o)



$(TARGET): $(SOURCE_OBJECTS)
	make -C cfreamwork
	$(CC) $(CFLAGS) $^ -lraylib -lm cfreamwork/cfreamwork.a -o $@ #-fsanitize=address

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I include/

run: $(TARGET)
	./$(TARGET)
rerun: re run

clean:
	make -C cfreamwork fclean
	$(RM) $(RM_OPTION) $(SOURCE_OBJECTS)

fclean: clean
	#$(RM) $(RM_OPTION) bin
	$(RM) $(RM_OPTION) $(TARGET)	

re: fclean $(TARGET)
