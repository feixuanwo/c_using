#$@--目标文件，$^--所有的依赖文件，$<--第一个依赖文件
GCC=gcc
LIBS=-lpthread

target:strtok thread


strtok:strtok.o
	${GCC} -o $@ $^
thread:thread.o
	${GCC} -o $@ $^ ${LIBS}
  
clean:
	rm -f strtok
	rm -f thread
	rm *.o
