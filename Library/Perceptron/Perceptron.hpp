// ****************************************************
// * Code by Kidsadakorn Nuallaoong
// * Neural Network - Perceptron
// * Artificial Neuron Network - Single Layer
// ****************************************************

#if !defined(PERCEPTRON_H)
#define PERCEPTRON_H

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class Perceptron
{
    public:
        vector<T> weights = vector<T>();
        T bias = 1;
        T output = 0;

        string activationType = "sigmoid";

    public:
        Perceptron();
        Perceptron(int inputSize);
        ~Perceptron();

        void init(int inputSize);

        void setWeights(const vector<T>& weights);
        void setBias(T bias);
        vector<T> _weights();
        T _bias();

         void typeActivation(string type);
        T activation(T x);

        T feedForward(const vector<T>& inputs);
        T feedForward(const vector<T>& inputs, T bias);

        void train(const vector<T>& inputs,const T target, const T learningRate);

        T getOutput();

        Perceptron<T> cpyEnv() const;

        void display();
};

#endif // PERCEPTRON_H