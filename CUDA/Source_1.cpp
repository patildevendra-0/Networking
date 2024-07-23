//-------------------------------------------------------------------------------------------------------------------------//
/*                                          CUDA-(Computed Unified Device Architecture)
//-------------------------------------------------------------------------------------------------------------------------//
    
    # CUDA - Computed unified device architecture 

            1.  CUDA is a parallel computing platform and programming model created by NVIDIA.
            2.  It allows developers to use NVIDIA GPUs (graphics processing units) to perform general-purpose processing, 
                which can massively speed up certain tasks. (an approach known as GPGPU, General-Purpose computing on Graphics Processing Units).
            3.  CUDA was released in 2006      


        # Real-Life Example: Car Factory Assembly Line
            
            Factory Setup

                1.  Car Factory as a Computer:

                        The car factory represents a computer.
                            Different sections of the factory handle different parts of car manufacturing, just like a computer has different components handling various tasks.
                        
                        1)  Manager (CPU) and Workers (GPU Cores):
                               1. CPU (Central Processing Unit): The manager of the factory, who plans and coordinates the entire car manufacturing process. The manager is skilled and handles complex tasks but can only manage one thing at a time.
                               2. GPU Cores (Graphics Processing Unit): The workers on the assembly line. There are many workers, each handling simple, repetitive tasks. They can work simultaneously, making the process much faster.
                    
                        
                        2)  CUDA Concepts in the Car Factory

                                1. Parallel Processing:
                                        Instead of one manager (CPU) building a car from start to finish, each worker (GPU core) is assigned a specific task, like installing the engine, painting the car, or fitting the tires. 
                                        All these tasks happen at the same time (in parallel), speeding up the production.
                                    
                                2. Threads (Workers):
                                        Each worker on the assembly line is a thread. They perform one specific task repeatedly. For example, one worker installs the windshield, another fits the tires, and another paints the car body.
                                
                                3. Blocks (Teams of Workers):
                                        The factory is divided into sections or teams (blocks). Each team of workers handles a particular stage of the car assembly. For example, one team installs the interiors, another paints the car, and another fits the wheels. 
                                        Each team works independently but in parallel with the others.
                            
                                4. Grid (Entire Assembly Line):
                                        The entire assembly line, which includes all the teams and their respective workers, represents the grid. The grid ensures that all parts of the car are being worked on at the same time across different stages of the assembly line.
                        
                                5. Shared Memory (Shared Tools and Parts):
                                        Some tools and parts are stored at a central station where all workers in a team can access them quickly. Similarly, shared memory in CUDA is a small, fast memory space that all threads within a block can access quickly.
                        
                                6. Global Memory (Warehouse):
                                        The warehouse stores all the parts and tools, but accessing it takes more time. Global memory in CUDA is the main memory accessible by all threads, but it’s slower than shared memory.
                                
                                7. Synchronization (Coordinated Timing):
                                        Sometimes, workers need to wait until another worker finishes their task before proceeding. This is synchronization. For example, you can’t fit the tires until the car body is painted. Similarly, 
                                        CUDA threads need to synchronize to ensure tasks are completed in the correct order.


*/
//-------------------------------------------------------------------------------------------------------------------------//