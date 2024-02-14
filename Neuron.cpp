#include <vector>
#include <iostream>
#include "Neuron.hpp"

double random_number()
{
    // static std::random_device rd;
    // static std::mt19937 gen(rd());
    // static std::uniform_real_distribution<> dis(-1.0, 1.0);
    // return dis(gen);
    return (double)rand() / RAND_MAX * 2.0 - 1.0;
}

void Neuron::display_weights()
{
    std::cout << "Weights: ";
    for (double w : weights_vector)
    {
        std::cout << w << " ";
    }
}

double Neuron::sigmoid_function(double x)
{

    return exp(x) / (1 + exp(x));
}
double Neuron::derivative_sigmoid_function()
{
    double x = suma;
    return exp(x) / ((exp(x) + 1) * (exp(x) + 1));
}

void Neuron::setValue(double value)
{

    this->neuron_value = value;
}

double Neuron::getValue()
{

    return this->neuron_value;
}

size_t Neuron::getWeightsVector()
{
    return weights_vector.size();
}

void Neuron::setSuma(double suma)
{
    this->suma = suma;
}

double Neuron::getSuma()
{
    return suma;
}

void Neuron::make_weights(size_t size)
{

    for (int i = 0; i < size; i++)
    {
        double weight = random_number();
        weights_vector.push_back(weight);
    }
}

double Neuron::getWeight(int waga)
{
    return weights_vector[waga];
}

void Neuron::setWeight(int i, double new_weight)
{
    weights_vector[i] = new_weight;
}

double Neuron::getError()
{
    return error;
}

void Neuron::setError(double error)
{
    this->error = error;
}