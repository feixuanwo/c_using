#$@--目标文件，$^--所有的依赖文件，$<--第一个依赖文件
GCC=gcc
LIBS=-lpthread

target:strtok thread des test_mem saolei


strtok:strtok.o
	${GCC} -o $@ $^
thread:thread.o
	${GCC} -o $@ $^ ${LIBS}
des:des.o
	${GCC} -o $@ $^
test_mem:malloc_mem.o
	$(GCC) -o $@ $^
saolei:saolei.o
	$(GCC) -o $@ $^
  
clean:
	rm -f strtok
	rm -f thread
	rm -f des
	rm -f test_mem
	rm -f saolei
	rm -f *.o
