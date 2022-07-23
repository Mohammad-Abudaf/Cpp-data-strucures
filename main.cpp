#include <iostream>

#include "node/Node.h"
#include "stack/Stack.h"
#include "stack/FixedStack.h"
#include "listnode/ListNode.h"
#include "queue/StaticQueue.h"
#include "queue/Queue.h"
#include "tree/Tree.h"

int main() {
    BinaryTree<int> binaryTree;

    binaryTree.insert(5);
    binaryTree.insert(10);
    binaryTree.insert(3);
    binaryTree.insert(4);
    binaryTree.insert(10);
    binaryTree.insert(2);
    std::cout << "printing the node values" << std::endl;
    binaryTree.preOrderTraversal(binaryTree.getRootNode());
    std::cout << std::endl;
    binaryTree.postOrderTraversal(binaryTree.getRootNode());
    std::cout << std::endl;
    binaryTree.inOrderTraversal(binaryTree.getRootNode());

    std::cout << std::endl;
    unsigned int result = binaryTree.search(10);

    std::cout << result << std::endl;
    std::cout << std::endl;
    int minValue = binaryTree.getMinValue();
    std::cout << "min value is " << minValue;

    std::cout << std::endl;
    int maxValue = binaryTree.getMaxValue();
    std::cout << "max value is " << maxValue;

    binaryTree.deleteNode(binaryTree.getRootNode(), 5);
    binaryTree.deleteNode(binaryTree.getRootNode(), 10);
    binaryTree.deleteNode(binaryTree.getRootNode(), 2);
    binaryTree.deleteNode(binaryTree.getRootNode(), 3);
    binaryTree.deleteNode(binaryTree.getRootNode(), 4);
    binaryTree.deleteNode(binaryTree.getRootNode(), 10);
    binaryTree.deleteNode(binaryTree.getRootNode(), 10);

    std::cout << std::endl;
    binaryTree.inOrderTraversal(binaryTree.getRootNode());
    return EXIT_SUCCESS;
}
