// Pre-requisitos
#include <locale.h> // Biblioteca para adicionar caracteres especiais em PT-BR
#include <stdio.h>  // Biblioteca para entrada/saida de dados

// ______________ Minhas funcoes personalizadas ______________
// bubble_sort
void bubble_sort(int vetor[], int tam){
	//variável auxiliar
	int proximo = 0;

	//varre todo o vetor externo
	for(int i = 0; i < tam; i++){
		//trabalha com os próximos elementos
		for(int j = 0; j < (tam - 1); j++){
			//Ocorre a troca
	        if(vetor[j] > vetor[j+1]){
	        	proximo = vetor[j];
	        	vetor[j] = vetor[j+1];
	        	vetor[j+1]=proximo;
	        }
	    }
	 }
}



// select_sort
void select_sort(int vetor[], int tam){
  int menor, troca;
  //Loop externo para repassar todo vetor
  for(int i = 0; i < (tam-1); i++){
	//variável para acompanhar o loop for pegando sempre o menor elemento
	menor = i;
	//Loop interno para trabalhar com o próximo elemento
    for(int j = (i+1); j < tam; j++){
      if(vetor[j] < vetor[menor]){
        menor = j;
      }
    }
    //Onde ocorre a troca
    if(i != menor){
      troca = vetor[i];
      vetor[i] = vetor[menor];
      vetor[menor] = troca;
    }
  }
}



// insert_sort
void insert_sort(int vetor[], int tam){
  int troca;

  //Percorre todo o vetor
  for(int i = 1; i < tam; i++){
    int proximo = i;

    //Responsável pelas trocas
    while((proximo != 0) && (vetor[proximo] < vetor[proximo - 1])){
      troca = vetor[proximo];
      vetor[proximo] = vetor[proximo - 1];
      vetor[proximo - 1] = troca;
      proximo--;
    }
  }
}



// shell_sort
void shell_sort(int vetor[], int tam){
	//variável  auxiliar
    int grupo = 1;

    //Gera o tamanho do grupo de acordo com o tamanho do vetor
    while(grupo < tam){
    	grupo = 3 * grupo + 1;
    }

    //Varre o vetor enquanto houver grupos para ordenar
    while(grupo > 1){
    	//Dividimos o grupo em 3 partes
    	grupo /= 3;
    	//Varremos cada grupo
        for(int i = grupo; i < tam; i++){
            int troca = vetor[i];
            int j = i - grupo;
            //realiza a troca
            while(j >= 0 && troca < vetor[j]){
            	vetor[j + grupo] = vetor[j];
                j -= grupo;
            }
            //realiza a troca
            vetor[j + grupo] = troca;
        }
    }
}



//quick_sort
void quick_sort(int vetor[], int tam){
    int i, j, grupo, troca;

    //Critério de parada da recursividade!
    if(tam < 2){
        return; //sai da função
    }else{
    	grupo = vetor[tam / 2];
    }

    //Fazendo um loop único se comportar como dois
    //Veja que estamos utilizando tanto a variável 'i'
    //quanto a variável 'j'.
    //Veja que não temos critério de parada aqui...
    for(i = 0, j = tam - 1;; i++, j--){

    	//Fazemos a movimentação dos elementos no vetor
        while(vetor[i] < grupo){
            i++;
        }

        //Fazemos a movimentação dos elementos no vetor
        while(grupo < vetor[j]){
            j--;
        }
        //Critério de parada do loop
        if(i >= j){
            break;
        }else{
        	//Onde ocorre as trocas
			troca = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = troca;
        }
    }
    //Usando recursividade para ordenar os grupos
    quick_sort(vetor, i);
    quick_sort(vetor + i, tam - i);
}

// RADIX
#include <stdio.h>

// Função para calcular o numero de digitos de um determinado valor
int nDigitos (int n){
	if (n/10==0){
    	return 1;
    }else{
    	return(1+nDigitos(n/10));
    }
}

// Função para encontra o maximo de digitos de um objeto de um determinado vetor

int maxDigVet(int vetor[], int tam){
	int temporario=0, i=0, resposta=1;
	for(0; i < tam; i++){
		temporario = nDigitos(vetor[i]);
		if(temporario>resposta){
			resposta =temporario;
		}
	}
	return resposta;
}

int encontreDig(int observacao, int posicao){
	posicao = posicao +1 ; // Porque no nosso pacote vou informar a posicao em um vetor, nao a visualizacao humana dessa posicao
	int i, multiplicador =1,a,b,resposta;
	for(i=0;i<posicao;i++){
		multiplicador = multiplicador*10;
	}

	a = observacao/multiplicador; // encontre o numero de casa decimais acima
	b = observacao -(multiplicador*a); // elimine as casas decimais a esquerda
	resposta = b/(multiplicador/10); // elimine as casas decimais a direita

	return resposta;
}

void radix_sort(int vetor[], int tam, int nDig){
	int vetorAux [tam];
	int vetorRef[10] ;
	int i, p, digitoVetor, rodadaDigito, acumulador=0, posicao;

	// Para cada digito (rodadaDigito)
	for(rodadaDigito=0;rodadaDigito < nDig;rodadaDigito++){

		// Zerar o vetor vetorRef
		for(p=0; p < 10; p++){
			vetorRef[p] = 0;
		}


		// Para cada elemento do vetor. Encontre o valor do DIGITO referente a rodada e atualize a tabela vetorRef
		for(p=0; p < tam; p++){
			digitoVetor=encontreDig(vetor[p],rodadaDigito); // Encontre o digito do elemento em questao
			vetorRef[digitoVetor]=vetorRef[digitoVetor]+1; // Atualizar vetor de referencia
		}


		// Soma numero de elementos com cada terminacao na tabela vetorRef
		acumulador = vetorRef[0];
		for(p=1; p < 10; p++){
			acumulador = vetorRef[p]+ acumulador;
			vetorRef[p] = acumulador;
		}


		// Atualizar dados do vetor auxiliar
		for(p=tam-1; p >=0; p--){
			digitoVetor=encontreDig(vetor[p],rodadaDigito); // Encontre o valor do Digito em questao e atualize a tabela vetorRef
			// encontre a posição na tabl vetorRef
			vetorRef[digitoVetor] = vetorRef[digitoVetor]-1; // Diminui 1 da referencia
			posicao = vetorRef[digitoVetor];
			vetorAux[posicao]=vetor[p];
		}


		// Transfere os valores do vetorAux para o vetor original
		for(p=0; p < tam; p++){
			vetor[p] = vetorAux[p];
		}

	}
}
