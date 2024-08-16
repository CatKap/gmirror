VERSION=0.0.2
all: main parser

main:
	gcc  main.c -o gmir  `pkg-config --cflags gtk4 --libs gtk4`

debug:
	gcc  -g main.c -o gmir_d  `pkg-config --cflags gtk4 --libs gtk4`

parser:
	gcc parse-markup.c -o parse


dpkg: main
	rm -rf ./gmirror 
	rm -rf ./gmirror_d 
	mkdir -p ./gmirror/DEBIAN
	mkdir -p ./gmirror/usr/bin
	cp ./control ./gmirror/DEBIAN/control
	cp ./gmir ./gmirror/usr/bin/
	sed "s/%ver%/$(VERSION)/g" -i ./gmirror/DEBIAN/control
	dpkg-deb --build gmirror
	mv gmirror.deb gmirror-$(VERSION).deb
	rm -rf ./gmirror 
	rm -rf ./gmirror_d 
