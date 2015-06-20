#if ! defined( CARTA_ )
#define CARTA_ /*NAO APAGAR*/

/***************************************************************************
*
*  $MCD M�dulo de defini��o: CAR Carta
*
*  Arquivo gerado:              Carta.H
*  Letras identificadoras:      CAR
*
*
*  Projeto: Disciplinas INF 1301
*  Professor: Flavio
*  Autores: ds	- Daniel Siles
*			fh	- Fernando Homem
*			mr	- Mateus Ribeiro
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor         Data     Observa��es
*       3.00 ds/fh/mr 26/04/2015 Uniformiza��o da interface das fun��es e
*                                de todas as condi��es de retorno.
*       2.00 ds/fh/mr 22/04/2015 Elimina��o de c�digo duplicado, reestrutura��o
*       1.00 ds/fh/mr 17/04/2015 In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa um conjunto simples de fun��es para criar e
*     explorar cartas.
*
***************************************************************************/

#if defined( CARTA_OWN )/*NAO APAGAR*/
#define CARTA_EXT
#else/*NAO APAGAR*/
#define CARTA_EXT extern
#endif/*NAO APAGAR*/

typedef struct carta CAR_tgCarta;
typedef CAR_tgCarta *CAR_tpCarta;

typedef enum{

	CAR_CondRetOK = 0,
	/*Tudo certo*/

	CAR_CondRetCartaNaoExiste = 1,
	/*A carta nao existe*/

	CAR_CondRetNaipeNaoExiste = 2,
	/*O naipe nao existe || invalido*/

	CAR_CondRetPosicaoNaoExiste = 3,
	/*A numeracao nao existe || invalida*/

	CAR_CondRetFaceErrada = 4,
	/*Face inserida � invalida*/

	CAR_CondRetMemoria = 5
	/*Excedeu limite de memoria*/

} CAR_tpCondRet;



/***********************************************************************
*
*  $FC Fun��o: CAR Criar Carta
*
*  $ED Descri��o da fun��o
*     Cria uma carta de baralho vazia
*
*  $EP Par�metros
*	pCarta - Endere�o que receber� um ponteiro para a carta criada.
*
*  $FV Valor retornado
*	CAR_CondRetOK - Criou OK
*	CAR_CondRetFaltouMemoria - Faltou mem�ria na cria��o da pilha
*
***********************************************************************/
CAR_tpCondRet CAR_criarCarta(CAR_tpCarta *pCarta); /*Cria uma carta(dinamicamente)*/

/***********************************************************************
*
*  $FC Fun��o: CAR Destroi Carta
*
*  $ED Descri��o da fun��o
*     Destroi uma carta de baralho liberando seu espa�o
*
*  $EP Par�metros
*	pCarta - Endere�o que receber� um ponteiro para a carta a ser destruida.
*
*  $FV Valor retornado
*	CAR_CondRetOK - Destruiu OK
*
***********************************************************************/
CAR_tpCondRet CAR_destruirCarta(CAR_tpCarta pCarta);
/***********************************************************************
*
*  $FC Fun��o: CAR Editar Carta
*
*  $ED Descri��o da fun��o
*     Edita/Preenche uma carta de baralho
*
*  $EP Par�metros
*	pCarta - Endere�o que receber� um ponteiro para a carta a ser editada/preenchida.
*	NovaFace - char contendo a informa��o se a carta est� Visivel ('V') ou Escondida ('E').
*	NovaNaipe - char contendo a informa��o do naipe da carta Espadas ('E'), Ouro ('O') , Paus ('P') , Copas ('C').
*	NovaPosicao - char contendo a informa��o da posicao da carta 'A','2','3','4','5','6','7','8','9','10','J','Q','K'.
*
*  $FV Valor retornado
*	CAR_CondRetCartaNaoExiste - Carta passada no par�metro nao existe
*	CAR_CondRetFaceErrada - Face passada no par�metro � inv�lida
*	CAR_CondRetNaipeNaoExiste - Naipe passado no par�metro � inv�lido
*	CAR_CondRetPosicaoNaoExiste - Posicao passada no par�metro � inv�lida
*	CAR_CondRetOK - Editou/Preencheu OK
*
***********************************************************************/
CAR_tpCondRet CAR_editarCarta(CAR_tpCarta pCarta, char NovaFace, char NovoNaipe, char NovaPosicao);/*Edita/Preenche uma carta*/
/***********************************************************************
*
*  $FC Fun��o: CAR Seta Posicao da Carta
*
*  $ED Descri��o da fun��o
*     Seta a posicao de uma carta de baralho
*
*  $EP Par�metros
*	pCarta - Endere�o que receber� um ponteiro para a carta a ser editada/preenchida.
*	pPosicao - Ponteiro char contendo a informa��o da posicao da carta 'A','2','3','4','5','6','7','8','9','10','J','Q','K'.
*
*  $FV Valor retornado
*	CAR_CondRetCartaNaoExiste - Carta passada no par�metro nao existe
*	CAR_CondRetPosicaoNaoExiste - Posicao passada no par�metro � inv�lida
*	CAR_CondRetOK - Editou/Preencheu OK
*
***********************************************************************/
CAR_tpCondRet CAR_retornaPosicao(CAR_tpCarta pCarta, char* pPosicao);
/***********************************************************************
*
*  $FC Fun��o: CAR Seta Naipe da Carta
*
*  $ED Descri��o da fun��o
*     Seta o naipe de uma carta de baralho
*
*  $EP Par�metros
*	pCarta - Endere�o que receber� um ponteiro para a carta a ser editada/preenchida.
*	pNaipe - Ponteiro char contendo a informa��o do naipe da carta Espadas ('E'), Ouro ('O') , Paus ('P') , Copas ('C').
*
*  $FV Valor retornado
*	CAR_CondRetCartaNaoExiste - Carta passada no par�metro nao existe
*	CAR_CondRetNaipeNaoExiste - Naipe passado no par�metro � inv�lido
*	CAR_CondRetOK - Editou/Preencheu OK
*
***********************************************************************/
CAR_tpCondRet CAR_retornaNaipe(CAR_tpCarta pCarta, char* pNaipe);
/***********************************************************************
*
*  $FC Fun��o: CAR Seta Face da Carta
*
*  $ED Descri��o da fun��o
*     Seta a face de uma carta de baralho
*
*  $EP Par�metros
*	pCarta - Endere�o que receber� um ponteiro para a carta a ser editada/preenchida.
*	pFace - Ponteiro char contendo a informa��o se a carta est� Visivel ('V') ou Escondida ('E').
*
*  $FV Valor retornado
*	CAR_CondRetCartaNaoExiste - Carta passada no par�metro nao existe
*	CAR_CondRetFaceErrada - Face passada no par�metro � inv�lida
*	CAR_CondRetOK - Editou/Preencheu OK
*
***********************************************************************/
CAR_tpCondRet CAR_retornaFace(CAR_tpCarta pCarta, char* pFace);
/***********************************************************************
*
*  $FC Fun��o: CAR Imprime Carta
*
*  $ED Descri��o da fun��o
*     Imprime a posicao , face e naipe de uma carta de baralho
*
*  $EP Par�metros
*	pCarta - Endere�o que receber� um ponteiro para a carta a ser editada/preenchida.
*
*  $FV Valor retornado
*	CAR_CondRetCartaNaoExiste - Carta passada no par�metro nao existe
*	CAR_CondRetFaceErrada - Face da carta � inv�lida
*	CAR_CondRetNaipeNaoExiste - Naipe da carta � inv�lido
*	CAR_CondRetPosicaoNaoExiste - Posicao da carta � inv�lida
*	CAR_CondRetOK - Editou/Preencheu OK
*
***********************************************************************/
CAR_tpCondRet CAR_imprimeCarta(CAR_tpCarta pCarta);




#undef CARTA_EXT /*NAO APAGAR*/

/********** Fim do m�dulo de defini��o: CAR Carta **********/

#else/*NAO APAGAR*/
#endif/*NAO APAGAR*/
