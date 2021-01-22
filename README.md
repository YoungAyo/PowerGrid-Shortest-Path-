# PowerGrid-Shortest-Path-
Used dijkstra’s shortest path algorithm to calculate amount of wire needed

The government is building a new town, named Utopia, on top of some abandoned farm
land in NJ.  The town will be represented as a graph.  The edges represent streets in the
town, and they have an official name as well as a length in meters.  The vertices represent
the intersection of streets.  The government officials want to ensure safety of the workers
building the town, so electricity must be supplied to the town immediately and every
intersection must have a traffic light installed (which, of course, requires power).  All
intersections must be linked by the power grid that is being installed.  (Upon completion of
installing the town’s power grid, the engineers will connect an intersection on the outskirts
of the town to the state’s power grid. You do not have to account for this aspect of the
project.)
Your goal is to write a program that reads the graph representation from a file and
computes the minimum set of roads on which to install power lines.  The results of your
program will tell the engineers how many meters of wire to purchase and on what streets
the power lines should be run.
