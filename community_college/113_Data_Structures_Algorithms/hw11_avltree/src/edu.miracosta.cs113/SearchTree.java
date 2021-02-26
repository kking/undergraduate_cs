package edu.miracosta.cs113;

/**
 * SearchTree : interface for classes which implement a binary search tree and its functions for the insertion,
 * searching, and removal of nodes.
 *
 * @author Elliot B. Koffman, Paul A. T. Wolfgang
 * @author Data Structures: Abstraction and Design Using Java (2nd ed.), pp. 317
 */
interface SearchTree<E> {

    /**
     * Returns true if the target is found in the tree.
     *
     * @param target The item whose presence in the tree is to be determined
     * @return true if target is found in the tree, false otherwise
     */
    public boolean contains(E target);

    /**
     * Returns a reference to the data in the node that is equal to target. If no such node is found, returns null.
     *
     * @param target The item whose presence in the tree is to be determined
     * @return a reference to the data item if found, null otherwise
     */
    public E find(E target);

    /**
     * Removes target (if found) from the tree and returns it; otherwise returns null.
     *
     * @param target The item to be deleted from the tree
     * @return a reference to the the data item if found and removed from the tree, null otherwise
     */
    public E delete(E target);

    /**
     * Inserts item where it belongs in the tree. Returns true if item is inserted; false if it is already present
     * in the tree.
     *
     * @param item The item to be inserted
     * @return true if item is successfully inserted, false if it already exists within the tree
     */
    public boolean add(E item);

    /**
     * Removes target (if found) from the tree and returns true; otherwise returns null.
     *
     * @param target The item to be removed from the tree
     * @return true if the item was found and removed from the tree, false otherwise
     */
    public boolean remove(E target);

} // End of interface SearchTee