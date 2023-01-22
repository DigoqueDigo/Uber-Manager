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


test_1:
	./$(TARGET_TESTS) $(CSV_REGULAR) inputs/input.txt exemplos_de_queries/tests_1


test_2:
	./$(TARGET_TESTS) $(CSV_REGULAR) inputs/input2.txt exemplos_de_queries/tests_2


test_3:
	./$(TARGET_TESTS) $(CSV_REGULAR_ERRORS) inputs/input3.txt exemplos_de_queries/tests_3


test_4:
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