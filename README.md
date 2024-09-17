# Neural Network Implementation and Comparison

## Learnings from Michael Nielsen’s Book

**1. Neural Network Basics**
   - **Perceptrons**: Basic building blocks of neural networks. They consist of inputs, weights, a bias, and an activation function.
   - **Activation Functions**: Introduced the concept of non-linearity in neural networks. Common functions include sigmoid, tanh, and ReLU.

**2. Forward Propagation**
   - **Calculation**: Involves computing the weighted sum of inputs and applying the activation function to obtain the output.
   - **Layer-by-Layer Processing**: Neural networks are built by stacking layers of neurons, with each layer’s output serving as the input for the next layer.

**3. Backpropagation and Learning**
   - **Error Calculation**: Measures the difference between predicted and actual outputs using loss functions (e.g., mean squared error, cross-entropy).
   - **Gradient Descent**: Optimization technique used to minimize the loss by adjusting weights and biases based on the gradients of the loss function.

**4. Model Training and Evaluation**
   - **Epochs and Batches**: Training involves multiple passes through the dataset (epochs) and processing data in smaller subsets (batches).
   - **Validation and Testing**: Evaluates the model’s performance on unseen data to assess generalization.

**5. Overfitting and Regularization**
   - **Overfitting**: When a model performs well on training data but poorly on new data. Regularization techniques like dropout help mitigate overfitting.

## Results

### Neural Network from Scratch
- **Training Accuracy**: 0.890
- **Training Loss**: 0.391
- **Test Accuracy**: 0.888

### CNN Model using TensorFlow
- **Training Accuracy**: 0.9942
- **Training Loss**: 0.0179
- **Test Accuracy**: 0.99
- **Test Loss**: 0.03

## Comparison

**Ease of Use**:
- **From Scratch**: Manual implementation, more effort required.
- **TensorFlow/PyTorch**: Simplifies model creation and training.

**Performance**:
- **From Scratch**: Good accuracy but room for improvement.
- **TensorFlow/PyTorch**: Higher accuracy and lower loss.

**Flexibility**:
- **From Scratch**: Maximum control, but more complex.
- **TensorFlow/PyTorch**: Easy experimentation with built-in tools.

**Conclusion**: TensorFlow/PyTorch offers better performance and ease of use compared to building from scratch.

