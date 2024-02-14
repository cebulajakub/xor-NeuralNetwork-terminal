#include <vector>
#include "Layer.hpp"

#pragma once

class NeuralNetwork
{
    std::vector<Layer> layers;
    double learning_rate;
    double total_error;

public:
    NeuralNetwork() {}

    NeuralNetwork(const std::vector<Layer> &layer_list) : layers(layer_list) {}

    void display_network();
    void back_propagation(double expected_output);
    double get_learning_rate();
    void set_learning_rate(double rate);
    void forward();
    void setInput(std::vector<double> &values);
    void train(int num_samples);
    void test(const std::vector<std::vector<double>> &test_inputs);

    // Layer getLayer(int i);
};