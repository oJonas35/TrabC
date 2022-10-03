#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct aluno {
	char nome[50], curso[50]; 
	float matricula;
    struct aluno * proximo;
}t_aluno;

int main (int argc, char *argv[])
{
	t_aluno * ini_aluno;
	t_aluno * proximo_aluno;
	char str[10];
	
	ini_aluno = (t_aluno *)malloc(sizeof(t_aluno));
	if(ini_aluno == NULL)
		exit(1);
	proximo_aluno = ini_aluno;
	
	while(1)
	{
	 printf("Digite o nome do aluno: ");
	 scanf("%s", &proximo_aluno->nome);
	 printf("Digite a matricula: ");
	 scanf("%f", &proximo_aluno->matricula);
	 printf("Digite o curso: ");
	 scanf("%s", &proximo_aluno->curso);
	 printf("Digite qualquer tecla para continuar ou digite 'fim': ");
	 scanf(" %9[^\n]", str);
	 if(strcmp(str, "fim") == 0) {
        break;
    }
	 else{
	 	proximo_aluno->proximo = (t_aluno *)malloc(sizeof(t_aluno));
	 	proximo_aluno = proximo_aluno->proximo;
	 }
	}
	
	proximo_aluno->proximo = NULL;
	proximo_aluno = ini_aluno;
	while(proximo_aluno != NULL) {
		printf("\n Aluno: %s \n Matricula: %f \n Curso: %s", proximo_aluno->nome, proximo_aluno->matricula, proximo_aluno->curso);
		proximo_aluno = proximo_aluno->proximo;
	}
	return 0;
}
