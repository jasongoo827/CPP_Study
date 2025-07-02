# 변수 설정
CXX = g++
CXXFLAGS = -std=c++17

# 타겟 이름
TARGET = main
SRC = ./*.cpp

TXT_FILE = cppTemplate.txt
CPP_FILE = main.cpp

# 기본 타겟
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

file: $(CPP_FILE)

$(CPP_FILE): $(TXT_FILE)
	cp $(TXT_FILE) $(CPP_FILE)

clean:
	rm -f $(TARGET)
