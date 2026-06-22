#include <algorithm>
#include <iostream>
#include <vector>

void binarySearchOnPiles(int sIdx, int eIdx, std::vector<int> &lastLabelFromPile, int comp) {
    if (sIdx > eIdx) return;
    int middle = sIdx + (eIdx - sIdx) / 2;
    int initialLabel = lastLabelFromPile[middle - 1] + 1;
    bool isOnInterval = comp >= initialLabel && comp <= lastLabelFromPile[middle];
    if (isOnInterval) {
        std::cout << middle << "\n";
    } else if (lastLabelFromPile[middle] < comp) {
        binarySearchOnPiles(middle + 1, eIdx, lastLabelFromPile, comp);
    } else {
        binarySearchOnPiles(sIdx, middle - 1, lastLabelFromPile, comp);
    }
}

void codef474B() {
    // Receber o numero de pilhas possíveis n
    int pileSize = 0;
    std::cin >> pileSize;

    // Receber o numero de minhocas por pilha
    std::vector<int> wormsPerPile(pileSize + 1);
    wormsPerPile[0] = 0;
    for (int i = 1; i <= pileSize; i++) {
        std::cin >> wormsPerPile[i];
    }

    // Receber o numero de michocas boas
    int goodWormsSize = 0;
    std::cin >> goodWormsSize;

    // Receber o indice das minhocas boas
    std::vector<int> goodWorms(goodWormsSize);
    for (int i = 0; i < goodWormsSize; i++) {
        std::cin >> goodWorms[i];
    }

    // Criar um vetor que mapeia sempre o último label da pilha em questão
    std::vector<int> lastLabelFromPile(pileSize + 1);
    lastLabelFromPile[0] = 0;

    // O(n+1) -> Mapeamento de últimos valores
    for (int pileIdx = 1; pileIdx <= pileSize; pileIdx++) {
        lastLabelFromPile[pileIdx] = lastLabelFromPile[pileIdx - 1] + wormsPerPile[pileIdx];
    }

    // Acha a pilha da minhoca escolhida
    for (int i = 0; i < goodWormsSize; i++) {
        binarySearchOnPiles(1, pileSize, lastLabelFromPile, goodWorms[i]);
    }
}