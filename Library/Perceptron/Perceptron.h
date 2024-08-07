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
    private:
        vector<T> inputs;
        vector<T> weights;
        const T bias = 1;
        T biasW = 0;
        T output = 0;
        T learningRate = 0.1;
        T target = 0;
        T error = 0; // target - output

        T accuracy = 0.1;

        string activationType = "Linear";
    public:
        Perceptron();
        Perceptron(Perceptron<T> *p) {copyEnv(p);};
        ~Perceptron();

        void setInputs(vector<T> inputs);
        void setWeights(vector<T> weights);
        void setBias(T biasW);
        void setLearningRate(T learningRate);
        void setTarget(T target);
        void setError(T error);
        void setAccuracy(T accuracy);

        vector<T> getInputs();
        vector<T> getWeights();
        T getBias();
        T getLearningRate();
        T getTarget();
        T getOutput();

        void copyEnv(Perceptron<T> *p);

        T Err();
        T Err(T target);
        T MSE();
        T MAE();
        T activation(T x);
        void setActivation(string type);

        T feedForward();
        T backpropagate();
        void train(bool verbose = false);
        void train(int epoch, T accuracy = 1e-4, bool verbose = false);

        // * monitor
        void display();
};

#endif // PERCEPTRON_H
