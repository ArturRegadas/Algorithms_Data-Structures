#include <iostream>
#include <queue>
#include <vector>

int main() {
    // Criando uma fila de prioridade (min-heap)
    std::priority_queue<int, std::vector<int>, std::greater<>> min_heap;//std::greater<> remover para uma max heap

    // Adicionando elementos
    min_heap.push(4);
    min_heap.push(10);
    min_heap.push(3);
    min_heap.push(5);
    min_heap.push(1);

    // Exibindo e removendo elementos da fila
    std::cout << "Elementos da fila de prioridade (Min-Heap): ";
    while (!min_heap.empty()) {
        std::cout << min_heap.top() << " "; // Acessa o menor elemento
        min_heap.pop(); // Remove o menor elemento
    }

    return 0;
}
