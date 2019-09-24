all: main

main: main.o buddy.o workout.o food.o relaxation.o workoutenvironment.o restaurant.o relaxplan.o
	g++ -o main main.o buddy.o workout.o food.o relaxation.o workoutenvironment.o restaurant.o relaxplan.o

main.o: main.cpp buddy.h workout.h food.h relaxation.h workoutenvironment.h restaurant.h relaxplan.h
	g++ -c main.cpp

buddy.o: buddy.cpp buddy.h
	g++ -c buddy.cpp

workout.o: workout.cpp workout.h
	g++ -c workout.cpp

food.o: food.cpp food.h
	g++ -c food.cpp

relaxation.o: relaxation.cpp relaxation.h
	g++ -c relaxation.cpp

workoutenvironment.o: workoutenvironment.cpp workoutenvironment.h
	g++ -c workoutenvironment.cpp

restaurant.o: restaurant.cpp restaurant.h
	g++ -c restaurant.cpp

relaxplan.o: relaxplan.cpp relaxplan.h
	g++ -c relaxplan.cpp

clean:
	rm -rf *.o
	rm -r main
