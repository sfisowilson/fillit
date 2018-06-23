gcc -Wall -Wextra -Werror -o sfiso.filler *.c ./libft/libft.a
rm log.txt
./resources/filler_vm -p1 ./sfiso.filler -p2 ./sfiso.filler  -v -f ./resources/maps/map00 >> log.txt
