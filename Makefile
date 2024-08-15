all:
	gcc  main.c -o gmirror  `pkg-config --cflags gtk4 --libs gtk4`

debug:
	gcc  -g main.c -o gmirror_d  `pkg-config --cflags gtk4 --libs gtk4`
