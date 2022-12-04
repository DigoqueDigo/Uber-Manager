CC = gcc
CFLAGS = -Wall -Wextra -pedantic-errors -O2 -Iinclude
LIBS = -lm -ltermcap
OBJS_INTERACTIVE = src/interactive/handle.o src/interactive/terminal.o src/interactive/pagination.o src/interactive/search.o
OBJS_CATALOGS = src/catalogs/cities.o src/catalogs/rides.o src/catalogs/users.o src/catalogs/drivers.o
OBJS_FETCH = src/fetch/collector.o
OBJS_UTILS = src/main.o src/sort.o src/fixtures.o
OBJS_PARSER = src/parsing/checker.o src/parsing/parser.o
OBJS_QUERIES = src/queries/queries.o src/queries/querie1.o src/queries/querie2.o src/queries/querie3.o src/queries/querie4.o src/queries/querie5.o src/queries/querie6.o src/queries/querie7.o src/queries/querie8.o src/queries/querie9.o 
TARGET = programa-principal
PATH_RESULTS = Resultados
PATH_CSV_DIOGO = /home/diogo/Desktop/grupo-19/trabalho-pratico/csv
PATH_INPUT_DIOGO = /home/diogo/Desktop/grupo-19/trabalho-pratico/inputs
PATH_CSV_JOAO = /home/joao/Desktop/grupo-19/trabalho-pratico/csv
PATH_INPUT_JOAO = /home/joao/Desktop/grupo-19/trabalho-pratico/inputs


$(TARGET): $(OBJS_UTILS) $(OBJS_PARSER) $(OBJS_CATALOGS) $(OBJS_FETCH) $(OBJS_QUERIES) $(OBJS_INTERACTIVE)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	@mkdir $(PATH_RESULTS)


$(OBJS_UTILS): src/%.o : src/%.c
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
	./$(TARGET) $(PATH_CSV_DIOGO) $(PATH_INPUT_DIOGO)/input.txt
#	./$(TARGET) $(PATH_CSV_JOAO) $(PATH_INPUT_JOAO)/input.txt
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
	./$(TARGET) $(PATH_CSV_DIOGO) $(PATH_INPUT_DIOGO)/input2.txt
#	./$(TARGET) $(PATH_CSV_JOAO) $(PATH_INPUT_JOAO)/input2.txt
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


clean_teste:
	rm Resultados/*.txt


clean:
	rm src/*.o
	rm src/queries/*.o
	rm src/parsing/*.o
	rm src/catalogs/*.o
	rm src/fetch/*.o
	rm src/interactive/*.o
	rm $(TARGET)
	rm -r $(PATH_RESULTS)/