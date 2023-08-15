# *__Advanced Programming Assignment__*

## Table of Contents
* [Project Description](#project-description)
* [Implementation](#implementation)
* [How To Run](#how-to-run)
* [Authors](#authors)

## Project Description
This project is a KNN (K-Nearest Neighbors) classifier implemented as a server and client that works on TCP sockets with multi-client support using threads. The classifier takes in a file of classified vectors and a file of test vectors, and can be configured to use a specific K and distance function. The classifier can then classify the test vectors and send the classified vectors either to the screen dialog or to a specified file.  

#### Course of the program
First, the server is being initialize, then clients can connect to the server (the number of clients dependes on how much clients the server can handle in hold, in our program can handle 5 clients by default).

Each client is being presented with a menu with various commands which includes:
<pre><code>Welcome to the KNN Classifier Server. Please choose an option:
1. upload an unclassified csv data file
2. algorithm settings
3. classify data
4. display results
5. download results
8. exit</code></pre>

#### Usage Flow
1. Upload Data : Begin by uploading both the "Train" and "Test" CSV files.  
2. Configure Algorithm : Optionally, customize the algorithm settings:
   
   - Adjust the number of neighbors (K).
   - Select a distance metric from the available options:  
    <pre><code> "AUC" - Euclidean metric
    "MAN" - Manhattan metric
    "CHB" - Chebyshev metric
    "CAN" - Canberra metric
    "MIN" - Minkowski metric</code></pre></p>

3. Run Classification : Initiate the KNN algorithm to classify vectors from the "Test" file using the vectors from the "Train" file.  
4. Review or Save Results : Choose to either review the classification results directly on-screen or save them as a local file for further analysis.  
5. Exit : Whenever you're done using the program, exit gracefully by selecting the exit option.  

## Implementation
#### Program Design and Workflow
We've implemented a Command design pattern for our program, where each command corresponds to a class inheriting from the abstract Command class. This allows us to maintain a clear structure for our system. The Command class itself is abstract and contains shared properties, primarily an abstract execute function responsible for executing specific command actions. Each specific command in our program implements this function based on its functionality. Furthermore, each command is associated with a description string.

#### Dependency Separation
In addition to what's covered in the project description, the CLI (Command Line Interface) object contains a vector that holds all the commands and a DefaultIO object. To achieve a modular design and to separate the dependency between the command and the input/output source, we've defined an abstract type named DefaultIO. Its successors are required to implement the read and write methods, allowing us to input different implementations of DefaultIO at runtime for the Command. This design facilitates expansion; for instance, if we decide to read and write to files, we can add an implementation to DefaultIO without altering the commands.

#### CLI and Interaction
The CLI class serves as a bridge between the command initiator (invoker) and the entity being executed (receiver). All communication between the server and the client occurs using the TCP protocol.

When a client connects to the server, the server transmits a menu of available functions to the client. We've employed an array of Command objects to achieve this. The server iterates through each Command, displaying its description. When a user selects a particular command, we navigate to the corresponding position in the array of commands and call its execute function. This command then proceeds to interact with the user as needed.

#### File Upload and Classification
Users are provided with the option to input a path to a local CSV file on their computers. Upon pressing enter, the client sends the file's contents to the server. If the lengths of classified and unclassified vectors differ, an error message is received. Similarly, an invalid path yields an "invalid input" message. Conversely, the server responds with "Upload complete" upon successful file transfer.

The server transmits the current classifier parameter values (K and distance metric) to the user. Users can maintain the parameters by pressing enter or input new values separated by space. If the format is incorrect, the system prompts an appropriate error message. The server executes the classification algorithm on the uploaded CSV files. If no files have been uploaded yet, "please upload data" is displayed.

#### Classification and Result Handling
Upon classification, the server sends back a list of classifications, which is displayed on the screen. If files haven't been uploaded or classified, appropriate error messages are shown. Users enter a local file path to save results. Similar to previous cases, if no files have been uploaded or classified, relevant error messages are displayed.

#### Parallelism for Seamless Interaction
To allow clients to send commands simultaneously while receiving data from the server, we've implemented parallelism. This empowers clients to send additional messages to the server regardless of its processing rate.

#### Continuous Interaction
It's important to note that after executing each command (excluding option 8, which exits), the main menu promptly reappears, enabling users to send further commands. The server continuously handles connections and interactions without closing after each connection.

## How To Run  

```bash
# Clone this repository :
$ git clone https://github.com/royamit1/KNN-Classifier-Server.git

# Go into the repository :
$ cd KNN-Classifier-Server

# Compile using makefile :
$ make
```

Running the server:  
<pre><code>$ ./server.out &#60port&#62                       // For example: ./server.out 12345</code></pre>
Running the client:  
<pre><code>$ ./client.out &#60ip address&#62 &#60server port&#62   // For example: ./client.out 127.0.0.1 12345</code></pre>



### Authors
- [Roy Amit](https://github.com/royamit1)
- [Yoav Shragay](https://github.com/yoavShragay)
