# Nazwa pliku wykonywalnego
TARGET = program_menu

# Kompilator i flagi
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -Iinclude

# Katalogi
SRC_DIR = src
INC_DIR = include

# Automatyczne wyszukiwanie wszystkich plików .cc w katalogu głównym i src/
SRCS = main.cc $(wildcard $(SRC_DIR)/*.cc)

# Tworzenie listy plików obiektowych .o na podstawie plików .cc
OBJS = $(SRCS:.cc=.o)

# Główny cel kompilacji
all: $(TARGET)
	@echo "Kompilacja zakonczona sukcesem! Uruchom program wpisujac: ./$(TARGET)"

# Linkowanie obiektów w jeden plik wykonywalny
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Kompilacja plików źródłowych do obiektowych
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Czyszczenie plików tymczasowych (komenda: make clean)
clean:
	rm -f $(OBJS) $(TARGET)
	@echo "Pliki obiektowe i program zostaly usuniete."