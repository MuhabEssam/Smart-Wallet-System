# 💳 Smart Wallet System (Client-Server Architecture)

A secure, cross-platform **desktop application** for personal finance management, built using **C++** and the powerful **Qt Framework**.

This project employs a robust **client-server model** to ensure concurrent user handling, secure data management, and a fluid, native desktop experience.

---

## ✨ Features Overview  

The system is split into two distinct, high-performance components:

---

### 🌐 Server Side (Core Engine & Concurrency)

The **server** centralizes security, data integrity, and multi-client communication.  

- **TCP Socket Server**  
  Built using Qt’s networking classes (`QTcpServer`, `QTcpSocket`) to provide **reliable socket-based communication** between server and clients.  

- **Threaded Architecture**  
  Utilizes multi-threading to handle multiple simultaneous client connections efficiently without blocking.  

- **Client Database Management**  
  Implements a persistent database structure for storing and managing all **user accounts**, **credentials**, and **financial transaction records**.  

- **Credential Validation**  
  Securely validates client login requests by checking provided credentials against the centralized database.  

- **Core Transaction Logic**  
  Executes and records all financial operations requested by the client.  

---

### 💻 Client Side (Qt User Interface)

The **client** provides a clean, fast, and cross-platform **Graphical User Interface (GUI)** built with Qt.  

- **Secure Login Interface**  
  Dedicated login page with **server-side credential validation** for authentication.  

- **Account Operations**  
  Users can perform essential financial actions:
  - ✅ Check **account balance** in real-time.  
  - 💰 Perform **deposits** and **withdrawals**.  

- **Transaction History**  
  Displays a **complete, detailed list** of all past transactions.  

- **⚠️ Transaction Rollback**  
  Implements a critical feature to communicate with the server and **undo the last performed transaction**, allowing for quick error correction.  

---

## 🚀 Tech Stack

- **Language:** C++  
- **Framework:** Qt (for GUI, networking, threading)  
- **Networking:** **TCP sockets** (`QTcpServer`, `QTcpSocket`)  
- **Database:** Persistent storage for credentials & transactions 
- **Architecture:** Client-Server with concurrency support  

---

## 🛠️ Setup & Usage

### 1️⃣ Clone the Repository
```bash
git clone https://github.com/MuhabEssam/Smart-Wallet-System.git
cd smart-wallet-system
```
- **Open New Terminal**
```bash
cd Exec
./TCPSERVER
```
- **Open Another Terminal**
```bash
./SmartWallet
```

