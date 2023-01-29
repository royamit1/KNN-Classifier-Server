# *__Advanced Programming Assignment__*

## Table of Contents
* [Project Description](#project-description)
* [How To Compile](#how-to-compile)
* [How To Run](#how-to-run)
* [Implementation](#implementation)
* [Authors](#authors)

### Project Description
In this assignment our server will have to handle several clients at the same time.   
That is, at a given moment, the server can speak with several clients at the same time.  
We would like our server to have a CLI (Command Line Interface). That is, when a client connects, he will see  
textual menus that the server sent and through which the interaction between the server and the client will take place.  
Further explanations regarding the server and the client, below.

### How To Compile
In order to compile the code, use the command: `make`

### How To Run
The program should run as follows:  
first, we run the server with the command `./server.out port`
- port is the port number, chosen by the user, and can be a number between 0 and 65535

After the server is running, it's waiting for a connection from the client.

Next, we run the client with the command `./client.out ip port`
- ip is the ipv4 address of the server so that a connection can be made with the server
- port is the same port used by the server

Finally, after the connection has been made, the client prints to the screen options received from the server.    
Each option works as described on the assignment page, and in the description of the functions in the code.  

### Implementation
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
- Roy Amit
- Yoav Shragay
