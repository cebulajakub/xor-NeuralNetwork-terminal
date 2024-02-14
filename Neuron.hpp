#include <vector>
#include <ctime>
#include <random>

#pragma once

class Neuron
{
    int number_neurons;
    double suma; // suma
    double neuron_value;
    std::vector<double> weights_vector;
    double error;
    // double bias;

public:
    Neuron() : number_neurons(0), neuron_value(0), suma(0), error(0) {}

    Neuron(int num_neurons, double value, double suma, const std::vector<double> &weights)
        : number_neurons(num_neurons), neuron_value(value), suma(suma), weights_vector(weights) {}

    // void make_weights(Neuron &input, size_t size /*std::vector<Neuron> &vec_next*/);
    void make_weights(/*std::vector<Neuron> &vec_next*/ size_t size);
    void display_weights();
    double sigmoid_function(double x);
    void setValue(double value);
    double getValue();
    size_t getWeightsVector();
    void setSuma(double suma);
    double getSuma();
    void setWeight(int i, double new_weight);
    double getWeight(int weight);
    double getError();
    void setError(double error);
    double derivative_sigmoid_function();
};