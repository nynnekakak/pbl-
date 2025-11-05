Installation
Requirements
ns-3 simulator v3.43.
c++ compiler.
cmake.
python3.
The simulation uses the ns-3 simulator, and has been developed and tested with the version 3.37.

Build
First, make sure you have already completed all the step required for the installation of the simulator shown here.
The directory structure should look something like this:

.
└── ns-allinone-3.43/
    └── ns-3.43/
        ├── ns3
        ├── examples/
        ├── src/
        ├── scratch/
        └── ...
Move to the scratch folder and clone the repository:

cd ns-allinone-3.37/ns-3.37/scratch
git clone git@github.com:TendTo/ns3-Tahoe-vs-Reno.git
Lastly, move back to the ns-3.37 folder and build the simulation:

cd ..
./ns3 run "tcp_reno_project --PrintHelp"
Usage
The simulation is highly configurable. The following options are available:

Usage: ./ns3 run "tcp_reno_project  [options]"

Program Options:
    --n_tcp_tahoe:         Number of Tcp Tahoe nodes [1]
    --n_tcp_reno:          Number of Tcp Reno nodes [1]
    --s_buf_size:          Sender buffer size (bytes) [131072]
    --r_buf_size:          Receiver buffer size (bytes) [131072]
    --cwnd:                Initial congestion window (segments) [1]
    --ssthresh:            Initial slow start threshold (segments) [65535]
    --mtu:                 Size of IP packets to send (bytes) [1500]
    --sack:                Enable SACK [true]
    --nagle:               Enable Nagle algorithm [false]
    --error_p:             Packet error rate [0]
    --s_bandwidth:         Sender link bandwidth [10Mbps]
    --s_delay:             Sender link delay [40ms]
    --r_bandwidth:         Receiver link bandwidth [10Mbps]
    --r_delay:             Receiver link delay [40ms]
    --tcp_queue_size:      TCP queue size (packets) [25]
    --run:                 Run id [0]
    --duration:            Duration of the simulation (s) [3]
    --max_mbytes_to_send:  Maximum number of megabytes to send (MB) [0]
    --prefix_file_name:    Prefix file name [P2P-project]
    --graph_output:        The type of image to output: png, svg [png]
    --ascii_tracing:       Enable ASCII tracing [false]
    --pcap_tracing:        Enable Pcap tracing [false]

General Arguments:
    --PrintGlobals:              Print the list of globals.
    --PrintGroups:               Print the list of groups.
    --PrintGroup=[group]:        Print all TypeIds of group.
    --PrintTypeIds:              Print all TypeIds.
    --PrintAttributes=[typeid]:  Print all attributes of typeid.
    --PrintVersion:              Print the ns-3 version.
    --PrintHelp:                 Print this help message.
