#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <random>
#include "NeuralNetwork.hpp"
#include "Neuron.hpp"
#include "Layer.hpp"

using namespace std;

double tanh_function(int x)
{

    return (exp(x) - exp(-x)) / ((exp(x)) + exp(-x));
}

// void train(NeuralNetwork &neural_net, std::vector<std::vector<double>> &inputs, const std::vector<std::vector<double>> &expected_outputs)
// {
//     for (int i = 0; i < 1000000; i++)
//     {
//         for (size_t j = 0; j < inputs.size(); j++)
//         {
//             neural_net.setInput(inputs[j]);

//             neural_net.forward();
//             neural_net.back_propagation(expected_outputs[j]);
//         }
//         // cout << "**********************UCZENIE" << j + 1 << endl;
//         // neural_net.display_network();
//     }
// }

// void test(NeuralNetwork &neural_net, std::vector<std::vector<double>> &inputs)
// {
//     for (size_t j = 0; j < inputs.size(); j++)
//     {
//         neural_net.setInput(inputs[j]);
//         neural_net.forward();
//         cout << "**********************TEST" << j + 1 << endl;
//         neural_net.display_network();
//     }
// }

int main()
{
    srand(time(NULL));

    std::vector<std::vector<double>> inputs = {
        {1, 0},
        {1, 1},
        {0, 1},
        {0, 0}};
    std::vector<std::vector<double>> expected_outputs = {
        {1.0},
        {0.0},
        {1.0},
        {1.0}};

    Layer layer1(2);
    Layer layer2(4);
    Layer layer3(1);

    std::vector<Layer> layers;

    layer1.make_weights(layer2.getLayersize());
    layer2.make_weights(layer3.getLayersize());

    layers.push_back(layer1);
    layers.push_back(layer2);
    layers.push_back(layer3);

    NeuralNetwork neural_net(layers);

    neural_net.train(1000000);
    neural_net.test(inputs);

    // std::cout << "test funkcji:" << std::endl;
    // for (int i = 0; i < 5; ++i)
    // {
    //     std::vector<double> input = random_input();
    //     double exp_output = expected(input);
    //     std::cout << "Input: " << input[0] << ", " << input[1] << " -> Expected output: " << exp_output << std::endl;
    // }

    // train(neural_net, inputs, expected_outputs);
    // test(neural_net, inputs);

    // for (size_t j = 0; j < inputs.size(); j++)
    // {
    //     neural_net.setInput(inputs[j]);

    //     // cout << "****************" << j + 1 << j + 1 << j + 1 << j + 1 << j + 1 << j + 1 << "****************" << endl;

    //     for (int i = 0; i < 100000; i++)
    //     {
    //         neural_net.forward();
    //         neural_net.back_propagation(expected_outputs[j]);
    //     }

    //     // neural_net.display_network();
    // }

    return 0;
}
