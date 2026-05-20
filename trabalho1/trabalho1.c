#include <stdio.h>

typedef struct {
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;
} DiasMesesAnos;

int q1(char data[]) {
    int i;
    int achou = 0;
    int ctrDia = 0, ctrMes = 0, ctrAno = 0;
    char dia[10] = {0};
    char mes[10] = {0};
    char ano[10] = {0};
    int intDia = 0, intMes = 0, intAno = 0;
    if (data[0] == '/') {
        return 0;
    }
    for (i = 0; data[i] != '\0'; i++) {
        if (data[i] == '/') {
            achou++;
            if (achou > 2) {
                return 0;
            }
            continue;
        }
        if (data[i] < '0' || data[i] > '9') {
            return 0;
        }
        if (achou == 0) {
            if (ctrDia >= 2) return 0;
            dia[ctrDia] = data[i];
            ctrDia++;
        } else if (achou == 1) {
            if (ctrMes >= 2) return 0;
            mes[ctrMes] = data[i];
            ctrMes++;
        } else if (achou == 2) {
            if (ctrAno >= 4) return 0;
            ano[ctrAno] = data[i];
            ctrAno++;
        }
    }
    if (achou != 2 || ctrDia == 0 || ctrMes == 0 || ctrAno == 0) {
        return 0;
    }
    if (ctrAno != 2 && ctrAno != 4) {
        return 0;
    }
    for (i = 0; i < ctrDia; i++) {
        intDia = (intDia * 10) + (dia[i] - '0');
    }
    for (i = 0; i < ctrMes; i++) {
        intMes = (intMes * 10) + (mes[i] - '0');
    }
    for (i = 0; i < ctrAno; i++) {
        intAno = (intAno * 10) + (ano[i] - '0');
    }
    if (ctrAno == 2) {
        intAno = intAno + 2000;
    }
    if (intMes < 1 || intMes > 12) {
        return 0;
    }
    int diasNoMes = 31;
    if (intMes == 4 || intMes == 6 || intMes == 9 || intMes == 11) {
        diasNoMes = 30;
    } else if (intMes == 2) {
        if ((intAno % 4 == 0 && intAno % 100 != 0) || (intAno % 400 == 0)) {
            diasNoMes = 29;
        } else {
            diasNoMes = 28;
        }
    }
    if (intDia < 1 || intDia > diasNoMes) {
        return 0;
    }
    return 1;
}

DiasMesesAnos q2(char datainicial[], char datafinal[]) {
    DiasMesesAnos dma;
    dma.qtdDias = 0;
    dma.qtdMeses = 0;
    dma.qtdAnos = 0;

    if (q1(datainicial) == 0) {
        dma.retorno = 2;
        return dma;
    }
    if (q1(datafinal) == 0) {
        dma.retorno = 3;
        return dma;
    }
    int dI = 0, mI = 0, aI = 0;
    int dF = 0, mF = 0, aF = 0;
    int i, achou;
    achou = 0;
    for (i = 0; datainicial[i] != '\0'; i++) {
        if (datainicial[i] == '/') {
            achou++;
            continue;
        }
        if (achou == 0) dI = (dI * 10) + (datainicial[i] - '0');
        else if (achou == 1) mI = (mI * 10) + (datainicial[i] - '0');
        else if (achou == 2) aI = (aI * 10) + (datainicial[i] - '0');
    }
    int tamInicial = 0;
    while (datainicial[tamInicial] != '\0') tamInicial++;
    int contaDigitosAnoI = 0;
    achou = 0;
    for(i = 0; i < tamInicial; i++) {
        if(datainicial[i] == '/') { achou++; continue; }
        if(achou == 2) contaDigitosAnoI++;
    }
    if (contaDigitosAnoI == 2) aI = aI + 2000;

    achou = 0;
    for (i = 0; datafinal[i] != '\0'; i++) {
        if (datafinal[i] == '/') {
            achou++;
            continue;
        }
        if (achou == 0) dF = (dF * 10) + (datafinal[i] - '0');
        else if (achou == 1) mF = (mF * 10) + (datafinal[i] - '0');
        else if (achou == 2) aF = (aF * 10) + (datafinal[i] - '0');
    }
    int tamFinal = 0;
    while (datafinal[tamFinal] != '\0') tamFinal++;
    int contaDigitosAnoF = 0;
    achou = 0;
    for(i = 0; i < tamFinal; i++) {
        if(datafinal[i] == '/') { achou++; continue; }
        if(achou == 2) contaDigitosAnoF++;
    }
    if (contaDigitosAnoF == 2) aF = aF + 2000;

    if (aI > aF || (aI == aF && mI > mF) || (aI == aF && mI == mF && dI > dF)) {
        dma.retorno = 4;
        return dma;
    }
    int isBissextoI = ((aI % 4 == 0 && aI % 100 != 0) || (aI % 400 == 0));
    int isBissextoF = ((aF % 4 == 0 && aF % 100 != 0) || (aF % 400 == 0));
    if (dI == 29 && mI == 2 && dF == 28 && mF == 2 && isBissextoI && !isBissextoF) {
        if (aF - aI == 1) {
            dma.qtdAnos = 1;
            dma.qtdMeses = 0;
            dma.qtdDias = 0;
            dma.retorno = 1;
            return dma;
        }
    }
    int anos = aF - aI;
    int meses = mF - mI;
    int dias = dF - dI;
    if (dias < 0) {
        meses = meses - 1;
        int mAnt = mF - 1;
        int aAnt = aF;
        if (mAnt == 0) {
            mAnt = 12;
            aAnt = aAnt - 1;
        }   
        int diasNoMesAnt = 31;
        if (mAnt == 4 || mAnt == 6 || mAnt == 9 || mAnt == 11) {
            diasNoMesAnt = 30;
        } else if (mAnt == 2) {
            if ((aAnt % 4 == 0 && aAnt % 100 != 0) || (aAnt % 400 == 0)) {
                diasNoMesAnt = 29;
            } else {
                diasNoMesAnt = 28;
            }
        }
        dias = dias + diasNoMesAnt;
    }
    if (meses < 0) {
        anos = anos - 1;
        meses = meses + 12;
    }
    dma.qtdAnos = anos;
    dma.qtdMeses = meses;
    dma.qtdDias = dias;
    dma.retorno = 1;
    return dma;
}

int q3(char *texto, char c, int isCaseSensitive) {
    int qtdOcorrencias = 0;
    int i = 0;
    char busca = c;
    if (isCaseSensitive == 0) {
        if (busca >= 'A' && busca <= 'Z') {
            busca = busca + 32;
        }
    }
    while (texto[i] != '\0') {
        char atual = texto[i];
        if (isCaseSensitive == 0) {
            if (atual >= 'A' && atual <= 'Z') {
                atual = atual + 32;
            }
            unsigned char uc = (unsigned char)atual;
            if ((uc >= 192 && uc <= 197) || (uc >= 224 && uc <= 229)) atual = 'a';
            if ((uc >= 200 && uc <= 203) || (uc >= 232 && uc <= 235)) atual = 'e';
            if ((uc >= 204 && uc <= 207) || (uc >= 236 && uc <= 239)) atual = 'i';
            if ((uc >= 210 && uc <= 214) || (uc >= 242 && uc <= 246)) atual = 'o';
            if ((uc >= 217 && uc <= 220) || (uc >= 249 && uc <= 252)) atual = 'u';
        }
        if (atual == busca) {
            qtdOcorrencias++;
        }
        i++;
    }
    return qtdOcorrencias;
}

int q4(char *strTexto, char *strBusca, int posicoes[30]) {
    int qtdOcorrencias = 0;
    int textoLimp[250];
    int buscaLimp[50];
    int lenTextoLimp = 0;
    int lenBuscaLimp = 0;
    int i, j;
    for (i = 0; strTexto[i] != '\0'; i++) {
        if (strTexto[i] != -61 && (unsigned char)strTexto[i] != 195) {
            char c = strTexto[i];
            if (c >= 'A' && c <= 'Z') {
                c = c + 32;
            }
            unsigned char uc = (unsigned char)strTexto[i];
            if (uc == 161 || uc == 162 || uc == 163 || uc == 164 || uc == 165) c = 'a';
            if (uc == 169 || uc == 170 || uc == 171) c = 'e';
            if (uc == 173 || uc == 174 || uc == 175) c = 'i';
            if (uc == 179 || uc == 180 || uc == 181 || uc == 182) c = 'o';
            if (uc == 186 || uc == 187 || uc == 188) c = 'u';
            textoLimp[lenTextoLimp] = c;
            lenTextoLimp++;
        }
    }
    for (i = 0; strBusca[i] != '\0'; i++) {
        if (strBusca[i] != -61 && (unsigned char)strBusca[i] != 195) {
            char c = strBusca[i];
            if (c >= 'A' && c <= 'Z') {
                c = c + 32;
            }
            unsigned char uc = (unsigned char)strBusca[i];
            if (uc == 161 || uc == 162 || uc == 163 || uc == 164 || uc == 165) c = 'a';
            if (uc == 169 || uc == 170 || uc == 171) c = 'e';
            if (uc == 173 || uc == 174 || uc == 175) c = 'i';
            if (uc == 179 || uc == 180 || uc == 181 || uc == 182) c = 'o';
            if (uc == 186 || uc == 187 || uc == 188) c = 'u';
            buscaLimp[lenBuscaLimp] = c;
            lenBuscaLimp++;
        }
    }
    if (lenBuscaLimp == 0 || lenTextoLimp == 0) {
        return 0;
    }
    int idxPos = 0;
    for (i = 0; i <= (lenTextoLimp - lenBuscaLimp); i++) {
        int match = 1;
        for (j = 0; j < lenBuscaLimp; j++) {
            if (textoLimp[i + j] != buscaLimp[j]) {
                match = 0;
                break;
            }
        }
        if (match == 1) {
            if (idxPos < 30) {
                posicoes[idxPos] = i + 1;
                idxPos++;
                posicoes[idxPos] = i + lenBuscaLimp;
                idxPos++;
                qtdOcorrencias++;
                i = i + (lenBuscaLimp - 1);
            }
        }
    }
    return qtdOcorrencias;
}

int q5(int num) {
    int invertido = 0;
    int resto;
    while (num > 0) {
        resto = num % 10;
        invertido = (invertido * 10) + resto;
        num = num / 10;
    }
    return invertido;
}

int q6(int numerobase, int numerobusca) {
    int qtdOcorrencias = 0;
    char baseStr[30] = {0};
    char buscaStr[30] = {0};
    int lenBase = 0;
    int lenBusca = 0;
    int i, j;
    int tempBase = numerobase;
    if (tempBase == 0) {
        baseStr[lenBase] = '0';
        lenBase++;
    }
    while (tempBase > 0) {
        baseStr[lenBase] = (tempBase % 10) + '0';
        lenBase++;
        tempBase = tempBase / 10;
    }
    for (i = 0; i < lenBase / 2; i++) {
        char temp = baseStr[i];
        baseStr[i] = baseStr[lenBase - 1 - i];
        baseStr[lenBase - 1 - i] = temp;
    }
    int tempBusca = numerobusca;
    if (tempBusca == 0) {
        buscaStr[lenBusca] = '0';
        lenBusca++;
    }
    while (tempBusca > 0) {
        buscaStr[lenBusca] = (tempBusca % 10) + '0';
        lenBusca++;
        tempBusca = tempBusca / 10;
    }
    for (i = 0; i < lenBusca / 2; i++) {
        char temp = buscaStr[i];
        buscaStr[i] = buscaStr[lenBusca - 1 - i];
        buscaStr[lenBusca - 1 - i] = temp;
    }
    for (i = 0; i <= (lenBase - lenBusca); i++) {
        int match = 1;
        for (j = 0; j < lenBusca; j++) {
            if (baseStr[i + j] != buscaStr[j]) {
                match = 0;
                break;
            }
        }
        if (match == 1) {
            qtdOcorrencias++;
            i = i + (lenBusca - 1);
        }
    }
    return qtdOcorrencias;
}

int q7(char matriz[8][10], char palavra[5]) {
    int lenPalavra = 0;
    while (palavra[lenPalavra] != '\0' && lenPalavra < 5) {
        lenPalavra++;
    }
    if (lenPalavra == 0) {
        return 0;
    }
    int r, c, d;
    int dr[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int dc[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
    for (r = 0; r < 8; r++) {
        for (c = 0; c < 10; c++) {
            for (d = 0; d < 8; d++) {
                int k;
                int curr_r = r;
                int curr_c = c;
                for (k = 0; k < lenPalavra; k++) {
                    if (curr_r < 0 || curr_r >= 8 || curr_c < 0 || curr_c >= 10) {
                        break;
                    }
                    if (matriz[curr_r][curr_c] != palavra[k]) {
                        break;
                    }
                    curr_r = curr_r + dr[d];
                    curr_c = curr_c + dc[d];
                }           
                if (k == lenPalavra) {
                    return 1;
                }
            }
        }
    }
    return 0;
}