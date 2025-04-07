CC = cc

RM = rm

RM_OPTION = rm -rf

CFLAGS = -Wall -Werror -Wextra -g

SOURCE_FILES = one.c set_cursor.c size_warning_message.c


SOURCE_OBJECTS = $(SOURCE_FILES:%.c=%.o)

TARGET = one

$(TARGET): $(SOURCE_OBJECTS)
	$(CC) $(CFLAGS) $^ -lraylib -lm cfreamwork.a -o $@ #-fsanitize=address

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(RM_OPTION) $(SOURCE_OBJECTS)

fclean: clean
	$(RM) $(RM_OPTION) $(TARGET)	
