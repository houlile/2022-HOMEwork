.PHONY:clean 

cc = g++
LIBS +=`pkg-config --libs opencv`
INC +=`pkg-config --cflags opencv`
CPPFLAGS += -g -std=c++11 -Wall
 
SRCS = work2.cpp
TARGET = text
OBJS = work2.o
 
$(TARGET):$(OBJS)
	$(cc) $(INC) $(CPPFLAGS) $(OBJS) -o $(TARGET) $(LIBS)
$(OBJS):%.o:%.cpp
	$(cc) $(INC) $(CPPFLAGS) -c $< -o $@
 

clean:
	rm -r *.o $(TARGET)


