#include "Layer.hpp"
#include <iostream>

size_t Layer::getLayersize()
{

    return neurons.size();
}

Neuron &Layer::getNeuron(int i)
{

    return neurons[i];
}

void Layer::forward_propagation(Layer &inputs)
{
    // std::cout << "Liczba neuronow w warstwie inputs: " << inputs.getLayersize() << std::endl;
    // std::cout << "neurons size: " << neurons.size() << std::endl;

    for (int i = 0; i < neurons.size(); i++)
    {

        double sum = 0.0;
        for (int j = 0; j < inputs.getLayersize(); ++j)
        {

            // std::cout << "wartosc neurona przed: " << inputs.getNeuron(j).getValue() << std::endl;

            sum += inputs.getNeuron(j).getValue() * inputs.getNeuron(j).getWeight(i);
        }
        sum += 1; // Dodanie biasu
        neurons[i].setValue(sum);
        neurons[i].setSuma(sum);
        neurons[i].setValue(neurons[i].sigmoid_function(sum));
        // std::cout << "wartosc neurona po:  " << neurons[i].getValue() << std::endl;
    }
}

void Layer::display_layer()
{
    for (int i = 0; i < neurons.size(); i++)
        std::cout << "wartosc neuronka " << i + 1 << ": " << neurons[i].getValue() << std::endl;
}

void Layer::make_weights(size_t size)
{
    std::cout << "Wywolano funkcje make_weights1" << std::endl;

    for (int i = 0; i < neurons.size(); i++)
    {
        neurons[i].make_weights(size);
    }
}

void Layer::setNeuronValues(std::vector<double> &values)
{
    for (size_t i = 0; i < values.size(); i++)
    {
        neurons[i].setValue(values[i]);
    }
}