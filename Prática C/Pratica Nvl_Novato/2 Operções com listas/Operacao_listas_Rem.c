# include <stdio.h>
# include <stdlib.h>

struct No{ // É a corrente
    int valor; // O osso guardado em cada argola
    struct No* proximo; // Ponteiro para o próximo osso na corrente
};

void removerDoInicio(struct No** inicio) { // '** inicio' são dois ponteiros — é como o dono segurando a corrente com as duas mãos pra ter controle total! 
    if (*inicio != NULL) { // "Tem alguma argola na corrente?" Se o quintal estiver vazio, não faz nada. Não dá pra tirar osso de onde não tem!
        struct No* temp = *inicio;// O dono aponta o dedo pra primeira argola — só pra não esquecer onde ela está!
        *inicio = (*inicio)->proximo; //  A corrente agora começa na SEGUNDA argola! O dono simplesmente ignora a primeira e considera que a corrente começa uma casa à frente.
        free(temp); // Joga a primeira argola no lixo! Libera a memória — sem isso o osso ficaria perdido no quintal ocupando espaço à toa! (memory leak!)
    }
} 

// [1] -> [2] -> [3] -> NULL
// ☝️ início
// Depois de remover do início:
// [1] -> [2] -> [3] -> NULL   ← [1] foi pro lixo 🗑️
//        ☝️ início