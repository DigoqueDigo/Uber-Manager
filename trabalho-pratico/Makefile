CC = gcc
CFLAGS = -Wall -Wextra -pedantic-errors -O2
LIBS = -lm
OBJS = main.o parsing/checker.o parsing/parser.o catalogs/rides.o catalogs/users.o catalogs/drivers.o fixtures.o queries/queries.o queries/querie1.o queries/querie3.o queries/querie8.o
TARGET = programa-principal


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)


teste1:
	./$(TARGET) csv/ inputs/input.txt
	diff command1_output.txt exemplos_de_queries/tests_1/command1_output.txt
	diff command2_output.txt exemplos_de_queries/tests_1/command2_output.txt
	diff command3_output.txt exemplos_de_queries/tests_1/command3_output.txt
	diff command4_output.txt exemplos_de_queries/tests_1/command4_output.txt
	diff command5_output.txt exemplos_de_queries/tests_1/command5_output.txt
	diff command6_output.txt exemplos_de_queries/tests_1/command6_output.txt
	diff command7_output.txt exemplos_de_queries/tests_1/command8_output.txt
	diff command8_output.txt exemplos_de_queries/tests_1/command17_output.txt
	diff command9_output.txt exemplos_de_queries/tests_1/command18_output.txt


teste2:
	./$(TARGET) csv/ inputs/input2.txt
	diff command1_output.txt exemplos_de_queries/tests_2/command1_output.txt
	diff command2_output.txt exemplos_de_queries/tests_2/command2_output.txt
	diff command3_output.txt exemplos_de_queries/tests_2/command3_output.txt
	diff command4_output.txt exemplos_de_queries/tests_2/command4_output.txt
	diff command5_output.txt exemplos_de_queries/tests_2/command5_output.txt
	diff command6_output.txt exemplos_de_queries/tests_2/command6_output.txt
	diff command7_output.txt exemplos_de_queries/tests_2/command7_output.txt
	diff command8_output.txt exemplos_de_queries/tests_2/command8_output.txt
	diff command9_output.txt exemplos_de_queries/tests_2/command9_output.txt
	diff command10_output.txt exemplos_de_queries/tests_2/command10_output.txt
	diff command11_output.txt exemplos_de_queries/tests_2/command11_output.txt
	diff command12_output.txt exemplos_de_queries/tests_2/command12_output.txt
	diff command13_output.txt exemplos_de_queries/tests_2/command13_output.txt
	diff command14_output.txt exemplos_de_queries/tests_2/command14_output.txt
	diff command15_output.txt exemplos_de_queries/tests_2/command15_output.txt
	diff command16_output.txt exemplos_de_queries/tests_2/command16_output.txt
	diff command17_output.txt exemplos_de_queries/tests_2/command17_output.txt
	diff command18_output.txt exemplos_de_queries/tests_2/command18_output.txt
	diff command19_output.txt exemplos_de_queries/tests_2/command19_output.txt
	diff command20_output.txt exemplos_de_queries/tests_2/command20_output.txt
	diff command21_output.txt exemplos_de_queries/tests_2/command22_output.txt
	diff command22_output.txt exemplos_de_queries/tests_2/command40_output.txt
	diff command23_output.txt exemplos_de_queries/tests_2/command41_output.txt
	diff command24_output.txt exemplos_de_queries/tests_2/command42_output.txt
	diff command25_output.txt exemplos_de_queries/tests_2/command43_output.txt
	diff command26_output.txt exemplos_de_queries/tests_2/command44_output.txt
	diff command27_output.txt exemplos_de_queries/tests_2/command45_output.txt


clean_teste1:
	rm command1_output.txt
	rm command2_output.txt
	rm command3_output.txt
	rm command4_output.txt
	rm command5_output.txt
	rm command6_output.txt
	rm command7_output.txt
	rm command8_output.txt
	rm command9_output.txt


clean_teste2:
	rm command1_output.txt
	rm command2_output.txt
	rm command3_output.txt
	rm command4_output.txt
	rm command5_output.txt
	rm command6_output.txt
	rm command7_output.txt
	rm command8_output.txt
	rm command9_output.txt
	rm command10_output.txt
	rm command11_output.txt
	rm command12_output.txt
	rm command13_output.txt
	rm command14_output.txt
	rm command15_output.txt
	rm command16_output.txt
	rm command17_output.txt
	rm command18_output.txt
	rm command19_output.txt
	rm command20_output.txt
	rm command21_output.txt
	rm command22_output.txt
	rm command23_output.txt
	rm command24_output.txt
	rm command25_output.txt
	rm command26_output.txt
	rm command27_output.txt


clean:
	rm *.o
	rm queries/*.o
	rm parsing/*.o
	rm catalogs/*.o