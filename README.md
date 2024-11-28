# Smart-trash-bin

The project is a smart trash bin that can classify up to four waste categories (Metal, plastic, paper, glass). The project’s mechanism is as follows: the infrared sensor detects if a waste was dumped in the bin and send a signal to the AI model to classify the waste type. The waste image is sent to AI via web cam application; then, the model classifies it. Using pyserial, the classification is sent to the Arduino; then, the servo motor rotates the correct classification bucket. The AI model is developed using transfer learning (VGG16) with 86% accuracy.
