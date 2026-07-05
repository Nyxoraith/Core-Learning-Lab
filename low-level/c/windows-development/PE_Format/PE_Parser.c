#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void epochTime(int rawTime);
long rvaToRaw(DWORD rva, IMAGE_SECTION_HEADER *sectionTable, int numSections);

int main() {
    FILE *file = fopen("calc.exe", "rb");
    if (file == NULL) {
        printf("[ERRO] Ao abrir o arquivo!\n");
        return 1;
    }

    char magic[3] = {0};
    fread(&magic, sizeof(char), 2, file);
    if (magic[0] != 'M' && magic[1] != 'Z'){
        printf("[+] Falha! Cabecalho MZ NÃO encontrado - O Arquivo não é um PE válido!\n");
        return 1;
    }

    printf("[+] Sucesso! Cabecalho MZ encontrado: [%s] - [0x%X%X]\n\n", magic, magic[0], magic[1]);

    DWORD e_lfanew;
    fseek(file, 0x3C, SEEK_SET);
    fread(&e_lfanew, sizeof(DWORD), 1, file);
    printf("[-] O PE Header comeca no offset: 0x%X\n", e_lfanew);

    fseek(file, e_lfanew, SEEK_SET);
    char magicPE[5] = {0};
    fread(magicPE, sizeof(char), 4, file);
    if (magicPE[0] != 'P' && magicPE[1] != 'E'){
        printf("[+] Falha! Cabecalho PE NÃO encontrado!\n");
        return 1;
    }
    printf("[+] Cabecalho PE encontrado: [%s] - [0x%X%X]\n", magicPE, magicPE[0], magicPE[1]);

    WORD machine;
    fread(&machine, sizeof(WORD), 1, file);
    if(machine == 0x14C){
        printf("[+] Sucesso! Campo Machine encontrado: [32 bits] - ");
    }else if(machine == 0x8664){
        printf("[+] Sucesso! Campo Machine encontrado: [64 bits] - ");
    }else{
        printf("[-] Falha! Campo Machine nao encontrado: ");
    }
    printf("[0x%X]\n", machine);

    WORD sections;
    fread(&sections, sizeof(WORD), 1, file);
    printf("[+] Sucesso! Campo NumberOfSections encontrado: [%d sessoes] - [0x%X]\n", sections, sections);

    DWORD timeStamp;
    fread(&timeStamp, sizeof(DWORD), 1, file);
    printf("[+] Sucesso! Campo TimeDateStamp encontrado: ");
    epochTime(timeStamp);

    fseek(file, 0x8, SEEK_CUR);
    WORD sizeOfOptionalHeader;
    fread(&sizeOfOptionalHeader, sizeof(WORD), 1, file);
    printf("[+] Sucesso! Campo SizeOfOptionalHeader encontrado: [%d Bytes]", sizeOfOptionalHeader);


    fseek(file, 0x2, SEEK_CUR);
    long offsetOpcional = ftell(file);
    printf("\n\n[-] Cabecalho Opcional comeca no offset: [0x%lX]\n", offsetOpcional);
    WORD magicPEOP;
    fread(&magicPEOP, sizeof(WORD), 1, file);
    printf("[+] Sucesso! Campo Magic encontrado: ");
    if(magicPEOP == 0x10b){
        printf("[PE32] - [0x%X]\n", magicPEOP);
    }else{
        printf("[PE32+] - [0x%X]\n", magicPEOP);
    }

    fseek(file, 0xE, SEEK_CUR);
    DWORD addressOfEntryPoint;
    fread(&addressOfEntryPoint, sizeof(DWORD), 1, file);
    printf("[+] Sucesso! Campo AddressOfEntryPoint encontrado: [0x%X]\n", addressOfEntryPoint);

    fseek(file, 0x8, SEEK_CUR);
    DWORD imageBase;
    fread(&imageBase, sizeof(DWORD), 1, file);
    printf("[+] Sucesso! Campo ImageBase encontrado: [0x%X]\n", imageBase);

    fseek(file, 0x24, SEEK_CUR);
    WORD subSystem;
    fread(&subSystem, sizeof(WORD), 1, file);
    if(subSystem == 0x1){
        printf("[+] Sucesso! Campo SubSystem encontrado: [Windows Native Driver] - [0x%X]\n", subSystem);
    }else if(subSystem == 0x2){
        printf("[+] Sucesso! Campo SubSystem encontrado: [Windows GUI] - [0x%X]\n", subSystem);
    }else if(subSystem == 0x3){
        printf("[+] Sucesso! Campo SubSystem encontrado: [Windows CLI] - [0x%X]\n", subSystem);
    }else if(subSystem == 0x9){
        printf("[+] Sucesso! Campo SubSystem encontrado: [Windows EFI Application] - [0x%X]\n", subSystem);
    }else{
        printf("[-] Falha! Campo SubSystem NAO encontrado\n");
    }

    if(magicPEOP == 0x10b){
        fseek(file, (offsetOpcional + 0x68), SEEK_SET);
    }else{
        fseek(file, (offsetOpcional + 0x78), SEEK_SET);
    }

    DWORD importRVA;
    DWORD importSize;
    fread(&importRVA, sizeof(DWORD), 1, file);
    fread(&importSize, sizeof(DWORD), 1, file);
    printf("\n[*] Data Directory -> Import Table RVA Alvo: %#010x\n", importRVA);

    fseek(file, offsetOpcional + sizeOfOptionalHeader, SEEK_SET);
    IMAGE_SECTION_HEADER *tabelaSecoes = malloc(sizeof(IMAGE_SECTION_HEADER) * sections);
    char importSectionName[9] = {0};
    DWORD importSectionRVA = 0;
    DWORD importSectionRaw = 0;
    printf("\n-----------------------------------TABELA DE SECOES----------------------------------\n");
    for(int i=0; i<sections; i++){
        fread(&tabelaSecoes[i], sizeof(IMAGE_SECTION_HEADER), 1, file);

        char *sectionName = (char*)tabelaSecoes[i].Name;
        DWORD virtualSize = tabelaSecoes[i].Misc.VirtualSize;
        DWORD virtualAddress = tabelaSecoes[i].VirtualAddress;
        DWORD sizeOfRawData = tabelaSecoes[i].SizeOfRawData;
        DWORD pointerToRawData = tabelaSecoes[i].PointerToRawData;

        printf("[Section %02d] Name: %-8s | RVA: %#010x | Size: %#010x | Offset: %#010x\n", i + 1, sectionName, virtualAddress, virtualSize, pointerToRawData);

        if (importRVA >= virtualAddress && importRVA < (virtualAddress + virtualSize)) { // Usando tamanhoReal
            strcpy(importSectionName, sectionName);
            importSectionRVA = virtualAddress;
            importSectionRaw = pointerToRawData;
        }
    }

    printf("-------------------------------------------------------------------------------------\n");

    if (importSectionRaw == 0) {
        printf("\n[-] Nao foi possivel mapear o RVA da Import Table nas secoes.\n");
    }

    long importTableOffset = rvaToRaw(importRVA, tabelaSecoes, sections);
    if(importTableOffset == 0){
       printf("\n[-] Falha! Diretorio Import Table NAO encontrado!\n");
    }
    printf("\n[+] Sucesso! Diretorio Import Table encontrado: [Section: %s - RVA: 0x%X - Offset: 0x%lX]\n", importSectionName, importSectionRVA, importTableOffset);

    fseek(file, importTableOffset, SEEK_SET);
    printf("\n============================= DLLs e FUNCOES IMPORTADAS =============================\n");
    while (1) {
        DWORD rvaILT;
        fread(&rvaILT, sizeof(DWORD), 1, file);

        fseek(file, 0x8, SEEK_CUR);

        DWORD rvaDllName;
        fread(&rvaDllName, sizeof(DWORD), 1, file);

        DWORD rvaIAT;
        fread(&rvaIAT, sizeof(DWORD), 1, file);

        if (rvaILT == 0 && rvaDllName == 0) {
            break;
        }

        long proximaDLLOffset = ftell(file);
        long dllNameOffsetHD = rvaToRaw(rvaDllName, tabelaSecoes, sections);
        fseek(file, dllNameOffsetHD, SEEK_SET);

        char nomeDLL[128] = {0};
        int ch, idx = 0;
        while ((ch = fgetc(file)) != EOF && ch != '\0' && idx < 127) {
            nomeDLL[idx++] = (char)ch;
        }
        if(idx > 0){
            printf("[+] DLL: %s\n", nomeDLL);
        }

        long iltOffsetHD = rvaToRaw(rvaILT, tabelaSecoes, sections);
        fseek(file, iltOffsetHD, SEEK_SET);

        while(1) {
            DWORDLONG rvaFunction;

            if(magicPEOP == 0x10b){
                DWORD rvaFunction32;
                fread(&rvaFunction32, sizeof(DWORD), 1, file);
                rvaFunction = rvaFunction32;
            }else{
                DWORDLONG rvaFunction64;
                fread(&rvaFunction64, sizeof(DWORDLONG), 1, file);
                rvaFunction = rvaFunction64;
            }

            if(rvaFunction == 0){
                break;
            }

            if(magicPEOP == 0x10b) {
                if(rvaFunction & 0x80000000) continue;
            } else {
                if(rvaFunction & 0x8000000000000000) continue;
            }

            long proximaFunctionOffset = ftell(file);
            long functionNameOffset = rvaToRaw(rvaFunction, tabelaSecoes, sections);
            fseek(file, functionNameOffset, SEEK_SET);

            fseek(file, 0x2, SEEK_CUR);
            char nameFunction[128] = {0};
            int caractere, max = 0;
            while((caractere = fgetc(file)) != EOF && caractere != '\0' && max < 127){
                nameFunction[max++] = (char) caractere;
            }
            if(max > 0) {
                printf("   [-] Function: %s\n", nameFunction);
            }
            fseek(file, proximaFunctionOffset, SEEK_SET);
        }

        fseek(file, proximaDLLOffset, SEEK_SET);
    }
    printf("=======================================================================================\n");

    free(tabelaSecoes);
    fclose(file);
    return 0;
}

void epochTime(int rawTime){
    time_t rawtime = (time_t) rawTime;
    struct tm ts;
    char buf[80];
    ts = *localtime(&rawtime);
    strftime(buf, sizeof(buf), "[%d/%m/%Y - %H:%M:%S]", &ts);
    printf("%s\n", buf);
}

long rvaToRaw(DWORD rva, IMAGE_SECTION_HEADER *sectionTable, int numSections) {
    for(int i = 0; i < numSections; i++) {
        if(rva >= sectionTable[i].VirtualAddress && rva < (sectionTable[i].VirtualAddress + sectionTable[i].Misc.VirtualSize)) {
            return (rva - sectionTable[i].VirtualAddress) + sectionTable[i].PointerToRawData;
        }
    }
    return 0;
}
