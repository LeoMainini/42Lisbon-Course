
export SIZE=26

gcc -Wall -Werror -Wextra -D BUFFER_SIZE=$SIZE -fsanitize=address -g get_next_line.c get_next_line_utils.c main.c && ./a.out

