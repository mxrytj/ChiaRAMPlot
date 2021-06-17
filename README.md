# ChiaRAMPlot
This is a new implementation of a chia plotter which is designed as a processing pipeline, similar to how GPUs work, only the "cores" are normal software CPU threads.
## Usage
  * Choose Number of Plots
    Number of plots to create (default = 1)
  * Number of threads
    Number of threads (default = 4)
  * Number of bucket 
    Number of buckets (default = 256)
  * Select Temporary Directory   
    Temporary directory, needs ~220 GiB
  * Select 2nd Temporary Directory   
    Temporary directory 2, needs ~110 GiB
  * Select Final Directory  
    Final directory (default = <tmpdir>)
  * Pool Public Key
    Pool Public Key (48 bytes)
  * Farmer Public Key 
    Farmer Public Key (48 bytes)
 
## Results
![4](https://user-images.githubusercontent.com/86047703/122366502-267aa200-cf4b-11eb-97bc-aeb9c97a68cf.PNG)
 
## Dependencies
* cmake (>=3.14)
* libsodium-dev
