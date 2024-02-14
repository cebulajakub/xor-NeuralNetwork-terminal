#include <vector>
#include "Neuron.hpp"

#pragma once

class Layer
{
    std::vector<Neuron> neurons;

public:
    Layer() {}

    Layer(const std::vector<double> &neuron_values)
    {
        neurons.reserve(neuron_values.size());
        for (double value : neuron_values)
        {
            neurons.emplace_back(Neuron(0, value, 0, std::vector<double>()));
        }
    }

    Layer(int num_neurons)
    {
        neurons.reserve(num_neurons);
        for (int i = 0; i < num_neurons; ++i)
        {
            neurons.emplace_back(Neuron());
        }
    }
    void forward_propagation(Layer &inputs);
    size_t getLayersize();
    Neuron &getNeuron(int i);

    void display_layer();
    void make_weights(size_t size);
    void display_layer(int layer_number);
    void setNeuronValues(std::vector<double> &values);
};