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

                                8. Streams (Multiple Assembly Lines)
                                                Concept : Streams allow different tasks to be executed concurrently, much like having multiple assembly lines in a factory.
                                                Analogy : Imagine the factory has several parallel assembly lines (streams), each building a different car model simultaneously. This way, the factory can produce multiple cars at the same time, increasing efficiency and throughput.
                                                
                                9. Kernel Launch (Assigning Tasks)
                                                Concept : A kernel launch is the process of sending tasks to the GPU.
                                                Analogy : When the manager (CPU) gives instructions to the workers (GPU cores), it's like assigning specific tasks to different teams on the assembly line. Each instruction set is a kernel launch, telling workers what to do.
                                
                                10. Occupancy (Worker Utilization)
                                                Concept : Occupancy refers to how effectively the GPU cores are utilized.
                                                Analogy : In the factory, occupancy is the ratio of active workers to the total available workers. High occupancy means most workers are busy, while low occupancy means many workers are idle. Efficient management aims for high occupancy to ensure all workers are utilized effectively.
                                
                                11. Warp Divergence (Misaligned Tasks)
                                                Concept : Warp divergence occurs when threads within the same warp (group of 32 threads) follow different execution paths.
                                                Analogy : Imagine a team of workers (warp) is given a task, but some workers need to paint while others need to fit tires. If they can't work simultaneously on their specific tasks, they need to wait for each other, causing delays. This misalignment reduces efficiency.
                                
                                12. Memory Coalescing (Efficient Memory Access)
                                                Concept : Memory coalescing is the efficient access of global memory by threads in a warp.
                                                Analogy : Think of workers (threads) needing parts from the warehouse (global memory). If they all go one by one to fetch their parts, it’s slow. But if they group their requests efficiently, they can get all parts in fewer trips, speeding up the process.
                                
                                13. Unified Memory (Single Storage Area)
                                                Concept : Unified memory allows CPU and GPU to share the same memory space, simplifying data management.
                                                Analogy : Instead of having separate storage areas for parts and tools for the manager (CPU) and workers (GPU cores), there is a single, shared storage area. Both the manager and workers can access the same parts without the need to transfer items back and forth.


*/
//-------------------------------------------------------------------------------------------------------------------------//