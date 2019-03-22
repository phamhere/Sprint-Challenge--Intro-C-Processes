**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

- Start - the initial state when a process is first started/created
- Ready - the process is waiting to be assigned to a processor
- Running - the process has been assigned a processor and is executed
- Waiting - the process is waiting for an event or for a resource
- Stopped - the process has been stopped
- Zombie - the process is dead but has not been removed from the process table

**2. What is a zombie process?**
A zombie process is a process that has terminated/exited that is waiting for another process. It has an entry in the process table.

**3. How does a zombie process get created? How does one get destroyed?**
A zombie process gets created when a child process exits before a parent process exits and has an exit value that it needs to pass on. A zombie process gets destroyed when the child process is able to give its exit value to the parent process, which occurs by terminating the parent process.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
A compiled language is directly compiled into machine code whereas non-compiled languages have an extra step of needing to interpret the language to another language before compiling it down to machine code. The benefit of the former is the speed by omitting the interpreting step and the ability to manipulate more deeper processes in the computer since it has not been abstracted away through interpretation.

By taking extra time to compile code, there is time to catch bugs in code through errors or warnings that would've otherwise been dismissed. This results in program malfunctions that are more difficult to debug.
