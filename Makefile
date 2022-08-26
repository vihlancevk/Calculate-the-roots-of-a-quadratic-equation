CC = g++

# -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr
# ?
CFLAGS = -c -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -fPIE -pie -Wlarger-than=8192 -Wstack-usage=8192

square: main.o userInteraction.o equationSolving.o testProgram.o
	$(CC) main.o userInteraction.o equationSolving.o testProgram.o -o square

# продумать логику
# square: clean

main.o: src/main.cpp
	$(CC) $(CFLAGS) $(DEBUG) $(TESTS) src/main.cpp

userInteraction.o: src/userInteraction.cpp
	$(CC) $(CFLAGS) $(DEBUG) $(TESTS) src/userInteraction.cpp

equationSolving.o: src/equationSolving.cpp
	$(CC) $(CFLAGS) $(DEBUG) $(TESTS) src/equationSolving.cpp

testProgram.o: src/testProgram.cpp
	$(CC) $(CFLAGS) $(DEBUG) $(TESTS) src/testProgram.cpp

debug: DEBUG = -DDEBUG

debug: square

tests: TESTS = -DTESTS

tests: square

clean:
	rm -rf *.o square
