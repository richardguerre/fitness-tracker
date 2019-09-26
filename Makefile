all: main

main: main.o buddy.o workout.o food.o relaxation.o workoutenvironment.o restaurant.o relaxplan.o
	g++ -g -o main main.o buddy.o workout.o food.o relaxation.o workoutenvironment.o restaurant.o relaxplan.o

main.o: main.cpp buddy.h workout.h food.h relaxation.h workoutenvironment.h restaurant.h relaxplan.h
	g++ -g -c main.cpp

buddy.o: buddy.cpp buddy.h
	g++ -g -c buddy.cpp

workout.o: workout.cpp workout.h
	g++ -g -c workout.cpp

food.o: food.cpp food.h
	g++ -g -c food.cpp

relaxation.o: relaxation.cpp relaxation.h
	g++ -g -c relaxation.cpp

workoutenvironment.o: workoutenvironment.cpp workoutenvironment.h
	g++ -g -c workoutenvironment.cpp

restaurant.o: restaurant.cpp restaurant.h
	g++ -g -c restaurant.cpp

relaxplan.o: relaxplan.cpp relaxplan.h
	g++ -g -c relaxplan.cpp

clean:
	rm -rf *.o
	rm -r main
