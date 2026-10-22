#include <iostream>
#include "queuell.h"

int main() {
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    std::cout << "-----Linked List Implementation-----" << std::endl;

    enqueue(&front, &back, '7');
    display(front);
    std::cout << "front: " << front->data << " back: " << back->data << "\n\n";

    enqueue(&front, &back, 'V');
    display(front);
    std::cout << "front: " << front->data << " back: " << back->data << "\n\n";

    enqueue(&front, &back, 'I');
    display(front);
    std::cout << "front: " << front->data << " back: " << back->data << "\n\n";

    enqueue(&front, &back, 'N');
    display(front);
    std::cout << "front: " << front->data << " back: " << back->data << "\n\n";

    enqueue(&front, &back, 'C');
    display(front);
    std::cout << "front: " << front->data << " back: " << back->data << "\n\n";

    enqueue(&front, &back, 'E');

    std::cout << "queue: ";
    display(front);
    std::cout << "front: " << front->data << " back: " << back->data << "\n\n";

    dequeue(&front, &back);

    std::cout << "deque: ";
    display(front);
    std::cout << "front: " << front->data << " back: " << back->data << std::endl;

    return 0;
}