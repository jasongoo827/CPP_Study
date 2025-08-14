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

# 문제 번호별 파일 생성 (디렉토리 생성 없이)
problem:
ifndef NUM
	$(error NUM is not set. Usage: make problem NUM=1234)
endif
	cp $(TXT_FILE) $(NUM).cpp
	@echo "Created $(NUM).cpp"

clean:
	rm -f $(TARGET) *.cpp

.PHONY: all file problem clean