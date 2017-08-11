CXX = g++
CXXFLAGS += -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g#

OBJS = inputValidation.o Menu.o Queue.o QueueMain.o

SRCS = inputValidation.cpp Menu.cpp Queue.cpp QueueMain.cpp

HEADERS = inputValidation.h Menu.h Queue.h

Queue: ${OBJS} ${HEADERS}
		${CXX} ${OBJS} -o Queue

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o Queue
