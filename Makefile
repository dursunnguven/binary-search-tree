# Compiler ve bayraklar
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Dizindeki dosyalar ve hedefler
SRC = src/main.cpp src/BinarySearchTree.cpp src/LinkedList.cpp src/Node.cpp
INCLUDE = include/BinarySearchTree.h include/LinkedList.h include/Node.h
OBJ = bin/main.o bin/BinarySearchTree.o bin/LinkedList.o bin/Node.o

# Çıktı dosyası
OUTPUT = bin/program

# Varsayılan hedef
all: $(OUTPUT)

# Çalıştırılabilir dosya oluşturma
$(OUTPUT): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(OUTPUT) $(OBJ)

# .o dosyalarını oluşturma
bin/%.o: src/%.cpp $(INCLUDE)
	$(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@

# Temizleme komutu
clean:
	rm -f bin/*.o $(OUTPUT)
