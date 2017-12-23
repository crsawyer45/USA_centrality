# USA_centrality

This program lists the 48 continental US states and DC in order of their centrality within the country, the most central states being listed first. The input file is comprised of a list of neighboring states such that every line has the abreviations of two states to indicate that those two states border one another.  Because the list contains all such pairs, 49 lists can be constructed to show what borders every state.
If we are to consider every state to simply be a node in a graph, then the most central state is the one who must touch the least number of other states to get to the node that is the most states away from it.
In order to find the most central state, a depth first search method of finding the shortest paths is used.  Thus, starting with one state, we travel to all of its neighbors, then to all of the neighbors of those neighbors (without revisiting any states), and so on, until the farthest state from that intital state has been found.  Doing this for every state creates the list that the program prints as output.
