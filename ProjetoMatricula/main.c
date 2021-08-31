#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

typedef struct aluno{
    int ra;
    char nome[20];


}aluno;

typedef struct professor{
    int rp;
    char nome[20];

}professor;

typedef struct disciplina{
    int rd;
    char nome[20];

}disciplina;

typedef struct cursa{
    int ra;
    int rd;
}cursa;

typedef struct ministra{
    int rp;
    int rd;
}ministra;

 //Principais
 //Cria��o
void criaAluno(aluno alunos[], int *ca);
void criaProfessor(professor professores[], int *cp);
void criaDisciplina(disciplina disciplinas[], int *cd);

//Exclus�o
void excluiAluno(aluno alunos[]);
void excluiProfessor(professor professores[]);
void excluiDisciplina(disciplina disciplinas[]);

//Forma��o de vinculos
void vinculaAluno(aluno alunos[], disciplina disciplinas[], cursa matriculas[]);
void vinculaProfessor(professor professores[], disciplina discplinas[], ministra vinculos[]);

//Quebra de vinculos
void desvinculaAluno(aluno alunos[], disciplina discplinas[], cursa matriculas[]);
void desvinculaProfessor(professor professores[], disciplina discplinas[], ministra vinculos[]);


//Impress�es
void imprimeDiscAluno(aluno alunos[], disciplina discplinas[], cursa matriculas[]);
void imprimeDiscProfessor(professor professores[], disciplina discplinas[], ministra vinculos[]);
void imprimeAllDisciplina(aluno alunos[], professor professores[], disciplina discplinas[],cursa matriculas[], ministra vinculos[]);
void imprimeAluno(aluno alunos[], int ca);
void imprimeProf(professor professores[], int cp);
void imprimeDisc(disciplina disciplinas[], int cd);
void imprimeProfDisc(disciplina disciplinas[], professor professores[], ministra vinculos[]);
//Auxiliares

int indexa(aluno alunos[], int cod);
int indexad(cursa matriculas[], int cod1, int cod2);
int indexp(professor professores[], int cod);
int indexpd(ministra vinculos[], int cod1, int cod2);
int indexd(disciplina disciplinas[], int cod);






int main(){
    int escolha1  = 0, escolha2 = 0, i = 0, j = 0, cd=0, ca=0, cp=0;
    disciplina disciplinas[20] = { NULL };
    aluno alunos[20] = { NULL };
    professor professores[20] = { NULL };
    cursa matriculas[400] = { NULL};
    ministra vinculos[400] = {NULL};
    while(escolha1 !=7){
        escolha1  = 0;
        escolha2 = 0;
        system("cls");
        printf("BEM VINDO! O que deseja?");
        printf("\n1. Alunos\n2. Professores\n3. Disciplinas\n4. Matricular|Desmatricular alunos em disciplina\n5. Vincular|Desvincular professores de disciplina");
        printf("\n6. Visualizar\n7. Sair do menu\n");
        scanf("%d", &escolha1);
        system("cls");
        if(escolha1 == 1){
            printf("1. Cadastrar Aluno");
            printf("\n2. Excluir Aluno");
            printf("\n3. Voltar para o menu\n");
            scanf("%d", &escolha2);
            if(escolha2 == 1)
                criaAluno(alunos, &ca);
            else if(escolha2 == 2)
                excluiAluno(alunos);
        }
        else if(escolha1 == 2){
            printf("1. Cadastrar Professor");
            printf("\n2. Excluir Professor ");
            printf("\n3. Voltar para o menu\n");
            scanf("%d", &escolha2);
            if(escolha2 == 1)
                criaProfessor(professores, &cp);
            else if(escolha2 == 2)
                excluiProfessor(professores);
        }
        else if(escolha1 == 3){
            printf("1. Cadastrar Disciplina\n");
            printf("2. Excluir Disciplina\n");
            printf("3. Voltar para o menu\n");
            scanf("%d", &escolha2);
            if(escolha2 == 1)
                criaDisciplina(disciplinas, &cd);
            else if(escolha2 == 2)
                excluiDisciplina(disciplinas);
        }
        else if (escolha1 == 4){
            printf("1. Matricular\n2. Desmatricular\n3. Voltar para o menu\n");
            scanf("%d", &escolha2);
            if(escolha2 == 1)
                vinculaAluno(alunos, disciplinas, matriculas);
            else if(escolha2 == 2)
                desvinculaAluno(alunos, disciplinas, matriculas);
        }
        else if(escolha1 == 5){
            printf("1. Vincular\n2. Desvincular\n3. Voltar para o menu\n");
            scanf("%d", &escolha2);
            if(escolha2 == 1)
                vinculaProfessor(professores, disciplinas, vinculos);
            else if(escolha2 == 2)
                desvinculaProfessor(professores, disciplinas,  vinculos);
        }
        else if (escolha1 == 6){
            printf("1. Visualizar disciplinas de aluno\n2. Visualizar disciplinas de professor\n3. Visualizar Alunos e Professores da disciplina\n");
            printf("4. Visualizar todos os professores de uma disciplina\n5. Visualizar lista de todos os professores\n6. Visualizar lista de todos as disciplinas ");
            printf("\n7. Visualizar lista de todos os alunos\n8. Voltar ao menu\n");
            scanf("%d", &escolha2);
            if(escolha2 == 1)
                imprimeDiscAluno(alunos, disciplinas, matriculas);
            else if (escolha2 == 2)
                imprimeDiscProfessor(professores, disciplinas, vinculos);
            else if (escolha2 == 3)
                imprimeAllDisciplina(alunos, professores, disciplinas, matriculas ,vinculos);
            else if (escolha2 == 4)
                imprimeProfDisc(disciplinas, professores, vinculos);
            else if (escolha2 == 5)
                imprimeProf(professores, cp);
            else if (escolha2 == 6)
                imprimeDisc(disciplinas, cd);
            else if (escolha2 == 7)
                imprimeAluno(alunos, ca);

        }
        else if(escolha1 == 7)
        {
            printf("Programa finalizado");
            return;
        }

    }

}

//Cria��o
void criaAluno(aluno alunos[], int *ca){
    int ra, index, i = 0, k;
    char nome[20];
    k=*ca;
    while(i!=2){
        printf("Cadastro de aluno ");
        printf("\nNome: ");
        fflush(stdin);
        gets(nome);
        printf("\nRA: ");
        scanf("%d",&ra);

        index = indexa(alunos, ra);
        if (index != -1){
            printf("RA ja cadastrado\n.");
            system("pause");

        }
        else{

        index = indexa(alunos,0);
        if(index == -1){
            printf("Sem vagas disponiveis.");
            system("pause");

        }
        else{
            strcpy(alunos[index].nome,nome);
            alunos[index].ra = ra;
            k++;
            *ca=k;
        }
        }
        printf("\nDeseja cadastrar outro aluno? (1 - Sim, 2 - Nao)");
        scanf("%d", &i);
    }
    return;
}

void criaProfessor(professor professores[], int *cp){
    int rp, index, i = 0, f;
    char nome[20];
    f=*cp;
    while(i!=2){
        printf("Cadastro de Professor ");
        printf("\nNome: ");
        fflush(stdin);
        gets(nome);
        printf("\nRP: ");
        scanf("%d",&rp);

        index = indexp(professores, rp);
        if (index != -1){
            printf("Registro de Professor ja cadastrado.\n");
            system("pause");

        }
        else{
            index = indexp(professores, NULL);
            if(index == -1){
                printf("Sem vagas disponiveis.\n");
                system("pause");

            }
            else{
                strcpy(professores[index].nome,nome);
                professores[index].rp = rp;

            f++;
            *cp=f;
            }

        }

         printf("\nDeseja cadastrar outro professor? (1 - Sim, 2 - Nao)");
        scanf("%d", &i);
    }
    return;
}

void criaDisciplina(disciplina disciplinas[], int *cd){
    int rd, index, i = 0, j;
    char nome[20];
    j=*cd;
    while(i!=2){
    printf("Cadastro de Disciplina ");
    printf("\nNome: ");
    fflush(stdin);
    gets(nome);
    printf("\nRD: ");
    scanf("%d",&rd);
   index = indexd(disciplinas, rd);
    if (index != -1){
        printf("\nCodigo de Disciplina ja cadastrado.");
        system("pause");

    }
    else{

        index = indexd(disciplinas, NULL);
        if(index == -1){
            printf("Sem vagas disponiveis.");
            system("pause");

        }
        else{
            strcpy(disciplinas[index].nome,nome);
            disciplinas[index].rd = rd;
            j++;
            *cd=j;
    }
    }
        printf("\nDeseja cadastrar outra disciplina? (1 - Sim, 2 - Nao)");
        scanf("%d", &i);
    }
    return;
}

//Exclus�o
void excluiAluno(aluno alunos[]){
    int i = 0, index, ra;
    while(i!=2){
        printf("Exclusao de Aluno");
        printf("\nRA: ");
        scanf("%d", &ra);

        index = indexa(alunos, ra);
        if(index == -1)
        {
            printf("\nAluno Nao existente");

        }
        else{
            alunos[index].ra = NULL;
            alunos[index].nome[0] = '\0';

            printf("\nAluno Excluido");
        }
        printf("\nDeseja excluir outro aluno? (1 - Sim, 2 - Nao)");
        scanf("%d", &i);
    }
    return;

}

void excluiProfessor(professor professores[]){
    int i = 0, index, rp;
    while(i!=2){
        printf("Exclusao de Professor");
        printf("\nRP: ");
        scanf("%d", &rp);

        index = indexp(professores, rp);
        if(index == -1)
        {
            printf("\nProfessor Nao existente");
        }
        else{
            professores[index].rp = NULL;
            professores[index].nome[0] = '\0';

            printf("\nProfessor Excluido");
        }
        printf("\nDeseja excluir outro professor? (1 - Sim, 2 - Nao)");
        scanf("%d", &i);
    }
    return;

}
void excluiDisciplina(disciplina disciplinas[]){
    int i = 0, index, rd;
    while(i!=2){
        printf("Exclusao de Disciplina");
        printf("\nRD: ");
        scanf("%d", &rd);

        index = indexd(disciplinas, rd);
        if(index == -1)
        {
            printf("\nDisciplina Nao existente");
        }
        else{
            disciplinas[index].rd = NULL;
            disciplinas[index].nome[0] = '\0';

            printf("\nDisciplina Excluida");
        }
        printf("\nDeseja excluir outra disciplina? (1 - Sim, 2 - Nao)");
        scanf("%d", &i);
    }
    return;

}
//Forma��o de v�nculos
void vinculaAluno(aluno alunos[], disciplina disciplinas[], cursa matriculas[]){
    int i = 0, index, ra[20], rd[20], escolha3 = 1, escolha4 = 1, j=0, k=0, a=0,b=0, aux;
    while(i!=2){
        printf("Matricula de Aluno");
        while(escolha3 == 1){
        printf("\nRA: ");
        scanf("%d", &aux);
        index = indexa(alunos, aux);
        if(index == -1)
        {
            printf("\nAluno Nao existente\n");
            system("pause");
            j--;

        }
        else
            ra[j] = aux;
        printf("Deseja matricular mais algum aluno? 1- Sim, 2-Nao\n");
        scanf("%d", &escolha3);
        j++;
        }
        while(escolha4 == 1){
        printf("\nRD: ");
        scanf("%d", &aux);
        index = indexd(disciplinas, aux);
        if(index == -1)
        {
            printf("\nDisciplina Nao existente\n");
            system("pause");
            k--;
        }
        else{
            rd[k] = aux;
        }
        printf("Deseja matricular mais alguma disciplina? 1- Sim, 2-Nao\n");
        scanf("%d", &escolha4);
        k++;
        }
        for(a=0;a<j;a++){
                for(b=0;b<k;b++){
            index = indexad(matriculas, ra[a], rd[b]);
            if(index != -1){
                printf("Aluno %d ja foi matriculado.\n",ra[a]);
                system("pause");

            }
                index = indexad(matriculas, NULL, NULL);
                if(index==-1)
            {
                printf("Sem vagas");
            }
                else{
                matriculas[index].ra = ra[a];
                matriculas[index].rd = rd[b];
                printf("Aluno %d matriculado\n", ra[a]);
                }
            }
        }
        printf("\nDeseja matricular outro aluno em uma disciplina? (1 - Sim, 2 - Nao)");
        scanf("%d", &i);
        escolha3=1;
        escolha4=1;
    }
    return;
}

void vinculaProfessor(professor professores[], disciplina disciplinas[], ministra vinculos[]){
    int i = 0, index, rp[20], rd[20], escolha3 = 1, escolha4 = 1, j=0, k=0, a=0,b=0, aux;
    while(i!=2){
        printf("Matricula de Professor");
        while(escolha3 == 1){
        printf("\nRP: ");
        scanf("%d", &aux);
        index = indexp(professores, aux);
        if(index == -1)
        {
            printf("\nProfessor nao existente\n");
            system("pause");
            j--;
        }
        else
            rp[j] = aux;
        printf("Deseja matricular mais algum professor? 1- Sim, 2-Nao\n");
        scanf("%d", &escolha3);
        j++;
        }
        while(escolha4 == 1){
        printf("\nRD: ");
        scanf("%d", &aux);
        index = indexd(disciplinas, aux);
        if(index == -1)
        {
            printf("\nDisciplina Nao existente");
            system("pause");
            k--;
        }
        else
            rd[k] = aux;
        printf("Deseja matricular em mais alguma disciplina? 1- Sim, 2-Nao\n");
        scanf("%d", &escolha4);
        k++;
        }
        for(a=0;a<j;a++){
                for(b=0;b<k;b++){
            index = indexpd(vinculos, rp[a], rd[b]);
            if(index != -1){
                printf("Professor %d ja foi matriculado.\n",rp[a]);
                system("pause");

            }
                index = indexpd(vinculos, NULL, NULL);
                if(index==-1)
            {
                printf("Sem vagas");
            }
                else{
                vinculos[index].rp = rp[a];
                vinculos[index].rd = rd[b];
                printf("Professor %d matriculado\n", rp[a]);
                }
            }
        }
        printf("\nDeseja matricular outro professor em uma disciplina? (1 - Sim, 2 - Nao)");
        scanf("%d", &i);
        escolha3=1;
        escolha4=1;
    }
    return;
}

//Quebra de v�nculos

void desvinculaAluno(aluno alunos[], disciplina disciplinas[], cursa matriculas[]){
    int i = 0, index, ra[20], rd[20], escolha3 = 1, escolha4 = 1, j=0, k=0, a=0,b=0, aux;
    while(i!=2){
        printf("Desmatricula de Aluno");
        while(escolha3 == 1){
        printf("\nRA: ");
        scanf("%d", &aux);
        index = indexa(alunos, aux);
        if(index == -1)
        {
            printf("\nAluno Nao existente\n");
            system("pause");
            j--;
        }
        else
            ra[j] = aux;
        printf("Deseja desmatricular mais algum aluno? 1- Sim, 2-Nao\n");
        scanf("%d", &escolha3);
        j++;
        }
        while(escolha4 == 1){
        printf("\nRD: ");
        scanf("%d", &aux);
        index = indexd(disciplinas, aux);
        if(index == -1)
        {
            printf("\nDisciplina Nao existente");
            system("pause");
            k--;
        }
        else
            rd[k] = aux;
        printf("Deseja desmatricular em mais alguma disciplina? 1- Sim, 2-Nao\n");
        scanf("%d", &escolha4);
        k++;
        }
        for(a=0;a<j;a++){
                for(b=0;b<k;b++){
            index = indexad(matriculas, ra[a], rd[b]);
            if(index == -1){
                printf("Aluno nao matriculado.\n");
                system("pause");
                return;
            }
                else{
                matriculas[index].ra = NULL;
                matriculas[index].rd = NULL;
                printf("Aluno %d desmatriculado\n", ra[a]);
                }
            }
        }
        printf("\nDeseja desmatricular outro aluno em uma disciplina? (1 - Sim, 2 - Nao)");
        scanf("%d", &i);
        escolha3=1;
        escolha4=1;
    }
    return;
}

void desvinculaProfessor(professor professores[], disciplina disciplinas[], ministra vinculos[]){
    int i = 0, index, rp[20], rd[20], escolha3 = 1, escolha4 = 1, j=0, k=0, a=0,b=0,aux;
    while(i!=2){
        printf("Desmatricula de professor");
        while(escolha3 == 1){
        printf("\nRP: ");
        scanf("%d", &aux);
        index = indexa(professores, aux);
        if(index == -1)
        {
            printf("\nProfessor Nao existente\n");
            system("pause");
            j--;
        }
        else
            rp[j] = aux;
        printf("Deseja desmatricular mais algum professor? 1- Sim, 2-Nao\n");
        scanf("%d", &escolha3);
        j++;
        }
        while(escolha4 == 1){
        printf("\nRD: ");
        scanf("%d", &aux);
        index = indexd(disciplinas, aux);
        if(index == -1)
        {
            printf("\nDisciplina Nao existente");
            system("pause");
            k--;
        }
        else
            rd[k] = aux;
        printf("Deseja desmatricular em mais alguma disciplina? 1- Sim, 2-Nao\n");
        scanf("%d", &escolha4);
        k++;
        }
        for(a=0;a<j;a++){
                for(b=0;b<k;b++){
            index = indexpd(vinculos, rp[a], rd[b]);
            if(index == -1){
                printf("Professor ja foi matriculado.\n");
                system("pause");
                return;
            }
                else{
                vinculos[index].rp = NULL;
                vinculos[index].rd = NULL;
                printf("Professor %d desmatriculado\n", rp[a]);
                }
            }
        }
        printf("\nDeseja desmatricular outro professor em uma disciplina? (1 - Sim, 2 - Nao)");
        scanf("%d", &i);
        escolha3=1;
        escolha4=1;
    }
    return;
}

//Impress�es
void imprimeDiscAluno(aluno alunos[], disciplina discplinas[], cursa matriculas[]){
    int i = 0, index, ra;
    printf("\nRA: ");
    scanf("%d", &ra);
    index = indexa(alunos, ra);
        if(index == -1)
        {
            printf("\nAluno Nao existente\n");
            system("pause");
            return;
        }
        else
        {
            printf("Nome: %s\n", alunos[index].nome);
        }
    printf("\nDisciplinas Matriculadas:\n");
    while (i<400){
        if(matriculas[i].ra == ra){
            index = indexd(discplinas, matriculas[i].rd);
            printf("\n%s\n", discplinas[index].nome);

        }

        i++;
    }
    system("pause");
}

void imprimeDiscProfessor(professor professores[], disciplina discplinas[], ministra vinculos[]){
    int i = 0, index, rp;
    printf("\nRP: ");
    scanf("%d", &rp);
    index = indexp(professores, rp);
        if(index == -1)
        {
            printf("\nProfessor Nao existente\n");
            system("pause");
            return;
        }
        else
        {
            printf("Nome: %s\n\n", professores[index].nome);
        }
    printf("\nDisciplinas Vinculadas:\n");
    while (i<400){
        if(vinculos[i].rp == rp){
            index = indexd(discplinas, vinculos[i].rd);
            printf("\n%s\n", discplinas[index].nome);
            }
        i++;
    }
    system("pause");
}

void imprimeAllDisciplina(aluno alunos[], professor professores[], disciplina disciplinas[],cursa matriculas[], ministra vinculos[]){
    int i = 0, index, rd;
    printf("\nRD: ");
    scanf("%d", &rd);
    index = indexd(disciplinas, rd);
    if(index == -1)
        {
            printf("\nDisciplina Nao existente\n");
            system("pause");
            return;
        }
        printf("Nome: %s\n", disciplinas[index].nome);
        printf("\nProfessores Vinculados:\n");
        while (i<400){
            if(vinculos[i].rd == rd){
                index = indexp(professores, vinculos[i].rp);
                printf("\n%s\n", professores[index].nome);
                }
            i++;
        }
        printf("\nAlunos Matriculados:\n");
        i=0;
        while (i<400){
        if(matriculas[i].rd == rd){
            index = indexa(alunos, matriculas[i].ra);
            printf("\n%s\n", alunos[index].nome);
        }
        i++;
    }
    system("pause");
}
void imprimeDisc(disciplina disciplinas[], int cd)
{
    int i;
    for(i=0;i<=cd;i++){
    printf("\n%s", disciplinas[i].nome);
    }
    system("pause");
}
void imprimeAluno(aluno alunos[], int ca)
{
    int i;
    for(i=0;i<=ca;i++){
    printf("\n%s", alunos[i].nome);
    }
    system("pause");
}
void imprimeProf(professor professores[], int cp)
{
    int i;
    for(i=0;i<=cp;i++){
    printf("%s\n", professores[i].nome);
    }
    system("pause");
}
void imprimeProfDisc(disciplina disciplinas[], professor professores[], ministra vinculos[])
{
    int i = 0, index, rd;
    printf("\nRD: ");
    scanf("%d", &rd);
    index = indexd(disciplinas, rd);
        if(index == -1)
        {
            printf("\nDisciplina Nao existente\n");
            system("pause");
            return;
        }
        else
        {
            printf("Nome: %s\n", disciplinas[index].nome);
        }
    printf("\nProfessores Matriculadas:\n");
    while (i<400){
        if(vinculos[i].rd == rd){
            index = indexp(professores, vinculos[i].rp);
            printf("\n%s\n", professores[index].nome);

        }

        i++;
    }
    system("pause");
}
//Auxiliares
int indexa(aluno alunos[], int cod){
    int i = 0;
    while (i<20){
        if(alunos[i].ra == cod)
        return i;
        else
        i++;
    }
    return -1;
}

int indexp(professor professores[], int cod){
    int i = 0;
    while (i<20){
        if(professores[i].rp == cod)
        return i;
        else
        i++;
    }
    return -1;

}

int indexd(disciplina disciplinas[], int cod){
    int i = 0;
    while (i<20){
        if(disciplinas[i].rd == cod)
        return i;
        else
        i++;
    }
    return -1;

}

int indexad(cursa matriculas[], int cod1, int cod2){
    int i = 0;
    while (i<400){
        if(matriculas[i].ra == cod1 && matriculas[i].rd == cod2)
        return i;
        else
        i++;
    }
    return -1;


}

int indexpd(ministra vinculos[], int cod1, int cod2){
    int i = 0;
    while (i<400){
        if(vinculos[i].rp == cod1 && vinculos[i].rd == cod2)
        return i;
        else
        i++;
    }
    return -1;


}


