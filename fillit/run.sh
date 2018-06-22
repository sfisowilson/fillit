gcc -Wall -Wextra -Werror -o sfiso.filler *.c ./libft/libft.a
./resources/filler_vm -p1 ./sfiso.filler -p2 ./resources/players/hcao.filler  -v -f ./resources/maps/map02 >> log.txt
