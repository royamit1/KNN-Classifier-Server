# *__Advanced Programming Assignment__*

## Table of Contents
* [Project Description](#project-description)
* [How To Run](#how-to-run)
* [Implementation](#implementation)
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
Upload Data: Begin by uploading both the "Train" and "Test" CSV files.  
Configure Algorithm: Optionally, customize the algorithm settings:
- Adjust the number of neighbors (K).  
- Select a distance metric from the available options:
  
   <pre><code>"AUC" - Euclidean metric
  "MAN" - Manhattan metric
  "CHB" - Chebyshev metric
  "CAN" - Canberra metric
  "MIN" - Minkowski metric</code></pre></p>

Run Classification: Initiate the KNN algorithm to classify vectors from the "Test" file using the vectors from the "Train" file.  
Review or Save Results: Choose to either review the classification results directly on-screen or save them as a local file for further analysis.  
Exit: Whenever you're done using the program, exit gracefully by selecting the exit option.  


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


## Implementation
We will use a design pattern called `Command`, where each command in our program has its own class of type Command.  
The `Command` class is abstract and can define anything relevant to all commands in our system,
in particular an abstract execute function for activation.  
This function will have to be implemented by all the successors, in our case - the various commands in the program.  
In addition to each command there is a description string.  
Further to what is said in the project description section, the CLI object holds a vector that contains all the commands, and a `DefaultIO` object.  
We would like to disconnect the dependency between the command and the input/output source.  
For this we defined the abstract type `DefaultIO` whose successors will have to implement the read and write methods in their own way.  
That way, we can enter different implementations of DefaultIO at runtime to the Command.  
Note that this implementation is also open to expansion. Because if we want, for example, to read and write to files, then we can add an implementation to `DefaultIO`.    
That way all the commands will not have to change and will work exactly the same.  
We used the `CLI` class to separation between the initiator of the command (invoker) and the one who is going to be
enabled (receiver).  
All communication between the server and the client will take place using the TCP protocol.  

When a client connects to the server, the server will send the client a menu of the server's functions:   
we used an array of `Command`, went through each `Command` and printed its description. When the user selects the i-th   command, we will go to the i-th position in the array of commands, and call its execute function. this command  
in turn, will continue the interaction with the user as needed.  
1. The user will be given the option to type a path to his local csv file on the computer,  
and after pressing enter the client will send the contents of the file to the server.  
If the classified or unclassified vectors have different lengths, an error message will be received.  
In addition, if the path of the file is invalid, the message `invalid input` will be printed.  
Otherwise, the server will send back the message `Upload complete` to the client.  
2. The server will send the current classifier parameter values, which is the K parameter value
and the current distance meter.  
The user can leave the parameters unchanged by pressing `enter`, otherwise, the user can enter new values separated by space (according to the regular format).  
Any input that does not meet the given format will receive an error message according to the error itself.  
3. The server will run the algorithm of classification on the CSV files uploaded earlier.  
If no files have been uploaded yet, the message `please upload data.` will be printed.  
4. The server will return the list of classifications, and it will be printed on the screen.  
If no files have been uploaded yet, or if the files have not been classified yet, an appropriate error message will be printed.  
5. The user will enter a path to create the file locally and there the client will save the results.  
If no files have been uploaded yet, or if the files have not been classified yet, an appropriate error message will be printed.  
In order for the client to be able to send commands at the same time as receiving data from the server, we used parallelism.  
In this way, the client can always send additional messages to the server and does not depend on the server's work rate.  
8. The interaction between the server and the client will end.  

It's important to say that after each command (except for option 8), the main menu will appear immediately and the user will be able to send additional commands.   
The server, in this case, continues to the next connection (the server does not close).  

### Authors
- [Roy Amit](https://github.com/royamit1)
- [Yoav Shragay](https://github.com/yoavShragay)
