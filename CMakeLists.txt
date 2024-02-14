cmake_minimum_required(VERSION 3.10)
project(neural-network VERSION 0.1.0 LANGUAGES C CXX)



add_executable(neural-network main.cpp Neuron.cpp Layer.cpp NeuralNetwork.cpp)


