CC = cc

RM = rm

RM_OPTION = rm -rf

CFLAGS = -Wall -Werror -Wextra -g


SRC = src

SOURCE_FILES = $(SRC)/one.c $(SRC)/set_cursor.c $(SRC)/size_warning_message.c $(SRC)/key_events.c $(SRC)/mouse_events.c $(SRC)/load_textures.c


SOURCE_OBJECTS = $(SOURCE_FILES:%.c=%.o)

TARGET = one

$(TARGET): $(SOURCE_OBJECTS)
	make -C cfreamwork
	$(CC) $(CFLAGS) $^ -lraylib -lm cfreamwork/cfreamwork.a -o $@ #-fsanitize=address

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I include/

run: re
	./$(TARGET)

clean:
	make -C cfreamwork fclean
	$(RM) $(RM_OPTION) $(SOURCE_OBJECTS)

fclean: clean
	$(RM) $(RM_OPTION) bin
	$(RM) $(RM_OPTION) $(TARGET)	

re: fclean $(TARGET)
