# 📡 minitalk

![42 Badge](https://img.shields.io/badge/42-minitalk-brightgreen)
![Score](https://img.shields.io/badge/Score-80%2F100-success)
![Language](https://img.shields.io/badge/Language-C-blue)
![Status](https://img.shields.io/badge/Status-Completed-success)

<p align="center">
  <img src="https://raw.githubusercontent.com/byaliego/42-project-badges/main/badges/minitalke.png" alt="minitalk Badge" width="150" height="150">
</p>

## 📝 Introduction

**minitalk** is a 42 School project focused on creating a small data exchange program using UNIX signals. The project consists of a client and server that communicate using only SIGUSR1 and SIGUSR2 signals.

> "A simple but powerful implementation of inter-process communication using signals."

The goal is to transmit any string from a client program to a server program using only UNIX signals as the communication method.

## 🎯 Project Objectives

- Implement a communication protocol using only UNIX signals
- Create a client that can send messages to a server
- Create a server that can receive and display messages
- Handle the transmission of strings of any length
- Implement proper error handling and signal management
- Learn about processes, signals, and bitwise operations

## 🧩 Project Structure

The project consists of three main components:

```
minitalk/
├── inc/
│   └── minitalk.h  # Header file with prototypes and includes
├── src/
│   ├── client.c    # Client implementation
│   └── server.c    # Server implementation
└── Makefile        # Compilation instructions
```

## 🛠️ Implementation Details

### **minitalk.h**
The header file includes:
- Standard library includes
- Custom function prototypes
- Wait time definition for signal transmission
- Utility function declarations

### **client.c**
The client program sends messages to the server:

| Function | Description |
|----------|-------------|
| **pid_error** | Validates command line arguments and PID format |
| **send_ch_by_bit** | Sends a single character by breaking it into 8 bits |
| **send_len_by_bit** | Sends string length as 32 bits to prepare the server |
| **main** | Parses arguments and orchestrates the message transmission |

### **server.c**
The server program receives and displays messages from clients:

| Function | Description |
|----------|-------------|
| **recive_len** | Reconstructs the length of the incoming message from bits |
| **recive_str** | Reconstructs characters from bits and builds the final string |
| **recive_client_data** | Signal handler that processes incoming signals |
| **main** | Displays PID, sets up signal handlers, and waits for client connections |

## 💡 Communication Protocol

1. **Connection Establishment**:
   - Server starts and displays its PID
   - Client uses the server's PID to target signal transmission

2. **Message Transmission**:
   - Client first sends the string length (32 bits) to the server
   - Server allocates memory based on the received length
   - Client sends each character of the string (8 bits per character)
   - Server reconstructs each character and builds the complete message

3. **Bit Encoding**:
   - SIGUSR1 represents bit value 1
   - SIGUSR2 represents bit value 0
   - Bits are sent sequentially with a delay between signals

## 🔍 Key Features

- Binary data transmission using only two signals
- Support for messages of any length
- Error handling for invalid PIDs
- Memory management for received strings
- Bitwise operations for encoding/decoding messages

## 🧠 Skills Developed

- Process management and inter-process communication
- Signal handling in UNIX systems
- Bitwise operations and binary data manipulation
- Memory management
- Protocol design and implementation

---

<div align="center">
  
  ### 📊 Project Stats
  
  | Metric | Value |
  |--------|-------|
  | Final Score | 80/100 |
  | Lines of Code | ~150 |
  | Signal Types | 2 (SIGUSR1, SIGUSR2) |
  
</div>

<p align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white" alt="42">
</p>
