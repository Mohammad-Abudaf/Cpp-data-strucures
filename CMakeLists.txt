cmake_minimum_required(VERSION 3.22)
project(DataStructures)

set(CMAKE_CXX_STANDARD 11)

add_executable(DataStructures main.cpp node/Node.cpp node/Node.h stack/Stack.cpp stack/Stack.h stack/FixedStack.cpp stack/FixedStack.h listnode/ListNode.cpp listnode/ListNode.h queue/StaticQueue.h queue/Queue.h array/Array.h tree/TreeNode.h tree/Tree.cpp tree/Tree.h)
