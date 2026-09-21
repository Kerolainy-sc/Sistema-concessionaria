#include <stdio.h>

int main(){

    char continuar;
    int cont;
    int totalClientes, i;
    int qtdAprovados = 0;
    int qtdAnalise = 0;
    int qtdReprovados = 0;

    printf("\n===== SISTEMA DE CONCESSIONARIA - MERCEDES BENZ =====\n");

    printf("Deseja cadastrar um cliente? (S/N): ");
    scanf("%c", &continuar);
    getchar();

    while (continuar == 'S' || continuar == 's') {
    
    printf("Quantos clientes deseja cadastrar para avaliacao? ");
    scanf("%d", &totalClientes);
    getchar(); 

    for (i = 1; i <= totalClientes; i++) {


 char nameCliente[50];
 char dataNascimento[15];
 char cpfCliente[20];
 char emailCliente[45];
 char telefoneCliente[20];
 char tentarNovamente = 'S';
 float rendaMensal;
 float precoCarro = 0.0;
 int opcaoCarro;
 int codigoStatus;


    printf("-------------------------------------\n");
    printf("\nCADASTRO DE CLIENTE %d\n", i);
    printf("------------------------------------\n");

    printf("1-Digite o nome do cliente: ");
    fgets(nameCliente, 50, stdin);

    printf("1.1-Digite a data de nascimento do cliente (dd/mm/aaaa): ");
    fgets(dataNascimento, 15, stdin);

    printf("1.2-Digite o CPF do cliente: ");
    fgets(cpfCliente, 20, stdin);

    printf("1.3-Digite o e-mail do cliente: ");
    fgets(emailCliente, 45, stdin);

    printf("1.4-Digite o numero de telefone do cliente: ");
    fgets(telefoneCliente, 20, stdin);

    printf("2-Digite a renda mensal do cliente (R$): ");
    scanf("%f", &rendaMensal);
    getchar();

///////////////////////////////////////////////////////////

do {
    printf("\n\n-------MENU MODELOS----------\n\n");
    printf("1 - Classe B 180 1.7 Automática  2011 (R$ 37.000)\n");
    printf("2 - C 180 Kompressor 2010 (R$ 59.900)\n");   
    printf("3 - C 180 2013–2016 (R$ 92.000)\n");
    printf("4 - Classe A 200 2016–2018 (R$ 100.000)\n");
    printf("5 - SUV GLA 2025 / 2026 (R$ 362.900,00))\n");
    printf("6 - Classe C Sedan 2025 / 2026 (R$ 396.900)\n");
    printf("7 - GLB 2025 / 2026 (R$ 562.900,00)\n");
    printf("8 - GLE 2025 / 2026 (R$ 784.900,00)\n");
    printf("9 - GT Coupé 2025 / 2026 (R$ 1.735.900,00\n");  
    printf("10 - SUV Classe G 2025 / 2026 (R$ 2.111.900,00) \n");     
    printf("Escolha o numero do modelo desejado: ");
    scanf("%d", &opcaoCarro);
    getchar();

    switch (opcaoCarro) {
            case 1:  precoCarro = 37000.00;   
            break;
            case 2:  precoCarro = 59900.00;   
            break;
            case 3:  precoCarro = 92000.00;   
            break;
            case 4:  precoCarro = 100000.00;  
            break;
            case 5:  precoCarro = 362900.00;  
            break;
            case 6:  precoCarro = 396900.00;  
            break;
            case 7:  precoCarro = 562900.00;  
            break;
            case 8:  precoCarro = 784900.00;  
            break;
            case 9:  precoCarro = 1735900.00; 
            break;
            case 10: precoCarro = 2111900.00; 
            break;
            default:
                printf("Opcao invalida! Atribuindo valor padrao de R$ 37.000,00.\n");
                precoCarro = 37000.00;
                break;
        }

printf("\n------------------------------------\n");
        printf("DADOS CADASTRADOS\n");
        printf("------------------------------------\n");
        printf("Nome do cliente         : %s", nameCliente);
        printf("Data de nascimento      : %s", dataNascimento);
        printf("CPF do cliente          : %s", cpfCliente);
        printf("E-mail do cliente       : %s", emailCliente);
        printf("Telefone do cliente     : %s", telefoneCliente);
        printf("Renda mensal do cliente : R$ %.2f\n", rendaMensal);
        printf("Preco do carro desejado : R$ %.2f\n", precoCarro);

    printf("\n\n========ANALISE DE COMPRA============\n\n");

    if (rendaMensal >= precoCarro * 0.30) {
        codigoStatus = 1;
    } 
    else if (rendaMensal >= precoCarro * 0.15) {
        codigoStatus = 2; 
    } 
    else {
        codigoStatus = 3;
    }

switch (codigoStatus) {
    case 1: 
        printf("Status: COMPRA APROVADA\n");
        printf("Parabéns! Você está apto a realizar a compra do carro desejado.\n");
        qtdAprovados++;
        tentarNovamente = 'N';
        break;

    case 2:
        printf("Status: COMPRA EM ANALISE!\n");
        printf("Seu pedido está em análise. É necessario fiador ou  uma entrada maior.\n");
        qtdAnalise++;
        tentarNovamente = 'N';
        break;

case 3:
    printf("Status: COMPRA NEGADA!\n");
    printf("Renda insuficiente para a faixa deste veiculo.\n");
    qtdReprovados++;
    
    printf("\nDeseja tentar outro modelo? (S/N): "); 
    scanf(" %c", &tentarNovamente);                  
    getchar();                                       

    if (tentarNovamente == 'S' || tentarNovamente == 's') {
        qtdReprovados--;
    }
    break;

    default:
        printf("Status: CÓDIGO INVÁLIDO!\n");
        tentarNovamente = 'N';
        break;
}

printf("--------------------------------------------------\n");

        } while (tentarNovamente == 'S' || tentarNovamente == 's');

    } 

    printf("\nDeseja realizar um novo lote de cadastros? (S/N): ");
    scanf(" %c", &continuar);
    getchar();

}

printf("\n=== RELATORIO FINAL ===\n");
printf("Aprovados  : %d\n", qtdAprovados);
printf("Em Analise : %d\n", qtdAnalise);
printf("Negados    : %d\n", qtdReprovados);

return 0;
} 