from chatterbot import ChatBot
from chatterbot.trainers import ChatterBotCorpusTrainer

# Create a ChatBot instance
chatbot = ChatBot('MyChatBot')

# Create a new trainer for the chatbot
trainer = ChatterBotCorpusTrainer(chatbot)

# Train the chatbot based on the English corpus
trainer.train('chatterbot.corpus.english')

# Start chatting
print("Hello! I am your chatbot. You can start chatting with me. Type 'exit' to end the conversation.")
while True:
    user_input = input("You: ")
    if user_input.lower() == 'exit':
        break
    response = chatbot.get_response(user_input)
    print("Bot:", response)

