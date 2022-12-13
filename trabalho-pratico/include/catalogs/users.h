#ifndef USERS_H
#define USERS_H


/**
 \file users.h
 \brief Módulo para a manipulação dos utilizadores
*/


/*!
 \def CAP_USER
 \brief Capacidade inicial do array que contem os indices das viagens de um utilizador
*/
#define CAP_USER 10


/*! 
 \def BUCKET
 \brief Número de buckets que a tabela de hash possui
*/
#define BUCKET 500057


/*!
 * @brief Estrutura responsável pelo armazenamento dos dados de um utilizador
 * 
 * É nesta estrutra que os dados de um utilizador são guardados (lista ligada)
 */
typedef struct user* USER;


/*!
 * @brief Estrutura responsável pelo armazenamento dos dados dos utilizadores
 * 
 * É nesta estrutra que os dados de todos os utilizadores são guardados (tabela de hash)
 */
typedef USER* USERS;


/**
 * @brief Função que inicializa a tabela de hash dos utilizadores
 * 
 * @return estrutura incializada
 */
USERS init_users();


/**
 * @brief Função que inicializa um utilizador e coloca nele os dados parados como argumento
 * 
 * @param username nome de perfil do utlizador
 * @param name nome do utilizador
 * @param gender genero do utilizador
 * @param birth_date data da aniversário do utilizador
 * @param account_creation data de criação da conta
 * @param pay_method metodo de pagamento utilizado pelo condutor
 * @param account_status estado da conta do utilizador
 * @return utilizador inicialiado com o parametros passado no argumento da função 
 */
USER init_user(
    char *username,
    char *name,
    char *gender,
    char *birth_date,
    char *account_creation,
    char *pay_method,
    char *account_status
);


/**
 * @brief Função que calcula o indice de um utilizados na tabela de hash, esta função foi inspirada a partir deste site (http://www.cse.yorku.ca/~oz/hash.html)
 * 
 * @param str string a partir da qual será calculado o indice
 * @return indice que corresponde ao utilizar em questão
 */
int hash_func(char *str);


/**
 * @brief Função que adiciona um utilizador no inicio de um lista ligada
 * 
 * @param lista estrutura na qual o utilizador será adicionado
 * @param x utilizador que será adicionado à estrutura
 */
void push_user_bucket(USER *lista, USER x);


/**
 * @brief Função que adiciona um utilizador à tabela de hash
 * 
 * @param lista tabela de hash com os dados de todos os utilizadores
 * @param username nome de perfil do utlizador
 * @param name nome do utilizador
 * @param gender genero do utilizador
 * @param birth_date data da aniversário do utilizador
 * @param account_creation data de criação da conta
 * @param pay_method metodo de pagamento utilizado pelo condutor
 * @param account_status estado da conta do utilizador
 */
void push_user(
    USERS lista,
    char *username,
    char *name,
    char *gender,
    char *birth_date,
    char *account_creation,
    char *pay_method,
    char *account_status
);


/**
 * @brief Função que adiciona um indice no array de um determinado utilizador
 * 
 * @param lista tabela de hash com os dados de todos os utilizadores
 * @param position indice que será adicionado a um utilizador
 * @param username utilizador ao qual será adicionado um indice
 */
void push_position(USERS lista, int position, char *username);


/**
 * @brief Função que liberta a memória alocada pela tabela de hash dos utilizadores
 * 
 * @param users_list estrutura de dados dos utilizadores (tabela de hash)
 */
void free_hash_table(USERS users_list);


// MANAGER


/**
 * @brief Função que analise se um determinado utilizador pode ser acedido ou não
 * 
 * @param users_list estrutura de dados dos utilizadores (tabela de hash)
 * @param username username do utilizador que pretendemos analisar
 * @param index indice da tabela de hash onde o utilizador está contido 
 * @return 1 se pode ser acedido, caso contrário 0
 */
int analyse_user(USERS users_list, char *username, int index);


/**
 * @brief Função que recolhe alguns dados dos utilizadores de forma sequencial
 * 
 * @param users_list estrutura com a informação de todos os utilizadores
 * @param start utilizador do qual se pretende extrair informação
 * @param bucket bloco no qual está a ser feita a procura
 * @param name string na qual será guardado o nome do utilizador
 * @param username string na qual será guardado o username do utilizador
 * @param positions endereço no qual será guardado o array das posições de um utilizador
 * @param sp inteiro no qual será guardado o comprimento do array positions
 * @return próximo utilizador ao qual se prentende recolher informação
 */
USER lookup_positions_and_name(USERS users_list, USER start, int *bucket, char *name, char *username, int **positions, int *sp);


/**
 * @brief Função que recolhe os indices de um utilizador
 * 
 * @param users_list estrutura com a informação de todos os utilizadores 
 * @param username utilizador que se pretende analisar
 * @param sp endereço no qual será guardado o comprimento do array positions
 * @param index indice do bucket fornecido pela função de hash
 */
int* lookup_user_positions(USERS users_list, char *username, int *sp, int index);


/**
 * @brief Função que recolhe o nome de um utilizador
 * 
 * @param users_list estrutura com a informação de todos os utilizadores 
 * @param username utilizador que se pretende analisar
 * @param name string na qual será guardado o nome do utilizador
 * @param index indice do bucket fornecido pela função de hash
 */
void lookup_user_name(USERS users_list, char *username, char *name, int index);


/**
 * @brief Função que recolhe a data de nascimento de um utilizador
 * 
 * @param users_list estrutura com a informação de todos os utilizadores 
 * @param username utilizador que se pretende analisar
 * @param date string na qual será guardado a data de aniversário do utilizador
 * @param index indice do bucket fornecido pela função de hash
 */
void lookup_user_birth_date(USERS users_list, char *username, char *date, int index);


/**
 * @brief Função que recolhe o genero de um utilizador
 * 
 * @param users_list estrutura com a informação de todos os utilizadores 
 * @param username utilizador que se pretende analisar
 * @param gender string na qual será guardado o genero do utilizador
 * @param index indice do bucket fornecido pela função de hash
 */
void lookup_user_gender(USERS users_list, char *username, char *gender, int index);


/**
 * @brief Função que recolhe o estado da conta de um utilizador
 * 
 * @param users_list estrutura com a informação de todos os utilizadores 
 * @param username utilizador que se pretende analisar
 * @param index indice do bucket fornecido pela função de hash
 * @return 1 se a conta está ativa, 0 caso esteja inátiva
 */
int lookup_user_account_status(USERS users_list, char *username, int index);


/**
 * @brief Função que recolhe a data de criação de conta de um utilizador
 * 
 * @param users_list estrutura com a informação de todos os utilizadores 
 * @param username utilizador que se pretende analisar
 * @param index indice do bucket fornecido pela função de hash
 * @return data de criação de conta do utilizador
 */
char* lookup_user_account_creation(USERS users_list, char *username, int index);

#endif