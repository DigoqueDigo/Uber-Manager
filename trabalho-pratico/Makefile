CC = gcc
CFLAGS = -Wall -Wextra -pedantic-errors -O2 -Iinclude
LIBS = -lm -ltermcap
OBJS_TESTS = src/tests/diff.o src/tests/test.o src/tests/main.o
OBJS_INTERACTIVE = src/interactive/handle.o src/interactive/terminal.o src/interactive/pagination.o src/interactive/search.o
OBJS_CATALOGS = src/catalogs/cities.o src/catalogs/rides.o src/catalogs/users.o src/catalogs/drivers.o
OBJS_FETCH = src/fetch/collector.o
OBJS_UTILS = src/main.o src/sort.o src/fixtures.o
OBJS_PARSER = src/parsing/checker.o src/parsing/parser.o
OBJS_QUERIES = src/queries/queries.o src/queries/querie1.o src/queries/querie2.o src/queries/querie3.o src/queries/querie4.o src/queries/querie5.o src/queries/querie6.o src/queries/querie7.o src/queries/querie8.o src/queries/querie9.o 
TARGET = programa-principal
TARGET_TESTS = programa-testes
PATH_RESULTS = Resultados
CSV_REGULAR = csv/data-regular
CSV_REGULAR_ERRORS = csv/data-regular-errors
CSV_LARGE = csv/data-large



all: $(TARGET) $(TARGET_TESTS)
	@mkdir -p $(PATH_RESULTS)


$(TARGET): $(OBJS_UTILS) $(filter-out src/tests/main.o, $(OBJS_TESTS)) $(OBJS_PARSER) $(OBJS_CATALOGS) $(OBJS_FETCH) $(OBJS_QUERIES) $(OBJS_INTERACTIVE)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)


$(TARGET_TESTS): $(filter-out src/main.o, $(OBJS_UTILS)) $(OBJS_TESTS) $(OBJS_PARSER) $(OBJS_CATALOGS) $(OBJS_FETCH) $(OBJS_QUERIES) $(OBJS_INTERACTIVE)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)


$(OBJS_UTILS): src/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJS_TESTS): src/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJS_PARSER): src/parsing/%.o : src/parsing/%.c
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJS_CATALOGS): src/catalogs/%.o : src/catalogs/%.c
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJS_FETCH): src/fetch/%.o : src/fetch/%.c
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJS_QUERIES): src/queries/%.o : src/queries/%.c
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJS_INTERACTIVE): src/interactive/%.o : src/interactive/%.c
	$(CC) $(CFLAGS) -c $< -o $@


teste1:
	./$(TARGET) $(CSV_REGULAR) inputs/input.txt
	diff Resultados/command1_output.txt exemplos_de_queries/tests_1/command1_output.txt
	diff Resultados/command2_output.txt exemplos_de_queries/tests_1/command2_output.txt
	diff Resultados/command3_output.txt exemplos_de_queries/tests_1/command3_output.txt
	diff Resultados/command4_output.txt exemplos_de_queries/tests_1/command4_output.txt
	diff Resultados/command5_output.txt exemplos_de_queries/tests_1/command5_output.txt
	diff Resultados/command6_output.txt exemplos_de_queries/tests_1/command6_output.txt
	diff Resultados/command7_output.txt exemplos_de_queries/tests_1/command7_output.txt
	diff Resultados/command8_output.txt exemplos_de_queries/tests_1/command8_output.txt
	diff Resultados/command9_output.txt exemplos_de_queries/tests_1/command9_output.txt
	diff Resultados/command10_output.txt exemplos_de_queries/tests_1/command10_output.txt
	diff Resultados/command11_output.txt exemplos_de_queries/tests_1/command11_output.txt
	diff Resultados/command12_output.txt exemplos_de_queries/tests_1/command12_output.txt
	diff Resultados/command13_output.txt exemplos_de_queries/tests_1/command13_output.txt
	diff Resultados/command14_output.txt exemplos_de_queries/tests_1/command14_output.txt
	diff Resultados/command15_output.txt exemplos_de_queries/tests_1/command15_output.txt
	diff Resultados/command16_output.txt exemplos_de_queries/tests_1/command16_output.txt
	diff Resultados/command17_output.txt exemplos_de_queries/tests_1/command17_output.txt
	diff Resultados/command18_output.txt exemplos_de_queries/tests_1/command18_output.txt
	diff Resultados/command19_output.txt exemplos_de_queries/tests_1/command19_output.txt


teste2:
	./$(TARGET) $(CSV_REGULAR) inputs/input2.txt
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
	diff Resultados/command21_output.txt exemplos_de_queries/tests_2/command21_output.txt
	diff Resultados/command22_output.txt exemplos_de_queries/tests_2/command22_output.txt
	diff Resultados/command23_output.txt exemplos_de_queries/tests_2/command23_output.txt
	diff Resultados/command24_output.txt exemplos_de_queries/tests_2/command24_output.txt
	diff Resultados/command25_output.txt exemplos_de_queries/tests_2/command25_output.txt
	diff Resultados/command26_output.txt exemplos_de_queries/tests_2/command26_output.txt
	diff Resultados/command27_output.txt exemplos_de_queries/tests_2/command27_output.txt
	diff Resultados/command28_output.txt exemplos_de_queries/tests_2/command28_output.txt
	diff Resultados/command29_output.txt exemplos_de_queries/tests_2/command29_output.txt
	diff Resultados/command30_output.txt exemplos_de_queries/tests_2/command30_output.txt
	diff Resultados/command31_output.txt exemplos_de_queries/tests_2/command31_output.txt
	diff Resultados/command32_output.txt exemplos_de_queries/tests_2/command32_output.txt
	diff Resultados/command33_output.txt exemplos_de_queries/tests_2/command33_output.txt
	diff Resultados/command34_output.txt exemplos_de_queries/tests_2/command34_output.txt
	diff Resultados/command35_output.txt exemplos_de_queries/tests_2/command35_output.txt
	diff Resultados/command36_output.txt exemplos_de_queries/tests_2/command36_output.txt
	diff Resultados/command37_output.txt exemplos_de_queries/tests_2/command37_output.txt
	diff Resultados/command38_output.txt exemplos_de_queries/tests_2/command38_output.txt
	diff Resultados/command39_output.txt exemplos_de_queries/tests_2/command39_output.txt
	diff Resultados/command40_output.txt exemplos_de_queries/tests_2/command40_output.txt
	diff Resultados/command41_output.txt exemplos_de_queries/tests_2/command41_output.txt
	diff Resultados/command42_output.txt exemplos_de_queries/tests_2/command42_output.txt
	diff Resultados/command43_output.txt exemplos_de_queries/tests_2/command43_output.txt
	diff Resultados/command44_output.txt exemplos_de_queries/tests_2/command44_output.txt
	diff Resultados/command45_output.txt exemplos_de_queries/tests_2/command45_output.txt
	diff Resultados/command46_output.txt exemplos_de_queries/tests_2/command46_output.txt
	diff Resultados/command47_output.txt exemplos_de_queries/tests_2/command47_output.txt
	diff Resultados/command48_output.txt exemplos_de_queries/tests_2/command48_output.txt
	diff Resultados/command49_output.txt exemplos_de_queries/tests_2/command49_output.txt
	diff Resultados/command50_output.txt exemplos_de_queries/tests_2/command50_output.txt


teste3:
	./$(TARGET) $(CSV_REGULAR_ERRORS) inputs/input3.txt
	diff Resultados/command1_output.txt exemplos_de_queries/tests_3/command1_output.txt
	diff Resultados/command2_output.txt exemplos_de_queries/tests_3/command2_output.txt
	diff Resultados/command3_output.txt exemplos_de_queries/tests_3/command3_output.txt
	diff Resultados/command4_output.txt exemplos_de_queries/tests_3/command4_output.txt
	diff Resultados/command5_output.txt exemplos_de_queries/tests_3/command5_output.txt
	diff Resultados/command6_output.txt exemplos_de_queries/tests_3/command6_output.txt
	diff Resultados/command7_output.txt exemplos_de_queries/tests_3/command7_output.txt
	diff Resultados/command8_output.txt exemplos_de_queries/tests_3/command8_output.txt
	diff Resultados/command9_output.txt exemplos_de_queries/tests_3/command9_output.txt
	diff Resultados/command10_output.txt exemplos_de_queries/tests_3/command10_output.txt
	diff Resultados/command11_output.txt exemplos_de_queries/tests_3/command11_output.txt
	diff Resultados/command12_output.txt exemplos_de_queries/tests_3/command12_output.txt
	diff Resultados/command13_output.txt exemplos_de_queries/tests_3/command13_output.txt
	diff Resultados/command14_output.txt exemplos_de_queries/tests_3/command14_output.txt
	diff Resultados/command15_output.txt exemplos_de_queries/tests_3/command15_output.txt
	diff Resultados/command16_output.txt exemplos_de_queries/tests_3/command16_output.txt
	diff Resultados/command17_output.txt exemplos_de_queries/tests_3/command17_output.txt
	diff Resultados/command18_output.txt exemplos_de_queries/tests_3/command18_output.txt
	diff Resultados/command19_output.txt exemplos_de_queries/tests_3/command19_output.txt
	diff Resultados/command20_output.txt exemplos_de_queries/tests_3/command20_output.txt
	diff Resultados/command21_output.txt exemplos_de_queries/tests_3/command21_output.txt
	diff Resultados/command22_output.txt exemplos_de_queries/tests_3/command22_output.txt
	diff Resultados/command23_output.txt exemplos_de_queries/tests_3/command23_output.txt
	diff Resultados/command24_output.txt exemplos_de_queries/tests_3/command24_output.txt
	diff Resultados/command25_output.txt exemplos_de_queries/tests_3/command25_output.txt
	diff Resultados/command26_output.txt exemplos_de_queries/tests_3/command26_output.txt
	diff Resultados/command27_output.txt exemplos_de_queries/tests_3/command27_output.txt
	diff Resultados/command28_output.txt exemplos_de_queries/tests_3/command28_output.txt
	diff Resultados/command29_output.txt exemplos_de_queries/tests_3/command29_output.txt
	diff Resultados/command30_output.txt exemplos_de_queries/tests_3/command30_output.txt
	diff Resultados/command31_output.txt exemplos_de_queries/tests_3/command31_output.txt
	diff Resultados/command32_output.txt exemplos_de_queries/tests_3/command32_output.txt
	diff Resultados/command33_output.txt exemplos_de_queries/tests_3/command33_output.txt
	diff Resultados/command34_output.txt exemplos_de_queries/tests_3/command34_output.txt
	diff Resultados/command35_output.txt exemplos_de_queries/tests_3/command35_output.txt
	diff Resultados/command36_output.txt exemplos_de_queries/tests_3/command36_output.txt
	diff Resultados/command37_output.txt exemplos_de_queries/tests_3/command37_output.txt
	diff Resultados/command38_output.txt exemplos_de_queries/tests_3/command38_output.txt
	diff Resultados/command39_output.txt exemplos_de_queries/tests_3/command39_output.txt
	diff Resultados/command40_output.txt exemplos_de_queries/tests_3/command40_output.txt
	diff Resultados/command41_output.txt exemplos_de_queries/tests_3/command41_output.txt
	diff Resultados/command42_output.txt exemplos_de_queries/tests_3/command42_output.txt
	diff Resultados/command43_output.txt exemplos_de_queries/tests_3/command43_output.txt
	diff Resultados/command44_output.txt exemplos_de_queries/tests_3/command44_output.txt
	diff Resultados/command45_output.txt exemplos_de_queries/tests_3/command45_output.txt
	diff Resultados/command46_output.txt exemplos_de_queries/tests_3/command46_output.txt
	diff Resultados/command47_output.txt exemplos_de_queries/tests_3/command47_output.txt
	diff Resultados/command48_output.txt exemplos_de_queries/tests_3/command48_output.txt
	diff Resultados/command49_output.txt exemplos_de_queries/tests_3/command49_output.txt
	diff Resultados/command50_output.txt exemplos_de_queries/tests_3/command50_output.txt
	diff Resultados/command51_output.txt exemplos_de_queries/tests_3/command51_output.txt
	diff Resultados/command52_output.txt exemplos_de_queries/tests_3/command52_output.txt
	diff Resultados/command53_output.txt exemplos_de_queries/tests_3/command53_output.txt
	diff Resultados/command54_output.txt exemplos_de_queries/tests_3/command54_output.txt


teste4:
	./$(TARGET_TESTS) $(CSV_REGULAR) inputs/input.txt exemplos_de_queries/tests_1


teste5:
	./$(TARGET_TESTS) $(CSV_REGULAR) inputs/input2.txt exemplos_de_queries/tests_2


teste6:
	./$(TARGET_TESTS) $(CSV_REGULAR_ERRORS) inputs/input3.txt exemplos_de_queries/tests_3

teste7:
	./$(TARGET_TESTS) $(CSV_LARGE) inputs/input4.txt exemplos_de_queries/tests_4


clean:
	rm src/*.o
	rm src/queries/*.o
	rm src/parsing/*.o
	rm src/catalogs/*.o
	rm src/fetch/*.o
	rm src/tests/*.o
	rm src/interactive/*.o
	rm $(TARGET)
	rm $(TARGET_TESTS)
	rm -r $(PATH_RESULTS)/