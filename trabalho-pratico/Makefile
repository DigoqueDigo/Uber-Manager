CC = gcc
CFLAGS = -Wall -Wextra -pedantic-errors -O2 -Iinclude
LIBS = -lm
OBJS = src/main.o src/fixtures.o src/parsing/checker.o src/parsing/parser.o src/catalogs/rides.o src/catalogs/users.o src/catalogs/drivers.o src/queries/queries.o src/queries/querie1.o src/queries/querie3.o src/queries/querie7.o src/queries/querie8.o
TARGET = programa-principal


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)


teste1:
	./$(TARGET) csv/ inputs/input.txt
	diff Resultados/command1_output.txt exemplos_de_queries/tests_1/command1_output.txt
	diff Resultados/command2_output.txt exemplos_de_queries/tests_1/command2_output.txt
	diff Resultados/command3_output.txt exemplos_de_queries/tests_1/command3_output.txt
	diff Resultados/command4_output.txt exemplos_de_queries/tests_1/command4_output.txt
	diff Resultados/command5_output.txt exemplos_de_queries/tests_1/command5_output.txt
	diff Resultados/command6_output.txt exemplos_de_queries/tests_1/command6_output.txt
	diff Resultados/command7_output.txt exemplos_de_queries/tests_1/command8_output.txt
	diff Resultados/command8_output.txt exemplos_de_queries/tests_1/command16_output.txt
	diff Resultados/command9_output.txt exemplos_de_queries/tests_1/command17_output.txt
	diff Resultados/command10_output.txt exemplos_de_queries/tests_1/command18_output.txt


teste2:
	./$(TARGET) csv/ inputs/input2.txt
	diff Resultados/command1_output.txt exemplos_de_queries/tests_2/command1_output.txt
	diff Resultados/command2_output.txt exemplos_de_queries/tests_2/command2_output.txt
	diff Resultados/command3_output.txt exemplos_de_queries/tests_2/command3_output.txt
	diff Resultados/command4_output.txt exemplos_de_queries/tests_2/command4_output.txt
	diff Resultados/command5_output.txt exemplos_de_queries/tests_2/command5_output.txt
	diff Resultados/command6_output.txt exemplos_de_queries/tests_2/command6_output.txt
	diff Resultados/command7_output.txt exemplos_de_queries/tests_2/command7_output.txt
	diff Resultados/command8_output.txt exemplos_de_queries/tests_2/command8_output.txt
	diff Resultados/command9_output.txt exemplos_de_queries/tests_2/command9_output.txt
	diff Resultados/command10_output.txt exemplos_de_queries/tests_2/command10_output.txt
	diff Resultados/command11_output.txt exemplos_de_queries/tests_2/command11_output.txt
	diff Resultados/command12_output.txt exemplos_de_queries/tests_2/command12_output.txt
	diff Resultados/command13_output.txt exemplos_de_queries/tests_2/command13_output.txt
	diff Resultados/command14_output.txt exemplos_de_queries/tests_2/command14_output.txt
	diff Resultados/command15_output.txt exemplos_de_queries/tests_2/command15_output.txt
	diff Resultados/command16_output.txt exemplos_de_queries/tests_2/command16_output.txt
	diff Resultados/command17_output.txt exemplos_de_queries/tests_2/command17_output.txt
	diff Resultados/command18_output.txt exemplos_de_queries/tests_2/command18_output.txt
	diff Resultados/command19_output.txt exemplos_de_queries/tests_2/command19_output.txt
	diff Resultados/command20_output.txt exemplos_de_queries/tests_2/command20_output.txt
	diff Resultados/command21_output.txt exemplos_de_queries/tests_2/command22_output.txt
	diff Resultados/command22_output.txt exemplos_de_queries/tests_2/command40_output.txt
	diff Resultados/command23_output.txt exemplos_de_queries/tests_2/command41_output.txt
	diff Resultados/command24_output.txt exemplos_de_queries/tests_2/command42_output.txt
	diff Resultados/command25_output.txt exemplos_de_queries/tests_2/command43_output.txt
	diff Resultados/command26_output.txt exemplos_de_queries/tests_2/command44_output.txt
	diff Resultados/command27_output.txt exemplos_de_queries/tests_2/command45_output.txt


clean_teste1:
	rm Resultados/command1_output.txt
	rm Resultados/command2_output.txt
	rm Resultados/command3_output.txt
	rm Resultados/command4_output.txt
	rm Resultados/command5_output.txt
	rm Resultados/command6_output.txt
	rm Resultados/command7_output.txt
	rm Resultados/command8_output.txt
	rm Resultados/command9_output.txt
	rm Resultados/command10_output.txt


clean_teste2:
	rm Resultados/command1_output.txt
	rm Resultados/command2_output.txt
	rm Resultados/command3_output.txt
	rm Resultados/command4_output.txt
	rm Resultados/command5_output.txt
	rm Resultados/command6_output.txt
	rm Resultados/command7_output.txt
	rm Resultados/command8_output.txt
	rm Resultados/command9_output.txt
	rm Resultados/command10_output.txt
	rm Resultados/command11_output.txt
	rm Resultados/command12_output.txt
	rm Resultados/command13_output.txt
	rm Resultados/command14_output.txt
	rm Resultados/command15_output.txt
	rm Resultados/command16_output.txt
	rm Resultados/command17_output.txt
	rm Resultados/command18_output.txt
	rm Resultados/command19_output.txt
	rm Resultados/command20_output.txt
	rm Resultados/command21_output.txt
	rm Resultados/command22_output.txt
	rm Resultados/command23_output.txt
	rm Resultados/command24_output.txt
	rm Resultados/command25_output.txt
	rm Resultados/command26_output.txt
	rm Resultados/command27_output.txt


clean:
	rm src/*.o
	rm src/queries/*.o
	rm src/parsing/*.o
	rm src/catalogs/*.o