project_debug: llist.o user_interface.o
	g++ -o project_debug llist.o user_interface.o
	@echo "Linking debugF..."
llist.o: llist.cpp 
	g++ -ansi -pedantic-errors -Wall -DDEBUG -c llist.cpp
	@echo "Compiling llist in debug..."
user_interface.o: user_interface.cpp
	g++ -ansi -pedantic-errors -Wall -DDEBUG -c user_interface.cpp
	@echo "Compiling user_interface in debug..."
