package edu.miracosta.cs113;

/**
 * DoubleLinkedList: an implementation of the LinkedList class, implementing
 * the List interface and utilizing a private inner class which implements the
 * ListIterator interface. As a doubly linked list, this class is used to add,
 * set, and remove node objects which can be accessed through transversing in
 * either the forwards or backwards direction.
 *
 * @author King
 * @version 1.0
 */

import java.util.Collection;
import java.util.Comparator;
import java.util.function.UnaryOperator;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;
import java.util.NoSuchElementException;
import java.util.Spliterator;

public class DoubleLinkedList<E> implements List<E> {
    private Node<E> head;
    private Node<E> tail;
    private int size;

    /**
     * Default constructor: creates an empty doubly linked list with 0 elements.
     */
    public DoubleLinkedList(){
        head = null;
        tail = null;
        size = 0;
    }

    @Override
    public Iterator<E> iterator() {
        return new DoubleListIterator();
    }

    @Override
    public ListIterator<E> listIterator() {
        return new DoubleListIterator();
    }

    @Override
    public ListIterator<E> listIterator(int index) {
        return new DoubleListIterator(index);
    }

    @Override
    public boolean add(E anObject) {
        this.listIterator(size).add(anObject); // Adds element to tail-end of the list
        return true;
    }

    @Override
    public void add(int index, E anObject) {
        listIterator(index).add(anObject);
    }

    @Override
    public E set(int index, E element) {
        checkIndex(index + 1); // Includes case of final index in this list from which next()
                               // cannot be called.
        DoubleListIterator itr = new DoubleListIterator(index);
        itr.next(); // Must be called prior to DoubleListIterator's set method
        itr.set(element);
        return element;
    }

    @Override
    public boolean remove(Object anObject) {
        if (this.contains(anObject)) {
            // Calling DoubleLinkedList method remove at an index
            this.remove(this.indexOf(anObject));
            return true;
        }
        else { // Given element is not found in the list
            return false;
        }
    }

    @Override
    public E remove(int index) {
        DoubleListIterator itr = new DoubleListIterator(index);
        E removedItem;

        // Exception thrown where, at the end of the list, a subsequent
        // call to next cannot occur
        if (index == size) {
            throw new IndexOutOfBoundsException();
        }
        else {
            removedItem = itr.next();
        }
        itr.remove();
        return removedItem;
    }

    @Override
    public void clear() {
        head = null;
        tail = null;
        size = 0;
    }

    @Override
    public E get(int index) {
        checkIndex(index + 1); // Includes case of final index in this list from which next()
                               // cannot be called.
        return listIterator(index).next();
    }

    @Override
    public int indexOf(Object anObject) {
        int firstIndex = -1; // If the given object is not in the list
        DoubleListIterator itr = new DoubleListIterator();
        while (itr.hasNext()) {
            if (itr.next().equals(anObject)) {
                firstIndex = itr.previousIndex(); // Index of last node
                break;                            // returned by iterator
            }
        }
        return firstIndex;
    }

    @Override
    public int lastIndexOf(Object anObject) {
        int lastIndex = -1; // If the given object is not in the list
        DoubleListIterator itr = new DoubleListIterator(size);
        while (itr.hasPrevious()) {
            if (itr.previous().equals(anObject)) {
                lastIndex = itr.index; // Index of last node returned
                break;                 // by iterator
            }
        }
        return lastIndex;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return (size == 0);
    }

    @Override
    public boolean contains(Object anObject) {
        boolean result = false;
        DoubleListIterator itr = new DoubleListIterator();
        while (itr.hasNext()) {
            if (itr.next().equals(anObject)) { // If current object is equal to the given
                result = true;
                break;
            }
        }
        return result;
    }

    @Override
    public boolean equals(Object anObject) {
        if ((anObject == null) || (this.getClass() != anObject.getClass())) {
            return false;
        }
        else { // Compare the two lists based on the information returned by toString
            DoubleLinkedList<E> aList = new DoubleLinkedList<E>();
            return this.toString().equals(aList.toString());

        }
    }

    @Override
    public String toString() {
        String listString = "[";
        DoubleListIterator itr = new DoubleListIterator();

        while (itr.hasNext()) {
            listString += itr.next().toString();
            if (itr.hasNext()) {
                listString += ", ";
            }
        }
        listString += "]";
        return listString;
    }

    /**
     * Helper method for checking if a given index is within the domain of the linked
     * list.
     *
     * @param index
     *          the given index for an existing element in the list
     * @throws IndexOutOfBoundsException
     *          if the given index is less than 0 or greater than the size of the list
     */
    private void checkIndex(int index) {
        if ((index < 0) || (index > size)) {
            throw new IndexOutOfBoundsException();
        }
    }

    /*
     * TODO:
     *  Implement the following List interface methods for the DoubleLinkedList class.
     */
    @Override
    public List<E> subList(int fromIndex, int toIndex) {return null; }
    @Override
    public Object[] toArray() { return null; }
    @Override
    public boolean addAll(Collection<? extends E> c) { return false; }
    @Override
    public boolean addAll(int index, Collection<? extends E> c) { return false; }
    @Override
    public boolean containsAll(Collection<?> c) { return false; }
    @Override
    public boolean removeAll(Collection<?> c) { return false; }
    @Override
    public int hashCode() { return 0; }
    @Override
    public void replaceAll(UnaryOperator<E> operator) { /* Stub */ }
    @Override
    public boolean retainAll(Collection<?> c) { return false; }
    @Override
    public <T> T[] toArray(T[] a) { return null; }
    @Override
    public void sort(Comparator<? super E> c) { /* Stub */ }
    @Override
    public Spliterator<E> spliterator() { return null; }

    /**
     * Private inner class DoubleListIterator for accessing and manipulating elements
     * within the doubly linked list.
     */
    private class DoubleListIterator implements ListIterator<E> {
        private Node<E> nextItem; // Item in front of current index
        private Node<E> lastItemReturned; // References Node last returned by next or previous
        private int index; // Iterator is positioned just before the item at index

        /**
         * Default constructor creates an iterator at position 0, where the head of
         * the double linked list is the next item.
         */
        DoubleListIterator() {
            nextItem = head; // Iterator position begins before head
            lastItemReturned = null;
            index = 0;
        }

        /**
         * Full constructor creates a list iterator starting from the specified index.
         *
         * @param index
         *          the initial index of the list iterator
         */
        DoubleListIterator(int index) {
            checkIndex(index); // Error check given list index
            lastItemReturned = null; // As not preceded by next or previous

            // If the index is equivalent to that of the last item in the list
            if (index == size) {
                this.index = size;
                nextItem = null;
            }
            else { // Otherwise iterate to index from the beginning of the list
                nextItem = head;
                for (this.index = 0; this.index < index; this.index ++) {
                    nextItem = nextItem.next;
                }
            }
        }

        @Override
        public void add(E anObject) {
            if (head == null) { // If the list is empty
                head = new Node<E>(anObject);
                tail = head;
            }
            else if (nextItem == head) { // Inserting at head
                Node<E> newHead = new Node<E>(anObject);
                newHead.next = nextItem;
                nextItem.previous = newHead;
                head = newHead;
            }
            else if (nextItem == null) { // Inserting at tail
                Node<E> newTail = new Node<E>(anObject);
                tail.next = newTail;
                newTail.previous = tail;
                tail = newTail;
            }
            else { // Inserting at the middle of the list
                Node<E> newNode = new Node<E>(anObject);
                newNode.previous = nextItem.previous;
                nextItem.previous.next = newNode;
                newNode.next = nextItem;
                nextItem.previous = newNode;
            }
            size ++;
            index ++;
            lastItemReturned = null;
        }

        @Override
        public void remove() {
            // Throw exception if neither next nor previous have been called,
            // or remove or add have been called prior to this invocation
            if (lastItemReturned == null) {
                throw new IllegalStateException();
            }
            else if (lastItemReturned == head) { // Removing current head
                head = head.next;
            }
            else if (lastItemReturned == tail) { // Removing current tail
                tail = tail.previous;
                tail.next = null;
            }
            else { // Removing an element in the middle of the list
                lastItemReturned.previous.next = lastItemReturned.next;
                lastItemReturned.next.previous = lastItemReturned.previous;
            }
            index --;
            size --;
            lastItemReturned = null;
        }

        @Override
        public boolean hasNext() {
            return (nextItem != null);
        }

        @Override
        public boolean hasPrevious() {
            if (isEmpty()) {
                return false;
            }
            else {
                return ((nextItem == null && size != 0)  // Checks at end of list
                        || (nextItem.previous != null)); // Checks at beginning of list
            }
        }

        @Override
        public E next() {
            if ( ! hasNext()) { // Error check index
                throw new NoSuchElementException();
            }
            lastItemReturned = nextItem;
            nextItem = nextItem.next;
            index ++;
            return lastItemReturned.data; // Returns Node data
        }

        @Override
        public int nextIndex() {
            if ( ! hasNext()) { // If at end of the list
                return size;
            }
            else {
                return index + 1;
            }
        }

        @Override
        public E previous() {
            if ( ! hasPrevious()) { // Error check index
                throw new NoSuchElementException();
            }
            if (nextItem == null) { // If iterator is past the last element,
                nextItem = tail;    // set nextItem to tail of linked list
            }
            else { // Otherwise pass element in front of current index
                nextItem = nextItem.previous;
            }
            lastItemReturned = nextItem;
            index --;
            return lastItemReturned.data; // Return Node data
        }

        @Override
        public int previousIndex() {
            return index - 1;
        }

        @Override
        public void set(E e) {
            // Exception if next or previous has not been previously called
            if (lastItemReturned == null) {
                throw new IllegalStateException();
            }

            Node<E> newNode = new Node<E>(e);

            if (lastItemReturned == head) { // Setting head
                head.next.previous = newNode; // (element after newNode)
                newNode.next = head.next;
                head = newNode;
            }
            else if (lastItemReturned == tail) { // Setting tail
                tail.previous.next = newNode; // (element before newNode)
                newNode.previous = tail.previous;
                tail = newNode;
            }
            else { // Setting element in middle of list
                lastItemReturned.previous.next = newNode; // (element before newNode)
                newNode.next = lastItemReturned.next;
                lastItemReturned.next.previous = newNode; // (element after newNode)
            }
        }

    } // End of class DoubleListIterator

    /**
     * Private static inner class Node.
     */
    private static class Node<E> {
        private E data;
        private Node<E> next = null;
        private Node<E> previous = null;

        /**
         * Creates a Node object as defined by the given data
         *
         * @param dataObject
         *          an element containing object-specific data
         */
        private Node(E dataObject) {
            data = dataObject;
        }

    } // End of class Node

} // End of class DoubleLinkedList
