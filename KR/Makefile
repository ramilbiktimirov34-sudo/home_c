CXX = gcc
CXXFLAGS = -Wall -Wextra -g -std=c11
TARGET = sensor
SRCS = main.c temp_api.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET):$(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del $(TARGET).exe $(OBJS)
