#if ! defined( PILHADECARTAS_ )
#define PILHADECARTAS_
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

#if defined( PILHADECARTAS_OWN )
#define PILHADECARTAS_EXT
#else
#define PILHADECARTAS_EXT extern
#endif

#include"Carta.h"
#include"LISTA.h"

typedef struct pilha PILHA_tgPilha;
typedef PILHA_tgPilha *PILHA_tpPilha;


typedef enum {

	PILHA_CondRetOK = 0,
	/* TUDO CERTO */

	PILHA_CondRetPilhaVazia = 1,
	/* A Pilha n�o cont�m elementos */

	PILHA_CondRetFimPilha = 2,
	/* Foi atingido o fim da Pilha */

	PILHA_CondRetNaoEncontrou = 3,
	/* N�o encontrou o valor procurado */

	PILHA_CondRetFaltouMemoria = 4,
	/* Faltou mem�ria ao tentar criar um elemento de lista */
	PILHA_CondRetErroEstrutura = 5

} PILHA_tpCondRet;

/***********************************************************************
*
*  $FC Fun��o: PILHA Criar Pilha
*
*  $ED Descri��o da fun��o
*     Cria uma pilha vazia
*
*  $EP Par�metros
*	pPilha - Endere�o que receber� um ponteiro para a pilha criada.
*
*  $FV Valor retornado
*	PILHA_CondRetOK - Criou a pilha sem erros
*	PILHA_CondRetFaltouMemoria - Faltou mem�ria na cria��o da pilha
*
***********************************************************************/
PILHA_tpCondRet PILHA_criarPilha(PILHA_tpPilha *pPilha);

/***********************************************************************
*
*  $FC Fun��o: PILHA Push Pilha
*
*  $ED Descri��o da fun��o
*     Insere um elemento no topo da pilha.
*
*  $EP Par�metros
*	pPilha - Endere�o que receber� um ponteiro para a pilha na qual ser� inserida uma carta.
*   c - Endere�o da carta a ser inserida no topo da pilha.
*
*  $FV Valor retornado
*	PILHA_CondRetOK - Inseriu o elemento sem erros
*
***********************************************************************/

PILHA_tpCondRet PILHA_pushPilha(PILHA_tpPilha pPilha, CAR_tpCarta c);

/***********************************************************************
*
*  $FC Fun��o: PILHA Pop Pilha
*
*  $ED Descri��o da fun��o
*     Retira o �ltimo elemento inserido na pilha.
*
*  $EP Par�metros
*	pPilha - Endere�o que receber� um ponteiro para a pilha da qual ser� retirada uma carta.
*   pCarta - Endere�o que recebera um ponteiro para a carta retirada da pilha.
*
*  $FV Valor retornado
*	PILHA_CondRetOK - Retirou o elemento sem erros
*	PILHA_CondRetNaoEncontrou - Carta n�o encontrada na pilha
*	PILHA_CondRetFimPilha - Final da pilha foi atingido
*	PILHA_CondRetPilhaVazia - A Pilha est� vazia
*
***********************************************************************/

PILHA_tpCondRet PILHA_popPilha(PILHA_tpPilha pPilha, CAR_tpCarta *pCarta);

/***********************************************************************
*
*  $FC Fun��o: PILHA Libera Pilha
*
*  $ED Descri��o da fun��o
*     Libera a mem�ria utilizada pela pilha.
*
*  $EP Par�metros
*	pPilha - Endere�o do ponteiro com a pilha a ser liberada.
*
*  $FV Valor retornado
*	PILHA_CondRetOK - Pilha liberada com sucesso
*
***********************************************************************/
PILHA_tpCondRet PILHA_liberaPilha(PILHA_tpPilha pPilha);

/***********************************************************************
*
*  $FC Fun��o: PILHA Verifica Pilha Vazia
*
*  $ED Descri��o da fun��o
*     Verifica se a pilha est� vazia.
*
*  $EP Par�metros
*	pPilha - Endere�o do ponteiro com a pilha a ser verificada.
*
*  $FV Valor retornado
*	PILHA_CondRetOK - Pilha recebida n�o est� vazia.
*	PILHA_CondRetPilhaVazia - Pilha recebida est� vazia.
*
*  $EAE Assertivas de entradas esperadas
*     pPilha != NULL
*
***********************************************************************/
PILHA_tpCondRet PILHA_verificaPilhaVazia(PILHA_tpPilha pPilha);

/***********************************************************************
*
*  $FC Fun��o: PILHA Imprime Pilha
*
*  $ED Descri��o da fun��o
*     Imprime as cartas contidas na pilha.
*
*  $EP Par�metros
*	pPilha - Endere�o do ponteiro com a pilha a ser exibida.
*
*  $FV Valor retornado
*	PILHA_CondRetOK - Pilha impressa sem erros.
*
*  $EAE Assertivas de entradas esperadas
*     pPilha != NULL
*
***********************************************************************/
PILHA_tpCondRet PILHA_imprimePilha(PILHA_tpPilha pPilha);

/***********************************************************************
*
*  $FC Fun��o: PILHA Retorna Num Elem
*
*  $ED Descri��o da fun��o
*     Retorna o n�mero de cartas presentes na pilha.
*
*  $EP Par�metros
*	pPilha - Endere�o do ponteiro com a pilha a ser verificada.
*	num - Endere�o com o ponteiro por onde ser� retornado o n�mero de cartas da pilha.
*
*  $FV Valor retornado
*	PILHA_CondRetOK - N�mero de elementos retornado sem erros.
*	
*  $EAE Assertivas de entradas esperadas
*     pPilha != NULL
*
***********************************************************************/
PILHA_tpCondRet PILHA_retornaNumElem(PILHA_tpPilha pPilha, int *num);

#ifdef _DEBUG

PILHA_tpCondRet PILHA_deturpaPilha (PILHA_tpPilha pPilha,int acao, int *numAlocAnt);

#endif

#ifdef _DEBUG

PILHA_tpCondRet PILHA_verificaNo(PILHA_tpPilha pPilha, int numAlocDps);

#endif



#undef PILHADECARTAS_EXT

/********** Fim do m�dulo de defini��o: PILHA PilhadeCartas **********/

#else
#endif