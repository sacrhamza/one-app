CC = cc

RM = rm

RM_OPTION = rm -rf

CFLAGS = -Wall -Werror -Wextra -g

SOURCE_FILES = one.c set_cursor.c size_warning_message.c


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
	$(RM) $(RM_OPTION) $(TARGET)	

re: fclean $(TARGET)
