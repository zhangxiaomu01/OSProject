//***************************************************************************
//1. Main types of operating system:
/*
- Batch OS
- Time sharing OS
- Distributed OS
- Network OS
- Real Time OS
- Multi-programming / processing / tasking OS
*/


//***************************************************************************
//2. Functions of operating system:
/*
- Interface between user and hardware;
- Allocation of resources;
- Management of memory, security etc.

The goal of OS is to make the usage of computer both convenient and efficient.
*/


//***************************************************************************
//3. Important terms related to OS:
/*
1)Bootstrap Program: The initial program that runs when a computer is powered up
                     or reboot.
    - It's stored in the ROM (read-only memory)
    - It must know how to load the OS and start executing that OS
    - It must locate and load the OS kernel into memory

2)Interrupt: The occurance of an event is typically signalled by an interrupt 
             from a hardware or software;
             Hardware may trigger an interrupt at anytime by sending a signal to
             the CPU, usally by the way of system bus.

3)System Call (Monitor Call): Software may trigger an interrupt by executing a 
                              special operation called system call!


- When a CPU is interrupted, it immediately stops what it is doing and immediately
transfers the execution to a fixed location (usually contains the starting 
address where the service routine of the interrupted is located);
- The interrupt service routine executes;
- On completion, the CPU resumes the interrupted computation.
*/


//***************************************************************************
//4. I/O structore
/*
A general-purpose computer system consists of CPUs and multiple device controllers
that are connected through a system bus.
- Each device controller(maintains local buffer storage and set of special purpose
registers) is in charge of specific type of device.
- Typically, operating system has a device driver for each device controller. The
driver can understand the device controller and present a uniform interface of
the device to the rest of the operating system.

Working of an I/O operation:
1) To start the I/O operation, the device driver loads the appropriate registers
within the device controller;
2) The device controller, in turn, examine the contents of these registers and 
decide which action to take;

//Default transformation
3) The controller starts the transfer of data from the device to the local buffer;
4) Once the transfer of the data completes, the device controller informs the 
device driver via an interrupt that it has finished the operation;
5) The device driver then returns control to the operating system.

This form of interrupt driven I/O is fine for moving small amount of data but can
produce high overhead when used for bulk data movement. To solve this problem,
direct memory access (DMA) is used!

//With DMA, we can start from 1 - 2 - 6 - 7 - 8 here. Much faster.
6) After setting up buffers, pointers and counters for the I/O device, the device
controller transfers an entire block of data directly to or from its own storage
to memory, with no intervention by the CPU.

7) Only one interrupt has been generated per block, to tell the device driver 
that the operation has been completed;

8) While the device controller is performing its operations, CPU is still 
available for other tasks.

*/


//***************************************************************************
//5. Computer System Architecture
/*
Types of computer systems based on the number of General Purpose Processors:
a) Single Processor System
    - One main CPU capable of executing a general purpose instruction set, 
    including instructions from user processes.
    - Other special purpose processors are also present which perform device
    specific task.


b) Multiprocessor System
    - Has two or more processors in close communication, sharing the computer 
    bus and sometimes the clock, memory and peripheral devices.
    - Also known as parallel systems or tightly coupled systems.
    
    Advantages: 
    1) Increased throughput 
    2) Economy of scale
    3) Increased reliability

    Type of multiprocessor system:
    -Symmetric Multiprocessing
        All processors perform similar tasks!
    -Asymmetric Multiprocessing
        One master processor + multiple slave processors!


c)Clustered System
    - Like multiprocessor system, clustered systems gather together multiple 
    CPUs to accomplish computational work.
    - They are composed of two or more individual systems coupled together.
    - Provides high availability.
    - Can be structured asymmetrically or symmetrically.
        -asymmetrical mode:
            1) One machine in hot-standby mode
            2) Others run applications
        -symmetrical mode (preferred):
            1) Two or more hosts run applications
            2) Monitor each other

*/


//***************************************************************************
//6. Operating system structure - Multiprogramming && Multitasking
/*
a) Multiprogramming
    - A single user cannot, in general, keep either the CPU or the I/O device
    busy all the time;
    - Multiprogramming increases CPU utilization by organizing jobs (code and 
    data) so that CPU always has one to execute.
    - Multiprogramming does not provide for the user interaction with the 
    computer system.

b) Multitasking (time-sharing system)
    - CPU executes multiple tasks by switching among them;
    - Switch occurs so frequently that users can interact with each program while
    it is running;
    - Time-sharing requires an interactive (hands-on) computer system, which 
    provides direct communication between the user and the system;
    - A time-sharing operating system allows many users to share the computer
    simultaneously.
        - Each user has at least one separate program in memory;
        - A program that loaded into memory and executing is called a "process"

*/



//***************************************************************************
//7. Operating system service
/*
- User interface (Command line interface vs. Graphic user interface)
- Program execution
- I/O operation
- File system manipulation
- Communications
- Error detection
- Resource allocation
- Accounting
- Protection and security
*/


//***************************************************************************
//8. System calls
/*
System calls provide an interface to the services made available by an operating
system.
System call is a programmatic way in which the computer program requests a 
service from the kernel of the OS. These calls are generally available as routines
written in C and C++. 

Types of system calls:
a) Process Control
    - end, abort
    - load, execute
    - create or terminate process
    - get / set process attributes
    - wait for time
    - wait event, signal event
    - allocate / free memory

b) File Manipulation
    - Create / delete file
    - Open / close file
    - read / write / reposition file
    - get / set file attributes

c) Device Management
    - request / release device
    - read / write / reposition device
    - get / set device attributes
    - logically attach / detach devices

d) Information Maintenance
    - get / set time or date
    - get / set system data
    - get / set process, file and device attributes

e) Communications
    - create / delete communication connection
    - send / receive messages
    - transfer status information
    - attach / detach remote devices
*/


//***************************************************************************
//9. System programs
/*
An important aspect of modern system is the collection of system programs.
- System program provides an convenient environment for program development and
execution;

Some system programs can be divided into the following categories:
    - File Management
        - Create, delete, copy, rename, print, dump.
        - List and generally manipulate files and directories.
    - Status Information
        - Data, time
        - Amount of available memory or disk space
        - Number of users
        - Detailed performance
        - Logging and debugging information etc.
    - File Modification
        - Modify the content of the file
        - Transformation of the file
    - Programming language support
        - Compiler, Assemblers, Debuggers and Interpreters
        (Common programming language such as C, C++, Java or VB are often provided
        to the user with the operating system) 
    - Program loading and executing
        The system may provide: 
            a) Absolute loaders b) Reloacate loaders
            c) Linkage editors  d) Overlay loaders
        Debugging systems for either high-level language or machine language are
        needed as well.
    - Communications
        Creating virtual connections between processes, users or computer systems.
*/


//***************************************************************************
//10. Operating system design & implementation
/*
1. Design goals:
First problem: Defining goals and specification
    - Choice of hardware
    - Types of system
Beyond this highest design level, the requirements may be much harder to specify.
Requirements:
    - User goal
    - System goal

A design principle: Always separate mechanism from policy.

Practical structures of OS:
1) Simple Structure
2) Monolithic Structure
3) Layered Structure
4) Microkernels Structure
5) Modules Structure

*/


//***************************************************************************
//11. Virtual Machine
/*
The fundamental idea behind the virtual machine is to abstract the hardware of 
a single computer (CPU, memory, disk drives, network interface card, and so forth)
into several different execution environment, thereby creating the illusion that
each separate execution environment is running its own private computer.

virtual machine implementation software - runs in actual kernel mode
virtual machine itself - runs in user mode (including virtual machine kernel 
                         mode and virtual machine user mode)

*/


//***************************************************************************
//12. Operating system generation and system boot
/*
A process sometimes known as system generation (SYSGEN) is used to configure or
generate operating system for specific computer site.

The following kinds of information must be determined by SYSGEN program:
- What CPU is to be used?
- How much memory is available?
- What devices are available?
- What operating system options are desired?


System boot:
The procedural of starting a computer by loading the kernel is known as booting.

On most computer systems, a small piece of code known as bootstrap program or 
bootstrap loader locates the kernel. This program is in the form of read-only
memory (ROM), because the RAM is an unknown state at system startup. ROM is 
convenient because it needs no initialization and cannot be infected by a computer
virus.

Firmware - A kind of read-only memory for small devices. (bootstrap program, even
OS can reside in it. Difficult to update!)


When the full bootstrap program has been loaded, it can traverse the file system
to find the OS kernel, load it into memory and start its execution. Only at this
point the system is said to be running!
*/


//***************************************************************************
//13. Process management (processes and threads)
/*
A process can be considered as a program in execution.

A thread is the unit of execution within a process. A process can have multiple
threads.

Process State: defined by the current activity of the process. During the execution
of the process, its state changes accordingly. 
- New state: The process is being created.
- Running state: Instructions are being executed.
- Waiting state: The process is waiting for some event to occur. (I/O or signal)
- Ready state: The process is waiting to be assigned to a processor.
- Terminated state: The process has finished execution.

New state => Admitted => Ready state;
Ready state => Scheduler dispatch => Running state;
Running state => Exit => Terminated state;
Running state => Interrupt => Ready state;
Running state => I/O or Event wait => Waiting state;
Waiting state => I/O or Event completion => Ready state;


Process control block (PCB): representation of a process in OS.
Content of PCB:
    - Process State
    - Process Number(ID)
    - Program Counter
    - Registers
    - Memory Limits
    - List of Open Files
    - CPU Scheduling Information
    - Memory Management Information
    - Accounting Information
    - I/O Status Information
    ...
*/


//***************************************************************************
//14. Process scheduling and context switch
/*
- The objective of multiprogramming is to have some processes running at all 
times, to maximum CPU utilization.
- The objective of time sharing is to switch the CPU among processes so 
frequently that users can interact with each program while it is running.
- To meet these objectives, the process scheduler selects an available process (
possibly from a set of available processes) for program execution on the CPU.
    - For single-processor system, there will never be more than one running  
    process; if there are more processes, the rest will have to wait until the 
    CPU is free and can be rescheduled.

Scheduling queues:
- Job queue: As processes enter the system, they are put into a job queue, which 
             consists of all processes in the system.
- Ready queue: The processes are residing in the main memory and are ready and 
               waiting to execute are kept on a list called the ready queue.


Context Switch:
Interrupts cause the operating system to change a CPU from its current task and 
to run a kernel routine. Such operations happen frequently on general-purpose
systems. 

When an interrupt occurs, the system needs to save the current *Context* of the 
process currently running on the CPU so that it can restore that context when 
the new required processing is done. (Suspending the process and then resume it)
The context is represented in the PCB of the process.

Switching the CPU to another process requires performing a state save of the 
current process and a state restore of different process (Context Switching).
    - Context-switch time is pure overhead, because the system does no useful 
    work while switching;
    - Its speed varies from machine to machine, depending on the memory speed,
    the number of registers that must be copied, and the existance of special
    instructions (such as a single instruction to store or load all registers).
    - Typical speed is a few milliseconds.

*/


//***************************************************************************
//15. Process creation and termination
/*
Process Creation:
- A process may create several new processes, via a create-process system call,
during the course of execution. Each of these new processes may create other 
processes, forming a tree of processes.
- When a process create a new process, two possibilities exist in terms of 
execution:
    a) The parent continue to execute concurrently with its children;
    b) The parent wait until some or all of the children have terminated.
- When a process create a new process, two possibilities exist in terms of 
address space:
    a) The child process is the duplicate of parent process (It has the same 
    program and data as the parent);
    b) The child process has a new program loaded into it.

Process Termination:
- A process terminates when it finishes executing its final statement and ask the
operating system to delete it by using the exit() system call.
- At that point, the process may return a status value (typically an integer) to
its parent process (via the wait() system call).
- All the resources of the process - including physical or virtual memory, open 
files, and I/O buffers - are deallocated by the operating system.

Termination can also occur in other circumstances as well:
- A process can cause the termination of another processes via an appropriate 
system call;
- Usually, such a system call can be invoked only by the parent of the process
that is to be terminated. Otherwise, processes could arbitrarily kill each 
other's jobs. 

A parent may terminate the execution of one of its children for a variaty of 
reasons, such as:
- The child has exceeded its usage of some of the resources that has been 
allocated (To determine whether this happens, the parent must have a mechanism
to inspect the status of the children);
- The task assigned to the child is no longer required;
- The parent is existing, and the OS does not allow a child to continue when its
parent terminates.
*/


//***************************************************************************
//16. Interprocess communication - shared memory && message passing
/*
Processes executing concurrently in the operating system may be either independent
process or cooperating process:
Independent processes - They cannot affect or be affected by other processes 
                        executing in the system;
Cooperating processes - They can affect or be affected by other processes 
                        executing in the system;
Any process that shares data with other processes is a cooperating process.

Reasons for providing process cooperation:
    - Information sharing
    - Computation speedup
    - Modularity
    - Convenience

Cooperating processes require an interprocess communication (IPC) mechanism that
will allow them to change data and information.
There are two fundumental models of interprocess communication:
- ** shared memory **
    - In the shared memory model, a region of memory that is shared by cooperating
    processes is established;
    - Processes can then exchange information by reading and writing data to the 
    shared region.
    - Typically, a shared memory resides in the address space of the process 
    creating the shared memory segment (processes which want to communicate 
    with other processes). Other processes want to communicate using this shared
    memory segment must attach it to their address space.

For example:
    Process A => write => shared memory => read => Process B

Normally, the operating system tries to prevent one process from accessing 
another process's memory. Shared memory requires that two or more processes agree
to remove this restriction.

Producer - consumer problem (A simple case, omit here).

Two kind of buffers: 
- Unbounded buffers 
    - Places no practical limit of the size of the buffer. The consumer may wait
    for new items, but the producer can always produce new item.

- Bounded buffers
    - Assumed a fixed buffer size. In this case, the consumer must wait if the 
    buffer is empty while the producer must wait if the buffer is full.



- ** message passing **
    - In the message passing model, communication takes place by means of messages
    exchange between the coorperating processes.
    - Message passing provides a mechanism to allow processes to communicate and
    synchoronize their actions without sharing the same address space;
    - It's particularly useful in a distributed environment, where communicating
    processes may reside on different computers which are connected by network.

For example:
    Process A => message sending => kernel => message receiving => Process B

A message passing facility provides at least two operations:
    send(message) && receive(message)

Messages sent by a process can be of fixed size or variable size.
Fixed size message: The system level of implementation is straightforward, but 
makes the task of programming more difficult;
Variable size message: The system level of implementation is more complex, but 
the programming task is easier.

If process P and Q want to communicate, they must send message to and receive 
message from each other. Then a communication link must exist between them.

The communication link can be implemented in a variety of ways. There are several
methods for logically implementing a link and the send() / receive() operations,
like:
    - Direct or indirect communication
    - Synchoronous or asynchoronous communication
    - Automatic or explicit buffering  

Several issues are related with features like:
    - Naming
    - Synchoronization
    - Buffering


Issue 1: Naming
The processes that want to communicate must have a way to refer each other. They
can use either *Direct* or *Indirect* communication

Direct Communication: Each process that wants to communicate must explicitly name
the receipient or sender of the communication.
    - send(Q, message) send a message to process Q
    - receive(P, message) receive a message from process P
A communication link in this scheme has the following properties:
    - A link is established automatically between each pair of the processes that
    want to communicate. The processes need to know each other's identity to 
    communicate.
    - A link is associated with exactly two processes. 
    - Between each pair of processes, there exists exactly one link. 
This scheme exhibits symmetry in addressing: that is both the sender process or 
the receiver process must name the other to communicate. 

Another variant of Direct Communication: Only the sender name the receipient;
the receipient is not required to name the sender.
    - send(Q, message) send a message to process Q
    - receive(id, message) receive a message from any process. The varibale id is
                           set to the name of the process with which the 
                           communication has taken place.
This scheme exhibits asymmetry in addressing.

The disadvantage in both of these schemes (symmetric or asymmetric) is the limited
modularity of the resulting process definitions. Changing the identifier of one
process may necessitate examing all other process definitions. 

Indirect Communication: The messages are sent to or received from a mailbox or 
ports.
    - A mailbox canbe viewed abstractly as an object into which messages can be
    placed and from which messages can be removed by processes;
    - Each mailbox has unique identification;
    - Two processes can communicate only if the processes have a shared mailbox.   

    send(A, message) - send a message to mailbox A
    receive(A, message) - receive a message from mailbox A

A communication link in this scheme has the following properties:
- A link is established between each pair of processes only if both member of
the pair have a shared mailbox;
- A link may be associated with more than two processes;
- Between each pair of communicating processes, there may be a number of different
links, with each link corresponding to one mailbox.
 
Then if a process P1 sends a message to mailbox A, while both P2 and P3 execute
an receive() from A. Which process will receive the message sent by P1?
The answer depends on which of the following methods we choose?
- Allow a link to be associated with two processes at most;
- Allow at most one process at a time to execute the receive() method;
- Allow the system to arbitrarily choose which process will receive the message(
that is, either P2 or P3, but not both). The system may also defining an algorithm
to do such selection (that is, round robin where processes take turns receiving
the message). The system may identify the receiver to the sender.


A mailbox may either be owned by a process or by the operating system.


Issue 2 Synchronization:
Communication between processes takes place through calls to send() and receive()
primitives. Message passing may be either blocking or nonblocking, which also 
known as synchronous and asynchronous. 
    Blocking send: The sending process is blocked until the message is received
    by the receiving process or by the mailbox;
    Nonblocking send: The sending process sends the message and resumes the 
    operation;
    Blocking receive: The receiver is blocked until a message is available;
    Nonblocking receive: The receiver receives either a valid message or a null.

Issue 3 Buffering:
Whether communication is direct or indirect, messages exchanged by communicating
processes reside in a temporary queue. Basically, such queue can be implemented
in 3 ways:
    - Zero Capacity: The queue has a maximum length of 0, thus the link cannot 
    have any messages waiting in it. In this case, the sender must be blocked 
    until the receipient receives the message;
    - Bounded Capacity: The queue has finite length n, so at most n messages can
    reside in it. If the queue is not empty when a new message is sent, the 
    message is placed in the queue and the sender can continue executing without
    waiting. If the queue is full, the sender must be blocked until space is 
    available in the queue.
    - Unbounded Capacity: The queue's length is potentially infinite. Any number 
    of messages can reside in it. The sender will never be blocked.
*/



//***************************************************************************
//17. Sockets in operating system
/*
Sockets: Used for communication in client - server system
- A socket is defined as an end point for communication;
- A pair of processes communicating over a network employ a pair of sockets, one
for each process;
- A socket is identified by an IP address concatenated with a port number;
- The server waits for incoming client requests by listening to a specified port.
Once a request is received, the server accepts a connection from the client socket
to complete the connection.
- Server implementing specific services (such as telnet, ftp and http) listen to
well known ports. (A telnet server listens to port 23, ftp - port 21 and http - 
port 80);
- All ports below 1024 are considered well-known, we can use them to implement
standard service.

Communication using socket:
Client side:
    - When a client process initiates a request for a connection, it's assigned
    a port by the host computer;
    - The port is some arbitrary number greater than 1024.
Server side:
    - The packets traveling between the hosts are delievered to the appropriate
    process based on the destination port number.

*/


//***************************************************************************
//18. Remote Procedure Call (RPC)
/*
Remote procedure call (RPC) is a protocal that one program can use to request 
a service from a program located in another computer on a network without 
having to understand network's detail. 
    - It's similar in many respects to inter process communicating mechanism;
    - Because the processes reside in different systems, we must use message
    passing scheme to handle the remote service.
    - In contrast to IPC facility,  the messages exchanged in RPC communication
    are well structured and are no longer just packets of data.
    - Each message is addressed to an RPC daemon listening to a port on the remote
    system, and each contains an identifier of the function to execute and the 
    parameters to pass to that function. 
    - The function is then executed as requested, and any output is sent banck 
    to the requester in a separate message.

The semantics of RPCs allow a client to invoke a procedure on a remote host as 
it would invoke a procedure locally:
- The RPC system hides the details that allow communication to take place by 
providing a stub on the client side;
- Typically, a separate stub exists for each separate remote procedure. 
- When the client invokes a remote procedure, the RPC system calls the appropriate
stub, passing it the parameters provided to the remote procedure. This stub locates
the prot on the server and marshals the parameters;
- Parameter marshalling involves packaging the parameters into a form that can be
transmitted over a network;
- The stub then trasmits the message to the server using message passing;
- A similar stub on the server side receives the message and invokes the procedure
on the server;
- If necessarily, return values are passed back to the client using the same 
techniques.


Issues in RPC and how they are solved:
Issue 1:
- Difference in data representation on the client and server machines. (e.g. 
representation of 32 bits integers may be different. Some system stores the most
significant byetes in high memory address, some stores in low memory address)
Solution:
- RPC system defines a machine independent representation of data. One such 
representation is known as external data representation (XDR). One the client
side, parameters marshalling convert the machine dependent data into XDR before
they are sent to the server; while on the server side, we reverse the process.

Issue 2:
- Whereas local procedure calls fail only under extreme circumstances, RPCs can
fail, or be duplicated and executed more than once, as a result of common network
error.
Solution:
- The operating system must ensure that messages are acted exactly once, rather
than at most once. Most local procedure calls have the "exactly once" functionality,
but it's more difficult to implement.

Issue 3:
- With standard procedure calls, some form of binding takes place during link, 
load or execute time so that a procedure call's name is replaced by the memory
address of the procedure call. The RPC scheme requires a similar binding of the
client and server port, but how does the client know the port numbers on the 
server? Neither system has information about the other because they do not share
memory with each other.
Solution:
- 1) The binding information may be predetermined, in the form of fixed port 
address. At compile time, an RPC call has a fixed number associated with it. Once the 
program is compiled, the server cannot change the port number of the requested
service;
- 2) Binding can be done by a rendezvous mechanism. Typically, an operating system
provides a rendezvous (matchmaker) daemon on a fixed RPC port. A client then send
the message containing the name of the RPC to the rendezvous daemon requesting the
port address of the RPC it needs to execute. Then the port number is returned, 
and the RPC calls can be sent to that port until the process terminates. (or the
service crashes)

*/


//***************************************************************************
//19. Introduction to thread
/*
A thread is a basic unit of CPU utilization. It comprises of a thread ID, a 
program counter, a register set and a stack. It shares with other threads within
the same process its code section, data section and other operating system 
resources, such as open files and signals.

A traditional/heavyweight process can has a single thread of control. If a process
has multiple threads of control, it can perform more than one task at a time.

Benefits of multithreaded programming:
a) Responsiveness: Multithreading an interactive application may allow a program
to continue running even if part of it is blocked or is performing a lengthy
operation, thereby increasing responsiveness to the user.
b) Resourse sharing: By default, threads share the memory and the resources of
the process to which they belong. The benefit of sharing code and data is that it
allows an application to have several different threads of activity within the
same address space.
c) Economy: Allocating memory and resources for process creation is costly. Because
threads share resources of the process to which they belong to, it is more 
economical to create and context-switch threads.
d) Utilization of multiprocessor architecture: The benefits of multithread can 
be greatly increased in a multiprocessor architecture, where threads may be running
in parallel on different processors. A single threaded process can only run on
one CPU, no matter how many are available. Multithreading on a multi-CPU machine
increases concurrency.


Multithreading Model and Hyperthreading
Types of thread:
1) user thread: Supported above the kernel and managed without kernel support;
2) kernel thread: Supported and managed directly by operating system.

Three common ways to establish a relationship between user thread and kernel 
thread:
- Many to one mode:
    + Maps many user threads to one kernel thread. 
    + Thread management is done by the thread libraray in user space, so it is
    efficient.
    - The entire process will block if a thread makes a blocking system call.
    - Because only one thread can access the kernel thread at a time, multiple
    threads are unable to run parallel on multiprocessors.
- One to one mode:
    = Maps each user thread to a kernel thread.
    + Provide more concurrency than the many to one mode by allowing aonther 
    thread to run when a thread makes a blocking system call.
    + Also allows multiple threads to run in parallel on multiprocessors.
    - Creating user thread requires creating a corresponding kernel thread. (costy)
    - Because the overhead of creating kernel thread can burden the performance of 
    an application, most implementations of this mode restrict the number of thread
    supported by the system.
- Many to many mode:
    + Multiplexes many user level threads to a smaller or equal number of kernel
    threads.
    = The number of kernel threads may be specific to either a particular application 
    or a particular machine.
    + Developers can create as many user threads as necessary, and the corresponding
    kernel threads can run in parallel on multiprocessors.
    + When a thread performs a blocking system call, the kernel can schedule another
    thread for execution.


Hyperthreading (Simultaneous Multithreading (SMT))
Hyperthreaded systems allows their processor cores' resources become multiple 
logical processors for performance.
It enables the processor to execute two threads, or sets of instructions, at the
same time. Since hyper threading allows two streams to be executed in parallel,
it's almost like to have two processors working together. 
*/


//***************************************************************************
//20. fork() and exec() system call
/*
fork(): The fork() system call is used to create a separate, duplicate process.
exec(): When an exec() system call is invoked, the program specified in the
parameters to exec() will replace the entire process -- including all threads.
*/

//***************************************************************************
//21. Threading issue
/*
Issue 1:
The semantics of fork() and exec() system calls change in a multithreaded program.

If one thread in a program calls fork(), does the new process duplicates all 
threads or is the new process single-threaded?  
Solution: Some UNIX system chose to have two versions of fork(), one that duplicates
all threads and another that duplicates only the thread that invoked the fork()
system call.

For exec() system call, if a thread invokes the exec() system call, the program 
specified in the parameter to exec() will replace entire process -- including 
all threads. 

Which version of for() call to use and when?
- If exec() is called immediately after forking:
In this instance, duplicating only the calling thread. (No necessary to duplicate
other threads since exec() will replace all the threads)
- If the separate process does not call exec() after forking:
Then the separate process should duplicate all threads.

Issue 2: Thread cancellation
Thread cancellation is the task of terminating a thread before it is completed.
When?
e.g. If multiple threads are concurrently searching through a database and one
thread returns the result, the remaining threads might be cancelled. 
e.g. When a user presses a button on a web browser that stops a web page from 
loading any further, all threads that load the page are cancelled.

A thread that is to be cancelled is often referred to as the target thread.

Cancellation of a target thread may occur in two different scenarios:
- Asynchronous cancellation: One thread that immediately terminates the target
thread;
- Deferred cancellation: The target thread periordically checks whether it should
terminate, allowing it an opportunity to terminate itself in an orderly fashion.

The difficulty with cancellation lies:
In situations where:
- Resources have been allocated to a canceled thread;
- A thread is canceled while in the midst of updating data which is shared with
other threads.
Often, OS will reclaim the system resources from a canceled thread but will not
reclaim all resources. Therefore, canceling a thread asynchronously may not 
free a necessary system wide resource.

With deferred cancellation, one thread is indicated that a target thread is to
be canceled, however, the cancallation occurs only after the target thread has 
checked a flag to determine if it should be canceled or not. This allows a thread
to check whether it should be canceled at a point when it can be canceled safely.
*/


//***************************************************************************
//22. Introduction to CPU scheduling
/*
CPU scheduling is the basis of multiprogrammed operating system;
By switching the CPU among processes, the OS can make computer more productive!
- In a single processor system, only one process can run at a time;
- Any others must wait until the CPU is free and can be rescheduled.
    - The objective of multiprogramming is to have some process running at all 
    times, to maximum CPU utilization.
    - A process is executed until it must wait, typically for the completion of
    some I/O request.
When one process has to wait, OS takes the CPU away from that process and gives 
the CPU to another process and this pattern continues.

CPU burst and I/O burst cycle
Process execution consists of a cycle of CPU execution and I/O wait, and processes
alternate between these two stages.
The final CPU burst is a system call to terminate the process.


Preemptive and non-preemptive scheduling
CPU scheduler: Whenever the CPU becomes idle, the OS must select one of the processes
in the ready queue to be executed. The selection process is carried out by the
short term scheduler (CPU scheduler). The scheduler selects a process from the
processes in memory that are ready to execute and allocates the CPU to that process.

Dispatcher: The dispatcher is the module that gives control of the CPU to the 
process selected by the short-term scheduler. The time it takes to stop one process
and start another running is known as the dispatch latency. 

CPU scheduling decisions may take place under the following four circumstances:
1) When a process switches from *running state* to the *waiting state*.
2) When a process switches from *running state* to the *ready state* (for example,
when an interrupt occurs).
3) When a process switches from *waiting state* to the *ready state* (for example,
at completion of I/O operation).
4) When a process terminates.

For situation 1) and 4), there is no choice in terms of scheduling. A new process(
if one exists in the ready queue) must be selected for execution. However, there
is a choice for 2) and 3).

When scheduling only happens under 1) and 4), we say that the scheduling scheme
is non-preemptive or cooperative; otherwise, it is preemptive.
*/
