/***************************************************************************
*  $MCI M�dulo de implementa��o: CAR Carta
*
*  Arquivo gerado:              Carta.c
*  Letras identificadoras:      CAR
*
*
*  Projeto: Disciplinas INF 1301
*  Professor: Flavio
*  Autores: ds  - Daniel Siles
*			fh  - Fernando Homem
*			mr - Mateus Ribeiro
*
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor     Data     Observa��es
*       3.00 ds/fh/mr 26/04/2015 Uniformiza��o da interface das fun��es e
*                                de todas as condi��es de retorno.
*       2.00 ds/fh/mr 22/04/2015 Elimina��o de c�digo duplicado, reestrutura��o
*       1.00 ds/fh/mr 17/04/2015 In�cio do desenvolvimento
*
***************************************************************************/



#include <stdio.h>
#include <malloc.h>
#ifdef _DEBUG
	#include "Generico.h"
	#include "Conta.h"
	#include "cespdin.h"
	#include "IdTiposEspaco.def"
#endif

#pragma pack (1)

#define CARTA_OWN
#include "Carta.h"
#undef CARTA_OWN

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/
int checarFace(char face);
int checarPosicao(char posicao);
int checarNaipe(char Naipe);

/***********************************************************************
*
*  $TC Tipo de dados: carta
*
*
*  $ED Descri��o do tipo
*     Descreve a estrutura carta
*
***********************************************************************/
struct carta{

#ifdef _DEBUG
	int tam;
	int tipo;
#endif

	char face; /*V-> visivel, E->Escondida*/
	char naipe; /*Indica qual naipe a carta pertence (P-> Paus, C-> Copas, E->Espadas, O-> Ouros)*/
	char posicao; /*indica em qual posi��o de uma sequ�ncia completa a carta esta (A,2,3,4,5,6,7,8,9,10,J,Q,K)*/
};

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***********************************************************************
*
*  $FC Fun��o: CAR criar Carta
*
*  $EAE Assertivas de entradas esperadas
*     pCarta != NULL
*
***********************************************************************/
CAR_tpCondRet CAR_criarCarta(CAR_tpCarta *pCarta){
	
	*pCarta = (CAR_tgCarta*)malloc(1 * sizeof(CAR_tgCarta));
	if (*pCarta == NULL){
		return CAR_CondRetMemoria;
	}

	(*pCarta)->face;
	(*pCarta)->naipe;
	(*pCarta)->posicao;

#ifdef _DEBUG
	(*pCarta)->tipo = 'c';
	CED_MarcarEspacoAtivo(pCarta);
#endif

	return CAR_CondRetOK;

}/* Fim fun��o: CAR criar Carta */

/***********************************************************************
*
*  $FC Fun��o: CAR destroir Carta
*
*  $EAE Assertivas de entradas esperadas
*     pCarta != NULL
*
***********************************************************************/
CAR_tpCondRet CAR_destruirCarta(CAR_tpCarta pCarta){
	if (pCarta != NULL){
		free(pCarta); /*Libera o espaco alocado dinamicamente para uma Carta*/
		pCarta = NULL;
	}

	return CAR_CondRetOK;

}/* Fim fun��o: CAR destroir Carta */


/***********************************************************************
*
*  $FC Fun��o: CAR editar Carta
*
*  $EAE Assertivas de entradas esperadas
*     pCarta != NULL
*	  NovaFace, NovoNaipe, NovaPosicao != NULL
***********************************************************************/
CAR_tpCondRet CAR_editarCarta(CAR_tpCarta pCarta, char NovaFace, char NovoNaipe, char NovaPosicao){
	
	if (pCarta == NULL){
		printf("Editar: N�o existe a carta atual!\n");
		return CAR_CondRetCartaNaoExiste;
	}

	if (checarFace(NovaFace) == 0){
		printf("Editar: N�o existe Face valida!\n");
		return CAR_CondRetFaceErrada;
	}

	if (checarNaipe(NovoNaipe) == 0){
		printf("Editar: Nao existe Naipe valido!\n");
		return CAR_CondRetNaipeNaoExiste;
	}

	if (checarPosicao(NovaPosicao) == 0){
		printf("Editar: Nao existe posicao valida!\n");
		return CAR_CondRetPosicaoNaoExiste;
	}
	
	pCarta->face = NovaFace;
	pCarta->naipe = NovoNaipe;
	pCarta->posicao = NovaPosicao;

	
	
	return CAR_CondRetOK;

}/* Fim fun��o: CAR editar Carta */

/***********************************************************************
*
*  $FC Fun��o: checar Face 
*
*  $EAE Assertivas de entradas esperadas
*     face != NULL
*
***********************************************************************/
int checarFace(char face){

	if (face == 'V' || face == 'E'){
		return 1;/*face de acordo com a struct*/
	}
	return 0; /*face invalida*/

}/* Fim fun��o: checar Face */

/***********************************************************************
*
*  $FC Fun��o: checar Posicao
*
*  $EAE Assertivas de entradas esperadas
*     posicao != NULL
*
***********************************************************************/
int checarPosicao(char posicao){
	int i;
	char checador[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
		

		for (i = 0; i < 13; i++){
			
			if (posicao == checador[i]){
				return 1; /*posicao v�lida*/
			}

		}
		
		return 0; /*posicao invalida*/

}/* Fim fun��o: checar Posicao*/

/***********************************************************************
*
*  $FC Fun��o: checar Naipe
*
*  $EAE Assertivas de entradas esperadas
*     Naipe != NULL
*
***********************************************************************/
int checarNaipe(char Naipe){
	if (Naipe == 'P' || Naipe == 'C' || Naipe == 'E' || Naipe == 'O'){
		return 1; /*Naipe valido*/
	}
	return 0; /*Naipe Invalido*/

}/* Fim fun��o: checar Naipe*/

/***********************************************************************
*
*  $FC Fun��o: CAR retorna Posicao
*
*  $EAE Assertivas de entradas esperadas
*     pCarta != NULL && pPosicao != NULL
*
***********************************************************************/
CAR_tpCondRet CAR_retornaPosicao(CAR_tpCarta pCarta, char* pPosicao){
	if (pCarta == NULL){
		return CAR_CondRetCartaNaoExiste;
	}
	
	if (checarPosicao(pCarta->posicao) == 0){
		return CAR_CondRetPosicaoNaoExiste;
	}

	*pPosicao = pCarta->posicao;
	
	return CAR_CondRetOK; /*posicao valido/retornado*/

}/* Fim fun��o: CAR retorna Posicao */


/***********************************************************************
*
*  $FC Fun��o: CAR retorna Naipe
*
*  $EAE Assertivas de entradas esperadas
*     pCarta != NULL && pNaipe != NULL
*
***********************************************************************/
CAR_tpCondRet CAR_retornaNaipe(CAR_tpCarta pCarta, char* pNaipe){
	
	if (pCarta == NULL){
		return CAR_CondRetCartaNaoExiste; 
	}

	if (checarNaipe(pCarta->naipe) == 0){
		return CAR_CondRetNaipeNaoExiste; 
	}

	*pNaipe = pCarta->naipe;

	return CAR_CondRetOK; /*naipe valido/retornado*/

}/* Fim fun��o: CAR retorna Naipe */

/***********************************************************************
*
*  $FC Fun��o: CAR retorna Face
*
*  $EAE Assertivas de entradas esperadas
*     pCarta != NULL && pFace != NULL
*
***********************************************************************/
CAR_tpCondRet CAR_retornaFace(CAR_tpCarta pCarta, char* pFace){
	
	if (pCarta == NULL){
		return CAR_CondRetCartaNaoExiste;
	}

	if (checarFace(pCarta->face) == 0){
		return CAR_CondRetFaceErrada;
	}

	*pFace = pCarta->face;

	return CAR_CondRetOK; /*face valida/retornado*/

}/* Fim fun��o: CAR retorna Face */

/***********************************************************************
*
*  $FC Fun��o: CAR imprime Carta
*
*  $EAE Assertivas de entradas esperadas
*     pCarta != NULL
*
***********************************************************************/
CAR_tpCondRet CAR_imprimeCarta(CAR_tpCarta pCarta){
	if (pCarta == NULL){
		return CAR_CondRetCartaNaoExiste;
	}

	if (checarNaipe(pCarta->naipe) == 0){
		return CAR_CondRetNaipeNaoExiste;
	}

	if (checarPosicao(pCarta->posicao) == 0){
		return CAR_CondRetPosicaoNaoExiste;
	}

	if (checarFace(pCarta->face) == 0){
		return CAR_CondRetFaceErrada;
	}

	printf("\n%c %c ", pCarta->posicao, pCarta->naipe);

	return CAR_CondRetOK;
}/* Fim fun��o: CAR imprime Carta */

#ifdef _DEBUG

CAR_tpCondRet CAR_retornaTipo(CAR_tpCarta cCarta, char *tipo){
	if (cCarta == NULL){
		*tipo = NULL;
		return CAR_CondRetCartaNaoExiste;
	}
	*tipo = cCarta->tipo;
	return CAR_CondRetOK;
}

CAR_tpCondRet CAR_setTipo(CAR_tpCarta cCarta, char tipo){
	cCarta->tipo = tipo;
	return CAR_CondRetOK;
}

#endif

/********** Fim do m�dulo de implementa��o: CAR Carta **********/