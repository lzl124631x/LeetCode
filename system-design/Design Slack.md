# Design Slack

## Features
* Group Chat (Channel)
* Persistent Chat History (Whenever you reopen app or switch device, the chat history is alway up-to-date)

* Last read message in channel.

## Components

For MVP:
* Client: Web App, Native App (iOS, Android).
* Server

## Workflow

### Join a new channel and chat
1. The user joins a channel using a channel Id in client.
2. After that, the client sends a request to retrieve the chat history.
3. The user sends a new message into the channel.
4. The the members in the channel receives the new message.

### Reopen app / switch device
1. The client sends a request to retrieve the chat history after the last message stored in app
2. The client appends the new messages (if any) to the tail of the chat history.


## API

According the workflows above:
```
JoinChannel(channelId: string): bool

RetrieveChatHistory(channelId: string): ChatEntry[]

SendMessage(channelId: string, message: string): bool

// Websocket
ListenToChannel(channelId: string): bool
OnChannelUpdate(message: string): void
```

## Details

When the server receives a new message, it use websocket to broadcast the message to all the channel members.

At the same time, the server stores the message into DB and Cache.

DB Choice: NoSQL. Because it's mainly about storing large amount of data. Seldom do we do JOINs.

# Reference
* [How Slack Works](https://www.youtube.com/watch?v=WE9c9AZe-DY)