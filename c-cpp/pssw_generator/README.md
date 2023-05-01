##Password Generator##

#Ensures secure randomization due to use of libsodium library.

#Needed:

- libsodium: 	https://doc.libsodium.org/installation
- xclip:	sudo apt install xclip

#Compile:

gcc-11 main.c password.c -Wall -Werror  -I/usr/local/include -lsodium -o password_generator
