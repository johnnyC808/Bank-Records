project: llist.o user_interface.o
	g++ -o project llist.o user_interface.o
	@echo "Creating exacutable.."

user_interface.o: user_interface.cpp
	g++ -ansi -pedantic-errors -Wall -c user_interface.cpp
	@echo "Generating user_interface.o"

llist.o: llist.cpp
	g++ -ansi -pedantic-errors -Wall -c llist.cpp
	@echo "Generating llist.o"
