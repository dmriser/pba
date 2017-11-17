# Processor Based Analysis (PBA)

PBA is a framework for analyzing generic numerical data in c++.  This software package is similar to other packages such as ARTUS, and CLARA, except that this one is not very good.  Using PBA one can define a data type, and pass it through a series of **nodes**.  Together nodes define a workflow, these are designed by writing a configuration file in json.  The three basic types of nodes are: 

* Producers 
* Processors
* Aggregators 

