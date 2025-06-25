# 변수 설정
CXX = g++
CXXFLAGS = -std=c++17

# 타겟 이름
TARGET = main
SRC = 9019.cpp

# 기본 타겟
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# clean 명령어: 실행파일 삭제
clean:
	rm -f $(TARGET)
