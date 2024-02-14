#include "NeuralNetwork.hpp"
#include <vector>
#include <iostream>
#include <cmath>
void NeuralNetwork::display_network()
{
    std::cout << "Neural Network:" << std::endl;
    for (int i = 0; i < layers.size(); ++i)
    {
        std::cout << "Layer " << i + 1 << ":" << std::endl;
        layers[i].display_layer();
        std::cout << std::endl;
    }
}

std::vector<double> random_input()
{
    std::vector<double> result(2);

    // double rand_num1 = rand() % 2;
    //  double rand_num2 = rand() % 2;

    result[0] = rand() % 2; // rand_num2;
    // double rand_num2 = rand() % 2;

    result[1] = rand() % 2;

    // std::cout << "rel1" << result[0] << " rel2" << result[1] << std::endl;

    return result;
}

double expected(const std::vector<double> &input)
{
    if ((input[0] == 1.0 && input[1] == 1.0) || (input[0] == 0.0 && input[1] == 0.0))
    {
        return 0.0;
    }
    else
    {
        return 1.0;
    }
}

void NeuralNetwork::back_propagation(double expected_output)
{
    learning_rate = 0.03;
    double error1 = 0.0;
    Layer &output_layer = layers.back();
    // obliczanie błedu
    for (int i = 0; i < output_layer.getLayersize(); ++i)
    {

        Neuron &neuron = output_layer.getNeuron(i);
        double output_error = expected_output - neuron.getValue();
        error1 = pow(neuron.getValue() - expected_output, 2);
        neuron.setError(output_error * neuron.derivative_sigmoid_function());
    }
    error1 /= layers.back().getLayersize();
    total_error = error1;

    // propagacja przez warstwy
    double error = 0.0;
    for (int i = layers.size() - 2; i >= 0; --i)
    {
        for (int j = 0; j < layers[i].getLayersize(); ++j)
        {
            error = layers[i].getNeuron(j).getError();
            for (int k = 0; k < layers[i].getNeuron(j).getWeightsVector(); k++)
            {
                error += layers[i + 1].getNeuron(k).getError() * layers[i].getNeuron(j).getWeight(k);
            }
            layers[i].getNeuron(j).setError(error * layers[i].getNeuron(j).derivative_sigmoid_function());
        }
    }

    // aktualizacja wag
    for (int i = layers.size() - 2; i >= 0; --i)
    {
        for (int j = 0; j < layers[i].getLayersize(); ++j)
        {

            for (int k = 0; k < layers[i].getNeuron(j).getWeightsVector(); k++)
            {

                double waga = layers[i].getNeuron(j).getWeight(k) + learning_rate * layers[i + 1].getNeuron(k).getError() * layers[i].getNeuron(j).getValue();
                layers[i].getNeuron(j).setWeight(k, waga);
            }
        }
    }
}

double NeuralNetwork::get_learning_rate()
{
    return learning_rate;
}

void NeuralNetwork::set_learning_rate(double rate)
{
    learning_rate = rate;
}

void NeuralNetwork::forward()
{
    for (int i = 1; i < layers.size(); ++i)
    {
        layers[i].forward_propagation(layers[i - 1]);
    }
}

void NeuralNetwork::setInput(std::vector<double> &values)
{
    layers[0].setNeuronValues(values);
}

void NeuralNetwork::train(int num_samples)
{

    std::cout << "Training data:" << std::endl;
    for (int j = 0; j < num_samples; ++j)
    {
        std::vector<double> input = random_input();

        double exp_output = expected(input);

        setInput(input);
        forward();
        back_propagation(exp_output);
    }
    // display_network();
    std::cout << "Training completed." << std::endl;
}

void NeuralNetwork::test(const std::vector<std::vector<double>> &test_inputs)
{
    for (size_t i = 0; i < test_inputs.size(); ++i)
    {
        std::vector<double> input = test_inputs[i];
        setInput(input);
        forward();
        std::cout << "**********************TEST " << i + 1 << std::endl;
        display_network();
    }
}

// void NeuralNetwork::back_propagation(const std::vector<double> &expected_output)
// {
//     learning_rate = 0.03;
//     Layer &output_layer = layers.back();
//     // obliczanie błedu
//     for (int i = 0; i < output_layer.getLayersize(); ++i)
//     {

//         Neuron &neuron = output_layer.getNeuron(i);
//         double output_error = expected_output[i] - neuron.getValue();
//         double error = pow(neuron.getValue() - expected_output[i], 2);
//         neuron.setError(output_error * neuron.derivative_sigmoid_function());
//         // std::cout << "gecik " << neuron.getError() << std::endl;
//     }
//     // propagacja przez warstwy
//     double error = 0.0;
//     for (int i = layers.size() - 2; i >= 0; --i)
//     {
//         for (int j = 0; j < layers[i].getLayersize(); ++j)
//         {
//             error = layers[i].getNeuron(j).getError();
//             for (int k = 0; k < layers[i].getNeuron(j).getWeightsVector(); k++)
//             {
//                 error += layers[i + 1].getNeuron(k).getError() * layers[i].getNeuron(j).getWeight(k);
//             }
//             layers[i].getNeuron(j).setError(layers[i].getNeuron(j).getError() * layers[i].getNeuron(j).derivative_sigmoid_function());
//         }
//     }

//     // aktualizacja wag
//     for (int i = layers.size() - 2; i >= 0; --i)
//     {
//         for (int j = 0; j < layers[i].getLayersize(); ++j)
//         {

//             for (int k = 0; k < layers[i].getNeuron(j).getWeightsVector(); k++)
//             {

//                 double waga = layers[i].getNeuron(j).getWeight(k) + learning_rate * layers[i + 1].getNeuron(k).getError() * layers[i].getNeuron(j).getValue();
//                 layers[i].getNeuron(j).setWeight(k, waga);
//             }
//         }
//     }
// }