// ****************************************************
// * Code by Kidsadakorn Nuallaoong
// * Multi-Layer Perceptron
// * Artificial Neuron Network - Multi Layer
// ****************************************************

#if !defined(MLP_HPP)
#define MLP_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <chrono>

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cctype>

#include "../Perceptron/Perceptron.hpp"

using namespace std;

// * enum : round display
enum rod {ROUND, DISPLAY, R_D , NONE};

template <typename T>
class MultiLayerPerceptron : private Perceptron<T>
{
    private:
        // * Perceptron layers in vector
        vector<vector<Perceptron<T>>> layers;
        vector<string> activationTypes = {"sigmoid"};

        T accuracy = 0.01;

        // * log history
        vector<MultiLayerPerceptron<T>> history;

    public:
        // * Constructor
        MultiLayerPerceptron();

        // * Constructor with layers size
        MultiLayerPerceptron(const vector<int>& layersSize);
        
        // * Destructor
        ~MultiLayerPerceptron();

        // * Initialize layers
        void initLayer(const vector<int>& layersSize);

        // TODO : feedForward, train, display
        vector<T> feedForward(const vector<T>& inputs);
        void backPropagation(const vector<vector<T>>& inputs, const vector<vector<T>>& targets, const T learningRate);
        void backPropagation_indexRandom(const vector<vector<T>>& inputs, const vector<vector<T>>& targets, const T learningRate);
        void train(const vector<vector<T>> &inputs, const vector<vector<T>> &targets, const T learningRate, const bool verbose = false);
        void train(const vector<vector<T>> &inputs, const vector<vector<T>> &targets, const T learningRate, const int iterations, const bool verbose = false);

        void typeDeActivation(string type);
        T activationDerivative(T x, string type);

        // TODO : update weights, update bias, hiddenLayerError, outputLayerError
        T updateWeights(const T weight, const T learningRate, const T error, const T output);
        T updateBias(const T bias, const T learningRate, const T error);
        T hiddenLayerError(const T output, const T error, const T weight);
        T outputLayerError(const T output, const T target);

        void resetWeightsBias();

        // TODO : Calculate accuracy, loss, all_outputs_correct
        T calculateAccuracy(const vector<vector<T>>& inputs, const vector<vector<T>>& targets);
        T calculateLoss(const vector<vector<T>>& inputs, const vector<vector<T>>& targets);
        bool allOutputsCorrect(const vector<vector<T>>& inputs, const vector<vector<T>>& targets);
        
        // TODO : setActivation, setLayerWeights, setLayerBias, setAccuracy
        void setActivation(const vector<string>& activationTypes);
        void setLayerWeights(int layerIndex, const vector<vector<T>>& weights);
        void setLayerBias(int layerIndex, const vector<T>& bias);
        void setAccuracy(T accuracy);

        // TODO : predict
        vector<T> predict(const vector<T>& inputs, const rod rd = NONE);
        vector<vector<T>> predict(const vector<vector<T>>& inputs, const rod rd = NONE);

        // TODO : exportWeights, exportBias to JSON, CSV, etc.
        void export_to_json(const string& filename);
        void export_to_csv(const string& filename);

        // TODO : importWeights, importBias from JSON, CSV, etc.
        void import_from_json(const string &filename);
        void import_from_csv(const string &filename);

        // * Display layers
        void display();

        // * Clone the MLP
        MultiLayerPerceptron<T> clone() const;

        // * Optional
        vector<MultiLayerPerceptron<T>> getHistory();
};

#endif // MLP_HPP