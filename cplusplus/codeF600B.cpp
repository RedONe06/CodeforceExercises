#include <algorithm>
#include <iostream>
#include <vector>

int binarySearchForEqual(int sIdx, int eIdx, const std::vector<int> &vec, int comp) {
    if (sIdx > eIdx) return sIdx;
    int middle = sIdx + (eIdx - sIdx) / 2;
    if (vec[middle] <= comp) {
        return binarySearchForEqual(middle + 1, eIdx, vec, comp);
    }
    return binarySearchForEqual(sIdx, middle-1, vec, comp);
}

void codeF600B() {
    // Receber n e m
    int n, m;
    std::cin >> n >> m;

    // Receber elementos de a
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Receber elementos de b
    std::vector<int> b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    // Ordena a em nlogN
    std::sort(a.begin(), a.end());

    // Calcular quantos elementos em a são menores ou iguais a bj
    for (int j = 0; j < m; j++) {
        int idxMax = binarySearchForEqual(0, n - 1, a, b[j]);
        // Printar a contagem final
        std::cout << idxMax << " ";
    }
}
