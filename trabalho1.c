// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:Leonardo Aleluia Sampaio
//  email:20242160031@ifba.edu.br
//  Matrícula:20242160031
//  Semestre:Segundo



 /* Q1 = validar data
    @objetivo
    Validar uma data*/

#define TAM 250
#define L 250
#define C 250
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void validandoData(int intDia, int intMes, int intAno);

void data(char data[TAM]);

void datas(char data[TAM], char data2[TAM]);

void contarMeses(int dia1, int dia2, int mes1, int mes2, int ano1, int ano2);

void contador(char texto[TAM], char letraBusca);

int transformaVetor(char strTexto[], int intTexto[]);

int buscarPalavra(int intTexto[], int tamTexto, int intBusca[], int tamBusca, int posicoes[]);

void printPosicoes(int posicoes[]);

int inverterNum(int num);

int procurarNum(int numBase, int numProcura);

char* direita(char nome[], char matriz[L][C]);

char* esquerda(char nome[], char matriz[L][C]);

char* baixo(char nome[], char matriz[L][C]);

char* cima(char nome[], char matriz[L][C]);

char* diagonalDireitaBaixo(char nome[], char matriz[L][C]);

char* diagonalEsquerdaBaixo(char nome[], char matriz[L][C]);

char* diagonalDireitaCima(char nome[], char matriz[L][C]);

char* diagonalEsquerdaCima(char nome[], char matriz[L][C]);

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}



void validandoData(int intDia, int intMes, int intAno){
	int achouBix = 0;
	int fevereiro = 0;
	if (intMes <= 12){
		if((intAno % 4 == 0 && intAno % 100 != 0) || (intAno % 400 == 0)){
			fevereiro = 29;
			achouBix = 1;
		}
		switch(intMes){
			case 1:{
				if(intDia <= 31 && intAno >= 2000){
					printf("data: %d/%d/%d", intDia, intMes, intAno);
				}else{
					printf("Data invalida");
				}
				break;
			}
			case 2:{
				if(achouBix && intDia == fevereiro && intAno >= 2000){
					printf("Ano bisexto %d/%d/%d", intDia, intMes, intAno);
				}else{
					if(intDia <= 28 && intAno >= 2000){
						printf("Data: %d/%d/%d", intDia, intMes, intAno);
					}else{
						printf("Data inválida %d");
					}
				}
				break;
			}
			case 3:{
				if(intDia <= 31 && intAno >= 2000){
					printf("Data: %d/%d/%d", intDia, intMes, intAno);
				}else{
					printf("Data inválida");
				}
				break;
			}
			case 4:{
				if(intDia <= 30 && intAno >= 2000){
					printf("Data: %d/%d/%d", intDia, intMes, intAno);
				}else{
					printf("Data inválida");
				}
				break;
			}
			case 5:{
				if(intDia <= 31 && intAno >= 2000){
					printf("Data: %d/%d/%d", intDia, intMes, intAno);
				}else{
					printf("Data inválida");
				}
				break;
			}
			case 6:{
				if(intDia <= 30 && intAno >= 2000){
					printf("Data: %d/%d/%d", intDia, intMes, intAno);
				}else{
					printf("Data inválida");
				}
				break;
			}
			case 7:{
				if(intDia <= 31 && intAno >= 2000){
					printf("Data: %d/%d/%d", intDia, intMes, intAno);
				}else{
					printf("Data inválida");
				}
				break;
			}
			case 8:{
				if(intDia <= 31 && intAno >= 2000){
					printf("Data: %d/%d/%d", intDia, intMes, intAno);
				}else{
					printf("Data inválida");
				}
				break;
			}
			case 9:{
				if(intDia <= 30 && intAno >= 2000){
					printf("Data: %d/%d/%d", intDia, intMes, intAno);
				}else{
					printf("Data inválida");
				}
				break;
			}
			case 10:{
				if(intDia <= 31 && intAno >= 2000){
					printf("Data: %d/%d/%d", intDia, intMes, intAno);
				}else{
					printf("Data inválida");
				}
				break;
			}
			case 11:{
				if(intDia <= 31 && intAno >= 2000){
					printf("Data: %d/%d/%d", intDia, intMes, intAno);
				}else{
					printf("Data inválida");
				}
				break;
			}
			case 12:{
				if(intDia <= 31 && intAno >= 2000){
					printf("Data: %d/%d/%d", intDia, intMes, intAno);
				}else{
					printf("Data inválida");
				}
				break;
			}
			default:{
				printf("Data inválida");
				break;
			}
		}
	}
}
void data(char data[TAM]){
	int intDia = 0;
	int i = 0;
	int intMes = 0;
	int intAno = 0;
	int achou = 0;
	int ctr = 0;
	int ctrAno = 0;
	char dia[TAM];
    char mes[TAM];
    char ano[TAM];
	for(i = 0; data[i] != '\0'; i++){
    	if(data[0] == '/'){
    		printf("Data invalida");
    		break;	
		}else if(data[i] != '/' && achou == 0){
			dia[i] = data[i];
			if(data[i + 1] == '/'){
				dia[i + 1] = '\0';
				achou++;
			}
		}else if(data[i] != '/' && achou == 1){
			mes[ctr] = data[i];
			if(data[i + 1] == '/'){
				mes[ctr + 1] = '\0';
				achou++;
			}
			ctr++;
		}else{
			if(achou == 2){
				int ii = i + 1;
				while (data[ii] != '\0'){
					ano[ctrAno] = data[ii];
					ctrAno++;
					ii++;
				}
				ano[ctrAno + 1] = '\0';
				break;
			}
		}
	}
	
	intMes = atoi(mes);
	intDia = atoi(dia);
	intAno = atoi(ano);
	validandoData(intDia, intMes, intAno);
}
//#################################################################

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
*/
void datas(char data[TAM], char data2[TAM]){
	int intDia1 = 0;
	int i = 0;
	int intMes1 = 0;
	int intAno1 = 0;
	int achou = 0;
	int ctr = 0;
	int ctrAno = 0;
	int intDia2 = 0;
	int intMes2 = 0;
	int intAno2 = 0;
	char dia[TAM];
    char mes[TAM];
    char ano[TAM];
    char dia2[TAM];
    char mes2[TAM];
    char ano2[TAM];
	for(i = 0; data[i] != '\0'; i++){
    	if(data[0] == '/'){
    		printf("Data invalida");
    		break;	
		}else if(data[i] != '/' && achou == 0){
			dia[i] = data[i];
			if(data[i + 1] == '/'){
				dia[i + 1] = '\0';
				achou++;
			}
		}else if(data[i] != '/' && achou == 1){
			mes[ctr] = data[i];
			if(data[i + 1] == '/'){
				mes[ctr + 1] = '\0';
				achou++;
			}
			ctr++;
		}else{
			if(achou == 2){
				int ii = i + 1;
				while (data[ii] != '\0'){
					ano[ctrAno] = data[ii];
					ctrAno++;
					ii++;
				}
				ano[ctrAno + 1] = '\0';
				break;
			}
		}
	}
	intMes1 = atoi(mes);
	intDia1= atoi(dia);
	intAno1 = atoi(ano);	
	ctr = 0;
	achou = 0;
	ctrAno = 0;
	for(i = 0; data2[i] != '\0'; i++){
    	if(data2[0] == '/'){
    		printf("Data invalida");
    		break;	
		}else if(data2[i] != '/' && achou == 0){
			dia2[i] = data2[i];
			if(data2[i + 1] == '/'){
				dia2[i + 1] = '\0';
				achou++;
			}
		}else if(data2[i] != '/' && achou == 1){
			mes2[ctr] = data2[i];
			if(data2[i + 1] == '/'){
				mes2[ctr + 1] = '\0';
				achou++;
			}
			ctr++;
		}else{
			if(achou == 2){
				int ii = i + 1;
				while (data2[ii] != '\0'){
					ano2[ctrAno] = data2[ii];
					ctrAno++;
					ii++;
				}
				ano2[ctrAno + 1] = '\0';
				break;
			}
		}
	}
	intMes2 = atoi(mes2);
	intDia2 = atoi(dia2);
	intAno2 = atoi(ano2);	
	contarMeses(intDia1, intDia2, intMes1, intMes2, intAno1, intAno2);
}
void contarMeses(int dia1, int dia2, int mes1, int mes2, int ano1, int ano2){
	int i = 0;
	int diaInicio = 0;
	int diaFim = 0;
	int diasTotais;
	int contMes = 0;
	for(i = mes1; i <= mes2; i++){
		switch (i){
			case 2:{
				int bissexto = 0;
				if((ano1 % 4 == 0 && ano1 % 100 != 0) || (ano1 % 400 == 0)){
					bissexto = 1;
				}
				if(bissexto == 1){
					if(i == mes1){
						diaInicio = 29 - dia1;
					}else if(i == mes2){
						diaFim = dia2;
					}else{
						diaInicio += 29;
					}
				}else{
					if(i == mes1){
						diaInicio = 28 - dia1;
					}else if(i == mes2){
						diaFim = dia2;
					}else{
						diaInicio += 28;
					}
				}
				break;
			}
			case 4:
			case 6:
			case 9:
			case 11:{
				if(i == mes1){
					diaInicio = 30 - dia1;
				}else if(i == mes2){
					diaFim = dia2;
				}else{
					diaInicio += 30;
				}
				break;
			}
			default:{
				if(i == mes1){
					diaInicio = 31 - dia1;
				}else if(i == mes2){
					diaFim = dia2;
				}else{
					diaInicio += 31;
				}
				break;
			}
		}
	}
	diasTotais = diaInicio + diaFim;
	if(diasTotais <= 31){
		printf("%d dias", diasTotais);
	}else{
		contMes = diasTotais / 30;
		int restoDias = diasTotais % 30;
		printf("%d meses e %d dias", contMes, restoDias);
	}
}

//############################################################################

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
*/

void contador(char texto[TAM], char letraBusca){
	int i = 0;
	int cont = 0;
	for(i = 0; i < strlen(texto); i++){
		switch(texto[i]){
			case 'á':
			case 'à':
			case 'â':
			case 'ã':
			case 'ä':{
				texto[i] = 'a';
				break;
			}
			case 'é':
			case 'è':
			case 'ê':
			case 'ë':{
				texto[i] = 'e';
				break;
			}
			case 'í':
			case 'ì':
			case 'î':
			case 'ï':{
				texto[i] = 'i';
				break;
			}
			case 'ó':
			case 'ò':
			case 'ô':
			case 'õ':
			case 'ö':{
				texto[i] = 'o';
				break;
			}
			case 'ú':
			case 'ù':
			case 'û':
			case 'ü':{
				texto[i] = 'u';
				break;
			}
			case 'ç':{
				texto[i] = 'c';
				break;
			}
		}
		if(texto[i] == letraBusca){
			cont++;
		}
	}
	printf("A letra apareceu %d vezes", cont);
}

//###########################################################################
/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
*/

int transformaVetor(char strTexto[], int intTexto[]);
int buscarPalavra(int intTexto[], int tamTexto, int intBusca[], int tamBusca, int posicoes[]);
void printPosicoes(int posicoes[]);

int transformaVetor(char strTexto[], int intTexto[]){
    int j = 0;
    int k = 0;
    for(j = 0; j < strlen(strTexto); j++){
        if(strTexto[j] != -61){
            intTexto[k] = strTexto[j];
            k++;
        }
    }
    return k;
}

int buscarPalavra(int intTexto[], int tamTexto, int intBusca[], int tamBusca,int posicoes[]){
    int i = 0;
    int j = 0;
    int ctr = 0;
    for(i = 0; i < tamTexto; i++){
        if(intTexto[i] == intBusca[0]){
            ctr = 0;
            for(j = i; j < tamTexto && ctr < tamBusca; j++){
                if(intTexto[j] == intBusca[ctr]){
                    ctr++;
                }else{
                    break;
                }
            }
            if(ctr == tamBusca){
                posicoes[0] = i;
                posicoes[1] = j - 1;
                return 1;
            }
        }
    }
    return 0;
}
void printPosicoes(int posicoes[]){
    printf("Inicio: %d\n", posicoes[0]);
    printf("Fim: %d\n", posicoes[1]);
}

//###########################################################################
/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
*/

int inverterNum (int num){
	int numCtr = 0;
	int ctr = 0;
	int resto = 0;
	int restoCtr = 0;
	int invertido = 0;
	int ctr2 = 0;
	while (num >= 10){
		numCtr = num;
		resto = num % 10;
		num = num / 10;
		while(numCtr >= 10){
			ctr2 = numCtr;
			numCtr = numCtr / 10;
			if (ctr == 0){
				restoCtr = ctr2 % 10;	
				restoCtr *= 10;
				ctr = 1;
			}else {
				restoCtr *= 10;
			}
		}
		ctr = 0;
		invertido += restoCtr;
	}
	invertido += num;
	return invertido;
}

//###########################################################################
/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
*/

int procurarNum(int numBase, int numProcura){
	int numCtr = 0;
	int res1 = 0;
	int ocorrencia = 0;
	int restoProcura = 0;
	int auxProcura = 0;
	while(numBase > 0){
		numCtr = numBase;
		res1 = numCtr % 10;
		numBase = numBase / 10;
		if(res1 == numProcura % 10){
			auxProcura = numProcura;
			while(auxProcura > 0){
				restoProcura = auxProcura % 10;
				res1 = numCtr % 10;
				if(res1 != restoProcura){
					break;
				}
				numCtr = numCtr / 10;
				auxProcura = auxProcura / 10;
			}
			if(auxProcura == 0){
				ocorrencia++;
			}
		}
	}
	return ocorrencia;
}

//#############################################################################

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíve
*/
char* direita(char nome[], char matriz[L][C]){
    int l, c;
    int ctr;
    int auxC;
    for(l = 0; l < L; l++){
        for(c = 0; c < C; c++){
            if(matriz[l][c] == nome[0]){
                ctr = 0;
                auxC = c;
                while(
                    ctr < strlen(nome) &&
                    auxC < C &&
                    matriz[l][auxC] == nome[ctr]
                ){
                    ctr++;
                    auxC++;
                }
                if(ctr == strlen(nome)){
                    return "achou direita";
                }
            }
        }
    }
    return "nao achou direita";
}
char* esquerda(char nome[], char matriz[L][C]){
    int l, c;
    int ctr;
    int auxC;
    for(l = 0; l < L; l++){
        for(c = 0; c < C; c++){
            if(matriz[l][c] == nome[0]){
                ctr = 0;
                auxC = c;
                while(
                    ctr < strlen(nome) &&
                    auxC >= 0 &&
                    matriz[l][auxC] == nome[ctr]
                ){
                    ctr++;
                    auxC--;
                }
                if(ctr == strlen(nome)){
                    return "achou esquerda";
                }
            }
        }
    }
    return "nao achou esquerda";
}
char* baixo(char nome[], char matriz[L][C]){
    int l, c;
    int ctr;
    int auxL;
    for(l = 0; l < L; l++){
        for(c = 0; c < C; c++){
            if(matriz[l][c] == nome[0]){
                ctr = 0;
                auxL = l;
                while(
                    ctr < strlen(nome) &&
                    auxL < L &&
                    matriz[auxL][c] == nome[ctr]
                ){
                    ctr++;
                    auxL++;
                }
                if(ctr == strlen(nome)){
                    return "achou baixo";
                }
            }
        }
    }
    return "nao achou baixo";
}
char* cima(char nome[], char matriz[L][C]){
    int l, c;
    int ctr;
    int auxL;
    for(l = 0; l < L; l++){
        for(c = 0; c < C; c++){
            if(matriz[l][c] == nome[0]){
                ctr = 0;
                auxL = l;
                while(
                    ctr < strlen(nome) &&
                    auxL >= 0 &&
                    matriz[auxL][c] == nome[ctr]
                ){
                    ctr++;
                    auxL--;
                }
                if(ctr == strlen(nome)){
                    return "achou cima";
                }
            }
        }
    }
    return "nao achou cima";
}
char* diagonalDireitaBaixo(char nome[], char matriz[L][C]){
    int l, c;
    int ctr;
    int auxL;
    int auxC;
    for(l = 0; l < L; l++){
        for(c = 0; c < C; c++){
            if(matriz[l][c] == nome[0]){
                ctr = 0;
                auxL = l;
                auxC = c;
                while(
                    ctr < strlen(nome) &&
                    auxL < L &&
                    auxC < C &&
                    matriz[auxL][auxC] == nome[ctr]
                ){
                    ctr++;
                    auxL++;
                    auxC++;
                }
                if(ctr == strlen(nome)){
                    return "achou diagonal direita baixo";
                }
            }
        }
    }
    return "nao achou diagonal direita baixo";
}
char* diagonalEsquerdaBaixo(char nome[], char matriz[L][C]){
    int l, c;
    int ctr;
    int auxL;
    int auxC;
    for(l = 0; l < L; l++){
        for(c = 0; c < C; c++){
            if(matriz[l][c] == nome[0]){
                ctr = 0;
                auxL = l;
                auxC = c;
                while(
                    ctr < strlen(nome) &&
                    auxL < L &&
                    auxC >= 0 &&
                    matriz[auxL][auxC] == nome[ctr]
                ){
                    ctr++;
                    auxL++;
                    auxC--;
                }
                if(ctr == strlen(nome)){
                    return "achou diagonal esquerda baixo";
                }
            }
        }
    }
    return "nao achou diagonal esquerda baixo";
}
char* diagonalDireitaCima(char nome[], char matriz[L][C]){
    int l, c;
    int ctr;
    int auxL;
    int auxC;
    for(l = 0; l < L; l++){
        for(c = 0; c < C; c++){
            if(matriz[l][c] == nome[0]){
                ctr = 0;
                auxL = l;
                auxC = c;
                while(
                    ctr < strlen(nome) &&
                    auxL >= 0 &&
                    auxC < C &&
                    matriz[auxL][auxC] == nome[ctr]
                ){
                    ctr++;
                    auxL--;
                    auxC++;
                }
                if(ctr == strlen(nome)){
                    return "achou diagonal direita cima";
                }
            }
        }
    }
    return "nao achou diagonal direita cima";
}
char* diagonalEsquerdaCima(char nome[], char matriz[L][C]){
    int l, c;
    int ctr;
    int auxL;
    int auxC;
    for(l = 0; l < L; l++){
        for(c = 0; c < C; c++){
            if(matriz[l][c] == nome[0]){
                ctr = 0;
                auxL = l;
                auxC = c;
                while(
                    ctr < strlen(nome) &&
                    auxL >= 0 &&
                    auxC >= 0 &&
                    matriz[auxL][auxC] == nome[ctr]
                ){
                    ctr++;
                    auxL--;
                    auxC--;
                }
                if(ctr == strlen(nome)){
                    return "achou diagonal esquerda cima";
                }
            }
        }
    }
    return "nao achou diagonal esquerda cima";
}