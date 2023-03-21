CXXFLAGS := -Wall -ggdb
LDFLAGS := -lSDL2 -lSDL2_image

SRC_DIR := src/CasseBrique/core
OBJ_DIR := obj
BIN_DIR := bin

OBJS := $(OBJ_DIR)/Pixel.o \
        $(OBJ_DIR)/Affichage.o \
        $(OBJ_DIR)/CasseBrique.o \
        $(OBJ_DIR)/main.o

$(BIN_DIR)/cb: $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/Pixel.o: $(SRC_DIR)/Pixel.cpp $(SRC_DIR)/Pixel.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/Affichage.o: $(SRC_DIR)/Affichage.cpp $(SRC_DIR)/Affichage.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/CasseBrique.o: $(SRC_DIR)/CasseBrique.cpp $(SRC_DIR)/CasseBrique.h $(SRC_DIR)/Complex.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(SRC_DIR)/CasseBrique.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(BIN_DIR)/cb