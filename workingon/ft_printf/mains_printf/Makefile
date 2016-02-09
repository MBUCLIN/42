all:
	@gcc -o printf mainprintf.c
	@gcc -o myprintf mainmyprintf.c ../libftprintf.a
	@gcc -o test maintest.c ../libft/libft.a
	@echo "\033[32mCompilation done!\033[0m"

clean:
	@rm -rfv printf.txt myprintf.txt
	@echo "\033[32mClean done!\033[0m"

fclean: clean
	@rm -rfv printf myprintf test
	@echo "\033[32mFclean done!\033[0m"

re: fclean all
