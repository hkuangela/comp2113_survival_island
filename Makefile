FLAGS = -pedantic-errors -std=c++11

display_introduction.o: display_introduction.cpp display_introduction.h
	g++ $(FLAGS) -c $<

display_help.o: display_help.cpp display_help.h
	g++ $(FLAGS) -c $<	
	
main.o: main.cpp display_help.h display_introduction.h
	g++ $(FLAGS) -c $<
	
main: display_introduction.o display_help.o main.o
	g++ $(FLAGS) $^ -o $@
	
clean:
	rm -f main display_introduction.o display_help.o main.o
	
tar:
	tar -czvf main.tgz *.cpp *.h

.PHONY: clean tar
