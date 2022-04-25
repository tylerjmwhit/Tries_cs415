cmake_minimum_required(VERSION 3.20)
project(cs415Project3)

set(CMAKE_CXX_STANDARD 14)

add_executable(cs415Project3 main.cpp Trie.cpp Trie.hpp TrieNode.hpp TrieNode.cpp Reader.cpp Reader.hpp TrieBST.cpp TrieBST.hpp TreeNode.hpp)
