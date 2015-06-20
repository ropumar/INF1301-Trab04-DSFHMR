/***************************************************************************
*  $MCI M�dulo de implementa��o: PILHA PilhadeCartas
*
*  Arquivo gerado:              PilhadeCartas.c
*  Letras identificadoras:      PILHA
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
*		5.00 ds/fh/mr 06/06/2015 Adi��o da fun��o retorna n�mero de elementos.
*		4.00 ds/fh/mr 27/04/2015 Uniformiza��o da interface das fun��es e
*                                de todas as condi��es de retorno - Parte II.
*       3.00 ds/fh/mr 26/04/2015 Uniformiza��o da interface das fun��es e
*                                de todas as condi��es de retorno - Parte I.
*       2.00 ds/fh/mr 22/04/2015 Elimina��o de c�digo duplicado, reestrutura��o
*       1.00 ds/fh/mr 17/04/2015 In�cio do desenvolvimento
*
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#include"Carta.h"
#include"LISTA.h"

#define PILHADECARTAS_OWN
#include "PilhadeCartas.h"
#undef PILHADECARTAS_OWN

struct pilha{
	LIS_tppLista topo;
};

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

void DestruirCarta(void * pValor);

/***********************************************************************
*
*  $FC Fun��o: PILHA criar Pilha
*
*
***********************************************************************/
PILHA_tpCondRet PILHA_criarPilha(PILHA_tpPilha *pPilha){ //Lembrete: a nossa fun��o cria uma pilhas vazia!
	LIS_tpCondRet auxiliar;
	
	*pPilha = NULL;
	*pPilha = (PILHA_tgPilha*)malloc(sizeof(PILHA_tgPilha));
	if (*pPilha == NULL){
		return PILHA_CondRetFaltouMemoria;
	}

	auxiliar = LIS_CriarLista(&((*pPilha)->topo),DestruirCarta);
	if(auxiliar == LIS_CondRetFaltouMemoria){
		return PILHA_CondRetFaltouMemoria;
	}
	
	return PILHA_CondRetOK;

}/* Fim fun��o: PILHA criar Pilha */

/***********************************************************************
*
*  $FC Fun��o: PILHA push Pilha
*
*
***********************************************************************/
PILHA_tpCondRet PILHA_pushPilha(PILHA_tpPilha pPilha, CAR_tpCarta c){
	
	LIS_IrInicioLista(pPilha->topo);
	
	LIS_InserirElementoAntes(pPilha->topo, c);
	
	return PILHA_CondRetOK;

}/* Fim fun��o: PILHA push Pilha */

/***********************************************************************
*
*  $FC Fun��o: PILHA pop Pilha
*
*
***********************************************************************/
PILHA_tpCondRet PILHA_popPilha(PILHA_tpPilha pPilha, CAR_tpCarta *pCarta){
	CAR_tpCondRet cRet;
	char naipe;
	char posicao;
	char face;


	LIS_ObterValor(pPilha->topo, pCarta);
	CAR_retornaFace(*pCarta, &face);
	CAR_retornaNaipe(*pCarta, &naipe);
	CAR_retornaPosicao(*pCarta, &posicao);
	
	LIS_ExcluirElemento(pPilha->topo);

	/*Como foi exclu�do o n� da lista, � necess�rio criar novamente a carta para n�o perder os dados*/
	CAR_criarCarta(pCarta);
	cRet = CAR_editarCarta(*pCarta, face, naipe, posicao);
	
	if (cRet == CAR_CondRetFaceErrada){
		return PILHA_CondRetNaoEncontrou;
	}
	

	return PILHA_CondRetOK;

}/* Fim fun��o: PILHA pop Pilha */

int checarPilha(PILHA_tpPilha pPilha){ //uso interno
	
	if (pPilha->topo == NULL){
		return 0;
		}
	return 1;
}

/***********************************************************************
*
*  $FC Fun��o: PILHA libera Pilha
*
*
***********************************************************************/
PILHA_tpCondRet PILHA_liberaPilha(PILHA_tpPilha pPilha){
	
	if (checarPilha(pPilha) == 0){
		free(pPilha);
		return PILHA_CondRetOK;
	}
	
	LIS_DestruirLista(pPilha->topo); //Esvazia a Lista e depois libera o ponteiro para lista.

	return PILHA_CondRetOK;

}/* Fim fun��o: PILHA libera Pilha */

/***********************************************************************
*
*  $FC Fun��o: PILHA verifica Pilha Vazia
*
*
***********************************************************************/
PILHA_tpCondRet PILHA_verificaPilhaVazia(PILHA_tpPilha pPilha){
	int n;

	if (LIS_retornaNumElementos(pPilha->topo, &n) == LIS_CondRetOK){
		return PILHA_CondRetOK;
	}
	else{
		return PILHA_CondRetPilhaVazia;
	}
}/* Fim fun��o: PILHA verifica Pilha Vazia */

/***********************************************************************
*
*  $FC Fun��o: PILHA imprime Pilha
*
*
***********************************************************************/
PILHA_tpCondRet PILHA_imprimePilha(PILHA_tpPilha pPilha){
	char posicao;
	char face;
	char naipe;

	PILHA_tpPilha auxiliar;
	PILHA_criarPilha(&auxiliar);
	PILHA_tpPilha auxiliar2;
	PILHA_criarPilha(&auxiliar2);
	CAR_tpCarta cAuxiliar;
	CAR_criarCarta(&cAuxiliar);

	if (PILHA_verificaPilhaVazia(pPilha) == PILHA_CondRetPilhaVazia){
		return PILHA_CondRetPilhaVazia;
	}

	while (PILHA_verificaPilhaVazia(pPilha) == PILHA_CondRetOK){
		CAR_criarCarta(&cAuxiliar);
		PILHA_popPilha(pPilha, &cAuxiliar);
		PILHA_pushPilha(auxiliar, cAuxiliar);
	}

	while (PILHA_verificaPilhaVazia(auxiliar) == PILHA_CondRetOK){
		CAR_criarCarta(&cAuxiliar);
		PILHA_popPilha(auxiliar, &cAuxiliar);
		PILHA_pushPilha(auxiliar2, cAuxiliar);
		CAR_retornaFace(cAuxiliar, &face);
		CAR_retornaNaipe(cAuxiliar, &naipe);
		CAR_retornaPosicao(cAuxiliar, &posicao);
		CAR_criarCarta(&cAuxiliar);
		CAR_editarCarta(cAuxiliar, face, naipe, posicao);
		PILHA_pushPilha(pPilha, cAuxiliar);
	}


	while (PILHA_verificaPilhaVazia(auxiliar2) == PILHA_CondRetOK){
		CAR_tpCarta carta;
		CAR_criarCarta(&carta);
		PILHA_popPilha(auxiliar2, &carta);
		CAR_retornaPosicao(carta, &posicao);
		CAR_retornaNaipe(carta, &naipe);
		CAR_retornaFace(carta, &face);
		printf("Carta da Pilha: P: %c N: %c F: %c", posicao, naipe, face);

	}
	return PILHA_CondRetOK;
}/* Fim fun��o: PILHA imprime Pilha */

/***********************************************************************
*
*  $FC Fun��o: PILHA retorna Num Elem
*
*
***********************************************************************/
PILHA_tpCondRet PILHA_retornaNumElem(PILHA_tpPilha pPilha, int *num){
	LIS_retornaNumElementos(pPilha->topo, num);
	return PILHA_CondRetOK;
}/* Fim fun��o: PILHA retorna Num Elem */


void DestruirCarta(void * pValor)
{
	CAR_destruirCarta((CAR_tpCarta)pValor);
}

/********** Fim do m�dulo de implementa��o: PILHA PilhadeCartas **********/