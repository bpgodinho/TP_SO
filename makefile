all: motor jogoUI

motor: 
	gcc -o motor motor.c
	gcc -o bot bot.c
jogoUI: 
	gcc -o jogoUI jogoUI.c -lncurses


clean: 
	rm -f motor jogoUI bot
