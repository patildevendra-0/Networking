//--------------------------------------------------------------------------------------------------------------//
/*										              CACHE			
//--------------------------------------------------------------------------------------------------------------//

		# WHAT IS CACHE : 
						In computer memory, a cache is a small, high-speed storage area that stores copies of frequently accessed data from main memory. 
						Its purpose is to speed up data retrieval and improve overall system performance
 
				  * LEVEL OF CATCHE : Modern computers often have multiple levels of cache:
				  
							1} L1 Cache:
										Size		: Smallest (16KB to 64KB)
										Speed		: Fastest
										Proximity	: Closest to the CPU cores
										Purpose		: Stores critical data and instructions needed immediately.

							2} L2 Cache:
										Size		: Larger than L1 (256KB to 512KB)
										Speed		: Slower than L1 but faster than L3
										Proximity	: Still close to the CPU
										Purpose		: Holds data that is not as frequently accessed as L1 but still needed quickly.

							3} L3 Cache: 
										Size		: Largest (1MB to 32MB)
										Speed		: Slowest among the three
										Proximity	: Shared among all CPU cores
										Purpose		: Acts as a buffer between RAM and L1/L2 caches.

				  * CACHING PROCESS - (How Cache Works)
							
							# When CPU needs to read the data ,it First check on cache .

							1} Cache Hit and Miss:
											1.Cache Hit		: When the CPU finds the requested data in the cache.If the data is found in cache (CACHE HIT),It can accessed quickly.
											2.Cache Miss	: When the CPU does not find the requested data in the cache and has to fetch it from RAM.
															  If the data is not found in cache (CHACHE MISS) then It must me fetched from main memory and copy placed in cache.

							2} Cache Line:
											A cache is divided into small blocks called cache lines (typically 64 bytes). When data is loaded from RAM into the cache, it is loaded into a cache line.
							

							3} Tag Directory:
											In cache memory, the Tag Directory (or tag store) is a part of the cache's metadata that stores information about which memory addresses are currently stored in the cache lines. 
											This helps the cache controller determine if a memory access can be served from the cache (a cache hit) or if it needs to fetch the data from main memory (a cache miss).
													Tag			: Each cache line has a tag that uniquely identifies which portion of the main memory it holds.
													Directory	: The collection of all tags in the cache.

							4} Mapping:
											1.Direct Mapping			: Each block of main memory maps to exactly one cache line.
											2.Fully Associative Mapping	: Any block of memory can be loaded into any cache line.
											3.Set Associative Mapping	: A compromise between direct and fully associative mapping.
																		  Memory is divided into sets, and each block of memory maps to any line within a set.
							
							5} Page Fault and Page Hit (FOR VIRTUAL MEMORY): 
											1. Page Fault:
															a. Occurs when a program tries to access data in a page that is not currently in RAM.
															b. Triggers an interrupt to the operating system to load the required page from disk into RAM.
															c. Can be costly in terms of performance due to the time required to read data from disk.
											
											2. Page Hit:
															a. Occurs when a program accesses data in a page that is already in RAM.
															b. Faster access since the data is immediately available in physical memory.

											3. Interaction Between Cache and Virtual Memory
															1] Cache Hit/Miss:
																	a. When the CPU requests data, it first checks the cache.
																	b. If the data is found in the cache, it’s a cache hit (fast access).
																	c. If the data is not in the cache, it’s a cache miss. The CPU then checks RAM.

															2] Page Hit/Miss:
																	a. If the data is not in RAM (cache miss), the CPU triggers a memory access.
																	b. If the requested data’s page is in RAM, it’s a page hit.
																	c. If the requested data’s page is not in RAM, it’s a page fault.

											4. How They Work Together : 
															Initial Request:
																		a. The CPU requests data.
																		b. The cache is checked first.

															Cache Hit:
																		a. If the data is in the cache, it’s quickly returned to the CPU.
																		b. No further action is needed.

															Cache Miss:
																		a. If the data is not in the cache, the CPU checks the corresponding memory page in RAM.

															Page Hit:
																		a. If the memory page is in RAM, the data is fetched and placed into the cache.
																		b. The data is then returned to the CPU.

															Page Fault:
																		a. If the memory page is not in RAM, a page fault occurs.
																		b. The operating system loads the required page from disk into RAM.
																		c. Once the page is in RAM, the data is fetched and placed into the cache.
																		d. The data is then returned to the CPU.

						 6} Locality of Reference : 
										* Locality of reference is a fundamental concept in computer science that describes how programs tend to access data and instructions
												1. It is the principle that programs tend to access a relatively small portion of their address space at any given time. 
												2. There are two main types:
																		a.	Spatial Locality	: If a particular memory location is accessed, nearby memory locations are likely to be accessed soon.
																			Example				: Iterating over an array.
																		
																		b.	Temporal Locality	: If a particular memory location is accessed, it is likely to be accessed again in the near future.
																			Example				: Loop variables in a program.

												a] Spatial Locality:
														Spatial Locality refers to the tendency of a program to access a sequence of memory locations that are close to each other.
														Example: When processing an array, accessing array[i] is likely followed by accessing array[i+1].
												
												b] Temporal Locality:
														Temporal Locality refers to the tendency of a program to access the same memory location multiple times within a short period.
														Example: Loop variables or frequently used data structures like counters.



						7} Visual Representation of  Basic units of data storage in memory	: 

																			Bit: 0 or 1

																			Nibble: 1010 (4 bits)

																			Byte: 10101010 (8 bits)
																				 └────┘
																				Nibble

																			16-bit Word: 1010101010101010 (2 bytes)
																						 └──────┴──────┘
																							Byte   Byte

																			32-bit Word: 10101010101010101010101010101010 (4 bytes)
																						 └──────┴──────┴──────┴──────┘
																							Byte   Byte   Byte   Byte

																			64-bit Word: 10101010 10101010 10101010 10101010 10101010 10101010 10101010 10101010 (8 bytes)
																						 └─────-─┴─────--─┴─────--─┴────--──┴───--───┴───--───┴────--──┴────--──┘
																							Byte    Byte    Byte      Byte     Byte     Byte     Byte     Byte
													
													a. Bit		: The smallest unit of data (0 or 1).
													b. Nibble	: 4 bits.
													c. Byte		: 8 bits.
													d. Word		: A unit of data of a specific size (e.g.,8, 16, 32, or 64 bits) depending on the computer architecture.




						8} PA BITS - Physical Address Bits:
													
													a. In computing, a physical address (PA) refers to a location in the computer's memory hardware (RAM). 
													   The number of bits used to represent a physical address determines the maximum addressable memory space

														   1. Physical Address (PA):
																	A physical address specifies a specific location in the memory hardware.
																	It is used by the memory controller to access data in RAM.

														   2. Address Bus:
																	A collection of wires that carries the address information from the CPU to the memory.
																	The width of the address bus (number of bits) determines the maximum addressable memory space.

													# Address Bits and Addressable Memory:
																	The number of bits (PA bits) in a physical address determines how many unique addresses (memory locations) can be accessed. 
																	The relationship can be described by the formula:
																										
																										   Number of PA bits
																					Addressable Memory = 2
																											
																					    
																										a. 4-bit Physical Address:     2 raise to 4 (2*2*2*2) = 16 unique locations
																										   ex					 :      (0-15 Memory locations).

																										b. 8-bit Physical Address:     2 raise to 8 (2*2*2*2*2*2*2*2) = 256 unique locations
																										   ex					 :      (0-255 Memory locations).

																										c. 16-bit Physical Address:    2 raise to 16 (2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2) = 65535 unique locations
																										   ex					 :      (0-65534 Memory locations).

																										d. 32-bit Physical Address:    2 raise to 32 (2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2) = 4,294,967,296 unique locations
																										   ex					 :      (0-4,294,967,295 Memory locations).
																										
																										e. 64-bit Physical Address:    2 raise to 64 
																										   ex					 :     An enormous memory space, theoretically up to 18.4 exabytes..
						9} CACHE MAPPING : 
										1. In computer systems, caching is used to speed up data access by storing frequently accessed data in a smaller, faster storage area (the cache). 
										   There are different techniques for mapping data from main memory to the cache, each with its advantages and trade-offs.
									    2. Techniques  :
												1]  Direct-Mapped Cache
												2]  Fully Associative Cache
												3]  Set-Associative Cache
													

													1] Direct-Mapped Cache :
														//========================================================================================//
															= How It Works:
																1.Mapping			: Each block of main memory maps to exactly one cache line. (0 mapped with 0, 1 with 1.......)
																					
																						- Each block maps to one specific line:
																						  - Block 0 maps to Line 0                 (Block 0 → Line 0)
																						  - Block 1 maps to Line 1                 (Block 1 → Line 1)
																						  - Block 2 maps to Line 2                 (Block 2 → Line 2)
																						  - Block 3 maps to Line 3                 (Block 3 → Line 3)
																						  - And so on...

																2.Indexing		    : The memory address is divided into three parts:
																			a. Tag			: Identifies the block of memory.
																			b. Index		: Specifies which cache line the block maps to.
																			c. Block Offset : Identifies the specific byte within the block.

															= Advantages:
																1.Simplicity		: Easy to implement and understand.
																2.Fast Lookup		: Each cache line can be checked quickly.

															= Disadvantages:
																1.Conflict Misses	: If multiple memory blocks map to the same cache line, they will replace each other, potentially causing more cache misses.
													
														//========================================================================================//


													2] Fully Associative Cache :
														//========================================================================================//
															= How It Works:
																1.Mapping			: A block of main memory can be placed in any cache line.(means mapped to any catch line)
																						
																						- Memory Block Mapping:
																							- Block 0 can be placed in Line 0, 1, 2, or 3
																							- Block 1 can be placed in Line 0, 1, 2, or 3
																							- Block 2 can be placed in Line 0, 1, 2, or 3
																							- Block 3 can be placed in Line 0, 1, 2, or 3
																							- Each cache line needs to be checked to find the block.

																2.Indexing		    : The entire address is used as a tag, and there is no indexing; 
																					  every cache line must be checked to see if it contains the requested block.

															= Advantages:
																Flexibility			: Any block can be placed in any cache line, reducing the likelihood of conflict misses.

															= Disadvantages:
																1.Complexity	: Requires checking all lines (or a subset) to find the block, which can be slower and more complex to implement.
																2.Cost			: More expensive in terms of hardware due to the need for more comparators and complex control logic.
													
														//========================================================================================//


													3] Set-Associative Cache :
														//========================================================================================//
															= How It Works:
																1.Mapping			: The cache is divided into multiple sets. Each block of main memory maps to exactly one set, (0 mapped with set 0 in set 0 placed in any line)
																					  but within that set, the block can be placed in any cache line.

																					  - Each block maps to a specific set:
																							- Block 0 maps to Set 0 (Line 0 or Line 1)   - Within Set 0, it can be placed in Line 0 or Line 1.
																							- Block 1 maps to Set 0 (Line 0 or Line 1)
																							- Block 2 maps to Set 1 (Line 0 or Line 1)
																							- Block 3 maps to Set 1 (Line 0 or Line 1)
																							- Blocks are placed in any line within the designated set.

																2.Indexing		    : The memory address is divided into three parts:
																			a. Tag			: Identifies the block of memory.
																			b. Set Index	: Specifies which set the block maps to.
																			c. Block Offset : Identifies the specific byte within the block.

															= Advantages:
																Balance			: Provides a balance between direct-mapped and fully associative caches, reducing conflict misses while maintaining manageable complexity.
															
															= Disadvantages:
																1.Complexity	: More complex than direct-mapped caches due to the need to check multiple lines within a set.
																2.Cost		: Requires more hardware than direct-mapped caches.

														//========================================================================================//

 10} Cache Misses :
										1. Cache misses occur when the data requested by the CPU is not found in the cache memory, causing a delay as the data is fetched from a slower memory source (like main memory). 
										   There are several types of cache misses, each with different causes and implications.
										2. Types of cache misses : 
														a.	Compulsory Miss (Cold Miss)
														b.	Capacity Miss
														c.	Conflict Miss (Collision Miss)
														d.	Coverage Miss
														e.	Coherence Miss
														f.	Replacement Miss
														g.	Sharing Miss

														//-----------------------------------------------------------------------------------------------------------------------------------------------------//
															a. Compulsory Miss : 
																		1. Compulsory misses occur the first time a block of data is accessed. 
																		   This is unavoidable because the data has never been loaded into the cache.

																		2. Analogy:
																					Imagine you just moved into a new house and are setting up your kitchen. The first time you need a spoon, 
																					you have to go buy it because you don’t have any spoons yet. This is a compulsory miss.
																		3.Example :
																					Accessing a new data element for the first time.
														
														//-----------------------------------------------------------------------------------------------------------------------------------------------------//

															b. Capacity Miss :
																		1. Capacity misses happen when the cache cannot hold all the data needed by the program, 
																		   causing older data to be evicted to make place for new data. This occurs even if the cache has been optimally organized.

																		2. Analogy :
																					Consider a small bookshelf that can hold only 100 books. If you have 200 books, you'll have to store some of them elsewhere. 
																					When you need a book that's not on the shelf, you have to go to the other storage, causing a capacity miss.
																		3.Example :
																					Running a large program that requires more memory than the cache can hold, leading to frequent evictions.

														//-----------------------------------------------------------------------------------------------------------------------------------------------------//

															c. Conflict Miss : 		
																		1. Conflict misses occur in set-associative or direct-mapped caches when multiple blocks compete for the same cache line, 
																		   even though there might be empty lines available in other parts of the cache.

																		2. Analogy : 
																					 Imagine you have a parking lot with designated spots for specific types of cars (e.g., red cars in spot 1, blue cars in spot 2). 
																		             If all the red cars arrive and fill up their designated spots, even if there are empty spots elsewhere, 
																					 new red cars can't park and must leave to find parking elsewhere.
																		3.Example :
																					Multiple data blocks mapping to the same cache line in a direct-mapped cache

														//-----------------------------------------------------------------------------------------------------------------------------------------------------//

															d. Coverage Miss : 
																		1. Coverage misses occur in multilevel caches where the miss in the lower-level cache is not effectively covered by the higher-level cache.

																		2. Analogy :
																					Suppose you have a two-step security check (front gate and main door). If a security check at the main door frequently misses threats that the front gate security didn't catch, 
																					this is a coverage miss.
																		3.Example :
																					Data not found in both L1 and L2 caches, requiring a fetch from main memory.
														
														//-----------------------------------------------------------------------------------------------------------------------------------------------------//

															e. Coherence Miss : 
																		1. Coherence misses occur in multiprocessor systems where cache coherence protocols force invalidation of cache lines 
																		   when other processors modify data, causing misses.
																		
																		2. Analogy :
																					Think of a shared whiteboard in an office where multiple people write and erase notes. 
																					If someone erases your note, and you need it again, you have to rewrite it (a miss in finding your data).

																		3.Example :
																					In a multiprocessor system, one processor writes to a memory location, invalidating that location in another processor's cache.
														
														//-----------------------------------------------------------------------------------------------------------------------------------------------------//

															f. Replacement Miss : 
																		1. Replacement misses occur when a cache line is evicted to make room for new data, and the evicted line is needed again shortly after.

																		2. Analogy :
																					Imagine you have a desk with limited space. You remove a document to make space for a new one, but then realize you need the removed document again, 
																					causing you to go find it elsewhere.
																		3.Example :
																					Frequently accessing a set of data that continually forces evictions and re-fetches.
														
														//-----------------------------------------------------------------------------------------------------------------------------------------------------//

															g. Sharing Miss : 
																		1. Sharing misses happen in shared caches where data shared between processors leads to frequent invalidations and refetches due to 
																		   cache coherence protocols.
																		
																		2. Analogy :
																					Imagine a shared workspace with a single communal printer. If multiple people are sending print jobs to the printer, 
																					and they frequently need to reprint their documents because someone else’s print job interrupts theirs, 
																					you’ll experience delays and inefficiencies.
																		3.Example :
																					Processors in a multiprocessor system repeatedly modifying and reading shared data.
														
														//-----------------------------------------------------------------------------------------------------------------------------------------------------//




				11} Cache Write Policies and Mechanisms : 
								
								KEY CONCEPTS : 
												1.	Write Hit
															a. Write-Through
															b. Write-Back (Copy-Back)
												2.  Write Miss
															a. Write Allocate (Fetch on Write)
															b. No-Write Allocate (Write Around)
												3.  Dirty Bit
												4.  Write Miss Penalty

														
														1. WRITE HIT : 
															         A write hit occurs when the data to be written is already present in the cache. 
																	 There are two main strategies for handling write hits:
																		--	a. Write-Through
																		--	b. Write-Back (Copy-Back)
																
																a. WRITE-THROUGH :
																					Definition		: The data is written to both the cache and the main memory simultaneously.
																					Advantages		: Ensures data consistency between the cache and the main memory.
																					Disadvantages	: Slower write operations due to the need to update the main memory every time.
																					Example			: Writing a letter on your desk and simultaneously making a copy for your records.

																b. WRITE-BACK    :		
																					Definition		: The data is written only to the cache and marked as dirty. The dirty data is written to the main memory only when it is evicted from the cache.
																					Advantages		: Faster write operations since updates are made only in the cache initially.
																					Disadvantages	: More complex to implement and requires additional mechanisms to ensure data consistency.
																					Example			: Writing a letter on your desk and only updating your records later when the desk is needed for another task.
														
														2. Write Miss : 
																	   A write miss occurs when the data to be written is not present in the cache. 
																	   There are two primary strategies for handling write misses:
																	      --   a. Write Allocate (Fetch on Write)
																		  --   b. No-Write Allocate (Write Around)
																
																a. WRITE ALLOCATE : 
																					Definition		: The block containing the data is loaded into the cache, and then the write is performed on the cache.
																					Advantages		: Subsequent writes to the same block can be handled more quickly.
																					Disadvantages	: Introduces additional latency due to the need to fetch the block from the main memory.
																					Example			: If you don’t have a specific document on your desk, you fetch it from your file cabinet before making changes.


																b. NO-WRITE ALLOCATE :
																					Definition		: The data is written directly to the main memory, bypassing the cache.
																					Advantages		: Avoids the overhead of fetching the block into the cache.
																					Disadvantages	: Subsequent writes to the same block will still miss in the cache, potentially leading to more write misses.
																					Example			: Writing directly to your records without using the desk.

														3. Dirty Bit  :
																		A dirty bit is a flag associated with a cache line that indicates whether the data in the cache has been modified (is "dirty") but not yet written back to the main memory.
																		
																		Role		: Helps the system identify which cache lines need to be written back to the main memory when they are evicted.
																		Analogy		: Marking a note on your desk that you have made changes but haven’t updated your records yet.
					
					
					
														4. Write Miss Penalty : (Additional time required for fetching and updating data.)
																			Write miss penalty refers to the additional time required to handle a write miss. 
																			This includes the time to fetch the block from the main memory (in case of write-allocate) and then perform the write operation.

																			Impact	: Write miss penalties can significantly affect system performance, particularly if write misses are frequent.
																			Analogy	: The time it takes to fetch a document from your file cabinet before making changes.
					

							# Internal Working of Cache During Write Operations : 

														Write Hit (Write-Back Example) -

																1. Check Cache	: Look for the block in the cache.
																2. Found		: If the block is found (write hit), update the data in the cache.
																3. Mark Dirty	: Set the dirty bit to indicate the block has been modified.
																4. Defer Write	: Defer writing the data back to the main memory until the block is evicted.

														Write Miss (Write-Allocate Example) -

																1. Check Cache	: Look for the block in the cache.
																2. Not Found	: If the block is not found (write miss), fetch the block from the main memory into the cache.
																3. Update Cache: Write the new data into the cache.
																4. Mark Dirty	: Set the dirty bit to indicate the block has been modified.
																5. Defer Write	: Defer writing the data back to the main memory until the block is evicted.


				12} Cache Replacement Policy : 

							1. Cache replacement policies determine which cache block to replace when a new block needs to be loaded into the cache and there are no empty slots. 
							   These policies are crucial for optimizing cache performance and minimizing cache misses. 
							2. Here are the main cache replacement policies:	
											a.	FIFO  		-(FIRST IN FIRST OUT)
											b.	LIFO  		-(LAST IN FIRST OUT)
											c.	MRU   		-(MOST RECENTLY USED)
											d.	LRU	  		-(LEAST RECENTLY USED)
											e.  Optimal Replacement
											f. 	Pseudo LRU 
											g.	LFU 		-(LEAST FREQUENCY USED)


														a. First In First Out - (FIFO) :
																			1. Definition		: Replaces the block that has been in the cache the longest.
																			2. Advantages		: Simple to implement as it only requires tracking the order of block entries.
																			3. Disadvantages	: Doesn't account for actual usage patterns, which can lead to suboptimal performance.
																			4. Analogy			: Think of a queue at a cafeteria. The first person to get in line is the first to be served, and new people are added to the end of the line.

														b. Last In First Out - (LIFO)  :
																			1. Definition		: Replaces the block that was most recently added to the cache.
																			2. Advantages		: Simple to implement and can be efficient for specific workloads.
																			3. Disadvantages	: Often performs poorly for general-purpose caching as it ignores temporal locality.
																			4. Analogy			: Think of a stack of plates. The most recently placed plate on top is the first one you use.

														c. Most Recently Used - (MRU)  :
																			1. Definition		: Replaces the block that was most recently accessed.
																			2. Advantages		: Simple to implement.
																			3. Disadvantages	: Often suboptimal as it ignores the likelihood of reaccessing recently used data.
																			4. Analogy			: Removing the most recently used book from your desk when you need to add a new one.

														d. Least Recently Used - (LRU) : 
																			1. Definition		: Replaces the block that has not been used for the longest period of time.
																			2. Advantages		: Takes advantage of temporal locality, as it assumes that recently used data will likely be used again soon.
																			3. Disadvantages	: Can be complex to implement, especially in hardware, due to the need to track the usage order of all blocks.
																			4. Analogy			: Imagine a stack of plates. You always use the plate on the top, and when you need a new plate, you put the used plate back on top of the stack. The plate at the bottom is the least recently used.

														e. Optimal Replacement : 
																			1. Definition		: Replaces the block that will not be used for the longest time in the future.
																			2. Advantages		: Provides the best possible hit rate.
																			3. Disadvantages	: Impossible to implement in practice as it requires future knowledge of memory accesses.
																			4. Analogy			: Knowing exactly which books you will need later and removing the one you won’t need for the longest time.

														f. Pseudo Least Recently Used (PLRU) : 
																			1. Definition		: An approximation of LRU that is easier to implement, often used in hardware.
																			2. Advantages		: Balances the simplicity of implementation with the benefits of LRU.
																			3. Disadvantages	: Not as accurate as true LRU, which can lead to slightly worse performance.
																			4. Analogy			: A simplified version of LRU where you roughly track usage patterns without maintaining a perfect order.

														g. Least Frequently USed : 
																			1. Definition		: Replaces the block that has the lowest access frequency.
																			2. Advantages		: Prioritizes keeping frequently accessed data in the cache.
																			3. Disadvantages	: Requires tracking the frequency of accesses, which can be complex and resource-intensive.
																			4. Analogy			: In a library, books that are rarely borrowed are moved to storage to make room for more popular books.
					
					NOTE :  In situations where there is a tie in the frequency or recency of cache blocks - For that FIFO is used.

				
				13} Cache Coherence Protocall : 
							1. Cache coherence protocols are essential in multiprocessor systems to ensure that multiple caches maintain consistent copies of shared data.
							2. They can be broadly classified into two categories: 
														a. Snooping-Based Protocols - 
														b. Directory-Based Protocols -


												a. SNOOPING-BASED PROTOCAL : 
															1. Snooping-based protocols rely on a broadcast medium (usually a shared bus) 
															   where caches "snoop" or listen to the communication between the processors and memory to ensure coherence.

															2. How It Works
																		Bus-Based Communication		: All caches are connected to a common bus. When a cache wants to read or write data, it broadcasts its request on the bus. Other caches that have a copy of this data invalidate their copy.
																		Snooping					: All caches monitor (snoop) the bus for any activity related to the memory blocks they store.	
															
															3. Common Protocols
																			1] MESI Protocol
																			2] MSI Protocol
																			3] MOESI Protocol

																			//------------------------------------------------------------------------------------------//
																				1] MESI PROTOCAL - 
																							M - Modified         -  Cache has modified data.
																							E - Exclusive	 	 -  Cache has unmodified data, not shared.
																							S - Shared		     -  Cache has unmodified data, possibly shared.
																							I - Invalid          -  Data is invalid.
																						
																						a. States:
																									Modified (M)	: The cache line is modified and is different from the main memory. This line is exclusive to the cache, and all other caches must have this line invalidated.
																									Exclusive (E)	: The cache line is the same as the main memory and is not shared with other caches. It is exclusive but unmodified.
																									Shared (S)		: The cache line is the same as the main memory and might be present in other caches.
																									Invalid (I)		: The cache line is invalid and should not be used.
																						
																						b. State Transitions:
																									Read miss  (I → E)	: If a processor reads a block that is not in its cache (Invalid state), it fetches the block from the main memory and moves to the Exclusive state.
																									Read miss  (I → S)	: If a another processor has the block in the Shared state, the processor fetches the block and also goes to the Shared state.
																									Write miss (I → M)	: If a processor writes to a block that is not in its cache, it fetches the block and moves to the Modified state, invalidating other caches.
																									Write hit  (S → M)	: If a processor writes to a block that is in the Shared state, it invalidates other caches and moves to the Modified state.
																									Read miss  (M → S)	: If a processor reads a block that is in the Modified state in another cache, it moves to the Shared state and writes back the modified data to the main memory.

																						Example Scenario:
																									Initial State	      : A memory block is loaded into Cache 1 in the Exclusive state.
																									Modification		  : Cache 1 modifies the block. The state changes to Modified.
																									Read by Another Cache : Cache 2 tries to read the same block. Cache 1 sends the block to Cache 2 and changes its state to Shared. Cache 2's state for the block is also Shared.
																									Invalidation	      : If another cache (Cache 3) writes to the same block, it sends an invalidation signal to Cache 1 and Cache 2, changing their states to Invalid.
																			
																				//------------------------------------------------------------------------------------------//

																				2]  MSI Protocol
																							The MSI protocol is simpler and includes three states: Modified, Shared, and Invalid.
																									States:
																											Modified (M)	: Similar to MESI.
																											Shared (S)		: Similar to MESI.
																											Invalid (I)		: Similar to MESI.
																				
																				//------------------------------------------------------------------------------------------//

																				3] MOESI Protocal
																							The MOESI protocol extends MESI by adding the Owned (O) state.
																									States:
																											Modified (M)	: Similar to MESI.
																											Owned (O)		: 1. The cache line is modified and is the same as the data in main memory.
																															  2. Multiple caches can have this line in the Shared (S) state.
																															  3. The cache in the Owned (O) state is responsible for supplying the data to other caches.
																															  4. This state helps reduce write-backs to main memory when multiple processors are reading the modified data .  ---(but the cache in the Owned state is responsible for providing the most up-to-date data.)
																											
																											Exclusive (E)	: Similar to MESI.
																											Shared (S)		: Similar to MESI.
																											Invalid (I)		: Similar to MESI.

																							How It Works:
																										1. Processor 1 (Cache 1) modifies a data block:
																																Cache 1 changes the state of the data block to Owned (O) because it has modified the data but allows other caches to have shared copies.
																										
																										2. Processor 2 (Cache 2) requests the same data block:
																																Cache 2 can receive the data block in the Shared (S) state.
																																Cache 1, which holds the Owned (O) state, supplies the data to Cache 2.

																				//------------------------------------------------------------------------------------------//
												b. Directory-Based Protocols : 
																1. Directory-based protocols use a directory to keep track of the state of each memory block and the caches that store copies of the block. 
																   This directory is typically located in main memory or is distributed among processors.

																2. How It Works
																		a. Central Directory	: A central directory keeps track of the state of each memory block and the caches that hold copies.
																		b. Request Handling	    : When a processor wants to read or write a memory block, it sends a request to the directory.
																		c. State Management	    : The directory manages the state of the block (e.g., whether it is shared, modified, or invalid) and responds to the requesting cache with the necessary information.
																		d. Interconnect Network : Bus or Network: 
																								   - Provides the communication path between caches and the directory. This can be a bus-based system or a more complex network of switches and links.													
																
																3. States : 
																		Similar to MESI (Modified, Exclusive, Shared, Invalid) or MOESI, but managed via the directory.

																4. Example Scenario
																			Initial State    : The directory indicates that a block is Shared in Cache 1 and Modified in Cache 2.
																			Read by Cache 3  : Cache 3 reads the block. The directory updates the state to Shared for Cache 3 and changes Cache 2's state to Owned.
																			Write by Cache 3 : Cache 3 writes to the block. The directory sends invalidation signals to Cache 1 and Cache 2, updating their states to Invalid.
																
																5. Advantages
																			Scalability           : Can handle a larger number of processors efficiently.
																			Reduced Bus Traffic   : Only necessary information is sent across the network, reducing traffic.
																
																6. Disadvantages
																			Complexity  : More complex to implement and manage.
																			Latency     : Communication with the directory can introduce additional latency.



			**	14}Implementation (DSA) :
									1.Doubly Linked List with Hash Map:
														a. A more efficient implementation uses a combination of a doubly linked list and a hash map:
														   The hash map provides O(1) time complexity for accessing cache items.

													    b. The doubly linked list maintains the order of usage, allowing quick updates of item positions.
														   In this setup, when an item is accessed, it is moved to the front of the list. When an item needs to be evicted, it is removed from the back of the list.
									
									2.Simple List:
														a. A simple way to implement LRU is using a linked list where the most recently used items are moved to the front, and the least recently used items are pushed to the back. 
														   This can be inefficient for large caches as updating the list requires traversal

				

*/
//--------------------------------------------------------------------------------------------------------------//